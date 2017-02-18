/* MEP IDP output

THIS FILE IS MACHINE GENERATED WITH CGEN.

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

  
extern void out_print_address(op_t &x, ea_t pc);
extern void out_print_spreg(op_t &x, ea_t pc);
extern void out_print_tpreg(op_t &x, ea_t pc);

void idaapi mep_data(ea_t ea)
{
  gl_name = 1;
  intel_data(ea);
}

static bool cgen_outop(op_t &x, uint16 opindex, ea_t pc)
{
  switch (opindex)
  {
    case MEP_OPERAND_ADDR24A4 :
      out_print_address(x, pc);
      break;
    case MEP_OPERAND_C5RMUIMM20 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_C5RNMUIMM24 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CALLNUM :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CCCC :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CCRN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CDISP10 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP10A2 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP10A4 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP10A8 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CDISP12 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CIMM4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CIMM5 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CODE16 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CODE24 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_CP_FLAG :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRN64 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRNX :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRNX64 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CROC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CROP :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRPC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRPP :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRQC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CRQP :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CSRN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_CSRN_IDX :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_DBG :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_DEPC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_EPC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_EXC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_HI :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_IMM16P0 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P12 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P25 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P5 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM3P9 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM4P10 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM4P4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM4P8 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P23 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P3 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P7 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM5P8 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM6P2 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM6P6 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM8P0 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM8P20 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IMM8P4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_2 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_3 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_0_5 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_6_1 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_6_2 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC_X_6_3 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_IVC2C3CCRN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_IVC2CCRN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_IVC2CRN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_IVC2RM :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_LO :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_LP :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_MB0 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_MB1 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_ME0 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_ME1 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_NPC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_OPT :
      out_register(ph.regNames[x.reg]);
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
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_R0 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_R1 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RL :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RL5 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RM :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RMA :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3 :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3C :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3L :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3S :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3UC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3UL :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RN3US :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RNC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RNL :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RNS :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RNUC :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RNUL :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_RNUS :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_SAR :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_SDISP16 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM16 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM16P0 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM6 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8P0 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8P20 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SIMM8P4 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_SP :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_SPR :
      out_print_spreg(x, pc);
      break;
    case MEP_OPERAND_TP :
      out_register(ph.regNames[x.reg]);
      break;
    case MEP_OPERAND_TPR :
      out_print_tpreg(x, pc);
      break;
    case MEP_OPERAND_UDISP2 :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UDISP7 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UDISP7A2 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UDISP7A4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM16 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM2 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM24 :
      if (!out_name_expr(x, x.value, x.value))
      {
        OutValue(x, OOF_NUMBER|OOFW_IMM);
      }
      break;
    case MEP_OPERAND_UIMM3 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM5 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_UIMM7A4 :
      OutValue(x, OOF_NUMBER|OOFW_IMM);
      break;
    case MEP_OPERAND_ZERO :
      OutValue(x, OOF_SIGNED|OOF_NUMBER|OOFW_IMM);
      break;
    default: return 0;
  }
  return 1;
}

bool idaapi outop(op_t &x)
{
  return cgen_outop(x, x.cgen_optype, cmd.ea);
}

void idaapi out(void)
{
  char buf[MAXSTR];
  init_output_buffer(buf, sizeof(buf));
  switch (cmd.itype)
  {
case MEP_INSN_STCB_R:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LDCB_R:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_PREF:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_PREFD:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_CASB3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_CASH3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_CASW3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SBCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBUCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SHCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LHCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LHUCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBUCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHUCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBUCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHUCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBUCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHUCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_UCI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_DSP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SB:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SH:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SW:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LB:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LH:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LW:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LBU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LHU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SW_SP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_SPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_LW_SP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_SPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_SB_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_SH_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_SW_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_LB_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_LH_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_LW_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_LBU_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_LHU_TP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    cgen_outop(cmd.Op3, MEP_OPERAND_TPR, cmd.ea);
    out_symbol(')');
    break;
case MEP_INSN_SB16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SH16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SW16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LB16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LH16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LW16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LBU16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LHU16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SW24:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LW24:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_EXTB:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_EXTH:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_EXTUB:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_EXTUH:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_SSARB:
    OutMnem();
    out_one_operand(0);
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_MOV:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVI8:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVI16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVU24:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVU16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MOVH:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ADD3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_ADD:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ADD3I:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    cgen_outop(cmd.Op2, MEP_OPERAND_SPR, cmd.ea);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_ADVCK3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SUB:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SBVCK3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_NEG:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLT3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLTU3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLT3I:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLTU3I:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SL1AD3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SL2AD3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ADD3X:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SLT3X:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SLTU3X:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_OR:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_AND:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_XOR:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_NOR:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_OR3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_AND3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_XOR3:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SRA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SRL:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLL:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SRAI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SRLI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLLI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SLL3:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_FSFT:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BRA:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_BEQZ:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BNEZ:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BEQI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BNEI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BLTI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BGEI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BEQ:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BNE:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BSR12:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_BSR24:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_JMP:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_JMP24:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_JSR:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_RET:
    OutMnem();
    break;
case MEP_INSN_REPEAT:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_EREPEAT:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_STC_LP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('p');
    break;
case MEP_INSN_STC_HI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('$');
    out_symbol('h');
    out_symbol('i');
    break;
case MEP_INSN_STC_LO:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('o');
    break;
case MEP_INSN_STC:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_LDC_LP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('p');
    break;
case MEP_INSN_LDC_HI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('$');
    out_symbol('h');
    out_symbol('i');
    break;
case MEP_INSN_LDC_LO:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('$');
    out_symbol('l');
    out_symbol('o');
    break;
case MEP_INSN_LDC:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DI:
    OutMnem();
    break;
case MEP_INSN_EI:
    OutMnem();
    break;
case MEP_INSN_RETI:
    OutMnem();
    break;
case MEP_INSN_HALT:
    OutMnem();
    break;
case MEP_INSN_SLEEP:
    OutMnem();
    break;
case MEP_INSN_SWI:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_BREAK:
    OutMnem();
    break;
case MEP_INSN_SYNCM:
    OutMnem();
    break;
case MEP_INSN_STCB:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_LDCB:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BSETM:
    OutMnem();
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCLRM:
    OutMnem();
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BNOTM:
    OutMnem();
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BTSTM:
    OutMnem();
    out_symbol('$');
    out_symbol('0');
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(0);
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_TAS:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_CACHE:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_MUL:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MULU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MULR:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MULRU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADD:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADDU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADDR:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MADDRU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DIV:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DIVU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_DRET:
    OutMnem();
    break;
case MEP_INSN_DBREAK:
    OutMnem();
    break;
case MEP_INSN_LDZ:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_ABS:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_AVE:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MIN:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MAX:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MINU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_MAXU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_CLIP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_CLIPU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SADD:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SSUB:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SADDU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SSUBU:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SWCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LWCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SMCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_LMCP:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol(')');
    break;
case MEP_INSN_SWCPI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_LWCPI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_SMCPI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_LMCPI:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    break;
case MEP_INSN_SWCP16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LWCP16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SMCP16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_LMCP16:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    out_symbol('(');
    out_one_operand(2);
    out_symbol(')');
    break;
case MEP_INSN_SBCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SHCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SWCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LWCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SMCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LMCPA:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SBCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SHCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SWCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LWCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SMCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LMCPM0:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SBCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LBCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SHCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LHCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SWCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LWCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_SMCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_LMCPM1:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_symbol('(');
    out_one_operand(1);
    out_symbol('+');
    out_symbol(')');
    out_symbol(',');
    OutChar(' ');
    out_one_operand(2);
    break;
case MEP_INSN_BCPEQ:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCPNE:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCPAT:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_BCPAF:
    OutMnem();
    out_one_operand(0);
    out_symbol(',');
    OutChar(' ');
    out_one_operand(1);
    break;
case MEP_INSN_SYNCCP:
    OutMnem();
    break;
case MEP_INSN_JSRV:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_BSRV:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_CP:
    OutMnem();
    out_one_operand(0);
    break;
case MEP_INSN_SIM_SYSCALL:
    OutMnem();
    break;
case MEP_INSN_RI_0:
    OutMnem();
    break;
case MEP_INSN_RI_1:
    OutMnem();
    break;
case MEP_INSN_RI_2:
    OutMnem();
    break;
case MEP_INSN_RI_3:
    OutMnem();
    break;
case MEP_INSN_RI_4:
    OutMnem();
    break;
case MEP_INSN_RI_5:
    OutMnem();
    break;
case MEP_INSN_RI_6:
    OutMnem();
    break;
case MEP_INSN_RI_7:
    OutMnem();
    break;
case MEP_INSN_RI_8:
    OutMnem();
    break;
case MEP_INSN_RI_9:
    OutMnem();
    break;
case MEP_INSN_RI_10:
    OutMnem();
    break;
case MEP_INSN_RI_11:
    OutMnem();
    break;
case MEP_INSN_RI_12:
    OutMnem();
    break;
case MEP_INSN_RI_13:
    OutMnem();
    break;
case MEP_INSN_RI_14:
    OutMnem();
    break;
case MEP_INSN_RI_15:
    OutMnem();
    break;
case MEP_INSN_RI_17:
    OutMnem();
    break;
case MEP_INSN_RI_20:
    OutMnem();
    break;
case MEP_INSN_RI_21:
    OutMnem();
    break;
case MEP_INSN_RI_22:
    OutMnem();
    break;
case MEP_INSN_RI_23:
    OutMnem();
    break;
case MEP_INSN_RI_26:
    OutMnem();
    break;
    default: break;
  }
  term_output_buffer();
  gl_comm = 1;
  MakeLine(buf);
}
