# Dump cfg file for camthesaxman/gbadisasm
# @author   akatsuki105 (2026-08-07)
# @category GBA
# @runtime PyGhidra

import os

import typing

if typing.TYPE_CHECKING:
    from ghidra.ghidra_builtins import *

func_modes = {
    True: "thumb_func",
    False: "arm_func",
}


def is_thumb_function(prog, func):
    r = prog.getRegister("TMode")
    if r is None:
        print(f"[DEBUG] {func.getName()}: no TMode register (non-ARM lang?)")
        return None
    value = prog.getProgramContext().getRegisterValue(r, func.getEntryPoint())
    if value is None or not value.hasValue():
        print(f"[DEBUG] {func.getName()} @ {func.getEntryPoint()}: TMode value UNSET")
        return None
    return value.getUnsignedValueIgnoreMask().intValue() == 1


def dump_gbadisasm_config(prog, start_addr, max=-1):
    space = prog.getAddressFactory().getDefaultAddressSpace()
    addr = space.getAddress(start_addr)
    fm = prog.getFunctionManager()
    result = ""
    for i, f in enumerate(fm.getFunctions(addr, True)):
        result += dump_row(prog, f)
        if max >= 0 and i + 1 == max:
            break
    return result


def dump_row(prog, func):
    mode = func_modes[is_thumb_function(prog, func)]
    name = func.getName()
    addr = func.getEntryPoint()
    return f"{mode} 0x{addr} {name}\n"


def write_cfg(s):
    cwd = os.getcwd()
    filename = askString("Output Path", cwd + "/")

    if filename == "":
        filename = "rom.cfg"
    elif not filename.endswith(".cfg"):
        filename = filename + ".cfg"
    dst = cwd + "/" + filename

    print("Write cfg file into {}".format(dst))
    with open(dst, "w") as f:
        f.write(s)


def main():
    result = dump_gbadisasm_config(currentProgram, 0x08000000, -1)
    write_cfg(result)


if __name__ == "__main__":
    main()
