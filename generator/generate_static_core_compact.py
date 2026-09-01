"""Generate one compact exact-context Jungle Strike S-CPU authority.

The sealed generated S-CPU layers are treated as immutable input authority.  This
tool composes their exact context overrides in production precedence order, then
losslessly factors identical emitted C structures into shared semantic templates
with frozen per-context parameters.  Runtime selection is by the exact packed
PBR:PC:E:M:X key.  It never reads or decodes a ROM opcode, learns a target, or
falls back to an emulator/interpreter.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
EXPECTED_CONTEXTS = 27835
EXPECTED_ROM_SHA256 = (
    "8d812ea4fa897274116f7f43bc689e110f1cfbd3f7eb3a1737c2a85d36369159"
)

LAYERS = (
    ("10.46", "generated/v10_46", "v10_46_scpu_group_*.c"),
    ("10.47", "generated/v10_47", "v10_47_scpu_group_*.c"),
    ("10.93", "generated/v10_93_scpu", "v10_93_scpu_group_*.c"),
    ("10.94", "generated/v10_94_scpu", "v10_94_scpu_group_*.c"),
    ("10.95", "generated/v10_95_scpu", "v10_95_scpu_group_*.c"),
    ("10.96", "generated/v10_96_scpu", "v10_96_scpu_group_*.c"),
    ("10.97", "generated/v10_97_scpu", "v10_97_scpu_group_*.c"),
    ("10.98", "generated/v10_98_scpu", "v10_98_scpu_group_*.c"),
    ("10.99", "generated/v10_99_scpu", "v10_99_scpu_group_*.c"),
    ("10.100", "generated/v10_100_scpu", "v10_100_scpu_group_*.c"),
)

BODY_RE = re.compile(
    r"^static js_stop_reason (?P<name>[A-Za-z0-9_]+)"
    r"\(js_machine_v05c \*m\) \{\n(?P<body>.*?)^\}\s*$",
    re.MULTILINE | re.DOTALL,
)
CASE_RE = re.compile(
    r"case\s+JS_V05C_KEY_CONST\("
    r"0x(?P<pbr>[0-9A-Fa-f]+)u,\s*0x(?P<pc>[0-9A-Fa-f]+)u,\s*"
    r"(?P<e>[01])u,\s*(?P<m>[01])u,\s*(?P<x>[01])u\)\s*:"
    r"\s*\*out\s*=\s*(?P<body>[A-Za-z0-9_]+)\(m\)\s*;\s*return\s+1\s*;"
)
NUMERIC_LITERAL_RE = re.compile(
    r"0x[0-9A-Fa-f]+[uUlL]*|(?<![A-Za-z_])\d+[uUlL]*"
)
KNOWN_CALL_RE = re.compile(r"js_v(?:\d+_?)+_scpu_context_known")
BLOCK_COMMENT_RE = re.compile(r"/\*.*?\*/", re.DOTALL)


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def packed_key(pbr: int, pc: int, e: int, m: int, x: int) -> int:
    # Matches JS_V05C_KEY_CONST in cpu_dispatch.h.
    return ((pbr & 0xFF) << 24) | ((pc & 0xFFFF) << 8) | (
        (e & 1) << 2) | ((m & 1) << 1) | (x & 1)


def normalize_body(body: str) -> str:
    body = body.replace("\r\n", "\n")
    body = BLOCK_COMMENT_RE.sub("", body)
    body = KNOWN_CALL_RE.sub("js_v10_100_scpu_context_known", body)
    # Template parameters cannot initialize a function-static object.  The guard
    # consumes this immutable local array synchronously, so automatic const
    # storage is semantically equivalent and permits frozen record parameters.
    body = body.replace("static const uint8_t expected[]", "const uint8_t expected[]")
    lines = [line.rstrip() for line in body.splitlines()]
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()
    return "\n".join(lines)


def skeleton_and_literals(text: str) -> tuple[str, tuple[str, ...]]:
    literals: list[str] = []
    pieces: list[str] = []
    cursor = 0
    for match in NUMERIC_LITERAL_RE.finditer(text):
        pieces.append(text[cursor:match.start()])
        literals.append(match.group(0))
        pieces.append("@N@")
        cursor = match.end()
    pieces.append(text[cursor:])
    return "".join(pieces), tuple(literals)


def literal_to_u32(token: str) -> int:
    value = re.sub(r"[uUlL]+$", "", token)
    parsed = int(value, 0)
    if not 0 <= parsed <= 0xFFFFFFFF:
        raise RuntimeError(f"literal does not fit uint32_t: {token}")
    return parsed


def analyze_columns(rows: list[dict]) -> tuple[list[str], list[tuple[str, ...]]]:
    width = len(rows[0]["literals"])
    if any(len(row["literals"]) != width for row in rows):
        raise RuntimeError("literal-column mismatch inside semantic skeleton")
    vectors = [tuple(row["literals"][i] for row in rows) for i in range(width)]
    variable_vectors: list[tuple[str, ...]] = []
    replacements: list[str] = []
    for vector in vectors:
        if len(set(vector)) == 1:
            replacements.append(vector[0])
        else:
            if vector not in variable_vectors:
                variable_vectors.append(vector)
            replacements.append(f"p[{variable_vectors.index(vector)}]")
    return replacements, variable_vectors


def substitute_literals(body: str, replacements: list[str]) -> str:
    index = 0

    def replace(_match: re.Match[str]) -> str:
        nonlocal index
        result = replacements[index]
        index += 1
        return result

    output = NUMERIC_LITERAL_RE.sub(replace, body)
    if index != len(replacements):
        raise RuntimeError("literal substitution did not consume every column")
    return output


def reconstruct(template: str, vectors: list[tuple[str, ...]], row: int) -> str:
    return re.sub(
        r"p\[(\d+)\]",
        lambda match: vectors[int(match.group(1))][row],
        template,
    )


def read_authority() -> tuple[dict[int, dict], list[dict]]:
    contexts: dict[int, dict] = {}
    inputs: list[dict] = []
    for layer, relative, pattern in LAYERS:
        directory = ROOT / relative
        paths = sorted(directory.glob(pattern), key=lambda path: path.name)
        if not paths:
            raise RuntimeError(f"missing generated authority layer {relative}/{pattern}")
        for path in paths:
            data = path.read_bytes()
            text = data.decode("utf-8").replace("\r\n", "\n")
            functions = {
                match.group("name"): normalize_body(match.group("body"))
                for match in BODY_RE.finditer(text)
            }
            cases = list(CASE_RE.finditer(text))
            if not cases:
                raise RuntimeError(f"no exact-context cases parsed from {path}")
            for match in cases:
                function = match.group("body")
                if function not in functions:
                    raise RuntimeError(f"missing {function} body in {path}")
                pbr = int(match.group("pbr"), 16)
                pc = int(match.group("pc"), 16)
                e = int(match.group("e"))
                m = int(match.group("m"))
                x = int(match.group("x"))
                key = packed_key(pbr, pc, e, m, x)
                contexts[key] = {
                    "key": key,
                    "pbr": pbr,
                    "pc": pc,
                    "e": e,
                    "m": m,
                    "x": x,
                    "group": ((pbr << 16) | pc) >> 10,
                    "body": functions[function],
                    "source": path.relative_to(ROOT).as_posix(),
                    "layer": layer,
                    "function": function,
                }
            inputs.append({
                "path": path.relative_to(ROOT).as_posix(),
                "bytes": len(data),
                "sha256": sha256_bytes(data),
                "parsed_cases": len(cases),
            })
    if len(contexts) != EXPECTED_CONTEXTS:
        raise RuntimeError(
            f"composed context count {len(contexts)} != sealed {EXPECTED_CONTEXTS}"
        )
    return contexts, inputs


def render_header(groups: list[int]) -> str:
    lines = [
        "/* generated compact exact-context S-CPU authority - do not edit */",
        "#ifndef JUNGLE_STATIC_CORE_COMPACT_GENERATED_H",
        "#define JUNGLE_STATIC_CORE_COMPACT_GENERATED_H",
        '#include "jungle/cpu_dispatch_v10_100.h"',
        "#define JS_CTX(PBR,PC,E,M,X) ((js_static_context_key){(uint8_t)(PBR),(uint16_t)(PC),(uint8_t)(E),(uint8_t)(M),(uint8_t)(X)})",
        "js_stop_reason js_compact_scpu_execute(js_machine_v05c *m,",
        "                                        uint16_t template_id,",
        "                                        const uint32_t *parameters);",
    ]
    for group in groups:
        lines += [
            f"int js_compact_scpu_group_{group:04X}(js_machine_v05c *m,",
            "                                  uint32_t packed,",
            "                                  js_stop_reason *out);",
        ]
    lines += ["#endif", ""]
    return "\n".join(lines)


def render_templates(templates: list[dict]) -> str:
    lines = [
        "/* generated compact exact-context semantic templates - do not edit */",
        "/* Exact key records select these templates; no ROM opcode is decoded. */",
        '#include "jungle/cpu_v08c_internal.h"',
        '#include "jungle/cpu_v10_3_internal.h"',
        '#include "jungle/cpu_v10_27_internal.h"',
        '#include "jungle/cpu_v10_36_internal.h"',
        '#include "jungle/cpu_v10_45_internal.h"',
        '#include "jungle/cpu_dispatch_v10_100.h"',
        '#include "jungle/status_v10_11.h"',
        '#include "static_core_compact_generated.h"',
        "",
    ]
    for template in templates:
        lines += [
            f"static js_stop_reason js_compact_template_{template['id']:03X}(",
            "        js_machine_v05c *m, const uint32_t *p) {",
            "    (void)p;",
        ]
        lines += ["    " + line for line in template["body"].splitlines()]
        lines += ["}", ""]
    lines += [
        "js_stop_reason js_compact_scpu_execute(js_machine_v05c *m,",
        "                                        uint16_t template_id,",
        "                                        const uint32_t *p) {",
        "    switch (template_id) {",
    ]
    for template in templates:
        lines.append(
            f"        case 0x{template['id']:03X}u: return "
            f"js_compact_template_{template['id']:03X}(m, p);"
        )
    lines += [
        "        default: return JS_STOP_UNKNOWN_STATIC_CONTEXT;",
        "    }",
        "}",
        "",
    ]
    return "\n".join(lines)


def render_shard(group: int, rows: list[dict]) -> tuple[str, int]:
    rows.sort(key=lambda row: row["key"])
    parameters: list[int] = []
    records: list[str] = []
    for row in rows:
        offset = len(parameters)
        parameters.extend(row["parameters"])
        records.append(
            f"    {{0x{row['key']:08X}u,0x{offset:08X}u,"
            f"0x{row['template_id']:04X}u,0u}},"
        )
    lines = [
        "/* generated compact exact-context S-CPU shard - do not edit */",
        '#include "static_core_compact_generated.h"',
        "typedef struct js_compact_record {",
        "    uint32_t key;",
        "    uint32_t parameter_offset;",
        "    uint16_t template_id;",
        "    uint16_t reserved;",
        "} js_compact_record;",
        f"static const js_compact_record records[{len(rows)}] = {{",
        *records,
        "};",
    ]
    if parameters:
        lines.append(f"static const uint32_t parameters[{len(parameters)}] = {{")
        for start in range(0, len(parameters), 8):
            chunk = parameters[start:start + 8]
            lines.append("    " + ",".join(f"0x{value:08X}u" for value in chunk) + ",")
        lines.append("};")
    else:
        lines.append("static const uint32_t parameters[1] = {0u};")
    lines += [
        f"int js_compact_scpu_group_{group:04X}(js_machine_v05c *m,",
        "                                  uint32_t packed,",
        "                                  js_stop_reason *out) {",
        f"    unsigned lo = 0u, hi = {len(rows)}u;",
        "    while (lo < hi) {",
        "        unsigned mid = lo + (hi - lo) / 2u;",
        "        uint32_t found = records[mid].key;",
        "        if (packed < found) hi = mid;",
        "        else if (packed > found) lo = mid + 1u;",
        "        else {",
        "            *out = js_compact_scpu_execute(",
        "                m, records[mid].template_id,",
        "                parameters + records[mid].parameter_offset);",
        "            return 1;",
        "        }",
        "    }",
        "    return 0;",
        "}",
        "",
    ]
    return "\n".join(lines), len(parameters)


def render_dispatch(contexts: list[dict], groups: list[int]) -> str:
    keys = sorted(row["key"] for row in contexts)
    lines = [
        "/* generated compact exact-context S-CPU index - do not edit */",
        '#include "static_core_compact_generated.h"',
        f"static const uint32_t known_keys[{len(keys)}] = {{",
    ]
    for start in range(0, len(keys), 8):
        lines.append("    " + ",".join(f"0x{key:08X}u" for key in keys[start:start + 8]) + ",")
    lines += [
        "};",
        "int js_v10_100_scpu_context_known(js_static_context_key key) {",
        "    uint32_t packed = js_v05c_pack_key(key);",
        f"    unsigned lo = 0u, hi = {len(keys)}u;",
        "    while (lo < hi) {",
        "        unsigned mid = lo + (hi - lo) / 2u;",
        "        uint32_t found = known_keys[mid];",
        "        if (packed < found) hi = mid;",
        "        else if (packed > found) lo = mid + 1u;",
        "        else return 1;",
        "    }",
        "    return 0;",
        "}",
        "",
        "js_stop_reason js_static_dispatch_v10_100(js_machine_v05c *m,",
        "                                          js_static_context_key key) {",
        "    js_stop_reason out = JS_STOP_UNKNOWN_STATIC_CONTEXT;",
        "    uint32_t packed = js_v05c_pack_key(key);",
        "    uint32_t address = ((uint32_t)key.pbr << 16) | key.pc;",
        "    switch (address >> 10u) {",
    ]
    for group in groups:
        lines.append(
            f"        case 0x{group:X}u: if (js_compact_scpu_group_{group:04X}("
            "m, packed, &out)) return out; break;"
        )
    lines += [
        "        default: break;",
        "    }",
        "    return JS_STOP_UNKNOWN_STATIC_CONTEXT;",
        "}",
        "",
        "js_stop_reason js_static_step_v10_100(js_machine_v05c *m) {",
        "    js_static_context_key key;",
        "    if (!m->rom_identity_ok) return JS_STOP_WRONG_ROM;",
        "    key = js_v05c_key_from_cpu(&m->cpu);",
        "    if ((key.e && (!key.m || !key.x)) ||",
        "        key.e > 1u || key.m > 1u || key.x > 1u)",
        "        return JS_STOP_INVALID_CPU_CONTEXT;",
        "    return js_static_dispatch_v10_100(m, key);",
        "}",
        "",
    ]
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out", type=Path, required=True)
    parser.add_argument("--rom", type=Path)
    args = parser.parse_args()
    if args.rom is not None:
        digest = sha256_bytes(args.rom.read_bytes())
        if digest != EXPECTED_ROM_SHA256:
            raise SystemExit("wrong Jungle Strike ROM")

    authority, inputs = read_authority()
    structural: dict[str, list[dict]] = defaultdict(list)
    for row in authority.values():
        skeleton, literals = skeleton_and_literals(row["body"])
        item = dict(row)
        item["literals"] = literals
        structural[skeleton].append(item)

    templates: list[dict] = []
    compact_rows: list[dict] = []
    original_hash = hashlib.sha256()
    reconstructed_hash = hashlib.sha256()
    ordered = sorted(structural.items(), key=lambda item: (-len(item[1]), item[0]))
    for template_id, (_skeleton, rows) in enumerate(ordered):
        replacements, vectors = analyze_columns(rows)
        template_body = substitute_literals(rows[0]["body"], replacements)
        templates.append({
            "id": template_id,
            "body": template_body,
            "parameter_count": len(vectors),
            "context_count": len(rows),
        })
        for row_index, row in enumerate(rows):
            rebuilt = reconstruct(template_body, vectors, row_index)
            if rebuilt != row["body"]:
                raise RuntimeError(f"semantic reconstruction mismatch at key {row['key']:08X}")
            key_bytes = row["key"].to_bytes(4, "little")
            original_hash.update(key_bytes)
            original_hash.update(row["body"].encode("utf-8"))
            reconstructed_hash.update(key_bytes)
            reconstructed_hash.update(rebuilt.encode("utf-8"))
            compact_rows.append({
                "key": row["key"],
                "group": row["group"],
                "template_id": template_id,
                "parameters": [literal_to_u32(vector[row_index]) for vector in vectors],
                "source": row["source"],
                "layer": row["layer"],
            })
    if original_hash.digest() != reconstructed_hash.digest():
        raise RuntimeError("whole-authority semantic reconstruction hash mismatch")
    if len(templates) > 0xFFFF:
        raise RuntimeError("template identifier exceeds uint16_t")

    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    grouped: dict[int, list[dict]] = defaultdict(list)
    for row in compact_rows:
        grouped[row["group"]].append(row)
    groups = sorted(grouped)

    generated: dict[str, str] = {}
    generated["static_core_compact_generated.h"] = render_header(groups)
    generated["static_core_compact_templates.c"] = render_templates(templates)
    generated["static_core_compact_dispatch.c"] = render_dispatch(compact_rows, groups)
    parameter_words = 0
    for group in groups:
        text, words = render_shard(group, grouped[group])
        generated[f"static_core_compact_group_{group:04X}.c"] = text
        parameter_words += words
    cmake_lines = [
        "# generated compact current authority - do not edit",
        "set(JUNGLE_COMPACT_SCPU_GENERATED_SOURCES",
        "  ${CMAKE_CURRENT_LIST_DIR}/static_core_compact_dispatch.c",
        "  ${CMAKE_CURRENT_LIST_DIR}/static_core_compact_templates.c",
    ]
    cmake_lines += [
        f"  ${{CMAKE_CURRENT_LIST_DIR}}/static_core_compact_group_{group:04X}.c"
        for group in groups
    ]
    cmake_lines += [")", ""]
    generated["static_core_compact_sources.cmake"] = "\n".join(cmake_lines)

    file_receipts = {}
    for name, text in generated.items():
        data = text.encode("utf-8")
        (out / name).write_bytes(data)
        file_receipts[name] = {"bytes": len(data), "sha256": sha256_bytes(data)}

    source_names = [name for name in generated if name.endswith((".c", ".h"))]
    source_bytes = sum(file_receipts[name]["bytes"] for name in source_names)
    owner_counts: dict[str, int] = defaultdict(int)
    for row in compact_rows:
        owner_counts[row["layer"]] += 1
    manifest = {
        "format": "jungle-strike-1.0.0-compact-exact-context-aot-v1",
        "status": "COMPACT_REPRESENTATION_CANDIDATE",
        "rom_sha256": EXPECTED_ROM_SHA256,
        "runtime_context_identity": "PBR:PC:E:M:X",
        "runtime_context_count": len(compact_rows),
        "semantic_template_count": len(templates),
        "parameter_word_count": parameter_words,
        "generated_shard_count": len(groups),
        "generated_source_files": len(source_names),
        "generated_source_bytes": source_bytes,
        "authority_owner_contexts": dict(sorted(owner_counts.items())),
        "input_generated_files": inputs,
        "output_files": file_receipts,
        "original_semantics_sha256": original_hash.hexdigest(),
        "reconstructed_semantics_sha256": reconstructed_hash.hexdigest(),
        "all_context_semantics_reconstructed_exactly": True,
        "runtime_rom_opcode_decode": False,
        "runtime_target_learning": False,
        "runtime_emulator_fallback": False,
        "exact_context_resume_points_preserved": True,
        "unknown_contexts_fail_closed": True,
    }
    manifest_text = json.dumps(manifest, indent=2, sort_keys=True) + "\n"
    (out / "static_core_compact_manifest.json").write_text(
        manifest_text, encoding="utf-8", newline="\n"
    )
    print(json.dumps({
        "contexts": len(compact_rows),
        "templates": len(templates),
        "parameter_words": parameter_words,
        "shards": len(groups),
        "source_files": len(source_names),
        "source_bytes": source_bytes,
        "semantics_sha256": original_hash.hexdigest(),
    }, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
