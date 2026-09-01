/* Generated exact-PC cumulative static S-SMP dispatch. */

case 0x0840u: {
  op_io();
  regs.p.p = 0;
  break;
}

case 0x0841u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0843u: {
  op_io();
  regs.sp = regs.x;
  break;
}

case 0x0844u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0846u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0849u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x084cu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x084fu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0852u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0855u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0858u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x085bu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x085eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0861u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0863u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0866u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0868u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x086au: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x086cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x086eu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0870u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0873u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0876u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0879u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x087cu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x087eu: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x087fu: {
  switch(++resume_cycle) {
  case 1:
    op_io(2);
    break;
  case 2:
    op_writedp(regs.x++, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0880u: {
  rd = op_readpc();
  regs.x = op_cmp(regs.x, rd);
  break;
}

case 0x0882u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0884u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0885u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0888u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x088bu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x088eu: {
  rd = op_readpc();
  op_io();
  regs.B.y--;
  op_io();
  if(regs.B.y == 0x00){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0890u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0892u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x0893u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x0896u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0898u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x089au: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x089du: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x089fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08a1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08a3u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08a5u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x08a8u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08abu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08aeu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x08b1u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x08b4u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x08b7u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x08b9u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08bcu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08bfu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08c1u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x08c3u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08c5u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08c8u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08cau: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08cdu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08d0u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08d3u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08d6u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08d8u: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x08dau: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08dcu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08deu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08e1u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08e4u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08e7u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08eau: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08ecu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x08eeu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x08f0u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x08f2u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x08f4u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x08f6u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08f8u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x08fau: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x08fcu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x08feu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0900u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0903u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0906u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0909u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x090bu: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x090du: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x090fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0911u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0914u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0917u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x091au: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x091du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x091fu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0921u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0923u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0924u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0926u: {
  op_io();
  regs.B.a = op_lsr(regs.B.a);
  break;
}

case 0x0927u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x092au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x092cu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x092fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0931u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x01) == 0x01){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0934u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0937u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0939u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x02) != 0x02){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x093cu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x093eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0941u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0943u: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0945u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0948u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x094bu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x094du: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x094fu: {
  op_io();
  regs.B.a = op_dec(regs.B.a);
  break;
}

case 0x0950u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0952u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x40) == 0x40){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0955u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0958u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0959u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x095bu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x095du: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x095eu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x095fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0961u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0964u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0967u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x096au: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x096du: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x096fu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0971u: {
  op_io();
  regs.B.a = op_dec(regs.B.a);
  break;
}

case 0x0972u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0974u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x40) == 0x40){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0977u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x097au: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x097bu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x097du: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x097fu: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0980u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0981u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0983u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0985u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0988u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x098bu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x098eu: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x20) == 0x20){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0991u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0993u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0994u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0996u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0997u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0998u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x099au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x099cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x099eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09a1u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09a3u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09a6u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x09a7u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09aau: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09adu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09b0u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09b3u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x09b5u: {
  rd = op_readpc();
  op_io();
  regs.B.y--;
  op_io();
  if(regs.B.y == 0x00){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x09b7u: {
  rd = op_readpc();
  op_io();
  regs.B.y--;
  op_io();
  if(regs.B.y == 0x00){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x09b9u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x09bbu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x09beu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09c1u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09c4u: {
  op_io(2);
  op_writestack(regs.p);
  break;
}

case 0x09c5u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09c7u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09cau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09ccu: {
  op_io();
  regs.p.p = 0;
  break;
}

case 0x09cdu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09cfu: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x09d1u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x09d3u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09d6u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09d9u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09dbu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x09ddu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09dfu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x09e1u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x09e3u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09e5u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x09e7u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09eau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09ecu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09eeu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x09f0u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09f2u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x09f4u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x09f6u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09f8u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09fbu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x09fdu: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x09ffu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0a01u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a03u: {
  op_io(11);
  ya = regs.ya;
  //overflow set if quotient >= 256
  regs.p.v = !!(regs.B.y >= regs.x);
  regs.p.h = !!((regs.B.y & 15) >= (regs.x & 15));
  if(regs.B.y < (regs.x << 1)) {
    //if quotient is <= 511 (will fit into 9-bit result)
    regs.B.a = ya / regs.x;
    regs.B.y = ya % regs.x;
  } else {
    //otherwise, the quotient won't fit into regs.p.v + regs.B.a
    //this emulates the odd behavior of the S-SMP in this case
    regs.B.a = 255    - (ya - (regs.x << 9)) / (256 - regs.x);
    regs.B.y = regs.x + (ya - (regs.x << 9)) % (256 - regs.x);
  }
  //result is set based on a (quotient) only
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0a04u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a06u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a08u: {
  op_io(11);
  ya = regs.ya;
  //overflow set if quotient >= 256
  regs.p.v = !!(regs.B.y >= regs.x);
  regs.p.h = !!((regs.B.y & 15) >= (regs.x & 15));
  if(regs.B.y < (regs.x << 1)) {
    //if quotient is <= 511 (will fit into 9-bit result)
    regs.B.a = ya / regs.x;
    regs.B.y = ya % regs.x;
  } else {
    //otherwise, the quotient won't fit into regs.p.v + regs.B.a
    //this emulates the odd behavior of the S-SMP in this case
    regs.B.a = 255    - (ya - (regs.x << 9)) / (256 - regs.x);
    regs.B.y = regs.x + (ya - (regs.x << 9)) % (256 - regs.x);
  }
  //result is set based on a (quotient) only
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0a09u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a0bu: {
  op_io();
  regs.B.y = op_dec(regs.B.y);
  break;
}

case 0x0a0cu: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a0eu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a10u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a12u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a14u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0a17u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a19u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0a1cu: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a1eu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a20u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a22u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0a25u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a27u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0a2au: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a2cu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0a2fu: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a31u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0a33u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a35u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0a37u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a39u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0a3bu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a3du: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a3fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a41u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a43u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a45u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a47u: {
  op_io(2);
  regs.p = op_readstack();
  break;
}

case 0x0a48u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0a4au: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0a4du: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a50u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a53u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a56u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a59u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0a5au: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0a5cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a5eu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0a60u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a62u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0a64u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a66u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a68u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a6au: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a6cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a6eu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a70u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a72u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a74u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a76u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a78u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a7au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a7cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd--;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a7eu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a80u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0a81u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0a83u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a85u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0a87u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a89u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0a8bu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0a8du: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a8fu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a91u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a93u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a95u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a97u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a99u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a9bu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0a9du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0a9fu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0aa1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0aa3u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd--;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0aa5u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0aa7u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0aa9u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0aabu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0aadu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0aafu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ab1u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ab3u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0ab5u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ab7u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ab9u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0abau: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0abcu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0abeu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0ac0u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ac2u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0ac4u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ac6u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ac8u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0acau: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0accu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0aceu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ad0u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0ad2u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ad4u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ad6u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0ad8u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0adau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0adcu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd--;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0adeu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ae0u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0ae2u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ae4u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0ae6u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ae8u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0aeau: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0aecu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0aeeu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0af0u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0af2u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0af4u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0af6u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0af8u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0af9u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0afbu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0afdu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0affu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b01u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0b03u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0b05u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b07u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b09u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0b0bu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b0du: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b0fu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0b10u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0b12u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b14u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0b16u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b18u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0b1au: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0b1cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b1eu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b20u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0b22u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b24u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b26u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0b28u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b2au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b2cu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0b2du: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b30u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b33u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b36u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b39u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b3cu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b3fu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b42u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b45u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b48u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b4bu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b4eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b51u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b54u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b57u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b5au: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b5du: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b60u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b63u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b66u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b69u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b6cu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b6fu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0b71u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0b73u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b76u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b78u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b7bu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b7du: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}

case 0x0b7eu: {
  rd = op_readpc();
  op_io();
  regs.B.y--;
  op_io();
  if(regs.B.y == 0x00){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0b80u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0b82u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0b84u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b86u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b89u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x0b8au: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x0b8cu: {
  rd = op_readpc();
  op_io();
  regs.B.y--;
  op_io();
  if(regs.B.y == 0x00){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0b8eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b91u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0b94u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0ba5u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ba8u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0baau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bacu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0bb2u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bb5u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0bb7u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0bb9u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bbbu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0bbdu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bbfu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0bc1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bc3u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0bc5u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bc7u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bc9u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x0bcau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bccu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bceu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bd0u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd--;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bd2u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0bd4u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bd6u: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_cmp(wr, rd);
  (0) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x0bd9u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0bdbu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_dec(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0bddu: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x0bdfu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0be1u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0be3u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0be5u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0be7u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0be9u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bebu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bedu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0befu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bf1u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bf3u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bf5u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0bf7u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bf9u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0bfbu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0bfdu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0bffu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c01u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c03u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c05u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c07u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c09u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c0bu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c0du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c0fu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c12u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c14u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c16u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c18u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c1au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c1cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c1eu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c20u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c22u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0c24u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c26u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0c29u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0c2cu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0c2eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c31u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0c32u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0c34u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c36u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c39u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c3bu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c3eu: {
  op_io(2);
  op_writestack(regs.B.y);
  break;
}

case 0x0c3fu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c41u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x0c43u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c45u: {
  op_io(2);
  regs.B.y = op_readstack();
  break;
}

case 0x0c46u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0c48u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c4bu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c4eu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0c50u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c53u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0c55u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c58u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c5bu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c5eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c61u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c64u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c67u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c6au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c6du: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c70u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0c72u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c75u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0c77u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c7au: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x0c7bu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    rd = op_readdp(dp);
    regs.B.y = op_cmp(regs.B.y, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c7du: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0c7fu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0c82u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0c84u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c87u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0c8au: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0c8cu: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}

case 0x0c8du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.x = op_cmp(regs.x, rd);
  break;
}

case 0x0c8fu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0c91u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0c92u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c95u: {
  op_io();
  regs.p.c = 1;
  break;
}

case 0x0c96u: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x0c98u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0c9au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0c9du: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0c9eu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0ca0u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ca3u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ca6u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ca9u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cacu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0caeu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cb1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cb3u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0cb5u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cb7u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0cb9u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cbbu: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0cbcu: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0cbeu: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0cc0u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0cc2u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cc5u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0cc6u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0cc8u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0cc9u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0ccbu: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0cccu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0cceu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cd0u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cd2u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x0cd4u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cd6u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cd9u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0cdau: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cddu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0cdeu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ce0u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0ce1u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ce3u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0ce4u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ce6u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0ce7u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ceau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cecu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cefu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cf1u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cf4u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cf6u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0cf7u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0cfau: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0cfcu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0cfeu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0d00u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0d02u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d04u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d07u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d09u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d0cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d0eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d11u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d14u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d16u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0d17u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d19u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x40) != 0x40){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d1cu: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0d1eu: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x20) != 0x20){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d21u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d24u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d27u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0d2au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d2du: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0d30u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0d32u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x20) != 0x20){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d35u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0d36u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d39u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0d3au: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0d3bu: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0d3cu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d3eu: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x0d3fu: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x0d41u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d43u: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0d44u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0d45u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d48u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0d49u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d4cu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0d4du: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d4fu: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0d51u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d53u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d56u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d59u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0d5bu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d5eu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0d60u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0d63u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0d64u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0d65u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d68u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0d69u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0d6cu: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0d6du: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0d6fu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0db0u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0db2u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0db5u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0db8u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dbau: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dbdu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dbfu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.y = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dc1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dc3u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x0dc4u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dc6u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dc8u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x0dc9u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dcbu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0dcdu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0dcfu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd--;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0dd1u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dd3u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0dd5u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x0dd7u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ddau: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0ddbu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ddeu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0de1u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0de3u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0de6u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0de9u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0decu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0defu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0df2u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0df5u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0df7u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0df8u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0df9u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0dfbu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0dfdu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0dfeu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e00u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e02u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e04u: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0e05u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0e06u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e09u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0e0au: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e0du: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0e0eu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0e10u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e13u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e16u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e18u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e1au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e1du: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e20u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e22u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e24u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e27u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e2au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e2cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e2eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e31u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0e32u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0e34u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0e35u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0e37u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0e38u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0e3au: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0e3bu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0e3du: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e3fu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e41u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x0e43u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e45u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e48u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0e49u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e4cu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e4fu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0e50u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e53u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  rd |= op_readdp(dp + 1) << 8;
  op_cmpw(regs.ya, rd);
  break;
}

case 0x0e55u: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0e57u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0e59u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e5bu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e5du: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e60u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e63u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0e65u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e67u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e69u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0e6bu: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}

case 0x0e6cu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e6fu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e72u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e74u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e76u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0e77u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e7au: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0e7bu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0e7du: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e80u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e83u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e86u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e88u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0e8au: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0e8bu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e8eu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0e8fu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0e91u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e94u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e97u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0e9au: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0e9cu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0e9fu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0ea2u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0ea4u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ea7u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0eaau: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0eacu: {
  rd = op_readpc();
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x0eaeu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0eb1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0eb3u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0eb5u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0eb8u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ebau: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0ebcu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ebfu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ec1u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0ec3u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ec6u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ec8u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0ecau: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0ecdu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0ed0u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ed3u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ed5u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ed7u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0ed9u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0edbu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0eddu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0ee0u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x0ee1u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0ee3u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    break;
  case 2:
    regs.x = op_readaddr(sp);
    regs.p.n = !!(regs.x & 0x80);
    regs.p.z = (regs.x == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ee6u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ee9u: {
  op_io(11);
  ya = regs.ya;
  //overflow set if quotient >= 256
  regs.p.v = !!(regs.B.y >= regs.x);
  regs.p.h = !!((regs.B.y & 15) >= (regs.x & 15));
  if(regs.B.y < (regs.x << 1)) {
    //if quotient is <= 511 (will fit into 9-bit result)
    regs.B.a = ya / regs.x;
    regs.B.y = ya % regs.x;
  } else {
    //otherwise, the quotient won't fit into regs.p.v + regs.B.a
    //this emulates the odd behavior of the S-SMP in this case
    regs.B.a = 255    - (ya - (regs.x << 9)) / (256 - regs.x);
    regs.B.y = regs.x + (ya - (regs.x << 9)) % (256 - regs.x);
  }
  //result is set based on a (quotient) only
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0eeau: {
  op_io(2);
  regs.x = op_readstack();
  break;
}

case 0x0eebu: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0eecu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0eeeu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ef0u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0ef2u: {
  op_io(2);
  regs.B.y = op_readstack();
  break;
}

case 0x0ef3u: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0ef4u: {
  rd = op_readpc();
  regs.B.y = op_cmp(regs.B.y, rd);
  break;
}

case 0x0ef6u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0ef8u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0efau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0efcu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0effu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0f01u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    op_io();
    break;
  case 2:
    sp  = op_readdp(dp);
    break;
  case 3:
    sp |= op_readdp(dp + 1) << 8;
    break;
  case 4:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f03u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0f05u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f08u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f0bu: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0f0cu: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0f0eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f11u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0f13u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0f14u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0f16u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f18u: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_cmp(wr, rd);
  (0) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x0f1bu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0f1du: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f20u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0f21u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f24u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_subw(regs.ya, rd);
  break;
}

case 0x0f26u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f28u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f2bu: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x80) == 0x80){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0f2eu: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_eor(wr, rd);
  (1) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x0f31u: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_eor(wr, rd);
  (1) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x0f34u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0f36u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x0f37u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.x = op_readdp(sp);
    regs.p.n = !!(regs.x & 0x80);
    regs.p.z = (regs.x == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f39u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f3bu: {
  op_io(11);
  ya = regs.ya;
  //overflow set if quotient >= 256
  regs.p.v = !!(regs.B.y >= regs.x);
  regs.p.h = !!((regs.B.y & 15) >= (regs.x & 15));
  if(regs.B.y < (regs.x << 1)) {
    //if quotient is <= 511 (will fit into 9-bit result)
    regs.B.a = ya / regs.x;
    regs.B.y = ya % regs.x;
  } else {
    //otherwise, the quotient won't fit into regs.p.v + regs.B.a
    //this emulates the odd behavior of the S-SMP in this case
    regs.B.a = 255    - (ya - (regs.x << 9)) / (256 - regs.x);
    regs.B.y = regs.x + (ya - (regs.x << 9)) % (256 - regs.x);
  }
  //result is set based on a (quotient) only
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0f3cu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f3eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f41u: {
  op_io(2);
  regs.x = op_readstack();
  break;
}

case 0x0f42u: {
  dp = op_readpc();
  sp = op_readdp(dp);
  rd = op_readpc();
  op_io();
  if((sp & 0x80) != 0x80){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0f45u: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_eor(wr, rd);
  (1) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x0f48u: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_eor(wr, rd);
  (1) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x0f4bu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd++;
  op_writedp(dp++, rd);
  rd += op_readdp(dp) << 8;
  op_writedp(dp, rd >> 8);
  regs.p.n = !!(rd & 0x8000);
  regs.p.z = (rd == 0);
  break;
}

case 0x0f4du: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f4fu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f52u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f54u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f57u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0f5au: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f5cu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f5fu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f61u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f64u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0f67u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0f68u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0f69u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f6bu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x0f6eu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x0f71u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f73u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x0f76u: {
  rd = op_readpc();
  regs.x = op_cmp(regs.x, rd);
  break;
}

case 0x0f78u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0f7au: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0f7cu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f7eu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f81u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0f83u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f85u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f88u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f8bu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f8eu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f90u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0f93u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0f94u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0f96u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0f97u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0f99u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0f9au: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0f9cu: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0f9du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0f9fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fa1u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0fa2u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  regs.pc = rd;
  break;
}

case 0x0fa5u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0fa6u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0fa7u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x0fa8u: {
  op_io(2);
  op_writestack(regs.B.y);
  break;
}

case 0x0fa9u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0facu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0faeu: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0fb0u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fb3u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fb5u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x0fb7u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0fb9u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0fbau: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0fbcu: {
  op_io();
  regs.B.a = regs.x;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0fbdu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0fbeu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fc1u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fc3u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0fc5u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0fc7u: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0fc9u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fcbu: {
  op_io();
  regs.B.a = regs.x;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0fccu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x0fcdu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fd0u: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}

case 0x0fd1u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0fd3u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0fd5u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0fd6u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0fd7u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fdau: {
  op_io(2);
  regs.B.y = op_readstack();
  break;
}

case 0x0fdbu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x0fdcu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0fddu: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x0fdfu: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x0fe1u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x0fe2u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x0fe3u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x0fe4u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0fe5u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x0fe6u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x0fe7u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0feau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0fecu: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x0fedu: {
  op_io(2);
  regs.p.c = !regs.p.c;
  break;
}

case 0x0feeu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0ff0u: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x0ff2u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0ff4u: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x0ff5u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x0ff7u: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x0ff8u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ffau: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x0ffdu: {
  op_io(4);
  regs.B.a = (regs.B.a >> 4) | (regs.B.a << 4);
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x0ffeu: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1000u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1002u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x1004u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1006u: {
  op_io(2);
  regs.B.y = op_readstack();
  break;
}

case 0x1007u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1009u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x100cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x100eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1011u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1013u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1016u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1018u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x101bu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x101eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1021u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1024u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1027u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x102au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x102du: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1030u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1032u: {
  op_io(4);
  regs.B.a = (regs.B.a >> 4) | (regs.B.a << 4);
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1033u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x1034u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x1035u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}

case 0x1036u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}

case 0x1037u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x103au: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x103bu: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x103cu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x103fu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1042u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x1043u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x1044u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x1047u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x104au: {
  op_io(2);
  regs.x = op_readstack();
  break;
}

case 0x104bu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x104eu: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x104fu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1051u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1053u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1055u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1058u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x105bu: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x105du: {
  op_io(4);
  regs.B.a = (regs.B.a >> 4) | (regs.B.a << 4);
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x105eu: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x105fu: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x1060u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1063u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}

case 0x1064u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}

case 0x1065u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1067u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x106au: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x106bu: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x106cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x106eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1071u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1074u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x1075u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x1076u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x1078u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x107bu: {
  op_io(2);
  regs.x = op_readstack();
  break;
}

case 0x107cu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x107fu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1082u: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1084u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1086u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x1088u: {
  op_io();
  regs.B.a = op_inc(regs.B.a);
  break;
}

case 0x1089u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x108cu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x108fu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1092u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1094u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1097u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x109au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x109du: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10a0u: {
  sp = op_readpc();
  rd = op_readdp(sp);
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_or(wr, rd);
  (1) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x10a3u: {
  sp = op_readpc();
  rd = op_readdp(sp);
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_or(wr, rd);
  (1) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0x10a6u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10a9u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10acu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10aeu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10b1u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10b3u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10b6u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10b8u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x10bbu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x10bdu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10c0u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10c2u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10c5u: {
  op_io(2);
  regs.x = op_readstack();
  break;
}

case 0x10c6u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x10c7u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x10c9u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10ccu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x10ceu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.x = op_readdp(sp);
    regs.p.n = !!(regs.x & 0x80);
    regs.p.z = (regs.x == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10d0u: {
  op_io();
  regs.x = op_dec(regs.x);
  break;
}

case 0x10d1u: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x10d3u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x10d5u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10d8u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10dbu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10ddu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10dfu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10e1u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10e3u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10e6u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10e9u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10ecu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10efu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10f2u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10f5u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10f8u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x10fbu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x10fdu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1100u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1103u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1105u: {
  op_io(2);
  op_writestack(regs.B.y);
  break;
}

case 0x1106u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1109u: {
  op_io(2);
  regs.B.y = op_readstack();
  break;
}

case 0x110au: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x110bu: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x110cu: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x110eu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x110fu: {
  op_io();
  regs.x = op_dec(regs.x);
  break;
}

case 0x1110u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1112u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1115u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1118u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x111au: {
  rd = op_readpc();
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x111cu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x111fu: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1121u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1124u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1127u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x112au: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x112du: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1130u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1133u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1136u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1139u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x113cu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x113eu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1141u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1144u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x1145u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1148u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x114au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.x);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x114cu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x114fu: {
  regs.B.y = op_readpc();
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1151u: {
  op_io(2);
  op_writestack(regs.B.y);
  break;
}

case 0x1152u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1154u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1157u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x115au: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x115cu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x115fu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1162u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1164u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1166u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1169u: {
  rd = op_readpc();
  if(!regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x116bu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x116du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x116fu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1171u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1173u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1175u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1177u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1179u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x117bu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x117du: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1180u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1182u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1185u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1187u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1189u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x118bu: {
  op_io();
  regs.B.a = op_dec(regs.B.a);
  break;
}

case 0x118cu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x118fu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1192u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1194u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1196u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x1198u: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x119au: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_dec(rd);
  op_writedp(dp + regs.x, rd);
  break;
}

case 0x119cu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x119eu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11a0u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x11a2u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x11a4u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11a6u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11a9u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x11abu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x11adu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11afu: {
  op_io(2);
  regs.B.y = op_readstack();
  break;
}

case 0x11b0u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x11b1u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x11b2u: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x11b4u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x11b5u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x11b7u: {
  op_io();
  regs.x = op_inc(regs.x);
  break;
}

case 0x11b8u: {
  rd = op_readpc();
  regs.x = op_cmp(regs.x, rd);
  break;
}

case 0x11bau: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x11bcu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11bfu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11c2u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11c5u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11c8u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11cbu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11ceu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11d1u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11d4u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11d6u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11d9u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11dcu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11dfu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11e1u: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x11e2u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x11e4u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11e6u: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x11e7u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x11e9u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x11eau: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11edu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11efu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11f2u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11f4u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11f7u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11fau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11fcu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x11feu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1201u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1204u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x1206u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1209u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x120cu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_asl(rd);
  op_writedp(dp, rd);
  break;
}

case 0x120eu: {
  op_io();
  regs.x = op_dec(regs.x);
  break;
}

case 0x120fu: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1211u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1213u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1216u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    rd = op_readdp(sp);
    break;
  case 3:
    dp = op_readpc();
    break;
  case 4:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1219u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x121bu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x121eu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1221u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1223u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1226u: {
  op_io();
  regs.p.c = 1;
  break;
}

case 0x1227u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x122au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x122du: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x122fu: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x1232u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    sp |= op_readpc() << 8;
    break;
  case 3:
    regs.B.a = op_readaddr(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1235u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x1236u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x1239u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    break;
  case 2:
    dp |= op_readpc() << 8;
    break;
  case 3:
    op_readaddr_discard(dp);
    break;
  case 4:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x123cu: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x123eu: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x123fu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1241u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1243u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1245u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1247u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1249u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x124cu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x124eu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1250u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1252u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1254u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1256u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1259u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x125bu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x125eu: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1260u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1262u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1264u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1266u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1268u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x126bu: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x126cu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x126fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1271u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1274u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1276u: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x1277u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1279u: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x127au: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x127cu: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x127du: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x127fu: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x1280u: {
  rd = op_readpc();
  regs.B.a = op_and(regs.B.a, rd);
  break;
}

case 0x1282u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x1284u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1286u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1288u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x1289u: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x128bu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x128du: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x128fu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1291u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  regs.B.a = op_or(regs.B.a, rd);
  break;
}

case 0x1293u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1295u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x1296u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1299u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x129bu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x129eu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12a0u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12a3u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12a5u: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x12a6u: {
  op_io(2);
  regs.p.c = !regs.p.c;
  break;
}

case 0x12a7u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x12a9u: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x12abu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12adu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12b0u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x12b1u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12b4u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x12b6u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12b8u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12bbu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x12bcu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12bfu: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x12c1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12c3u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x12c4u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12c7u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x12c8u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x12cau: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12cdu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x12ceu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12d1u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x12d3u: {
  op_io(2);
  op_writestack(regs.x);
  break;
}

case 0x12d4u: {
  rd  = op_readpc();
  rd |= op_readpc() << 8;
  op_io(3);
  op_writestack(regs.pc >> 8);
  op_writestack(regs.pc);
  regs.pc = rd;
  break;
}

case 0x12d7u: {
  op_io(2);
  regs.x = op_readstack();
  break;
}

case 0x12d8u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x12d9u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0x12dbu: {
  op_io(11);
  ya = regs.ya;
  //overflow set if quotient >= 256
  regs.p.v = !!(regs.B.y >= regs.x);
  regs.p.h = !!((regs.B.y & 15) >= (regs.x & 15));
  if(regs.B.y < (regs.x << 1)) {
    //if quotient is <= 511 (will fit into 9-bit result)
    regs.B.a = ya / regs.x;
    regs.B.y = ya % regs.x;
  } else {
    //otherwise, the quotient won't fit into regs.p.v + regs.B.a
    //this emulates the odd behavior of the S-SMP in this case
    regs.B.a = 255    - (ya - (regs.x << 9)) / (256 - regs.x);
    regs.B.y = regs.x + (ya - (regs.x << 9)) % (256 - regs.x);
  }
  //result is set based on a (quotient) only
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x12dcu: {
  op_io();
  regs.p.c = 1;
  break;
}

case 0x12ddu: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x12dfu: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x12e1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12e3u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12e6u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12e8u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12ebu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12edu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_lsr(rd);
  op_writedp(dp, rd);
  break;
}

case 0x12efu: {
  op_io();
  regs.B.a = op_ror(regs.B.a);
    break;
}

case 0x12f0u: {
  rd = op_readpc();
  op_io();
  regs.B.y--;
  op_io();
  if(regs.B.y == 0x00){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x12f2u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x12f3u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x12f6u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12f8u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x12fau: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x12fcu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  rd = op_readaddr(dp);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x12ffu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1301u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1303u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x1304u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.y = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1306u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1309u: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x130au: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x130cu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x130fu: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x1310u: {
  rd = op_readpc();
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x1312u: {
  op_io();
  regs.B.a = op_lsr(regs.B.a);
  break;
}

case 0x1313u: {
  op_io();
  regs.B.a = op_lsr(regs.B.a);
  break;
}

case 0x1314u: {
  op_io();
  regs.B.a = op_lsr(regs.B.a);
  break;
}

case 0x1315u: {
  op_io();
  regs.B.a = op_lsr(regs.B.a);
  break;
}

case 0x1316u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x1317u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1318u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x131bu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x131cu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x131eu: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x131fu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1321u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1323u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x1324u: {
  rd = op_readpc();
  regs.B.a = op_eor(regs.B.a, rd);
  break;
}

case 0x1326u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1327u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x132au: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x132bu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x132du: {
  op_io(8);
  ya = regs.B.y * regs.B.a;
  regs.B.a = ya;
  regs.B.y = ya >> 8;
  //result is set based on y (high-byte) only
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x132eu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1330u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1332u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0x1343u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1346u: {
  rd = op_readpc();
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x1348u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x134au: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x134bu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x134du: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x134fu: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x1350u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x1351u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1352u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x1355u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1357u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x135au: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x135cu: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x135eu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1361u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1362u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1365u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1367u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1369u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x136au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x136cu: {
  dp = op_readpc();
  op_io();
  rd = op_readdp(dp + regs.x);
  rd = op_dec(rd);
  op_writedp(dp + regs.x, rd);
  break;
}

case 0x136eu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1371u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1373u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1376u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1378u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x137bu: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x137cu: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x137du: {
  op_io(2);
  regs.p.c = !regs.p.c;
  break;
}

case 0x137eu: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1380u: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x1382u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1383u: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x1384u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x1386u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1389u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x138au: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x138du: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    op_io();
    break;
  case 2:
    regs.B.a = op_readdp(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x138fu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x1392u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1394u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x1395u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.B.y);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1398u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x139bu: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0x139cu: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x139du: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_cmp(regs.B.a, rd);
  break;
}

case 0x13a0u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13a2u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13a5u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13a7u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13aau: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13acu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13afu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x13b0u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13b3u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13b5u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13b8u: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x13b9u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13bcu: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  rd |= op_readdp(dp + 1) << 8;
  op_cmpw(regs.ya, rd);
  break;
}

case 0x13beu: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13c0u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13c3u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13c5u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13c7u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13cau: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  rd |= op_readdp(dp + 1) << 8;
  op_cmpw(regs.ya, rd);
  break;
}

case 0x13ccu: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13ceu: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13d0u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13d3u: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  rd |= op_readdp(dp + 1) << 8;
  op_cmpw(regs.ya, rd);
  break;
}

case 0x13d5u: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13d7u: {
  rd = op_readpc();
  if(!regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13d9u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13dcu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13dfu: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13e2u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13e5u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x13e7u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13eau: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13edu: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13f0u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x13f2u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x13f5u: {
  op_io(2);
  op_writestack(regs.B.a);
  break;
}

case 0x13f6u: {
  op_io();
  regs.B.a = op_rol(regs.B.a);
  break;
}

case 0x13f7u: {
  op_io(2);
  regs.p.c = !regs.p.c;
  break;
}

case 0x13f8u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x13fau: {
  rd = op_readpc();
  regs.B.a = op_sbc(regs.B.a, rd);
  break;
}

case 0x13fcu: {
  op_io();
  regs.B.y = regs.B.a;
  regs.p.n = !!(regs.B.y & 0x80);
  regs.p.z = (regs.B.y == 0);
  break;
}

case 0x13fdu: {
  op_io(2);
  regs.B.a = op_readstack();
  break;
}

case 0x13feu: {
  dp  = op_readpc();
  rd  = op_readdp(dp);
  op_io();
  rd |= op_readdp(dp + 1) << 8;
  regs.ya = op_addw(regs.ya, rd);
  break;
}

case 0x1400u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1403u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0x1404u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1407u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x140au: {
  rd = op_readpc();
  if(!regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x140cu: {
  op_io();
  regs.B.a = op_dec(regs.B.a);
  break;
}

case 0x140du: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1410u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x1412u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1415u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1418u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x1419u: {
  rd = op_readpc();
  if(regs.p.c){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x141bu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x141eu: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1420u: {
  op_io();
  regs.B.a = op_asl(regs.B.a);
  break;
}

case 0x1421u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_rol(rd);
  op_writedp(dp, rd);
  break;
}

case 0x1423u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1426u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1428u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x142bu: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0x142du: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1430u: {
  op_io();
  regs.p.c = 0;
  break;
}

case 0x1431u: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x1434u: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1437u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    sp |= op_readpc() << 8;
    op_io();
    break;
  case 2:
    regs.B.a = op_readaddr(sp + regs.x);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x143au: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  rd = op_readaddr(dp + regs.x);
  regs.B.a = op_adc(regs.B.a, rd);
  break;
}

case 0x143du: {
  switch(++resume_cycle) {
  case 1:
    dp  = op_readpc();
    dp |= op_readpc() << 8;
    op_io();
    dp += regs.x;
    break;
  case 2:
    op_readaddr_discard(dp);
    break;
  case 3:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0x1440u: {
  rd  = op_readstack();
  rd |= op_readstack() << 8;
  op_io(2);
  regs.pc = rd;
  break;
}

case 0xffc0u: {
  regs.x = op_readpc();
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0xffc2u: {
  op_io();
  regs.sp = regs.x;
  break;
}

case 0xffc3u: {
  regs.B.a = op_readpc();
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0xffc5u: {
  switch(++resume_cycle) {
  case 1:
    op_io();
    break;
  case 2:
    op_readdp_discard(regs.x);
    break;
  case 3:
    op_writedp(regs.x, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffc6u: {
  op_io();
  regs.x = op_dec(regs.x);
  break;
}

case 0xffc7u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffc9u: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffccu: {
  switch(++resume_cycle) {
  case 1:
    rd = op_readpc();
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffcfu: {
  rd = op_readpc();
  dp = op_readpc();
  wr = op_readdp(dp);
  wr = op_cmp(wr, rd);
  (0) ? op_writedp(dp, wr) : op_io();
  break;
}

case 0xffd2u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffd4u: {
  rd = op_readpc();
  if(0){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffd6u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.y = op_readdp(sp);
    regs.p.n = !!(regs.B.y & 0x80);
    regs.p.z = (regs.B.y == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffd8u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffdau: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    rd = op_readdp(dp);
    regs.B.y = op_cmp(regs.B.y, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffdcu: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffdeu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    regs.p.n = !!(regs.B.a & 0x80);
    regs.p.z = (regs.B.a == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffe0u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffe2u: {
  switch(++resume_cycle) {
  case 1:
    sp  = op_readpc();
    break;
  case 2:
    dp  = op_readdp(sp);
    break;
  case 3:
    dp |= op_readdp(sp + 1) << 8;
    op_io();
    dp += regs.B.y;
    break;
  case 4:
    op_readaddr_discard(dp);
    break;
  case 5:
    op_writeaddr(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffe4u: {
  op_io();
  regs.B.y = op_inc(regs.B.y);
  break;
}

case 0xffe5u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffe7u: {
  dp = op_readpc();
  rd = op_readdp(dp);
  rd = op_inc(rd);
  op_writedp(dp, rd);
  break;
}

case 0xffe9u: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffebu: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    rd = op_readdp(dp);
    regs.B.y = op_cmp(regs.B.y, rd);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xffedu: {
  rd = op_readpc();
  if(regs.p.n){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xffefu: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xfff1u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp,     regs.B.a);
    break;
  case 4:
    op_writedp(dp + 1, regs.B.y);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xfff3u: {
  switch(++resume_cycle) {
  case 1:
    sp = op_readpc();
    break;
  case 2:
    regs.B.a = op_readdp(sp);
    op_io();
    break;
  case 3:
    regs.B.y = op_readdp(sp + 1);
    regs.p.n = !!(regs.ya & 0x8000);
    regs.p.z = (regs.ya == 0);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xfff5u: {
  switch(++resume_cycle) {
  case 1:
    dp = op_readpc();
    break;
  case 2:
    op_readdp_discard(dp);
    break;
  case 3:
    op_writedp(dp, regs.B.a);
    resume_cycle = 0;
    break;
  }
  break;
}

case 0xfff7u: {
  op_io();
  regs.B.a = regs.B.y;
  regs.p.n = !!(regs.B.a & 0x80);
  regs.p.z = (regs.B.a == 0);
  break;
}

case 0xfff8u: {
  op_io();
  regs.x = regs.B.a;
  regs.p.n = !!(regs.x & 0x80);
  regs.p.z = (regs.x == 0);
  break;
}

case 0xfff9u: {
  rd = op_readpc();
  if(regs.p.z){ break; }
  op_io(2);
  regs.pc += (int8)rd;
  break;
}

case 0xfffbu: {
  dp  = op_readpc();
  dp |= op_readpc() << 8;
  op_io();
  dp += regs.x;
  rd  = op_readaddr(dp);
  rd |= op_readaddr(dp + 1) << 8;
  regs.pc = rd;
  break;
}

case 0xfffeu: {
  op_io(2);
  regs.p.i = 0;
  break;
}

case 0xffffu: {
  op_io(2);
  regs.pc--;
  break;
}

default: sc_aot_fail(3u,current_static_pc,0xffu,guard_byte); break;
