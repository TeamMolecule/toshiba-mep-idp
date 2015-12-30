#include "mep.hpp"

void out_print_address(op_t &x, ea_t /*pc*/)
{
  if (!out_name_expr(x, x.addr))
  {
    OutValue(x, OOF_ADDR | OOF_NUMBER | OOFS_NOSIGN);
    QueueSet(Q_noName, cmd.ea);
  }
}

void out_print_spreg(op_t &/*x*/, ea_t /*pc*/)
{
  out_register("$sp");
}

void out_print_tpreg(op_t &/*x*/, ea_t /*pc*/)
{
  out_register("$tp");
}

void make_stack_var(op_t &x)
{
  if (may_create_stkvars())
  {
    adiff_t sp_off = x.value;
    if ( ua_stkvar2(x, sp_off, 0) )
      op_stkvar(cmd.ea, x.n);
  }
}

//--------------------------------------------------------------------------

static int idaapi notify(processor_t::idp_notify msgid, ...) // Various messages:
{
  va_list va;
  va_start(va, msgid);

// A well behaving processor module should call invoke_callbacks()
// in his notify() function. If this function returns 0, then
// the processor module should process the notification itself
// Otherwise the code should be returned to the caller:

  int code = invoke_callbacks(HT_IDP, msgid, va);
  if ( code )
    return code;
  code = 1;

  switch ( msgid )
  {
    case processor_t::loader_elf_machine:
      {
        linput_t *li = va_arg(va, linput_t *);
        int machine_type = va_arg(va, int);
        const char **p_procname = va_arg(va, const char **);
        (void)li; // unused variable
        if (machine_type == 0xF00D)
        {
          *p_procname = "Toshiba MeP";
          code = 0xF00D;
        }
        else
        {
          code = 0;
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
static void idaapi header(void)
{
}

//--------------------------------------------------------------------------
static void idaapi segstart(ea_t /*ea*/)
{
}

//--------------------------------------------------------------------------
static void idaapi segend(ea_t /*ea*/)
{
}

//--------------------------------------------------------------------------
static void idaapi footer(void)
{
}

//--------------------------------------------------------------------------

static const asm_t mepasm =
{
  0,
  0,
  "MEP assembler",
  0,
  NULL,
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

//-----------------------------------------------------------------------
// use simple translation
static ea_t idaapi mep_translate(ea_t base, adiff_t offset)
{
  return base+offset;
}

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

idaman processor_t ida_module_data LPH =
{
  IDP_INTERFACE_VERSION,        // version
  PLFM_MEP,                      // id
  PR_USE32
  |PRN_HEX
  |PR_WORD_INS
  |PR_RNAMESOK          // can use register names for byte names
  |PR_SEGTRANS          // segment translation is supported (codeSeg)
  |PR_SGROTHER,         // the segment registers don't contain
                        // the segment selectors, something else
  8,                            // 8 bits in a byte for code segments
  8,                            // 8 bits in a byte for other segments

  shnames,    // short processor names (null term)
  lnames,     // long processor names (null term)

  asms,       // array of enabled assemblers

  notify,     // Various messages:

  header,     // produce start of text file
  footer,     // produce end of text file

  segstart,   // produce start of segment
  segend,     // produce end of segment

  NULL,

  ana,
  emu,

  out,
  outop,
  mep_data,    //intel_data,
  NULL,       // compare operands
  NULL,       // can have type

  qnumber(RegNames),    // Number of registers
  RegNames,             // Register names
  NULL,                 // get abstract register

  0,                    // Number of register files
  NULL,                 // Register file names
  NULL,                 // Register descriptions
  NULL,                 // Pointer to CPU registers

  0,0,
  4,                    // size of a segment register
  0,0,

  NULL,                 // No known code start sequences
  retcodes,

  0, MEP_INSN_RI_26+1,
  Instructions,
  NULL,                 // int  (*is_far_jump)(int icode);
  mep_translate,        // Translation function for offsets
  0,                    // int tbyte_size;  -- doesn't exist
  NULL,                 // int (*realcvt)(void *m, ushort *e, ushort swt);
  { 0, 0, 0, 0 },       // char real_width[4];
                        // number of symbols after decimal point
                        // 2byte float (0-does not exist)
                        // normal float
                        // normal double
                        // long double
  NULL,                 // int (*is_switch)(switch_info_t *si);
  NULL,                 // int32 (*gen_map_file)(FILE *fp);
  NULL,                 // ea_t (*extract_address)(ea_t ea,const char *string,int x);
  NULL,                 // int (*is_sp_based)(op_t &x); -- always, so leave it NULL
  NULL,                 // int (*create_func_frame)(func_t *pfn);
  NULL,                 // int (*get_frame_retsize(func_t *pfn)
  NULL,                 // void (*gen_stkvar_def)(char *buf,const member_t *mptr,int32 v);
  gen_spcdef,           // Generate text representation of an item in a special segment
  MEP_INSN_RET,         // Icode of return instruction. It is ok to give any of possible return instructions
  NULL,                 // const char *(*set_idp_options)(const char *keyword,int value_type,const void *value);
  NULL,                 // int (*is_align_insn)(ea_t ea);
  NULL,                 // mvm_t *mvm;
};
