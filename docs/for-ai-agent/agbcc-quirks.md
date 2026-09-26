# agbcc compiler quirks

A catalog of **source-level idioms** that make agbcc (legacy GCC 2.x, Thumb-1,
`-O2 -fshort-enums`) emit byte-identical code. Each entry: the asm symptom →
the source that reproduces it. Read before inventing a lever for a
non-matching function; extend after discovering a new one.

Three rules keep this file usable:

- **Record only what `make compare` confirmed.** A lever that merely lowers a
  streamdiff/permuter score on a function that stays NON_MATCH is not
  confirmed — it may be a partial fix for a symptom whose real cause is
  elsewhere. Leave those in the function's `NONMATCHING_C` block and promote
  them here once some function actually reaches OK using them.
- **Keep the Frequency line.** Each entry lists the functions that confirmed
  it; one confirmation can be coincidence, several is a real rule. Append the
  function whenever an idiom is confirmed again, and never drop a name — same
  discipline as `c-programmer-habits.md`.
- **Route by the asm symptom, not by the C lever that fixed it.** When an entry
  already describes the same instructions differing in the same way, append a
  bullet to it and bump its Frequency instead of opening a near-duplicate. Open
  a new entry only when no existing one covers the symptom.

## Control flow & loop shape

### Which arm falls into the epilogue: the two spellings are not interchangeable

- **Frequency**: `RemoveSpecifiedItem`, `FindFile`, `Video_GetHankakuTiles`, `Video_GetZenkakuTiles`, `Save_GetCoreAddr`, `EntityMsgBus_Register`, `EntityMsgBus_Unregister`, `Demo_RequestNextStep`, `EntityMsg_Send`, `Demo_Resume`, `Demo_IsRunning`, `ArcTan2_8`, `FUN_082375c8`, `MainSprite_Add`, `ScriptShadow_Move`, `SignalStrengthIcon_Create`, `SignalStrengthIcon_Init`, `Entity081d0e20_Create`, `FUN_080eddf8`, `Breakable_TakeStateChanged`, `FUN_0804a3e4`, `FUN_0804a40c`, `TextBox_Open`, `FUN_080488dc`, `TextBox_SetExtendValue`, `FUN_08049eb0`, `FUN_0807b118`.
- **Symptom**: the two arms' bodies appear in the opposite order from the
  target, and one arm carries a `b` to the epilogue that the target puts on
  the other arm. Instruction counts are usually equal.
- For `if (c) { A } B`, exactly one of the two arms falls into the epilogue
  and the other pays a `b`. Which one is **not** predictable from the source
  shape — read it off the target and pick the spelling to match. Inverting the
  condition and swapping the two arms is the lever; `RemoveSpecifiedItem`
  (a 2-way dispatcher that needed the negated condition written first, matching
  its sibling `TryAddItem`), `FindFile` and `Video_GetHankakuTiles` (a `NULL`
  guard) all needed exactly that.
- Two adjacent, near-identical functions can need opposite spellings.
  `FUN_0804a3e4` and `FUN_0804a40c` (`src/text_panel.c`) share a body down to
  the argument list; the only difference is that the first discards the
  callee's result and returns 0, while the second returns it. The first needed
  the guard written first (`if (p == NULL) { return -1; } f(...); return 0;`),
  the second needed it inverted (`if (p != NULL) { return f(...); } return -1;`).
  Do not carry a spelling over from the function next to it.
- The common case is that **the if-body goes to the branch target and falls
  into the epilogue**, while the trailing statement sits inline and pays the
  `b`. This reproduces on a minimal probe and does not depend on how big
  either arm is:

```c
  s32 A(s32 c) { if (c) { return -1; } return 0; }
```
```
	cmp	r0, #0
	bne	.L3          @ the conditional branch goes to the if-body
	mov	r0, #0x0     @ `return 0` (the trailing statement) is inline
	b	.L4          @ ...and pays the b
.L3:
	mov	r0, #0x1
	neg	r0, r0       @ `return -1` (the if-body) is last
.L4:
	pop	{r1}         @ ...and falls into the epilogue
```

- **It is only the common case, not a rule.** `Save_GetCoreAddr` and the second
  guard of `Demo_RequestNextStep` come out exactly like the probe, but
  `MainSprite_Setup` (`if (p->active != 0) return -1;` followed by the body) and
  the *first* guard of `Demo_RequestNextStep` come out the other way round —
  `beq` over an inline `return -1`, with the body falling through. What flips it
  is not established; in `MainSprite_Setup` the register holding the tested
  field is reused as the constant `0` for the stores on the fall-through path,
  which may be what forces that side to be the fall-through. Until it is pinned
  down, treat the layout as something to read, not to predict.
- An `else` changes nothing when **both** arms end in `return`: with no shared
  code after the `if`, `if(){return;}return;` and `if(){return;}else{return;}`
  compile identically, so only the written order matters.
- Two guards in a row: only the **last** guard's return moves to the end.
  The first one stays inline (`bne` jumps over it). `Demo_RequestNextStep` needed
  `if (g == NULL) return -1; if (g->f != 0) return -2; g->f = 1; return 0;`.
  Here `-1` stays inline and `-2` is placed at the end. Nesting it as
  `if (g != NULL) { ... } return -1;` flips both branches.
- A guard with two conditions comes out the other way from the probe above. `if (a && b) { A } return B;` put `A` inline and `B` at the end. `if (!a || !b) return B; A` put `B` inline and `A` at the end. `Demo_Resume` and `Demo_IsRunning` needed the `||` form. The opposite also occurs: `ScriptShadow_Move` needed `if (a && b) { ...; return 0; } return -1;` (success inline, `-1` at the end) while its sibling `ScriptShadow_SetMode` matched with the `||` guard, so try both.
- The same single guard compiled both ways in one sibling pair. `MainSprite_Setup` matched with `if (p->active != 0) return -1; ...; return 0;` (`-1` inline). `MainSprite_Add`, which has an extra `if`/`else` before the guard, needed `if (p->active == 0) { ...; return 0; } return -1;` (`bne` to `-1` at the end). If the early-return form leaves the return inline when the target puts it at the end, nest the body.
- When the returned value is still in `r0` from the call just made, an early `return x;` beats falling through to the function's shared `return x;`: the target branches *past* the join's `adds r0, rN, #0` instead of into it. `SignalStrengthIcon_Create` (`p = Get(); if (p != NULL) return p;`) showed up as a streamdiff with equal instruction counts and only a branch target one instruction off.
- The same applies when the value comes from a **global** rather than a call, and there the fix is to name it twice. `Entity081d0e20_Create` matched only as `if (gEntity081d0e20 != NULL) { return gEntity081d0e20; }`; assigning it to the local that the rest of the function reuses (`p = gEntity081d0e20; if (p != NULL) return p;`) put it in a callee-saved register and branched *into* the join instead of past it.
- The guard form also decides whether a saved pointer is reloaded afterwards. `SignalStrengthIcon_Init` nested as `if (f != NULL) { ... } return -1;` put `-1` inline *and* emitted `adds r0, r2, #0` before the struct copy; the early-return `if (f == NULL) return -1;` fixed both at once, letting the copy read the call result still in `r0`.

### A ternary argument shares the call's other arguments; two calls duplicate them

- **Frequency**: `Entity12C4_Create`.
- **Symptom**: the arm-independent argument is set up once before the branch, where the target sets it up inside both arms. The `bl` itself stays single either way — cross-jumping merges it.

```c
p = CreateEntity(cond ? A : B, SIZE);   // SIZE set once, kind branches around it
// ↓
if (cond) {                             // both arms set SIZE, then the kind
  p = CreateEntity(A, SIZE);
} else {
  p = CreateEntity(B, SIZE);
}
```

### A `switch` that starts with `cmp low / beq / cmp low / ble` has one more case than it looks

- **Frequency**: `FUN_080f8abc`, `Video_SetBG23OFSDirect`.
- `switch (x) { case 1: case 3: case 5: A; default: B; }` balances its three
  nodes into a tree rooted at the middle one: `cmp #3 / beq / cmp #3 / bgt`.
  A target that instead walks them in order — `cmp #1 / beq / cmp #1 / ble /
  cmp #3 / beq / cmp #5 / bne` — has a **fourth case below the others whose
  body is the default's**. Writing `case 0: B;` explicitly moves the root to 1,
  and since the operand is unsigned `x < 1` can only be `0`, so that subtree
  needs no compare of its own and cross-jumps into `B` — the bare `ble`.
- Corollary: the rightmost node is tested with `bne default` and no lower-bound
  check, so a missing `cmp` in the middle of the chain is not evidence of a
  missing case.
- The same reading applies to a two-case switch. `Video_SetBG23OFSDirect` handles only `case 2` and `case 3`, and a bare two-case switch emits `cmp #2 / beq / cmp #3 / beq / b default` with no lower-bound test. The target's extra `cmp #2 / ble default` means the low values are spelled out: `case 0: case 1: default:` sharing the default's body.

### `pop {r1}; bx r1` means a non-void return type, even with nothing returned

- **Frequency**: `AuxShadow_SetSprite`, `AuxShadow_SetAffine`, `Eff082473e0Emitter_Reset`, `Entity080ac374_Destroy`, `Entity080ac374_Update`.
- A `void` function restores the return address into `r0` (`pop {r0}` / `bx r0`). A function declared to return a value uses `r1`, so `r0` survives. `AuxShadow_SetSprite` ends with `pop {r1}` but never sets `r0` after its last call. Declaring it `s32` with no `return` statement matched; `void` gave `pop {r0}`.
- This bites hardest on entity `_Update` / `_Destroy`, which the project declares `s32` even when they only ever return 0. If the last thing the function does is call something, the target usually has **no `movs r0, #0`** — it lets the callee's return value fall through. Writing `return 0;` costs exactly one instruction, and the streamdiff shows it as a lone extra `movs r0, #0` right before the epilogue. Drop the `return` and add a one-line comment saying the value comes from the last call.
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

### `break` and `return` are not interchangeable

- **Frequency**: `TextPanel_StateTyping`.
- **Symptom**: `break` and `return` produce different code even when the loop
  is the last statement in the function and nothing follows it, so both reach
  the same point.

```c
for (i = 0; i < N; i++) {          for (i = 0; i < N; i++) {
  if (cond) {                        if (cond) {
    // ...                             // ...
    return;                            break;
  }                                  }
}                                  }
```

## Comparisons & bit tests

### `x != 0` (and `a != b`) materialized as a 0/1 int normalize via `(0-x)|x >> 31`

- **Frequency**: `Script_LoadPointer`, `AuxSprite_Add`, `FUN_0822d9f0`.
- **Routing.** This entry and "`(x & (1<<n)) != 0` auto-optimizes to `(x>>n)&1`" below are the same expression seen through two different symptoms, and the same three functions confirm both — read them together. `rsbs` / `orrs` / `lsrs #0x1f` (the general form) is this entry; `lsrs #n` / `ands #1` (the single-bit form) is that one, which also says how to force one form or the other.
- Only applies when the comparison's result must become an actual 0/1 integer VALUE — assigned, stored, or `return`ed (equivalently, `x != 0 ? 1 : 0` written out explicitly) — not when it's used purely as an `if`/`while` condition (those just branch, no materialization needed).
- `flag != 0` materialized this way compiles to `rsbs r0, r1, #0` / `orrs r0, r1` / `lsrs r0, r0, #0x1f` — negate, OR with the original, then shift the sign bit down to bit 0. Writing the raw bit trick by hand (`(u32)((0 - flag) | flag) >> 0x1F`) produces byte-identical output to writing the natural `flag != 0`, so prefer the natural form; no need to hand-roll the trick.
- **The "prefer the natural form" advice has an exception: position.** In `AuxSprite_Add` the target computes the 0/1 value *before* two unrelated stores and only then sets up the call (`movs`/`ands`/`rsbs`/`lsrs`, `str`, `str`, `bl`). Written naturally as a call argument (`f(p, (flags & mask) != 0)`) the trick is emitted correctly but stays anchored at the call, after the stores; assigning it to a local first (`idx = (flags & mask) != 0;`) moves it early but switches agbcc to a *branch-based* setcc (`cmp`/`beq`/`movs #1`, one insn longer). Hand-rolling the trick into the assignment — `idx = (u32)(0 - (flags & mask)) >> 31;` — is the only form that is both early and branchless, and it matched. So: use the natural form when the trick lands where you need it, and hand-roll only when the target evaluates it earlier than the call site would.
- Two-operand `a != b` (both `s32`) generalizes the same trick via XOR first: `return a != b;` compiles as if written `return ((u32)(-(a ^ b) | (a ^ b))) >> 31;` — i.e. agbcc reduces `a != b` to `(a^b) != 0` then applies the same negate/OR/shift sequence.

### `/ 256` on a signed value is a 3-instruction bias, not the 6-instruction abs form

- **Frequency**: `Camera_Translate` (matched), `FUN_082470a8`, and the same block in `Camera_Init`, `FUN_0823bac8`, `FUN_0823b8ac`, `MapItemManager_Init`.
- `v / 256` compiles to `cmp #0` / `bge` / `add #0xff` / `asr #8`. The target's `cmp #0` / `blt` / `asr #8` / `b` / `rsb` / `asr #8` / `rsb` is the same value computed a different way, and agbcc only emits it for the ternary spelled out: `v >= 0 ? (v >> 8) : -((-v) >> 8)`. Writing `v < 0 ? -((-v) >> 8) : (v >> 8)` puts the negate arm first, so the operand order still matters.
- The project has this as `Div256` in `src/camera.c`. The isometric projection uses it three times per call, so a function doing the projection is 9 instructions short without it.
- In `Camera_Translate` the projection is a `static inline` taking `(Vec3* out, Vec3* world)` (`WorldToVp` in `src/camera.c`): the target materializes both pointers — the `ldr =dest` pool load and the source's base copy — as an adjacent pair **before** the arithmetic, which is the inlined call's entry. Written flat in the caller, the pool load slides down to the first store instead.

### A range test becomes `(unsigned)(x - lo) <= hi - lo`

- **Frequency**: `GameOverManager_StateWaitFlag`, `IsSpecialWeapon`, `CountFoundArmors`.
- **Symptom**: `subs rN, #lo` / `lsls rN, #24` / `lsrs rN, #24` / `cmp rN, #k` / `bhi` — one subtraction, one *unsigned* compare, one branch, where the source seems to need two compares. `#16` shifts for a `u16`, no shifts at all for a `u32`/`s32`, `bls` instead of `bhi` for the negated form.
- agbcc folds a two-sided range check into a single unsigned compare. **Write the left column; the right column is only what the asm and the decompiler show you.** The casts and the `3 < ...` operand order on the right are the decompiler's spelling, not the source.

| write this | you will see this |
| --- | --- |
| `if (s32val < 33 \|\| s32val > 36) {` | `if (3 < (u32)(s32val - 33)) {` |
| `if (s32val >= 58 && s32val <= 65) {` | `if ((u32)(s32val - 58) < 8) {` |
| `if (u8val >= 28 && u8val <= 29) {` | `if ((u8)(u8val - 28) <= 1) {` |

- **Two *signed* compares are a `switch`, not a range test.** `cmp rN, #hi` / `bgt` then `cmp rN, #lo` / `blt` — no subtraction, no shifts — is the range check agbcc puts in front of a `switch` whose cases are contiguous. An `if` never produces it: the fold above always wins. `WeatherManager_StopScripted` needed `switch (p->state) { case 1: case 2: case 3: ... }`.

### Two bit tests on one load: the masked-value helper folds, the `bool32` one does not

- **Frequency**: `FUN_080f09a4`.
- A single test through a `bool32` bit-test helper branches cleanly
  (`FUN_080f1cb8`). But when two tests on the same field share one load, the
  second one leaves the boolean half-materialized —
  `ands / cmp #0 / beq / movs r0,#1 / cmp r0,#0 / beq` — three instructions too
  many, whichever way the condition is written (`&&` chain, nested `if`s,
  negated guards, positive or negated).
- Declaring the helper to return the **masked value** instead
  (`static inline EnemyFlags Enemy_TestFlag(Enemy* p, EnemyFlags bit) { return p->flags & bit; }`,
  called as `== 0` / `!= 0`) folds both tests. Mixing a helper for one test and
  a bare `p->flags & BIT` for the other is worse still — it reorders the load.

### `(x & (1<<n)) != 0` auto-optimizes to `(x>>n)&1` unless the mask is precomputed

- **Frequency**: `Script_LoadPointer`, `AuxSprite_Add`, `PlaySound_0824078c`, `FUN_0822da50`, `FUN_0822d9f0`, `MainSprite_Add`, `BgPlttGroupFader_Update`.
- The fallback this entry keeps talking about is the general 0/1 trick in "`x != 0` (and `a != b`) materialized as a 0/1 int" above; read that entry first for what the trick is and where it lands.
- Hoisting the mask also moves *where* the constant is built. In `PlaySound_0824078c`, `if (!((a | b) & 0x400))` built `movs #0x80` / `lsls #3` right before the `ands`; the target builds it first, before both loads. Swapping the `&` operands changed nothing; `u32 mask = 0x400;` as its own statement before the `if` matched.
- Writing a single-bit test as one fused expression — `(byte & (1 << bit)) != 0` — lets agbcc's combiner recognize the "extract one bit" idiom and emit the cheaper `asrs`/`ands` (shift the target bit to position 0, mask with 1) instead of the general nonzero-materialize trick above. If the target's real assembly uses the general `rsbs`/`orrs`/`lsrs` trick instead (i.e. the shift-based optimization did NOT happen), the mask must be computed in its own prior statement — `s32 mask = 1 << bit; ... (byte & mask) != 0;` — splitting it into a separate pseudo-register apparently hides the "single bit" shape from the combiner and falls back to the general path.
- The lever also works with a plain literal mask, not just `1 << bit`: in `AuxSprite_Add`, `(flags & 0x80) != 0` compiled to `lsrs r1, rN, #7` / `ands r1, r4` (and pinned one extra callee-saved register), while hoisting the constant into its own statement (`mask = 0x80; ... (flags & mask) != 0`) fell back to the general `movs #0x80` / `ands` path and fixed the register allocation at the same time. Constant propagation does not undo the split.
- As a call argument, hand-rolling the trick also avoids the shift form without a separate statement. In `MainSprite_Add`, `f(p, (flags & 0x80) != 0)` gave `lsrs #7` / `movs #1` / `ands`, while `f(p, (u32)-(flags & 0x80) >> 31)` gave the target's `movs #0x80` / `ands` / `rsbs` / `lsrs #0x1f` (no `orrs`, since the masked value is never negative).
- That statement split has a side effect: splitting *only* the mask into its own statement (leaving the address `src + (offset >> 3)` inline) reintroduced an unrelated register-allocation regression (two unrelated parameters got pinned into extra callee-saved registers for the whole function instead of just one). Also splitting the address into its own pointer variable (`u8* p = src + (offset >> 3);`) alongside the mask fixed it. Net effect: both the mask AND the address need their own statement (address first, then mask, matching the target's instruction order) to get byte-identical output.
- The same applies to a loop-variable shift. `BgPlttGroupFader_Update` tests `p->litMask & (1 << i)` inside a `for`; written inline it became `asrs r0, r6` on the field, and a `s32 mask = 1 << i;` at the top of the loop body restored `movs r1, #1` / `lsls r1, r6` / `ands r0, r1`. The same variable then feeds the second test on another field, which is what the target reuses it for.

## Integer width & sign extension
- `Player_WeaponEffect*` (14個) が同じ形。目標は **マスクを先に材料化してから** フィールドを読む (`movs r2, #4` → `ldr r0, [r1, #0x38]` → `ands`)。`if (a->attributes & 0x4)` と直に書くと順序が逆になり、使うレジスタも1つずれる。`u32 mask = 0x0004;` とローカルに置くと目標と一致する。
- 同じ族で **分岐の向き** も決まっている。`cmp` の直後が `bne` で「非0側」へ飛ぶなら、ソースは `if (x & mask) { return 10; } return 0;`。`if (!(x & mask)) { return 0; } return 10;` は等価でも `beq` になり、2つのアームが入れ替わる。

### A signed field narrowed on assignment loses its `ldrsh`

- **Frequency**: `FUN_08049668`.
- **Symptom**: your build has `ldrh rN, [rB, #off]` where the target has `movs rT, #off` / `ldrsh rN, [rB, rT]`.
- Assigning an `s16` field straight into a narrower field (`p->speed = gStat->messageSpeed;` with `speed` a `u8`) lets agbcc drop the sign extension — only the low byte survives either way. Reading it through something typed `s32` keeps the `ldrsh`; a `static inline s32 GetMessageSpeed(void) { return gStat->messageSpeed; }` was what the original had.

### A declared type narrower than the value produces an `lsls`/`lsrs` pair — move it by changing the declaration

- **Frequency**: `FUN_082402c8`, `FUN_082402e0`, `FUN_08240428`, `sound_082403b8`, `sound_08240728`, `Entity6978_Create`, `ParticleShadow_Init`, `AuxShadow_Init`, `AuxShadow_SetScaleParams`, `TextRenderer_SetRect`.
- **Symptom**: an `lsls rN, #k` / `lsrs rN, #k` pair your build has and the target does not, or vice versa (`#0x10` for a `u16`, `#0x18` for a `u8`). agbcc emits it wherever a value has to be narrowed to a declared type, so **where it sits says which declaration is wrong** — never the arithmetic.

| you emit the pair | the target has it | write this |
| --- | --- | --- |
| at the call site | nowhere | widen the **callee's** parameter (`u16 x` → `u32 x`) |
| nowhere | at the call site | narrow the **callee's** parameter (`u32 x` → `u16 x`) |
| at your own function's entry | at the *use* of that parameter | widen your **own** parameter to `s32` and cast at the use: `(u8)kind == 0` |
| before a narrow store | nowhere | widen the parameter to `s32`; the `strb`/`strh` truncates by itself |

- Widening a callee is safe whenever it has exactly one caller, and a NAKED callee's `.inc` body is untouched by it. The callee does not have to be NAKED: `PlaySound_08240718(SoundID16 id) { m4aSongNumStart(id); }` already truncates `id` in its own body, so widening it to `SoundID32` left its own bytes unchanged and removed the extra truncation from its caller.

### A narrowing compound assignment puts its truncation where the assignment's value is read

- **Frequency**: `Entity87FE_Update`, `Entity87FE_Init`, `FUN_08237098`, `FUN_08237064`.
- **Symptom**: an `lsls #16` / `lsrs #16` pair in the wrong place around a compare (`#0x18` for a `u8` field). `p->n += step` is `p->n = (u16)(p->n + step)`, and the *value of that assignment* is the converted one, so the truncation lands wherever that value is consumed — not where the addition happens. Match the right column against the target.

| write this | the `lsls`/`lsrs` lands |
| --- | --- |
| `u16 n = a + b; p->n = n; ... if (n >= max)` | right after the `adds` |
| `if ((p->n += step) >= p->max)` | after the pointer and bound reloads, just before the `cmp` |
| `p->n += step; if (p->n >= max)` | nowhere, but the value is re-read instead of reused — 6 fewer instructions |

- The clamp idiom `if ((p->w = expr) == 0) { p->w = 1; }` is the same shape and is what three of the four functions use (`Entity87FE_Init`, `FUN_08237064`, `FUN_08237098`).
- Row 2 and the clamp idiom are the one place this project writes an assignment inside a condition. That is deliberate: the separated spellings are rows 1 and 3, and neither matches. Leave a one-line comment saying so when you use it.

## Operand order & scheduling

### Equivalent spellings agbcc does not canonicalize

- **Frequency**: `Script_StorePointerCore`, `FUN_0822ea10`, `EntityMsgBus_Post`, `sound_08240740`, `Save_WriteCore`, `Hitbox_GetPushDir`, `FUN_0823c35c`, `FUN_0822bcf4`, `FUN_08089b48`, `BlendPlttToColor`, `BlendPltt`, `LoadParticleFile`, `FUN_0822a4fc`, `Entity92BE_Shake`, `FUN_08237834`, `FUN_08237848`, `Video_GetActorSprite`, `Video_CreateSpriteLUT`, `OpenCollisionMapFile`, `GetTilemapFile`, `VM_CallScript`, `Entity28CB_Update`, `VM_Ctrl_22FF`, `ArcTan2_8`.
- The order you write, the way you group it, the form you choose and the type you declare all survive into the asm. When a function is close but will not match, try the other side of a pair below — the difference is usually one swapped operand pair, one moved `lsls`, or one extra callee-saved register.
- Below: `p` is a pointer and `i` an index, `q` a local holding a derived address, `a` and `b` two struct pointers with fields `x` and `y`, `n` and `m` scalars, `k` a constant addend, `s` a shift amount, `M1`–`M3` mask constants.

| one spelling | the other |
| --- | --- |
| `*(u16*)(p + (i << 1))` | `*(u16*)(p + i * 2)` |
| `u32* q = &p[i];` then `*q` | `p[i]` at each use |
| `u8* q = &p->arr[i];` then `*q` | `p->arr[i]` at each use |
| `p[i]` | `*(p + i)` |
| `a->x + a->y` | `a->y + a->x` |
| `(a->x + a->y) + b->y` | `b->y + a->y + a->x` |
| `(n << 1) * m` | `m * (n * 2)` |
| `n * m` | `m * n` |
| `p->n * 32` passed to a macro that divides | `p->n << 5` passed to the same macro |
| `a \| b \| c` | `a \| (b \| c)` |
| `a &= M1; b &= M2; c &= M3; *p = a \| b \| c;` | `*p = (a & M1) \| (b & M2) \| (c & M3);` |
| `p[i] == n` | `n == p[i]` |
| `if (f(...) != n)` | `m = f(...); if (m != n)` |
| `(u8)(n + k) >> s` | `((n + k) & 0xFF) >> s` |
| `for (...; i++, p++)` | `for (...; p++, i++)` |
| `n = (u8)p[i]; m = p[i] >> 8;` | `m = p[i] >> 8; n = (u8)p[i];` |
| `p->field = n;` then pass `p` on | `*(u32*)p = n;` then pass `p` on |
| `Div(-n * 256, m)` | `Div(n * -256, m)` |
| `s16 x = n;` | `s32 x = (s16)n;` |
| `u16 i; i++;` | `s16 i; i++;` |

Which side to pick, once the asm has told you what is wrong:

- A binary operator loads and copies **the operand written first, first** — `+` and `*` alike. Two loads feeding one `adds` in the wrong order, or the wrong value copied before a `muls`, means flipping the written order.
- The **grouped** form of a `|` chain keeps one more value live at once, so it costs an extra callee-saved register and changes the `push` list. Register allocation off by exactly one in an expression of three or more terms: regroup the parentheses.
- A constant factor written `* 2` is **reassociated through a multiply** onto the other operand; written `<< 1` it stays where you put it.
- A macro that divides its argument folds a `*` into a single shift but cannot fold a `<<`, because `(x << 5) / 4` is not `x << 3` for a negative `x`. The `<<` form is one instruction longer, enough to flip a leaf function's prologue to `push {lr}`.
- The **subscript** form emits the base address first and the index scaling after it; the **pointer** form emits the scaling first. Splitting the index into its own local, or hoisting the base into a pointer local, does not move it — only the subscript-vs-pointer choice does.
- Holding an address in a local vs indexing at each use also decides how a field offset is grouped: `p + (i + OFF)` for the local, `(p + OFF) + i` for the repeated subscript.
- A `(u8)` cast folds the addition into the shifts; `& 0xFF` keeps a separate `ands` and leaves the value signed, so the shift down is an `asrs`.
- The `for` increment's comma order is the order of the two `adds`.
- Reading the **low byte first** keeps both loads (`ldrh` + `ldrb`); reading the high half first lets CSE collapse them into one `ldrh` plus shifts.
- A **struct-field** store lets agbcc keep a global pointer live across it; a **cast** store forces it to be reloaded.
- Caching a global pointer in a local (`cam = gCamera;`) keeps the **value** in a callee-saved register; writing `gCamera->field` at each use keeps the **address** there (`adds r6, r0, #0`) and reloads the value (`ldr r2, [r6]`) after anything that needs the registers. `Camera_Translate` reloads once after the projection — with the local, that reload has to be written out as a second `cam = gCamera;`, which is the tell that the local does not belong there.
- `-n * 256` lets agbcc reuse a `-n` computed for a nearby compare, overwriting `n`; `n * -256` negates after the shift and keeps `n` alive.
- An `s16` local sign-extends at **every use**; `s32 x = (s16)n;` sign-extends **once at the assignment**.
- A `u16` counter adds then truncates; an `s16` counter additionally sign-extends where it is read.
- **Not confirmed**: the `|` grouping rule should apply to the other associative operators (`&`, `^`), but no function has been matched on that.

### A constant or global address materializes in the wrong place

- **Frequency**: `FUN_0807b3c0`, `Sprite_SetPlttID`, `sound_08240264`, `FUN_082436dc`, `FUN_08089d50`, `FUN_08089e98`, `FUN_08089f58`, `FUN_08089d24`, `FUN_08089f38`, `FUN_0823a9f4`, `FUN_0823aa10`, `FUN_08240360`, `FUN_082405c0`, `Sound_SetBGMTempo`, `FUN_082410e8`, `FreezeEffect_GatherSubParticles`, `IsWeaponLevelChanged`, `ParticleShadow_Init`, `Cactus_OnHit`, `Entity08080be8_SetupSprite`, `CheckNamakuraProc`, `CheckParalyzeProc`.
- **Symptom**: one `movs rN, #k` or `ldr rN, =SYMBOL` sits earlier or later than the target has it, usually with registers renamed and an identical instruction count.
- The lever is how the expression is split into statements, never the arithmetic. The mask-hoisting bullets under "`(x & (1<<n)) != 0` auto-optimizes" are the same mechanism seen through a bit test.

**Splitting a value into its own statement — or into an inlined helper's argument — makes it materialize earlier.** A helper's constant argument materializes at the call site, ahead of the body's loads.

| you wrote | write this instead | function |
|---|---|---|
| `p->state = 2;` | `T_SetState(p, 2)` — the helper also resets `stateTimer`, which every state change in that entity does | `FUN_08089d24`, `FUN_08089f38` |
| `gEntityDisableFlags &= ~2;` | `EnableEntityFlags(2)` taking `u32 flags` | `FUN_0823a9f4` |
| `if (!((gA \| gB) & 1))` | a helper taking the mask as `flags` | `FUN_0823aa10` |
| `if (!(a->weakness & 4))` | `Hitbox_HasWeakness(a, 4)` taking `u32 mask`. `(x & 4) == 0`, `4 & x` and an inverted `if`/`else` change nothing | `Cactus_OnHit` |
| `arr[i]` on a **global array**, or on an array member reached through a global pointer (`gStat->weaponExp[i]`) | `*(arr + i)` — different tree in the front end (`ARRAY_REF` vs `INDIRECT_REF` of a `PLUS_EXPR`), so the base's pool load moves relative to the index's `lsls`. No `-f` option controls it; pick the spelling off the target | `CheckNamakuraProc`, `CheckParalyzeProc`, `GetWeaponSkillLevel` |
| `p->sprite.metaspriteIdx = 0;` right after `AuxSprite_Add(&p->sprite, ...)` | `AuxSprite_SetPoseIdx(&p->sprite, 0)` — the helper's argument re-materializes `&p->sprite` after the call, so agbcc reuses the register that held `p` instead of keeping a second one live across it | `Entity08080be8_SetupSprite` |
| `p->plttID = id; p->pltt = &g[p->plttID * 16];` | reload the field in its own statement: `i = p->plttID;` | `Sprite_SetPlttID` |
| `f(0, (T*)gPtr, g(0x28))` | `len = g(0x28);` first | |
| `Div(..., n + 1)` at each of three calls | `d = n + 1;` directly after `n`'s assignment | `FreezeEffect_GatherSubParticles` |
| `if (p->weaponLv[i] != GetWeaponSkillLevel(i))` | `lv = p->weaponLv[i];` first | `IsWeaponLevelChanged` |
| `if (g[10] != 0) { id = g[10]; ... }` — costs an extra `adds rN, r0, #0` | hoist the read above the `if` | |
| `... * 34 + gMgr->group0->tile` | put the global term first | `ParticleShadow_Init` |
| `gX.field` at each use | a pointer local (`T* s = &gX;`) is loaded at entry and kept in a callee-saved register across calls | |
| `gArr[f()]` — the base's pool `ldr` hoists **above** the `bl`, so it needs a callee-saved register and the function grows a `push {r4}` | `i = f();` first, then `gArr[i]`. The base then materializes after the call and stays in a scratch register | `FUN_0807b3c0` and the 14 other `gPlayerPtr[VM_GetPlayerIdx()]` wrappers |

**Merging it back into one expression makes it materialize later.**

- `ms = gSongTable[id].ms; f(gMPlayTable[ms].info); gSoundIDs[ms] = id;` loads `=gSongTable` first; the target loads `=gMPlayTable` first, which writing the index inline at both uses matched (CSE still reuses the `ms*2`).
- `FUN_08089d50` draws twice from `gRandomTable[(gRandTableIdx + 1) & 0x3FF]`: only the *second* index may be stored back, and each value needs a `u16` local before `& 0x1F` so the mask keeps its own register. The original RNG macro or inline is not known.

**Both directions occur for the same code shape, so try both.**

- The nested subscript above cuts the other way too: as one expression the outer table's pool `ldr` hoists above the inner subscript, split into `u16 ms = ...;` it lands after. One function needed each. When only a pool `ldr` is misplaced, try splitting *and* merging first.
- The choice can decide only which callee-saved registers a parameter and a base address get, at an identical instruction count. `FUN_082405c0` needed `id = g[12];` above the `if` where testing `g[12] != 0` gave the same 32 instructions with `r6`/`r7` swapped — and its twin `Sound_FadeOutBGM` matched with the opposite shape.
- Which one the target used is readable: hoisting the read leaves the base in a scratch register (`ldr r0, =g` / `ldrh r0, [r0, #N]`), testing the global directly keeps the base in its own register across the guard. `Sound_SetBGMTempo` needed the hoisted form, `Sprite_LoadSprite` the other.
- A local's initializer materializes at function entry, not at the use. `u32 mask = 1 << 2;` put the `movs` ahead of everything; declaring it bare and assigning `mask = 1 << 2;` on the line before the `if` put it where the target has it (`Entity08202cd8_Update`). The inline constant `& 4` materializes one instruction later still.

### A zero stored from a reused local takes that local's register

- **Frequency**: `ReadKeyInput`, `FindZonesByID`.
- In `ReadKeyInput`, the loop that clears players 1-4 stores 0 twice (`strh r3, [r1]` / `strh r3, [r1, #2]`), with the 0 in `r3`, the register that held `keys` a moment earlier. Writing `gInput[i].down = 0; gInput[i].pressed = 0;` (or a chained `= 0`) put the 0 in a fresh `r0`. Setting the existing local once, `keys = 0;` before the loop, and storing `keys` (`down = keys; pressed = keys;`) matched. Going further and reusing the full update formula (`pressed = keys & ~prev`) with `keys = 0` did not fold and added four instructions.

- The reverse also happens: **initialising a local at its declaration lets agbcc reuse a zero it materialised for something else.** `FindZonesByID` starts with `*count = 0;` and a `Zone* first` that stays NULL until a match. Declaring `Zone* first = NULL;` made agbcc store that same register through `*count`, one `movs` short of the target; the target materialises three separate zeros (`*count`, `first`, the index), which `*count = 0; first = NULL;` as two plain statements reproduces. The source order is visible: whichever zero is written first gets the `strh`.

### A parameter copied into a local is not coalesced; the copy's declared type decides which one is the working variable

- **Frequency**: `GetFile`, `GetTilemapFile`, `Cactus_OnHit`.
- **Symptom**: two callee-saved registers hold the same incoming value, and the uses are split between them — often with the register pair swapped relative to the target, at an identical instruction count.
- `GetFile(FileID directoryID, FileID fileID)` rewrites `fileID` in each `case` and passes the original to `GetAssetFile` at the end. The target truncates the incoming `fileID` into `r1`, copies it to `r7` (`adds r7, r1, #0`), and at the call moves `r7` into `r2` first, before building the 4th argument. A copy declared `FileID file = fileID;` either swapped `r1`/`r7` or moved `r2` last. Declaring the copy as `u32 file = fileID;` (found by the permuter as `int`) matched.
- The type does not have to be a width change: a `void*` parameter assigned to a typed local is not coalesced either, so the two live in separate callee-saved registers. `Cactus_OnHit` keeps `p->hp` on the parameter's register and `p->damageTimer` / `&p->sprite` on the copy's; declaring the third parameter as `Cactus* p` gives one register and one fewer, and `void* owner` with `Cactus* p = owner;` — the shape `HitboxData.fn` actually has — matched.

### A field copied into a local is loaded at the declaration; read directly it hoists with the rest

- **Frequency**: `TextBoxChoice_Finish`, `MapItem_UpdateFall`, `EntityCF82_Init`, `RingoDemoAnim_Init`, `BreakableManager_Update`, `Player_ReduceENE_0807aa60`.
- A field read **and** written in the same statement, at an offset too large for the load's immediate, rebuilds the address on each side: `movs r3, #0xDA` / `lsls` / `adds` before the `ldrh`, and the same three again before the `strh`, which also splits a ternary into two stores. A `u16*` local to that field collapses both onto one base (`adds r2, r2, r0`), and then the two arms must be an `if`/`else` — as a ternary agbcc keeps the arms in the other order and no spelling of the condition swaps them back (`Player_ReduceENE_0807aa60`).
- `TextBoxChoice_Finish` hoists both `&args` (`add r5, sp, #0x14`) and `p->scriptID` (`ldr r4, [r2, #0x54]`) above the argument-copy loop, in the order their *uses* appear after it. Opening the block with `u32 scriptID = p->scriptID;` pinned that load to the declaration, so it came out first and `r4`/`r5` stayed swapped for the rest of the function. Reading `p->scriptID` directly in the later `if` and call let agbcc hoist the load as a loop invariant and restored both the order and the registers.
- The same pinning applies to a pointer local holding a global's address, so a declaration at the top of the function drags its `ldr` above everything before its first use. `EntityCF82_Init` writes two `strb`s and only then loads the palette address; wrapping the two pointer declarations and their one statement in a bare inner block put the `ldr` back after the stores.
- Splitting the declaration from the assignment moves the computation to the assignment instead. `RingoDemoAnim_Init` computes `&p->pos` between `p->msgBox = msgBox;` and the `Vec3` copy; `Vec3* q = &p->pos;` put it at function entry, and `Vec3* q;` with `q = &p->pos;` placed after the first store matched.
- The same pinning inside a nested block. `MapItem_UpdateFall` loads `item->pos` *before* the clamp in the `if` body, which only happens when the block opens with `Vec3* q = item->pos;`. Writing `item->pos->y -= n;` at the point of use put the load after the clamp instead.
- A guard on the same field decides whether the load needs a copy. `BreakableManager_Update` guards on `p->items` and then walks it: `Breakable* item = p->items; if (item != NULL) {` loads straight into the walking register, while the target tests `p->items` and only then names the local, spending an extra `adds r4, r1, #0`. Declaring the local **inside** the guarded block (`if (p->items != NULL) { Breakable* item = p->items; ... }`) reproduces the copy, and shifts the other two loop registers with it.

### A nested struct's field folds both offsets; a pointer to the inner struct keeps its base

- **Frequency**: `RingoDemoAnim_Update`, `Breakable_Spawn`.
- `p->sprite2.flags |= SPRFLAG_HIDDEN;` (`sprite2` at 0xA8, `flags` at +8) adds the sum: `adds r2, r6, #0` / `add r2, #0xb0` / `ldr r0, [r2]`. The target keeps the inner base and uses the load's immediate: `add r2, #0xa8` / `ldr r0, [r2, #0x8]`. A `MainSprite*` local pointing at the inner struct reproduces it. The instruction counts are equal, so this shows up as nothing but a wrong constant. Assign the local where the target computes the address, not at its declaration — see the entry above.
- With several fields of the inner struct, the tell is *how many* base registers appear. Thumb cannot encode `strb` past +31 or `strh` past +62, so those accesses need a base either way; without a local, agbcc builds a throwaway `adds`/`add` pair per access and still reaches the encodable ones from the outer base. One pointer local collapses all of them onto a single base. `Breakable_Spawn` touches `sprite.pos` (+0x58), `.metaspriteIdx` (+0x4C) and `.priority` (+0x43) and went from three temporaries to one `r5 = item + 0x3C`; the same function needed a second local for `&item->hitbox`.

### A countdown in the asm can be an upward loop agbcc reversed

- **Frequency**: `FUN_0822d98c`, `ClockAlarm_Init`.
- `for (j = 0; j < 16; j++)` over walking pointers comes out as a countdown (`movs rN, #0xf` / body / `subs rN, #1` / `cmp rN, #0` / `bge`), so the asm does not tell you which way the source counted. The two are not interchangeable: a hand-written `for (j = 15; j >= 0; j--)` gives the same loop body but keeps the counter as its own pseudo, while the reversed one is a compiler temp that can take the enclosing loop index's register. In `FUN_0822d98c` that decided whether the outer `i + 1` was computed at the top of the body and parked in a second register (`adds r4, r3, #1` … `adds r3, r4, #0`, the target) or folded into one `add r4, #1` — the same body, one instruction apart. When a countdown's body matches but the surrounding increment does not, write the loop counting up.
- The reversal flips the walking pointer too, so even the direction of travel is not evidence. `ClockAlarm_Init` fills `p->armed[0..3]` with a pointer that starts at `&armed[3]` and runs down (`strb` / `subs r0, #1`); the source is the plain `for (i = 0; i < 4; i++) { p->armed[i] = 1; }`. Writing it downward — as a subscript, as a walking pointer, as a `do`/`while`, or with the two inits in either comma order — left the stored constant's `movs` one slot out of place every time.

### agbcc does not rotate loops: a guard plus `do/while` is a different shape from `while`

- **Frequency**: `FUN_080ed068`, `GetMapAreaAt`.
- `while (p != NULL) { ... }` and `for (node = head; (p = node->enemy) != NULL; node = node->next)`
  both compile to a `b` into the test at the bottom — the test is never peeled.
  When the target instead evaluates the condition once before the loop
  (`ldr` / `cmp` / `beq end`) and ends with `bne` back to the top, the source was
  an explicit guard around a `do/while`:
  `p = node->enemy; if (p != NULL) { do { ... } while (p != NULL); }`.
- A `break` as the **first** statement of the body is the one thing that does get rotated: `for (i = 0; i < 16; i++) { if (arr[i] <= 0) break; ... }` peels that test into the preheader and duplicates it in the latch, costing 1-2 instructions. Writing the same exit as `return` instead leaves the test at the top of the body, where the target has it (`GetMapAreaAt`); the two `return -1`s cross-jump into one, so nothing is duplicated. With the `break` in place, an explicit walker looked necessary to get the `adds r4, #4` — once it was a `return`, plain `arr[i]` produced the walker and the counter on its own.
- This also decides where a loop-invariant constant lands. Inside the guard,
  `flag = 0x1000;` is emitted between the `beq` and the loop head, which is
  where the target has it; initialising it at the declaration hoists it to
  function entry instead, before the first call.
- The enemy list walkers in `enemy_manager.c` are nearly all this shape
  (`FUN_080ecf18`, `FUN_080ecf60`, `FUN_080ed020`, `FUN_080ed724`, `FUN_080eda7c`),
  so check which of the two shapes the target has before writing the loop.

### Digits extracted all at once, or one per term: the accumulator decides

- **Frequency**: `FromBCD`.
- `return d0 + d1 * 10 + d2 * 100 + d3 * 1000;` — whether the digits are
  written inline or pulled into locals first — makes agbcc hoist **every**
  extraction (`lsrs` / `ands` per digit) above the first multiply. A target that
  interleaves them, extracting each digit right before its own multiply, was
  written as an accumulator instead:
  `result = d0; result += d1 * 10; result += d2 * 100; ...`.
- The same rewrite also decided how the parameter is held: with the accumulator
  and a `u16` parameter agbcc keeps the value left-shifted by 16 and widens the
  masks (`movs #0xf0` / `lsls #0xc` / `ands` / `lsrs #0x10`) instead of
  normalising it once with `lsls` / `lsrs` — one instruction longer, and the
  shape the target has.

### Scalars and an array in one frame: the scalars land above the array

- **Frequency**: `FUN_0823e298`.
- `s32 year, month, day; u8 buf[8];` (in either declaration order) puts `buf` at
  `sp+0` and the three scalars above it, so every use of `buf` is a bare
  `mov r0, sp`. A target that has the scalars at `sp+0` and the array above
  them — paying `add r4, sp, #0xc` and a callee-saved register to hold it — had
  the scalars as an **array** too: `s32 ymd[3]; u8 buf[8];`, filled through
  `&ymd[0]` / `&ymd[1]` / `&ymd[2]`. Two arrays are laid out in declaration
  order; an array and loose scalars are not.

### Two loops sharing one counter variable shift the register allocation

- **Frequency**: `LevelUpper_Update`.
- `LevelUpper_Update` has an 8-iteration loop in one branch and a 5-iteration loop in the other. With one `s32 i` for both, every register was off by one (`p` in `r5` instead of `r4`, the counter and the stored 0 swapped). Giving the first loop its own counter (`s32 i, j;`, `for (j = 0; j < 8; j++)`) matched with no other change.

### A loop index that starts at a parameter: reuse the parameter, save the start

- **Frequency**: `FUN_0822eadc`, `FUN_0822ea60`.
- A nested loop whose inner index starts at a parameter (`for (x = x8; x < right; x++)`) keeps both `x8` and `x` live to the end. With a separate `x`, agbcc parks `x8` in a callee-saved register and puts the hoisted `x8 * 2` in `ip`; the target does the opposite — `mov ip, rN` before the nest, `mov rN, ip` at the top of each outer iteration, and `x8 * 2` in a low register, so the row address adds two low registers instead of `add r0, r12`. Writing the parameter itself as the loop variable and saving its start in a local (`u32 left = x8; ... for (x8 = left; x8 < right; x8++)`) matched. The instruction count is identical either way, so this surfaces as nothing but a register permutation — seven other shapes (separate `x`/`y`, inline bounds, `w8 += x8`, row pointer, `*(map + i)`, declaration order, inner-scope `x`) all produced the same wrong permutation.

### `arr[i]` vs `*p++` change where the walking pointer is initialized

- **Frequency**: `FUN_082315c0`, `FUN_0824082c`, `FUN_08089ce0`, `Entity0800a89c_ReleaseSwarm`, `Entity0800a89c_UpdateSwarm`, `Entity080146e0_Destroy`, `Eff082473e0Emitter_FadeParticle`.
- Both compile to the same `stm rN!, {r0}` walking store, but the init of that pointer lands in a different place. `*out++ = v;` modifies the parameter, so agbcc copies it to a callee-saved register in the **entry block**, before any loop-invariant hoists. `out[i] = v;` leaves the parameter alone and lets loop strength reduction create the pointer, so its init goes in the **preheader**, after the hoists — swapping the order of the two setup instructions. (Strength reduction also frees `i` to be reversed into a down-counter while the pointer still walks up.)
- A walking pointer compared against `base + const` (`adds r0, r5, #0` / `adds r0, #0x14` / `cmp r4, r0`) with a **signed** loop exit (`ble`) and no pre-loop test is an `s32 i` index loop, not a pointer loop: loop strength reduction deletes `i` and rewrites `i == 10` and `i < 32` as compares on the pointer. In `FUN_0824082c`, writing the pointer loop (`p == &arr[10]`, `p <= &arr[31]`) gave a pre-loop `bhi`, unsigned `bls` and pool-loaded addresses; `for (i = 0; i < 32; i++) { if (arr[i]) { if (i == 10) ... } }` matched, including the second walking pointer used for the `arr[i]` call argument.
- The same split decides whether a **member offset** is folded into the pointer. `f(&arr[i].member)` initialises one pointer at `&arr[0].member` and steps it by `sizeof(*arr)`; an explicit `T* p = arr; f(&p->member); p++;` keeps `p` at `arr` and pays an `adds r0, #offset` every iteration. `Entity0800a89c_ReleaseSwarm` (`Particle_Remove(&swarm->bugs[i].ptcl)`) needed the index form. When the body reads a field **and** takes the address of another one, the index form creates **two** induction variables stepping the element size side by side, which a single walker can never produce: `Entity080146e0_Destroy` (`if (data->ptcls[j].active) Particle_Remove(&data->ptcls[j].ptcl);`) went from 35 to 43 instructions — exactly the target — just by dropping the walker. Two registers stepping by the same `sizeof` in the target asm is the tell.
- With an explicit walker **and** an index that the body still needs, both the init order and the increment order are visible. `Entity0800a89c_UpdateSwarm` matched only as `for (i = 0, bug = swarm->bugs; i < 4; i++) { ...; bug++; }`: putting `bug = ...` first swapped the two registers, and putting `bug++` in the `for` increment emitted it after `i++` instead of before.
- A `T* e = &arr[i];` declared **inside** the loop body splits the constant hoists around the pointer's init, where `arr[i]` spelled out at each use emits them adjacently. `Eff082473e0Emitter_FadeParticle` stores three constants into one element; indexing gave `movs 2` / `movs 10` back to back before the pointer setup, the inner declaration gave `movs 2` / pointer setup / `movs 10` — the target's order, and it swapped the two registers as well. Same 29 instructions either way, so the streamdiff hunk is only the hoist order.
- `Video_ResetFrameState` clears 128 OAM entries. `*(u32*)&gOAMBuffer[i] = v;` in a `for (i = 0; i < 128; i++)` let agbcc fold the index and the counter into one pointer running **downward** from the last entry (`adds r0, r1, #0x3f8` / `subs r0, #8` / `cmp r0, r1`). The target keeps a separate countdown counter and an upward pointer, which an explicit `OamData* oam = gOAMBuffer; ... *(u32*)oam = v; oam++;` reproduces.

### Two addresses in one object share a base register; separate symbols get their own pool constants

- **Frequency**: `OpenCollisionMapFile`, `GetTilemapFile`, `EntityCF82_Init`.
- Passing `arr` to a call and then returning `&arr[4]` held the base in a callee-saved register (`ldr r4, =arr` / `adds r1, r4, #0` / `adds r0, r4, #4`) and cost a `push {r4, lr}`. The target loads `=arr` and `=arr+4` as two independent pool constants and pushes only `lr` — agbcc shares a base only when both addresses come from the same object, so splitting the one `u8 arr[16384]` definition into two adjacent externs (a 4-byte head and the body) matched.
- Two constant indices into one array pick their pool constant from how they are spelled. `a[0x20] = a[0x2F];` puts `=a` in the pool and adds both offsets; declaring them as pointer locals puts `=a+off` of the **first declared** one in the pool and derives the other with `adds rN, rM, #0` / `subs rN, #k`. `EntityCF82_Init` needed the source first (`rgb555* off = a + 0x2F; rgb555* pltt = a + 0x20;`); declaring the destination first instead collapsed to a single `ldrh rN, [rM, #0x1e]`.

### An intermediate result variable can block a store's cross-jump merge

- **Frequency**: `VM_RunExpression`, `TextBoxChoice_CreateFromScript`, `MapItem_UpdateFall`.
- `if (c) { x = A; } else { x = B; } slot->f = x;` and `if (c) { slot->f = A; } else { slot->f = B; }` produce the same merged store, but not the same scheduling around it. In `VM_RunExpression` the `x` version delayed a later call's first-argument setup (`adds r0, r5, #0` emitted after the other two argument registers instead of before them); writing the store directly in both arms fixed it. If argument setup order is the only thing off near a two-armed store, try removing the intermediate variable.
- A `adds rN, rM, #0` copy right before a clamp means the clamped value is its own variable (`s32 n = d; if (n > 0x20) { n = 0x20; }`); reusing the original (`if (d > 0x20) { d = 0x20; }`) is one instruction shorter (`MapItem_UpdateFall`).

### Shared code after an if/else: inside the arms it can keep stepping an offset register, after the join it cannot

- **Frequency**: `TextBoxChoice_SetCursor`, `Entity08080be8_SetupHitbox`.
- Written once after the `if/else`, the four `pos` stores started a fresh offset (`movs r2, #0x93` / `lsls r2, #1` for 0x126); the target steps it (`add r2, #2`) from the 0x124 the arms left in `r2`. agbcc's CSE only knows an offset register inside the block that built it, and cross-jumping runs afterwards — so a *stepped* offset across the join means that code sat in **both** arms and was merged. Calling a `static inline` helper from each arm reproduces it without duplicating the source.
- The same applies to a field the arms leave alone. `Entity08080be8_SetupHitbox` sets a `Vec3` differently per arm and then `offset.z = 0`; factored out after the join it reloaded the `0xFFFF0000` half-word mask from the pool, while the target keeps it live in a register. Writing the whole vector in each arm (`offset.x = 0, offset.y = 30, offset.z = 0;`) lets cross-jumping merge the identical `z` store and keeps the mask where the target has it.
- In a loop the same variable also costs a register: `u32 val = 0; if (VM_GetPC() != NULL) { val = Script_GetValue(); } args[i] = val;` hoisted the `movs #0` out of the loop and pushed three values into `r8`-`r10`. `if (VM_GetPC() != NULL) { args[i] = Script_GetValue(); } else { args[i] = 0; }` cross-jumps the store, and the `movs #0` disappears entirely because `r0` is already 0 on the `beq` path.

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
