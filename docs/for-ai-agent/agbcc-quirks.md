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

**New entry, or extend an existing one?** Route by the *asm symptom*, not by
the C lever that fixed it. When an entry already describes the same symptom
(the same instructions differing in the same way), append a bullet to it and
bump its Frequency rather than opening a new entry — that is what keeps this
file from growing a near-duplicate for every variation of one behavior. Open
a new entry only when no existing entry covers the symptom, and file it under
the section matching how you would go looking for it.

## Control flow & loop shape

### Branch direction

- **Frequency**: `RemoveSpecifiedItem`, `FindFile`, `Video_GetHankakuTiles`, `Video_GetZenkakuTiles`, `Save_GetCoreAddr`, `FUN_080223f4`, `FUN_08022428`, `FUN_08022448`, `FUN_080224f0`, `FUN_08022618`, `FUN_08022644`.
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
- **Careful: for the guard shape `if (c) { return A; } return B;` the rule
  reads the other way round.** agbcc makes the *trailing* statement (`B`) the
  fall-through and puts the if-body (`A`) out of line — which is what the
  `RemoveSpecifiedItem` example above actually shows. So write **last**
  whichever arm the target has falling through. `FindFile`
  (`if (list[start] != id) return -1; return start;` put `return start` on the
  fall-through path; the target wanted `-1` there) and
  `Video_GetHankakuTiles` (same flip on a `NULL` guard) both needed the
  condition inverted and the two returns swapped.
- Two guards in a row: only the **last** guard's return moves to the end.
  The first one stays inline (`bne` jumps over it). `FUN_08022448` needed
  `if (g == NULL) return -1; if (g->f != 0) return -2; g->f = 1; return 0;`.
  Here `-1` stays inline and `-2` is placed at the end. Nesting it as
  `if (g != NULL) { ... } return -1;` flips both branches.
- A guard with two conditions reverses the single-guard rule. `if (a && b) { A } return B;` put `A` inline and `B` at the end. `if (!a || !b) return B; A` put `B` inline and `A` at the end. `FUN_08022618` and `FUN_08022644` needed the `||` form.

### switch case body layout follows source order, independent of dispatch order

- **Frequency**: `VM_ReadContainerLength`.
- For a sparse `switch` (few, non-contiguous case values), agbcc lays out each case's compiled body in the same order the `case` labels appear in the source — but the *comparison/dispatch* instructions it emits to reach them can use a completely different order (e.g. a value-magnitude-based pivot). Matching only the dispatch order isn't enough; the case labels' source order must also match, or bodies land in the wrong place in the output.

### A peeled first call duplicates the call and costs a saved register

- **Frequency**: `VM_CallScript`.
- `call(); while (cond) { body; call(); }` emits **two** `bl` sites; `while (TRUE) { call(); if (!cond) break; body; }` emits **one**, entered by a `b` that jumps over the body to the call. If the target has a single call site reached by a leading `b`, write the loop in the second form. The peeled form also raised register pressure enough that agbcc strength-reduced `arr[i] = v; i++;` into a walking pointer (`stmia rN!`) and needed an extra callee-saved register; the single-call form dropped both.

### A `do`-`while` with `break` can lay its latch out mid-body; a `for` increment puts it at the bottom

- **Frequency**: `Rfu_FindPartnerRecord`.
- Target: body, then `if (f(p) == 7) break;`, then `pos += f(p) + 2; cmp pos, #0xf; bls top` at the very end. `do { ...; if (...) break; pos += ...; } while (pos <= 15);` emitted the increment and test in the middle of the body behind an extra `b` (one insn longer). Moving the increment into a `for (pos = 0; pos <= 15; pos += f(p) + 2)` header, with `p` declared outside the loop, matched.
- In the same loop, the target keeps `&buf[pos] + 1` in one register across the `== 7` test and the increment. Recomputing `&buf[pos + 1]` at each use rebuilt it every time; a pointer local (`p = &buf[pos]; ... p++;`) matched.

## Comparisons & bit tests

### `x != 0` (and `a != b`) materialized as a 0/1 int normalize via `(0-x)|x >> 31`

- **Frequency**: `Script_LoadPointer`, `FUN_0822a470`, `FUN_0822d9f0`.
- Only applies when the comparison's result must become an actual 0/1 integer VALUE — assigned, stored, or `return`ed (equivalently, `x != 0 ? 1 : 0` written out explicitly) — not when it's used purely as an `if`/`while` condition (those just branch, no materialization needed).
- `flag != 0` materialized this way compiles to `rsbs r0, r1, #0` / `orrs r0, r1` / `lsrs r0, r0, #0x1f` — negate, OR with the original, then shift the sign bit down to bit 0. Writing the raw bit trick by hand (`(u32)((0 - flag) | flag) >> 0x1F`) produces byte-identical output to writing the natural `flag != 0`, so prefer the natural form; no need to hand-roll the trick.
- **The "prefer the natural form" advice has an exception: position.** In `FUN_0822a470` the target computes the 0/1 value *before* two unrelated stores and only then sets up the call (`movs`/`ands`/`rsbs`/`lsrs`, `str`, `str`, `bl`). Written naturally as a call argument (`f(p, (flags & mask) != 0)`) the trick is emitted correctly but stays anchored at the call, after the stores; assigning it to a local first (`idx = (flags & mask) != 0;`) moves it early but switches agbcc to a *branch-based* setcc (`cmp`/`beq`/`movs #1`, one insn longer). Hand-rolling the trick into the assignment — `idx = (u32)(0 - (flags & mask)) >> 31;` — is the only form that is both early and branchless, and it matched. So: use the natural form when the trick lands where you need it, and hand-roll only when the target evaluates it earlier than the call site would.
- Two-operand `a != b` (both `s32`) generalizes the same trick via XOR first: `return a != b;` compiles as if written `return ((u32)(-(a ^ b) | (a ^ b))) >> 31;` — i.e. agbcc reduces `a != b` to `(a^b) != 0` then applies the same negate/OR/shift sequence.

### `(x & (1<<n)) != 0` auto-optimizes to `(x>>n)&1` unless the mask is precomputed

- **Frequency**: `Script_LoadPointer`, `FUN_0822a470`, `PlaySound_0824078c`, `FUN_0822da50`, `FUN_0822d9f0`.
- Hoisting the mask also moves *where* the constant is built. In `PlaySound_0824078c`, `if (!((a | b) & 0x400))` built `movs #0x80` / `lsls #3` right before the `ands`; the target builds it first, before both loads. Swapping the `&` operands changed nothing; `u32 mask = 0x400;` as its own statement before the `if` matched.
- Writing a single-bit test as one fused expression — `(byte & (1 << bit)) != 0` — lets agbcc's combiner recognize the "extract one bit" idiom and emit the cheaper `asrs`/`ands` (shift the target bit to position 0, mask with 1) instead of the general nonzero-materialize trick above. If the target's real assembly uses the general `rsbs`/`orrs`/`lsrs` trick instead (i.e. the shift-based optimization did NOT happen), the mask must be computed in its own prior statement — `s32 mask = 1 << bit; ... (byte & mask) != 0;` — splitting it into a separate pseudo-register apparently hides the "single bit" shape from the combiner and falls back to the general path.
- The lever also works with a plain literal mask, not just `1 << bit`: in `FUN_0822a470`, `(flags & 0x80) != 0` compiled to `lsrs r1, rN, #7` / `ands r1, r4` (and pinned one extra callee-saved register), while hoisting the constant into its own statement (`mask = 0x80; ... (flags & mask) != 0`) fell back to the general `movs #0x80` / `ands` path and fixed the register allocation at the same time. Constant propagation does not undo the split.
- That statement split has a side effect: splitting *only* the mask into its own statement (leaving the address `src + (offset >> 3)` inline) reintroduced an unrelated register-allocation regression (two unrelated parameters got pinned into extra callee-saved registers for the whole function instead of just one). Also splitting the address into its own pointer variable (`u8* p = src + (offset >> 3);`) alongside the mask fixed it. Net effect: both the mask AND the address need their own statement (address first, then mask, matching the target's instruction order) to get byte-identical output.

## Integer width & sign extension

### Narrow NAKED-callee parameter forces truncation at a single call site

- **Frequency**: `FUN_082402c8`, `FUN_082402e0`, `FUN_08240428`, `sound_082403b8`, `sound_08240728`.
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
- The callee may also be a MATCHING C function: `PlaySound_08240718(SoundID16 id) { m4aSongNumStart(id); }` already truncates `id` in its own body for the `u16` callee, so widening it to `SoundID32` left its bytes unchanged and removed the extra truncation from the caller `sound_08240728`.

### `s16` locals defer sign-extension to each use

- **Frequency**: `VM_CallScript`.
- `s16 x = expr;` keeps the raw value and emits `lsls`/`asrs` at every *use*; `s32 x = (s16)expr;` sign-extends once at the *assignment*. Pick whichever places the extension where the target has it.

### `u16` vs `s16` counters increment differently (and `s16` can still use `lsr`)

- **Frequency**: `VM_Ctrl_22FF`.
- `u16 n; n++;` adds first, then truncates: `adds #1` / `lsls #16` / `lsrs #16`. `s16 n; n++;` shifts up first and adds there: `lsls #16` / `adds 0x10000` (built with `movs #0x80` + `lsls #9`) / `lsrs #16`. If the target has the second shape, the counter is `s16` — no natural `u16` spelling (`n = n + 1`, `for(...; n++)`, `(u16)(n + 1)`, `(n + 1) & 0xFFFF`, `arr[n++]`) produces it.
- Don't read the `lsr` as proof of `u16`: an `s16` counter that is never compared needs no sign extension, so agbcc drops the `asr`. Adding a comparison on the counter (e.g. `n < 16`) brings the `asr` back.

## Operand order & scheduling

### Pointer-add Rn/Rm order depends on how the address is spelled

- **Frequency**: `Script_StorePointerCore`, `FUN_0822ea10`, `FUN_08022128`.
- Scaling an index by 2 as `offset << 1` vs `offset * 2` is value-identical, but agbcc doesn't always canonicalize the two the same way: in `*(u16*)(dst + (offset << 1))`, the shift form compiled the subsequent `dst + offset*2` addition as `adds r0, r4, r0` (dst first); the literal `offset * 2` form instead gave `adds r0, r0, r4` (offset-term first) — same instruction, swapped operands, real byte difference. When a pointer-add's Rn/Rm order doesn't match and the scale is a power of 2, try switching between `<<` and `*` for the scale before reaching for other levers.
- The same symptom also comes from the *pointer vs subscript* choice, and that lever is independent of the one above. In `FUN_0822ea10`, holding the address in a variable (`u32* p = &base[i];` then `*p`) emitted `adds r3, r1, r0` (base first); indexing at each use (`base[i]`, three times) emitted `adds r3, r0, r1` (offset first) and matched. Switching `<<`/`*` did nothing there, so try both levers.
- The pointer-vs-subscript choice also changes how a field offset is grouped. In `FUN_08022128`, `u8* count = &node->unk_6[side];` emitted `adds r1, r4, #6` / `adds r3, r5, r1`, which is `node + (side + 6)`. Writing `node->unk_6[side]` at each use emitted `adds r1, r5, #6` / `adds r3, r1, r4`, which is `(node + 6) + side`, and matched.

### `==` operand order sets the `cmp` operands and which value keeps the address register

- **Frequency**: `sound_08240740`, `Save_WriteCore`.
- A call result compared directly (`if (f(...) != len + 8)`) keeps the result in `r0` and builds `len + 8` in `r1`; the target had `adds r1, r0, #0` / `adds r0, r5, #0` / `adds r0, #8` / `cmp r1, r0`. Swapping the operands made it worse, but assigning the result to a local first (`ret = f(...); if (ret != len + 8)`) matched.
- `a[i] == x` and `x == a[i]` are not canonicalized. In `if (gSoundIDs[gSongTable[id].ms] == id) { gSoundIDs[...] = 0; ... }`, agbcc emitted `adds r1, r0, r2` / `ldrh r0, [r1]` / `cmp r0, r4` and stored through `r1`; the target had `adds r0, r0, r2` / `ldrh r1, [r0]` / `cmp r4, r1` and stored through `r0`. Writing `id == gSoundIDs[...]` matched. When a streamdiff shows only a swapped `cmp` plus the loaded value and its address trading registers, swap the operands of the comparison.

### The `for` increment's comma order is the order of the two `adds`

- **Frequency**: `Video_GetActorSprite`.
- In a search loop that walks a pointer and a counter together, `for (...; i++, a++)` emitted `adds r2, #1` before `adds r4, #0xc`; the target had the pointer first, and `a++, i++` matched. Siblings such as `FUN_0822e8d0` are also written pointer-first (`p++, i++`).

### Two reads of one halfword (`ldrh` + `ldrb`) survive only in low-byte-first order

- **Frequency**: `Video_CreateSpriteLUT`.
- The target read `gSpriteSizeTable[i]` twice (`ldrh r1, [r6]` / `ldrb r2, [r6]`). Writing `s32 w = (u8)t[i]; s32 h = t[i] >> 8;` kept both loads; writing `h` first CSE'd them into one `ldrh` plus `lsls #24` / `lsrs #24` for the low byte. The same function also needed `tw = w >> 3; th = h >> 3;` as locals so the `asrs` land right after the loads instead of at each store.

### A field re-read before a global pool load needs a narrow local

- **Frequency**: `Sprite_SetPlttID`.
- `p->plttID = id; p->pltt = &gObjPlttData[p->plttID * 16];` emitted `ldr rN, =gObjPlttData` before `ldrh r2, [r0, #0x3a]`, and so did `gObjPlttData + ...`, `<< 4`, and `index + gObjPlttData`. The target reloads the field first. Reading it into a `u16` local in its own statement (`u16 i; p->plttID = id; i = p->plttID; p->pltt = &gObjPlttData[i * 16];`) matched. (`Sprite_LoadSprite` writes the same two lines inline and matches with the global first, so check the target's order before choosing.)

### Global-address pool loads are ordered by expression nesting, not by source statement

- **Frequency**: `sound_08240264`, `FUN_082436dc`.
- A global struct's address loaded at function entry (`ldr r4, =gSaved` before anything else) and kept in a callee-saved register across calls comes from a pointer local declared first: `SavedHBlankState* s = &gSavedHBlankState;` then `s->field`. Writing `gSavedHBlankState.field` at each use loaded the address late, after the calls, and needed one less saved register.
- After a call, `u16 ms = gSongTable[id].ms; f(gMPlayTable[ms].info); gSoundIDs[ms] = id;` loaded `=gSongTable` first and `=gMPlayTable` just before its use. The target loads `=gMPlayTable` into a register **before** `=gSongTable`; writing the index inline, `f(gMPlayTable[gSongTable[id].ms].info); gSoundIDs[gSongTable[id].ms] = id;`, matched (CSE still reuses the `ms*2` for the second subscript). If a streamdiff only shows one `ldr rN, =POOL` moved earlier and a register renamed, try inlining or splitting the index local.

### A struct-field store does not force a global pointer to be reloaded; a cast store does

- **Frequency**: `Save_WriteCore`.
- After `gStat->magicNumber = x;`, agbcc assumes the struct-field store cannot touch the scalar pointer `gStat`, so it reuses the loaded pointer for `f(&gStat->magicNumber, 4)`. The target reloads it (`ldr r2, =gStat` / `ldr r1, [r2]` / `str r0, [r1]` / `ldr r0, [r2]`), which happens only when the store is not a struct-field access: `*(u32*)gStat = x; f(gStat, 4);` matched. If the target re-reads a global pointer right after storing through it, write the store without the field.

### `(a * 2) * b` moves the doubling onto `b`; `(a << 1) * b` keeps it on `a`

- **Frequency**: `FUN_0822bcf4`.
- The target computed a row pitch as `ldrsh r0, [...]` / `lsls r0, r0, #1` / `muls r0, r2`. Both `y * (w * 2)` and `(w * 2) * y` emitted `lsls r2, r2, #1` instead, on the other operand, because agbcc reassociates a constant factor through a multiply. Writing the doubling as a shift, `(w << 1) * y`, is not reassociated and matched.

### An `|` chain accumulates left-to-right exactly as written

- **Frequency**: `FUN_0822a4fc`, `FUN_0822bcf4`.
- agbcc does not reassociate `a | b | c`. Written flat, it emits `a|b` into the accumulator and then ORs `c` (`orrs acc, b` ... `orrs acc, c`); written `a | (b | c)`, it builds `b|c` in a separate register first and ORs that into `a` once (`orrs r1, r0` then `orrs r3, r1`). Both forms have the same instruction count, so a streamdiff shows only swapped `orrs` operands — plus, because the grouped form needs one more value live at once, a different `push` list (`{r4, lr}` vs `{r4, r5, lr}`) and every register shifted by one. When the register allocation is off by exactly one callee-saved register in an expression built from three or more `|` terms, try regrouping the parentheses before suspecting anything else. The same should apply to other associative operators (`+`, `&`, `^`).

### Bitfield store vs hand-written mask differ in operand evaluation order

- **Frequency**: `VM_CallScript`.
- Assigning a 16-bit bitfield (`u32 argc : 16;` → `s.argc = n;`) computes the truncated value **first** (`lsls`/`lsrs`), then loads the word, ANDs the mask constant, ORs and stores. The hand-written equivalent `w = (w & 0xFFFF0000) | (u16)n;` loads and masks first, then truncates. Same instructions, different order — if the order doesn't match, the original almost certainly used a bitfield.

### `arr[i]` vs `*p++` change where the walking pointer is initialized

- **Frequency**: `FUN_082315c0`, `FUN_0824082c`.
- Both compile to the same `stm rN!, {r0}` walking store, but the init of that pointer lands in a different place. `*out++ = v;` modifies the parameter, so agbcc copies it to a callee-saved register in the **entry block**, before any loop-invariant hoists. `out[i] = v;` leaves the parameter alone and lets loop strength reduction create the pointer, so its init goes in the **preheader**, after the hoists — swapping the order of the two setup instructions. (Strength reduction also frees `i` to be reversed into a down-counter while the pointer still walks up.)
- A walking pointer compared against `base + const` (`adds r0, r5, #0` / `adds r0, #0x14` / `cmp r4, r0`) with a **signed** loop exit (`ble`) and no pre-loop test is an `s32 i` index loop, not a pointer loop: loop strength reduction deletes `i` and rewrites `i == 10` and `i < 32` as compares on the pointer. In `FUN_0824082c`, writing the pointer loop (`p == &arr[10]`, `p <= &arr[31]`) gave a pre-loop `bhi`, unsigned `bls` and pool-loaded addresses; `for (i = 0; i < 32; i++) { if (arr[i]) { if (i == 10) ... } }` matched, including the second walking pointer used for the `arr[i]` call argument.

### Where a global's address and value materialize follows statement splitting

- **Frequency**: `FUN_08240360`, `FUN_082405c0`, `Sound_SetBGMTempo`, `FUN_082410e8`.
- The same holds for a call used as an argument. `f(0, (T*)gPtr, g(0x28))` loaded `=gPtr` and its value into a callee-saved register before calling `g` (one extra saved register); the target calls `g` first and loads `gPtr` right before `f`. Putting the inner call in its own statement, `s32 len = g(0x28); f(0, (T*)gPtr, len);`, matched.
- A nested subscript written as one expression (`gMPlayTable[gSongTable[id].ms].info`) hoists the outer table's pool `ldr` *before* the inner subscript is read; splitting the inner index into its own statement (`u16 ms = gSongTable[id].ms;` then `gMPlayTable[ms].info`) emits that `ldr` after it, where the target had it. If only a pool `ldr` sits in the wrong place, try splitting or merging the surrounding subscripts.
- Related: reading a global in the guard and again in the body (`if (g[10] != 0) { id = g[10]; ... }`) costs an extra `adds rN, r0, #0` — the compare uses the loaded value and the body's copy gets its own register. Hoisting the read above the `if` removes that move, so match whichever the target has.
- The same choice also decides *which* callee-saved registers a parameter and the array's base address get, with no instruction-count difference. `FUN_082405c0` needed `SoundID16 id = g[12];` above the `if`; testing `g[12] != 0` directly gave the identical 32 instructions with two registers swapped (`r6`/`r7`). Its slot-10 twin `Sound_FadeOutBGM` matched with the opposite shape, so don't assume a copy-pasted sibling used the same one.
- Which of the two shapes the target used is readable from the asm: hoisting the read leaves the array's base address in a scratch register (`ldr r0, =g` / `ldrh r0, [r0, #N]`), while testing the global directly and indexing it again keeps the base in its own register across the guard. `Sound_SetBGMTempo` needed the hoisted form for exactly that reason.

### An intermediate result variable can block a store's cross-jump merge

- **Frequency**: `VM_RunExpression`.
- `if (c) { x = A; } else { x = B; } slot->f = x;` and `if (c) { slot->f = A; } else { slot->f = B; }` produce the same merged store, but not the same scheduling around it. In `VM_RunExpression` the `x` version delayed a later call's first-argument setup (`adds r0, r5, #0` emitted after the other two argument registers instead of before them); writing the store directly in both arms fixed it. If argument setup order is the only thing off near a two-armed store, try removing the intermediate variable.
