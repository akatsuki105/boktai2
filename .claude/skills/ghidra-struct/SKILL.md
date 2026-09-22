---
name: ghidra-struct
description: Recover C struct layouts in Ghidra for GBA decompilation through the GhidraMCP HTTP server (http://127.0.0.1:8089) — find every function and struct that uses a type, gather evidence from the code (callee parameter types, allocation sizes, loop strides, load/store width and signedness, GBA hardware semantics), check existing types before inventing new ones, and edit Ghidra data types without packing fields or wiping function signatures. Use this whenever the user asks to analyze / 解析 / 調べる a struct or type in Ghidra, fill unknown fields (unk_XX, field_0x...), determine or verify a struct's size, split or merge struct types, retype function signatures around a struct, or otherwise mentions Ghidra together with 構造体 / 型 / フィールド / サイズ — even if they don't name this skill. Invoked as `/ghidra-struct TypeName` to run one full analysis pass on that type.
argument-hint: <TypeName> [--reflect]
---

# Ghidra struct analysis

Goal: a struct layout in Ghidra where every field is backed by evidence from
the code, with the confidence of each field visible in its name — produced
without ever damaging the Ghidra project.

Ghidra's GUI must be running with the program open. The GhidraMCP plugin
serves an HTTP API at `http://127.0.0.1:8089` (override with
`GHIDRA_MCP_URL`); the MCP tools are thin wrappers over it, so plain `curl`
works even when the MCP connection is down. Endpoint cheat sheet and the API
behaviors that have caused damage: `references/http-api.md` — read it before
the first write.

## Invocation: `/ghidra-struct <TypeName> [--reflect]`

The text after the command arrives as `ARGUMENTS:` at the end of this skill.

- **The first word is the type** to analyse, by its exact Ghidra name
  (`FreezeEffect`).
- **Options are matched as exact tokens.** Nothing parses or validates them, so
  read the argument string literally and apply these two rules before anything
  else:
  - `--reflect` present verbatim → do step 10 at the end. Absent → this skill
    does not touch the repository at all.
  - Any other `--token` → an option this skill does not have, or a typo of one
    it does. **Stop and ask.** Do not guess, and do not silently ignore it; a
    mistyped `--reflct` must not quietly skip the reflection.
  A plain-language request ("終わったらリポジトリにも反映して") also turns step 10
  on, but `--reflect` is the form to prefer.
- **With only a type name, do one complete pass on that type** — the same
  thing that was done for `FreezeEffect`:
  1. current layout and its undefined ranges;
  2. every user: functions already typed with it, the `T_*` family, untyped
     helpers at neighbouring addresses, and the callers of `T_Create` for
     what its parameters mean;
  3. an offset → evidence table for every gap those functions reach;
  4. new sub-types only where no existing type fits (`StructCandidates`);
  5. fill the fields, and retype those functions' parameters to `T *`
     (plus `s32` returns for `Init`/`Update`/`Destroy`);
  6. verify until `check_decomp.ts` shows no raw offsets on `T` in the users;
  7. save and report.
  For an entity, first compare the size in `CreateEntity(kind, size)` with the
  struct's size; a mismatch is the first thing to report.
- **The unit of work is this one type** plus the element/sub-types it needs.
  What you learn about other types (e.g. an undefined byte inside
  `HitboxData`) goes into the report as a hint, not into edits.
- **Large or widely used types:** if the pass would span many functions or
  unrelated subsystems (as a rough guide, more than ~15 users, or hundreds of
  undefined bytes), finish one coherent part — e.g. everything the
  Create/Init/Update/Destroy family proves — save, report, and ask before
  continuing.
- **No argument:** ask which type. **No exact match:** run
  `search_data_types?pattern=` and show the candidates rather than guessing.
  **Several types with that name:** list their category paths and ask.

## Working agreement with the user

These come from the user's corrections; follow them unless told otherwise.

- **Ghidra first, repository last.** Do not edit the repository (headers,
  `src/`) while the analysis is running — the layout is not settled until it is
  saved in Ghidra. Reflecting it into the repo happens only when the user asked
  for it, and only in step 10, after the Ghidra side is saved.
- **The repository's file split is not evidence.** Functions sit in files by
  link order, and neighbours from other modules leak in.
- **Start from functions.** Collect accesses first; don't propose a layout and
  then look for confirmation — that led to circular reasoning here before.
- **Check existing types before creating one** (size, layout, users, and the
  `struct { Base base; ... }` pattern where the unknown type extends a known one).
- **Small work units.** Stop at a natural boundary (all fields provable from
  one path, one struct done, …), save, and report. If the user names the
  boundary ("only what the OAM writes prove"), stop exactly there.
- **Narrate briefly while working** — which function, what it proves.
- Skip library code (m4a and similar): not worth the time.

## Confidence and naming

**Do not use the `q_` prefix.** Provisional fields and new struct types get
plain names, the same as confirmed ones (`scaleX`, `SpriteNode44`). The
confidence of each item belongs in the report and in the field comment, not in
the name. Existing `q_` names stay as they are — do not rename them unless the
user asks.

What still differs is how much evidence a name needs:

- **Confirmed** — uniquely determined by other confirmed facts: the parameter
  type of a callee whose own type is settled (a matching-build function, a
  typed API such as `GetParticleGroup`), an allocation size, a matching
  build, a GBA hardware definition.
- **Provisional** — everything else. Name it, and say in the report that it is
  provisional and on what evidence.
- Width known, meaning unknown: `unk_XX` (offset in hex) with the right type.
  Do not invent a name for a field whose meaning you cannot back with
  evidence — `unk_XX` is the honest answer there.

## Workflow

Keep working files in the scratchpad. `G=http://127.0.0.1:8089`,
`S=.claude/skills/ghidra-struct/scripts` (run from the repo root).

1. **Current state.** `curl -s "$G/get_struct_layout?struct_name=T"`. List the
   undefined ranges — they are the job.
2. **Find the users.**
   - `$S/run_ghidra_script.ts $S/TypeUsers.java T` — functions (params,
     locals, return), embedding structs (with the bytes after each
     embedding), globals.
   - `curl -s "$G/search_functions?name_pattern=T"` — named functions such as
     `T_Create` / `T_Init` / `T_Update` / `T_Destroy`.
   - Untyped helpers usually sit next to them:
     `curl -s "$G/list_functions?offset=0&limit=6000" | awk '{a=$NF} a>="080a7900" && a<="080a8200"'`.
   - For a list head or other global, `get_xrefs_to` gives the insert, remove
     and walk functions.
3. **Decompile the users** into one scratch file
   (`$G/decompile_function?address=...`) and build an offset → evidence
   table. Use the evidence catalog below. Read the disassembly
   (`$G/disassemble_function?address=0x...`) whenever signedness matters.
4. **Look for an existing type** before creating one:
   `$S/run_ghidra_script.ts $S/StructCandidates.java SIZE [HeadType]`.
   Compare layout and users, not just size.
5. **Snapshot.** Save the current layouts of every struct you will touch (and
   of the embedding structs if the size can change) to the scratchpad, and
   the signatures of functions you will retype.
6. **Edit through a script**, following `references/edit-recipes.md`
   (`replaceAtOffset`, `clearComponent`, `growStructure`; guards; size check
   before/after; idempotent). Never use `remove_struct_field`,
   `recreate_struct`, `clone_data_type` or `create_enum`.
7. **Retype functions** with `/set_function_prototype`, writing the function's
   current name and `"calling_convention":"__stdcall"`. Entity `Init` /
   `Update` / `Destroy` return `s32` in this project.
8. **Verify.**
   - Layouts: diff against the snapshot; every size unchanged unless the
     change was intended.
   - Code: `$S/check_decomp.ts --quiet f1 f2 ...` over the users. Zero raw
     offset lines means every access in those functions is explained by
     types. Hits can belong to other structs used in the same function (e.g. `gCollisionMap->field_0x24`); only those on the struct under analysis matter. It cannot see offsets hidden in temporaries (`iVar3 = p + 0x2c`
     then `*(u8 *)(iVar3 + 200)`), so skim the decompile too.
9. **Save** (`POST $G/save_program`) and report.
10. **Reflect into the repository** — only when the invocation asked for it.
    Mirror the saved Ghidra layout into the header or `.c` that declares the
    type, field names and comments included, plus any function signature this
    pass changed. Ghidra's category path tells you which file. Then
    `make clean-code && make compare` must print the OK line; a struct edit can
    change `sizeof` and break a `static_assert`, so never report it as done
    without that. Do not commit unless the user asked. Keep the two sides
    spelled the same — the repo's field-name style is `unk_1c`, not `unk_1C`
    or `unk_01c`.

## Evidence catalog

Strongest first. Most of these produced a confirmed field on this project.

- **Callee parameter types.** `f(p + 0x70, ...)` where `f` takes `Particle*`
  → a `Particle` at 0x70. Two addresses passed together
  (`FUN_0822a470(p + 0x18, p + 0x44, 0)`) pin two fields at once.
- **Size.** `CreateEntity(kind, size)`, `Malloc(n)`, a container tiled exactly
  (`Malloc(0x8c)` holding 5 elements → 28 each), the spacing between
  consecutive instances, loop strides.
  - Decompiled pointer arithmetic is scaled by Ghidra's *current* type:
    `undefined4 *p; p = p + 0x18` is 96 bytes, and `T *p; p + 1` is whatever
    `sizeof(T)` Ghidra believes today. Get the byte stride from the asm
    (`adds rN, #0x2c`) or from an explicit `i * 0x2c`.
  - Not every `+= 0x18` is a stride: counters written into a field, or screen
    coordinates stepping 24 pixels, look the same. `Entity` is 24 bytes, so
    `p[5].field` in the decompile is often a larger struct read as `Entity[]`.
  - Alignment cannot explain an extra 4 bytes on a struct that contains
    pointers and is already a multiple of 4.
  - The same unused 4 bytes after *every* embedding of a type, across
    unrelated containers, means the type is bigger than defined.
- **Width** comes from the load/store instruction. **Signedness** only from
  `ldrsb`/`ldrsh` vs `ldrb`/`ldrh`, or from use (`asr` vs `lsr`, signed vs
  unsigned branches, `lsl #16; asr #16` sign extension). Stores carry no
  sign. In Thumb, `ldrsb`/`ldrsh` exist only with a register offset, so a signed read looks like `mov r3, #0x20` / `ldrsh r0, [r5, r3]` — grepping for `#0x20]` finds only the unsigned forms; grep for `ldrs` and read the preceding `mov`. Decompiler casts are not evidence: `(byte)x` has been shown for an
  `ldrsb`. 4-byte fields: a pointer if dereferenced; `u32` vs `s32` needs a
  signed use.
- **Block copies.** Two word copies of the same 8 bytes from a `Vec3`
  argument → a `Vec3` (x, y, z, val).
- **List operations.** Insert/remove functions give `active`, the list index,
  `prev` and `next` in one go, and type the list-head global.
- **GBA hardware.** A value OR'd into an OAM word or written to an I/O
  register is identified by the spec: OAM attr0 bits 0-7 Y, 8-9 affine/double,
  10-11 mode (01 semi-transparent, 10 OBJ window), 12 mosaic, 13 8bpp, 14-15
  shape; attr1 bits 0-8 X, 9-13 affine index, 12/13 H/V flip, 14-15 size;
  attr2 bits 0-9 tile, 10-11 priority, 12-15 palette. `BGnCNT` bit 6 mosaic;
  `MOSAIC` low byte BG, high byte OBJ.
- **Recognisable math.** Isometric projection `(x - z) * k`, `(x + z) * k`,
  `y * k'` identifies world `x`/`y`/`z`; a sine-table index is an angle; a
  factor compared around `0x40` with `>> 6` is 6.6 fixed-point scale.
- **State machines.** A function pointer called by `Update`, plus a timer
  reset whenever it changes, gives `fn` and the state timer.

## Reporting (in Japanese)

- A table: offset, type, name, evidence (function + access), confidence.
- New types created, functions retyped, what was saved.
- Remaining gaps and why they are still open (e.g. "written only, no reader").
- Mistakes and how they were rolled back — state them plainly.
- Hints for other types found on the way (e.g. an undefined byte in
  `HitboxData` that this struct writes to).

## When something goes wrong

- A script that throws may have committed its earlier statements. Read the
  current layout before re-running; make the rerun reuse what already exists.
- If an edit damaged a struct or signatures and was not saved, tell the user
  at once: closing Ghidra without saving discards it, and they keep `.gar`
  backups. Do not paper over a large mistake with more edits.

## Scripts

| Script | Use |
|---|---|
| `scripts/run_ghidra_script.ts <file.java> [args...]` | Run a GhidraScript in the GUI; prints only its output, exit 1 on build/runtime error. `--raw` for the full response. |
| `scripts/TypeUsers.java <Type> [bytesAfter]` | Everything that uses a type, with the bytes after each embedding. |
| `scripts/StructCandidates.java <size\|-> [HeadType]` | Existing structs that might be the unknown one. |
| `scripts/MergeSplitTail.java <parent> <fake> <end>` | Merge a function Ghidra split off a parent's shared epilogue back into it (bare hex, no `0x`). Guards and aborts on anything unexpected; does not save. See `docs/for-ai-agent/ghidra-split-functions.md`. |
| `scripts/MergeContinuation.java <parent> <fake>...` | Same, for a chunk of a function registered as its own function (the `.inc` has no `push`). Absorbs several at once, unioning their bodies. |
| `scripts/check_decomp.ts [--quiet] <func...>` | Decompile and count unresolved raw-offset lines. |

Repo tools on the same server: `tools/ghidra/decompile.ts`, `tools/ghidra/pcode.ts`,
`tools/ghidra/rename_struct_field.ts <Struct> <field|0xOFF> <newName>` (renames
one field, checks that nothing but the name changed, then saves; use it for
plain renames instead of writing an edit script).
