/* MEP IDP output

THIS FILE IS (mostly) MACHINE GENERATED WITH CGEN.

Copyright 1996-2010 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#include "mep.hpp"

//----------------------------------------------------------------------
class out_mep_t : public outctx_t
{
  out_mep_t(void) : outctx_t(BADADDR) {} // not used
public:
  bool out_operand(const op_t &x);
  void out_insn(void);
private:
  void out_print_address(const op_t &x, ea_t pc, int n = 0);
  void out_print_spreg(const op_t &/*x*/, ea_t /*pc*/);
  void out_print_tpreg(const op_t &/*x*/, ea_t /*pc*/);
  bool cgen_outop(const op_t &x, uint16 opindex, ea_t pc);
};
CASSERT(sizeof(out_mep_t) == sizeof(outctx_t));

DECLARE_OUT_FUNCS_WITHOUT_OUTMNEM(out_mep_t)

void out_mep_t::out_print_address(const op_t &x, ea_t pc, int n)
{
  const char *prefix;

  refinfo_t ri;
  if (get_refinfo(&ri, pc, n))
  {
    switch (ri.type())
    {
      case REF_LOW8: prefix = "LO8"; break;
      case REF_LOW16: prefix = "LO16"; break;
      case REF_HIGH8: prefix = "HI8"; break;
      case REF_HIGH16: prefix = "HI16"; break;
      default: prefix = NULL; break;
    }
  } else {
    prefix = NULL;
  }

  if (prefix)
  {
    out_line(prefix, COLOR_MACRO);
    out_line("(", COLOR_MACRO);
  }
  if (!out_name_expr(x, x.addr))
  {
    out_tagon(COLOR_ERROR);
    out_value(x, OOF_ADDR | OOF_NUMBER | OOFS_NOSIGN);
    out_tagoff(COLOR_ERROR);
    remember_problem(PR_NONAME, insn.ea);
  }
  if (prefix)
  {
    out_line(")", COLOR_MACRO);
  }
}

void out_mep_t::out_print_spreg(const op_t &/*x*/, ea_t /*pc*/)
{
  out_register("$sp");
}

void out_mep_t::out_print_tpreg(const op_t &/*x*/, ea_t /*pc*/)
{
  out_register("$tp");
}

bool out_mep_t::cgen_outop(const op_t &x, uint16 opindex, ea_t pc)
{
  switch (opindex)
  {
    case MEP_OPERAND_ADDR24A4 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_C5RMUIMM20 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_C5RNMUIMM24 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CALLNUM :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CCCC :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CCRN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CDISP10 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP10A2 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP10A4 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP10A8 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP12 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CIMM4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CIMM5 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CODE16 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CODE24 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CP_FLAG :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRN64 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRNX :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRNX64 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CROC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CROP :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRPC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRPP :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRQC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CRQP :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CSRN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_CSRN_IDX :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_DBG :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_DEPC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_EPC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_EXC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_HI :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_IMM16P0 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P12 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P25 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P5 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P9 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM4P10 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM4P4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM4P8 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P23 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P3 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P7 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P8 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM6P2 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM6P6 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM8P0 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM8P20 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM8P4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_2 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_3 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_5 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_6_1 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_6_2 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_6_3 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC2C3CCRN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_IVC2CCRN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_IVC2CRN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_IVC2RM :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_LO :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_LP :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_MB0 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_MB1 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_ME0 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_ME1 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_NPC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_OPT :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_PCABS24A2 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_PCREL12A2 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_PCREL17A2 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_PCREL24A2 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_PCREL8A2 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_PSW :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_R0 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_R1 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RL :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RL5 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RM :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RMA :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3 :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3C :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3L :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3S :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3UC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3UL :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RN3US :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RNC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RNL :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RNS :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RNUC :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RNUL :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_RNUS :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_SAR :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_SDISP16 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM16 :
      if (x.type == o_imm)
      {
        out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      }
      else if (x.type == o_mem)
      {
        out_print_address(x, pc, x.n);
      }
      break;
    case MEP_OPERAND_SIMM16P0 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM6 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8P0 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8P20 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8P4 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SP :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_SPR :
      out_print_spreg(x, pc);
      break;
    case MEP_OPERAND_TP :
      out_register(ph.reg_names[x.reg]);
      break;
    case MEP_OPERAND_TPR :
      out_print_tpreg(x, pc);
      break;
    case MEP_OPERAND_UDISP2 :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UDISP7 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UDISP7A2 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UDISP7A4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM16 :
      if (x.type == o_imm)
      {
        out_value(x, OOF_NUMBER|OOFW_IMM);
      }
      else if (x.type == o_mem)
      {
        out_print_address(x, pc, x.n);
      }
      break;
    case MEP_OPERAND_UIMM2 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM24 :
      if (x.type == o_imm)
      {
        out_value(x, OOF_NUMBER|OOFW_IMM);
      }
      else if (x.type == o_mem)
      {
        out_print_address(x, pc, x.n);
      }
      break;
    case MEP_OPERAND_UIMM3 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM5 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM7A4 :
      out_value(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_ZERO :
      out_value(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    default: return 0;
  }
  return 1;
}

bool out_mep_t::out_operand(const op_t &x)
{
  return cgen_outop(x, x.cgen_optype, insn.ea);
}

void out_mep_t::out_insn(void)
{
  switch (insn.itype)
  {
case MEP_INSN_STCB_R:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LDCB_R:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_PREF:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_PREFD:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_CASB3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_CASH3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_CASW3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SBCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBUCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SHCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LHCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LHUCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBUCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHUCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBUCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHUCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBUCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHUCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_UCI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_DSP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SB:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SH:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SW:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LB:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LH:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LW:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LBU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LHU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SW_SP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_SPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_LW_SP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_SPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_SB_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_SH_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_SW_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_LB_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_LH_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_LW_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_LBU_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_LHU_TP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(insn.Op3, MEP_OPERAND_TPR, insn.ea);
    out_symbol(')');
    break;
case MEP_INSN_SB16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SH16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SW16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LB16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LH16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LW16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBU16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LHU16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SW24:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LW24:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_EXTB:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_EXTH:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_EXTUB:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_EXTUH:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_SSARB:
    out_mnem();
    out_one_operand(0);
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_MOV:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVI8:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVI16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVU24:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVU16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVH:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ADD3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_ADD:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ADD3I:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    cgen_outop(insn.Op2, MEP_OPERAND_SPR, insn.ea);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_ADVCK3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SUB:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SBVCK3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_NEG:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLT3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLTU3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLT3I:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLTU3I:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SL1AD3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SL2AD3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ADD3X:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SLT3X:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SLTU3X:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_OR:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_AND:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_XOR:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_NOR:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_OR3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_AND3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_XOR3:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SRA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SRL:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLL:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SRAI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SRLI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLLI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLL3:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_FSFT:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BRA:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_BEQZ:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BNEZ:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BEQI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BNEI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BLTI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BGEI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BEQ:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BNE:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BSR12:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_BSR24:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_JMP:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_JMP24:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_JSR:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_RET:
    out_mnem();
    break;
case MEP_INSN_REPEAT:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_EREPEAT:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_STC_LP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('p');
    break;
case MEP_INSN_STC_HI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('$');
    out_symbol('h');
    out_symbol('i');
    break;
case MEP_INSN_STC_LO:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('o');
    break;
case MEP_INSN_STC:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_LDC_LP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('p');
    break;
case MEP_INSN_LDC_HI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('$');
    out_symbol('h');
    out_symbol('i');
    break;
case MEP_INSN_LDC_LO:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('o');
    break;
case MEP_INSN_LDC:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DI:
    out_mnem();
    break;
case MEP_INSN_EI:
    out_mnem();
    break;
case MEP_INSN_RETI:
    out_mnem();
    break;
case MEP_INSN_HALT:
    out_mnem();
    break;
case MEP_INSN_SLEEP:
    out_mnem();
    break;
case MEP_INSN_SWI:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_BREAK:
    out_mnem();
    break;
case MEP_INSN_SYNCM:
    out_mnem();
    break;
case MEP_INSN_STCB:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_LDCB:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BSETM:
    out_mnem();
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCLRM:
    out_mnem();
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BNOTM:
    out_mnem();
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BTSTM:
    out_mnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_TAS:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_CACHE:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_MUL:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MULU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MULR:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MULRU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADD:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADDU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADDR:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADDRU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DIV:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DIVU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DRET:
    out_mnem();
    break;
case MEP_INSN_DBREAK:
    out_mnem();
    break;
case MEP_INSN_LDZ:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ABS:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_AVE:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MIN:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MAX:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MINU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MAXU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_CLIP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_CLIPU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SADD:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SSUB:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SADDU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SSUBU:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SWCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LWCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SMCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LMCP:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SWCPI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_LWCPI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_SMCPI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_LMCPI:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_SWCP16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LWCP16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SMCP16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LMCP16:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SBCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SHCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SWCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LWCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SMCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LMCPA:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SBCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SHCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SWCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LWCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SMCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LMCPM0:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SBCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SHCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SWCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LWCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SMCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LMCPM1:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    out_char(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BCPEQ:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCPNE:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCPAT:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCPAF:
    out_mnem();
    out_one_operand(0);
    out_symbol(',');
    out_char(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SYNCCP:
    out_mnem();
    break;
case MEP_INSN_JSRV:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_BSRV:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_CP:
    out_mnem();
    out_one_operand(0);
    break;
case MEP_INSN_SIM_SYSCALL:
    out_mnem();
    break;
case MEP_INSN_RI_0:
    out_mnem();
    break;
case MEP_INSN_RI_1:
    out_mnem();
    break;
case MEP_INSN_RI_2:
    out_mnem();
    break;
case MEP_INSN_RI_3:
    out_mnem();
    break;
case MEP_INSN_RI_4:
    out_mnem();
    break;
case MEP_INSN_RI_5:
    out_mnem();
    break;
case MEP_INSN_RI_6:
    out_mnem();
    break;
case MEP_INSN_RI_7:
    out_mnem();
    break;
case MEP_INSN_RI_8:
    out_mnem();
    break;
case MEP_INSN_RI_9:
    out_mnem();
    break;
case MEP_INSN_RI_10:
    out_mnem();
    break;
case MEP_INSN_RI_11:
    out_mnem();
    break;
case MEP_INSN_RI_12:
    out_mnem();
    break;
case MEP_INSN_RI_13:
    out_mnem();
    break;
case MEP_INSN_RI_14:
    out_mnem();
    break;
case MEP_INSN_RI_15:
    out_mnem();
    break;
case MEP_INSN_RI_17:
    out_mnem();
    break;
case MEP_INSN_RI_20:
    out_mnem();
    break;
case MEP_INSN_RI_21:
    out_mnem();
    break;
case MEP_INSN_RI_22:
    out_mnem();
    break;
case MEP_INSN_RI_23:
    out_mnem();
    break;
case MEP_INSN_RI_26:
    out_mnem();
    break;
    default: break;
  }
  flush_outbuf();
}
