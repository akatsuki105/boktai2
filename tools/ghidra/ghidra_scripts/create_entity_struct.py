# Creates an Entity struct type under /entity.h: `Entity e` at 0x00, the rest left undefined.
# Args: <name> <size>
# Prints "EXISTS <path>" and changes nothing if a data type with that name already exists,
# otherwise "CREATED <path> <size>".
#   tools/ghidra/run_pyghidra_script.ts tools/ghidra/ghidra_scripts/create_entity_struct.py Entity08013b68 32
# Usually run through tools/ghidra/create_entity_struct.ts.
# @author   akatsuki105 (2026-09-15)
# @category GBA
# @runtime PyGhidra

import typing

if typing.TYPE_CHECKING:
    from ghidra.ghidra_builtins import *

ENTITY_SIZE = 24


def find_types(dtm, name):
    """名前が完全に一致する DataType をすべて返す"""
    from java.util import ArrayList

    found = ArrayList()
    dtm.findDataTypes(name, found)
    return [d for d in found if d.getName() == name]


def main():
    from ghidra.program.model.data import CategoryPath, DataTypeConflictHandler, StructureDataType

    args = getScriptArgs()
    if len(args) != 2:
        raise ValueError("usage: create_entity_struct.py <name> <size>")
    name = args[0]
    size = int(args[1], 0)
    if size < ENTITY_SIZE:
        raise ValueError(f"サイズ {size} は Entity ({ENTITY_SIZE} バイト) より小さいです")

    dtm = currentProgram.getDataTypeManager()

    existing = find_types(dtm, name)
    if existing:
        println(f"EXISTS {existing[0].getPathName()}")
        return

    entities = [d for d in find_types(dtm, "Entity") if d.getLength() == ENTITY_SIZE]
    if not entities:
        raise ValueError(f"{ENTITY_SIZE} バイトの Entity 型が見つかりません")

    sd = StructureDataType(CategoryPath("/entity.h"), name, size, dtm)
    sd.replaceAtOffset(0, entities[0], ENTITY_SIZE, "e", None)
    dt = dtm.addDataType(sd, DataTypeConflictHandler.DEFAULT_HANDLER)
    println(f"CREATED {dt.getPathName()} {dt.getLength()}")


if __name__ == "__main__":
    main()
