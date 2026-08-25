---
name: decomp-naked
description: Promote boktai2 functions from TODO level to NAKED level (give them a C signature + INCFUNC stub, no decompilation of the body).
---

## The one rule

**Promotion must never change the ROM.** A NAKED stub's body is
`INCFUNC("asm/func/FUNCNAME.inc")` — the exact same bytes the linker already
emits for this function today. This skill only gives a function a C-callable
signature; it does not decompile the body (that's `/decomp-func`'s job, and
only after this skill has made the function NAKED). `make compare` must
print OK before and after every promotion.

**The second-highest priority is never guessing a wrong signature.** A wrong
NAKED body is impossible (it's literally the original bytes), but a wrong
*signature* can silently corrupt callers once they get decompiled later.
When in doubt, don't promote — leave the function in its `.s` file. See
"The promotion workflow" step 1 for the exact bar.

## Scope

See CLAUDE.md's "Function Decompilation Levels" for the 4-level vocabulary
(TODO / NAKED / NON_MATCH / MATCHING). This skill only handles:

```
TODO → NAKED
```

It never touches NON_MATCH or MATCHING functions, and it never writes a real
(non-INCFUNC) function body — that's out of scope, hand off to
`/decomp-func` once a function reaches NAKED.

## Where TODO functions live

Most remaining TODO functions live in monolithic `src/code_*.s` files —
plain assembler files built directly by the Makefile's wildcard rule (no
`.inc`/`INCFUNC` indirection yet). Each contains many functions back to
back, one `thumb_func_start` block per function.

**Some of these files are enormous** (`src/code_08000440.s` is ~200k
lines). **Before opening any `src/code_*.s` file, always check its size
first** (`wc -l`) and treat large files as off-limits to read in full —
work only with the smallest files, and only ever read/manipulate one
function's worth of lines within them, not the whole file.

## Picking a target

Within one `.s` file, promote functions strictly in **address order**,
front to back (the order they physically appear in the file). This keeps
the destination `.c` file's name and the linker-script insertion point
correct without ever having to search or reorder later (see "File &
linker placement" below).

The basic unit of work is **one function**. Promoting several functions is
just repeating the workflow below function-by-function, still in address
order.

## The promotion workflow

For the next (address-order) function in the target `.s` file:

1. **Determine the signature first** — if it can't be pinned down
   confidently, stop here and leave the function untouched in the `.s`
   file. Do not proceed to extraction for a function you're going to
   guess.

   - **Check Ghidra before anything else.** Look up the function by name;
     if that fails (not renamed yet), look it up by address. If Ghidra
     already has a concrete, non-`undefined` type for the return value or
     a parameter, adopt it directly and skip the corresponding heuristic
     below for that part of the signature. Ghidra's `undefined`/
     `undefinedN`/`undefined4*`-style placeholder types are mechanically
     assigned by auto-analysis, not evidence of anything — never adopt
     them, and don't even treat them as a hint; fall through to the
     heuristics below exactly as if Ghidra had nothing for that part.
     A Ghidra-given type that looks unfamiliar (e.g. a `Unk_XXXXXXXX`
     struct) is not automatically the same as `undefined` — check
     `include/` (`global.h` in particular) before assuming it isn't
     usable; it may already be a real, defined project type. Only treat
     it as unusable if it genuinely isn't defined anywhere in the repo.
     When adopting a Ghidra parameter's *type*, don't bother adopting
     whatever name Ghidra attached to it (`param_1`, `r0`, ...) verbatim —
     just use the plain register name (`r0`..`r3`), same as every other
     parameter in this skill's output. The point is to not invent a
     semantic name from usage, not to preserve Ghidra's own placeholder
     naming scheme, which varies by which Ghidra tool produced it
     (`get_function_by_address` names by register, `decompile_function`
     names by `param_N`) and isn't worth reconciling for a purpose that
     isn't understood yet anyway.
     If two Ghidra results disagree on a type for what looks like the
     same underlying data (e.g. a plain scan via
     `get_function_by_address` vs. a forced `decompile_function` pass, or
     a sibling function handling the same structure), don't pick a side —
     that disagreement is itself a signal the type isn't reliably known,
     so fall back to `UNK_PTR`/register-name like any other unidentified
     parameter.
     `get_function_by_address` sometimes returns a stale/never-analyzed
     stub (`undefined FUNCNAME(void)`) that isn't a real conclusion — if
     the params look suspiciously empty given the assembly, run
     `decompile_function` on it to force a real pass before trusting the
     `(void)`.
     Ghidra's decompilation of this project's `pop {rN}; bx rN` epilogue
     idiom routinely misreads it as a 64-bit return
     (`undefined8` / `CONCAT44(in_lr, realValue)`), folding the link
     register into the return value. This is a known Ghidra
     misinterpretation, not a real wide return — always ignore `in_lr`
     and treat only the other half (`realValue`) as the actual return
     value's evidence.
   - **Finding callers.** Whenever a step below says "check call sites,"
     query Ghidra for them (callers/xrefs to the function) rather than
     grepping — Ghidra's answer is trustworthy and, unlike grep, actually
     covers callers still sitting in the giant unread `.s` files. When a
     caller happens to already be decompiled C, still read the real
     source at that call site for the precise C-level type (Ghidra's own
     decompilation of it is secondary to the actual committed C).
   - **Return type.** Check the register used by the function's *epilogue*
     `bx` (the one at the actual return point — `pop {rN}; bx rN` —, not
     any mid-function `bx`). agbcc reuses r0 for this pop/bx trick only
     when r0 is free, i.e. when the function has no return value:
     - `bx r0` → the function is void. Use `void` directly, no further
       check needed.
     - `bx r1` (or any non-r0 register) → r0 was deliberately preserved,
       so the function **does** return a value. Do not default to `void`
       here even if it looks unused. Check every known caller's `bl`
       site — is r0 read (used in any computation, comparison, store, or
       passed on) before it's next overwritten or the caller itself
       returns?
       - If some caller reads it → infer the return type from that
         usage, same as for parameters.
       - If every known caller provably discards it (r0 is overwritten
         or the caller returns without ever reading it — e.g. `bl FUNC`
         immediately followed by `pop {r0}; bx r0` with nothing reading
         r0 in between) → the value exists but nothing depends on its
         type, so it's safe to fall back to `UNK_PTR` as the return
         type, same reasoning as the parameter fallback.
       - If no caller exists yet in already-decompiled code, or a
         caller's handling of r0 can't be determined confidently either
         way → **abort, leave in `.s`.**
   - **Parameters.** Argument count/order comes from which of r0-r3 the
     function actually reads before clobbering them — this is usually
     mechanical. For each parameter:
     - If the type can be identified (from usage inside the function, or
       from already-decompiled call sites) → give it a real type and a
       semantic name, e.g. `WeaponTemplate* w`. For numeric (non-pointer)
       parameters, check for the `lsls`/`lsrs`/`asrs` truncation and
       sign-extension idioms cataloged in
       `docs/for-ai-agent/agbcc-quirks.md` (repo root) "Signedness &
       width" — they reveal `u8`/`s8`/`u16`/`s16` vs plain `s32`/`u32`.
       The same idiom, applied to r0 right after a `bl`, is also useful
       for narrowing down a numeric *return* type above.
     - If the type can't be identified → use `UNK_PTR rN`, keeping the
       raw register name (`r0`..`r3`) as the variable name. `UNK_PTR` is
       a `typedef void*` in `include/types.h` that exists specifically to
       mark "not yet identified" — greppable across the codebase.
       **Do not** retroactively rename existing plain `void*` parameters
       in already-NAKED functions to `UNK_PTR`; it only applies to new
       promotions from this skill.
     - If you can't even tell how many arguments there are with
       confidence → **abort, leave in `.s`.**

2. **Extract the assembly** into `asm/func/FUNCNAME.inc`:
   - Boundary: from the function's `thumb_func_start FUNCNAME` line up to
     (not including) the next `thumb_func_start` line, or EOF.
   - Drop the first two lines of that block (`thumb_func_start FUNCNAME`
     and the `FUNCNAME: @ 0xADDR` label line) — a per-function `.inc` has
     no header, no `thumb_func_start`, no function label. It starts
     directly with the instruction body and keeps internal local labels,
     pool constants (`.4byte`), and the trailing `.align 2, 0` as-is.
   - Remove that same block (including the two header lines) from the
     source `.s` file.

3. **Add the NAKED stub** to the destination `.c` file (see "File &
   linker placement" for which file). If the file is new, its only
   include is `#include "global.h"` — matching existing precedent
   (`code_08230d30.c`, `code_0823b190.c`). Don't guess at additional
   headers for whatever types the signature needs.
   ```c
   NAKED <ret> FUNCNAME(<params>) { INCFUNC("asm/func/FUNCNAME.inc"); }
   ```

4. **`make compare`** — must print OK. The bytes are unchanged by
   construction, so a FAILED here means a mistake in placement,
   signature, symbol naming, or linker-script position — not a real
   codegen difference. Fix and retry rather than treating this like
   `/decomp-func`'s NON-MATCH loop. If the build itself fails to
   compile (e.g. a type from the signature isn't visible with only
   `global.h` included), don't guess at which extra header to add —
   report the failure and why to the user and let them decide.

## File & linker placement

- **Destination `.c` file name**: `code_<address of the FIRST function
  promoted from this .s file>.c`, lowercase hex — e.g. promoting
  `ReflectClock` (`0x08241F6C`) first out of `src/code_082418f0.s`
  creates `src/code_08241f6c.c`. This matches existing precedent in the
  repo (`src/code_08230d30.c`, `src/code_0823b190.c` are both named after
  the first function they contain).
- **Subsequent functions** promoted from the *same* `.s` file (still in
  address order) are appended to that *same* `.c` file — do not create a
  new file per function.
- **`ld_script.ld` insertion**: object order in the linker script is the
  *original link order*, not a numeric sort of the address in the
  filename — do not assume you can sort entries by name. When creating
  the destination `.c` file for the first time (i.e. promoting the first
  function out of a given `.s` file), insert
  `src/code_<new-addr>.o (.text);` **immediately before** the existing
  `src/code_<original>.o (.text);` line for that `.s` file. Because
  promotion always proceeds in address order and reuses the same `.c`
  file, this insertion happens exactly once per `.s` file — never move it
  again.
- **Makefile**: no changes needed. `ASM_SRCS`/`C_SRCS` are collected via
  `find src -name '*.s'` / `'*.c'` wildcards.
- **When a `.s` file becomes empty** (every function promoted out of it),
  delete the `.s` file and remove its now-dangling
  `src/code_*.o (.text);` line from `ld_script.ld`.
- **Cross-references need no bookkeeping.** A `bl OTHERFUNC` inside a
  function you're extracting keeps working unchanged even if `OTHERFUNC`
  is still sitting in the original `.s` file (or gets promoted later,
  before or after this one) — the linker resolves global symbols by name,
  not by which file defines them. Don't rewrite call instructions or
  worry about promotion order across *different* target symbols; the
  address-order rule is only about keeping the destination `.c` file name
  and linker-script insertion point sane, not about resolving calls.

## Validated

The full workflow (Steps 1-4, naming, linker insertion, empty-file
cleanup) has been exercised end-to-end on `src/code_082418f0.s`
(4 functions, address order), covering every branch of the design:

- a Ghidra-confirmed pointer return + pointer param (`UnkSolarEntity_Init`:
  `UnkSolarEntity* UnkSolarEntity_Init(UnkSolarEntity* p)`), cross-checked independently by
  the parameter being passed unchanged into an already-decompiled
  sibling call.
- a Ghidra-confirmed `void` (`clock_08241fd0`).
- a Ghidra-confirmed pointer return with no params (`UnkSolarEntity_Create`:
  `UnkSolarEntity* UnkSolarEntity_Create(void)`).
- the `UNK_PTR` discarded-return fallback (`ReflectClock`: epilogue
  `bx r1` proved a return value exists, but the only known caller
  discards it without reading `r0`).
- first-of-file insertion into `ld_script.ld`, three same-file appends
  with no further linker changes, and final `.s` deletion + line removal
  once the file emptied out.

`make compare` stayed OK after every individual promotion, not just at
the end.

## Scripts

None yet. Candidates for later, now that the workflow has a validated
reference run to mechanize against:

- a census script listing remaining TODO functions per `.s` file (name,
  address, size), the same way `decomp-func/scripts/census.py` does for
  NAKED/NON_MATCH.
- a splitter that mechanizes step 2 given a function name and source `.s`
  file (finds the `thumb_func_start` boundary, strips the header, writes
  the `.inc`, removes the block from the `.s`).

## Resources

None yet.
