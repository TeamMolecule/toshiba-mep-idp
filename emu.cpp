/* IDP emulator for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "mep.hpp"

extern void make_stack_var(op_t &x);

// ********** x-invalid: --invalid--

static int
mep_emu_x_invalid (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

  {
    return 0;
  }

  return 0;
}

// ********** sb: sb $rnc,($rma)

static int
mep_emu_sb (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** sh: sh $rns,($rma)

static int
mep_emu_sh (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ UHI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** sw: sw $rnl,($rma)

static int
mep_emu_sw (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** lb: lb $rnc,($rma)

static int
mep_emu_lb (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTQISI ([&valid](){ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** lh: lh $rns,($rma)

static int
mep_emu_lh (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTHISI ([&valid](){ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** lw: lw $rnl,($rma)

static int
mep_emu_lw (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;

  return 2;
}

// ********** lbu: lbu $rnuc,($rma)

static int
mep_emu_lbu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTQISI ([&valid](){ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** lhu: lhu $rnus,($rma)

static int
mep_emu_lhu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTHISI ([&valid](){ UHI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** sw-sp: sw $rnl,$udisp7a4($spr)

static int
mep_emu_sw_sp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ((((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) + ([&valid](){ valid = 0; return 0; }()))) & ((~ (3)))); if (valid) ua_add_dref(0, val, dr_W); }
}

  make_stack_var(cmd.Op2);

  return 2;
}

// ********** lw-sp: lw $rnl,$udisp7a4($spr)

static int
mep_emu_lw_sp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ SI val = ((((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) + ([&valid](){ valid = 0; return 0; }()))) & ((~ (3)))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
  make_stack_var(cmd.Op2);

  return 2;
}

// ********** sb-tp: sb $rn3c,$udisp7($tpr)

static int
mep_emu_sb_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ QI val = ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** sh-tp: sh $rn3s,$udisp7a2($tpr)

static int
mep_emu_sh_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ HI val = ANDSI (ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()), (~ (1))); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** sw-tp: sw $rn3l,$udisp7a4($tpr)

static int
mep_emu_sw_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI (ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()), (~ (3))); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** lb-tp: lb $rn3c,$udisp7($tpr)

static int
mep_emu_lb_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTQISI ([&valid](){ QI val = ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** lh-tp: lh $rn3s,$udisp7a2($tpr)

static int
mep_emu_lh_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTHISI ([&valid](){ HI val = ANDSI (ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()), (~ (1))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** lw-tp: lw $rn3l,$udisp7a4($tpr)

static int
mep_emu_lw_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ SI val = ANDSI (ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()), (~ (3))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;

  return 2;
}

// ********** lbu-tp: lbu $rn3uc,$udisp7($tpr)

static int
mep_emu_lbu_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTQISI ([&valid](){ QI val = ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** lhu-tp: lhu $rn3us,$udisp7a2($tpr)

static int
mep_emu_lhu_tp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTHISI ([&valid](){ HI val = ANDSI (ADDSI (ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), [&valid](){ valid = 0; return 0; }()), (~ (1))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);

  return 2;
}

// ********** sb16: sb $rnc,$sdisp16($rma)

static int
mep_emu_sb16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ QI val = ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)); if (valid) ua_add_dref(0, val, dr_W); }
}

  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** sh16: sh $rns,$sdisp16($rma)

static int
mep_emu_sh16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ HI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)), (~ (1))); if (valid) ua_add_dref(0, val, dr_W); }
}
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** sw16: sw $rnl,$sdisp16($rma)

static int
mep_emu_sw16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)), (~ (3))); if (valid) ua_add_dref(0, val, dr_W); }
}
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** lb16: lb $rnc,$sdisp16($rma)

static int
mep_emu_lb16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTQISI ([&valid](){ QI val = ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** lh16: lh $rns,$sdisp16($rma)

static int
mep_emu_lh16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTHISI ([&valid](){ HI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)), (~ (1))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** lw16: lw $rnl,$sdisp16($rma)

static int
mep_emu_lw16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ SI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)), (~ (3))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** lbu16: lbu $rnuc,$sdisp16($rma)

static int
mep_emu_lbu16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTQISI ([&valid](){ QI val = ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** lhu16: lhu $rnus,$sdisp16($rma)

static int
mep_emu_lhu16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTHISI ([&valid](){ HI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr)), (~ (1))); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
  if (cmd.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(cmd.Op2);

  return 4;
}

// ********** sw24: sw $rnl,($addr24a4)

static int
mep_emu_sw24 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 4;
}

// ********** lw24: lw $rnl,($addr24a4)

static int
mep_emu_lw24 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ SI val = ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;

  return 4;
}

// ********** extb: extb $rn

static int
mep_emu_extb (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTQISI (ANDQI ([&valid](){ valid = 0; return 0; }(), 255));

  return 2;
}

// ********** exth: exth $rn

static int
mep_emu_exth (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTHISI (ANDHI ([&valid](){ valid = 0; return 0; }(), 65535));

  return 2;
}

// ********** extub: extub $rn

static int
mep_emu_extub (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTSISI (ANDSI ([&valid](){ valid = 0; return 0; }(), 255));

  return 2;
}

// ********** extuh: extuh $rn

static int
mep_emu_extuh (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTSISI (ANDSI ([&valid](){ valid = 0; return 0; }(), 65535));

  return 2;
}

// ********** ssarb: ssarb $udisp2($rm)

static int
mep_emu_ssarb (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ZEXTSISI (((((((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) + ([&valid](){ valid = 0; return 0; }()))) & (3))) * (8)));
((32) - (ZEXTSISI (((((((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) + ([&valid](){ valid = 0; return 0; }()))) & (3))) * (8)))));
}

  return 2;
}

// ********** mov: mov $rn,$rm

static int
mep_emu_mov (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** movi8: mov $rn,$simm8

static int
mep_emu_movi8 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 2;
}

// ********** movi16: mov $rn,$simm16

static int
mep_emu_movi16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 4;
}

// ********** movu24: movu $rn3,$uimm24

static int
mep_emu_movu24 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 4;
}

// ********** movu16: movu $rn,$uimm16

static int
mep_emu_movu16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ZEXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 4;
}

// ********** movh: movh $rn,$uimm16

static int
mep_emu_movh (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) << (16));

  return 4;
}

// ********** add3: add3 $rl,$rn,$rm

static int
mep_emu_add3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ADDSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** add: add $rn,$simm6

static int
mep_emu_add (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr));
  if (cmd.Op1.reg == REGS_HW_H_GPR_BASE + 15)
    add_auto_stkpnt2(NULL, cmd.ea+cmd.size, (sval_t)cmd.Op2.value);

  return 2;
}

// ********** add3i: add3 $rn,$spr,$uimm7a4

static int
mep_emu_add3i (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ADDSI ([&valid](){ valid = 0; return 0; }(), ZEXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
  add_auto_stkpnt2(NULL, cmd.ea+cmd.size, (sval_t)cmd.Op3.value);

  return 2;
}

// ********** advck3: advck3 \$0,$rn,$rm

static int
mep_emu_advck3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sub: sub $rn,$rm

static int
mep_emu_sub (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SUBSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** sbvck3: sbvck3 \$0,$rn,$rm

static int
mep_emu_sbvck3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** neg: neg $rn,$rm

static int
mep_emu_neg (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

NEGSI ([&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** slt3: slt3 \$0,$rn,$rm

static int
mep_emu_slt3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sltu3: sltu3 \$0,$rn,$rm

static int
mep_emu_sltu3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** slt3i: slt3 \$0,$rn,$uimm5

static int
mep_emu_slt3i (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sltu3i: sltu3 \$0,$rn,$uimm5

static int
mep_emu_sltu3i (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sl1ad3: sl1ad3 \$0,$rn,$rm

static int
mep_emu_sl1ad3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ADDSI (SLLSI ([&valid](){ valid = 0; return 0; }(), 1), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** sl2ad3: sl2ad3 \$0,$rn,$rm

static int
mep_emu_sl2ad3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ADDSI (SLLSI ([&valid](){ valid = 0; return 0; }(), 2), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** add3x: add3 $rn,$rm,$simm16

static int
mep_emu_add3x (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
  if (cmd.Op1.reg == REGS_HW_H_GPR_BASE + 15 && cmd.Op2.reg == REGS_HW_H_GPR_BASE + 15)
    add_auto_stkpnt2(NULL, cmd.ea+cmd.size, (sval_t)cmd.Op3.value);

  return 4;
}

// ********** slt3x: slt3 $rn,$rm,$simm16

static int
mep_emu_slt3x (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 4;
}

// ********** sltu3x: sltu3 $rn,$rm,$uimm16

static int
mep_emu_sltu3x (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
1;
0;
}

  return 4;
}

// ********** or: or $rn,$rm

static int
mep_emu_or (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** and: and $rn,$rm

static int
mep_emu_and (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ANDSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** xor: xor $rn,$rm

static int
mep_emu_xor (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

XORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());

  return 2;
}

// ********** nor: nor $rn,$rm

static int
mep_emu_nor (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

INVSI (ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }()));

  return 2;
}

// ********** or3: or3 $rn,$rm,$uimm16

static int
mep_emu_or3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ORSI ([&valid](){ valid = 0; return 0; }(), ZEXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));

  return 4;
}

// ********** and3: and3 $rn,$rm,$uimm16

static int
mep_emu_and3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ANDSI ([&valid](){ valid = 0; return 0; }(), ZEXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));

  return 4;
}

// ********** xor3: xor3 $rn,$rm,$uimm16

static int
mep_emu_xor3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

XORSI ([&valid](){ valid = 0; return 0; }(), ZEXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));

  return 4;
}

// ********** sra: sra $rn,$rm

static int
mep_emu_sra (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SRASI ([&valid](){ valid = 0; return 0; }(), ANDSI ([&valid](){ valid = 0; return 0; }(), 31));

  return 2;
}

// ********** srl: srl $rn,$rm

static int
mep_emu_srl (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SRLSI ([&valid](){ valid = 0; return 0; }(), ANDSI ([&valid](){ valid = 0; return 0; }(), 31));

  return 2;
}

// ********** sll: sll $rn,$rm

static int
mep_emu_sll (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SLLSI ([&valid](){ valid = 0; return 0; }(), ANDSI ([&valid](){ valid = 0; return 0; }(), 31));

  return 2;
}

// ********** srai: sra $rn,$uimm5

static int
mep_emu_srai (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SRASI ([&valid](){ valid = 0; return 0; }(), cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 2;
}

// ********** srli: srl $rn,$uimm5

static int
mep_emu_srli (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SRLSI ([&valid](){ valid = 0; return 0; }(), cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 2;
}

// ********** slli: sll $rn,$uimm5

static int
mep_emu_slli (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SLLSI ([&valid](){ valid = 0; return 0; }(), cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 2;
}

// ********** sll3: sll3 \$0,$rn,$uimm5

static int
mep_emu_sll3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SLLSI ([&valid](){ valid = 0; return 0; }(), cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr);

  return 2;
}

// ********** fsft: fsft $rn,$rm

static int
mep_emu_fsft (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_temp;
  QI tmp_shamt;
  tmp_shamt = ANDSI ([&valid](){ valid = 0; return 0; }(), 63);
  tmp_temp = SLLDI (ORDI (SLLDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&valid](){ valid = 0; return 0; }())), tmp_shamt);
SUBWORDDISI (SRLDI (tmp_temp, 32), 1);
}

  return 2;
}

// ********** bra: bra $pcrel12a2

static int
mep_emu_bra (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = ((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** beqz: beqz $rn,$pcrel8a2

static int
mep_emu_beqz (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** bnez: bnez $rn,$pcrel8a2

static int
mep_emu_bnez (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** beqi: beqi $rn,$uimm4,$pcrel17a2

static int
mep_emu_beqi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bnei: bnei $rn,$uimm4,$pcrel17a2

static int
mep_emu_bnei (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** blti: blti $rn,$uimm4,$pcrel17a2

static int
mep_emu_blti (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bgei: bgei $rn,$uimm4,$pcrel17a2

static int
mep_emu_bgei (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** beq: beq $rn,$rm,$pcrel17a2

static int
mep_emu_beq (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bne: bne $rn,$rm,$pcrel17a2

static int
mep_emu_bne (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ((cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bsr12: bsr $pcrel12a2

static int
mep_emu_bsr12 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ADDSI (pc, 2);
{ USI val = ((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** bsr24: bsr $pcrel24a2

static int
mep_emu_bsr24 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ADDSI (pc, 4);
{ USI val = ((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** jmp: jmp $rm

static int
mep_emu_jmp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{
{
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
}
}

  return 2;
}

// ********** jmp24: jmp $pcabs24a2

static int
mep_emu_jmp24 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ USI val = ANDSI (ORSI (ANDSI (pc, 0xf0000000), cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** jsr: jsr $rm

static int
mep_emu_jsr (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ADDSI (pc, 2);
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** ret: ret

static int
mep_emu_ret (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{
{
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
}
}

  return 2;
}

// ********** repeat: repeat $rn,$pcrel17a2

static int
mep_emu_repeat (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ADDSI (pc, 4);
((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1))));
[&valid](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** erepeat: erepeat $pcrel17a2

static int
mep_emu_erepeat (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ADDSI (pc, 4);
((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) & ((~ (1))));
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (0))))), ((((1) << (0))) & (((1) << (0)))));
1;
}

  return 4;
}

// ********** stc_lp: stc $rn,\$lp

static int
mep_emu_stc_lp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** stc_hi: stc $rn,\$hi

static int
mep_emu_stc_hi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** stc_lo: stc $rn,\$lo

static int
mep_emu_stc_lo (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** stc: stc $rn,$csrn

static int
mep_emu_stc (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc_lp: ldc $rn,\$lp

static int
mep_emu_ldc_lp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc_hi: ldc $rn,\$hi

static int
mep_emu_ldc_hi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc_lo: ldc $rn,\$lo

static int
mep_emu_ldc_lo (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc: ldc $rn,$csrn

static int
mep_emu_ldc (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ADDSI (pc, 2);
[&valid](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** di: di

static int
mep_emu_di (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

SLLSI (SRLSI ([&valid](){ valid = 0; return 0; }(), 1), 1);

  return 2;
}

// ********** ei: ei

static int
mep_emu_ei (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ORSI ([&valid](){ valid = 0; return 0; }(), 1);

  return 2;
}

// ********** reti: reti

static int
mep_emu_reti (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{
{
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (9))))), ((((1) << (9))) & (((0) << (9)))));
}
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (9))))), ((((1) << (9))) & (((0) << (9)))));
}
}
{
{
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (2))))), ((((1) << (2))) & (SLLSI (ANDSI (SRLSI ([&valid](){ valid = 0; return 0; }(), 3), 1), 2))));
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (0))))), ((((1) << (0))) & (SLLSI (ANDSI (SRLSI ([&valid](){ valid = 0; return 0; }(), 1), 1), 0))));
}
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (1))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (2))))), ((((1) << (2))) & (SLLSI (ANDSI (SRLSI ([&valid](){ valid = 0; return 0; }(), 3), 1), 2))));
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (0))))), ((((1) << (0))) & (SLLSI (ANDSI (SRLSI ([&valid](){ valid = 0; return 0; }(), 1), 1), 0))));
}
}
}
((void) 0); /*nop*/
}

  return 2;
}

// ********** halt: halt

static int
mep_emu_halt (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

ORSI ([&valid](){ valid = 0; return 0; }(), ((1) << (11)));

  return 2;
}

// ********** sleep: sleep

static int
mep_emu_sleep (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;


  return 2;
}

// ********** swi: swi $uimm2

static int
mep_emu_swi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ORSI ([&valid](){ valid = 0; return 0; }(), ((1) << (4)));
ORSI ([&valid](){ valid = 0; return 0; }(), ((1) << (5)));
ORSI ([&valid](){ valid = 0; return 0; }(), ((1) << (6)));
ORSI ([&valid](){ valid = 0; return 0; }(), ((1) << (7)));
}

  return 2;
}

// ********** break: break

static int
mep_emu_break (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** syncm: syncm

static int
mep_emu_syncm (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

((void) 0); /*nop*/

  return 2;
}

// ********** stcb: stcb $rn,$uimm16

static int
mep_emu_stcb (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;


  return 4;
}

// ********** ldcb: ldcb $rn,$uimm16

static int
mep_emu_ldcb (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

[&valid](){ valid = 0; return 0; }();

  return 4;
}

// ********** bsetm: bsetm ($rma),$uimm3

static int
mep_emu_bsetm (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** bclrm: bclrm ($rma),$uimm3

static int
mep_emu_bclrm (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** bnotm: bnotm ($rma),$uimm3

static int
mep_emu_bnotm (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** btstm: btstm \$0,($rma),$uimm3

static int
mep_emu_btstm (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ZEXTQISI (ANDQI ([&valid](){ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
, ((1) << (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr))));
}

  return 2;
}

// ********** tas: tas $rn,($rma)

static int
mep_emu_tas (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  SI tmp_result;
  tmp_result = ZEXTQISI ([&valid](){ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
{ UQI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
tmp_result;
}

  return 2;
}

// ********** cache: cache $cimm4,($rma)

static int
mep_emu_cache (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;


  return 2;
}

// ********** mul: mul $rn,$rm

static int
mep_emu_mul (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI ([&valid](){ valid = 0; return 0; }()), EXTSIDI ([&valid](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** mulu: mulu $rn,$rm

static int
mep_emu_mulu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), ZEXTSIDI ([&valid](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** mulr: mulr $rn,$rm

static int
mep_emu_mulr (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI ([&valid](){ valid = 0; return 0; }()), EXTSIDI ([&valid](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** mulru: mulru $rn,$rm

static int
mep_emu_mulru (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), ZEXTSIDI ([&valid](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** madd: madd $rn,$rm

static int
mep_emu_madd (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&valid](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (EXTSIDI ([&valid](){ valid = 0; return 0; }()), EXTSIDI ([&valid](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** maddu: maddu $rn,$rm

static int
mep_emu_maddu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&valid](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), ZEXTSIDI ([&valid](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** maddr: maddr $rn,$rm

static int
mep_emu_maddr (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&valid](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (EXTSIDI ([&valid](){ valid = 0; return 0; }()), EXTSIDI ([&valid](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** maddru: maddru $rn,$rm

static int
mep_emu_maddru (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&valid](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (ZEXTSIDI ([&valid](){ valid = 0; return 0; }()), ZEXTSIDI ([&valid](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** div: div $rn,$rm

static int
mep_emu_div (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{
{
0x80000000;
0;
}
{
DIVSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
MODSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
}
}
}
}

  return 2;
}

// ********** divu: divu $rn,$rm

static int
mep_emu_divu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{
UDIVSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
UMODSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
}
}
}

  return 2;
}

// ********** dret: dret

static int
mep_emu_dret (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (SLLSI (1, 15)));
{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** dbreak: dbreak

static int
mep_emu_dbreak (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ORSI ([&valid](){ valid = 0; return 0; }(), 1);
}

  return 2;
}

// ********** ldz: ldz $rn,$rm

static int
mep_emu_ldz (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** abs: abs $rn,$rm

static int
mep_emu_abs (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
ABSSI (SUBSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }()));
}

  return 4;
}

// ********** ave: ave $rn,$rm

static int
mep_emu_ave (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
SRASI (ADDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }()), 1), 1);
}

  return 4;
}

// ********** min: min $rn,$rm

static int
mep_emu_min (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
[&valid](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** max: max $rn,$rm

static int
mep_emu_max (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
[&valid](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** minu: minu $rn,$rm

static int
mep_emu_minu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
[&valid](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** maxu: maxu $rn,$rm

static int
mep_emu_maxu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
[&valid](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** clip: clip $rn,$cimm5

static int
mep_emu_clip (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  SI tmp_min;
  SI tmp_max;
  tmp_max = ((((1) << (((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) - (1))))) - (1));
  tmp_min = (- (((1) << (((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) - (1))))));
{
0;
tmp_max;
tmp_min;
}
}

  return 4;
}

// ********** clipu: clipu $rn,$cimm5

static int
mep_emu_clipu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
  SI tmp_max;
  tmp_max = ((((1) << (cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr))) - (1));
{
0;
tmp_max;
0;
}
}

  return 4;
}

// ********** sadd: sadd $rn,$rm

static int
mep_emu_sadd (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{
(- (((1) << (31))));
((((1) << (31))) - (1));
}
ADDSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** ssub: ssub $rn,$rm

static int
mep_emu_ssub (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{
(- (((1) << (31))));
((((1) << (31))) - (1));
}
SUBSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** saddu: saddu $rn,$rm

static int
mep_emu_saddu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
(~ (0));
ADDSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** ssubu: ssubu $rn,$rm

static int
mep_emu_ssubu (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
0;
SUBSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** swcp: swcp $crn,($rma)

static int
mep_emu_swcp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 2;
}

// ********** lwcp: lwcp $crn,($rma)

static int
mep_emu_lwcp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
}

  return 2;
}

// ********** smcp: smcp $crn64,($rma)

static int
mep_emu_smcp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
}

  return 2;
}

// ********** lmcp: lmcp $crn64,($rma)

static int
mep_emu_lmcp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** swcpi: swcpi $crn,($rma+)

static int
mep_emu_swcpi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_W); }
ADDSI ([&valid](){ valid = 0; return 0; }(), 4);
}

  return 2;
}

// ********** lwcpi: lwcpi $crn,($rma+)

static int
mep_emu_lwcpi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
ADDSI ([&valid](){ valid = 0; return 0; }(), 4);
}

  return 2;
}

// ********** smcpi: smcpi $crn64,($rma+)

static int
mep_emu_smcpi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** lmcpi: lmcpi $crn64,($rma+)

static int
mep_emu_lmcpi (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
[&valid](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** swcp16: swcp $crn,$sdisp16($rma)

static int
mep_emu_swcp16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), INVSI (3)); if (valid) ua_add_dref(0, val, dr_W); }
}

  return 4;
}

// ********** lwcp16: lwcp $crn,$sdisp16($rma)

static int
mep_emu_lwcp16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ SI val = ANDSI (ADDSI ([&valid](){ valid = 0; return 0; }(), cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr), INVSI (3)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
}

  return 4;
}

// ********** smcp16: smcp $crn64,$sdisp16($rma)

static int
mep_emu_smcp16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
}

  return 4;
}

// ********** lmcp16: lmcp $crn64,$sdisp16($rma)

static int
mep_emu_lmcp16 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** sbcpa: sbcpa $crn,($rma+),$cdisp10

static int
mep_emu_sbcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
}

  return 4;
}

// ********** lbcpa: lbcpa $crn,($rma+),$cdisp10

static int
mep_emu_lbcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTQISI ([&valid](){ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
}

  return 4;
}

// ********** shcpa: shcpa $crn,($rma+),$cdisp10a2

static int
mep_emu_shcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (1)); if (valid) ua_add_dref(0, val, dr_W); }
ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
}

  return 4;
}

// ********** lhcpa: lhcpa $crn,($rma+),$cdisp10a2

static int
mep_emu_lhcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTHISI ([&valid](){ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (1)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
}

  return 4;
}

// ********** swcpa: swcpa $crn,($rma+),$cdisp10a4

static int
mep_emu_swcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_W); }
ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
}

  return 4;
}

// ********** lwcpa: lwcpa $crn,($rma+),$cdisp10a4

static int
mep_emu_lwcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr));
}

  return 4;
}

// ********** smcpa: smcpa $crn64,($rma+),$cdisp10a8

static int
mep_emu_smcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** lmcpa: lmcpa $crn64,($rma+),$cdisp10a8

static int
mep_emu_lmcpa (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
[&valid](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** sbcpm0: sbcpm0 $crn,($rma+),$cdisp10

static int
mep_emu_sbcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lbcpm0: lbcpm0 $crn,($rma+),$cdisp10

static int
mep_emu_lbcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTQISI ([&valid](){ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** shcpm0: shcpm0 $crn,($rma+),$cdisp10a2

static int
mep_emu_shcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (1)); if (valid) ua_add_dref(0, val, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lhcpm0: lhcpm0 $crn,($rma+),$cdisp10a2

static int
mep_emu_lhcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTHISI ([&valid](){ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (1)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** swcpm0: swcpm0 $crn,($rma+),$cdisp10a4

static int
mep_emu_swcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lwcpm0: lwcpm0 $crn,($rma+),$cdisp10a4

static int
mep_emu_lwcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
;
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** smcpm0: smcpm0 $crn64,($rma+),$cdisp10a8

static int
mep_emu_smcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lmcpm0: lmcpm0 $crn64,($rma+),$cdisp10a8

static int
mep_emu_lmcpm0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** sbcpm1: sbcpm1 $crn,($rma+),$cdisp10

static int
mep_emu_sbcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lbcpm1: lbcpm1 $crn,($rma+),$cdisp10

static int
mep_emu_lbcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTQISI ([&valid](){ QI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** shcpm1: shcpm1 $crn,($rma+),$cdisp10a2

static int
mep_emu_shcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (1)); if (valid) ua_add_dref(0, val, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lhcpm1: lhcpm1 $crn,($rma+),$cdisp10a2

static int
mep_emu_lhcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTHISI ([&valid](){ HI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (1)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** swcpm1: swcpm1 $crn,($rma+),$cdisp10a4

static int
mep_emu_swcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lwcpm1: lwcpm1 $crn,($rma+),$cdisp10a4

static int
mep_emu_lwcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
EXTSISI ([&valid](){ SI val = ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (3)); if (valid) ua_add_dref(0, val, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** smcpm1: smcpm1 $crn64,($rma+),$cdisp10a8

static int
mep_emu_smcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lmcpm1: lmcpm1 $crn64,($rma+),$cdisp10a8

static int
mep_emu_lmcpm1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
[&valid](){ valid = 0; return 0; }();
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&valid](){ valid = 0; return 0; }(), [&valid](){ valid = 0; return 0; }());
; return SRLSI (-1, [&valid](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&valid](){ valid = 0; return 0; }()); return ADDSI ([&valid](){ valid = 0; return 0; }(), EXTSISI (cmd.Op3.type == o_imm ? cmd.Op3.value : cmd.Op3.addr)); }(); }();
}

  return 4;
}

// ********** bcpeq: bcpeq $cccc,$pcrel17a2

static int
mep_emu_bcpeq (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{ USI val = ((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** bcpne: bcpne $cccc,$pcrel17a2

static int
mep_emu_bcpne (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{ USI val = ((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** bcpat: bcpat $cccc,$pcrel17a2

static int
mep_emu_bcpat (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{ USI val = ((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** bcpaf: bcpaf $cccc,$pcrel17a2

static int
mep_emu_bcpaf (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
{ USI val = ((cmd.Op2.type == o_imm ? cmd.Op2.value : cmd.Op2.addr) & ((~ (1)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** synccp: synccp

static int
mep_emu_synccp (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
((void) 0); /*nop*/
}

  return 2;
}

// ********** jsrv: jsrv $rm

static int
mep_emu_jsrv (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
ORSI (ADDSI (pc, 2), 1);
{
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (3))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (7))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
}
}

  return 2;
}

// ********** bsrv: bsrv $pcrel24a2

static int
mep_emu_bsrv (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{
{
ORSI (ADDSI (pc, 4), 1);
{
{ USI val = ((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) & ((~ (3)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ((cmd.Op1.type == o_imm ? cmd.Op1.value : cmd.Op1.addr) & ((~ (7)))); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&valid](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
}
}

  return 4;
}

// ********** sim-syscall: --syscall--

static int
mep_emu_sim_syscall (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;


  return 2;
}

// ********** ri-0: --reserved--

static int
mep_emu_ri_0 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-1: --reserved--

static int
mep_emu_ri_1 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-2: --reserved--

static int
mep_emu_ri_2 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-3: --reserved--

static int
mep_emu_ri_3 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-4: --reserved--

static int
mep_emu_ri_4 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-5: --reserved--

static int
mep_emu_ri_5 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-6: --reserved--

static int
mep_emu_ri_6 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-7: --reserved--

static int
mep_emu_ri_7 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-8: --reserved--

static int
mep_emu_ri_8 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-9: --reserved--

static int
mep_emu_ri_9 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-10: --reserved--

static int
mep_emu_ri_10 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-11: --reserved--

static int
mep_emu_ri_11 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-12: --reserved--

static int
mep_emu_ri_12 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-13: --reserved--

static int
mep_emu_ri_13 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-14: --reserved--

static int
mep_emu_ri_14 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-15: --reserved--

static int
mep_emu_ri_15 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-17: --reserved--

static int
mep_emu_ri_17 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-20: --reserved--

static int
mep_emu_ri_20 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-21: --reserved--

static int
mep_emu_ri_21 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-22: --reserved--

static int
mep_emu_ri_22 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-23: --reserved--

static int
mep_emu_ri_23 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-26: --reserved--

static int
mep_emu_ri_26 (void)
{
  ea_t pc = cmd.ea;
  int valid = 1;

{ USI val = [&valid](){ valid = 0; return 0; }(); if (valid) ua_add_cref(0, val, InstrIsSet(cmd.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}


// Emulator entry
int idaapi emu(void)
{
  int len;  switch (cmd.itype)
  {
    case MEP_INSN_X_INVALID: len = mep_emu_x_invalid(); break;
    case MEP_INSN_SB: len = mep_emu_sb(); break;
    case MEP_INSN_SH: len = mep_emu_sh(); break;
    case MEP_INSN_SW: len = mep_emu_sw(); break;
    case MEP_INSN_LB: len = mep_emu_lb(); break;
    case MEP_INSN_LH: len = mep_emu_lh(); break;
    case MEP_INSN_LW: len = mep_emu_lw(); break;
    case MEP_INSN_LBU: len = mep_emu_lbu(); break;
    case MEP_INSN_LHU: len = mep_emu_lhu(); break;
    case MEP_INSN_SW_SP: len = mep_emu_sw_sp(); break;
    case MEP_INSN_LW_SP: len = mep_emu_lw_sp(); break;
    case MEP_INSN_SB_TP: len = mep_emu_sb_tp(); break;
    case MEP_INSN_SH_TP: len = mep_emu_sh_tp(); break;
    case MEP_INSN_SW_TP: len = mep_emu_sw_tp(); break;
    case MEP_INSN_LB_TP: len = mep_emu_lb_tp(); break;
    case MEP_INSN_LH_TP: len = mep_emu_lh_tp(); break;
    case MEP_INSN_LW_TP: len = mep_emu_lw_tp(); break;
    case MEP_INSN_LBU_TP: len = mep_emu_lbu_tp(); break;
    case MEP_INSN_LHU_TP: len = mep_emu_lhu_tp(); break;
    case MEP_INSN_SB16: len = mep_emu_sb16(); break;
    case MEP_INSN_SH16: len = mep_emu_sh16(); break;
    case MEP_INSN_SW16: len = mep_emu_sw16(); break;
    case MEP_INSN_LB16: len = mep_emu_lb16(); break;
    case MEP_INSN_LH16: len = mep_emu_lh16(); break;
    case MEP_INSN_LW16: len = mep_emu_lw16(); break;
    case MEP_INSN_LBU16: len = mep_emu_lbu16(); break;
    case MEP_INSN_LHU16: len = mep_emu_lhu16(); break;
    case MEP_INSN_SW24: len = mep_emu_sw24(); break;
    case MEP_INSN_LW24: len = mep_emu_lw24(); break;
    case MEP_INSN_EXTB: len = mep_emu_extb(); break;
    case MEP_INSN_EXTH: len = mep_emu_exth(); break;
    case MEP_INSN_EXTUB: len = mep_emu_extub(); break;
    case MEP_INSN_EXTUH: len = mep_emu_extuh(); break;
    case MEP_INSN_SSARB: len = mep_emu_ssarb(); break;
    case MEP_INSN_MOV: len = mep_emu_mov(); break;
    case MEP_INSN_MOVI8: len = mep_emu_movi8(); break;
    case MEP_INSN_MOVI16: len = mep_emu_movi16(); break;
    case MEP_INSN_MOVU24: len = mep_emu_movu24(); break;
    case MEP_INSN_MOVU16: len = mep_emu_movu16(); break;
    case MEP_INSN_MOVH: len = mep_emu_movh(); break;
    case MEP_INSN_ADD3: len = mep_emu_add3(); break;
    case MEP_INSN_ADD: len = mep_emu_add(); break;
    case MEP_INSN_ADD3I: len = mep_emu_add3i(); break;
    case MEP_INSN_ADVCK3: len = mep_emu_advck3(); break;
    case MEP_INSN_SUB: len = mep_emu_sub(); break;
    case MEP_INSN_SBVCK3: len = mep_emu_sbvck3(); break;
    case MEP_INSN_NEG: len = mep_emu_neg(); break;
    case MEP_INSN_SLT3: len = mep_emu_slt3(); break;
    case MEP_INSN_SLTU3: len = mep_emu_sltu3(); break;
    case MEP_INSN_SLT3I: len = mep_emu_slt3i(); break;
    case MEP_INSN_SLTU3I: len = mep_emu_sltu3i(); break;
    case MEP_INSN_SL1AD3: len = mep_emu_sl1ad3(); break;
    case MEP_INSN_SL2AD3: len = mep_emu_sl2ad3(); break;
    case MEP_INSN_ADD3X: len = mep_emu_add3x(); break;
    case MEP_INSN_SLT3X: len = mep_emu_slt3x(); break;
    case MEP_INSN_SLTU3X: len = mep_emu_sltu3x(); break;
    case MEP_INSN_OR: len = mep_emu_or(); break;
    case MEP_INSN_AND: len = mep_emu_and(); break;
    case MEP_INSN_XOR: len = mep_emu_xor(); break;
    case MEP_INSN_NOR: len = mep_emu_nor(); break;
    case MEP_INSN_OR3: len = mep_emu_or3(); break;
    case MEP_INSN_AND3: len = mep_emu_and3(); break;
    case MEP_INSN_XOR3: len = mep_emu_xor3(); break;
    case MEP_INSN_SRA: len = mep_emu_sra(); break;
    case MEP_INSN_SRL: len = mep_emu_srl(); break;
    case MEP_INSN_SLL: len = mep_emu_sll(); break;
    case MEP_INSN_SRAI: len = mep_emu_srai(); break;
    case MEP_INSN_SRLI: len = mep_emu_srli(); break;
    case MEP_INSN_SLLI: len = mep_emu_slli(); break;
    case MEP_INSN_SLL3: len = mep_emu_sll3(); break;
    case MEP_INSN_FSFT: len = mep_emu_fsft(); break;
    case MEP_INSN_BRA: len = mep_emu_bra(); break;
    case MEP_INSN_BEQZ: len = mep_emu_beqz(); break;
    case MEP_INSN_BNEZ: len = mep_emu_bnez(); break;
    case MEP_INSN_BEQI: len = mep_emu_beqi(); break;
    case MEP_INSN_BNEI: len = mep_emu_bnei(); break;
    case MEP_INSN_BLTI: len = mep_emu_blti(); break;
    case MEP_INSN_BGEI: len = mep_emu_bgei(); break;
    case MEP_INSN_BEQ: len = mep_emu_beq(); break;
    case MEP_INSN_BNE: len = mep_emu_bne(); break;
    case MEP_INSN_BSR12: len = mep_emu_bsr12(); break;
    case MEP_INSN_BSR24: len = mep_emu_bsr24(); break;
    case MEP_INSN_JMP: len = mep_emu_jmp(); break;
    case MEP_INSN_JMP24: len = mep_emu_jmp24(); break;
    case MEP_INSN_JSR: len = mep_emu_jsr(); break;
    case MEP_INSN_RET: len = mep_emu_ret(); break;
    case MEP_INSN_REPEAT: len = mep_emu_repeat(); break;
    case MEP_INSN_EREPEAT: len = mep_emu_erepeat(); break;
    case MEP_INSN_STC_LP: len = mep_emu_stc_lp(); break;
    case MEP_INSN_STC_HI: len = mep_emu_stc_hi(); break;
    case MEP_INSN_STC_LO: len = mep_emu_stc_lo(); break;
    case MEP_INSN_STC: len = mep_emu_stc(); break;
    case MEP_INSN_LDC_LP: len = mep_emu_ldc_lp(); break;
    case MEP_INSN_LDC_HI: len = mep_emu_ldc_hi(); break;
    case MEP_INSN_LDC_LO: len = mep_emu_ldc_lo(); break;
    case MEP_INSN_LDC: len = mep_emu_ldc(); break;
    case MEP_INSN_DI: len = mep_emu_di(); break;
    case MEP_INSN_EI: len = mep_emu_ei(); break;
    case MEP_INSN_RETI: len = mep_emu_reti(); break;
    case MEP_INSN_HALT: len = mep_emu_halt(); break;
    case MEP_INSN_SLEEP: len = mep_emu_sleep(); break;
    case MEP_INSN_SWI: len = mep_emu_swi(); break;
    case MEP_INSN_BREAK: len = mep_emu_break(); break;
    case MEP_INSN_SYNCM: len = mep_emu_syncm(); break;
    case MEP_INSN_STCB: len = mep_emu_stcb(); break;
    case MEP_INSN_LDCB: len = mep_emu_ldcb(); break;
    case MEP_INSN_BSETM: len = mep_emu_bsetm(); break;
    case MEP_INSN_BCLRM: len = mep_emu_bclrm(); break;
    case MEP_INSN_BNOTM: len = mep_emu_bnotm(); break;
    case MEP_INSN_BTSTM: len = mep_emu_btstm(); break;
    case MEP_INSN_TAS: len = mep_emu_tas(); break;
    case MEP_INSN_CACHE: len = mep_emu_cache(); break;
    case MEP_INSN_MUL: len = mep_emu_mul(); break;
    case MEP_INSN_MULU: len = mep_emu_mulu(); break;
    case MEP_INSN_MULR: len = mep_emu_mulr(); break;
    case MEP_INSN_MULRU: len = mep_emu_mulru(); break;
    case MEP_INSN_MADD: len = mep_emu_madd(); break;
    case MEP_INSN_MADDU: len = mep_emu_maddu(); break;
    case MEP_INSN_MADDR: len = mep_emu_maddr(); break;
    case MEP_INSN_MADDRU: len = mep_emu_maddru(); break;
    case MEP_INSN_DIV: len = mep_emu_div(); break;
    case MEP_INSN_DIVU: len = mep_emu_divu(); break;
    case MEP_INSN_DRET: len = mep_emu_dret(); break;
    case MEP_INSN_DBREAK: len = mep_emu_dbreak(); break;
    case MEP_INSN_LDZ: len = mep_emu_ldz(); break;
    case MEP_INSN_ABS: len = mep_emu_abs(); break;
    case MEP_INSN_AVE: len = mep_emu_ave(); break;
    case MEP_INSN_MIN: len = mep_emu_min(); break;
    case MEP_INSN_MAX: len = mep_emu_max(); break;
    case MEP_INSN_MINU: len = mep_emu_minu(); break;
    case MEP_INSN_MAXU: len = mep_emu_maxu(); break;
    case MEP_INSN_CLIP: len = mep_emu_clip(); break;
    case MEP_INSN_CLIPU: len = mep_emu_clipu(); break;
    case MEP_INSN_SADD: len = mep_emu_sadd(); break;
    case MEP_INSN_SSUB: len = mep_emu_ssub(); break;
    case MEP_INSN_SADDU: len = mep_emu_saddu(); break;
    case MEP_INSN_SSUBU: len = mep_emu_ssubu(); break;
    case MEP_INSN_SWCP: len = mep_emu_swcp(); break;
    case MEP_INSN_LWCP: len = mep_emu_lwcp(); break;
    case MEP_INSN_SMCP: len = mep_emu_smcp(); break;
    case MEP_INSN_LMCP: len = mep_emu_lmcp(); break;
    case MEP_INSN_SWCPI: len = mep_emu_swcpi(); break;
    case MEP_INSN_LWCPI: len = mep_emu_lwcpi(); break;
    case MEP_INSN_SMCPI: len = mep_emu_smcpi(); break;
    case MEP_INSN_LMCPI: len = mep_emu_lmcpi(); break;
    case MEP_INSN_SWCP16: len = mep_emu_swcp16(); break;
    case MEP_INSN_LWCP16: len = mep_emu_lwcp16(); break;
    case MEP_INSN_SMCP16: len = mep_emu_smcp16(); break;
    case MEP_INSN_LMCP16: len = mep_emu_lmcp16(); break;
    case MEP_INSN_SBCPA: len = mep_emu_sbcpa(); break;
    case MEP_INSN_LBCPA: len = mep_emu_lbcpa(); break;
    case MEP_INSN_SHCPA: len = mep_emu_shcpa(); break;
    case MEP_INSN_LHCPA: len = mep_emu_lhcpa(); break;
    case MEP_INSN_SWCPA: len = mep_emu_swcpa(); break;
    case MEP_INSN_LWCPA: len = mep_emu_lwcpa(); break;
    case MEP_INSN_SMCPA: len = mep_emu_smcpa(); break;
    case MEP_INSN_LMCPA: len = mep_emu_lmcpa(); break;
    case MEP_INSN_SBCPM0: len = mep_emu_sbcpm0(); break;
    case MEP_INSN_LBCPM0: len = mep_emu_lbcpm0(); break;
    case MEP_INSN_SHCPM0: len = mep_emu_shcpm0(); break;
    case MEP_INSN_LHCPM0: len = mep_emu_lhcpm0(); break;
    case MEP_INSN_SWCPM0: len = mep_emu_swcpm0(); break;
    case MEP_INSN_LWCPM0: len = mep_emu_lwcpm0(); break;
    case MEP_INSN_SMCPM0: len = mep_emu_smcpm0(); break;
    case MEP_INSN_LMCPM0: len = mep_emu_lmcpm0(); break;
    case MEP_INSN_SBCPM1: len = mep_emu_sbcpm1(); break;
    case MEP_INSN_LBCPM1: len = mep_emu_lbcpm1(); break;
    case MEP_INSN_SHCPM1: len = mep_emu_shcpm1(); break;
    case MEP_INSN_LHCPM1: len = mep_emu_lhcpm1(); break;
    case MEP_INSN_SWCPM1: len = mep_emu_swcpm1(); break;
    case MEP_INSN_LWCPM1: len = mep_emu_lwcpm1(); break;
    case MEP_INSN_SMCPM1: len = mep_emu_smcpm1(); break;
    case MEP_INSN_LMCPM1: len = mep_emu_lmcpm1(); break;
    case MEP_INSN_BCPEQ: len = mep_emu_bcpeq(); break;
    case MEP_INSN_BCPNE: len = mep_emu_bcpne(); break;
    case MEP_INSN_BCPAT: len = mep_emu_bcpat(); break;
    case MEP_INSN_BCPAF: len = mep_emu_bcpaf(); break;
    case MEP_INSN_SYNCCP: len = mep_emu_synccp(); break;
    case MEP_INSN_JSRV: len = mep_emu_jsrv(); break;
    case MEP_INSN_BSRV: len = mep_emu_bsrv(); break;
    case MEP_INSN_SIM_SYSCALL: len = mep_emu_sim_syscall(); break;
    case MEP_INSN_RI_0: len = mep_emu_ri_0(); break;
    case MEP_INSN_RI_1: len = mep_emu_ri_1(); break;
    case MEP_INSN_RI_2: len = mep_emu_ri_2(); break;
    case MEP_INSN_RI_3: len = mep_emu_ri_3(); break;
    case MEP_INSN_RI_4: len = mep_emu_ri_4(); break;
    case MEP_INSN_RI_5: len = mep_emu_ri_5(); break;
    case MEP_INSN_RI_6: len = mep_emu_ri_6(); break;
    case MEP_INSN_RI_7: len = mep_emu_ri_7(); break;
    case MEP_INSN_RI_8: len = mep_emu_ri_8(); break;
    case MEP_INSN_RI_9: len = mep_emu_ri_9(); break;
    case MEP_INSN_RI_10: len = mep_emu_ri_10(); break;
    case MEP_INSN_RI_11: len = mep_emu_ri_11(); break;
    case MEP_INSN_RI_12: len = mep_emu_ri_12(); break;
    case MEP_INSN_RI_13: len = mep_emu_ri_13(); break;
    case MEP_INSN_RI_14: len = mep_emu_ri_14(); break;
    case MEP_INSN_RI_15: len = mep_emu_ri_15(); break;
    case MEP_INSN_RI_17: len = mep_emu_ri_17(); break;
    case MEP_INSN_RI_20: len = mep_emu_ri_20(); break;
    case MEP_INSN_RI_21: len = mep_emu_ri_21(); break;
    case MEP_INSN_RI_22: len = mep_emu_ri_22(); break;
    case MEP_INSN_RI_23: len = mep_emu_ri_23(); break;
    case MEP_INSN_RI_26: len = mep_emu_ri_26(); break;
    default: len = 0; break;
  }
  if (len && !InstrIsSet(cmd.itype, CF_STOP))
  {
    ua_add_cref(0, cmd.ea+len, fl_F);
  }
  return 1;
}
