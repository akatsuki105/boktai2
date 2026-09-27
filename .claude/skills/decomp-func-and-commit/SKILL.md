---
name: decomp-func-and-commit
description: Run the decomp-func skill on the given function(s), committing each function as soon as it is finished with its name as the commit message. Use when the user invokes /decomp-func-and-commit.
argument-hint: [function-name...]
---

# decomp-func-and-commit

A thin wrapper: do the `decomp-func` work exactly as that skill says, then commit.
This is the one workflow where committing is expected; everywhere else, keep not committing unless asked.

The text after the command arrives as `ARGUMENTS:` at the end of this skill.

## Steps

1. **Check the tree first.** Run `git status --porcelain`. If anything is already modified or untracked, stop and ask the user before doing any work — otherwise their changes would end up in this commit.

2. **One function at a time.** With several functions in the arguments, take them in the order given and run steps 3–5 for each before starting the next, so every function gets its own commit. Do not batch several functions into one commit.

3. **Run `decomp-func`** on that one function and follow it to the end, including its stop condition, `agbcc-quirks.md` updates, and any renames the user asked for. Nothing in this wrapper changes how that work is done.

4. **Confirm the build.** Run `make compare`, or `make clean-code && make compare` when the work touched `include/` or anything else shared — a stale object file will happily report a match that isn't there. The output must contain the `boktai2.gba: OK` line; read that line rather than inferring a match from the command finishing. A function left at NON_MATCH is fine (its `INCFUNC` fallback keeps the ROM matching); a failing ROM is not — report it, do not commit, and stop there instead of moving on to the next function.

5. **Commit and push** by following the `git-push` skill, with two things fixed here:
   - **The message is that function's name and nothing else**, e.g. `FUN_08237a5c`. If it was renamed during the work, use the new name. No body.
   - Step 2 of `git-push` (confirming the ROM) is already done in step 4 above, so do not rebuild.

   Push each function's commit as soon as it is made, so that stopping partway still leaves the finished work on the remote. An `--amend` that folds a late edit into a commit already pushed would need a force-push, so make sure everything for that function — `docs/` updates included — is in the commit before pushing it.

6. **Report** as `decomp-func` does, once all functions are done, listing each function with its commit hash (`git log --oneline -N`).
