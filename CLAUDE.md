# CLAUDE.md

This file provides guidelines for Claude Code when working in this repository.
This project's goal is a **matching decompile** of the GBA title *Zoku Bokura no Taiyou: Taiyou Shounen Django*.

NEVER PRINT YOUR OWN SCAFFOLDING TO THE CONSOLE — PLANS, STEP ANNOUNCEMENTS, RAW TOOL OUTPUT, VERIFICATION NARRATION. WRITE ONLY WHAT THE USER NEEDS TO READ.

---

## Project Overview

- **Target title**: Zoku Bokura no Taiyou: Taiyou Shounen Django (ID: `AGB-U32J-1`, the Japanese title corresponding to Boktai 2: Solar Boy Django)
- **Platform**: Game Boy Advance (ARM7TDMI, ARMv4T)
- **Goal**: Produce decompiled output that, when rebuilt, is **binary-identical** to the original ROM

---

## Validation

**Binary identity with the original ROM always takes priority.**

```sh
make compare -j$(nproc)
```

It passes only when the output contains the `boktai2.gba: OK` line. Read that line — do not infer a match from the command finishing.

When headers, linker scripts, data, build rules, shared declarations, or configuration changed, clean the build cache and rebuild.

```sh
make clean-code && make compare -j$(nproc)
```

---

## Function Decompilation Levels

Every function in this codebase is in one of four states:

1. **TODO** — only assembly exists; not even a C signature is defined.

2. **NAKED** — C signature defined, but no C implementation:
```c
NAKED void* VM_Ctrl_22FF(void) { INCFUNC("asm/func/VM_Ctrl_22FF.inc"); }
```

3. **NON_MATCH** — C implementation written, but it does not produce matching output:
```c
NON_MATCH void FUN_08242c08(slot32_t n) {
#ifdef NONMATCHING_C
  s32 i;
  FUN_08242b6c(n, &gWeaponDB[0]);
  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == n) {
      REGISTERED_WEAPON(i) = -1;
    }
  }
#else
  INCFUNC("asm/func/FUN_08242c08.inc");
#endif
}
```

4. **MATCHING** — C implementation written, and it produces byte-identical output.

Assembly for a not-yet-matching function lives in `asm/func/FUNCNAME.inc` (e.g. `FUN_08242c08` -> `asm/func/FUN_08242c08.inc`).

---
