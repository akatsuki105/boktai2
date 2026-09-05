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
skill), that function is the target — do not run `census.py` or pick
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
# list all NAKED or NON_MATCH functions, sorted by size
scripts/census.py          # TSV: size  name  inc
```

Sort candidates by byte size (address delta between consecutive
`thumb_func_start` labels, or `arm-none-eabi-objdump` on the built
objects). Small functions teach the compiler's habits cheaply.

Before committing to the smallest candidate, check whether its name
already has an entry in `docs/for-ai-agent/stuck-points.md`
(a prior session got stuck on it and paused/left it NON_MATCH). If it
does, skip it and move to the next-smallest candidate, repeating until you
reach one with no stuck-points.md entry — don't re-attempt a recently
stuck function automatically just because it sorts first. This skip only
applies to auto-picked targets; if the user explicitly names a stuck
function as the argument, that's a deliberate retry and should proceed
normally.

Also skip a candidate whose `asm/func/FUNCNAME.inc` still contains raw
`.byte` data instead of proper mnemonics (a disassembler failure, not a
real target — `census.py`'s reported size is unreliable for these, since
it's counting garbled data). Check with a quick
`grep -l '\.byte' asm/func/FUNCNAME.inc`; if it hits, this isn't a normal
decompile task (the `.inc` itself needs to be regenerated with a proper
disassembly first, which is out of scope for this skill) — move to the
next-smallest candidate instead of trying to work around it inline. This
skip applies to auto-picked targets only, same as the stuck-points skip
above.

## The decompile workflow

1. **Read the context.** Context includes the target assembly, current C implementation.

```sh
# e.g. e.g. scripts/context.py FUN_08242b88 src/weapon.c asm/func/FUN_08242b88.inc
scripts/context.py <FUNCTION_NAME> <SRC_FILE> <ASM_FILE>
```

2. **Check siblings.** Before inventing anything, grep `src/` for a
   matched function with the same shape (same macros, same field access
   pattern). The repo's existing C *is* the idiom dictionary — most
   "mysterious" codegen (staged dead zeros, merged flag stores, shared
   constants) falls out of plain porter-style statements.

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

6. **On NON-MATCH, gather two independent signals** — never the ROM bytes (pool offsets shift):

    a. **Instruction-stream diff.** Diff your object against the original asm:
       `scripts/streamdiff.py BUILT_OBJECT SYMBOL ORIGINAL_INC` (keep a copy of the original inc via `git show HEAD:asm/... > /tmp/orig.inc` before truncating it).
       Every surviving hunk is a real codegen difference; pool offsets, branch targets, and spelling variants are masked.

    b. **Permuter score.** Regenerate the per-function work dir from the CURRENT `src/*.c` content (this picks up whatever C you just wrote, permuter-authored or not) and score it, without running a full random search:
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

7. Claude sees the diff and the score and proposes a fix. Go back to Step 3 (loop until match).
    [parallel] decomp-permuter can also be run in the background with a full random search to explore (see below) — separate from the `--debug` score check in Step 6b.
    Don't just let the background search run indefinitely hoping for score 0: launch it with `-j2 --stop-on-zero` (not more than `-j2` — higher pins all CPU cores and causes problems; `--stop-on-zero` makes it exit on its own the moment it finds a match instead of continuing to search past it). permuter.py has no time-based timeout flag, so still enforce the ~2 minute cap externally (a background timer + `pkill`) in case zero is never found — then stop it. If it hasn't found score 0 by then, take its best-scoring candidate (`nonmatchings/<dir>/output-<score>-*/source.c` under the perm dir) as feedback — read what structural/register-allocation change it made — and go back to Step 3 to write the next manual candidate informed by that, rather than treating the permuter as the final word or leaving it running unattended.
    If the iteration loop doesn't finish after 10 iterations, pause and prompt the user for instructions.
    Before checking siblings (Step 2) on a *different* function, check `docs/for-ai-agent/stuck-points.md` — the same function name showing up repeatedly, or several functions stuck in the same area, is a signal worth noticing.

8. `make && sha1sum -c boktai2.sha1` to verify the entire ROM matches
    `./tools/refresh-expected.sh` to update the `expected/` baseline
    Once MATCHING, the `asm/func/FUNCNAME.inc` is no longer referenced by any `INCFUNC` — confirm with `grep -rn "FUNCNAME.inc" src/*.c` (expect no hits) and delete it.
    Add a one-line Japanese comment directly above the function signature summarizing what it does, for human readers (e.g. `// リンクリストからノードを削除する`). Keep it to one line; skip it if an equivalent comment is already present, or if the function's behavior is self-evident from the code itself (e.g. a bare `return 0;`, or a standard `CreateEntity`/`SetEntityRoutine`/init-or-kill entity-creation function). Never write a comment that's just a literal restatement of the code (e.g. "reads pc[1..2] as a little-endian s16 and advances pc by 3" for code that visibly does exactly that) — describe the *meaning*/*purpose*, not the mechanics; if you don't know the meaning, skip the comment rather than paraphrasing the code.

## Leaving a function unmatched

Whenever a function is left at NON_MATCH without reaching MATCHING — the
10-iteration cap was hit, or the user paused it — add an entry to
`docs/for-ai-agent/stuck-points.md` (format described there) before ending
the session on that function. Not needed when it ends up MATCHING.

## Scripts

All in `scripts/` next to this file (run from the repo root):

- `context.py` — prints the target assembly, current C implementation.
- `census.py` — remaining-function census, smallest-first TSV with sizes and inc paths; excludes NON_MATCH/NAKED/INCFUNC dual-forms.
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
- `stuck-points.md` — log of where past functions got stuck without reaching MATCHING; check for a recurring symptom before a fresh manual iteration round on a similar-looking function, and add an entry whenever leaving a function at NON_MATCH.
