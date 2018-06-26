#include "mep.hpp"

//------------------------------------------------------------------------
static bool idaapi can_have_type(const op_t &x)      // returns 1 - operand can have
{
  switch ( x.type )
  {
    case o_void:
    case o_reg:
    case o_near:
      return 0;
//    case o_phrase: can have type because of ASI or 0 struct offsets
  }
  return 1;
}

//--------------------------------------------------------------------------

static ssize_t idaapi notify(void *, int msgid, va_list va) // Various messages:
{
  int code = 0;

  switch ( msgid )
  {
    case processor_t::ev_ana_insn:
      {
        insn_t *out = va_arg(va, insn_t *);
        return mep_ana(out);
      }

    case processor_t::ev_emu_insn:
      {
        const insn_t *insn = va_arg(va, const insn_t *);
        return mep_emu(*insn) ? 1 : -1;
      }

    case processor_t::ev_out_insn:
      {
        outctx_t *ctx = va_arg(va, outctx_t *);
        out_insn(*ctx);
        return 1;
      }

    case processor_t::ev_out_operand:
      {
        outctx_t *ctx = va_arg(va, outctx_t *);
        const op_t *op = va_arg(va, const op_t *);
        return out_opnd(*ctx, *op) ? 1 : -1;
      }

    case processor_t::ev_can_have_type:
      {
        const op_t *op = va_arg(va, const op_t *);
        return can_have_type(*op) ? 1 : -1;
      }

    case processor_t::ev_loader_elf_machine:
      {
        linput_t *li = va_arg(va, linput_t *);
        int machine_type = va_arg(va, int);
        const char **p_procname = va_arg(va, const char **);
        (void)li; // unused variable
        if (machine_type == 0xF00D)
        {
          *p_procname = "MeP";
          code = 0xF00D;
        }
      }
      break;

    default:
      break;
  }
  va_end(va);

  return code;
}

//--------------------------------------------------------------------------

static const asm_t mepasm =
{
  ASH_HEXF3 | ASO_OCTF1 | ASB_BINF3,
  0,
  "MeP assembler",
  0,
  NULL,
  ".org",
  ".end",

  ";",          // comment string
  '"',          // string delimiter
  '\'',         // char delimiter (no char consts)
  "\\\"'",      // special symbols in char and string constants

  ".ascii",     // ascii string directive
  ".byte",      // byte directive
  ".word",      // word directive
  ".dword",     // dword  (4 bytes)
  ".qword",     // qword  (8 bytes)
  NULL,         // oword  (16 bytes)
  ".float"      // float  (4 bytes)
  ".double",    // double (8 bytes)
  NULL,         // tbyte  (10/12 bytes)
  NULL,         // packed decimal real
  NULL,         // arrays (#h,#d,#v,#s(...)
  ".block %s",  // uninited arrays
  ".equ",       // Equ
  NULL,         // seg prefix
//  preline, NULL, operdim,
  NULL, NULL, NULL,
  NULL,
  NULL,
  NULL,         // func_header
  NULL,         // func_footer
  NULL,         // public
  NULL,         // weak
  NULL,         // extrn
  NULL,         // comm
  NULL,         // get_type_name
  NULL,         // align
  0, 0,     // lbrace, rbrace
  NULL,    // mod
  NULL,    // and
  NULL,    // or
  NULL,    // xor
  NULL,    // not
  NULL,    // shl
  NULL,    // shr
  NULL,    // sizeof
};

static const asm_t *const asms[] = { &mepasm, NULL };

//-----------------------------------------------------------------------
static const uchar retcode_1[] = { 0x02, 0x70 };

static const bytes_t retcodes[] =
{
  { sizeof(retcode_1), retcode_1 },
  { 0, NULL }
};

//--------------------------------------------------------------------------

#define FAMILY "Toshiba MeP family:"
static const char *const shnames[] = { "MeP", NULL };
static const char *const lnames[]  = { FAMILY"Toshiba MeP C5 media engine", NULL };

//--------------------------------------------------------------------------

//-----------------------------------------------------------------------
//      Processor Definition
//-----------------------------------------------------------------------

#define PLFM_MEP 0xF00D
#include "reg.cpp"

processor_t LPH =
{
  IDP_INTERFACE_VERSION,  // version
  PLFM_MEP,               // id
                          // flag
  PR_USE32
  |PR_DEFSEG32
  |PRN_HEX
  |PR_WORD_INS
  |PR_RNAMESOK          // can use register names for byte names
  |PR_SEGTRANS          // segment translation is supported (codeSeg)
  |PR_SGROTHER,         // the segment registers don't contain
                        // the segment selectors, something else
                          // flag2
  0,                    // the module has processor-specific configuration options
  8,                      // 8 bits in a byte for code segments
  8,                      // 8 bits in a byte for other segments

  shnames,
  lnames,

  asms,

  notify,

  RegNames,
  qnumber(RegNames),    // number of registers

  qnumber(RegNames)-2,qnumber(RegNames)-1, // first, last
  0,                    // size of a segment register
  qnumber(RegNames)-2,qnumber(RegNames)-1, // virtual CS,DS

  NULL,                 // No known code start sequences
  retcodes,             // 'Return' instruction codes

  0, MEP_INSN_RI_26+1,
  Instructions,         // instruc
  0,                    // int tbyte_size;  -- doesn't exist
  { 0, 0, 0, 0 },       // char real_width[4];
                        // number of symbols after decimal point
                        // 2byte float (0-does not exist)
                        // normal float
                        // normal double
                        // long double
  MEP_INSN_RET,         // Icode of return instruction. It is ok to give any of possible return instructions
};
