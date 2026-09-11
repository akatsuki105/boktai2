# GhidraMCP HTTP API notes

The Ghidra MCP tools are thin wrappers over an HTTP server that the GhidraMCP
plugin (bethington/ghidra-mcp v6) runs inside the Ghidra GUI at
`http://127.0.0.1:8089`. Call it directly with `curl` — it works even when the
MCP connection is down, as long as Ghidra is open with the program loaded.

Full endpoint list with parameters: `GET /mcp/schema` (JSON `tools[]`, each with
`path`, `method`, and `params[]` whose `source` is `query` or `body`). Check it
before guessing a parameter name — several endpoints use unexpected names
(`search_data_types` takes `pattern`, not `query`; `search_functions` takes
`name_pattern`).

## Read endpoints (GET, query parameters)

| Purpose | Call |
|---|---|
| Struct layout | `/get_struct_layout?struct_name=NAME` |
| Find types by name | `/search_data_types?pattern=TEXT&limit=N` |
| Decompile | `/decompile_function?address=0x08xxxxxx&timeout=120` (a function name also works) |
| Disassemble | `/disassemble_function?address=0x08xxxxxx` — needs a `0x` address; a bare name fails with "could not be resolved" |
| Cross references | `/get_xrefs_to?address=0x...&limit=N` (lines `From ADDR in FUNC [READ/WRITE/UNCONDITIONAL_CALL/DATA]`) |
| Functions by name | `/search_functions?name_pattern=TEXT&limit=N` |
| All functions | `/list_functions?offset=0&limit=6000` (lines `NAME at ADDR`; filter an address range with awk) |
| Defined data | `/list_data_items?limit=4000` (lines `NAME @ ADDR [TYPE] (n bytes)`) |
| One function's signature | `/get_function_by_address?address=0x...` |

Repo helpers that wrap the same server: `tools/ghidra/decompile.ts <name|addr>`
and `tools/ghidra/pcode.ts <name|addr>`.

## Write endpoints (POST, JSON body)

| Purpose | Body |
|---|---|
| Set a function prototype | `{"function_address":"0x...","prototype":"void NAME(T *p, s32 x)","calling_convention":"__stdcall"}` |
| Rename a function | `{"function_address":"0x...","new_name":"..."}` → `/rename_function_by_address` |
| Apply a type to a global | `{"address":"0x...","type_name":"T *[2]"}` → `/apply_data_type` |
| Rename a data type | `{"old_name":"...","new_name":"..."}` → `/rename_data_type` |
| Run a Java GhidraScript | `{"code":"...","args":"a b"}` → `/run_script_inline` (use `scripts/run_ghidra_script.ts`) |
| Save | `{}` → `/save_program` |

## Behaviors that have caused damage

Each of these was hit for real on this project. Structural edits therefore go
through `run_script_inline` (see `edit-recipes.md`), not through the struct
endpoints.

- **`remove_struct_field` packs the struct.** The size shrinks and every later
  field shifts down. There is no "leave a hole" option.
- **`recreate_struct` wipes the parameter types of every function that uses
  the struct** (they fall back to `undefined`). On a widely used type that is
  hundreds of signatures.
- **`create_struct` / `recreate_struct` ignore `offset`.** Fields are packed in
  list order, so gaps must be spelled out as `u8[N]` fillers.
- **`clone_data_type` renames instead of copying.** The type and all of its
  pointer/array derivatives get the new name. If this happens, rename it back
  with `rename_data_type` at once.
- **`add_struct_field` / `modify_struct_field` rewrite names** with Hungarian
  prefixes (a pointer field `next` becomes `pNext`, a word may get `w…`), and
  renaming through the same endpoint reapplies the prefix. When the exact name
  matters, set it with `DataTypeComponent.setFieldName` from a script.
- **Growing a field needs truly undefined bytes.** `add_struct_field` at an
  offset and `modify_struct_field_type` to a larger type fail with "Not enough
  undefined bytes" if the target bytes belong to any defined component —
  including one typed `undefined2`.
- **`set_function_prototype` renames the function** to whatever name appears in
  the prototype string. Always write the function's current name. Also pass
  `"calling_convention":"__stdcall"`; without it the decompiler prints
  "Unknown calling convention -- yet parameter storage is locked".
- **`rename_data` enforces its own `g_` naming rule** and refuses other names.
  Applying a pointer/array type with `apply_data_type` gives an automatic name
  such as `PTR_ARRAY_03003560`, which is acceptable.
- **`analyze_struct_field_usage` needs an in-memory struct instance address.**
  It is useless for heap-allocated structs (almost every entity).
- **Decompiler casts are not evidence of signedness.** Output reflects Ghidra's
  current type info: `(byte)p->field_0x5` was displayed for an `ldrsb`. Read
  the disassembly for `ldrb`/`ldrsb`/`ldrh`/`ldrsh`.
