---
name: decomp-func-and-commit
description: Run the decomp-func skill on the given function(s), committing each function as soon as it is finished, with `MATCHING: <name>` or `NON_MATCH: <name>` as the commit message. Use when the user invokes /decomp-func-and-commit.
argument-hint: [function-name...]
---

# decomp-func-and-commit

A thin wrapper: do the `decomp-func` work exactly as that skill says, then commit.
This is the one workflow where committing is expected; everywhere else, keep not committing unless asked.

The text after the command arrives as `ARGUMENTS:` at the end of this skill.

## Steps

1. **Check the tree first.** Run `git status --porcelain`. If anything is already modified or untracked, stop and ask the user before doing any work. `tools/git_push.sh` stages with `git add -A`, so anything sitting in the tree lands in this function's commit whether it belongs there or not.

2. **One function at a time.** With several functions in the arguments, take them in the order given and run steps 3–4 for each before starting the next, so every function gets its own commit. Do not batch several functions into one commit.

3. **Run `decomp-func`** on that one function and follow it to the end, including its stop condition and any renames the user asked for. Nothing in this wrapper changes how that work is done.

   **It can end without producing a commit.** `decomp-func` stops before the loop when the target turns out to be hand-written assembly, when `context.ts` reports a `(+4)` and the struct has to be settled first, or when too many functions in that file are already NON_MATCH and it asks whether to switch target. None of those touch `src/`. When that happens, skip step 4 for this function — `tools/git_push.sh` would exit with `コミットするものがありません` — say why in the report, and move on to the next function.

4. **Commit and push.**

   ```sh
   tools/git_push.sh "MATCHING: FUN_08237a5c"    # 一致した
   tools/git_push.sh "NON_MATCH: FUN_08237a5c"   # 一致せず NON_MATCH で残した
   ```

   The message is the level the function ended at, then its name — nothing else. `MATCHING:` when `make compare` accepted the C, `NON_MATCH:` when the loop hit its stop condition and the best candidate went back behind `#ifdef NONMATCHING_C`. If the function was renamed during the work, use the new name. The script re-runs `make clean-code && make compare` and refuses to commit unless the ROM matches — if it refuses, report that and stop there rather than moving on to the next function. A function left at NON_MATCH is fine: its `INCFUNC` fallback keeps the ROM matching.

   Push each function's commit as soon as it is made, so that stopping partway still leaves the finished work on the remote. An `--amend` that folds a late edit into a commit already pushed would need a force-push, so make sure everything for that function — any `agbcc-internals.md` entry included — is in the commit before running the script.

   The script runs a full `make clean-code && make compare` every time, so N functions means N clean rebuilds. That is deliberate (the script's own header explains why) but it is the reason a long argument list takes a long time.

5. **Report** once all functions are done: one line per function with its level and commit hash (`git log --oneline -N`), plus the reason for any function that produced no commit. Do not narrate the iterations and do not paste the matched C — the source is in the commit.
