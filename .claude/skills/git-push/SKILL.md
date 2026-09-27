---
name: git-push
description: Commit the current working tree and push it, the way this repository expects — verify the ROM still matches, stage only hand-written sources, write a one-line Japanese message, and push. Use when the user says /git-push, 「コミットしてpush」, 「pushして」 or otherwise asks for the current work to be committed and/or pushed.
argument-hint: [commit-message]
---

# git-push

The user's standing request 「コミットしてpush」 in one place. Everything here is
a rule that was learned the hard way — none of it is ceremony.

The text after the command arrives as `ARGUMENTS:` at the end of this skill. If
it is a commit message, use it verbatim. If it is empty, write the message
yourself from the diff (see **The message**).

## Steps

1. **Look at what is actually there.** `git status --porcelain` and
   `git diff --stat HEAD`. Commit what the tree holds; do not start new work,
   and do not "tidy up" files the user did not touch.

   If the tree also holds changes from something unrelated to the work just
   done, say so and ask before folding them into one commit. The user's own
   edits are not yours to commit silently.

2. **Confirm the ROM** — whenever `src/`, `include/`, `asm/`, `data/`,
   `ld_script.ld` or the build tooling changed:

   ```sh
   make clean-code && make compare
   ```

   It must print the `boktai2.gba: OK` line — read that line, do not infer a
   match from the command finishing. **A failing ROM is never committed** —
   report it and stop.
   `clean-code` is not optional: a stale object file will happily report a
   match that isn't there. Skip step 2 entirely when the change touches only
   `docs/`, `.claude/`, `README` and the like — there is no ROM to break.

3. **Stage.** `git add -A -- src include asm docs data` plus every other path
   `git status` showed (`.claude`, `include`, `tools`, `ld_script.ld` — a
   rename reaches `data/*.inc`). Never stage `build/` or `tmp/` (`expected/` is already gitignored).

4. **Commit — in a separate tool call from the `git add`.** The clang-format
   hook runs on the `git commit` call and inspects what is staged; putting both
   in one Bash invocation makes the hook fire before the `add` has run, so the
   formatting is silently skipped.

   ```sh
   git commit -q -m "<メッセージ>"
   ```

5. **Push.** A bare `git push` is enough. If it is rejected, **stop and tell the
   user**. Never force-push and never rewrite history — not to make a push go
   through, not to fold in a late edit, not for anything.

6. **Report** the hash (`git log --oneline -1`) in one line, and that the ROM
   check passed when step 2 ran.

## The message

- **One line, in Japanese, no body.** `Entity56DC のレイアウトを埋める`,
  `FUN_08237a5c`, `ghidra-struct: 共有する型はヘッダに出す旨を追記`.
- Say what changed, read from the diff — not what the user asked for, and not
  a restatement of the file names. When a single decompiled function is the
  change, its name alone is the message.
- One commit per logical change. If the tree holds several finished functions
  or several struct types, commit them one at a time rather than lumping them
  into one message that names none of them.

## Pitfalls seen in practice

- `git add` and `git commit` in the **same** Bash call: the format hook sees an
  empty index and passes. This has already let an unformatted file through once.
- Reporting "pushed" from a `git push` whose output was swallowed by a pipe.
  Print `git log --oneline -1` afterwards and read it.
- `rm` and `cp` are interactive here — use `rm -f` / `cp -f`. Without the flag
  they block on a prompt that never gets an answer, and every later command in
  the same invocation is silently skipped, including the `make compare`.
