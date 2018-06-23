/* IDP emulator for mep.

THIS FILE IS (mostly) MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "mep.hpp"

static void make_stack_var(const insn_t &insn, const op_t &x)
{
  if (may_create_stkvars())
  {
    adiff_t sp_off = x.value;
    if ( insn_create_stkvar(insn, x, sp_off, 0) )
      op_stkvar(insn.ea, x.n);
  }
}

static void add_sp(const insn_t &insn, sval_t delta)
{
  func_t *pfn = get_func(insn.ea);

  if (may_trace_sp() && pfn)
  {
    add_auto_stkpnt(pfn, insn.ea+insn.size, delta);
  }
}

// ********** x-invalid: --invalid--

static int
mep_emu_x_invalid (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

  {
    return 0;
  }

  return 0;
}

// ********** stcb_r: stcb $rn,($rma)

static int
mep_emu_stcb_r (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;


  return 2;
}

// ********** ldcb_r: ldcb $rn,($rma)

static int
mep_emu_ldcb_r (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** pref: pref $cimm4,($rma)

static int
mep_emu_pref (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
}

  return 2;
}

// ********** prefd: pref $cimm4,$sdisp16($rma)

static int
mep_emu_prefd (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
}

  return 4;
}

// ********** casb3: casb3 $rl5,$rn,($rm)

static int
mep_emu_casb3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** cash3: cash3 $rl5,$rn,($rm)

static int
mep_emu_cash3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** casw3: casw3 $rl5,$rn,($rm)

static int
mep_emu_casw3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** sbcp: sbcp $crn,$cdisp12($rma)

static int
mep_emu_sbcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ QI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 4;
}

// ********** lbcp: lbcp $crn,$cdisp12($rma)

static int
mep_emu_lbcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTQISI ([&](){ QI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
}

  return 4;
}

// ********** lbucp: lbucp $crn,$cdisp12($rma)

static int
mep_emu_lbucp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTQISI ([&](){ QI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
}

  return 4;
}

// ********** shcp: shcp $crn,$cdisp12($rma)

static int
mep_emu_shcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ HI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 4;
}

// ********** lhcp: lhcp $crn,$cdisp12($rma)

static int
mep_emu_lhcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTHISI ([&](){ HI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
}

  return 4;
}

// ********** lhucp: lhucp $crn,$cdisp12($rma)

static int
mep_emu_lhucp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTHISI ([&](){ HI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
}

  return 4;
}

// ********** lbucpa: lbucpa $crn,($rma+),$cdisp10

static int
mep_emu_lbucpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
ADDSI ([&](){ valid = 0; return 0; }(), insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr);
}

  return 4;
}

// ********** lhucpa: lhucpa $crn,($rma+),$cdisp10a2

static int
mep_emu_lhucpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** lbucpm0: lbucpm0 $crn,($rma+),$cdisp10

static int
mep_emu_lbucpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lhucpm0: lhucpm0 $crn,($rma+),$cdisp10a2

static int
mep_emu_lhucpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lbucpm1: lbucpm1 $crn,($rma+),$cdisp10

static int
mep_emu_lbucpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lhucpm1: lhucpm1 $crn,($rma+),$cdisp10a2

static int
mep_emu_lhucpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** uci: uci $rn,$rm,$uimm16

static int
mep_emu_uci (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 4;
}

// ********** dsp: dsp $rn,$rm,$uimm16

static int
mep_emu_dsp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 4;
}

// ********** sb: sb $rnc,($rma)

static int
mep_emu_sb (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** sh: sh $rns,($rma)

static int
mep_emu_sh (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ UHI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** sw: sw $rnl,($rma)

static int
mep_emu_sw (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** lb: lb $rnc,($rma)

static int
mep_emu_lb (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** lh: lh $rns,($rma)

static int
mep_emu_lh (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** lw: lw $rnl,($rma)

static int
mep_emu_lw (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ SI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;

  return 2;
}

// ********** lbu: lbu $rnuc,($rma)

static int
mep_emu_lbu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTQISI ([&](){ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** lhu: lhu $rnus,($rma)

static int
mep_emu_lhu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTHISI ([&](){ UHI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** sw-sp: sw $rnl,$udisp7a4($spr)

static int
mep_emu_sw_sp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ((((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) + ([&](){ valid = 0; return 0; }()))) & ((~ (3)))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  make_stack_var(insn, insn.Op2);

  return 2;
}

// ********** lw-sp: lw $rnl,$udisp7a4($spr)

static int
mep_emu_lw_sp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ SI val = ((((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) + ([&](){ valid = 0; return 0; }()))) & ((~ (3)))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
  make_stack_var(insn, insn.Op2);

  return 2;
}

// ********** sb-tp: sb $rn3c,$udisp7($tpr)

static int
mep_emu_sb_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ QI val = ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** sh-tp: sh $rn3s,$udisp7a2($tpr)

static int
mep_emu_sh_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ HI val = ANDSI (ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** sw-tp: sw $rn3l,$udisp7a4($tpr)

static int
mep_emu_sw_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI (ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()), (~ (3))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** lb-tp: lb $rn3c,$udisp7($tpr)

static int
mep_emu_lb_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTQISI ([&](){ QI val = ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** lh-tp: lh $rn3s,$udisp7a2($tpr)

static int
mep_emu_lh_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTHISI ([&](){ HI val = ANDSI (ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** lw-tp: lw $rn3l,$udisp7a4($tpr)

static int
mep_emu_lw_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ SI val = ANDSI (ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()), (~ (3))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;

  return 2;
}

// ********** lbu-tp: lbu $rn3uc,$udisp7($tpr)

static int
mep_emu_lbu_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTQISI ([&](){ QI val = ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** lhu-tp: lhu $rn3us,$udisp7a2($tpr)

static int
mep_emu_lhu_tp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTHISI ([&](){ HI val = ANDSI (ADDSI (ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), [&](){ valid = 0; return 0; }()), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);

  return 2;
}

// ********** sb16: sb $rnc,$sdisp16($rma)

static int
mep_emu_sb16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ QI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** sh16: sh $rns,$sdisp16($rma)

static int
mep_emu_sh16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ HI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** sw16: sw $rnl,$sdisp16($rma)

static int
mep_emu_sw16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)), (~ (3))); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** lb16: lb $rnc,$sdisp16($rma)

static int
mep_emu_lb16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTQISI ([&](){ QI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** lh16: lh $rns,$sdisp16($rma)

static int
mep_emu_lh16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTHISI ([&](){ HI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** lw16: lw $rnl,$sdisp16($rma)

static int
mep_emu_lw16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ SI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)), (~ (3))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** lbu16: lbu $rnuc,$sdisp16($rma)

static int
mep_emu_lbu16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTQISI ([&](){ QI val = ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** lhu16: lhu $rnus,$sdisp16($rma)

static int
mep_emu_lhu16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTHISI ([&](){ HI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr)), (~ (1))); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
  if (insn.Op3.reg == REGS_HW_H_GPR_BASE + 15)
    make_stack_var(insn, insn.Op2);

  return 4;
}

// ********** sw24: sw $rnl,($addr24a4)

static int
mep_emu_sw24 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 4;
}

// ********** lw24: lw $rnl,($addr24a4)

static int
mep_emu_lw24 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ SI val = ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;

  return 4;
}

// ********** extb: extb $rn

static int
mep_emu_extb (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTQISI (ANDQI ([&](){ valid = 0; return 0; }(), 255));

  return 2;
}

// ********** exth: exth $rn

static int
mep_emu_exth (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTHISI (ANDHI ([&](){ valid = 0; return 0; }(), 65535));

  return 2;
}

// ********** extub: extub $rn

static int
mep_emu_extub (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTSISI (ANDSI ([&](){ valid = 0; return 0; }(), 255));

  return 2;
}

// ********** extuh: extuh $rn

static int
mep_emu_extuh (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTSISI (ANDSI ([&](){ valid = 0; return 0; }(), 65535));

  return 2;
}

// ********** ssarb: ssarb $udisp2($rm)

static int
mep_emu_ssarb (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTSISI (((((((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) + ([&](){ valid = 0; return 0; }()))) & (3))) * (8)));
((32) - (ZEXTSISI (((((((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) + ([&](){ valid = 0; return 0; }()))) & (3))) * (8)))));
}

  return 2;
}

// ********** mov: mov $rn,$rm

static int
mep_emu_mov (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** movi8: mov $rn,$simm8

static int
mep_emu_movi8 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 2;
}

// ********** movi16: mov $rn,$simm16

static int
mep_emu_movi16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 4;
}

// ********** movu24: movu $rn3,$uimm24

static int
mep_emu_movu24 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

  ea_t addr = ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  if (segtype(addr) != SEG_UNDF) {
    insn_add_dref(insn, 0, addr, dr_O);
  }

  return 4;
}

// ********** movu16: movu $rn,$uimm16

static int
mep_emu_movu16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ZEXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 4;
}

// ********** movh: movh $rn,$uimm16

static int
mep_emu_movh (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) << (16));

  return 4;
}

// ********** add3: add3 $rl,$rn,$rm

static int
mep_emu_add3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ADDSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** add: add $rn,$simm6

static int
mep_emu_add (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr));
  if (insn.Op1.reg == REGS_HW_H_GPR_BASE + 15)
    add_sp(insn, (sval_t)insn.Op2.value);

  return 2;
}

// ********** add3i: add3 $rn,$spr,$uimm7a4

static int
mep_emu_add3i (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ADDSI ([&](){ valid = 0; return 0; }(), ZEXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
  if (insn.Op1.reg == REGS_HW_H_GPR_BASE + 15)
    add_sp(insn, (sval_t)insn.Op3.value);

  return 2;
}

// ********** advck3: advck3 \$0,$rn,$rm

static int
mep_emu_advck3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sub: sub $rn,$rm

static int
mep_emu_sub (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SUBSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** sbvck3: sbvck3 \$0,$rn,$rm

static int
mep_emu_sbvck3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** neg: neg $rn,$rm

static int
mep_emu_neg (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

NEGSI ([&](){ valid = 0; return 0; }());

  return 2;
}

// ********** slt3: slt3 \$0,$rn,$rm

static int
mep_emu_slt3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sltu3: sltu3 \$0,$rn,$rm

static int
mep_emu_sltu3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** slt3i: slt3 \$0,$rn,$uimm5

static int
mep_emu_slt3i (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sltu3i: sltu3 \$0,$rn,$uimm5

static int
mep_emu_sltu3i (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 2;
}

// ********** sl1ad3: sl1ad3 \$0,$rn,$rm

static int
mep_emu_sl1ad3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ADDSI (SLLSI ([&](){ valid = 0; return 0; }(), 1), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** sl2ad3: sl2ad3 \$0,$rn,$rm

static int
mep_emu_sl2ad3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ADDSI (SLLSI ([&](){ valid = 0; return 0; }(), 2), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** add3x: add3 $rn,$rm,$simm16

static int
mep_emu_add3x (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
  if (insn.Op1.reg == REGS_HW_H_GPR_BASE + 15 && insn.Op2.reg == REGS_HW_H_GPR_BASE + 15)
    add_sp(insn, (sval_t)insn.Op3.value);

  return 4;
}

// ********** slt3x: slt3 $rn,$rm,$simm16

static int
mep_emu_slt3x (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 4;
}

// ********** sltu3x: sltu3 $rn,$rm,$uimm16

static int
mep_emu_sltu3x (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
1;
0;
}

  return 4;
}

// ********** or: or $rn,$rm

static int
mep_emu_or (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** and: and $rn,$rm

static int
mep_emu_and (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ANDSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** xor: xor $rn,$rm

static int
mep_emu_xor (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

XORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());

  return 2;
}

// ********** nor: nor $rn,$rm

static int
mep_emu_nor (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

INVSI (ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }()));

  return 2;
}

// ********** or3: or3 $rn,$rm,$uimm16

static int
mep_emu_or3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ORSI ([&](){ valid = 0; return 0; }(), ZEXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));

  return 4;
}

// ********** and3: and3 $rn,$rm,$uimm16

static int
mep_emu_and3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ANDSI ([&](){ valid = 0; return 0; }(), ZEXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));

  return 4;
}

// ********** xor3: xor3 $rn,$rm,$uimm16

static int
mep_emu_xor3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

XORSI ([&](){ valid = 0; return 0; }(), ZEXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));

  return 4;
}

// ********** sra: sra $rn,$rm

static int
mep_emu_sra (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SRASI ([&](){ valid = 0; return 0; }(), ANDSI ([&](){ valid = 0; return 0; }(), 31));

  return 2;
}

// ********** srl: srl $rn,$rm

static int
mep_emu_srl (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SRLSI ([&](){ valid = 0; return 0; }(), ANDSI ([&](){ valid = 0; return 0; }(), 31));

  return 2;
}

// ********** sll: sll $rn,$rm

static int
mep_emu_sll (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SLLSI ([&](){ valid = 0; return 0; }(), ANDSI ([&](){ valid = 0; return 0; }(), 31));

  return 2;
}

// ********** srai: sra $rn,$uimm5

static int
mep_emu_srai (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SRASI ([&](){ valid = 0; return 0; }(), insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 2;
}

// ********** srli: srl $rn,$uimm5

static int
mep_emu_srli (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SRLSI ([&](){ valid = 0; return 0; }(), insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 2;
}

// ********** slli: sll $rn,$uimm5

static int
mep_emu_slli (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SLLSI ([&](){ valid = 0; return 0; }(), insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 2;
}

// ********** sll3: sll3 \$0,$rn,$uimm5

static int
mep_emu_sll3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SLLSI ([&](){ valid = 0; return 0; }(), insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr);

  return 2;
}

// ********** fsft: fsft $rn,$rm

static int
mep_emu_fsft (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_temp;
  QI tmp_shamt;
  tmp_shamt = ANDSI ([&](){ valid = 0; return 0; }(), 63);
  tmp_temp = SLLDI (ORDI (SLLDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&](){ valid = 0; return 0; }())), tmp_shamt);
SUBWORDDISI (SRLDI (tmp_temp, 32), 1);
}

  return 2;
}

// ********** bra: bra $pcrel12a2

static int
mep_emu_bra (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** beqz: beqz $rn,$pcrel8a2

static int
mep_emu_beqz (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** bnez: bnez $rn,$pcrel8a2

static int
mep_emu_bnez (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** beqi: beqi $rn,$uimm4,$pcrel17a2

static int
mep_emu_beqi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bnei: bnei $rn,$uimm4,$pcrel17a2

static int
mep_emu_bnei (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** blti: blti $rn,$uimm4,$pcrel17a2

static int
mep_emu_blti (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bgei: bgei $rn,$uimm4,$pcrel17a2

static int
mep_emu_bgei (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** beq: beq $rn,$rm,$pcrel17a2

static int
mep_emu_beq (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bne: bne $rn,$rm,$pcrel17a2

static int
mep_emu_bne (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ((insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** bsr12: bsr $pcrel12a2

static int
mep_emu_bsr12 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ADDSI (pc, 2);
{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** bsr24: bsr $pcrel24a2

static int
mep_emu_bsr24 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ADDSI (pc, 4);
{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** jmp: jmp $rm

static int
mep_emu_jmp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
{
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
}
}

  return 2;
}

// ********** jmp24: jmp $pcabs24a2

static int
mep_emu_jmp24 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ USI val = ANDSI (ORSI (ANDSI (pc, 0xf0000000), insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 4;
}

// ********** jsr: jsr $rm

static int
mep_emu_jsr (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ADDSI (pc, 2);
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** ret: ret

static int
mep_emu_ret (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
{
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}
}
}

  return 2;
}

// ********** repeat: repeat $rn,$pcrel17a2

static int
mep_emu_repeat (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ADDSI (pc, 4);
((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1))));
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** erepeat: erepeat $pcrel17a2

static int
mep_emu_erepeat (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ADDSI (pc, 4);
((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (1))));
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (0))))), ((((1) << (0))) & (((1) << (0)))));
1;
}

  return 4;
}

// ********** stc_lp: stc $rn,\$lp

static int
mep_emu_stc_lp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** stc_hi: stc $rn,\$hi

static int
mep_emu_stc_hi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** stc_lo: stc $rn,\$lo

static int
mep_emu_stc_lo (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** stc: stc $rn,$csrn

static int
mep_emu_stc (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc_lp: ldc $rn,\$lp

static int
mep_emu_ldc_lp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc_hi: ldc $rn,\$hi

static int
mep_emu_ldc_hi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc_lo: ldc $rn,\$lo

static int
mep_emu_ldc_lo (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 2;
}

// ********** ldc: ldc $rn,$csrn

static int
mep_emu_ldc (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ADDSI (pc, 2);
[&](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** di: di

static int
mep_emu_di (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

SLLSI (SRLSI ([&](){ valid = 0; return 0; }(), 1), 1);

  return 2;
}

// ********** ei: ei

static int
mep_emu_ei (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ORSI ([&](){ valid = 0; return 0; }(), 1);

  return 2;
}

// ********** reti: reti

static int
mep_emu_reti (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
{
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (9))))), ((((1) << (9))) & (((0) << (9)))));
}
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (9))))), ((((1) << (9))) & (((0) << (9)))));
}
}
{
{
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (2))))), ((((1) << (2))) & (SLLSI (ANDSI (SRLSI ([&](){ valid = 0; return 0; }(), 3), 1), 2))));
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (0))))), ((((1) << (0))) & (SLLSI (ANDSI (SRLSI ([&](){ valid = 0; return 0; }(), 1), 1), 0))));
}
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (2))))), ((((1) << (2))) & (SLLSI (ANDSI (SRLSI ([&](){ valid = 0; return 0; }(), 3), 1), 2))));
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (0))))), ((((1) << (0))) & (SLLSI (ANDSI (SRLSI ([&](){ valid = 0; return 0; }(), 1), 1), 0))));
}
}
}
((void) 0); /*nop*/
}

  return 2;
}

// ********** halt: halt

static int
mep_emu_halt (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

ORSI ([&](){ valid = 0; return 0; }(), ((1) << (11)));

  return 2;
}

// ********** sleep: sleep

static int
mep_emu_sleep (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;


  return 2;
}

// ********** swi: swi $uimm2

static int
mep_emu_swi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ORSI ([&](){ valid = 0; return 0; }(), ((1) << (4)));
ORSI ([&](){ valid = 0; return 0; }(), ((1) << (5)));
ORSI ([&](){ valid = 0; return 0; }(), ((1) << (6)));
ORSI ([&](){ valid = 0; return 0; }(), ((1) << (7)));
}

  return 2;
}

// ********** break: break

static int
mep_emu_break (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** syncm: syncm

static int
mep_emu_syncm (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

((void) 0); /*nop*/

  return 2;
}

// ********** stcb: stcb $rn,$uimm16

static int
mep_emu_stcb (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;


  return 4;
}

// ********** ldcb: ldcb $rn,$uimm16

static int
mep_emu_ldcb (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

[&](){ valid = 0; return 0; }();

  return 4;
}

// ********** bsetm: bsetm ($rma),$uimm3

static int
mep_emu_bsetm (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** bclrm: bclrm ($rma),$uimm3

static int
mep_emu_bclrm (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** bnotm: bnotm ($rma),$uimm3

static int
mep_emu_bnotm (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** btstm: btstm \$0,($rma),$uimm3

static int
mep_emu_btstm (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ZEXTQISI (ANDQI ([&](){ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
, ((1) << (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr))));
}

  return 2;
}

// ********** tas: tas $rn,($rma)

static int
mep_emu_tas (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  SI tmp_result;
  tmp_result = ZEXTQISI ([&](){ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
{ UQI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
tmp_result;
}

  return 2;
}

// ********** cache: cache $cimm4,($rma)

static int
mep_emu_cache (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;


  return 2;
}

// ********** mul: mul $rn,$rm

static int
mep_emu_mul (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI ([&](){ valid = 0; return 0; }()), EXTSIDI ([&](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** mulu: mulu $rn,$rm

static int
mep_emu_mulu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), ZEXTSIDI ([&](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** mulr: mulr $rn,$rm

static int
mep_emu_mulr (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (EXTSIDI ([&](){ valid = 0; return 0; }()), EXTSIDI ([&](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** mulru: mulru $rn,$rm

static int
mep_emu_mulru (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = MULDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), ZEXTSIDI ([&](){ valid = 0; return 0; }()));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 2;
}

// ********** madd: madd $rn,$rm

static int
mep_emu_madd (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (EXTSIDI ([&](){ valid = 0; return 0; }()), EXTSIDI ([&](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** maddu: maddu $rn,$rm

static int
mep_emu_maddu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), ZEXTSIDI ([&](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** maddr: maddr $rn,$rm

static int
mep_emu_maddr (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (EXTSIDI ([&](){ valid = 0; return 0; }()), EXTSIDI ([&](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** maddru: maddru $rn,$rm

static int
mep_emu_maddru (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  DI tmp_result;
  tmp_result = ORDI (SLLDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), 32), ZEXTSIDI ([&](){ valid = 0; return 0; }()));
  tmp_result = ADDDI (tmp_result, MULDI (ZEXTSIDI ([&](){ valid = 0; return 0; }()), ZEXTSIDI ([&](){ valid = 0; return 0; }())));
SUBWORDDISI (tmp_result, 0);
SUBWORDDISI (tmp_result, 1);
SUBWORDDISI (tmp_result, 1);
}

  return 4;
}

// ********** div: div $rn,$rm

static int
mep_emu_div (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{
{
0x80000000;
0;
}
{
DIVSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
MODSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
}
}
}
}

  return 2;
}

// ********** divu: divu $rn,$rm

static int
mep_emu_divu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{
UDIVSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
UMODSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
}
}
}

  return 2;
}

// ********** dret: dret

static int
mep_emu_dret (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ANDSI ([&](){ valid = 0; return 0; }(), INVSI (SLLSI (1, 15)));
{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}

  return 2;
}

// ********** dbreak: dbreak

static int
mep_emu_dbreak (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ORSI ([&](){ valid = 0; return 0; }(), 1);
}

  return 2;
}

// ********** ldz: ldz $rn,$rm

static int
mep_emu_ldz (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** abs: abs $rn,$rm

static int
mep_emu_abs (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
ABSSI (SUBSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }()));
}

  return 4;
}

// ********** ave: ave $rn,$rm

static int
mep_emu_ave (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
SRASI (ADDSI (ADDSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }()), 1), 1);
}

  return 4;
}

// ********** min: min $rn,$rm

static int
mep_emu_min (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
[&](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** max: max $rn,$rm

static int
mep_emu_max (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
[&](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** minu: minu $rn,$rm

static int
mep_emu_minu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
[&](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** maxu: maxu $rn,$rm

static int
mep_emu_maxu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
[&](){ valid = 0; return 0; }();
}
}

  return 4;
}

// ********** clip: clip $rn,$cimm5

static int
mep_emu_clip (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  SI tmp_min;
  SI tmp_max;
  tmp_max = ((((1) << (((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) - (1))))) - (1));
  tmp_min = (- (((1) << (((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) - (1))))));
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
mep_emu_clipu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
  SI tmp_max;
  tmp_max = ((((1) << (insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr))) - (1));
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
mep_emu_sadd (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
(- (((1) << (31))));
((((1) << (31))) - (1));
}
ADDSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** ssub: ssub $rn,$rm

static int
mep_emu_ssub (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
(- (((1) << (31))));
((((1) << (31))) - (1));
}
SUBSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** saddu: saddu $rn,$rm

static int
mep_emu_saddu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
(~ (0));
ADDSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** ssubu: ssubu $rn,$rm

static int
mep_emu_ssubu (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
0;
SUBSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
}
}

  return 4;
}

// ********** swcp: swcp $crn,($rma)

static int
mep_emu_swcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 2;
}

// ********** lwcp: lwcp $crn,($rma)

static int
mep_emu_lwcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
}

  return 2;
}

// ********** smcp: smcp $crn64,($rma)

static int
mep_emu_smcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
}

  return 2;
}

// ********** lmcp: lmcp $crn64,($rma)

static int
mep_emu_lmcp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** swcpi: swcpi $crn,($rma+)

static int
mep_emu_swcpi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
ADDSI ([&](){ valid = 0; return 0; }(), 4);
}

  return 2;
}

// ********** lwcpi: lwcpi $crn,($rma+)

static int
mep_emu_lwcpi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
ADDSI ([&](){ valid = 0; return 0; }(), 4);
}

  return 2;
}

// ********** smcpi: smcpi $crn64,($rma+)

static int
mep_emu_smcpi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** lmcpi: lmcpi $crn64,($rma+)

static int
mep_emu_lmcpi (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
[&](){ valid = 0; return 0; }();
}

  return 2;
}

// ********** swcp16: swcp $crn,$sdisp16($rma)

static int
mep_emu_swcp16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
}

  return 4;
}

// ********** lwcp16: lwcp $crn,$sdisp16($rma)

static int
mep_emu_lwcp16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ SI val = ANDSI (ADDSI ([&](){ valid = 0; return 0; }(), insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
}

  return 4;
}

// ********** smcp16: smcp $crn64,$sdisp16($rma)

static int
mep_emu_smcp16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
}

  return 4;
}

// ********** lmcp16: lmcp $crn64,$sdisp16($rma)

static int
mep_emu_lmcp16 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** sbcpa: sbcpa $crn,($rma+),$cdisp10

static int
mep_emu_sbcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** lbcpa: lbcpa $crn,($rma+),$cdisp10

static int
mep_emu_lbcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** shcpa: shcpa $crn,($rma+),$cdisp10a2

static int
mep_emu_shcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** lhcpa: lhcpa $crn,($rma+),$cdisp10a2

static int
mep_emu_lhcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** swcpa: swcpa $crn,($rma+),$cdisp10a4

static int
mep_emu_swcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** lwcpa: lwcpa $crn,($rma+),$cdisp10a4

static int
mep_emu_lwcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr));
}

  return 4;
}

// ********** smcpa: smcpa $crn64,($rma+),$cdisp10a8

static int
mep_emu_smcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** lmcpa: lmcpa $crn64,($rma+),$cdisp10a8

static int
mep_emu_lmcpa (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
[&](){ valid = 0; return 0; }();
}

  return 4;
}

// ********** sbcpm0: sbcpm0 $crn,($rma+),$cdisp10

static int
mep_emu_sbcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lbcpm0: lbcpm0 $crn,($rma+),$cdisp10

static int
mep_emu_lbcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** shcpm0: shcpm0 $crn,($rma+),$cdisp10a2

static int
mep_emu_shcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lhcpm0: lhcpm0 $crn,($rma+),$cdisp10a2

static int
mep_emu_lhcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** swcpm0: swcpm0 $crn,($rma+),$cdisp10a4

static int
mep_emu_swcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lwcpm0: lwcpm0 $crn,($rma+),$cdisp10a4

static int
mep_emu_lwcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
;
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** smcpm0: smcpm0 $crn64,($rma+),$cdisp10a8

static int
mep_emu_smcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lmcpm0: lmcpm0 $crn64,($rma+),$cdisp10a8

static int
mep_emu_lmcpm0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** sbcpm1: sbcpm1 $crn,($rma+),$cdisp10

static int
mep_emu_sbcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lbcpm1: lbcpm1 $crn,($rma+),$cdisp10

static int
mep_emu_lbcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTQISI ([&](){ QI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** shcpm1: shcpm1 $crn,($rma+),$cdisp10a2

static int
mep_emu_shcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lhcpm1: lhcpm1 $crn,($rma+),$cdisp10a2

static int
mep_emu_lhcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTHISI ([&](){ HI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (1)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** swcpm1: swcpm1 $crn,($rma+),$cdisp10a4

static int
mep_emu_swcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_W); }
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lwcpm1: lwcpm1 $crn,($rma+),$cdisp10a4

static int
mep_emu_lwcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
EXTSISI ([&](){ SI val = ANDSI ([&](){ valid = 0; return 0; }(), INVSI (3)); if (valid) insn_add_dref(insn, val, 0, dr_R); return 0; }()
);
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** smcpm1: smcpm1 $crn64,($rma+),$cdisp10a8

static int
mep_emu_smcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** lmcpm1: lmcpm1 $crn64,($rma+),$cdisp10a8

static int
mep_emu_lmcpm1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
[&](){ valid = 0; return 0; }();
[&](){   SI tmp_modulo_mask;
  tmp_modulo_mask = [&](){   SI tmp_temp;
  tmp_temp = ORSI ([&](){ valid = 0; return 0; }(), [&](){ valid = 0; return 0; }());
; return SRLSI (-1, [&](){ valid = 0; return 0; }()); }();
; return [&](){ ORSI (ANDSI ([&](){ valid = 0; return 0; }(), INVSI (tmp_modulo_mask)), [&](){ valid = 0; return 0; }()); return ADDSI ([&](){ valid = 0; return 0; }(), EXTSISI (insn.Op3.type == o_imm ? insn.Op3.value : insn.Op3.addr)); }(); }();
}

  return 4;
}

// ********** bcpeq: bcpeq $cccc,$pcrel17a2

static int
mep_emu_bcpeq (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{ USI val = ((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** bcpne: bcpne $cccc,$pcrel17a2

static int
mep_emu_bcpne (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{ USI val = ((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** bcpat: bcpat $cccc,$pcrel17a2

static int
mep_emu_bcpat (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{ USI val = ((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** bcpaf: bcpaf $cccc,$pcrel17a2

static int
mep_emu_bcpaf (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{ USI val = ((insn.Op2.type == o_imm ? insn.Op2.value : insn.Op2.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
}

  return 4;
}

// ********** synccp: synccp

static int
mep_emu_synccp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
((void) 0); /*nop*/
}

  return 2;
}

// ********** jsrv: jsrv $rm

static int
mep_emu_jsrv (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
ORSI (ADDSI (pc, 8), 1);
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
}
{
ORSI (ADDSI (pc, 4), 1);
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (1))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
}
{
ORSI (ADDSI (pc, 2), 1);
{
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (3))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ANDSI ([&](){ valid = 0; return 0; }(), (~ (7))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
}
}
}

  return 2;
}

// ********** bsrv: bsrv $pcrel24a2

static int
mep_emu_bsrv (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{
{
{
ORSI (ADDSI (pc, 8), 1);
{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
}
{
ORSI (ADDSI (pc, 4), 1);
{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (1)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((0) << (12)))));
}
{
ORSI (ADDSI (pc, 4), 1);
{
{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (3)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
{ USI val = ((insn.Op1.type == o_imm ? insn.Op1.value : insn.Op1.addr) & ((~ (7)))); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }
}
ORSI (ANDSI ([&](){ valid = 0; return 0; }(), (~ (((1) << (12))))), ((((1) << (12))) & (((1) << (12)))));
}
}
}

  return 4;
}

// ********** cp: cp $code24

static int
mep_emu_cp (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;


  return 4;
}

// ********** sim-syscall: --syscall--

static int
mep_emu_sim_syscall (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;


  return 2;
}

// ********** ri-0: --reserved--

static int
mep_emu_ri_0 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-1: --reserved--

static int
mep_emu_ri_1 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-2: --reserved--

static int
mep_emu_ri_2 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-3: --reserved--

static int
mep_emu_ri_3 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-4: --reserved--

static int
mep_emu_ri_4 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-5: --reserved--

static int
mep_emu_ri_5 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-6: --reserved--

static int
mep_emu_ri_6 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-7: --reserved--

static int
mep_emu_ri_7 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-8: --reserved--

static int
mep_emu_ri_8 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-9: --reserved--

static int
mep_emu_ri_9 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-10: --reserved--

static int
mep_emu_ri_10 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-11: --reserved--

static int
mep_emu_ri_11 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-12: --reserved--

static int
mep_emu_ri_12 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-13: --reserved--

static int
mep_emu_ri_13 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-14: --reserved--

static int
mep_emu_ri_14 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-15: --reserved--

static int
mep_emu_ri_15 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-17: --reserved--

static int
mep_emu_ri_17 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-20: --reserved--

static int
mep_emu_ri_20 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-21: --reserved--

static int
mep_emu_ri_21 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-22: --reserved--

static int
mep_emu_ri_22 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-23: --reserved--

static int
mep_emu_ri_23 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}

// ********** ri-26: --reserved--

static int
mep_emu_ri_26 (const insn_t &insn)
{
  ea_t pc = insn.ea;
  int valid = 1;

{ USI val = [&](){ valid = 0; return 0; }(); if (valid) insn_add_cref(insn, val, 0, has_insn_feature(insn.itype, CF_CALL) ? fl_CN : fl_JN); }

  return 2;
}


// Emulator entry
int idaapi mep_emu(const insn_t &insn)
{
  int len;  switch (insn.itype)
  {
    case MEP_INSN_X_INVALID: len = mep_emu_x_invalid(insn); break;
    case MEP_INSN_STCB_R: len = mep_emu_stcb_r(insn); break;
    case MEP_INSN_LDCB_R: len = mep_emu_ldcb_r(insn); break;
    case MEP_INSN_PREF: len = mep_emu_pref(insn); break;
    case MEP_INSN_PREFD: len = mep_emu_prefd(insn); break;
    case MEP_INSN_CASB3: len = mep_emu_casb3(insn); break;
    case MEP_INSN_CASH3: len = mep_emu_cash3(insn); break;
    case MEP_INSN_CASW3: len = mep_emu_casw3(insn); break;
    case MEP_INSN_SBCP: len = mep_emu_sbcp(insn); break;
    case MEP_INSN_LBCP: len = mep_emu_lbcp(insn); break;
    case MEP_INSN_LBUCP: len = mep_emu_lbucp(insn); break;
    case MEP_INSN_SHCP: len = mep_emu_shcp(insn); break;
    case MEP_INSN_LHCP: len = mep_emu_lhcp(insn); break;
    case MEP_INSN_LHUCP: len = mep_emu_lhucp(insn); break;
    case MEP_INSN_LBUCPA: len = mep_emu_lbucpa(insn); break;
    case MEP_INSN_LHUCPA: len = mep_emu_lhucpa(insn); break;
    case MEP_INSN_LBUCPM0: len = mep_emu_lbucpm0(insn); break;
    case MEP_INSN_LHUCPM0: len = mep_emu_lhucpm0(insn); break;
    case MEP_INSN_LBUCPM1: len = mep_emu_lbucpm1(insn); break;
    case MEP_INSN_LHUCPM1: len = mep_emu_lhucpm1(insn); break;
    case MEP_INSN_UCI: len = mep_emu_uci(insn); break;
    case MEP_INSN_DSP: len = mep_emu_dsp(insn); break;
    case MEP_INSN_SB: len = mep_emu_sb(insn); break;
    case MEP_INSN_SH: len = mep_emu_sh(insn); break;
    case MEP_INSN_SW: len = mep_emu_sw(insn); break;
    case MEP_INSN_LB: len = mep_emu_lb(insn); break;
    case MEP_INSN_LH: len = mep_emu_lh(insn); break;
    case MEP_INSN_LW: len = mep_emu_lw(insn); break;
    case MEP_INSN_LBU: len = mep_emu_lbu(insn); break;
    case MEP_INSN_LHU: len = mep_emu_lhu(insn); break;
    case MEP_INSN_SW_SP: len = mep_emu_sw_sp(insn); break;
    case MEP_INSN_LW_SP: len = mep_emu_lw_sp(insn); break;
    case MEP_INSN_SB_TP: len = mep_emu_sb_tp(insn); break;
    case MEP_INSN_SH_TP: len = mep_emu_sh_tp(insn); break;
    case MEP_INSN_SW_TP: len = mep_emu_sw_tp(insn); break;
    case MEP_INSN_LB_TP: len = mep_emu_lb_tp(insn); break;
    case MEP_INSN_LH_TP: len = mep_emu_lh_tp(insn); break;
    case MEP_INSN_LW_TP: len = mep_emu_lw_tp(insn); break;
    case MEP_INSN_LBU_TP: len = mep_emu_lbu_tp(insn); break;
    case MEP_INSN_LHU_TP: len = mep_emu_lhu_tp(insn); break;
    case MEP_INSN_SB16: len = mep_emu_sb16(insn); break;
    case MEP_INSN_SH16: len = mep_emu_sh16(insn); break;
    case MEP_INSN_SW16: len = mep_emu_sw16(insn); break;
    case MEP_INSN_LB16: len = mep_emu_lb16(insn); break;
    case MEP_INSN_LH16: len = mep_emu_lh16(insn); break;
    case MEP_INSN_LW16: len = mep_emu_lw16(insn); break;
    case MEP_INSN_LBU16: len = mep_emu_lbu16(insn); break;
    case MEP_INSN_LHU16: len = mep_emu_lhu16(insn); break;
    case MEP_INSN_SW24: len = mep_emu_sw24(insn); break;
    case MEP_INSN_LW24: len = mep_emu_lw24(insn); break;
    case MEP_INSN_EXTB: len = mep_emu_extb(insn); break;
    case MEP_INSN_EXTH: len = mep_emu_exth(insn); break;
    case MEP_INSN_EXTUB: len = mep_emu_extub(insn); break;
    case MEP_INSN_EXTUH: len = mep_emu_extuh(insn); break;
    case MEP_INSN_SSARB: len = mep_emu_ssarb(insn); break;
    case MEP_INSN_MOV: len = mep_emu_mov(insn); break;
    case MEP_INSN_MOVI8: len = mep_emu_movi8(insn); break;
    case MEP_INSN_MOVI16: len = mep_emu_movi16(insn); break;
    case MEP_INSN_MOVU24: len = mep_emu_movu24(insn); break;
    case MEP_INSN_MOVU16: len = mep_emu_movu16(insn); break;
    case MEP_INSN_MOVH: len = mep_emu_movh(insn); break;
    case MEP_INSN_ADD3: len = mep_emu_add3(insn); break;
    case MEP_INSN_ADD: len = mep_emu_add(insn); break;
    case MEP_INSN_ADD3I: len = mep_emu_add3i(insn); break;
    case MEP_INSN_ADVCK3: len = mep_emu_advck3(insn); break;
    case MEP_INSN_SUB: len = mep_emu_sub(insn); break;
    case MEP_INSN_SBVCK3: len = mep_emu_sbvck3(insn); break;
    case MEP_INSN_NEG: len = mep_emu_neg(insn); break;
    case MEP_INSN_SLT3: len = mep_emu_slt3(insn); break;
    case MEP_INSN_SLTU3: len = mep_emu_sltu3(insn); break;
    case MEP_INSN_SLT3I: len = mep_emu_slt3i(insn); break;
    case MEP_INSN_SLTU3I: len = mep_emu_sltu3i(insn); break;
    case MEP_INSN_SL1AD3: len = mep_emu_sl1ad3(insn); break;
    case MEP_INSN_SL2AD3: len = mep_emu_sl2ad3(insn); break;
    case MEP_INSN_ADD3X: len = mep_emu_add3x(insn); break;
    case MEP_INSN_SLT3X: len = mep_emu_slt3x(insn); break;
    case MEP_INSN_SLTU3X: len = mep_emu_sltu3x(insn); break;
    case MEP_INSN_OR: len = mep_emu_or(insn); break;
    case MEP_INSN_AND: len = mep_emu_and(insn); break;
    case MEP_INSN_XOR: len = mep_emu_xor(insn); break;
    case MEP_INSN_NOR: len = mep_emu_nor(insn); break;
    case MEP_INSN_OR3: len = mep_emu_or3(insn); break;
    case MEP_INSN_AND3: len = mep_emu_and3(insn); break;
    case MEP_INSN_XOR3: len = mep_emu_xor3(insn); break;
    case MEP_INSN_SRA: len = mep_emu_sra(insn); break;
    case MEP_INSN_SRL: len = mep_emu_srl(insn); break;
    case MEP_INSN_SLL: len = mep_emu_sll(insn); break;
    case MEP_INSN_SRAI: len = mep_emu_srai(insn); break;
    case MEP_INSN_SRLI: len = mep_emu_srli(insn); break;
    case MEP_INSN_SLLI: len = mep_emu_slli(insn); break;
    case MEP_INSN_SLL3: len = mep_emu_sll3(insn); break;
    case MEP_INSN_FSFT: len = mep_emu_fsft(insn); break;
    case MEP_INSN_BRA: len = mep_emu_bra(insn); break;
    case MEP_INSN_BEQZ: len = mep_emu_beqz(insn); break;
    case MEP_INSN_BNEZ: len = mep_emu_bnez(insn); break;
    case MEP_INSN_BEQI: len = mep_emu_beqi(insn); break;
    case MEP_INSN_BNEI: len = mep_emu_bnei(insn); break;
    case MEP_INSN_BLTI: len = mep_emu_blti(insn); break;
    case MEP_INSN_BGEI: len = mep_emu_bgei(insn); break;
    case MEP_INSN_BEQ: len = mep_emu_beq(insn); break;
    case MEP_INSN_BNE: len = mep_emu_bne(insn); break;
    case MEP_INSN_BSR12: len = mep_emu_bsr12(insn); break;
    case MEP_INSN_BSR24: len = mep_emu_bsr24(insn); break;
    case MEP_INSN_JMP: len = mep_emu_jmp(insn); break;
    case MEP_INSN_JMP24: len = mep_emu_jmp24(insn); break;
    case MEP_INSN_JSR: len = mep_emu_jsr(insn); break;
    case MEP_INSN_RET: len = mep_emu_ret(insn); break;
    case MEP_INSN_REPEAT: len = mep_emu_repeat(insn); break;
    case MEP_INSN_EREPEAT: len = mep_emu_erepeat(insn); break;
    case MEP_INSN_STC_LP: len = mep_emu_stc_lp(insn); break;
    case MEP_INSN_STC_HI: len = mep_emu_stc_hi(insn); break;
    case MEP_INSN_STC_LO: len = mep_emu_stc_lo(insn); break;
    case MEP_INSN_STC: len = mep_emu_stc(insn); break;
    case MEP_INSN_LDC_LP: len = mep_emu_ldc_lp(insn); break;
    case MEP_INSN_LDC_HI: len = mep_emu_ldc_hi(insn); break;
    case MEP_INSN_LDC_LO: len = mep_emu_ldc_lo(insn); break;
    case MEP_INSN_LDC: len = mep_emu_ldc(insn); break;
    case MEP_INSN_DI: len = mep_emu_di(insn); break;
    case MEP_INSN_EI: len = mep_emu_ei(insn); break;
    case MEP_INSN_RETI: len = mep_emu_reti(insn); break;
    case MEP_INSN_HALT: len = mep_emu_halt(insn); break;
    case MEP_INSN_SLEEP: len = mep_emu_sleep(insn); break;
    case MEP_INSN_SWI: len = mep_emu_swi(insn); break;
    case MEP_INSN_BREAK: len = mep_emu_break(insn); break;
    case MEP_INSN_SYNCM: len = mep_emu_syncm(insn); break;
    case MEP_INSN_STCB: len = mep_emu_stcb(insn); break;
    case MEP_INSN_LDCB: len = mep_emu_ldcb(insn); break;
    case MEP_INSN_BSETM: len = mep_emu_bsetm(insn); break;
    case MEP_INSN_BCLRM: len = mep_emu_bclrm(insn); break;
    case MEP_INSN_BNOTM: len = mep_emu_bnotm(insn); break;
    case MEP_INSN_BTSTM: len = mep_emu_btstm(insn); break;
    case MEP_INSN_TAS: len = mep_emu_tas(insn); break;
    case MEP_INSN_CACHE: len = mep_emu_cache(insn); break;
    case MEP_INSN_MUL: len = mep_emu_mul(insn); break;
    case MEP_INSN_MULU: len = mep_emu_mulu(insn); break;
    case MEP_INSN_MULR: len = mep_emu_mulr(insn); break;
    case MEP_INSN_MULRU: len = mep_emu_mulru(insn); break;
    case MEP_INSN_MADD: len = mep_emu_madd(insn); break;
    case MEP_INSN_MADDU: len = mep_emu_maddu(insn); break;
    case MEP_INSN_MADDR: len = mep_emu_maddr(insn); break;
    case MEP_INSN_MADDRU: len = mep_emu_maddru(insn); break;
    case MEP_INSN_DIV: len = mep_emu_div(insn); break;
    case MEP_INSN_DIVU: len = mep_emu_divu(insn); break;
    case MEP_INSN_DRET: len = mep_emu_dret(insn); break;
    case MEP_INSN_DBREAK: len = mep_emu_dbreak(insn); break;
    case MEP_INSN_LDZ: len = mep_emu_ldz(insn); break;
    case MEP_INSN_ABS: len = mep_emu_abs(insn); break;
    case MEP_INSN_AVE: len = mep_emu_ave(insn); break;
    case MEP_INSN_MIN: len = mep_emu_min(insn); break;
    case MEP_INSN_MAX: len = mep_emu_max(insn); break;
    case MEP_INSN_MINU: len = mep_emu_minu(insn); break;
    case MEP_INSN_MAXU: len = mep_emu_maxu(insn); break;
    case MEP_INSN_CLIP: len = mep_emu_clip(insn); break;
    case MEP_INSN_CLIPU: len = mep_emu_clipu(insn); break;
    case MEP_INSN_SADD: len = mep_emu_sadd(insn); break;
    case MEP_INSN_SSUB: len = mep_emu_ssub(insn); break;
    case MEP_INSN_SADDU: len = mep_emu_saddu(insn); break;
    case MEP_INSN_SSUBU: len = mep_emu_ssubu(insn); break;
    case MEP_INSN_SWCP: len = mep_emu_swcp(insn); break;
    case MEP_INSN_LWCP: len = mep_emu_lwcp(insn); break;
    case MEP_INSN_SMCP: len = mep_emu_smcp(insn); break;
    case MEP_INSN_LMCP: len = mep_emu_lmcp(insn); break;
    case MEP_INSN_SWCPI: len = mep_emu_swcpi(insn); break;
    case MEP_INSN_LWCPI: len = mep_emu_lwcpi(insn); break;
    case MEP_INSN_SMCPI: len = mep_emu_smcpi(insn); break;
    case MEP_INSN_LMCPI: len = mep_emu_lmcpi(insn); break;
    case MEP_INSN_SWCP16: len = mep_emu_swcp16(insn); break;
    case MEP_INSN_LWCP16: len = mep_emu_lwcp16(insn); break;
    case MEP_INSN_SMCP16: len = mep_emu_smcp16(insn); break;
    case MEP_INSN_LMCP16: len = mep_emu_lmcp16(insn); break;
    case MEP_INSN_SBCPA: len = mep_emu_sbcpa(insn); break;
    case MEP_INSN_LBCPA: len = mep_emu_lbcpa(insn); break;
    case MEP_INSN_SHCPA: len = mep_emu_shcpa(insn); break;
    case MEP_INSN_LHCPA: len = mep_emu_lhcpa(insn); break;
    case MEP_INSN_SWCPA: len = mep_emu_swcpa(insn); break;
    case MEP_INSN_LWCPA: len = mep_emu_lwcpa(insn); break;
    case MEP_INSN_SMCPA: len = mep_emu_smcpa(insn); break;
    case MEP_INSN_LMCPA: len = mep_emu_lmcpa(insn); break;
    case MEP_INSN_SBCPM0: len = mep_emu_sbcpm0(insn); break;
    case MEP_INSN_LBCPM0: len = mep_emu_lbcpm0(insn); break;
    case MEP_INSN_SHCPM0: len = mep_emu_shcpm0(insn); break;
    case MEP_INSN_LHCPM0: len = mep_emu_lhcpm0(insn); break;
    case MEP_INSN_SWCPM0: len = mep_emu_swcpm0(insn); break;
    case MEP_INSN_LWCPM0: len = mep_emu_lwcpm0(insn); break;
    case MEP_INSN_SMCPM0: len = mep_emu_smcpm0(insn); break;
    case MEP_INSN_LMCPM0: len = mep_emu_lmcpm0(insn); break;
    case MEP_INSN_SBCPM1: len = mep_emu_sbcpm1(insn); break;
    case MEP_INSN_LBCPM1: len = mep_emu_lbcpm1(insn); break;
    case MEP_INSN_SHCPM1: len = mep_emu_shcpm1(insn); break;
    case MEP_INSN_LHCPM1: len = mep_emu_lhcpm1(insn); break;
    case MEP_INSN_SWCPM1: len = mep_emu_swcpm1(insn); break;
    case MEP_INSN_LWCPM1: len = mep_emu_lwcpm1(insn); break;
    case MEP_INSN_SMCPM1: len = mep_emu_smcpm1(insn); break;
    case MEP_INSN_LMCPM1: len = mep_emu_lmcpm1(insn); break;
    case MEP_INSN_BCPEQ: len = mep_emu_bcpeq(insn); break;
    case MEP_INSN_BCPNE: len = mep_emu_bcpne(insn); break;
    case MEP_INSN_BCPAT: len = mep_emu_bcpat(insn); break;
    case MEP_INSN_BCPAF: len = mep_emu_bcpaf(insn); break;
    case MEP_INSN_SYNCCP: len = mep_emu_synccp(insn); break;
    case MEP_INSN_JSRV: len = mep_emu_jsrv(insn); break;
    case MEP_INSN_BSRV: len = mep_emu_bsrv(insn); break;
    case MEP_INSN_CP: len = mep_emu_cp(insn); break;
    case MEP_INSN_SIM_SYSCALL: len = mep_emu_sim_syscall(insn); break;
    case MEP_INSN_RI_0: len = mep_emu_ri_0(insn); break;
    case MEP_INSN_RI_1: len = mep_emu_ri_1(insn); break;
    case MEP_INSN_RI_2: len = mep_emu_ri_2(insn); break;
    case MEP_INSN_RI_3: len = mep_emu_ri_3(insn); break;
    case MEP_INSN_RI_4: len = mep_emu_ri_4(insn); break;
    case MEP_INSN_RI_5: len = mep_emu_ri_5(insn); break;
    case MEP_INSN_RI_6: len = mep_emu_ri_6(insn); break;
    case MEP_INSN_RI_7: len = mep_emu_ri_7(insn); break;
    case MEP_INSN_RI_8: len = mep_emu_ri_8(insn); break;
    case MEP_INSN_RI_9: len = mep_emu_ri_9(insn); break;
    case MEP_INSN_RI_10: len = mep_emu_ri_10(insn); break;
    case MEP_INSN_RI_11: len = mep_emu_ri_11(insn); break;
    case MEP_INSN_RI_12: len = mep_emu_ri_12(insn); break;
    case MEP_INSN_RI_13: len = mep_emu_ri_13(insn); break;
    case MEP_INSN_RI_14: len = mep_emu_ri_14(insn); break;
    case MEP_INSN_RI_15: len = mep_emu_ri_15(insn); break;
    case MEP_INSN_RI_17: len = mep_emu_ri_17(insn); break;
    case MEP_INSN_RI_20: len = mep_emu_ri_20(insn); break;
    case MEP_INSN_RI_21: len = mep_emu_ri_21(insn); break;
    case MEP_INSN_RI_22: len = mep_emu_ri_22(insn); break;
    case MEP_INSN_RI_23: len = mep_emu_ri_23(insn); break;
    case MEP_INSN_RI_26: len = mep_emu_ri_26(insn); break;
    default: len = 0; break;
  }
  if (len && !has_insn_feature(insn.itype, CF_STOP))
  {
    insn_add_cref(insn, insn.ea+len, 0, fl_F);
  } else if (may_trace_sp()) {
    recalc_spd(insn.ea);
  }
  return 1;
}
