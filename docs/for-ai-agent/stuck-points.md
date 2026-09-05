# Stuck points

A log of where `/decomp-func` got stuck on a function without reaching
MATCHING — not what worked (see `agbcc-quirks.md` /
`c-programmer-habits.md` for that), but where progress stalled and why.

**Why this exists:** a single stuck function might just be a hard function.
The same *kind* of stuck point recurring across multiple functions is a
different signal — it usually means something systemic (a missing idiom, a
tooling gap, a wrong struct layout) rather than bad luck on each individual
function. Check this file for a matching symptom before spending a fresh
round of manual iteration on a new function that looks similar.

**When to add an entry:** whenever a function is left at NON_MATCH/paused
without reaching a match — whether because the 10-iteration cap
(SKILL.md Step 7) was hit, or the user explicitly paused it. Not needed for
functions that end up MATCHING.

## Entry format

Just the function name (and file). No detail write-up.

## Log

- `VM_DecodeValue` (`src/vm.c`)
- `VM_MountScriptDirectory` (`src/vm.c`)
- `VM_ConvertEucJpToSjis` (`src/vm_ctrl1.c`)
- `FUN_08231698` (`src/vm.c`)
- `VM_Ctrl_Switch` (`src/vm_ctrl1.c`)
