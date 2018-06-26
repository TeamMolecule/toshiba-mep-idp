/* MEP IDP analysis

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

 /* The size of an "int" needed to hold an instruction word.
   This is usually 32 bits, but some architectures needs 64 bits.  */
typedef CGEN_INSN_INT CGEN_INSN_WORD;
  
/* Split the instruction into chunks. stolen from binutils */

static inline uint64_t get_bits (const void *p, int bits, int big_p)
{
  const unsigned char *addr = (const unsigned char *) p;
  uint64_t data;
  int i;
  int bytes;

  if (bits % 8 != 0)
    abort ();

  data = 0;
  bytes = bits / 8;
  for (i = 0; i < bytes; i++)
    {
      int addr_index = big_p ? i : bytes - i - 1;

      data = (data << 8) | addr[addr_index];
    }

  return data;
}

static inline CGEN_INSN_WORD get_insn_value(unsigned char *buf, int length)
{
  int big_p = 0;
  int insn_chunk_bitsize = 16;
  CGEN_INSN_WORD value = 0;

  if (insn_chunk_bitsize != 0 && insn_chunk_bitsize < length)
    {
      /* We need to divide up the incoming value into insn_chunk_bitsize-length
   segments, and endian-convert them, one at a time. */
      int i;

      /* Enforce divisibility. */ 
      if ((length % insn_chunk_bitsize) != 0)
  abort ();

      for (i = 0; i < length; i += insn_chunk_bitsize) /* NB: i == bits */
  {
    int bit_index;
    uint64_t this_value;

    bit_index = i; /* NB: not dependent on endianness; opposite of cgen_put_insn_value! */
    this_value = get_bits (& buf[bit_index / 8], insn_chunk_bitsize, big_p);
    value = (value << insn_chunk_bitsize) | this_value;
  }
    }
  else
    {
      value = get_bits (buf, length, big_p);
    }

  return value;
}

static inline ea_t calc_reference_target(ea_t from, const refinfo_t &ri, adiff_t opval)
{
  ea_t target;
  ea_t base;
  calc_reference_data(&target, &base, from, ri, opval);
  return base+target;
}

/* Analyze the current instruction.  */

int idaapi mep_ana(insn_t *_insn)
{
  insn_t &ida_insn = *_insn;

  /* temporary buffer */
  unsigned char buffer[4];

  /* Result of decoder.  */
  MEP_INSN_TYPE itype;

  CGEN_INSN_WORD insn;
  CGEN_INSN_WORD entire_insn;
  ea_t pc;
  get_data_value((uval_t *)buffer, ida_insn.ea, 4);
  insn = get_insn_value(buffer, 16);
  entire_insn = get_insn_value(buffer, 32);
  pc = ida_insn.ea;
  {

    {
      unsigned int val = (((insn >> 8) & (15 << 4)) | ((insn >> 0) & (15 << 0)));
      switch (val)
      {
      case 0 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_MOV; goto extract_sfmt_mov;
      case 1 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_NEG; goto extract_sfmt_mov;
      case 2 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLT3; goto extract_sfmt_advck3;
      case 3 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLTU3; goto extract_sfmt_advck3;
      case 4 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SUB; goto extract_sfmt_sub;
      case 5 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SBVCK3; goto extract_sfmt_advck3;
      case 6 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_0; goto extract_sfmt_break;
      case 7 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_ADVCK3; goto extract_sfmt_advck3;
      case 8 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SB; goto extract_sfmt_sb;
      case 9 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SH; goto extract_sfmt_sh;
      case 10 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SW; goto extract_sfmt_sw;
      case 11 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LBU; goto extract_sfmt_lbu;
      case 12 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LB; goto extract_sfmt_lb;
      case 13 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LH; goto extract_sfmt_lh;
      case 14 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LW; goto extract_sfmt_lw;
      case 15 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LHU; goto extract_sfmt_lhu;
      case 16 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_OR; goto extract_sfmt_sub;
      case 17 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_AND; goto extract_sfmt_sub;
      case 18 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_XOR; goto extract_sfmt_sub;
      case 19 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_NOR; goto extract_sfmt_sub;
      case 20 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_MUL; goto extract_sfmt_mul;
      case 21 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_MULU; goto extract_sfmt_mul;
      case 22 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_MULR; goto extract_sfmt_mulr;
      case 23 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_MULRU; goto extract_sfmt_mulr;
      case 24 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_DIV; goto extract_sfmt_div;
      case 25 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_DIVU; goto extract_sfmt_div;
      case 26 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_1; goto extract_sfmt_break;
      case 27 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_2; goto extract_sfmt_break;
      case 28 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xfc0f) == 0x100c)
          { itype = MEP_INSN_SSARB; goto extract_sfmt_ssarb; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 29 :
        {
          unsigned int val = (((insn >> 6) & (1 << 1)) | ((insn >> 5) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x100d)
              { itype = MEP_INSN_EXTB; goto extract_sfmt_extb; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x102d)
              { itype = MEP_INSN_EXTH; goto extract_sfmt_extb; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x108d)
              { itype = MEP_INSN_EXTUB; goto extract_sfmt_extb; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 3 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf0ff) == 0x10ad)
              { itype = MEP_INSN_EXTUH; goto extract_sfmt_extb; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 30 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xff0f) == 0x100e)
          { itype = MEP_INSN_JMP; goto extract_sfmt_jmp; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 31 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xff0f) == 0x100f)
              { itype = MEP_INSN_JSR; goto extract_sfmt_jsr; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xff0f) == 0x180f)
              { itype = MEP_INSN_JSRV; goto extract_sfmt_jsr; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 32 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2000)
          { itype = MEP_INSN_BSETM; goto extract_sfmt_bsetm; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 33 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2001)
          { itype = MEP_INSN_BCLRM; goto extract_sfmt_bsetm; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 34 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2002)
          { itype = MEP_INSN_BNOTM; goto extract_sfmt_bsetm; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 35 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf80f) == 0x2003)
          { itype = MEP_INSN_BTSTM; goto extract_sfmt_btstm; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 36 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_TAS; goto extract_sfmt_tas;
      case 37 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_3; goto extract_sfmt_break;
      case 38 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SL1AD3; goto extract_sfmt_sl1ad3;
      case 39 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SL2AD3; goto extract_sfmt_sl1ad3;
      case 40 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_4; goto extract_sfmt_break;
      case 41 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_5; goto extract_sfmt_break;
      case 42 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_6; goto extract_sfmt_break;
      case 43 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_7; goto extract_sfmt_break;
      case 44 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SRL; goto extract_sfmt_sub;
      case 45 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SRA; goto extract_sfmt_sub;
      case 46 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLL; goto extract_sfmt_sub;
      case 47 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_FSFT; goto extract_sfmt_fsft;
      case 48 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SWCPI; goto extract_sfmt_swcpi;
      case 49 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LWCPI; goto extract_sfmt_lwcpi;
      case 50 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SMCPI; goto extract_sfmt_smcpi;
      case 51 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LMCPI; goto extract_sfmt_lmcpi;
      case 52 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_8; goto extract_sfmt_break;
      case 53 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_9; goto extract_sfmt_break;
      case 54 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_10; goto extract_sfmt_break;
      case 55 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_11; goto extract_sfmt_break;
      case 56 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SWCP; goto extract_sfmt_swcp;
      case 57 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LWCP; goto extract_sfmt_lwcp;
      case 58 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SMCP; goto extract_sfmt_smcp;
      case 59 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LMCP; goto extract_sfmt_lmcp;
      case 60 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_12; goto extract_sfmt_break;
      case 61 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_13; goto extract_sfmt_break;
      case 62 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_14; goto extract_sfmt_break;
      case 63 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_15; goto extract_sfmt_break;
      case 64 : /* fall through */
      case 68 : /* fall through */
      case 72 : /* fall through */
      case 76 :
        {
          unsigned int val = (((insn >> 7) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_ADD3I; goto extract_sfmt_add3i;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf880) == 0x4880)
              { itype = MEP_INSN_LBU_TP; goto extract_sfmt_lbu_tp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 65 : /* fall through */
      case 69 : /* fall through */
      case 73 : /* fall through */
      case 77 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xf880) == 0x4880)
          { itype = MEP_INSN_LBU_TP; goto extract_sfmt_lbu_tp; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 66 : /* fall through */
      case 70 : /* fall through */
      case 74 : /* fall through */
      case 78 :
        {
          unsigned int val = (((insn >> 10) & (1 << 1)) | ((insn >> 7) & (1 << 0)));
          switch (val)
          {
          case 0 : /* fall through */
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_SW_SP; goto extract_sfmt_sw_sp;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_SW_TP; goto extract_sfmt_sw_tp;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LBU_TP; goto extract_sfmt_lbu_tp;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 67 : /* fall through */
      case 71 : /* fall through */
      case 75 : /* fall through */
      case 79 :
        {
          unsigned int val = (((insn >> 10) & (1 << 1)) | ((insn >> 7) & (1 << 0)));
          switch (val)
          {
          case 0 : /* fall through */
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LW_SP; goto extract_sfmt_lw_sp;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LW_TP; goto extract_sfmt_lw_tp;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LBU_TP; goto extract_sfmt_lbu_tp;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 80 : /* fall through */
      case 81 : /* fall through */
      case 82 : /* fall through */
      case 83 : /* fall through */
      case 84 : /* fall through */
      case 85 : /* fall through */
      case 86 : /* fall through */
      case 87 : /* fall through */
      case 88 : /* fall through */
      case 89 : /* fall through */
      case 90 : /* fall through */
      case 91 : /* fall through */
      case 92 : /* fall through */
      case 93 : /* fall through */
      case 94 : /* fall through */
      case 95 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_MOVI8; goto extract_sfmt_movi8;
      case 96 : /* fall through */
      case 100 : /* fall through */
      case 104 : /* fall through */
      case 108 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_ADD; goto extract_sfmt_add;
      case 97 : /* fall through */
      case 105 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLT3I; goto extract_sfmt_slt3i;
      case 98 : /* fall through */
      case 106 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SRLI; goto extract_sfmt_srai;
      case 99 : /* fall through */
      case 107 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SRAI; goto extract_sfmt_srai;
      case 101 : /* fall through */
      case 109 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLTU3I; goto extract_sfmt_slt3i;
      case 102 : /* fall through */
      case 110 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLLI; goto extract_sfmt_srai;
      case 103 : /* fall through */
      case 111 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_SLL3; goto extract_sfmt_sll3;
      case 112 :
        {
          unsigned int val = (((insn >> 10) & (1 << 1)) | ((insn >> 4) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7000)
              { itype = MEP_INSN_DI; goto extract_sfmt_di; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7010)
              { itype = MEP_INSN_EI; goto extract_sfmt_di; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 : /* fall through */
          case 3 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xf8ef) == 0x7800)
              { itype = MEP_INSN_SIM_SYSCALL; goto extract_sfmt_sim_syscall; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 113 :
        {
          unsigned int val = (((insn >> 4) & (3 << 0)));
          switch (val)
          {
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7011)
              { itype = MEP_INSN_SYNCM; goto extract_sfmt_sleep; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7021)
              { itype = MEP_INSN_SYNCCP; goto extract_sfmt_synccp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 114 :
        {
          unsigned int val = (((insn >> 4) & (7 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7002)
              { itype = MEP_INSN_RET; goto extract_sfmt_ret; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7012)
              { itype = MEP_INSN_RETI; goto extract_sfmt_reti; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7022)
              { itype = MEP_INSN_HALT; goto extract_sfmt_halt; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 3 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7032)
              { itype = MEP_INSN_BREAK; goto extract_sfmt_break; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 6 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7062)
              { itype = MEP_INSN_SLEEP; goto extract_sfmt_sleep; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 115 :
        {
          unsigned int val = (((insn >> 5) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7013)
              { itype = MEP_INSN_DRET; goto extract_sfmt_dret; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            entire_insn = entire_insn >> 16;
            if ((entire_insn & 0xffff) == 0x7033)
              { itype = MEP_INSN_DBREAK; goto extract_sfmt_dbreak; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 116 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_CACHE; goto extract_sfmt_pref;
      case 117 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_PREF; goto extract_sfmt_pref;
      case 118 :
        entire_insn = entire_insn >> 16;
        if ((entire_insn & 0xffcf) == 0x7006)
          { itype = MEP_INSN_SWI; goto extract_sfmt_swi; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 119 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_17; goto extract_sfmt_break;
      case 120 :
        {
          unsigned int val = (((insn >> 4) & (15 << 0)));
          switch (val)
          {
          case 0 : /* fall through */
          case 2 : /* fall through */
          case 3 : /* fall through */
          case 4 : /* fall through */
          case 5 : /* fall through */
          case 6 : /* fall through */
          case 9 : /* fall through */
          case 10 : /* fall through */
          case 11 : /* fall through */
          case 12 : /* fall through */
          case 13 : /* fall through */
          case 14 : /* fall through */
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_STC; goto extract_sfmt_stc;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_STC_LP; goto extract_sfmt_stc_lp;
          case 7 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_STC_HI; goto extract_sfmt_stc_hi;
          case 8 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_STC_LO; goto extract_sfmt_stc_lo;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 121 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_STC; goto extract_sfmt_stc;
      case 122 :
        {
          unsigned int val = (((insn >> 4) & (15 << 0)));
          switch (val)
          {
          case 0 : /* fall through */
          case 2 : /* fall through */
          case 3 : /* fall through */
          case 4 : /* fall through */
          case 5 : /* fall through */
          case 6 : /* fall through */
          case 9 : /* fall through */
          case 10 : /* fall through */
          case 11 : /* fall through */
          case 12 : /* fall through */
          case 13 : /* fall through */
          case 14 : /* fall through */
          case 15 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LDC; goto extract_sfmt_ldc;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LDC_LP; goto extract_sfmt_ldc_lp;
          case 7 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LDC_HI; goto extract_sfmt_ldc_hi;
          case 8 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LDC_LO; goto extract_sfmt_ldc_lo;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 123 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LDC; goto extract_sfmt_ldc;
      case 124 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_STCB_R; goto extract_sfmt_stcb_r;
      case 125 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_LDCB_R; goto extract_sfmt_ldcb_r;
      case 126 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_20; goto extract_sfmt_break;
      case 127 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_21; goto extract_sfmt_break;
      case 128 : /* fall through */
      case 130 : /* fall through */
      case 132 : /* fall through */
      case 134 : /* fall through */
      case 136 : /* fall through */
      case 138 : /* fall through */
      case 140 : /* fall through */
      case 142 :
        {
          unsigned int val = (((insn >> 10) & (1 << 1)) | ((insn >> 7) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_SB_TP; goto extract_sfmt_sb_tp;
          case 1 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_SH_TP; goto extract_sfmt_sh_tp;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LB_TP; goto extract_sfmt_lb_tp;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LH_TP; goto extract_sfmt_lh_tp;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 129 : /* fall through */
      case 131 : /* fall through */
      case 133 : /* fall through */
      case 135 : /* fall through */
      case 137 : /* fall through */
      case 139 : /* fall through */
      case 141 : /* fall through */
      case 143 :
        {
          unsigned int val = (((insn >> 10) & (1 << 1)) | ((insn >> 7) & (1 << 0)));
          switch (val)
          {
          case 0 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_SB_TP; goto extract_sfmt_sb_tp;
          case 2 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LB_TP; goto extract_sfmt_lb_tp;
          case 3 :
            entire_insn = entire_insn >> 16;
            itype = MEP_INSN_LHU_TP; goto extract_sfmt_lhu_tp;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 144 : /* fall through */
      case 145 : /* fall through */
      case 146 : /* fall through */
      case 147 : /* fall through */
      case 148 : /* fall through */
      case 149 : /* fall through */
      case 150 : /* fall through */
      case 151 : /* fall through */
      case 152 : /* fall through */
      case 153 : /* fall through */
      case 154 : /* fall through */
      case 155 : /* fall through */
      case 156 : /* fall through */
      case 157 : /* fall through */
      case 158 : /* fall through */
      case 159 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_ADD3; goto extract_sfmt_add3;
      case 160 : /* fall through */
      case 162 : /* fall through */
      case 164 : /* fall through */
      case 166 : /* fall through */
      case 168 : /* fall through */
      case 170 : /* fall through */
      case 172 : /* fall through */
      case 174 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_BEQZ; goto extract_sfmt_beqz;
      case 161 : /* fall through */
      case 163 : /* fall through */
      case 165 : /* fall through */
      case 167 : /* fall through */
      case 169 : /* fall through */
      case 171 : /* fall through */
      case 173 : /* fall through */
      case 175 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_BNEZ; goto extract_sfmt_beqz;
      case 176 : /* fall through */
      case 178 : /* fall through */
      case 180 : /* fall through */
      case 182 : /* fall through */
      case 184 : /* fall through */
      case 186 : /* fall through */
      case 188 : /* fall through */
      case 190 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_BRA; goto extract_sfmt_bra;
      case 177 : /* fall through */
      case 179 : /* fall through */
      case 181 : /* fall through */
      case 183 : /* fall through */
      case 185 : /* fall through */
      case 187 : /* fall through */
      case 189 : /* fall through */
      case 191 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_BSR12; goto extract_sfmt_bsr12;
      case 192 : itype = MEP_INSN_ADD3X; goto extract_sfmt_add3x;
      case 193 :
        {
          unsigned int val = (((insn >> 4) & (3 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ff0000) == 0xc0010000)
              { itype = MEP_INSN_MOVI16; goto extract_sfmt_movi16; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            if ((entire_insn & 0xf0ff0000) == 0xc0110000)
              { itype = MEP_INSN_MOVU16; goto extract_sfmt_movu16; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 :
            if ((entire_insn & 0xf0ff0000) == 0xc0210000)
              { itype = MEP_INSN_MOVH; goto extract_sfmt_movu16; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 194 : itype = MEP_INSN_SLT3X; goto extract_sfmt_slt3x;
      case 195 : itype = MEP_INSN_SLTU3X; goto extract_sfmt_sltu3x;
      case 196 : itype = MEP_INSN_OR3; goto extract_sfmt_or3;
      case 197 : itype = MEP_INSN_AND3; goto extract_sfmt_or3;
      case 198 : itype = MEP_INSN_XOR3; goto extract_sfmt_or3;
      case 199 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_22; goto extract_sfmt_break;
      case 200 : itype = MEP_INSN_SB16; goto extract_sfmt_sb16;
      case 201 : itype = MEP_INSN_SH16; goto extract_sfmt_sh16;
      case 202 : itype = MEP_INSN_SW16; goto extract_sfmt_sw16;
      case 203 : itype = MEP_INSN_LBU16; goto extract_sfmt_lbu16;
      case 204 : itype = MEP_INSN_LB16; goto extract_sfmt_lb16;
      case 205 : itype = MEP_INSN_LH16; goto extract_sfmt_lh16;
      case 206 : itype = MEP_INSN_LW16; goto extract_sfmt_lw16;
      case 207 : itype = MEP_INSN_LHU16; goto extract_sfmt_lhu16;
      case 208 : /* fall through */
      case 209 : /* fall through */
      case 210 : /* fall through */
      case 211 : /* fall through */
      case 218 : /* fall through */
      case 220 : /* fall through */
      case 221 : /* fall through */
      case 222 : /* fall through */
      case 223 :
        if ((entire_insn & 0xf8000000) == 0xd0000000)
          { itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24; }
        itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      case 212 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8040000)
              { itype = MEP_INSN_BCPEQ; goto extract_sfmt_bcpeq; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 213 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8050000)
              { itype = MEP_INSN_BCPNE; goto extract_sfmt_bcpeq; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 214 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8060000)
              { itype = MEP_INSN_BCPAT; goto extract_sfmt_bcpeq; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 215 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 :
            if ((entire_insn & 0xff0f0000) == 0xd8070000)
              { itype = MEP_INSN_BCPAF; goto extract_sfmt_bcpeq; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 216 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 : itype = MEP_INSN_JMP24; goto extract_sfmt_jmp24;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 217 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 : itype = MEP_INSN_BSR24; goto extract_sfmt_bsr24;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 219 :
        {
          unsigned int val = (((insn >> 11) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_MOVU24; goto extract_sfmt_movu24;
          case 1 : itype = MEP_INSN_BSRV; goto extract_sfmt_bsr24;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 224 : itype = MEP_INSN_BEQI; goto extract_sfmt_beqi;
      case 225 : itype = MEP_INSN_BEQ; goto extract_sfmt_beq;
      case 226 : /* fall through */
      case 230 : /* fall through */
      case 234 : /* fall through */
      case 238 : itype = MEP_INSN_SW24; goto extract_sfmt_sw24;
      case 227 : /* fall through */
      case 231 : /* fall through */
      case 235 : /* fall through */
      case 239 : itype = MEP_INSN_LW24; goto extract_sfmt_lw24;
      case 228 : itype = MEP_INSN_BNEI; goto extract_sfmt_beqi;
      case 229 : itype = MEP_INSN_BNE; goto extract_sfmt_beq;
      case 232 : itype = MEP_INSN_BGEI; goto extract_sfmt_beqi;
      case 233 :
        {
          unsigned int val = (((insn >> 4) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ff0000) == 0xe0090000)
              { itype = MEP_INSN_REPEAT; goto extract_sfmt_repeat; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            if ((entire_insn & 0xffff0000) == 0xe0190000)
              { itype = MEP_INSN_EREPEAT; goto extract_sfmt_erepeat; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 236 : itype = MEP_INSN_BLTI; goto extract_sfmt_beqi;
      case 237 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_23; goto extract_sfmt_break;
      case 240 : itype = MEP_INSN_DSP; goto extract_sfmt_dsp;
      case 241 :
        {
          unsigned int val = (((entire_insn >> 8) & (3 << 4)) | ((entire_insn >> 0) & (15 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00fffff) == 0xf0010000)
              { itype = MEP_INSN_LDZ; goto extract_sfmt_ldz; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 :
            if ((entire_insn & 0xf00fffff) == 0xf0010002)
              { itype = MEP_INSN_AVE; goto extract_sfmt_abs; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 3 :
            if ((entire_insn & 0xf00fffff) == 0xf0010003)
              { itype = MEP_INSN_ABS; goto extract_sfmt_abs; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 4 :
            if ((entire_insn & 0xf00fffff) == 0xf0010004)
              { itype = MEP_INSN_MIN; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 5 :
            if ((entire_insn & 0xf00fffff) == 0xf0010005)
              { itype = MEP_INSN_MAX; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 6 :
            if ((entire_insn & 0xf00fffff) == 0xf0010006)
              { itype = MEP_INSN_MINU; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 7 :
            if ((entire_insn & 0xf00fffff) == 0xf0010007)
              { itype = MEP_INSN_MAXU; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 8 :
            if ((entire_insn & 0xf00fffff) == 0xf0010008)
              { itype = MEP_INSN_SADD; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 9 :
            if ((entire_insn & 0xf00fffff) == 0xf0010009)
              { itype = MEP_INSN_SADDU; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 10 :
            if ((entire_insn & 0xf00fffff) == 0xf001000a)
              { itype = MEP_INSN_SSUB; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 11 :
            if ((entire_insn & 0xf00fffff) == 0xf001000b)
              { itype = MEP_INSN_SSUBU; goto extract_sfmt_min; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 16 : /* fall through */
          case 24 :
            if ((entire_insn & 0xf0ffff07) == 0xf0011000)
              { itype = MEP_INSN_CLIP; goto extract_sfmt_clip; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 17 : /* fall through */
          case 25 :
            if ((entire_insn & 0xf0ffff07) == 0xf0011001)
              { itype = MEP_INSN_CLIPU; goto extract_sfmt_clip; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 32 :
            if ((entire_insn & 0xf00ff0ff) == 0xf0012000)
              { itype = MEP_INSN_CASB3; goto extract_sfmt_casb3; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 33 :
            if ((entire_insn & 0xf00ff0ff) == 0xf0012001)
              { itype = MEP_INSN_CASH3; goto extract_sfmt_casb3; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 34 :
            if ((entire_insn & 0xf00ff0ff) == 0xf0012002)
              { itype = MEP_INSN_CASW3; goto extract_sfmt_casb3; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 52 :
            if ((entire_insn & 0xf00fffff) == 0xf0013004)
              { itype = MEP_INSN_MADD; goto extract_sfmt_madd; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 53 :
            if ((entire_insn & 0xf00fffff) == 0xf0013005)
              { itype = MEP_INSN_MADDU; goto extract_sfmt_madd; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 54 :
            if ((entire_insn & 0xf00fffff) == 0xf0013006)
              { itype = MEP_INSN_MADDR; goto extract_sfmt_maddr; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 55 :
            if ((entire_insn & 0xf00fffff) == 0xf0013007)
              { itype = MEP_INSN_MADDRU; goto extract_sfmt_maddr; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 242 : itype = MEP_INSN_UCI; goto extract_sfmt_uci;
      case 243 : itype = MEP_INSN_PREFD; goto extract_sfmt_prefd;
      case 244 :
        {
          unsigned int val = (((insn >> 4) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf0ff0000) == 0xf0040000)
              { itype = MEP_INSN_STCB; goto extract_sfmt_stcb; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            if ((entire_insn & 0xf0ff0000) == 0xf0140000)
              { itype = MEP_INSN_LDCB; goto extract_sfmt_movu16; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 245 :
        {
          unsigned int val = (((entire_insn >> 10) & (63 << 0)));
          switch (val)
          {
          case 0 : itype = MEP_INSN_SBCPA; goto extract_sfmt_sbcpa;
          case 2 : itype = MEP_INSN_SBCPM0; goto extract_sfmt_sbcpm0;
          case 3 : itype = MEP_INSN_SBCPM1; goto extract_sfmt_sbcpm1;
          case 4 : itype = MEP_INSN_SHCPA; goto extract_sfmt_shcpa;
          case 6 : itype = MEP_INSN_SHCPM0; goto extract_sfmt_shcpm0;
          case 7 : itype = MEP_INSN_SHCPM1; goto extract_sfmt_shcpm1;
          case 8 : itype = MEP_INSN_SWCPA; goto extract_sfmt_swcpa;
          case 10 : itype = MEP_INSN_SWCPM0; goto extract_sfmt_swcpm0;
          case 11 : itype = MEP_INSN_SWCPM1; goto extract_sfmt_swcpm1;
          case 12 : itype = MEP_INSN_SMCPA; goto extract_sfmt_smcpa;
          case 14 : itype = MEP_INSN_SMCPM0; goto extract_sfmt_smcpm0;
          case 15 : itype = MEP_INSN_SMCPM1; goto extract_sfmt_smcpm1;
          case 16 : itype = MEP_INSN_LBCPA; goto extract_sfmt_lbucpa;
          case 18 : itype = MEP_INSN_LBCPM0; goto extract_sfmt_lbucpm0;
          case 19 : itype = MEP_INSN_LBCPM1; goto extract_sfmt_lbucpm1;
          case 20 : itype = MEP_INSN_LHCPA; goto extract_sfmt_lhucpa;
          case 22 : itype = MEP_INSN_LHCPM0; goto extract_sfmt_lhucpm0;
          case 23 : itype = MEP_INSN_LHCPM1; goto extract_sfmt_lhucpm1;
          case 24 : itype = MEP_INSN_LWCPA; goto extract_sfmt_lwcpa;
          case 26 : itype = MEP_INSN_LWCPM0; goto extract_sfmt_lwcpm0;
          case 27 : itype = MEP_INSN_LWCPM1; goto extract_sfmt_lwcpm1;
          case 28 : itype = MEP_INSN_LMCPA; goto extract_sfmt_lmcpa;
          case 30 : itype = MEP_INSN_LMCPM0; goto extract_sfmt_lmcpm0;
          case 31 : itype = MEP_INSN_LMCPM1; goto extract_sfmt_lmcpm1;
          case 48 : itype = MEP_INSN_LBUCPA; goto extract_sfmt_lbucpa;
          case 50 : itype = MEP_INSN_LBUCPM0; goto extract_sfmt_lbucpm0;
          case 51 : itype = MEP_INSN_LBUCPM1; goto extract_sfmt_lbucpm1;
          case 52 : itype = MEP_INSN_LHUCPA; goto extract_sfmt_lhucpa;
          case 54 : itype = MEP_INSN_LHUCPM0; goto extract_sfmt_lhucpm0;
          case 55 : itype = MEP_INSN_LHUCPM1; goto extract_sfmt_lhucpm1;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 246 :
        {
          unsigned int val = (((entire_insn >> 13) & (3 << 1)) | ((entire_insn >> 12) & (1 << 0)));
          switch (val)
          {
          case 0 :
            if ((entire_insn & 0xf00ff000) == 0xf0060000)
              { itype = MEP_INSN_SBCP; goto extract_sfmt_sbcp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 1 :
            if ((entire_insn & 0xf00ff000) == 0xf0061000)
              { itype = MEP_INSN_SHCP; goto extract_sfmt_shcp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 2 :
            if ((entire_insn & 0xf00ff000) == 0xf0064000)
              { itype = MEP_INSN_LBCP; goto extract_sfmt_lbcp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 3 :
            if ((entire_insn & 0xf00ff000) == 0xf0065000)
              { itype = MEP_INSN_LHCP; goto extract_sfmt_lhcp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 6 :
            if ((entire_insn & 0xf00ff000) == 0xf006c000)
              { itype = MEP_INSN_LBUCP; goto extract_sfmt_lbcp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          case 7 :
            if ((entire_insn & 0xf00ff000) == 0xf006d000)
              { itype = MEP_INSN_LHUCP; goto extract_sfmt_lhcp; }
            itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
          }
        }
      case 247 : itype = MEP_INSN_CP; goto extract_sfmt_cp;
      case 248 :
        entire_insn = entire_insn >> 16;
        itype = MEP_INSN_RI_26; goto extract_sfmt_break;
      case 252 : itype = MEP_INSN_SWCP16; goto extract_sfmt_swcp16;
      case 253 : itype = MEP_INSN_LWCP16; goto extract_sfmt_lwcp16;
      case 254 : itype = MEP_INSN_SMCP16; goto extract_sfmt_smcp16;
      case 255 : itype = MEP_INSN_LMCP16; goto extract_sfmt_lmcp16;
      default : itype = MEP_INSN_X_INVALID; goto extract_sfmt_empty;
      }
    }
  }

  /* The instruction has been decoded, now extract the fields.  */

 extract_sfmt_empty:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 0;
    return 0;
  }

 extract_sfmt_stcb_r:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ldcb_r:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_pref:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_imm;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.value = f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CIMM4;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_prefd:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op1.type = o_imm;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.value = f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CIMM4;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_casb3:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    UINT f_rl5;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_rl5 = EXTRACT_MSB0_UINT (insn, 32, 20, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rl5;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RL5;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sbcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_12s20;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_12s20 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_12s20;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CDISP12;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lbcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_12s20;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_12s20 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_12s20;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CDISP12;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_shcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_12s20;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_12s20 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_12s20;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CDISP12;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lhcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_12s20;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_12s20 = EXTRACT_MSB0_SINT (insn, 32, 20, 12);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_12s20;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CDISP12;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lbucpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lhucpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A2;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lbucpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lhucpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A2;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lbucpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lhucpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A2;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_uci:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_16u16;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_UIMM16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_dsp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_16u16;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_UIMM16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sb:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNC;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sh:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNS;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sw:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lb:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNC;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lh:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNS;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lw:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lbu:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNUC;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lhu:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNUS;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sw_sp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    SI f_7u9a4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a4;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A4;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lw_sp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    SI f_7u9a4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a4;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sb_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    UINT f_7u9;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9 = EXTRACT_MSB0_UINT (insn, 16, 9, 7);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3C;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sh_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    SI f_7u9a2;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a2 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 6)) << (1));

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3S;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a2;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A2;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sw_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    SI f_7u9a4;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3L;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a4;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A4;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lb_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    UINT f_7u9;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9 = EXTRACT_MSB0_UINT (insn, 16, 9, 7);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3C;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lh_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    SI f_7u9a2;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a2 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 6)) << (1));

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a2;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3S;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lw_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    SI f_7u9a4;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a4;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3L;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lbu_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    UINT f_7u9;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9 = EXTRACT_MSB0_UINT (insn, 16, 9, 7);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3UC;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lhu_tp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    SI f_7u9a2;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_7u9a2 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 6)) << (1));

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_7u9a2;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UDISP7A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3US;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sb16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNC;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sh16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNS;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sw16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lb16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNC;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lh16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNS;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lw16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lbu16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNUC;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lhu16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNUS;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sw24:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_24u8a4n_lo;
    UINT f_24u8a4n_hi;
    UINT f_24u8a4n;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_24u8a4n_lo = EXTRACT_MSB0_UINT (insn, 32, 8, 6);
    f_24u8a4n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u8a4n = ((((f_24u8a4n_hi) << (8))) | (((f_24u8a4n_lo) << (2))));

    /* Record the operands  */
    ida_insn.Op2.type = o_mem;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.addr = f_24u8a4n;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_ADDR24A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lw24:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_24u8a4n_lo;
    UINT f_24u8a4n_hi;
    UINT f_24u8a4n;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_24u8a4n_lo = EXTRACT_MSB0_UINT (insn, 32, 8, 6);
    f_24u8a4n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u8a4n = ((((f_24u8a4n_hi) << (8))) | (((f_24u8a4n_lo) << (2))));

    /* Record the operands  */
    ida_insn.Op2.type = o_mem;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.addr = f_24u8a4n;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_ADDR24A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RNL;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_extb:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ssarb:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_2u6;
    UINT f_rm;

    f_2u6 = EXTRACT_MSB0_UINT (insn, 16, 6, 2);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_imm;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.value = f_2u6;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_UDISP2;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_mov:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_movi8:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    INT f_8s8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_8s8 = EXTRACT_MSB0_SINT (insn, 16, 8, 8);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_8s8;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SIMM8;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_movi16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SIMM16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    refinfo_t ri;
    if (get_refinfo(&ri, ida_insn.ea, 1))
    {
      ida_insn.Op2.type = o_mem;
      ida_insn.Op2.addr = calc_reference_target(ida_insn.ea, ri, f_16s16);
    }

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_movu24:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn3;
    UINT f_24u8n_lo;
    UINT f_24u8n_hi;
    UINT f_24u8n;

    f_rn3 = EXTRACT_MSB0_UINT (insn, 32, 5, 3);
    f_24u8n_lo = EXTRACT_MSB0_UINT (insn, 32, 8, 8);
    f_24u8n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u8n = ((((f_24u8n_hi) << (8))) | (f_24u8n_lo));

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_24u8n;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM24;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn3;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN3;

    refinfo_t ri;
    if (get_refinfo(&ri, ida_insn.ea, 1))
    {
      ida_insn.Op2.type = o_mem;
      ida_insn.Op2.addr = calc_reference_target(ida_insn.ea, ri, f_24u8n);
    }

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_movu16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16u16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    refinfo_t ri;
    if (get_refinfo(&ri, ida_insn.ea, 1))
    {
      ida_insn.Op2.type = o_mem;
      ida_insn.Op2.addr = calc_reference_target(ida_insn.ea, ri, f_16u16);
    }

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_add3:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    UINT f_rl;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_rl = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rl;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RL;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_add:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    INT f_6s8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_6s8 = EXTRACT_MSB0_SINT (insn, 16, 8, 6);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_6s8;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SIMM6;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_add3i:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    SI f_7u9a4;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_7u9a4 = ((EXTRACT_MSB0_UINT (insn, 16, 9, 5)) << (2));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_7u9a4;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_UIMM7A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_advck3:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sub:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_slt3i:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_5u8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_5u8 = EXTRACT_MSB0_UINT (insn, 16, 8, 5);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_5u8;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM5;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sl1ad3:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_add3x:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_16s16;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_SIMM16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    refinfo_t ri;
    if (get_refinfo(&ri, ida_insn.ea, 2))
    {
      ida_insn.Op3.type = o_mem;
      ida_insn.Op3.addr = calc_reference_target(ida_insn.ea, ri, f_16s16);
    }

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_slt3x:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    INT f_16s16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_16s16;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_SIMM16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sltu3x:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_16u16;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_UIMM16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_or3:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_16u16;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_UIMM16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    refinfo_t ri;
    if (get_refinfo(&ri, ida_insn.ea, 2))
    {
      ida_insn.Op3.type = o_mem;
      ida_insn.Op3.addr = calc_reference_target(ida_insn.ea, ri, f_16u16);
    }

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_srai:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_5u8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_5u8 = EXTRACT_MSB0_UINT (insn, 16, 8, 5);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_5u8;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM5;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sll3:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_5u8;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_5u8 = EXTRACT_MSB0_UINT (insn, 16, 8, 5);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_5u8;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM5;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_fsft:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_bra:
  {
    CGEN_INSN_WORD insn = entire_insn;
    SI f_12s4a2;

    f_12s4a2 = ((((EXTRACT_MSB0_SINT (insn, 16, 4, 11)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op1.type = o_near;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.addr = f_12s4a2;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_PCREL12A2;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_beqz:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    SI f_8s8a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_8s8a2 = ((((EXTRACT_MSB0_SINT (insn, 16, 8, 7)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op2.type = o_near;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.addr = f_8s8a2;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_PCREL8A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_beqi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_4u8;
    SI f_17s16a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_4u8 = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op3.type = o_near;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.addr = f_17s16a2;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_PCREL17A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_4u8;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM4;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_beq:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;
    SI f_17s16a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op3.type = o_near;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.addr = f_17s16a2;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_PCREL17A2;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_bsr12:
  {
    CGEN_INSN_WORD insn = entire_insn;
    SI f_12s4a2;

    f_12s4a2 = ((((EXTRACT_MSB0_SINT (insn, 16, 4, 11)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op1.type = o_near;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.addr = f_12s4a2;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_PCREL12A2;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_bsr24:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_24s5a2n_lo;
    INT f_24s5a2n_hi;
    INT f_24s5a2n;

    f_24s5a2n_lo = EXTRACT_MSB0_UINT (insn, 32, 5, 7);
    f_24s5a2n_hi = EXTRACT_MSB0_SINT (insn, 32, 16, 16);
  f_24s5a2n = ((((((f_24s5a2n_hi) << (8))) | (((f_24s5a2n_lo) << (1))))) + (pc));

    /* Record the operands  */
    ida_insn.Op1.type = o_near;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.addr = f_24s5a2n;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_PCREL24A2;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_jmp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rm;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RM;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_jmp24:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_24u5a2n_lo;
    UINT f_24u5a2n_hi;
    UINT f_24u5a2n;

    f_24u5a2n_lo = EXTRACT_MSB0_UINT (insn, 32, 5, 7);
    f_24u5a2n_hi = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u5a2n = ((((f_24u5a2n_hi) << (8))) | (((f_24u5a2n_lo) << (1))));

    /* Record the operands  */
    ida_insn.Op1.type = o_mem;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.addr = f_24u5a2n;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_PCABS24A2;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_jsr:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rm;

    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RM;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ret:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_repeat:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    SI f_17s16a2;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op2.type = o_near;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.addr = f_17s16a2;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_PCREL17A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_erepeat:
  {
    CGEN_INSN_WORD insn = entire_insn;
    SI f_17s16a2;

    f_17s16a2 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op1.type = o_near;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.addr = f_17s16a2;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_PCREL17A2;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_stc_lp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_stc_hi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_stc_lo:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_stc:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_csrn_lo;
    UINT f_csrn_hi;
    UINT f_csrn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_csrn_lo = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_csrn_hi = EXTRACT_MSB0_UINT (insn, 16, 15, 1);
  f_csrn = ((((f_csrn_hi) << (4))) | (f_csrn_lo));

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_CSR_BASE + f_csrn;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CSRN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ldc_lp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ldc_hi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ldc_lo:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ldc:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_csrn_lo;
    UINT f_csrn_hi;
    UINT f_csrn;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_csrn_lo = EXTRACT_MSB0_UINT (insn, 16, 8, 4);
    f_csrn_hi = EXTRACT_MSB0_UINT (insn, 16, 15, 1);
  f_csrn = ((((f_csrn_hi) << (4))) | (f_csrn_lo));

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_CSR_BASE + f_csrn;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CSRN;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_di:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_reti:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_halt:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_sleep:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_swi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_2u10;

    f_2u10 = EXTRACT_MSB0_UINT (insn, 16, 10, 2);

    /* Record the operands  */
    ida_insn.Op1.type = o_imm;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.value = f_2u10;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_UIMM2;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_break:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_stcb:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_16u16;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_16u16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16u16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM16;

    refinfo_t ri;
    if (get_refinfo(&ri, ida_insn.ea, 1))
    {
      ida_insn.Op2.type = o_mem;
      ida_insn.Op2.addr = calc_reference_target(ida_insn.ea, ri, f_16u16);
    }

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_bsetm:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_3u5;
    UINT f_rm;

    f_3u5 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_3u5;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM3;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_btstm:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_3u5;
    UINT f_rm;

    f_3u5 = EXTRACT_MSB0_UINT (insn, 16, 5, 3);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_3u5;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_UIMM3;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_tas:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_mul:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_mulr:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_madd:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_maddr:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_div:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_dret:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_dbreak:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_ldz:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_abs:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_min:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_rm;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RM;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_clip:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rn;
    UINT f_5u24;

    f_rn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_5u24 = EXTRACT_MSB0_UINT (insn, 32, 24, 5);

    /* Record the operands  */
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_5u24;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_CIMM5;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_GPR_BASE + f_rn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_RN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_swcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lwcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_smcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lmcp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_swcpi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lwcpi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_smcpi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_lmcpi:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;

    f_crn = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 16, 8, 4);

    /* Record the operands  */
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_swcp16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lwcp16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_smcp16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lmcp16:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    INT f_16s16;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_16s16 = EXTRACT_MSB0_SINT (insn, 32, 16, 16);

    /* Record the operands  */
    ida_insn.Op3.type = o_reg;
    ida_insn.Op3.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op2.type = o_imm;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.value = f_16s16;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_SDISP16;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sbcpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_shcpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_swcpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lwcpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A4;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_smcpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A8;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lmcpa:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A8;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sbcpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_shcpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_swcpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lwcpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A4;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_smcpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A8;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lmcpm0:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A8;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sbcpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_shcpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A2;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_swcpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A4;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lwcpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A4;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_smcpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A8;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_lmcpm1:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_crn;
    UINT f_rm;
    SI f_cdisp10;

    f_crn = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_cdisp10 = (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (512))) ? (((((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023))) - (1024))) : (((((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) & (512))) ? ((((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10))) - (1024))) : ((((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) & (128))) ? (((EXTRACT_MSB0_SINT (insn, 32, 22, 10)) ^ (768))) : (EXTRACT_MSB0_SINT (insn, 32, 22, 10)))) & (1023)));

    /* Record the operands  */
    ida_insn.Op3.type = o_imm;
    ida_insn.Op3.dtype = get_dtype_by_size(4);
    ida_insn.Op3.value = f_cdisp10;
    ida_insn.Op3.cgen_optype = MEP_OPERAND_CDISP10A8;
    ida_insn.Op2.type = o_reg;
    ida_insn.Op2.reg = REGS_HW_H_GPR_BASE + f_rm;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_RMA;
    ida_insn.Op1.type = o_reg;
    ida_insn.Op1.reg = REGS_HW_H_CR64_BASE + f_crn;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CRN64;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_bcpeq:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_rm;
    SI f_17s16a2;

    f_rm = EXTRACT_MSB0_UINT (insn, 32, 8, 4);
    f_17s16a2 = ((((EXTRACT_MSB0_SINT (insn, 32, 16, 16)) << (1))) + (pc));

    /* Record the operands  */
    ida_insn.Op1.type = o_imm;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.value = f_rm;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CCCC;
    ida_insn.Op2.type = o_near;
    ida_insn.Op2.dtype = get_dtype_by_size(4);
    ida_insn.Op2.addr = f_17s16a2;
    ida_insn.Op2.cgen_optype = MEP_OPERAND_PCREL17A2;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_synccp:
  {


    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

 extract_sfmt_cp:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_24u4n_hi;
    UINT f_24u4n_lo;
    UINT f_24u4n;

    f_24u4n_hi = EXTRACT_MSB0_UINT (insn, 32, 4, 8);
    f_24u4n_lo = EXTRACT_MSB0_UINT (insn, 32, 16, 16);
  f_24u4n = ((((f_24u4n_hi) << (16))) | (f_24u4n_lo));

    /* Record the operands  */
    ida_insn.Op1.type = o_imm;
    ida_insn.Op1.dtype = get_dtype_by_size(4);
    ida_insn.Op1.value = f_24u4n;
    ida_insn.Op1.cgen_optype = MEP_OPERAND_CODE24;

    ida_insn.itype = itype;
    ida_insn.size = 4;
    return 4;
  }

 extract_sfmt_sim_syscall:
  {
    CGEN_INSN_WORD insn = entire_insn;
    UINT f_5;
    UINT f_6;
    UINT f_7;
    UINT f_11;
    UINT f_callnum;

    f_5 = EXTRACT_MSB0_UINT (insn, 16, 5, 1);
    f_6 = EXTRACT_MSB0_UINT (insn, 16, 6, 1);
    f_7 = EXTRACT_MSB0_UINT (insn, 16, 7, 1);
    f_11 = EXTRACT_MSB0_UINT (insn, 16, 11, 1);
  f_callnum = ((((f_5) << (3))) | (((((f_6) << (2))) | (((((f_7) << (1))) | (f_11))))));

    /* Record the operands  */

    ida_insn.itype = itype;
    ida_insn.size = 2;
    return 2;
  }

}
