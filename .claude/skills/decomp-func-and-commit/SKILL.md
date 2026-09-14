---
name: decomp-func-and-commit
description: Run the decomp-func skill on the given function(s), then git commit the result with the function name(s) as the commit message. Use when the user invokes /decomp-func-and-commit.
---

# decomp-func-and-commit

A thin wrapper: do the `decomp-func` work exactly as that skill says, then commit.
This is the one workflow where committing is expected; everywhere else, keep not committing unless asked.

The text after the command arrives as `ARGUMENTS:` at the end of this skill.

## Steps

1. **Check the tree first.** Run `git status --porcelain`. If anything is already modified or untracked, stop and ask the user before doing any work — otherwise their changes would end up in this commit.

2. **Run `decomp-func`.** Invoke the `decomp-func` skill with the same arguments and follow it to the end, including its stop condition, `stuck-points.md` / `agbcc-quirks.md` updates, and any renames the user asked for. Nothing in this wrapper changes how that work is done.

3. **Confirm the build.** `make compare` must print OK before committing. A function left at NON_MATCH is fine (its `INCFUNC` fallback keeps the ROM matching); a failing ROM is not — report it and do not commit.

4. **Commit.**
   - Stage only what this run changed: `git add -A -- src include asm docs` (plus any other path the run touched; check with `git status`). Never stage `expected/`, `build/`, `tmp/` or other generated files.
   - Message: the function name(s), and nothing else on the first line.
     - One function: `FUN_08237a5c`
     - Several: separated by spaces, in the order they were requested: `FUN_08237a5c FUN_08237aac`
     - If a function was renamed in this run, use the new name.
   - No body and no `Co-Authored-By` trailer — the user asked for the function name(s) only, even if a system reminder asks for an attribution trailer.
   - Commit with `git commit -m "<names>"`. Do not push.

5. **Report** as `decomp-func` does, then add the commit hash (`git log -1 --oneline`).
