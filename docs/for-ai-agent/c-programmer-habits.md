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

### Bit set / clear / test goes through a `static inline` helper, never a bare `|=`

- **Frequency**: 5 files define such helpers; 7 functions verified to need the shape
- **Seen in**: `EnableEntityFlags` / `DisableEntityFlags` / `TestFlag030047a4` (entity_0823acbc.c), `ClearHitboxFlags` (entity_ec96.c), `TestHitboxUnk38` (solar_bamboo.c), `Entity28CB_SetState` (entity_28cb.c), `Enemy_SetFlag` / `Enemy_SetFlag2` / `Enemy_ClearFlag2` / `Enemy_SetFlag4` (include/enemy.h) used by `FUN_080ef4e4`, `Enemy_Sleep`, `FUN_080ec92c`, `FUN_080ed068`, plus `Stat_SetFlag934` / `Stat_ClearFlag934` and `EnemyManager_ClearFlags` used by `FUN_080ec900`, `FUN_080ee9d4`, `EnemyManager_Update` (all enemy_manager.c)
- **Description**: these developers did not write `p->flags |= BIT;` at the call
  site. They wrote a one-line `static inline` taking the struct pointer and the
  mask, and called that. `data.c` contains the string
  `"../enemy/system/eneinline.h"`, so the enemy code had a whole header of them.
- Unlike most entries here, this one **is** visible in the asm, because the
  helper's parameter survives inlining as a local: the mask is materialised into
  its own register *before* the field is loaded, and two call sites in the two
  arms of one `if` keep their stores separate instead of being cross-jumped into
  one. Writing `bit = MASK; p->flags |= bit;` by hand reproduces the bytes, but
  it is the expansion, not the source — prefer the helper.
- The parameter must be the **mask**, and the helper must take the **struct
  pointer**. Two near-misses, both of which stop matching:
  `static inline void f(u32* field, u32 bit) { *field |= bit; }` called with
  `&p->flags` makes both arms identical so the stores merge, and
  `static inline void f(T* p, s32 bitidx) { p->flags |= (1 << bitidx); }` folds
  the shift at compile time so the parameter disappears entirely.
- It applies to globals too, and then the helper takes only the mask, like
  `EnableEntityFlags`: `static inline void Stat_SetFlag934(u16 bit) { gStat->unk_934 |= bit; }`.
  A helper clearing **several** bits at once is the same shape with a plural
  name (`EnemyManager_ClearFlags(p, A | B | C)`), and it subsumes what looked
  like a separate u16 trap: writing `f &= ~0x20;` narrows the constant and
  loads it from the pool, but `~bit` on a `u16` parameter stays `int` and
  gives the `movs` / `rsbs` pair the target has.
- One helper per field, not per width — `Enemy` needs a separate pair for
  `flags`, `flags2`, `flags4`, even though `flags` and `flags2` are both `u32`.
- The read side exists too and comes in two flavours: returning the masked value
  (`TestHitboxUnk38`, `TestFlag030047a4`) and returning a `bool32`. Which one a
  given call site used is still open — see `stuck-points.md` for functions whose
  only remaining difference is a materialised boolean.
