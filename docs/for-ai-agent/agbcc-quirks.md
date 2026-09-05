# agbcc compiler quirks

A catalog of **source-level idioms** that make agbcc (legacy GCC 2.x, Thumb-1,
`-O2 -fshort-enums`) emit byte-identical code. Each entry: the asm symptom →
the source that reproduces it. Read before inventing a lever for a
non-matching function; extend after discovering a new one.

**Frequency matters here too.** The compiler's behavior is deterministic,
but *our hypothesis* about which C idiom explains a given asm pattern is
inferred from a small sample and can be wrong or only partially right. A
count of how many different functions actually confirmed an idiom (i.e.
adopting it got `make compare` to OK, not just "looked plausible") is the
evidence behind it — one confirmation could be coincidence, several is a
real rule. Every entry below carries a **Frequency** line; increment it and
append the function whenever the idiom is confirmed again, the same
discipline as `c-programmer-habits.md`.

**Only record an entry here once a function using it actually reaches
MATCHING.** A lever that reduces a streamdiff/permuter score on a function
that stays NON_MATCH is not confirmed — it might be a real idiom, or it
might be a partial fix for a symptom whose real cause is something else
(or specific to that one function's register pressure). Track those in
`stuck-points.md` under the stuck function instead, and only promote them
here once some function's `make compare` actually hits OK using them.

## Control flow / scheduling

### Branch direction

- **Frequency**: `RemoveSpecifiedItem`.
- agbcc keeps the *first-written* if-branch as fall-through; put an
  out-of-line block in the `else`.
- Applies even when **both** arms end in `return` (no shared code after
  the `if`, so `if(){return;}return;` and `if(){return;}else{return;}`
  compile identically — the `else` doesn't matter, only which condition
  and which arm is written first). `RemoveSpecifiedItem` — a 2-way
  dispatcher `if (IsValuable(id)) return removeSpecifiedValuable(id);
  return _RemoveSpecifiedItem(id);` compiled with the wrong branch
  (`bne` instead of `beq`, `removeSpecifiedValuable` placed out-of-line
  instead of as fall-through). Fixed by writing the **negated** condition
  first, matching the sibling `TryAddItem`'s existing shape exactly:
  `if (!IsValuable(id)) return _RemoveSpecifiedItem(id); return
  removeSpecifiedValuable(id);` — swapping which branch is written first
  (and negating the condition to match) flipped the fall-through arm to
  the correct one.

### Narrow NAKED-callee parameter forces truncation at a single call site

- **Frequency**: `FUN_082402c8`, `FUN_082402e0`, `FUN_08240428`, `sound_082403b8`.
- When the only call site passes a wider value (e.g. a `u32`-returning
  `Script_GetValue()`) directly into a NAKED callee declared with a
  narrower parameter type (`u16`), agbcc inserts a truncation
  (`lsls rN, rN, #0x10` / `lsrs rN, rN, #0x10`) at the call site to
  narrow the argument — but the original binary has no such truncation,
  because the callee's real parameter is the wider type. Fix: widen the
  NAKED callee's declared parameter type to match what the call site
  actually produces (`u16 speed` → `u32 speed`). Safe whenever the
  callee has exactly one caller (no risk of breaking another call site's
  expectations); the callee's own `.inc` body is untouched since it's
  still NAKED.

### switch case body layout follows source order, independent of dispatch order

- **Frequency**: `VM_ReadContainerLength`.
- For a sparse `switch` (few, non-contiguous case values), agbcc lays out each case's compiled body in the same order the `case` labels appear in the source — but the *comparison/dispatch* instructions it emits to reach them can use a completely different order (e.g. a value-magnitude-based pivot). Matching only the dispatch order isn't enough; the case labels' source order must also match, or bodies land in the wrong place in the output.

### `x << 1` vs `x * 2` pick opposite Rn/Rm order for a later pointer add

- **Frequency**: `Script_StorePointerCore`.
- Scaling an index by 2 as `offset << 1` vs `offset * 2` is value-identical, but agbcc doesn't always canonicalize the two the same way: in `*(u16*)(dst + (offset << 1))`, the shift form compiled the subsequent `dst + offset*2` addition as `adds r0, r4, r0` (dst first); the literal `offset * 2` form instead gave `adds r0, r0, r4` (offset-term first) — same instruction, swapped operands, real byte difference. When a pointer-add's Rn/Rm order doesn't match and the scale is a power of 2, try switching between `<<` and `*` for the scale before reaching for other levers.

### `x != 0` (and `a != b`) materialized as a 0/1 int normalize via `(0-x)|x >> 31`

- **Frequency**: `Script_LoadPointer`.
- Only applies when the comparison's result must become an actual 0/1 integer VALUE — assigned, stored, or `return`ed (equivalently, `x != 0 ? 1 : 0` written out explicitly) — not when it's used purely as an `if`/`while` condition (those just branch, no materialization needed).
- `flag != 0` materialized this way compiles to `rsbs r0, r1, #0` / `orrs r0, r1` / `lsrs r0, r0, #0x1f` — negate, OR with the original, then shift the sign bit down to bit 0. Writing the raw bit trick by hand (`(u32)((0 - flag) | flag) >> 0x1F`) produces byte-identical output to writing the natural `flag != 0`, so prefer the natural form; no need to hand-roll the trick.
- Two-operand `a != b` (both `s32`) generalizes the same trick via XOR first: `return a != b;` compiles as if written `return ((u32)(-(a ^ b) | (a ^ b))) >> 31;` — i.e. agbcc reduces `a != b` to `(a^b) != 0` then applies the same negate/OR/shift sequence.

### `(x & (1<<n)) != 0` auto-optimizes to `(x>>n)&1` unless the mask is precomputed

- **Frequency**: `Script_LoadPointer`.
- Writing a single-bit test as one fused expression — `(byte & (1 << bit)) != 0` — lets agbcc's combiner recognize the "extract one bit" idiom and emit the cheaper `asrs`/`ands` (shift the target bit to position 0, mask with 1) instead of the general nonzero-materialize trick above. If the target's real assembly uses the general `rsbs`/`orrs`/`lsrs` trick instead (i.e. the shift-based optimization did NOT happen), the mask must be computed in its own prior statement — `s32 mask = 1 << bit; ... (byte & mask) != 0;` — splitting it into a separate pseudo-register apparently hides the "single bit" shape from the combiner and falls back to the general path.
- That statement split has a side effect: splitting *only* the mask into its own statement (leaving the address `src + (offset >> 3)` inline) reintroduced an unrelated register-allocation regression (two unrelated parameters got pinned into extra callee-saved registers for the whole function instead of just one). Also splitting the address into its own pointer variable (`u8* p = src + (offset >> 3);`) alongside the mask fixed it. Net effect: both the mask AND the address need their own statement (address first, then mask, matching the target's instruction order) to get byte-identical output.

### A peeled first call duplicates the call and costs a saved register

- **Frequency**: `VM_CallScript`.
- `call(); while (cond) { body; call(); }` emits **two** `bl` sites; `while (TRUE) { call(); if (!cond) break; body; }` emits **one**, entered by a `b` that jumps over the body to the call. If the target has a single call site reached by a leading `b`, write the loop in the second form. The peeled form also raised register pressure enough that agbcc strength-reduced `arr[i] = v; i++;` into a walking pointer (`stmia rN!`) and needed an extra callee-saved register; the single-call form dropped both.

### Bitfield store vs hand-written mask differ in operand evaluation order

- **Frequency**: `VM_CallScript`.
- Assigning a 16-bit bitfield (`u32 argc : 16;` → `s.argc = n;`) computes the truncated value **first** (`lsls`/`lsrs`), then loads the word, ANDs the mask constant, ORs and stores. The hand-written equivalent `w = (w & 0xFFFF0000) | (u16)n;` loads and masks first, then truncates. Same instructions, different order — if the order doesn't match, the original almost certainly used a bitfield.

### `s16` locals defer sign-extension to each use

- **Frequency**: `VM_CallScript`.
- `s16 x = expr;` keeps the raw value and emits `lsls`/`asrs` at every *use*; `s32 x = (s16)expr;` sign-extends once at the *assignment*. Pick whichever places the extension where the target has it.

### `arr[i]` vs `*p++` change where the walking pointer is initialized

- **Frequency**: `FUN_082315c0`.
- Both compile to the same `stm rN!, {r0}` walking store, but the init of that pointer lands in a different place. `*out++ = v;` modifies the parameter, so agbcc copies it to a callee-saved register in the **entry block**, before any loop-invariant hoists. `out[i] = v;` leaves the parameter alone and lets loop strength reduction create the pointer, so its init goes in the **preheader**, after the hoists — swapping the order of the two setup instructions. (Strength reduction also frees `i` to be reversed into a down-counter while the pointer still walks up.)

### An intermediate result variable can block a store's cross-jump merge

- **Frequency**: `VM_RunExpression`.
- `if (c) { x = A; } else { x = B; } slot->f = x;` and `if (c) { slot->f = A; } else { slot->f = B; }` produce the same merged store, but not the same scheduling around it. In `VM_RunExpression` the `x` version delayed a later call's first-argument setup (`adds r0, r5, #0` emitted after the other two argument registers instead of before them); writing the store directly in both arms fixed it. If argument setup order is the only thing off near a two-armed store, try removing the intermediate variable.
