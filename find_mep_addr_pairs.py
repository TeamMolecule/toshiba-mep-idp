import idaapi
import idautils
import idc

MAX_REGISTERS = 228

def find_pairs():
    ea = idc.MinEA()
    movh = [None] * MAX_REGISTERS
    while ea < idc.MaxEA():
        insn = idautils.DecodeInstruction(ea)
        if insn:
            mnem = insn.get_canon_mnem()
            reg1 = insn.Op1.reg
            reg2 = insn.Op2.reg
            val1 = insn.Op2.value
            val2 = insn.Op3.value
            size = insn.size

            if mnem == "movh" and insn.Op2.type == o_imm:
                movh[reg1] = (val1, insn.ea)
            elif movh[reg1] is not None:
                other = movh[reg1]
                if mnem == "add3" and reg1 == reg2:
                    target = (other[0] << 16) + val2
                    print "Found a add3 pointer pair to ", hex(target), " at ", hex(insn.ea)
                    idc.add_dref(insn.ea, target, dr_O)
                    idc.add_dref(other[1], target, dr_O)
                    idaapi.set_refinfo(insn.ea, 2, REF_LOW16, target, 0, 0)
                    idaapi.set_refinfo(other[1], 1, REF_HIGH16, target, 0, 0)
                elif mnem == "or3" and reg1 == reg2:
                    target = (other[0] << 16) | val2
                    print "Found a or3 pointer pair to ", hex(target), " at ", hex(insn.ea)
                    idc.add_dref(insn.ea, target, dr_O)
                    idc.add_dref(other[1], target, dr_O)
                    idaapi.set_refinfo(insn.ea, 2, REF_LOW16, target, 0, 0)
                    idaapi.set_refinfo(other[1], 1, REF_HIGH16, target, 0, 0)
                movh[reg1] = None

            if insn.get_canon_feature() & (idaapi.CF_STOP | idaapi.CF_CALL):
                movh = [None] * MAX_REGISTERS
        else:
            size = 2
        ea += size

def main():
    print "Finding all address pairs"
    find_pairs()
    print "Done."

if __name__ == "__main__":
    main()
