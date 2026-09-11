# Original C programmer habits

Unlike `agbcc-quirks.md` (what the *compiler* does to any equivalent C —
deterministic, true every time), this file is about what the *original
developers* tended to write: their style, when there's a choice of several
C shapes that all compile to the same bytes. This is statistical, not
deterministic, so **frequency is the whole point** — a habit seen once is
a coincidence, a habit seen many times is something to default to.

## Entry format

```
### <habit name>
- **Frequency**: N functions
- **Seen in**: FuncA (file), FuncB (file), ...
- **Description**: what the pattern is and when it applies
```

Every time you spot a candidate habit (a stylistic choice, not a
compiler-forced one) in a function that just reached MATCHING:
1. Check `src/*.c` siblings to see if the same choice appears elsewhere.
2. If there's no entry for it yet and you've now seen it in 2+ places,
   add one with the functions found so far.
3. If an entry already exists and this function repeats it, **increment
   Frequency and append the function to Seen in** — don't just leave the
   count stale. The count is the evidence; keep it current.
4. A single occurrence isn't worth an entry yet — note it mentally and
   check again next time a similar function comes up, but don't record
   n=1 here (it'd just be noise to re-verify later).

## Observed so far

### Entity `_Create` is fixed boilerplate: allocate, wire routines, init-or-kill

- **Frequency**: 13 functions
- **Seen in**: `Entity080de11c_Create` (entity_080ddf88.c), `GameOverManager_Create` (gameover.c), `EntityAF33_Create` (entity_af33.c), `Entity4DDF_Create` (entity_4ddf.c), `UnkSolarEntity_Create` (solar.c), `LevelUpper_Create` (level_upper.c), `Entity0866_Create` (entity_0866.c), `Entity6367_Create` (entity_6367.c), `Entity0800f110_Create` (entity_0800f110.c), `Duneyrr_Create` (boss/duneyrr.c), `Dvalinn_Create` (boss/dvalinn.c), `Entity0623_Create` (boss/entity_0623.c), `BossShadeMan_Create` (boss/shademan.c)
- **Description**: every `X_Create` has the same body — `p = CreateEntity(ENTITY_KIND, sizeof(X));` then `if (p != NULL) { SetEntityRoutine(p, X_Update, X_Destroy); if (X_Init(p) < 0) { KillEntity((Entity*)p); return NULL; } }` then `return p;`. Write it verbatim from a matched sibling before analyzing the asm; the only per-function choices are the entity kind, the size argument (`sizeof(X)` vs a bare number — both appear), and whether `X_Init` takes extra arguments.
- Singleton entities add a global guard, and the two spellings are NOT interchangeable — they differ in branch direction (see `agbcc-quirks.md`). `if (g == NULL) { ...body...; return p; } return g;` (`Entity080de11c_Create`, `UnkSolarEntity_Create`, `LevelUpper_Create`, `Entity0800f110_Create`) vs the early return `if (g != NULL) { return g; }` followed by the unindented body (`GameOverManager_Create`, and the boss files where the "existing instance" comes from `FUN_08022a2c(BOSS_*)` rather than a global: `Duneyrr_Create`, `Dvalinn_Create`, `BossShadeMan_Create`). Pick whichever puts the allocation on the fall-through path in the target.
