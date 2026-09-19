# agbcc compiler quirks

A catalog of **source-level idioms** that make agbcc (legacy GCC 2.x, Thumb-1,
`-O2 -fshort-enums`) emit byte-identical code. Each entry: the asm symptom →
the source that reproduces it. Read before inventing a lever for a
non-matching function; extend after discovering a new one.

Three rules keep this file usable:

- **Record only what `make compare` confirmed.** A lever that merely lowers a
  streamdiff/permuter score on a function that stays NON_MATCH is not
  confirmed — it may be a partial fix for a symptom whose real cause is
  elsewhere. Track those in `stuck-points.md` and promote them here once some
  function actually reaches OK using them.
- **Keep the Frequency line.** Each entry lists the functions that confirmed
  it; one confirmation can be coincidence, several is a real rule. Append the
  function whenever an idiom is confirmed again, and never drop a name — same
  discipline as `c-programmer-habits.md`.
- **Route by the asm symptom, not by the C lever that fixed it.** When an entry
  already describes the same instructions differing in the same way, append a
  bullet to it and bump its Frequency instead of opening a near-duplicate. Open
  a new entry only when no existing one covers the symptom.

## Control flow & loop shape

### Branch direction: whichever arm should fall through, write it last

- **Frequency**: `RemoveSpecifiedItem`, `FindFile`, `Video_GetHankakuTiles`, `Video_GetZenkakuTiles`, `Save_GetCoreAddr`, `EntityMsgBus_Register`, `EntityMsgBus_Unregister`, `Demo_RequestNextStep`, `EntityMsg_Send`, `Demo_Resume`, `Demo_IsRunning`, `ArcTan2_8`, `FUN_082375c8`, `MainSprite_Add`, `ScriptShadow_Move`, `SignalStrengthIcon_Create`, `SignalStrengthIcon_Init`, `Entity081d0e20_Create`, `FUN_080eddf8`.
- For `if (c) { A } B`, agbcc makes the trailing statement `B` the fall-through
  and places the if-body `A` out of line. So choose the condition's polarity
  and the order of the two arms by which one the target falls through to, not
  by which reads better. `RemoveSpecifiedItem` (a 2-way dispatcher that needed
  the negated condition written first, matching its sibling `TryAddItem`),
  `FindFile` and `Video_GetHankakuTiles` (a `NULL` guard) all needed the
  condition inverted and the two returns swapped.
- This holds even when **both** arms end in `return`: with no shared code after
  the `if`, `if(){return;}return;` and `if(){return;}else{return;}` compile
  identically, so the `else` is irrelevant — only the written order matters.
- Two guards in a row: only the **last** guard's return moves to the end.
  The first one stays inline (`bne` jumps over it). `Demo_RequestNextStep` needed
  `if (g == NULL) return -1; if (g->f != 0) return -2; g->f = 1; return 0;`.
  Here `-1` stays inline and `-2` is placed at the end. Nesting it as
  `if (g != NULL) { ... } return -1;` flips both branches.
- A guard with two conditions reverses the single-guard rule. `if (a && b) { A } return B;` put `A` inline and `B` at the end. `if (!a || !b) return B; A` put `B` inline and `A` at the end. `Demo_Resume` and `Demo_IsRunning` needed the `||` form. The opposite also occurs: `ScriptShadow_Move` needed `if (a && b) { ...; return 0; } return -1;` (success inline, `-1` at the end) while its sibling `ScriptShadow_SetMode` matched with the `||` guard, so try both.
- The same single guard compiled both ways in one sibling pair. `MainSprite_Setup` matched with `if (p->active != 0) return -1; ...; return 0;` (`-1` inline). `MainSprite_Add`, which has an extra `if`/`else` before the guard, needed `if (p->active == 0) { ...; return 0; } return -1;` (`bne` to `-1` at the end). If the early-return form leaves the return inline when the target puts it at the end, nest the body.
- When the returned value is still in `r0` from the call just made, an early `return x;` beats falling through to the function's shared `return x;`: the target branches *past* the join's `adds r0, rN, #0` instead of into it. `SignalStrengthIcon_Create` (`p = Get(); if (p != NULL) return p;`) showed up as a streamdiff with equal instruction counts and only a branch target one instruction off.
- The same applies when the value comes from a **global** rather than a call, and there the fix is to name it twice. `Entity081d0e20_Create` matched only as `if (gEntity081d0e20 != NULL) { return gEntity081d0e20; }`; assigning it to the local that the rest of the function reuses (`p = gEntity081d0e20; if (p != NULL) return p;`) put it in a callee-saved register and branched *into* the join instead of past it.
- The guard form also decides whether a saved pointer is reloaded afterwards. `SignalStrengthIcon_Init` nested as `if (f != NULL) { ... } return -1;` put `-1` inline *and* emitted `adds r0, r2, #0` before the struct copy; the early-return `if (f == NULL) return -1;` fixed both at once, letting the copy read the call result still in `r0`.

### `pop {r1}; bx r1` means a non-void return type, even with nothing returned

- **Frequency**: `AuxShadow_SetSprite`, `AuxShadow_SetAffine`.
- A `void` function restores the return address into `r0` (`pop {r0}` / `bx r0`). A function declared to return a value uses `r1`, so `r0` survives. `AuxShadow_SetSprite` ends with `pop {r1}` but never sets `r0` after its last call. Declaring it `s32` with no `return` statement matched; `void` gave `pop {r0}`.
- The return type also shifts every scratch register up by one, because `r0` is no longer free. `AuxShadow_SetAffine` as `void` used `r0`/`r1`/`r2` for the flag update and `pop {r0}`; as `s32` it used `r1`/`r2`/`r3` and `pop {r1}`, which matched. So a register-renamed diff that also has `pop {r0}` vs `pop {r1}` is this lever, not a register-allocation problem.

### Guards chained with `&&` (or nested `if`s) drop the `adds r0, rN, #0` reload before the next call

- **Frequency**: `ScriptShadow_Create`, `ScriptShadow_Delete`.
- `if (mgr != NULL && f(mgr, id) == NULL && (p = Malloc(n)) != NULL)` reuses the value still in `r0` as the next call's first argument. The target reloads it from the saved register (`adds r0, r5, #0`) before each call. Splitting the chain into separate guards (`mgr = f(); if (mgr == NULL) return -1; if (g(mgr, id) != NULL) return -1; ...`) restored the three reloads. Nested `if (mgr != NULL) { shadow = g(mgr, id); if (shadow != NULL) { ... } }` loses the reload the same way; early returns fixed `ScriptShadow_Delete` too. The success path of the final `&&` still had to come first (`if (a >= 0 && b >= 0) { ...; return 0; } Free(p); return -1;`) to put `Free` right before the shared `return -1`.

### switch case body layout follows source order, independent of dispatch order

- **Frequency**: `VM_ReadContainerLength`, `EntityE06A_SetupSprite`.
- For a sparse `switch` (few, non-contiguous case values), agbcc lays out each case's compiled body in the same order the `case` labels appear in the source — but the *comparison/dispatch* instructions it emits to reach them can use a completely different order (e.g. a value-magnitude-based pivot). Matching only the dispatch order isn't enough; the case labels' source order must also match, or bodies land in the wrong place in the output.
- The dispatch-first layout is also what lets agbcc cross-jump identical case tails into one. `EntityE06A_SetupSprite` has two cases ending in the same `y -= v;`: written as `if (x == 1) ... else if (x == 2) ...` the subtraction was emitted twice, and the `switch` form merged them and branched past the join in the default case.

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

- **Frequency**: `Script_LoadPointer`, `FUN_0822a470`, `PlaySound_0824078c`, `FUN_0822da50`, `FUN_0822d9f0`, `MainSprite_Add`.
- Hoisting the mask also moves *where* the constant is built. In `PlaySound_0824078c`, `if (!((a | b) & 0x400))` built `movs #0x80` / `lsls #3` right before the `ands`; the target builds it first, before both loads. Swapping the `&` operands changed nothing; `u32 mask = 0x400;` as its own statement before the `if` matched.
- Writing a single-bit test as one fused expression — `(byte & (1 << bit)) != 0` — lets agbcc's combiner recognize the "extract one bit" idiom and emit the cheaper `asrs`/`ands` (shift the target bit to position 0, mask with 1) instead of the general nonzero-materialize trick above. If the target's real assembly uses the general `rsbs`/`orrs`/`lsrs` trick instead (i.e. the shift-based optimization did NOT happen), the mask must be computed in its own prior statement — `s32 mask = 1 << bit; ... (byte & mask) != 0;` — splitting it into a separate pseudo-register apparently hides the "single bit" shape from the combiner and falls back to the general path.
- The lever also works with a plain literal mask, not just `1 << bit`: in `FUN_0822a470`, `(flags & 0x80) != 0` compiled to `lsrs r1, rN, #7` / `ands r1, r4` (and pinned one extra callee-saved register), while hoisting the constant into its own statement (`mask = 0x80; ... (flags & mask) != 0`) fell back to the general `movs #0x80` / `ands` path and fixed the register allocation at the same time. Constant propagation does not undo the split.
- As a call argument, hand-rolling the trick also avoids the shift form without a separate statement. In `MainSprite_Add`, `f(p, (flags & 0x80) != 0)` gave `lsrs #7` / `movs #1` / `ands`, while `f(p, (u32)-(flags & 0x80) >> 31)` gave the target's `movs #0x80` / `ands` / `rsbs` / `lsrs #0x1f` (no `orrs`, since the masked value is never negative).
- That statement split has a side effect: splitting *only* the mask into its own statement (leaving the address `src + (offset >> 3)` inline) reintroduced an unrelated register-allocation regression (two unrelated parameters got pinned into extra callee-saved registers for the whole function instead of just one). Also splitting the address into its own pointer variable (`u8* p = src + (offset >> 3);`) alongside the mask fixed it. Net effect: both the mask AND the address need their own statement (address first, then mask, matching the target's instruction order) to get byte-identical output.

## Integer width & sign extension

### Narrow NAKED-callee parameter forces truncation at a single call site

- **Frequency**: `FUN_082402c8`, `FUN_082402e0`, `FUN_08240428`, `sound_082403b8`, `sound_08240728`, `Entity6978_Create`, `ParticleShadow_Init`, `AuxShadow_Init`, `AuxShadow_SetScaleParams`.
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
- The reverse also holds: when the target *does* truncate before the call, narrow the callee. `Entity6978_Create(u32 id)` has `lsls #16` / `lsrs #16` before `bl Entity6978_Init`, which matched once `Entity6978_Init`'s parameter was declared `u16 id`.
- The same applies to the function's *own* parameter. `ParticleShadow_Init(..., u8 kind)` truncated `kind` at entry (`lsls #0x18` / `lsrs #0x18`), but the target copies it untouched (`adds r4, r2, #0`) and only narrows at the test (`lsls r0, r4, #0x18` / `cmp`). Declaring `s32 kind` and writing `(u8)kind == 0` at the use matched; the `strb` store needs no cast.
- `AuxShadow_Init` has ten narrow fields filled straight from its parameters (`strb r5, [r0]` with no `lsls`/`lsrs` first). Declaring every one of them `s32` matched; the stores truncate by themselves.

### `s16` locals defer sign-extension to each use

- **Frequency**: `VM_CallScript`, `Entity28CB_Update`.
- `s16 x = expr;` keeps the raw value and emits `lsls`/`asrs` at every *use*; `s32 x = (s16)expr;` sign-extends once at the *assignment*. Pick whichever places the extension where the target has it.
- Reading an `s16` field into an `s32` local (`s32 spread = p->q_spread;`) gives a single `ldrsh` that every use shares. An `s16` local gives `ldrh` with `lsls`/`asrs` at each use (`Entity28CB_Update`).

### `u16` vs `s16` counters increment differently (and `s16` can still use `lsr`)

- **Frequency**: `VM_Ctrl_22FF`.
- `u16 n; n++;` adds first, then truncates: `adds #1` / `lsls #16` / `lsrs #16`. `s16 n; n++;` shifts up first and adds there: `lsls #16` / `adds 0x10000` (built with `movs #0x80` + `lsls #9`) / `lsrs #16`. If the target has the second shape, the counter is `s16` — no natural `u16` spelling (`n = n + 1`, `for(...; n++)`, `(u16)(n + 1)`, `(n + 1) & 0xFFFF`, `arr[n++]`) produces it.
- Don't read the `lsr` as proof of `u16`: an `s16` counter that is never compared needs no sign extension, so agbcc drops the `asr`. Adding a comparison on the counter (e.g. `n < 16`) brings the `asr` back.

### `(u8)(x + c) >> n` folds into shifts; `((x + c) & 0xFF) >> n` keeps the `ands`

- **Frequency**: `FUN_08237834`, `FUN_08237848`.
- `(u8)(val + 0x10) >> 5` compiles to `lsls #24` / `adds 0x10 << 24` / `lsrs #29` (the add is done in the top byte). The target's `adds #0x10` / `movs #0xFF` / `ands` / `asrs #5` comes from `((val + 0x10) & 0xFF) >> 5`; the `asrs` shows the masked value stayed a signed `int`.

### A `u16` local updated with `|=` truncates before a 16-bit store; writing the `|` into the store does not

- **Frequency**: `Sio_StartParentTimer`, `Sio_ParentTimerIntr`, `Sio_ChildSerialIntr`, `Entity87FE_Update`, `Entity87FE_Init`, `FUN_08237098`, `FUN_08237064`.
- A `u16` local built up with `send |= ...` in `Sio_ParentTimerIntr` / `Sio_ChildSerialIntr` also left an extra `lsls #16` / `lsrs #16` before the store; the target has none, and declaring it `s32` matched. In the same functions, `u16 m2 = REG_SIOMULTI2;` added a register copy (`adds r6, r2, #0`) that the target lacks; `s32` locals for the three register reads removed it.
- `u16 ie = REG_IE; ... REG_IE = ie | 0x40;` emits `orrs` then `strh` directly. The target has `orrs` / `lsls #16` / `lsrs #16` / `strh`, which `ie |= 0x40; REG_IE = ie;` reproduces: the assignment back to the `u16` local keeps its truncation even though the store would drop the upper half anyway.
- The same truncation moves when a `u16` compound assignment feeds a comparison. In `Entity87FE_Update` the target stores the sum, reloads the pointer, loads the bound, and only then emits `lsls #16` / `lsrs #16` before the `cmp` — `if ((p->player->hp += step) >= p->player->maxHP)` places it there, because the conversion applies where the assignment's value is read. A `u16` local (`hp = a + b; ... if (hp >= max)`) truncates right after the `adds` instead, and a plain `+=` followed by re-reading the field drops the reuse entirely (6 fewer instructions). A `u8` field behaves the same way with a `lsls #0x18` — `if ((p->wait = (speed * p->duration) >> 6) == 0)` matched `FUN_08237098` first try.

## Operand order & scheduling

### Pointer-add Rn/Rm order depends on how the address is spelled

- **Frequency**: `Script_StorePointerCore`, `FUN_0822ea10`, `EntityMsgBus_Post`.
- Scaling an index by 2 as `offset << 1` vs `offset * 2` is value-identical, but agbcc doesn't always canonicalize the two the same way: in `*(u16*)(dst + (offset << 1))`, the shift form compiled the subsequent `dst + offset*2` addition as `adds r0, r4, r0` (dst first); the literal `offset * 2` form instead gave `adds r0, r0, r4` (offset-term first) — same instruction, swapped operands, real byte difference. When a pointer-add's Rn/Rm order doesn't match and the scale is a power of 2, try switching between `<<` and `*` for the scale before reaching for other levers.
- The same symptom also comes from the *pointer vs subscript* choice, and that lever is independent of the one above. In `FUN_0822ea10`, holding the address in a variable (`u32* p = &base[i];` then `*p`) emitted `adds r3, r1, r0` (base first); indexing at each use (`base[i]`, three times) emitted `adds r3, r0, r1` (offset first) and matched. Switching `<<`/`*` did nothing there, so try both levers.
- The pointer-vs-subscript choice also changes how a field offset is grouped. In `EntityMsgBus_Post`, `u8* count = &node->unk_6[side];` emitted `adds r1, r4, #6` / `adds r3, r5, r1`, which is `node + (side + 6)`. Writing `node->unk_6[side]` at each use emitted `adds r1, r5, #6` / `adds r3, r1, r4`, which is `(node + 6) + side`, and matched.

### `==` operand order sets the `cmp` operands and which value keeps the address register

- **Frequency**: `sound_08240740`, `Save_WriteCore`.
- A call result compared directly (`if (f(...) != len + 8)`) keeps the result in `r0` and builds `len + 8` in `r1`; the target had `adds r1, r0, #0` / `adds r0, r5, #0` / `adds r0, #8` / `cmp r1, r0`. Swapping the operands made it worse, but assigning the result to a local first (`ret = f(...); if (ret != len + 8)`) matched.
- `a[i] == x` and `x == a[i]` are not canonicalized. In `if (gSoundIDs[gSongTable[id].ms] == id) { gSoundIDs[...] = 0; ... }`, agbcc emitted `adds r1, r0, r2` / `ldrh r0, [r1]` / `cmp r0, r4` and stored through `r1`; the target had `adds r0, r0, r2` / `ldrh r1, [r0]` / `cmp r4, r1` and stored through `r0`. Writing `id == gSoundIDs[...]` matched. When a streamdiff shows only a swapped `cmp` plus the loaded value and its address trading registers, swap the operands of the comparison.

### The `for` increment's comma order is the order of the two `adds`

- **Frequency**: `Video_GetActorSprite`.
- In a search loop that walks a pointer and a counter together, `for (...; i++, a++)` emitted `adds r2, #1` before `adds r4, #0xc`; the target had the pointer first, and `a++, i++` matched. Siblings such as `FUN_0822e8d0` are also written pointer-first (`p++, i++`).

### Two reads of one halfword (`ldrh` + `ldrb`) survive only in low-byte-first order

- **Frequency**: `Video_CreateSpriteLUT`, `OpenCollisionMapFile`, `GetTilemapFile`.
- The target read `gSpriteSizeTable[i]` twice (`ldrh r1, [r6]` / `ldrb r2, [r6]`). Writing `s32 w = (u8)t[i]; s32 h = t[i] >> 8;` kept both loads; writing `h` first CSE'd them into one `ldrh` plus `lsls #24` / `lsrs #24` for the low byte. The same function also needed `tw = w >> 3; th = h >> 3;` as locals so the `asrs` land right after the loads instead of at each store.
- The merge also runs the other way, collapsing two adjacent *byte* compares into one halfword load. `OpenCollisionMapFile` checks a 4-byte magic: `f->magic[0] == 0x48 && f->magic[1] == 0x50` through the `char magic[4]` field emitted a single `ldrh` and one `cmp`, losing the short-circuit. The target keeps two `ldrb`/`cmp` pairs with a branch between them, which reading through a `u8 *` local (`u8 *magic = file;` then `magic[0]` / `magic[1]`) reproduces.

### A constant or global address materializes in the wrong place

- **Frequency**: `Sprite_SetPlttID`, `sound_08240264`, `FUN_082436dc`, `FUN_08089d50`, `FUN_08089e98`, `FUN_08089f58`, `FUN_08089d24`, `FUN_08089f38`, `FUN_0823a9f4`, `FUN_0823aa10`, `FUN_08240360`, `FUN_082405c0`, `Sound_SetBGMTempo`, `FUN_082410e8`, `FreezeEffect_GatherSubParticles`, `IsWeaponLevelChanged`, `ParticleShadow_Init`.
- **Symptom**: a streamdiff shows only a `movs rN, #k` or `ldr rN, =SYMBOL` sitting earlier or later than the target has it — usually with registers renamed, sometimes with one extra callee-saved register, and often with an identical instruction count. agbcc materializes each of these where the expression tree first needs it, so the lever is always *how the surrounding expression is split into statements*, never the arithmetic. The mask-hoisting bullets under "`(x & (1<<n)) != 0` auto-optimizes" are the same mechanism seen through a bit test.

- The operand order of a `+` also moves a global's load. In `ParticleShadow_Init`, `... * 34 + gMgr->group0->tile` loaded the manager pointer after the multiply; writing the global term first, `gMgr->group0->tile + ... * 34`, loaded it before the two `ldrb`s as the target does.

**Splitting a value out into its own statement makes it materialize earlier.**

- A store's constant. The target loads `movs r0, #2` *before* computing the store address (`subs r1, #0xe`), but `p->state = 2;` computes the address first. The permuter found a temporary (`v = 2; p->state = v;`) for `FUN_08089d24`; the natural form that gives the same code is a helper — `static inline void Entity28CB_SetState(Entity28CB* p, u16 state) { p->state = state; p->stateTimer = 0; }` — and since every state change in that entity also resets `stateTimer`, the original probably had one. In `FUN_08089f38`, eight rewrites (direct stores, a merged `timer` local, both statement orders) all left the two registers swapped, and `Entity28CB_SetState(p, 6)` matched on the first try, merged timer store included.
- A read-modify-write of a global. `gEntityDisableFlags &= ~2;` (and `= ~2 & g`) emitted `ldr r1, [r0]` before building `~2`; the target builds the mask first (`movs r1, #3` / `rsbs r1, r1, #0` / `ldr r0, [r2]`), which `static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }` called as `EnableEntityFlags(2)` reproduces (`FUN_0823a9f4`).
- A mask in a condition. `if (!((gFlag030047a4 | u32_030047a0) & 1))` built `movs r1, #1` right before the `ands`; the target builds it first, before both loads. A helper `static inline u32 TestFlag030047a4(u32 flags) { return (gFlag030047a4 | u32_030047a0) & flags; }` matched (`FUN_0823aa10`, which also needed `DisableEntityFlags(2)` for its `|= 2`).
- A table's base address. `u16* table = gRandomTable;` loads `=gRandomTable` before `=gRandTableIdx`; a global struct's address declared first as a pointer local (`SavedHBlankState* s = &gSavedHBlankState;`) is loaded at function entry and kept in a callee-saved register across calls, where writing `gSavedHBlankState.field` at each use loaded it late and needed one less saved register.
- A field re-read. `p->plttID = id; p->pltt = &gObjPlttData[p->plttID * 16];` emitted `ldr rN, =gObjPlttData` before `ldrh r2, [r0, #0x3a]` — as did `gObjPlttData + ...`, `<< 4`, and `index + gObjPlttData`. The target reloads the field first, which a `u16` local in its own statement (`u16 i; p->plttID = id; i = p->plttID; p->pltt = &gObjPlttData[i * 16];`) matched (`Sprite_SetPlttID`).
- An inner call used as an argument. `f(0, (T*)gPtr, g(0x28))` loaded `=gPtr` and its value into a callee-saved register before calling `g`; the target calls `g` first and loads `gPtr` right before `f`, which `s32 len = g(0x28); f(0, (T*)gPtr, len);` matched.
- An argument shared by several calls. `FreezeEffect_GatherSubParticles` divides three times by `n + 1`; writing `Div(..., n + 1)` at each call computed it just before the first `Div`, while the target computes it once right after `n` (`adds r6, r4, #1`) — a local `d = n + 1;` placed directly after `n = 8 - frame;` matched.
- A field compared against a call result. `if (p->weaponLv[i] != GetWeaponSkillLevel(i))` kept the field's address in a callee-saved register and loaded it after the call; the target loads the value first (`ldrh r4, [r0]` before the `bl`), which `lv = p->weaponLv[i]; if (lv != GetWeaponSkillLevel(i))` matched (`IsWeaponLevelChanged`).
- A global read in both a guard and the body. `if (g[10] != 0) { id = g[10]; ... }` costs an extra `adds rN, r0, #0`, because the compare uses the loaded value and the body's copy gets its own register; hoisting the read above the `if` removes that move.

**Merging it back into one expression makes it materialize later.**

- Two draws from the random table (`gRandomTable[(gRandTableIdx + 1) & 0x3FF]`) in `FUN_08089d50` needed the *first* index kept in a local with only the second stored — storing `gRandTableIdx` twice kept the first `str` — alongside the table pointer local above and a `u16` local for each value before `& 0x1F` (which keeps the mask in its own register, `ands r0, r4`). The permuter found the last two. A `static inline` returning `gRandomTable[++idx]` still stored the first index; the original RNG macro or inline is not known yet.
- After a call, `u16 ms = gSongTable[id].ms; f(gMPlayTable[ms].info); gSoundIDs[ms] = id;` loaded `=gSongTable` first and `=gMPlayTable` just before its use. The target loads `=gMPlayTable` **before** `=gSongTable`, which writing the index inline — `f(gMPlayTable[gSongTable[id].ms].info); gSoundIDs[gSongTable[id].ms] = id;` — matched (CSE still reuses the `ms*2` for the second subscript).

**Both directions occur for the same code shape, so try both.**

- The nested-subscript case above cuts the other way too: written as one expression, `gMPlayTable[gSongTable[id].ms].info` hoists the outer table's pool `ldr` *before* the inner subscript is read, and splitting the inner index into its own statement (`u16 ms = gSongTable[id].ms;`) emits that `ldr` after it. One function needed the merged form and another the split form, so when only a pool `ldr` sits in the wrong place, try splitting *and* merging before looking elsewhere.
- The choice can also decide only *which* callee-saved registers a parameter and a base address get, with no instruction-count difference at all. `FUN_082405c0` needed `SoundID16 id = g[12];` above the `if`, while testing `g[12] != 0` directly gave the identical 32 instructions with `r6`/`r7` swapped — and its slot-10 twin `Sound_FadeOutBGM` matched with the opposite shape, so don't assume a copy-pasted sibling used the same one.
- Which shape the target used is readable from the asm: hoisting the read leaves the array's base address in a scratch register (`ldr r0, =g` / `ldrh r0, [r0, #N]`), while testing the global directly and indexing it again keeps the base in its own register across the guard. `Sound_SetBGMTempo` needed the hoisted form for exactly that reason, and `Sprite_LoadSprite` writes `Sprite_SetPlttID`'s two lines inline and matches with the global first — so check the target's order before choosing.

### A struct-field store does not force a global pointer to be reloaded; a cast store does

- **Frequency**: `Save_WriteCore`.
- After `gStat->magicNumber = x;`, agbcc assumes the struct-field store cannot touch the scalar pointer `gStat`, so it reuses the loaded pointer for `f(&gStat->magicNumber, 4)`. The target reloads it (`ldr r2, =gStat` / `ldr r1, [r2]` / `str r0, [r1]` / `ldr r0, [r2]`), which happens only when the store is not a struct-field access: `*(u32*)gStat = x; f(gStat, 4);` matched. If the target re-reads a global pointer right after storing through it, write the store without the field.

### `(a * 2) * b` moves the doubling onto `b`; `(a << 1) * b` keeps it on `a`

- **Frequency**: `FUN_0822bcf4`, `FUN_08089b48`, `BlendPlttToColor`, `FUN_0823c35c`.
- The target computed a row pitch as `ldrsh r0, [...]` / `lsls r0, r0, #1` / `muls r0, r2`. Both `y * (w * 2)` and `(w * 2) * y` emitted `lsls r2, r2, #1` instead, on the other operand, because agbcc reassociates a constant factor through a multiply. Writing the doubling as a shift, `(w << 1) * y`, is not reassociated and matched.
- Operand order also decides which value is copied before `muls`. In `FUN_08089b48`, `t * g2` emitted `adds r1, r7, #0` / `muls r1, r2` (copy `t`). The target has `adds r1, r2, #0` / `muls r1, r7` (copy `g2`), and writing `g2 * t` matched.
- Same in `BlendPlttToColor`: the target copies the channel (`adds r3, r0, #0` / `muls r3, r5`), so the channel comes first: `(*src & 0x1F) * ((1 << shift) - t)`.
- `+` behaves the same way, and the order is the *reverse* of what you write. In `FUN_0823c35c`, `min->x + min->z - min->y` emitted `ldrh` of `z` before `x`; the target loads `x` first, which `min->z + min->x - min->y` produced. When two field loads feeding one `adds` are swapped, flip the written operand order.

### `-y * 256` reuses a `-y` computed earlier; `y * -256` negates the product separately

- **Frequency**: `ArcTan2_8`.
- With `if (x > -y) return t[Div(-y * 256, x)];` agbcc CSE's the `-y` from the compare, overwriting `y` (`rsbs r1, r1` / `lsls r0, r1, #8`). The target keeps `y` alive and negates after the shift (`rsbs r3, r1` for the compare, then `lsls r0, r1, #8` / `rsbs r0, r0`), which `Div(y * -256, x)` reproduces.

### A zero stored from a reused local takes that local's register

- **Frequency**: `ReadKeyInput`.
- In `ReadKeyInput`, the loop that clears players 1-4 stores 0 twice (`strh r3, [r1]` / `strh r3, [r1, #2]`), with the 0 in `r3`, the register that held `keys` a moment earlier. Writing `gInput[i].down = 0; gInput[i].pressed = 0;` (or a chained `= 0`) put the 0 in a fresh `r0`. Setting the existing local once, `keys = 0;` before the loop, and storing `keys` (`down = keys; pressed = keys;`) matched. Going further and reusing the full update formula (`pressed = keys & ~prev`) with `keys = 0` did not fold and added four instructions.

### A `u16` parameter saved in a wider local keeps the parameter as the working variable

- **Frequency**: `GetFile`, `GetTilemapFile`.
- `GetFile(FileID directoryID, FileID fileID)` rewrites `fileID` in each `case` and passes the original to `GetAssetFile` at the end. The target truncates the incoming `fileID` into `r1`, copies it to `r7` (`adds r7, r1, #0`), and at the call moves `r7` into `r2` first, before building the 4th argument. A copy declared `FileID file = fileID;` either swapped `r1`/`r7` or moved `r2` last. Declaring the copy as `u32 file = fileID;` (found by the permuter as `int`) matched.

### Two loops sharing one counter variable shift the register allocation

- **Frequency**: `LevelUpper_Update`.
- `LevelUpper_Update` has an 8-iteration loop in one branch and a 5-iteration loop in the other. With one `s32 i` for both, every register was off by one (`p` in `r5` instead of `r4`, the counter and the stored 0 swapped). Giving the first loop its own counter (`s32 i, j;`, `for (j = 0; j < 8; j++)`) matched with no other change.

### An `|` chain accumulates left-to-right exactly as written

- **Frequency**: `FUN_0822a4fc`, `FUN_0822bcf4`, `FUN_08089b48`, `BlendPlttToColor`, `BlendPltt`.
- agbcc does not reassociate `a | b | c`. Written flat, it emits `a|b` into the accumulator and then ORs `c` (`orrs acc, b` ... `orrs acc, c`); written `a | (b | c)`, it builds `b|c` in a separate register first and ORs that into `a` once (`orrs r1, r0` then `orrs r3, r1`). Both forms have the same instruction count, so a streamdiff shows only swapped `orrs` operands — plus, because the grouped form needs one more value live at once, a different `push` list (`{r4, lr}` vs `{r4, r5, lr}`) and every register shifted by one. When the register allocation is off by exactly one callee-saved register in an expression built from three or more `|` terms, try regrouping the parentheses before suspecting anything else. The same should apply to other associative operators (`+`, `&`, `^`).
- Masks follow the same order as the source. `(r & 0x1F) | (g & 0x3E0) | (b & 0x7C00)` interleaves them: `ands`, `ands`, `orrs`, `ands`, `orrs`. The target did all three `ands` first. Separate statements `r &= 0x1F; g &= 0x3E0; b &= 0x7C00; *dst = r | g | b;` matched (`FUN_08089b48`). Putting each mask into the line that computes the value (`r = (...) >> 6) & 0x1F;`) instead changed the register allocation for the whole loop.
- The opposite case, `BlendPlttToColor` (blend 16 colors toward one color): the target interleaves `ands`/`orrs`, so the single expression `*dst = (r & 0x1F) | (g & 0x3E0) | (b & 0x7C00);` matched. It also masks each channel straight from `*src` inside its own formula (`((*src & 0x3E0) * k + g2 * t) >> shift`). Pulling all three channels into locals first put three `ands` before the multiplies and spilled the loop counter to the stack.

### Bitfield store vs hand-written mask differ in operand evaluation order

- **Frequency**: `VM_CallScript`, `ScriptShadow_CreateFromScript`, `ScriptShadow_MoveFromScript`.
- Assigning a 16-bit bitfield (`u32 argc : 16;` → `s.argc = n;`) computes the truncated value **first** (`lsls`/`lsrs`), then loads the word, ANDs the mask constant, ORs and stores. The hand-written equivalent `w = (w & 0xFFFF0000) | (u16)n;` loads and masks first, then truncates. Same instructions, different order — if the order doesn't match, the original almost certainly used a bitfield.
- The same shape on a *stack local* means the original declared its coordinates as bitfields, not `s16`. `ScriptShadow_CreateFromScript` fills a `Vec3` from three `Script_GetValue()` calls with `ldr [sp]` / `ands 0xFFFF0000` / `orrs` / `str [sp]` instead of `strh`. `struct { u32 x : 16; u32 y : 16; u32 z : 16; } pos;` passed as `(Vec3*)&pos` matched (x and y share the first word, z starts the second).

### `arr[i]` vs `*p++` change where the walking pointer is initialized

- **Frequency**: `FUN_082315c0`, `FUN_0824082c`, `FUN_08089ce0`, `Entity0800a89c_ReleaseSwarm`, `Entity0800a89c_UpdateSwarm`.
- Both compile to the same `stm rN!, {r0}` walking store, but the init of that pointer lands in a different place. `*out++ = v;` modifies the parameter, so agbcc copies it to a callee-saved register in the **entry block**, before any loop-invariant hoists. `out[i] = v;` leaves the parameter alone and lets loop strength reduction create the pointer, so its init goes in the **preheader**, after the hoists — swapping the order of the two setup instructions. (Strength reduction also frees `i` to be reversed into a down-counter while the pointer still walks up.)
- A walking pointer compared against `base + const` (`adds r0, r5, #0` / `adds r0, #0x14` / `cmp r4, r0`) with a **signed** loop exit (`ble`) and no pre-loop test is an `s32 i` index loop, not a pointer loop: loop strength reduction deletes `i` and rewrites `i == 10` and `i < 32` as compares on the pointer. In `FUN_0824082c`, writing the pointer loop (`p == &arr[10]`, `p <= &arr[31]`) gave a pre-loop `bhi`, unsigned `bls` and pool-loaded addresses; `for (i = 0; i < 32; i++) { if (arr[i]) { if (i == 10) ... } }` matched, including the second walking pointer used for the `arr[i]` call argument.
- The same split decides whether a **member offset** is folded into the pointer. `f(&arr[i].member)` initialises one pointer at `&arr[0].member` and steps it by `sizeof(*arr)`; an explicit `T* p = arr; f(&p->member); p++;` keeps `p` at `arr` and pays an `adds r0, #offset` every iteration. `Entity0800a89c_ReleaseSwarm` (`FUN_0822dabc(&swarm->bugs[i].ptcl)`) needed the index form.
- With an explicit walker **and** an index that the body still needs, both the init order and the increment order are visible. `Entity0800a89c_UpdateSwarm` matched only as `for (i = 0, bug = swarm->bugs; i < 4; i++) { ...; bug++; }`: putting `bug = ...` first swapped the two registers, and putting `bug++` in the `for` increment emitted it after `i++` instead of before.

### `a = b = v` stores `b` first and evaluates `v` once

- **Frequency**: `Entity28CB_Update`.
- Two statements `n->q_scaleX = p->q_scale >> 4; n->q_scaleY = p->q_scale >> 4;` load `q_scale` twice, because the byte store may alias it. The target loaded it once and stored `+8` (X) before `+9` (Y). A chained assignment evaluates the value once, but stores the inner target first, so it has to be written `n->q_scaleY = n->q_scaleX = p->q_scale >> 4;` to get X then Y.

### Two addresses in one object share a base register; separate symbols get their own pool constants

- **Frequency**: `OpenCollisionMapFile`, `GetTilemapFile`.
- Passing `arr` to a call and then returning `&arr[4]` held the base in a callee-saved register (`ldr r4, =arr` / `adds r1, r4, #0` / `adds r0, r4, #4`) and cost a `push {r4, lr}`. The target loads `=arr` and `=arr+4` as two independent pool constants and pushes only `lr` — agbcc shares a base only when both addresses come from the same object, so splitting the one `u8 arr[16384]` definition into two adjacent externs (a 4-byte head and the body) matched.

### An intermediate result variable can block a store's cross-jump merge

- **Frequency**: `VM_RunExpression`.
- `if (c) { x = A; } else { x = B; } slot->f = x;` and `if (c) { slot->f = A; } else { slot->f = B; }` produce the same merged store, but not the same scheduling around it. In `VM_RunExpression` the `x` version delayed a later call's first-argument setup (`adds r0, r5, #0` emitted after the other two argument registers instead of before them); writing the store directly in both arms fixed it. If argument setup order is the only thing off near a two-armed store, try removing the intermediate variable.

### A returned boolean built with one branch: initialise, then clear

- **Frequency**: `FUN_080eddc8`.
- `movs r1, #1` / `cmp` / `bgt` over a `movs r1, #0` / `adds r0, r1, #0` is not
  `return x > 0;` and not a ternary — agbcc canonicalises both of those into the
  opposite polarity (`movs r1, #0` first, `ble` over `movs r1, #1`), and writing
  the comparison inverted (`x <= 0 ? FALSE : TRUE`) does not move it either.
  What matches is an explicit variable: `alive = TRUE; if (x <= 0) { alive = FALSE; }
  return alive;`.
- The **load** has to happen before the `= TRUE`, or the field access is
  scheduled after it and a second scratch register appears. Read the field into
  its own local first (`hp = p->unk_184;`), then initialise the flag. Declaring
  both at the top of the function C89-style and assigning them in that order is
  what the target looks like.

### A bit constant loaded before the field it is OR'd into needs its own local

- **Frequency**: `FUN_0823b47c`, `FUN_080ec900`, `EnemyManager_Update`, `FUN_080ee9d4`, `FUN_080ec92c`.
- `p->flags |= 4;` emits `ldrh` then `movs r2, #4`; the target had `movs r2, #4` first and used that register as the `orrs` destination. Writing `4 | p->flags` does not help — agbcc canonicalises the constant to the right. Assigning it first (`u16 flag = 4; p->flags |= flag;`) puts the constant in its own register before the load and matches.
- Holds for a global's field too, and inside an `if` body: `FUN_080ec900` needed `u16 flag = 1; gStat->unk_934 |= flag;` in the same shape.
- Clearing a bit from a **u16** field is a separate trap: `f &= ~0x20;` narrows the
  constant to `0xFFDF` and loads it from the pool, and so do `-0x21` and an
  `s32` local holding `~0x20`. The target's `movs r0, #0x21` / `rsbs r0, r0, #0`
  is a 32-bit `-33`, which you get by complementing the local instead of the
  literal: `flag = 0x20; f &= ~flag;` keeps the expression `int`. `FUN_080ee9d4`
  sets and clears the same bit in the two arms of one `if`, and both arms use
  the same `u16 flag` local this way.
- `&=` with a complement mask behaves the same: `p->flags &= ~0x1C000;` loads the field first, the target loaded the mask first. What matters is where the local is **assigned**, not where it is declared — C89-style `u32 mask;` at the top of the function with `mask = ~0x1C000;` immediately before the `&=` matches, while initialising it at the declaration does not (the constant then has to survive six intervening calls). `EnemyManager_Update`.

