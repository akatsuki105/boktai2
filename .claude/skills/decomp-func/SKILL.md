---
name: decomp-func
description: Decompile boktai2 function into C code that generates matching builds.
argument-hint: [function-name]
---

## The one rule

**Only the ROM proves a match.** A function is done when `make compare` prints the OK line for `boktai2.gba` (full-image SHA-1 against a verified retail dump). Compiling proves nothing about bytes; assembling nothing about layout; linking nothing about the image.

Two things follow from that, and they are what this skill is really about:

- **Write code that produces the same machine code — not code that merely "works."** A correct C rendering of the function that assembles differently is a failed attempt, not a partial success.
- **Learn the compiler's habits and write to them deliberately.** agbcc has behaviour that plain C does not reveal. The lever that makes a function match is usually a property of the compiler, not of the algorithm — which is why `docs/for-ai-agent/agbcc-internals.md` (why a pass decides what it decides) and `agbcc-levers.md` (what to try, in what order) are read before inventing one.

Neither licenses unnatural C. The original was written by a person, so a shape you would not defend to a colleague is more likely a wrong guess about the compiler than a discovery about it.

## Picking a target

See CLAUDE.md's "Function Decompilation Levels" for the 4-level vocabulary
(TODO / NAKED / NON_MATCH / MATCHING). Only functions at the NAKED or
NON_MATCH level can be targets.

**If the user names a specific function** (passed as an argument to this
skill), that function is the target — do not run `census.ts` or pick
anything else. First confirm it's actually at the NAKED or NON_MATCH level:

```sh
grep -n "^\(NAKED\|NON_MATCH\)\b.*\b<FUNCTION_NAME>\s*(" src/*.c
```

- A match found → proceed to the decompile workflow with that function.
- No match (function doesn't exist, is TODO with no C signature, or is
  already MATCHING) → **stop immediately**, do nothing else, and tell the
  user the function isn't a valid NAKED/NON_MATCH target. Do not fall back
  to picking a different target on your own.

**Otherwise**, list all NAKED/NON_MATCH functions and work smallest-first:

```sh
# list the NAKED / NON_MATCH functions in those files, sorted by size
.claude/skills/decomp-func/scripts/census.ts src/**/*.c   # TSV: size  level  name  inc
```

The `.c` paths are required — pass only the files the request is about
(`src/enedefault.c`), and the glob above only when it really is the whole
repository.

`census.ts` already reports each candidate's byte size; take them
smallest-first. Small functions teach the compiler's habits cheaply.

**Prefer NAKED over NON_MATCH when picking automatically.** `census.ts`'s
`level` column says which is which. A NON_MATCH function is by definition one
that somebody already wrote C for and failed to match, so it is a retry, not a
fresh target — take the smallest NAKED candidate first and only fall through to
NON_MATCH when the request leaves nothing else. This ordering applies to
auto-picked targets only; if the user explicitly names a NON_MATCH function as
the argument, that is a deliberate retry and should proceed normally.

Also skip a candidate whose `asm/func/FUNCNAME.inc` still contains raw
`.byte` data instead of proper mnemonics (a disassembler failure, not a
real target — `census.ts`'s reported size is unreliable for these, since
it's counting garbled data). Check with a quick
`grep -l '\.byte' asm/func/FUNCNAME.inc`; if it hits, this isn't a normal
decompile task (the `.inc` itself needs to be regenerated with a proper
disassembly first, which is out of scope for this skill) — move to the
next-smallest candidate instead of trying to work around it inline. This
skip applies to auto-picked targets only, same as the NAKED/NON_MATCH
ordering above.

## The decompile workflow

1. **Read the context.** The function name is enough — the `.c` is found by
   searching `src/`, and the assembly defaults to `asm/func/<name>.inc`.

```sh
.claude/skills/decomp-func/scripts/context.ts <FUNCTION_NAME>
```

   It prints the assembly (instructions and pool split apart, with
   `=0x030xxxxx` pool constants resolved against the `iwram`/`ewram`
   declarations), the repo's own signature line, a typed decompile from Ghidra
   when it is running (m2c is only the fallback), every offset the assembly
   touches mapped onto the struct declarations in `include/`, the declaration
   of each `bl` target, and — for a NON_MATCH — the current C.

   The offset table is the part that saves the most work: it resolves
   `[rN, #0x28]`, `=0x0000046D` and the `movs`/`lsls` pairs that build a large
   offset, and says `(+4)` when the offset lands inside an `unk_` blob rather
   than on a named field.

   **A `(+4)` is a fork, not a footnote.** The struct is missing the field this
   function uses, so the C cannot be written yet. Settle the layout first —
   `/ghidra-struct <Type>` if the type needs a real pass, or a single field
   split out of the `unk_` blob when the evidence is already in front of you.
   That edits a header, so the next build needs `make clean-code` and it can
   break a `static_assert` or another function. Do not guess a field and draft
   around it; a wrong layout is the usual reason several functions in one file
   are all stuck (step 2).

   Add `--brief` to drop the offset table and the sibling list when that
   information is already in the conversation (working through one file
   function by function, for instance). `--no-ghidra` skips the Ghidra queries.

   **Then check the target is reachable from C at all**, before spending any
   iterations on it. agbcc emits neither of these, so their presence means the
   function is hand-written assembly and no C will reproduce it:

```sh
grep -nE '^[[:space:]]*tst\b' asm/func/<FUNCTION_NAME>.inc          # cannot be emitted
grep -nE '^[[:space:]]*(subs|adds|ands|orrs|eors)\b' asm/func/<FUNCTION_NAME>.inc
```

   The second grep is only a prompt to look: a flag-setting instruction is fine
   on its own, but a conditional branch that uses its result with **no `cmp` in
   between** is not something this compiler produces. ARM-mode functions are
   likewise out of scope (they belong to `sprite_main_arm.c` or
   `lib/librfu_intr.c`); a `.inc` whose prologue is `mov ip, sp` / `push {...,
   pc}` is ARM, not Thumb. Also check for raw `.byte` data — a disassembler
   failure, not a target.

   On a hit, stop and tell the user which signal fired. Do not start the loop.
   See `docs/for-ai-agent/agbcc-levers.md` §1.

2. **Check siblings, and check whether the file is already stuck.**

```sh
grep -c '^NON_MATCH' src/FILE.c
```

   Several functions stuck in one file is a property of the file, not luck on
   each one — usually a wrong struct layout or a missing idiom. When the count
   is high, settling the struct (step 1's fork) is worth more than drafting the
   next function, because the ones already NON_MATCH often fall out with it.
   Ask the user before switching the target.

   Then read a matched function with the same shape (same macros, same field
   access pattern) before inventing anything. `context.ts` lists the ones in the
   same `.c` that call the same functions; widen it with a grep over `src/` when
   none of those fit. The repo's existing C *is* the idiom dictionary — most
   "mysterious" codegen (staged dead zeros, merged flag stores, shared
   constants) falls out of plain porter-style statements.

3. **Write the C into `src/*.c`**, replacing the `NAKED` stub or the NON_MATCH `#else INCFUNC` block, and removing the `NON_MATCH` marker and the `#ifdef NONMATCHING_C` wrapper with it. The draft need not be perfect — the streamdiff loop below is what sharpens it.

```c
NAKED void* DecompTargetFunc(void) { INCFUNC("asm/xxx.inc"); }
// ↓
void* DecompTargetFunc(void) {
  // the draft goes here
}

NON_MATCH void* DecompTargetFunc(void) {
#ifdef NONMATCHING_C
  // previously written C code here (non-matching)
#else
  INCFUNC("asm/xxx.inc");
#endif
}
// ↓
void* DecompTargetFunc(void) {
  // the draft goes here
}
```

4. **Build.** `make compare`, or `make clean-code && make compare` when the work also touched `include/` or anything else shared — a stale object file will happily report a match that isn't there.
    -> the output contains the `boktai2.gba: OK` line: goto Step 6
    -> it does not: goto Step 5

5. **On NON-MATCH, take the instruction-stream diff and classify it** — never the ROM bytes (pool offsets shift). **State which iteration this is against the budget** ("2 回目 / 5", the budget from `context.ts`) before anything else; the stop condition counts these and nothing else counts them for you.

    a. **Instruction-stream diff (every iteration).** Diff your object against the original asm:
       `.claude/skills/decomp-func/scripts/streamdiff.py BUILT_OBJECT SYMBOL ORIGINAL_INC` (keep a copy of the original inc via `git show HEAD:asm/... > <scratchpad>/orig.inc` before truncating it).
       Spelling variants, label/symbol spelling, pool offsets and immediate radix are masked, so every surviving hunk is a real codegen difference. **Branch targets are not masked** — an in-function target becomes a signed instruction-index delta (`beq ~+7`), so a branch landing on the wrong block shows up as a hunk rather than hiding behind a matching label.
       **Zero hunks is not a match.** Pool *values* and references that leave the function still differ underneath the masking. Measured on this repo: of the five NON_MATCH functions that streamdiff reported as identical, one matched the ROM and four did not. Only step 4 decides.
       **Diffing a NON_MATCH function means `make clean-code` first.** Its C only exists in the object when the build defines `NONMATCHING_C`, and `make` does not treat `EXTRA_CPPFLAGS` as a dependency: run `make EXTRA_CPPFLAGS=-DNONMATCHING_C` right after a normal build and the untouched objects are reused, so the function is still compiled from its `INCFUNC` — the original assembly against itself. That reports "stream identical" and any `objdump` you take is the target, not your C. Always
       `make clean-code && make EXTRA_CPPFLAGS=-DNONMATCHING_C`, or let `residual.ts` do it. Seen on seven functions in one session, three of which got a wrong instruction count written into their residual note.
       Two readings that save time:
       - A residual whose **only** difference is a trailing `.word <abs>` against `.word .rodata` is a real match. Those are table relocations the linker resolves.
       - When `make compare` reports a huge diff starting early in the ROM, the function's **size** changed and everything after it shifted; the body is probably fine. `Entity080abd14_Create` and `Entity080ac374_Create` both did this — an over-narrow parameter type (`u16` where the target takes `u32`) expands to `lsls`/`lsrs` at entry, keeps one more register live, and adds it to the push/pop pair. streamdiff normalises the stream, so it does not show a prologue register count as a hunk.

    b. **Classify the residual.** This picks the next move, so do it explicitly instead of jumping to a guess:

       - **different opcodes, or a different number of them** → a shape problem. Enter `docs/for-ai-agent/agbcc-levers.md` at tier A (control flow and expression shape), then B (types and signedness).
       - **same opcodes in the same order, different registers or spill slots** → an allocation problem. Enter at tier C (order), after reading `agbcc-internals.md` §4 — the three inputs to the priority formula are the only things that move it.

       Before either, rule out the cheap causes in `agbcc-levers.md` §0: a wrong field width or signedness (the load mnemonic is the oracle and a cast cannot override it), a wrong prototype, a wrong `sizeof`. Most near misses are one of those, and no lever fixes them.

    c. **Permuter score (only when (a) and (b) leave you unsure).** Each run is two commands and two compiles, so it is not worth paying on an iteration where the streamdiff already names the difference — which is most of them. Reach for it when:
       - the streamdiff hunks do not tell you *what kind* of difference you are looking at; or
       - the instruction counts are equal and the hunks look like nothing but renamed registers, and you want the penalty breakdown to confirm it is register allocation rather than scheduling; or
       - several iterations have gone by with no visible progress and you want a number to tell whether you are getting closer at all.

       Otherwise skip it. Regenerate the per-function work dir from the CURRENT `src/*.c` content (this picks up whatever C you just wrote, permuter-authored or not) and score it, without running a full random search:
       ```sh
       tools/permuter/setup.sh <FUNCTION_NAME> <SRC_FILE>
       (cd tmp && "$DECOMP_PERMUTER/permuter.py" /tmp/perm_<FUNCTION_NAME> --debug)
       ```
       `--debug` writes a debug copy of the candidate source to
       `./debug_source.c` (decomp-permuter's own hardcoded relative path) —
       run it from the repo's `tmp/` directory (as above) so that file
       lands there instead of cluttering the repo root; it's safe to leave
       or delete afterward.
       `--debug` only compiles and scores the current candidate (no search). Score 0 == instruction-stream match by the permuter's own metric; the penalty breakdown (stack/branch/regalloc/reordering/insertion/deletion) tells you what kind of difference dominates. Still not the ROM gate — treat it as a second, quantitative opinion alongside (a).

       **Do not run a random search.** `--debug` scores the candidate already in `src/*.c` and exits; that is the only permuter use this project has. The search was retired: FE8J burned 1.3M iterations on one 852-byte function without beating its base score and 7k on a 128-byte one for a 5-point gain, and concluded the reorderings agbcc needs are not in the permuter's transformation space. Our own experience matches. A stalled function goes to `agbcc-levers.md`, not to a search.

    Then apply the lever the classification points at and go back to step 3.

6. **Finish up.** The `make compare` from step 4 already ran `sha1sum -c` over the whole image and refreshed the `expected/` baseline, so there is nothing more to build.
    Once MATCHING, the `asm/func/FUNCNAME.inc` is no longer referenced by any `INCFUNC` — confirm with `grep -rn "FUNCNAME.inc" src` (expect no hits) and delete it.
    Add a one-line Japanese comment directly above the function signature summarizing what it does, for human readers (e.g. `// リンクリストからノードを削除する`). Keep it to one line; skip it if an equivalent comment is already present, or if the function's behavior is self-evident from the code itself (e.g. a bare `return 0;`, or a standard `CreateEntity`/`SetEntityRoutine`/init-or-kill entity-creation function). Never write a comment that's just a literal restatement of the code (e.g. "reads pc[1..2] as a little-endian s16 and advances pc by 3" for code that visibly does exactly that) — describe the *meaning*/*purpose*, not the mechanics; if you don't know the meaning, skip the comment rather than paraphrasing the code.
    **Do not write up the lever.** The matched C is committed in `src/` and the diff that closed it is in git; that is the record. The one exception is an explanation of *why* the compiler behaves that way, which goes in `agbcc-internals.md` and only with the compiler source file and line that proves it — if you cannot point at the code, it does not get written anywhere.

## Stopping

**The budget scales with the target's size.** `context.ts` prints it on its own first line (`asm/func/FUN_08066d2c.inc (78 バイト, 予算: 3 反復 / 6000 トークン)`), so it is decided and on screen before the first iteration:

| size | iterations | tokens |
|---|---|---|
| ≤ 100 bytes | 3 | 6,000 |
| 101 – 350 bytes | 5 | 20,000 |
| > 350 bytes | 7 | 40,000 |

The thresholds are the quartiles of what is left in the repo (p25 = 98, p75 = 332 bytes over 2452 functions), and `census.ts`'s `size` column is the same measure. A flat count fits neither end: on a 20-byte function the residual has one cause, so two levers exhaust it, while a 600-byte function stacks several independent residuals and each iteration can only close one.

Stop at that iteration count and keep whichever candidate is best. Step 5 states the iteration number against the budget, so the count is on screen rather than remembered. The token figure is the secondary rule — apply it only when the remaining count (`N tokens left`) happens to be visible, because it is not always on screen and resets across a compaction.

Leave the best candidate as NON_MATCH: its C inside `#ifdef NONMATCHING_C`, the `INCFUNC` restored in `#else` (restore the `.inc` from git if it was deleted), and `make compare` printing OK.

**Write one line above the `#ifdef` saying how far you got** — the residual in one phrase, and which tiers of `agbcc-levers.md` you actually exhausted:

```c
// 残差はr4/r5の入れ替えのみ, Tier A-C は試済, 未: per-TU フラグ
```

Without it the next session cannot tell "nobody tried hard" from "the cheap tiers are used up", and spends its whole budget repeating them. Stopping is a budget decision, never a proof that no C exists — that distinction is `agbcc-levers.md` §7.

`scripts/residual.ts` measures every NON_MATCH function in the repo at once, so use it rather than re-deriving how close a stalled function is.

## Scripts

All in `.claude/skills/decomp-func/scripts/`. Run them from the repo root,
spelling that path out in full — there is no `scripts/` directory at the repo
root, so a bare `scripts/context.ts` just fails with "no such file or
directory":

`rm` and `cp` are interactive here, which matters because this workflow deletes
the `.inc` on a match and shuffles candidate sources around. Use `rm -f` /
`cp -f`: without the flag they stop on a confirmation prompt that never gets an
answer, so the call hangs and every later command in the same invocation is
silently skipped — including the `make compare` you were relying on.

- `context.ts <FUNCTION_NAME> [SRC_FILE] [ASM_FILE]` — the assembly, the repo
  signature, a Ghidra decompile, the asm offsets mapped onto the struct
  declarations, the `bl` targets' declarations, and the current C.
  `--brief` / `--no-ghidra` trim it.
- `census.ts <file.c>...` — remaining-function census over the given `.c` files, smallest-first TSV with sizes and inc paths.
- `streamdiff.py` — canonicalized instruction diff, object vs inc.
- `residual.ts [file.c...]` — build with `-DNONMATCHING_C` and report every NON_MATCH function's hunk count, smallest-first. Cleans `build/` before and after, so its numbers are the trustworthy ones and the next build starts over.

## Resources (read when you reach that phase)

In `docs/for-ai-agent/` at the repo root (shared across skills):

- `agbcc-levers.md` — what to try when a function nearly matches, in order. The main one: step 5 routes into it.
- `agbcc-internals.md` — why a compiler pass decides what it decides, with the source line for every rule. Read it to work out *which* lever exists; extend it only with a quotation.
- `c-programmer-habits.md` — original-developer style patterns (not compiler behavior); add an entry once a pattern is corroborated across multiple matched functions.
