# Dumps the data at the cursor (or every defined data item in the current
# selection) as a C initializer, printed to the Ghidra console.
# Assumes a boktai2-side struct with the same field layout/names as the
# Ghidra data type already exists.
# @author   akatsuki105 (2026-08-20)
# @category GBA
# @runtime PyGhidra

import typing

if typing.TYPE_CHECKING:
    from ghidra.ghidra_builtins import *

INDENT_UNIT = "    "


def resolve_base_type(dt):
    """typedef を辿って実体の DataType を返す"""
    from ghidra.program.model.data import TypeDef

    while isinstance(dt, TypeDef):
        dt = dt.getBaseDataType()
    return dt


def is_char_array(dt):
    """char/uchar の配列(=文字列として扱いたい配列)かどうか

    "byte" は含めない。u8(=byte typedef)の生バイト配列を文字列扱いすると
    getDefaultValueRepresentation() が空文字列を返し初期化子が消えてしまうため。
    """
    from ghidra.program.model.data import Array

    if not isinstance(dt, Array):
        return False
    elem = resolve_base_type(dt.getDataType())
    return elem.getName() in ("char", "uchar")


def get_data_name(data):
    """データのシンボル名を取得する(なければアドレスから仮の名前を生成)"""
    prog = data.getProgram()
    sym = prog.getSymbolTable().getPrimarySymbol(data.getAddress())
    if sym is not None:
        return sym.getName()
    return "data_{}".format(data.getAddress())


def format_pointer(data):
    """ポインタを &シンボル名 / NULL / (void*)0xXXX として表現する

    THUMB関数ポインタは最下位ビット(Tビット)が立った奇数アドレスとして
    格納されている。シンボルの完全一致検索(getPrimarySymbol)だと関数の
    開始アドレス(偶数)からずれて解決に失敗する、または offcut な
    "FuncName+1" 名で解決されてしまう。関数の本体バイト範囲に含まれるか
    どうかで判定する getFunctionContaining() を先に使うことで、奇数
    アドレスのままでも関数そのものの名前を取得する。
    """
    prog = data.getProgram()
    value = data.getValue()  # Address or None
    if value is None:
        return "NULL"

    func_mgr = prog.getFunctionManager()
    symtab = prog.getSymbolTable()

    func = func_mgr.getFunctionContaining(value)
    if func is not None:
        return "&{}".format(func.getName())

    sym = symtab.getPrimarySymbol(value)
    if sym is not None:
        return "&{}".format(sym.getName())

    if (value.getOffset() & 1) == 1:
        even_addr = value.subtract(1)
        func = func_mgr.getFunctionContaining(even_addr)
        if func is not None:
            return "&{}".format(func.getName())
        sym = symtab.getPrimarySymbol(even_addr)
        if sym is not None:
            return "&{}".format(sym.getName())

    return "(void*)0x{:X}".format(value.getOffset())


def format_enum(data, dt):
    """enum を定数名(取得できなければ 16進数値)として表現する"""
    value = data.getValue()
    try:
        lv = (
            value.getUnsignedValue()
            if hasattr(value, "getUnsignedValue")
            else int(value)
        )
    except Exception:
        lv = value
    try:
        name = dt.getName(lv)
    except Exception:
        name = None
    return name if name else "0x{:X}".format(lv)


def format_leaf(data):
    """構造体/配列以外(スカラー・enum・ポインタ・文字列)を C リテラルとして表現する"""
    from ghidra.program.model.data import Enum as GEnum
    from ghidra.program.model.data import Pointer
    from ghidra.program.model.scalar import Scalar

    dt = resolve_base_type(data.getDataType())

    if isinstance(dt, Pointer):
        return format_pointer(data)

    if isinstance(dt, GEnum):
        return format_enum(data, dt)

    value = data.getValue()

    if isinstance(value, Scalar):
        v = value.getUnsignedValue()
        if dt.getName() in ("char", "uchar") and 0x20 <= v < 0x7F:
            return "'{}'".format(chr(v))
        # s8/s16/s32(基底型 sbyte/short/int)は符号付きとして表示する。
        # value.getSignedValue() は DataType の符号有無に関係なくスカラーの
        # ビット幅で符号拡張した値を返す。
        if dt.getName() in ("sbyte", "short", "int"):
            sv = value.getSignedValue()
            if sv < 0:
                return "-0x{:X}".format(-sv)
            return "0x{:X}".format(sv)
        return "0x{:X}".format(v)

    # char配列や文字列型は Ghidra 標準表現(ダブルクォート付き)をそのまま使う
    return data.getDefaultValueRepresentation()


def format_data(data, indent):
    """Data を再帰的に C の初期化子文字列へ変換する"""
    from ghidra.program.model.data import Array, Structure

    dt = resolve_base_type(data.getDataType())

    # char配列は要素ごとに展開せず文字列リテラルとして扱う
    if is_char_array(dt):
        return format_leaf(data)

    n = data.getNumComponents()
    if n <= 0 or not (isinstance(dt, Array) or isinstance(dt, Structure)):
        return format_leaf(data)

    is_struct = isinstance(dt, Structure)
    lines = []
    for i in range(n):
        comp = data.getComponent(i)
        comp_str = format_data(comp, indent + 1)
        if is_struct:
            dtc = dt.getComponent(i)
            fname = dtc.getFieldName()
            if not fname:
                fname = "field_0x{:X}".format(dtc.getOffset())
            lines.append(
                INDENT_UNIT * (indent + 1) + ".{} = {}".format(fname, comp_str)
            )
        else:
            lines.append(INDENT_UNIT * (indent + 1) + comp_str)

    inner = ",\n".join(lines)
    return "{\n" + inner + "\n" + INDENT_UNIT * indent + "}"


def get_c_declaration(data):
    """`型 名前[N][M]...` 形式の宣言部分を組み立てる

    型名は typedef(u8/u16/s32 など)をそのまま表示に使う。dims 検出のために
    配列判定だけ resolve_base_type() で行い、要素型自体は typedef を保った
    ままたどる(そうしないと u8 が byte のように基底組み込み型で表示されてしまう)。
    """
    from ghidra.program.model.data import Array

    name = get_data_name(data)

    dims = []
    cur = data.getDataType()
    while isinstance(resolve_base_type(cur), Array):
        arr = resolve_base_type(cur)
        dims.append(arr.getNumElements())
        cur = arr.getDataType()

    dim_str = "".join("[{}]".format(n) for n in dims)
    return "{} {}{}".format(cur.getDisplayName(), name, dim_str)


def dump_one(data):
    decl = get_c_declaration(data)
    body = format_data(data, 0)
    println("{} = {};".format(decl, body))


def collect_selection_data(prog, selection):
    """選択範囲内で定義済みの最上位データを列挙する"""
    listing = prog.getListing()
    result = []
    it = listing.getDefinedData(selection, True)
    while it.hasNext():
        result.append(it.next())
    return result


def main():
    prog = currentProgram
    listing = prog.getListing()

    if currentSelection is not None and not currentSelection.isEmpty():
        items = collect_selection_data(prog, currentSelection)
        if not items:
            println("[dump_data_as_c] 選択範囲内に定義済みデータが見つかりません")
            return
        for data in items:
            dump_one(data)
        return

    if currentAddress is None:
        println("[dump_data_as_c] アドレスを取得できませんでした")
        return

    data = listing.getDataContaining(currentAddress)
    if data is None:
        println("[dump_data_as_c] カーソル位置にデータが定義されていません")
        return

    dump_one(data)


if __name__ == "__main__":
    main()
