---
name: todo-to-naked
description: Promote boktai2 functions from the TODO level to the NAKED level — pull one function's assembly out of a bulk INCASM file into asm/func/NAME.inc, give it a C signature in src/, and (when the evidence is solid) a real name. Use when the user invokes /todo-to-naked, or asks to move functions out of an asm/*.inc / src/*.s blob into C stubs.
---

# todo-to-naked

See CLAUDE.md's "Function Decompilation Levels" for the four levels. This skill
does exactly one step: **TODO → NAKED**. It never writes C bodies — that is
`decomp-func`'s job.

## Invocation

`/todo-to-naked <FUNCTION_NAME>...` — promote those functions.

`/todo-to-naked <FILE>` — promote every TODO function still inside that file's
`INCASM` blob. Take them **from the highest address down**: a C stub always
sits after the `INCASM`, so a function cannot leave the blob while a
higher-addressed one is still in it. `prepare_asm.ts` refuses and names the
blockers when you get this backwards. Do them one at a time, all the way
through, before starting the next.

## The two states a TODO function can be in

A TODO function lives inside a bulk asm file that `src/FOO.c` pulls in with
`INCASM("asm/foo.inc")`. It is in one of two shapes:

```asm
	thumb_func_start FUN_080a939c        ← not extracted: body is inline
FUN_080a939c: @ 0x080A939C
	push {r4, r5, r6, lr}
	...

	thumb_func_start HealingParticles_Destroy    ← already extracted
HealingParticles_Destroy: @ 0x080A91BC
  .include "asm/func/HealingParticles_Destroy.inc"
```

`scripts/prepare_asm.ts` handles both: the first gets extracted and then
unstubbed, the second only unstubbed.

## Steps

1. **Work out the signature.** See "Signature evidence" below.

2. **Promote it:**

   ```sh
   .claude/skills/todo-to-naked/scripts/prepare_asm.ts FUNCTION_NAME \
     --sig "void FUNCTION_NAME(HealingEffect* p)"
   ```

   That does all three edits, which only work as a set:
   - extracts the body into `asm/func/NAME.inc` (skipped when the `.include`
     form is already there, by calling `tools/extract_func.ts`);
   - deletes the three-line stub (`thumb_func_start` / label / `.include`) from
     the bulk asm file;
   - inserts `NAKED <sig> { INCFUNC("asm/func/NAME.inc"); }` into the `.c` that
     `INCASM`s that file, in ROM-address order;
   - deletes the bulk asm file and its `INCASM` line once nothing but the
     header directives is left in it.

   Leaving the stub while adding the C line includes the same `.inc` twice
   (`symbol '_080AXXXX' is already defined`, `invalid offset, value too big`);
   removing the stub without the C line drops the symbol from the ROM.

   Without `--sig` it stops after the asm side and prints the function's
   address, for when you want to place the C line yourself. Use
   `tools/extract_func.ts` directly when the function is staying at the TODO
   level — that only extracts and leaves the stub in place.

3. **Name it, if the evidence is solid.** Rename only when you can say what the
   function does; `FUN_xxxxxxxx` is the honest answer otherwise. Use:

   ```sh
   tools/rename_with_ghidra.sh --quiet OLD_NAME NEW_NAME
   ```

   That renames the repo and Ghidra together (Ghidra's GUI must be open), and
   renames `asm/func/OLD_NAME.inc` too. Follow the neighbouring functions'
   naming: `Owner_Verb` (`HealingParticles_InitHitbox`), and the
   `XXX_Create` / `_Init` / `_Update` / `_Destroy` family for entities.

4. **Verify.** `make clean-code && make compare` must print the `boktai2.gba: OK`
   line. A stale object file will happily report a match that isn't there, so do
   not skip `clean-code`.

5. **Report** what was promoted, the signature, and the evidence for the name.
   Do not commit unless the user asked.

## Signature evidence

Ghidra answers all of this; `http://127.0.0.1:8089` works even when the MCP
connection is down (see `.claude/skills/ghidra-struct/references/http-api.md`).

- **Parameters** come from the callers:
  `curl -s "$G/get_xrefs_to?address=0xADDR&limit=10"`, then decompile a caller
  and read what it passes. A caller that is already MATCHING C in `src/` is the
  strongest evidence — its own types are settled.
- **Return type** comes from the epilogue. `pop {r0}` / `bx r0` means `void`;
  `pop {r1}` / `bx r1` means the function is declared to return a value (see
  the `pop {r1}` entry in `docs/for-ai-agent/agbcc-quirks.md`). An entity's
  `Init` / `Update` / `Destroy` returns `s32` in this project even when the
  body only returns 0.
- **The pointer's type** comes from what the body touches. If it indexes fields
  of a struct the caller already owns (`p + 0x24` passed to a `HitboxData*`
  callee), use that struct.
- Ghidra's own prototype (`get_function_by_address`) is a starting point, not
  evidence; it is often `undefined FUN_xxx(void)`.

**When a type doesn't fall out quickly, use `unknown*`** — a `void*` alias that
says "not analysed yet" out loud — and move on. This step is about getting the
function into C, not about finishing its analysis; a later pass (or
`decomp-func` on that function) settles the type with the body in front of it.
Spending the time here only pays off when the answer is one xref away.

## Pitfalls seen in practice

- `prepare_asm.ts` counts the extracted body in lines, not functions — a "61 行"
  message does not mean it found the right boundaries. Check the tail of the
  new `.inc` ends at the function's own `bx`/pool constants.
- The pool constants at the end of a function move with it. If the following
  function in the blob referenced them, the build fails; extract that one too.
- `prepare_asm.ts` places the `NAKED` line by address, using the function
  **definitions** already in the `.c` as markers (forward declarations are
  skipped — they sit at the top of the file and say nothing about `.text`
  order). If it still gets the order wrong it prints a `警告:` line naming the
  two functions; move the line by hand, or `make compare` fails with no other
  clue.
- A candidate whose body is just a few instructions ending in `pop`/`bx`, sitting
  right after the previous function, is probably not a function at all but that
  function's shared epilogue, split off because Ghidra read a long `bl` branch as
  a call. Promoting it produces a bogus C stub. Check whether the previous
  function branches to it, and see
  `docs/for-ai-agent/ghidra-split-functions.md` for how to merge it instead.
- `rm` is interactive here — use `rm -f` if you ever need to delete a file.
- Renaming touches `data/*.inc` as well (script command tables reference these
  symbols). Check `git status` for files outside `src`/`include`/`asm` before
  reporting the work as done.

## Scripts

| Script | Use |
|---|---|
| `scripts/prepare_asm.ts <FUNCTION_NAME> [ASM_FILE] [--sig SIG]` | Extract if needed, remove the stub from the bulk asm file, and with `--sig` add the `NAKED` line to the `.c` in address order. Deletes the blob and its `INCASM` line when it empties out. Refuses when a higher-addressed function is still in the blob. |
