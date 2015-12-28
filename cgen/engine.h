/* Engine header for Cpu tools GENerated simulators.
   Copyright (C) 1998-2015 Free Software Foundation, Inc.
   Contributed by Cygnus Support.

This file is part of GDB, the GNU debugger.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* This file is included by ${cpu}.h.
   It needs CGEN_INSN_WORD which is defined by ${cpu}.h.
   ??? A lot of this could be moved to genmloop.sh to be put in eng.h
   and thus remove some conditional compilation.  We'd still need
   CGEN_INSN_WORD though.  */

/* Semantic functions come in six versions on two axes:
   fast/full-featured, and using one of the simple/scache/compilation engines.
   A full featured simulator is always provided.  --enable-sim-fast includes
   support for fast execution by duplicating the semantic code but leaving
   out all features like tracing and profiling.
   Using the scache is selected with --enable-sim-scache.  */
/* FIXME: --enable-sim-fast not implemented yet.  */
/* FIXME: undecided how to handle WITH_SCACHE_PBB.  */

/* There are several styles of engines, all generally supported by the
   same code:

   WITH_SCACHE && WITH_SCACHE_PBB - pseudo-basic-block scaching
   WITH_SCACHE && !WITH_SCACHE_PBB - scaching on an insn by insn basis
   !WITH_SCACHE - simple engine: fetch an insn, execute an insn

   The !WITH_SCACHE case can also be broken up into two flavours:
   extract the fields of the insn into an ARGBUF struct, or defer the
   extraction to the semantic handler.  The former can be viewed as the
   WITH_SCACHE case with a cache size of 1 (thus there's no need for a
   WITH_EXTRACTION macro).  The WITH_SCACHE case always extracts the fields
   into an ARGBUF struct.  */

#ifndef CGEN_ENGINE_H
#define CGEN_ENGINE_H

/* Instruction field support macros.  */

#define EXTRACT_MSB0_SINT(val, total, start, length) \
(((INT) (val) << ((sizeof (INT) * 8) - (total) + (start))) \
 >> ((sizeof (INT) * 8) - (length)))
#define EXTRACT_MSB0_UINT(val, total, start, length) \
(((UINT) (val) << ((sizeof (UINT) * 8) - (total) + (start))) \
 >> ((sizeof (UINT) * 8) - (length)))

#define EXTRACT_LSB0_SINT(val, total, start, length) \
(((INT) (val) << ((sizeof (INT) * 8) - (start) - 1)) \
 >> ((sizeof (INT) * 8) - (length)))
#define EXTRACT_LSB0_UINT(val, total, start, length) \
(((UINT) (val) << ((sizeof (UINT) * 8) - (start) - 1)) \
 >> ((sizeof (UINT) * 8) - (length)))

#define EXTRACT_MSB0_LGSINT(val, total, start, length) \
(((CGEN_INSN_LGSINT) (val) << ((sizeof (CGEN_INSN_LGSINT) * 8) - (total) + (start))) \
 >> ((sizeof (CGEN_INSN_LGSINT) * 8) - (length)))
#define EXTRACT_MSB0_LGUINT(val, total, start, length) \
(((CGEN_INSN_UINT) (val) << ((sizeof (CGEN_INSN_LGUINT) * 8) - (total) + (start))) \
 >> ((sizeof (CGEN_INSN_LGUINT) * 8) - (length)))

#define EXTRACT_LSB0_LGSINT(val, total, start, length) \
(((CGEN_INSN_LGSINT) (val) << ((sizeof (CGEN_INSN_LGSINT) * 8) - (start) - 1)) \
 >> ((sizeof (CGEN_INSN_LGSINT) * 8) - (length)))
#define EXTRACT_LSB0_LGUINT(val, total, start, length) \
(((CGEN_INSN_LGUINT) (val) << ((sizeof (CGEN_INSN_LGUINT) * 8) - (start) - 1)) \
 >> ((sizeof (CGEN_INSN_LGUINT) * 8) - (length)))

#endif /* CGEN_ENGINE_H */
