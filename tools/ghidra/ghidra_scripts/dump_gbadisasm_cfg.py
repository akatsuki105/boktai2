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


def check_dst(dst):
    """意図しない場所に書き出さないよう、出力先を検査する。問題があれば例外を投げる

    - 絶対パスであること (相対パスは Ghidra のカレントディレクトリ基準になり、場所が分かりにくい)
    - 拡張子が .cfg であること (ソースなど別のファイルを上書きしないため)
    - 書き出し先のディレクトリが既にあること (タイプミスで新しい場所に作らないため)
    """
    if not os.path.isabs(dst):
        raise ValueError(f"出力先は絶対パスで指定してください: {dst}")
    if not dst.endswith(".cfg"):
        raise ValueError(f"出力先の拡張子は .cfg にしてください: {dst}")
    if os.path.isdir(dst):
        raise ValueError(f"出力先がディレクトリです: {dst}")
    parent = os.path.dirname(dst)
    if not os.path.isdir(parent):
        raise ValueError(f"出力先のディレクトリがありません: {parent}")


def write_cfg(s, dst=None):
    """dst が指定されていればそこに書き出す。なければダイアログで出力先を聞く"""
    if dst is None:
        cwd = os.getcwd()
        filename = askString("Output Path", cwd + "/")

        if filename == "":
            filename = "rom.cfg"
        elif not filename.endswith(".cfg"):
            filename = filename + ".cfg"
        # ダイアログの初期値 (cwd + "/") を残したまま入力すると絶対パスになるので、そのときは cwd を重ねない
        dst = filename if os.path.isabs(filename) else os.path.join(cwd, filename)

    dst = os.path.normpath(dst)
    check_dst(dst)
    print("Write cfg file into {}".format(dst))
    with open(dst, "w") as f:
        f.write(s)


def main():
    # 引数で出力先を渡せる (Ghidra のカレントディレクトリはリポジトリではないので絶対パスで渡すこと)
    #   tools/ghidra/run_pyghidra_script.ts tools/ghidra/ghidra_scripts/dump_gbadisasm_cfg.py $PWD/rom.cfg
    args = getScriptArgs()
    dst = args[0] if args else None
    if dst is not None:
        check_dst(dst)  # 全関数を走査する前に弾く
    result = dump_gbadisasm_config(currentProgram, 0x08000000, -1)
    write_cfg(result, dst)


if __name__ == "__main__":
    main()
