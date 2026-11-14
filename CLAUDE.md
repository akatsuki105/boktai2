# CLAUDE.md

This file provides guidelines for Claude Code when working in this repository.
This project's goal is a **matching decompile** of the GBA title *Zoku Bokura no Taiyou: Taiyou Shounen Django*.

NEVER PRINT YOUR OWN SCAFFOLDING TO THE CONSOLE — PLANS, STEP ANNOUNCEMENTS, RAW TOOL OUTPUT, VERIFICATION NARRATION. WRITE ONLY WHAT THE USER NEEDS TO READ.

FINISH WHAT YOU WERE ASKED TO DO. Do not stop partway, cut the scope, or defer the rest on your own judgment. Stop early only for a reason you can name: a skill's iteration budget is spent, the build is broken, or a decision is genuinely the user's. Other queued work, and your own guess that the remaining effort will not pay off, are not reasons.

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
NAKED s32 VM_Ctrl_Mesg(void) { INCFUNC("asm/func/VM_Ctrl_Mesg.inc"); }
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

## C Code Style

- Refer to existing code and follow its conventions.
- Write comments in Japanese, but use commas `,` instead of sentence-ending punctuation `。`

---

## Asset Viewer CLI (bokmagic)

`deno task asset` runs the bokmagic CLI (published from the separate bokmagic-web repository at https://akatsuki105.github.io/bokmagic-web/bokmagic.js) on `baserom.gba`. It dumps ROM assets as JSON and PNG, so you can check what a sprite, tilemap or map actually looks like without a browser. Nothing is stored in this repository.

```sh
deno task asset list map                                                # list (sprite | aux | tilemap | map)
deno task asset sprite SPRITE_SHADEMAN --pose 3 -o /tmp/bokmagic/a.png  # MainSprite pose -> JSON + PNG
deno task asset aux SPRITE_EFF_1C1B --sheet -o /tmp/bokmagic/b.png      # all AuxSprite poses in one image
deno task asset tilemap TILEMAP_7DB3 -o /tmp/bokmagic/c.png             # tilemap (tiles taken from the map script if the file has none)
deno task asset map Script_0x02BF -o /tmp/bokmagic/d.png                # map composed from what the script loads
```

- Targets accept hex IDs or constant names from this repo (`SPRITE_*`, `TILEMAP_*`, `Script_*`)
- JSON goes to stdout; `-o` writes a PNG. Write PNGs under `/tmp/bokmagic/` (the task creates it), not under this repository's `tmp/`. Read the PNG to inspect it visually
- Options: `--scale`, `--pose`, `--sheet`, `--pltt`, `--xflip`/`--yflip`, `--layers`, `--part`, `--scene`, `--hide-bg`. Run without arguments for help
- Deno caches the script; add `--reload` once to pick up a newer version
- Constant names come from the headers at the time the tool was built; after renaming constants, ask for the tool to be rebuilt

---

## Script Interpreter CLI (bokvm)

`deno task bokvm` runs a script from `baserom.gba` on a TypeScript port of the VM (`tools/bokvm`, ported from `src/vm.c`, `src/vm_expr.c`, `src/vm_ctrl1.c` and `src/vm_ctrl2.c`). It prints each executed statement in `.bokc` spelling, which branch was taken, script calls and their return values, and every write to variables and `stat` / `world` / `scratch`, then a summary of the memory that changed. Use it to see what a script actually does, or how a command gets called and with which named arguments, instead of tracing `scripts.bokc` by hand.

```sh
deno task bokvm Scr_UseKey --args 65                    # script by script.h name, Scr_0xXXXX or ID; --args fills p0, p1, ...
deno task bokvm Scr_st00_00 -q                          # -q: hide statements, keep calls, commands, writes and events
deno task bokvm Scr_UseKey --ret Cmd_HasItem=1          # return value of a command that is not ported (default 0)
deno task bokvm Scr_UseKey --overlay my.bokc            # scripts defined in my.bokc replace the ROM's (goes through cpp)
```

- Only a few commands are ported (`tools/bokvm/commands/`); the rest log their call and return 0, so branches after them may differ from the game
- Control instructions that act on the game (LoadMap, trap, Mesg, ...) read their arguments like the C does and only log them
- `src/vm.c` is the source of truth for VM behavior; bokvm copies it, so fix bokvm when they disagree

