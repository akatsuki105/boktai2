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

- **Function** — name, file
- **Residual score/diff** — the last streamdiff.py/permuter score before
  pausing
- **Symptom** — what kind of mismatch it is (register allocation,
  reordering, unknown struct field, etc.)
- **What was tried** — brief, so a future attempt doesn't repeat dead ends
- **Status** — paused / abandoned-for-now / needs-tooling-fix

## Log

### SortArmors (`src/armor.c`)

- **Residual score/diff**: permuter score 105 (manual) / 40 (permuter, but
  via an untrustworthy `long long` mutation — see `matching-idiom.md`
  §1.2's trustworthy/not-trustworthy note). streamdiff shows pure
  register-letter swaps only (no missing/extra logic, no reordering).
- **Symptom**: register allocation, specifically in a doubly-nested loop
  (selection sort) where the outer and inner loop counters compete for the
  same low registers.
- **What was tried**: rewriting redundant do-while guards as natural
  `for` loops (fixed structural mismatch, 235); precomputing the outer
  counter's next value before the inner loop (105); permuter background
  search at `-j2 --stop-on-zero` for ~2 min, twice (best found: 105
  independently, then 40 via an untrustworthy type-widening mutation not
  worth adopting). **Neither lever is confirmed** — this function never
  reached MATCHING, so per policy they're recorded here as unconfirmed
  hypotheses, not in `agbcc-quirks.md`.
- **Status**: paused at NON_MATCH by user request, score-105 candidate
  kept in `#ifdef NONMATCHING_C`.

### FUN_082438e0 (`src/code_08243660.c`)

- **Residual score/diff**: manual best = streamdiff instruction count
  exact match (82/82) but all-register-letter/pure-regalloc diff, permuter
  score 2695 for that candidate. Background permuter search
  (`-j2 --stop-on-zero`, ~2 min) found best score 1765, but via a broken
  mutation (reads `*buf` instead of advancing `*p`, i.e. reads the same
  element repeatedly — semantically wrong even though it scores lower) —
  not adopted.
- **Symptom**: **same as `SortArmors` above** — register allocation in a
  doubly-nested loop (outer record-count loop, inner 4-halfword checksum
  loop) where the two loops' counters compete for registers. This is now
  2 functions with the identical symptom — worth treating as systemic
  (possibly something about how agbcc allocates registers across nested
  do-while loops that neither of the tried source-level levers fully
  captures) rather than two unlucky functions.
- **What was tried**: precomputing the outer loop's next address before
  the inner loop (same idea as `SortArmors`, insufficient alone here);
  merging the checksum accumulator with the read buffer into one struct
  to force stack residency (fixed a *different*, cruder mismatch — got
  instruction count from 66/82 to exactly 82/82 — but didn't close the
  remaining regalloc gap); reordering local variable declarations (no
  effect at all on this occasion, unlike the usual declaration-order
  idiom); reverting the merge to a plain `u16 checksum[2]` array (produced
  byte-identical output to the merged-struct version — declaration
  strategy didn't matter here).
- **Status**: paused at NON_MATCH by user request, best (82/82,
  pure-regalloc) candidate kept in `#ifdef NONMATCHING_C`.

### FUN_08242c08 (`src/weapon.c`)

- **Residual score/diff**: streamdiff instruction count exact match
  (24/24) but a real structural difference, not just register letters:
  original recomputes `GAME->registeredWeapon + i` (reloading the `GAME`
  pointer via `ldr r0,[0x030046A0]`) from scratch on **every** loop
  iteration; my candidate got the address hoisted out of the loop by the
  compiler (loaded once) with the per-iteration step reduced to a plain
  `+= 2` pointer increment (classic induction-variable strength
  reduction), and consequently used one fewer callee-saved register
  (`push {r4,r5,lr}` vs original's `push {r4,r5,r6,lr}`).
- **Symptom**: an optimization-presence mismatch, not a
  register-letter/order mismatch — the original's codegen looks
  *less* optimized (no LICM/strength-reduction applied to the
  `GAME->registeredWeapon[i]` address inside the loop) than what agbcc
  naturally produces for the obvious `REGISTERED_WEAPON(i)` C translation.
  Something about the real source must suppress that optimization, but
  what specifically triggers/suppresses it here is unclear.
- **What was tried**: plain `for (i = 0; i <= 3; i++)` with the
  `REGISTERED_WEAPON(i)` macro (the pre-existing candidate in the repo);
  rewriting the same loop body as an explicit `do { ... i++; } while (i
  <= 3);` — **produced byte-identical compiled output to the for-loop
  version**, so loop *shape* is not the lever here. Did not yet try:
  splitting the read/write into two separate macro-free
  `GAME->registeredWeapon[i]` expressions, introducing an explicit
  non-cached intermediate (e.g. forcing a `volatile`-like re-read), or
  permuter search (permuter work dir was set up via
  `tools/permuter/setup.sh FUN_08242c08 src/weapon.c` but not run before
  pausing).
- **Status**: paused at NON_MATCH by user request (function looked hard,
  moved on to a smaller target); pre-existing score-unknown candidate
  restored in `#ifdef NONMATCHING_C` unchanged from before this session's
  attempt.
- **2nd confirmation — see `FUN_08242f44` entry below** — same symptom,
  same file, reproduced independently.
- **3rd confirmation — see `RegisterMagic` entry below** (`src/equip_magic.c`)
  — same symptom, different macro (`REGISTERED_MAGIC` not
  `REGISTERED_WEAPON`, same underlying `GAME->` array-field shape).

### FUN_08242f44 (`src/weapon.c`)

- **Residual score/diff**: same symptom as `FUN_08242c08` immediately
  above — same file, same `REGISTERED_WEAPON(i)` for-loop shape (plus one
  extra assignment after the loop). My candidate's GAME-pointer address
  gets hoisted/strength-reduced out of the loop (28 insns) while original
  reloads it fresh every iteration and uses `mov r12/ip` to park the
  second parameter across the loop (30 insns, `push {r4,r5,r6,r7,lr}` —
  even more registers than `FUN_08242c08`'s original).
- **Symptom**: identical to `FUN_08242c08` — optimization-presence
  mismatch (LICM/strength-reduction applied to my candidate's
  `GAME->registeredWeapon[i]` address computation, not applied in the
  original).
- **What was tried**: only the direct-macro candidate (already known to
  fail from the `FUN_08242c08` instance) — restored to NON_MATCH
  immediately rather than repeating the same manual iterations that
  already failed once. This is now **2 independent functions with the
  identical symptom**, strengthening the case that it's systemic
  (something about how the real source expresses
  `GAME->registeredWeapon[i]` prevents agbcc's LICM/strength-reduction
  that a plain `REGISTERED_WEAPON(i)` macro/array-index translation
  triggers) rather than incidental. Any future lever that fixes one of
  `FUN_08242c08` / `FUN_08242f44` should be tried on the other
  immediately — they're almost certainly the same root cause.
- **Status**: paused at NON_MATCH, original pre-existing candidate
  restored in `#ifdef NONMATCHING_C` unchanged.

### RegisterMagic (`src/equip_magic.c`)

- **Residual score/diff**: same symptom as `FUN_08242c08`/`FUN_08242f44`
  above, this time with `REGISTERED_MAGIC(i)` instead of
  `REGISTERED_WEAPON(i)` (offset `0x68` field instead of `0x60`/`0x70`,
  otherwise identical shape: `for (i=0;i<=3;i++) { if (REGISTERED_MAGIC(i)
  == m) REGISTERED_MAGIC(i) = -1; } REGISTERED_MAGIC(idx) = m;`). My
  candidate: 28 insns, GAME-pointer hoisted out of the loop. Original: 30
  insns, `mov r12/ip` to park the second parameter, reloads GAME fresh
  every iteration.
- **Symptom**: identical to `FUN_08242c08`/`FUN_08242f44` — same
  optimization-presence mismatch, now confirmed **3 independent
  functions**, all sharing the `for (i=0;i<=N;i++) { if
  (REGISTERED_X(i) == v) REGISTERED_X(i) = w; } REGISTERED_X(idx) = v;`
  shape against a `GAME->` array field. This is no longer plausibly
  coincidental — it's a systemic gap in how this project currently
  expresses that shape in C vs. what agbcc's original source did.
- **What was tried**: only the direct-macro candidate — confirmed the
  identical failure signature, then restored to NON_MATCH immediately
  without further manual iteration (no new information to gain from
  repeating known-failing attempts a third time).
- **Status**: paused at NON_MATCH, original pre-existing candidate
  restored in `#ifdef NONMATCHING_C` unchanged.

### FUN_08241f28 (`src/solar.c`)

- **Residual score/diff**: streamdiff instruction count exact (23/23);
  permuter quick-score 610 → 475 after adopting one genuine mutation
  (splitting a field RHS load into an explicit temp before the store).
  Two structural mismatches remain unresolved:
  1. A `movs r2, #0` materializing the shared zero constant for the
     `p->unk_19/unk_20/unk_22 = 0` writes gets hoisted to the very top of
     the function (before even the unrelated `p->unk_18 = 1` write) and
     uses a fresh register (r2); original places it right before its
     first use (reusing r1, freed right after the preceding pointer
     store) instead of hoisting.
  2. For `GAME->lx = u16_03004870;`, original fully computes the
     LHS field address (`GAME` deref + `0x940` offset add) *before*
     loading the RHS pool value; my compiled code loads the RHS value
     partway through computing the LHS address (interleaved), needing an
     extra register (r3 instead of reusing r1).
- **Symptom**: pure instruction-ordering/register-allocation mismatches
  around back-to-back small field writes through a global-pointer-derived
  struct (`GAME->fieldX = value;`), not a logic/structure difference —
  similar in flavor to the `FUN_08242c08` register-hoisting issue above
  but a different underlying pattern (LHS/RHS evaluation interleaving
  and constant-hoisting, not loop strength-reduction).
- **What was tried**: direct field assignment (baseline, both issues
  present); splitting the second field's RHS into an explicit `u16 tmp`
  local before the store (**adopted, genuine improvement, 610→475**, kept
  in the candidate); doing the same for the first field (`tmp =
  u16_03004870; GAME->lx = tmp;`) — made it *worse* (order flipped
  further, extra insertions); introducing local pointer variables
  (`u16* p940 = &GAME->lx;` etc.) for one or both fields — caused
  the compiler to CSE/cache the `GAME` dereference across both field
  writes instead of reloading it fresh per field like the original does
  (fewer instructions than original, wrong shape); grouping the three
  zero-writes as a chained assignment
  (`p->unk_20 = (p->unk_19 = 0); p->unk_22 = 0;`, suggested by a
  permuter mutation that scored better) — reproduced the *same* residual
  diff once store order was corrected to match, i.e. no real gain, the
  permuter score improvement here was a metric artifact, not a fix.
  Background permuter search (`-j2 --stop-on-zero`, ~2 min, twice) best
  found: 405, via the misordered zero-write grouping (not adopted, since
  fixing the order regressed the score back to no improvement).
- **Status**: paused at NON_MATCH by user request (10-iteration budget
  effectively spent); best candidate (with the field2 `tmp` split kept)
  restored in `#ifdef NONMATCHING_C`.

### Malloc (`src/malloc.c`)

- **Residual score/diff**: streamdiff instruction count 51 vs 50
  (off-by-one), and even after fixing the count, a persistent register
  *swap*: my candidate assigns `block` (EWRAM heap pointer, loop-carried)
  and `bytesize`-turned-`need` (aligned allocation size) to `r2`/`r3` in
  the opposite order from the original (original: `need`→r2, `block`→r3;
  mine: `block`→r2, `need`→r3, or vice versa depending on declaration
  order tried) — structurally identical instruction sequence otherwise,
  just consistently the wrong physical register for these two values
  throughout the whole function.
- **Symptom**: a first-fit heap allocator over a doubly-linked list of
  `MemBlock` nodes (fields renamed from `unk_00`/`unk_04` to
  `prev`/`next` — pointer types — during this attempt, confirmed
  harmless by diffing `InitHeap`'s compiled output against
  `expected/build/boktai2/src/malloc.o` unchanged). The register-swap
  symptom is reminiscent of the "declare-with-initializer" and
  "duplicate one variable across a whole function" idioms already
  logged, but neither directly explains a *swap* between two
  simultaneously-live, non-overlapping-purpose locals — this may be its
  own new idiom once solved, not yet identified.
- **What was tried**: (1) plain declare-both-early (worst case, needed
  `push {r4,r5,lr}`, 2 spare registers — original only needs 1); (2)
  merging `freeSize`/`remain` into one variable (no effect, compiler
  already treated them equivalently); (3) reusing the `bytesize`
  parameter in place for `need` instead of a fresh local, combined with
  deferring the `oldNext = block->next;` read to right before its first
  use instead of hoisting it early — **this got the push list down to
  exactly `{r4,lr}` matching original's register *count***, but `block`
  and `need` landed in the swapped `r2`/`r3` slots; (4) swapping which of
  `block`/`bytesize` is initialized first in source order — flipped which
  variable got r2 vs r3, but never the *right* way (whichever was tried,
  the other one ended up swapped instead). Did not try: permuter search
  (not run before pausing — worth trying next time, this looks like
  exactly the kind of register-letter-only diff permuter is good at
  scoring/fixing).
- **(5) Bitfield hypothesis, tried and disproven**: user suggested
  `MemBlock.unk_08` might be a real C bitfield (`u32 size : 20; u32 : 11;
  u32 free : 1;`) instead of a plain `u32` with manual mask/shift. Tried
  rewriting both `InitHeap` (the heap initializer, already
  MATCHING before this attempt) and `Malloc` to use named bitfield
  members (`block->size`, `block->free`) instead of
  `unk_08 & MEMBLOCK_FLAG` / `unk_08 & 0x000FFFFF`. Result: **broke the
  previously-matching `InitHeap`** — agbcc laid out the 1-bit `free`
  field as its own separate byte-addressed storage unit (compiled to
  `ldrb`/`strb` at offset+11, a read-modify-write on a single byte)
  instead of packing it into the same word as `size`, producing
  completely different bytes from the original's single
  `str r1, [r0, #8]` full-word constant store. This proves `unk_08` is
  **not** accessed as a real bitfield in the original source, at least
  not in a way agbcc packs the way we tried — the field is written as a
  plain whole `u32` (either a literal combined constant like
  `MEMBLOCK_FLAG | HEAP_SIZE`, or masked/OR'd by hand as the pre-existing
  candidate already does). Reverted immediately; `InitHeap` confirmed
  restored to its exact prior matching bytes before resuming. **Do not
  retry the bitfield struct approach for this field** without a
  fundamentally different bitfield layout (e.g. explicit union with a
  same-sized plain-`u32` alias for the constant-store case) — the naive
  version is a confirmed dead end.
- **Status**: paused at NON_MATCH by user request; candidate from
  attempt (3) — the closest, off by the r2/r3 swap only — kept in
  `#ifdef NONMATCHING_C`. `InitHeap` confirmed still MATCHING.

### Free (`src/malloc.c`)

- **Residual score/diff**: streamdiff instruction count 59 vs 60
  (off-by-one), and — same symptom family as `Malloc` above — a
  persistent register *swap*: `prev`/`next` (both `MemBlock*`, loaded
  from `block->prev`/`block->next` right after computing `block`) land
  in `r5`/`r4` in my candidate but original uses `r4`/`r5` (i.e. exactly
  reversed), throughout the whole function. Otherwise the instruction
  sequence and structure match closely (free-with-coalesce: mark block
  free, merge into `prev` if it's also free, then merge `next` into the
  result if it's also free).
- **Symptom**: the *same* register-letter-swap symptom as `Malloc`
  immediately above, on a sibling function in the same file — 2nd
  confirmed instance of this exact pattern (two `MemBlock*`/pointer-ish
  locals loaded back-to-back near function entry landing in swapped
  registers vs. original). Worth checking together with `Malloc` if a
  fix for one is found — likely the same underlying cause.
- **What was tried**: swapping which of `block->next`/`block->prev` is
  read first (`prev = ...; next = ...;` vs `next = ...; prev = ...;`) —
  **zero effect on the compiled output either way**, ruling out simple
  read-order as the lever (same negative result `Malloc` got from
  swapping its own two variables' order); permuter background search
  (`-j2 --stop-on-zero`, ~2 min) — best score found 385 (down from a
  base score of 880), but the improving mutations were mostly duplicated
  dead branches (`if (header) {...} else {...}` with identical bodies)
  rather than a genuine structural insight, not adopted.
- **Status**: paused at NON_MATCH by user request; candidate with
  `prev`/`next` read in that order (matching original's read order, even
  though it doesn't fix the register swap) kept in `#ifdef NONMATCHING_C`.
