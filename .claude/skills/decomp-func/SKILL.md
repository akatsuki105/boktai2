---
name: decomp-func
description: Decompile boktai2 function into C code that generates matching builds.
---

## The one rule

**Only the ROM proves a match.** A function is done when `make compare` prints the OK line for `boktai2.gba` (full-image SHA-1 against a verified retail dump). Compiling proves nothing about bytes; assembling nothing about layout; linking nothing about the image.

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
(`src/enemy_080ef84c.c`), and the glob above only when it really is the whole
repository.

Sort candidates by byte size (address delta between consecutive
`thumb_func_start` labels, or `arm-none-eabi-objdump` on the built
objects). Small functions teach the compiler's habits cheaply.

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
   than on a named field, which is the signal that the struct needs a new field
   before the function can be written.

   Add `--brief` to drop the offset table and the sibling list when that
   information is already in the conversation (working through one file
   function by function, for instance). `--no-ghidra` skips the Ghidra queries.

2. **Check siblings.** Before inventing anything, read a matched function with
   the same shape (same macros, same field access pattern). `context.ts` lists
   the ones in the same `.c` that call the same functions; widen it with a grep
   over `src/` when none of those fit. The repo's existing C *is* the idiom
   dictionary — most "mysterious" codegen (staged dead zeros, merged flag
   stores, shared constants) falls out of plain porter-style statements.

3. Claude proposes draft C code for the target function. The draft may not be perfect, but it should be a good starting point.

4. Modify src/*.c: Replace NAKED stubs / NON_MATCH #else INCFUNC blocks with Claude's C code (also remove NON_MATCH/#ifdef NONMATCHING_C wrappers)

```c
NAKED void* DecompTargetFunc(void) { INCFUNC("asm/xxx.inc"); }
// ↓
void* DecompTargetFunc(void) {
  // Claude's C code here
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
  // Claude's C code here
}
```

5. `make compare`
    -> prints OK: goto Step 8
    -> prints FAILED: goto Step 6

6. **On NON-MATCH, read the instruction-stream diff** — never the ROM bytes (pool offsets shift). The permuter score in (b) is a second opinion to reach for only when (a) leaves you unsure:

    a. **Instruction-stream diff (every iteration).** Diff your object against the original asm:
       `.claude/skills/decomp-func/scripts/streamdiff.py BUILT_OBJECT SYMBOL ORIGINAL_INC` (keep a copy of the original inc via `git show HEAD:asm/... > <scratchpad>/orig.inc` before truncating it).
       Every surviving hunk is a real codegen difference; pool offsets, branch targets, and spelling variants are masked.

    b. **Permuter score (only when (a) is inconclusive).** Each run is two commands and two compiles, so it is not worth paying on an iteration where the streamdiff already names the difference — which is most of them. Reach for it when:
       - the streamdiff hunks do not tell you *what kind* of difference you are looking at; or
       - the instruction counts are equal and the hunks look like nothing but renamed registers, and you want the penalty breakdown to confirm it is register allocation rather than scheduling; or
       - several iterations have gone by with no visible progress and you want a number to tell whether you are getting closer at all.

       Otherwise skip it and go straight to Step 7. Regenerate the per-function work dir from the CURRENT `src/*.c` content (this picks up whatever C you just wrote, permuter-authored or not) and score it, without running a full random search:
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

7. Claude sees the diff (and the score, when (b) was run) and proposes a fix. Go back to Step 3 (loop until match).
    [parallel] decomp-permuter can also be run in the background with a full random search to explore (see below) — separate from the `--debug` score check in Step 6b.
    Don't just let the background search run indefinitely hoping for score 0: launch it with `-j2 --stop-on-zero` (not more than `-j2` — higher pins all CPU cores and causes problems; `--stop-on-zero` makes it exit on its own the moment it finds a match instead of continuing to search past it). permuter.py has no time-based timeout flag, so still enforce the ~1 minute cap externally (a background timer + `pkill`) in case zero is never found — then stop it. If it hasn't found score 0 by then, take its best-scoring candidate (`nonmatchings/<dir>/output-<score>-*/source.c` under the perm dir) as feedback — read what structural/register-allocation change it made — and go back to Step 3 to write the next manual candidate informed by that, rather than treating the permuter as the final word or leaving it running unattended.
    **Stop condition.** When you start on a function, note the remaining token count shown in the conversation (`N tokens left`). Whenever it is visible again, check how much has been consumed since then. If more than **20,000 tokens** have been consumed, or the loop has reached 5 iterations, leave the best candidate so far as NON_MATCH and stop: put its C inside `#ifdef NONMATCHING_C`, restore the `INCFUNC` in `#else` (restore the `.inc` from git if it was deleted), and confirm `make compare` prints OK. The `NON_MATCH` marker in the source is the record that it stalled — nothing else needs writing down.
    Before checking siblings (Step 2) on a *different* function, count how many functions in that file are already NON_MATCH: `grep -c '^NON_MATCH' src/FILE.c`. Several stuck together in one file is a signal worth noticing — usually a wrong struct layout or a missing idiom rather than bad luck on each one.

8. `make && sha1sum -c boktai2.sha1` to verify the entire ROM matches
    `./tools/refresh-expected.sh` to update the `expected/` baseline
    Once MATCHING, the `asm/func/FUNCNAME.inc` is no longer referenced by any `INCFUNC` — confirm with `grep -rn "FUNCNAME.inc" src` (expect no hits) and delete it.
    Add a one-line Japanese comment directly above the function signature summarizing what it does, for human readers (e.g. `// リンクリストからノードを削除する`). Keep it to one line; skip it if an equivalent comment is already present, or if the function's behavior is self-evident from the code itself (e.g. a bare `return 0;`, or a standard `CreateEntity`/`SetEntityRoutine`/init-or-kill entity-creation function). Never write a comment that's just a literal restatement of the code (e.g. "reads pc[1..2] as a little-endian s16 and advances pc by 3" for code that visibly does exactly that) — describe the *meaning*/*purpose*, not the mechanics; if you don't know the meaning, skip the comment rather than paraphrasing the code.
    **Record the lever.** If reaching MATCHING took a non-obvious C shape — anything you would not have written on the first try, or that you only found by iterating on a streamdiff hunk — write it into `docs/for-ai-agent/agbcc-quirks.md` before moving on. Follow that file's own "New entry, or extend an existing one?" rule: route by the **asm symptom**, so when an entry already covers that symptom, append a bullet and add the function to its Frequency instead of opening a near-duplicate entry. This step is not optional bookkeeping — a lever that stays in the transcript is a lever the next session pays to rediscover.

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
- `microtest.sh` — single-file compile probe with the repo flags.
- `corpus-grep.sh` — search the 17-repo corpus for an asm shape (`-c` for C idioms). Grep the corpus BEFORE inventing a lever.

## Resources (read when you reach that phase)

In `resources/` next to this file:

- `decomp-corpus.md` — the 17-repo corpus list and search discipline.
- `fe8j-playbook.md` — what the fireemblem8j project's techniques transfer (same compiler family).

In `docs/for-ai-agent/` at the repo root (shared across skills):

- `matching-idiom.md` — the two oracles and decomp-permuter recipes (tooling/process).
- `agbcc-quirks.md` — compiler-level idioms (why a given C shape produces given bytes); read before inventing a lever, extend after discovering one.
- `c-programmer-habits.md` — original-developer style patterns (not compiler behavior); add an entry once a pattern is corroborated across multiple matched functions.
