"""Decompile a ROM function by address with Ghidra (existing project).

Usage: python3 tools/ghidra_decompile.py 0x08XXXXXX
Opens the existing Ghidra project (Boktai) and decompiles the function at the
given address from Boktai2B.gba. Uses the project's existing analysis results
(function names, types, comments) as-is — no re-analysis needed.
"""
import os, sys

for _v in ('GHIDRA_INSTALL_DIR', 'JAVA_HOME', 'GHIDRA_PROJECT_DIR'):
    if not os.environ.get(_v):
        sys.exit('%s is not set -- see notes/ghidra-mcp-setup.md' % _v)

PROJECT_DIR  = os.environ['GHIDRA_PROJECT_DIR']
PROJECT_NAME = os.environ.get('GHIDRA_PROJECT_NAME', 'Boktai')
PROGRAM_PATH = os.environ.get('GHIDRA_PROGRAM_PATH', '/Boktai2B.gba')

addr_hex = next((a for a in sys.argv[1:] if a.startswith('0x') or a.startswith('0X')), None)
if addr_hex is None:
    sys.exit('Usage: python3 tools/ghidra_decompile.py 0x08XXXXXX')

import pyghidra
pyghidra.start()

project = pyghidra.open_project(PROJECT_DIR, PROJECT_NAME)
with pyghidra.program_context(project, PROGRAM_PATH) as prog:
    space = prog.getAddressFactory().getDefaultAddressSpace()
    a = space.getAddress(int(addr_hex, 16))

    fn = prog.getFunctionManager().getFunctionContaining(a)
    if fn is None:
        print("NO FUNCTION at", addr_hex, "-- trying to create one...")
        txid = prog.startTransaction("create-func")
        from ghidra.app.cmd.function import CreateFunctionCmd
        CreateFunctionCmd(a).applyTo(prog)
        prog.endTransaction(txid, False)  # False = don't save
        fn = prog.getFunctionManager().getFunctionContaining(a)

    if fn is None:
        print("FAILED to find/create function at", addr_hex)
        sys.exit(2)

    from ghidra.app.decompiler import DecompInterface
    di = DecompInterface()
    di.openProgram(prog)
    res = di.decompileFunction(fn, 90, None)
    print("=== decompiled", fn.getName(), "@", addr_hex, "===")
    if res.decompileCompleted():
        print(res.getDecompiledFunction().getC())
    else:
        print("DECOMPILE FAILED:", res.getErrorMessage())
