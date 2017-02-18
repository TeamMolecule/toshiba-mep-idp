/* MEP IDP instructions

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

instruc_t Instructions[] = {
  { "", 0 }, // unknown
  { "--invalid--",    0 }, //--invalid--
  { "stcb",    CF_USE1|CF_USE2 }, //stcb $rn,($rma)
  { "ldcb",    CF_USE2|CF_CHG1 }, //ldcb $rn,($rma)
  { "pref",    CF_USE1|CF_USE2 }, //pref $cimm4,($rma)
  { "pref",    CF_USE1|CF_USE3|CF_USE2 }, //pref $cimm4,$sdisp16($rma)
  { "casb3",    CF_USE2|CF_USE3|CF_USE1|CF_CHG1 }, //casb3 $rl5,$rn,($rm)
  { "cash3",    CF_USE2|CF_USE3|CF_USE1|CF_CHG1 }, //cash3 $rl5,$rn,($rm)
  { "casw3",    CF_USE2|CF_USE3|CF_USE1|CF_CHG1 }, //casw3 $rl5,$rn,($rm)
  { "sbcp",    CF_USE1|CF_USE3|CF_USE2 }, //sbcp $crn,$cdisp12($rma)
  { "lbcp",    CF_USE3|CF_USE2|CF_CHG1 }, //lbcp $crn,$cdisp12($rma)
  { "lbucp",    CF_USE3|CF_USE2|CF_CHG1 }, //lbucp $crn,$cdisp12($rma)
  { "shcp",    CF_USE1|CF_USE3|CF_USE2 }, //shcp $crn,$cdisp12($rma)
  { "lhcp",    CF_USE3|CF_USE2|CF_CHG1 }, //lhcp $crn,$cdisp12($rma)
  { "lhucp",    CF_USE3|CF_USE2|CF_CHG1 }, //lhucp $crn,$cdisp12($rma)
  { "lbucpa",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lbucpa $crn,($rma+),$cdisp10
  { "lhucpa",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lhucpa $crn,($rma+),$cdisp10a2
  { "lbucpm0",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lbucpm0 $crn,($rma+),$cdisp10
  { "lhucpm0",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lhucpm0 $crn,($rma+),$cdisp10a2
  { "lbucpm1",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lbucpm1 $crn,($rma+),$cdisp10
  { "lhucpm1",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lhucpm1 $crn,($rma+),$cdisp10a2
  { "uci",    CF_USE1|CF_USE2|CF_CHG1 }, //uci $rn,$rm,$uimm16
  { "dsp",    CF_USE1|CF_USE2|CF_USE3|CF_CHG1 }, //dsp $rn,$rm,$uimm16
  { "dsp0",    CF_USE1 }, //dsp0 $c5rnmuimm24
  { "dsp1",    CF_USE1|CF_USE2|CF_CHG1 }, //dsp1 $rn,$c5rmuimm20
  { "sb",    CF_USE1|CF_USE2 }, //sb $rnc,($rma)
  { "sh",    CF_USE1|CF_USE2 }, //sh $rns,($rma)
  { "sw",    CF_USE1|CF_USE2 }, //sw $rnl,($rma)
  { "lb",    CF_USE2|CF_CHG1 }, //lb $rnc,($rma)
  { "lh",    CF_USE2|CF_CHG1 }, //lh $rns,($rma)
  { "lw",    CF_USE2|CF_CHG1 }, //lw $rnl,($rma)
  { "lbu",    CF_USE2|CF_CHG1 }, //lbu $rnuc,($rma)
  { "lhu",    CF_USE2|CF_CHG1 }, //lhu $rnus,($rma)
  { "sw",    CF_USE1|CF_USE2 }, //sw $rnl,$udisp7a4($spr)
  { "lw",    CF_USE2|CF_CHG1 }, //lw $rnl,$udisp7a4($spr)
  { "sb",    CF_USE1|CF_USE2 }, //sb $rn3c,$udisp7($tpr)
  { "sh",    CF_USE1|CF_USE2 }, //sh $rn3s,$udisp7a2($tpr)
  { "sw",    CF_USE1|CF_USE2 }, //sw $rn3l,$udisp7a4($tpr)
  { "lb",    CF_USE2|CF_CHG1 }, //lb $rn3c,$udisp7($tpr)
  { "lh",    CF_USE2|CF_CHG1 }, //lh $rn3s,$udisp7a2($tpr)
  { "lw",    CF_USE2|CF_CHG1 }, //lw $rn3l,$udisp7a4($tpr)
  { "lbu",    CF_USE2|CF_CHG1 }, //lbu $rn3uc,$udisp7($tpr)
  { "lhu",    CF_USE2|CF_CHG1 }, //lhu $rn3us,$udisp7a2($tpr)
  { "sb",    CF_USE1|CF_USE3|CF_USE2 }, //sb $rnc,$sdisp16($rma)
  { "sh",    CF_USE1|CF_USE3|CF_USE2 }, //sh $rns,$sdisp16($rma)
  { "sw",    CF_USE1|CF_USE3|CF_USE2 }, //sw $rnl,$sdisp16($rma)
  { "lb",    CF_USE3|CF_USE2|CF_CHG1 }, //lb $rnc,$sdisp16($rma)
  { "lh",    CF_USE3|CF_USE2|CF_CHG1 }, //lh $rns,$sdisp16($rma)
  { "lw",    CF_USE3|CF_USE2|CF_CHG1 }, //lw $rnl,$sdisp16($rma)
  { "lbu",    CF_USE3|CF_USE2|CF_CHG1 }, //lbu $rnuc,$sdisp16($rma)
  { "lhu",    CF_USE3|CF_USE2|CF_CHG1 }, //lhu $rnus,$sdisp16($rma)
  { "sw",    CF_USE1|CF_USE2 }, //sw $rnl,($addr24a4)
  { "lw",    CF_USE2|CF_CHG1 }, //lw $rnl,($addr24a4)
  { "extb",    CF_USE1|CF_CHG1 }, //extb $rn
  { "exth",    CF_USE1|CF_CHG1 }, //exth $rn
  { "extub",    CF_USE1|CF_CHG1 }, //extub $rn
  { "extuh",    CF_USE1|CF_CHG1 }, //extuh $rn
  { "ssarb",    CF_USE1|CF_USE2 }, //ssarb $udisp2($rm)
  { "mov",    CF_USE2|CF_CHG1 }, //mov $rn,$rm
  { "mov",    CF_USE2|CF_CHG1 }, //mov $rn,$simm8
  { "mov",    CF_USE2|CF_CHG1 }, //mov $rn,$simm16
  { "movu",    CF_USE2|CF_CHG1 }, //movu $rn3,$uimm24
  { "movu",    CF_USE2|CF_CHG1 }, //movu $rn,$uimm16
  { "movh",    CF_USE2|CF_CHG1 }, //movh $rn,$uimm16
  { "add3",    CF_USE2|CF_USE3|CF_CHG1 }, //add3 $rl,$rn,$rm
  { "add",    CF_USE1|CF_USE2|CF_CHG1 }, //add $rn,$simm6
  { "add3",    CF_USE3|CF_CHG1 }, //add3 $rn,$spr,$uimm7a4
  { "advck3",    CF_USE1|CF_USE2 }, //advck3 \$0,$rn,$rm
  { "sub",    CF_USE1|CF_USE2|CF_CHG1 }, //sub $rn,$rm
  { "sbvck3",    CF_USE1|CF_USE2 }, //sbvck3 \$0,$rn,$rm
  { "neg",    CF_USE2|CF_CHG1 }, //neg $rn,$rm
  { "slt3",    CF_USE1|CF_USE2 }, //slt3 \$0,$rn,$rm
  { "sltu3",    CF_USE1|CF_USE2 }, //sltu3 \$0,$rn,$rm
  { "slt3",    CF_USE1|CF_USE2 }, //slt3 \$0,$rn,$uimm5
  { "sltu3",    CF_USE1|CF_USE2 }, //sltu3 \$0,$rn,$uimm5
  { "sl1ad3",    CF_USE1|CF_USE2 }, //sl1ad3 \$0,$rn,$rm
  { "sl2ad3",    CF_USE1|CF_USE2 }, //sl2ad3 \$0,$rn,$rm
  { "add3",    CF_USE2|CF_USE3|CF_CHG1 }, //add3 $rn,$rm,$simm16
  { "slt3",    CF_USE2|CF_USE3|CF_CHG1 }, //slt3 $rn,$rm,$simm16
  { "sltu3",    CF_USE2|CF_USE3|CF_CHG1 }, //sltu3 $rn,$rm,$uimm16
  { "or",    CF_USE1|CF_USE2|CF_CHG1 }, //or $rn,$rm
  { "and",    CF_USE1|CF_USE2|CF_CHG1 }, //and $rn,$rm
  { "xor",    CF_USE1|CF_USE2|CF_CHG1 }, //xor $rn,$rm
  { "nor",    CF_USE1|CF_USE2|CF_CHG1 }, //nor $rn,$rm
  { "or3",    CF_USE2|CF_USE3|CF_CHG1 }, //or3 $rn,$rm,$uimm16
  { "and3",    CF_USE2|CF_USE3|CF_CHG1 }, //and3 $rn,$rm,$uimm16
  { "xor3",    CF_USE2|CF_USE3|CF_CHG1 }, //xor3 $rn,$rm,$uimm16
  { "sra",    CF_USE1|CF_USE2|CF_CHG1 }, //sra $rn,$rm
  { "srl",    CF_USE1|CF_USE2|CF_CHG1 }, //srl $rn,$rm
  { "sll",    CF_USE1|CF_USE2|CF_CHG1 }, //sll $rn,$rm
  { "sra",    CF_USE1|CF_USE2|CF_CHG1 }, //sra $rn,$uimm5
  { "srl",    CF_USE1|CF_USE2|CF_CHG1 }, //srl $rn,$uimm5
  { "sll",    CF_USE1|CF_USE2|CF_CHG1 }, //sll $rn,$uimm5
  { "sll3",    CF_USE1|CF_USE2 }, //sll3 \$0,$rn,$uimm5
  { "fsft",    CF_USE1|CF_USE2|CF_CHG1 }, //fsft $rn,$rm
  { "bra",    CF_USE1|CF_STOP }, //bra $pcrel12a2
  { "beqz",    CF_USE1|CF_USE2 }, //beqz $rn,$pcrel8a2
  { "bnez",    CF_USE1|CF_USE2 }, //bnez $rn,$pcrel8a2
  { "beqi",    CF_USE1|CF_USE2|CF_USE3 }, //beqi $rn,$uimm4,$pcrel17a2
  { "bnei",    CF_USE1|CF_USE2|CF_USE3 }, //bnei $rn,$uimm4,$pcrel17a2
  { "blti",    CF_USE1|CF_USE2|CF_USE3 }, //blti $rn,$uimm4,$pcrel17a2
  { "bgei",    CF_USE1|CF_USE2|CF_USE3 }, //bgei $rn,$uimm4,$pcrel17a2
  { "beq",    CF_USE1|CF_USE2|CF_USE3 }, //beq $rn,$rm,$pcrel17a2
  { "bne",    CF_USE1|CF_USE2|CF_USE3 }, //bne $rn,$rm,$pcrel17a2
  { "bsr",    CF_CALL|CF_USE1 }, //bsr $pcrel12a2
  { "bsr",    CF_CALL|CF_USE1 }, //bsr $pcrel24a2
  { "jmp",    CF_CALL|CF_STOP|CF_USE1 }, //jmp $rm
  { "jmp",    CF_CALL|CF_STOP|CF_USE1 }, //jmp $pcabs24a2
  { "jsr",    CF_CALL|CF_USE1 }, //jsr $rm
  { "ret",    CF_STOP }, //ret
  { "repeat",    CF_USE1|CF_USE2 }, //repeat $rn,$pcrel17a2
  { "erepeat",    CF_USE1 }, //erepeat $pcrel17a2
  { "stc",    CF_USE1 }, //stc $rn,\$lp
  { "stc",    CF_USE1 }, //stc $rn,\$hi
  { "stc",    CF_USE1 }, //stc $rn,\$lo
  { "stc",    CF_USE1|CF_CHG2 }, //stc $rn,$csrn
  { "ldc",    CF_CHG1 }, //ldc $rn,\$lp
  { "ldc",    CF_CHG1 }, //ldc $rn,\$hi
  { "ldc",    CF_CHG1 }, //ldc $rn,\$lo
  { "ldc",    CF_USE2|CF_CHG1 }, //ldc $rn,$csrn
  { "di",    0 }, //di
  { "ei",    0 }, //ei
  { "reti",    CF_STOP }, //reti
  { "halt",    0 }, //halt
  { "sleep",    0 }, //sleep
  { "swi",    CF_USE1 }, //swi $uimm2
  { "break",    0 }, //break
  { "syncm",    0 }, //syncm
  { "stcb",    CF_USE1|CF_USE2 }, //stcb $rn,$uimm16
  { "ldcb",    CF_USE2|CF_CHG1 }, //ldcb $rn,$uimm16
  { "bsetm",    CF_USE2|CF_USE1 }, //bsetm ($rma),$uimm3
  { "bclrm",    CF_USE2|CF_USE1 }, //bclrm ($rma),$uimm3
  { "bnotm",    CF_USE2|CF_USE1 }, //bnotm ($rma),$uimm3
  { "btstm",    CF_USE2|CF_USE1 }, //btstm \$0,($rma),$uimm3
  { "tas",    CF_USE2|CF_CHG1 }, //tas $rn,($rma)
  { "cache",    CF_USE1|CF_USE2 }, //cache $cimm4,($rma)
  { "mul",    CF_USE1|CF_USE2 }, //mul $rn,$rm
  { "mulu",    CF_USE1|CF_USE2 }, //mulu $rn,$rm
  { "mulr",    CF_USE1|CF_USE2|CF_CHG1 }, //mulr $rn,$rm
  { "mulru",    CF_USE1|CF_USE2|CF_CHG1 }, //mulru $rn,$rm
  { "madd",    CF_USE1|CF_USE2 }, //madd $rn,$rm
  { "maddu",    CF_USE1|CF_USE2 }, //maddu $rn,$rm
  { "maddr",    CF_USE1|CF_USE2|CF_CHG1 }, //maddr $rn,$rm
  { "maddru",    CF_USE1|CF_USE2|CF_CHG1 }, //maddru $rn,$rm
  { "div",    CF_USE1|CF_USE2 }, //div $rn,$rm
  { "divu",    CF_USE1|CF_USE2 }, //divu $rn,$rm
  { "dret",    CF_STOP }, //dret
  { "dbreak",    0 }, //dbreak
  { "ldz",    CF_USE2|CF_CHG1 }, //ldz $rn,$rm
  { "abs",    CF_USE1|CF_USE2|CF_CHG1 }, //abs $rn,$rm
  { "ave",    CF_USE1|CF_USE2|CF_CHG1 }, //ave $rn,$rm
  { "min",    CF_USE1|CF_USE2|CF_CHG1 }, //min $rn,$rm
  { "max",    CF_USE1|CF_USE2|CF_CHG1 }, //max $rn,$rm
  { "minu",    CF_USE1|CF_USE2|CF_CHG1 }, //minu $rn,$rm
  { "maxu",    CF_USE1|CF_USE2|CF_CHG1 }, //maxu $rn,$rm
  { "clip",    CF_USE1|CF_USE2|CF_CHG1 }, //clip $rn,$cimm5
  { "clipu",    CF_USE1|CF_USE2|CF_CHG1 }, //clipu $rn,$cimm5
  { "sadd",    CF_USE1|CF_USE2|CF_CHG1 }, //sadd $rn,$rm
  { "ssub",    CF_USE1|CF_USE2|CF_CHG1 }, //ssub $rn,$rm
  { "saddu",    CF_USE1|CF_USE2|CF_CHG1 }, //saddu $rn,$rm
  { "ssubu",    CF_USE1|CF_USE2|CF_CHG1 }, //ssubu $rn,$rm
  { "swcp",    CF_USE1|CF_USE2 }, //swcp $crn,($rma)
  { "lwcp",    CF_USE2|CF_CHG1 }, //lwcp $crn,($rma)
  { "smcp",    CF_USE1|CF_USE2 }, //smcp $crn64,($rma)
  { "lmcp",    CF_USE2|CF_CHG1 }, //lmcp $crn64,($rma)
  { "swcpi",    CF_USE1|CF_USE2|CF_CHG2 }, //swcpi $crn,($rma+)
  { "lwcpi",    CF_USE2|CF_CHG1|CF_CHG2 }, //lwcpi $crn,($rma+)
  { "smcpi",    CF_USE1|CF_USE2|CF_CHG2 }, //smcpi $crn64,($rma+)
  { "lmcpi",    CF_USE2|CF_CHG1|CF_CHG2 }, //lmcpi $crn64,($rma+)
  { "swcp",    CF_USE1|CF_USE3|CF_USE2 }, //swcp $crn,$sdisp16($rma)
  { "lwcp",    CF_USE3|CF_USE2|CF_CHG1 }, //lwcp $crn,$sdisp16($rma)
  { "smcp",    CF_USE1|CF_USE3|CF_USE2 }, //smcp $crn64,$sdisp16($rma)
  { "lmcp",    CF_USE3|CF_USE2|CF_CHG1 }, //lmcp $crn64,$sdisp16($rma)
  { "sbcpa",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //sbcpa $crn,($rma+),$cdisp10
  { "lbcpa",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lbcpa $crn,($rma+),$cdisp10
  { "shcpa",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //shcpa $crn,($rma+),$cdisp10a2
  { "lhcpa",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lhcpa $crn,($rma+),$cdisp10a2
  { "swcpa",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //swcpa $crn,($rma+),$cdisp10a4
  { "lwcpa",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lwcpa $crn,($rma+),$cdisp10a4
  { "smcpa",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //smcpa $crn64,($rma+),$cdisp10a8
  { "lmcpa",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lmcpa $crn64,($rma+),$cdisp10a8
  { "sbcpm0",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //sbcpm0 $crn,($rma+),$cdisp10
  { "lbcpm0",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lbcpm0 $crn,($rma+),$cdisp10
  { "shcpm0",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //shcpm0 $crn,($rma+),$cdisp10a2
  { "lhcpm0",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lhcpm0 $crn,($rma+),$cdisp10a2
  { "swcpm0",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //swcpm0 $crn,($rma+),$cdisp10a4
  { "lwcpm0",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lwcpm0 $crn,($rma+),$cdisp10a4
  { "smcpm0",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //smcpm0 $crn64,($rma+),$cdisp10a8
  { "lmcpm0",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lmcpm0 $crn64,($rma+),$cdisp10a8
  { "sbcpm1",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //sbcpm1 $crn,($rma+),$cdisp10
  { "lbcpm1",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lbcpm1 $crn,($rma+),$cdisp10
  { "shcpm1",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //shcpm1 $crn,($rma+),$cdisp10a2
  { "lhcpm1",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lhcpm1 $crn,($rma+),$cdisp10a2
  { "swcpm1",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //swcpm1 $crn,($rma+),$cdisp10a4
  { "lwcpm1",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lwcpm1 $crn,($rma+),$cdisp10a4
  { "smcpm1",    CF_USE1|CF_USE2|CF_USE3|CF_CHG2 }, //smcpm1 $crn64,($rma+),$cdisp10a8
  { "lmcpm1",    CF_USE2|CF_USE3|CF_CHG1|CF_CHG2 }, //lmcpm1 $crn64,($rma+),$cdisp10a8
  { "bcpeq",    CF_USE1|CF_USE2 }, //bcpeq $cccc,$pcrel17a2
  { "bcpne",    CF_USE1|CF_USE2 }, //bcpne $cccc,$pcrel17a2
  { "bcpat",    CF_USE1|CF_USE2 }, //bcpat $cccc,$pcrel17a2
  { "bcpaf",    CF_USE1|CF_USE2 }, //bcpaf $cccc,$pcrel17a2
  { "synccp",    0 }, //synccp
  { "jsrv",    CF_CALL|CF_USE1 }, //jsrv $rm
  { "bsrv",    CF_CALL|CF_USE1 }, //bsrv $pcrel24a2
  { "cp",    CF_USE1 }, //cp $code24
  { "--syscall--",     }, //--syscall--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
  { "--reserved--",    0 }, //--reserved--
};
