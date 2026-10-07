# Levers — what to try when a function nearly matches

`agbcc-internals.md` says why a pass decides what it decides.
`src/` is the corpus: every `MATCHING` function there is a proven C-to-bytes
pair, and `git log -p` on one shows what closed it.
This file is the **procedure**: given a function that is close but not
matching, what to try next and in what order.

The ordering is not stylistic. Each tier is cheaper to verify, easier to
defend as something a 2003 programmer would have written, and more likely to
survive the next edit than the tier below it. Escalating early is how a wrong
reconstruction gets frozen behind a trick that happens to cancel it out.

**The project's policy, stated once.** The original was written by a person, so
the goal is the source they wrote, not any source that produces these bytes.
`register T x asm("rN")`, `asm("")` barriers and hand-written instructions can
force a match — they are in tier E below — but **a match obtained that way is
not evidence the reconstruction is right**, and this project does not commit
them. Tier E exists as a *diagnostic*: it tells you which register or spill the
target wanted, which is information you then use to find the source shape.

---

## 0. First: is this even a codegen problem?

Before any lever, rule out the cheap causes. Most "near misses" are one of
these, and no lever will fix them:

- **A wrong struct field type.** The load mnemonic is the oracle and it cannot
  be overridden by a cast: `ldrb` = `u8`, `ldrsb` = `s8`, `ldrh` = `u16`,
  `ldrsh` = `s16`. A signed 16-bit read appears as `mov rN, #off` followed by
  `ldrsh r, [b, rN]`, so grepping for `#0x20]` finds only the unsigned form —
  grep for `ldrs` and read the preceding `mov`. Ghidra's decompiler output is
  not evidence about width or signedness; the disassembly is.
- **A wrong prototype.** Argument count, return type, and whether the return
  value is used all change the emitted code.
- **A wrong struct size.** An index scale of `lsl #2` on a three-`char` struct
  is correct — agbcc pads to the alignment. Check `sizeof` before blaming the
  index arithmetic.
- **A stale build.** `make clean-code` before believing a match or a mismatch.

---

## 1. Classify the residual

Read the streamdiff (`.claude/skills/decomp-func/scripts/streamdiff.py`) and
decide which of two things you are looking at. They need different tiers.

- **Opcode difference** — different instructions, or a different number of
  them. This is a *shape* problem: control flow, types, expression structure.
  Go to tier A.
- **Allocation difference** — same opcodes in the same order, different
  registers or a different spill decision. Go to tier C, and read
  `agbcc-internals.md` §4 first, because the three inputs to the priority
  formula are the only things you can move.

If the target contains a `tst`, or a conditional branch that reuses flags from
a `subs`/`adds`/`ands` with no `cmp` in between, stop. This compiler emits
neither (`agbcc-internals.md` §7). That function is hand-written assembly and
no C will match it. This test applies to Thumb only — `sprite_main_arm.c` and
`lib/librfu_intr.c` are ARM and use a different machine description.

---

## 2. Tier A — control flow and expression shape

The highest-yield tier, and the only one that also makes the source more
plausible.

- **Branch polarity and which arm falls through.** A conditional branch with
  the opposite condition from the target usually means the `if`/`else` bodies
  are assigned the other way round. Inverting the test and swapping the bodies
  is semantically identical and changes the emitted branch
  (`agbcc-internals.md` §7).
- **Loop form.** A constant positive bound folds to a bottom-tested loop with
  no entry guard; a runtime bound keeps the guard. If the target has a guard
  and you do not, the bound is not the constant you assumed.
- **An ascending index loop comes back descending.** With no loop-carried
  dependency, gcc reverses `for (i = 0; i < 4; i++) a[i] = 0;` and walks a
  pointer *down* from `&a[3]`, exiting on a **signed** compare against the base.
  So a descending pointer walk in the target is evidence of an *ascending*
  source loop. The descending form keeps its counter and cannot be reversed
  again, which is one instruction too many (`VM_Ctrl_SetZoneCallback`,
  `Text_FormatDecimal`):

```sh
printf 'void f(unsigned short*a){int i;for(i=0;i<4;i++){a[i]=0;}}\n' \
  | tools/agbcc/bin/agbcc -mthumb-interwork -O2 -o - -
# add r1,r0,#6 / strh / sub r1,#2 / cmp r1,r0 / bge
```

- **Do not write the walking pointer yourself.** The cursor a reduced loop uses
  is created by the compiler in the loop preheader, i.e. *after* the `i = 0`
  init. Declaring `u16* dst` before the loop and writing `*dst++ = v` puts its
  initialization *before* the init and costs a move; the array-index form
  (`ev.args1[i] = v`) lets strength reduction place it where the target has it
  (`VM_Ctrl_SetZoneCallback`).
- **`if (a && b) return X; return Y;` and `if (!a) return Y; if (b) return X; return Y;`
  put different arms on the fallthrough.** The `&&` chain emits the `X` block
  first and branches over it; the split form emits `Y` right after the second
  compare and puts `X` last, cross-jumping the two `Y` returns into one.
  `FUN_08084710` only closed on the split form.
- **Which of the two `movs r0, #N` blocks comes first names the `if`'s own
  return.** For a predicate that ends in `movs r0, #0` / `b` / `movs r0, #1`,
  the block emitted *first* is the value the `if` body returns and the second is
  the fallthrough `return`. So `0` first means the source is the de Morgan'd
  form — `if (!a || (b && c)) return FALSE; return TRUE;` — not
  `if (a && (!b || !c)) return TRUE; return FALSE;`. Negating the whole
  condition and swapping the two returns is the only edit needed, and it leaves
  the individual compares' polarity alone (`FUN_0807a9d0`).
- **`x = (a && b)` puts its accumulator init where the first operand ends.**
  The `movs rX, #0` that starts a materialized `&&` is emitted *after* whatever
  RTL the first operand needed. If the target has it after the first `ldrh` and
  you have it before, cache that operand in a local: `u16 state = p->unk_446;`
  then `skip = state != 0 && p->unk_442 == 7;` moves the init past the load and
  nothing else changes (`FUN_080667b0`).
- **Do not collapse a duplicated body into `||`.** `if (a) {X} else if (b) {X}`
  and `if (a || b) {X}` emit different condition tests; the shared tails are
  cross-jumped but the branches stay distinct. Write the structure the target
  actually has.
- **Shared tails.** If the target reaches one `bl` from two arms and you emit
  two, your two tails are not textually identical. Compute a common local in
  each arm and call once. The converse is also a lever: one `bl` whose argument
  differs per arm can come from **two calls** that agbcc cross-jumped. A ternary
  or a local hoists one of the constants above the compare and saves an
  instruction; writing the call out in both arms keeps each constant inside its
  own arm (`Entity08001610_Create`).
  A single `bl` shared by two arms is sometimes **not** reproducible: when both
  arms are `return f(...)` with different arguments, agbcc cross-jumps the one
  `bl` whatever the surrounding shape, while the target keeps two. Every spelling
  tried (if/else, early-out, a `ret` local, a local for the argument) merged it,
  so this residual is one instruction that no source-level change reaches
  (`FUN_0807a6cc`).
- **Aggregates.** Several scalars that always travel together may have been one
  struct. A local aggregate has different lifetime and addressing rules than
  independent locals, so restoring it changes codegen as well as readability.
  Check `include/` for an existing type before inventing one.
- **`&local` forces a stack home.** A frame larger than your locals justify, or
  a stack slot for something that could live in a register, means the source
  took an address you did not.
- **`lsls #5` / `lsrs #3` on a count, then `sub sp`, is a variable-length
  array.** agbcc sizes a VLA in bits and divides by 8, so `u32 argv[n]` becomes
  `n << 5 >> 3`. The base address gets its own stack slot, the old `sp` another,
  and both are restored in the epilogue (`VM_Loop`).
- **Index the array, do not walk a pointer.** `argv[j] = ...` lets strength
  reduction create the walking pointer in the loop's preheader, i.e. *after* the
  entry guard; `u32* dst = argv;` above the loop materializes it before the
  guard and takes a different register (`VM_Loop`). Strength reduction also
  folds the member offset into the pointer (`ldr r0, [r1]` on `p->a[i].flags`,
  stride `sizeof(a[0])`), and turns an ascending `i < N` into a countdown trip
  counter; a hand-written `for (i = N - 1; i >= 0; i--, q++)` keeps the offset
  (`ldr r0, [r1, #0x8]`) and does not match (`SolarBank_HideAllSprites`).

### A repeated `||` comparison is CSE'd; an inlined predicate is not

`Time_GetSpanOfTime` compares `(hour, minute)` lexicographically against two boundary
times, three times over. Written out as `a.hour < b.hour || (a.hour == b.hour &&
a.minute < b.minute)` at each site — or through a macro, which is the same tree —
agbcc shares the compares and the function comes out 81 instructions against the
target's 107. The same comparison as a `static inline` returning `bool32` is
expanded separately per call, each copy materializing its own 0/1, and reaches
105. The remaining 2 are the `.minute` loads: by-value parameters are evaluated
at the call, while the target loads a minute only on the path that needs it.
Pointer parameters make it worse (119) because each `&gClock.field` becomes its
own pool constant. Left NON_MATCH with the plain expression, because an inline
that does not close the gap does not belong in `src/`.

### Caching an operand in a local pins both the order and the association

Two symptoms turn out to have one cure. `bool32 k = FALSE; if (p->a != 0 && p->b == N) { k = TRUE; }`
emits `movs rK, #0` *before* the load of `p->a`, while several targets emit it
after; and `a - (b - 100)` is reassociated by fold into `(a + 100) - b`, so the
`subs #0x64` lands on the wrong register. In both cases naming the first operand
in a local — `u16 n = p->a;`, `s32 agility = p->stats[...];` plus
`s32 over = p->armor.weight - 100;` — reproduces the target exactly: the load
becomes its own insn that cannot be sunk past the accumulator init, and a local
is not a `PLUS_EXPR` that fold can split, so the constant stays with its own
operand (`CalcMoveSpeed`).

Caching only the *second* operand is not enough and makes things worse: with
`over` alone the weight is loaded before the first operand, which is the opposite
of the target. Cache the leftmost operand first.

### An empty `case` is dropped, and that moves the switch's pivot

agbcc builds a `switch` as a balanced binary tree over the case values and picks
the root by node count, so the first `cmp` names how many cases the source had:
four cases spanning 0..3 pivot on 1, three cases spanning 0..3 pivot on 2. A
case whose body is only `break;` is removed before the tree is built, so writing
`case 1: { break; }` for a case the target clearly dispatches on changes nothing
and leaves the pivot wrong. `case 1: { return; }` keeps the node — the `return`
is real code, and after jump optimization its jump lands on the same end label,
which is why the case looks empty in the disassembly (`FUN_0806f1ec`).

### A cached global pointer that the target reloads per store

`gStat->playerX = pos->x;` three times in a row emits one `ldr rG, [=gStat]`
here and three `strh` through it; several targets keep the *address* in a
register and reload `[rG]` before every store, while still re-reading `pos`
each time. agbcc's CSE invalidates the `pos` MEM on each store but decides the
store cannot touch the `gStat` variable itself, so the pointer stays cached.
`-fvolatile-global` reproduces the three loads, which only confirms the
mechanism — it is a whole-translation-unit flag and `gStat` cannot be volatile,
since functions that read two of its fields in one expression match today.
Writing the stores through three `static inline` setters does not help (they are
inlined and then CSE'd together), nor does a `GameInfo*` local, which is the
opposite direction. `FUN_0807a91c` stays two instructions short.

The read side behaves the same way. `FUN_08078844` tests `gEntity0B50 != NULL`,
reads one of its fields, and then reads two more fields to build a call's
arguments; the target keeps `&gEntity0B50` in a register (`adds r3, r0, #0`) and
reloads `[r3]` for the argument setup, because the branch join in the middle of
the condition ends the extended basic block. agbcc folds all of it into a single
load and comes out two instructions short. Caching the pointer in a local, or
caching it only for part of the condition, hoists the load above the first
condition instead and makes the diff worse; nesting the conditions as separate
`if`s changes nothing.

### `gPlayerPtr[i]` loads into a temp and is copied

`Player* p = gPlayerPtr[i];` emits `ldr rP, [rAddr]` straight into `p`'s
register. Several targets instead emit `ldr r0, [r0]` followed by a dead
`adds rP, r0, #0` and then compare `rP`, i.e. the element read and `p` are two
pseudos that agbcc never coalesced. Tried without effect: the initializer and a
separate assignment, either declaration order, `u32` vs `s32` for the index,
`*(gPlayerPtr + i)` and `*(i + gPlayerPtr)` (both move the pool load instead),
reading the element twice so CSE makes the temp explicit, a
`static inline Player* GetPlayerPtr(s32 n)` accessor with the index passed in or
the call nested inside, and splitting the two early-outs. Leaves
`FUN_0807b1a4` and `FUN_0807b2dc` at a one-instruction residual.

### The 0/1 materialization: it comes back from two plain statements

**Closed for the assignment form** (`Entity0809eb24_Update`). The materialization
survives when the flag is set by its own `if` statement and read by a later one:

```c
u16 override = gSunlightOverride;   /* 先頭オペランドをローカルに退避する */
bool32 forced = FALSE;

if (override == 1) {
  forced = TRUE;
}
if (forced && u16_03002bf0 != 0) { ... }
```

That emits `ldrh` → `movs rK, #0` → `cmp` → `movs rK, #1` → `cmp rK, #0`, exactly
the target. What folds it is writing the flag as one expression —
`bool32 forced = (gSunlightOverride == 1);` collapses into the branch and comes
out 5 instructions short, and so does a `static inline` predicate whose `return`
is the materialized value. The local for the first operand is what puts the
`movs #0` *after* the load (see "Caching an operand in a local" above); without it
the init is hoisted ahead of it.

Untried lead for the sites below: they all consume an inline predicate's return
value directly (`if (!T(bit)) { return TRUE; }`). Rewriting them in the two-statement
form — `bool32 ok = FALSE; if (gStat->unk_934 & mask) { ok = TRUE; } if (!ok) …` —
has not been measured yet and is the first thing to try.

The rest of this entry is the record of what was tried against the
*return-value* form, which is still open.

About 400 sites across 255 unmatched functions end a predicate test like this:

```asm
	ands r0, r1          @ flags & mask
	cmp r0, #0
	beq _0f
	movs r0, #1
	b _0j
_0f:
	movs r0, #0
_0j:
	cmp r0, #0           @ and only now the real branch
	bne _false
```

The value is materialized as 0/1 and *then* compared. `src/` has never
reproduced it: every spelling collapses the materialization into the following
branch, leaving the function exactly 5 instructions short
(`FUN_08065a98`, `FUN_08065ad0`, `FUN_08065b08`, `FUN_08065b44`,
`FUN_0809e0d4`, `FUN_0809e138`).

Two partial observations, neither of which shortens the residual:

- A one-argument `static inline` predicate such as `Stat_TestFlag934(0x18)`
  reproduces `movs r1, #0x18` **ahead of** the `gStat` load, because the inline
  argument materializes before the body (see the Tier C bullet). Two levels of
  inlining push the mask *after* the load, so it would be one level with a literal.
- The inline's source polarity decides which constant is emitted first:
  `if ((x & bit) == 0) { return FALSE; } return TRUE;` gives `beq` → `movs 0`
  with `movs 1` on the fallthrough, which is what the targets have. The
  `if (x & bit) { return TRUE; } return FALSE;` spelling gives the inverse.

A `static inline` accessor only earns its place in `src/` when a function matches
*because of it*. Writing one, failing to match, and committing both together
leaves an invented accessor that no matching function justifies — delete it and
spell the access out before committing the NON_MATCH.

**Do not put that helper back in `src/`.** It was there for a while and every one
of its six callers stayed NON_MATCH at the same 5-instruction residual, so it
bought nothing while inventing an accessor no matching function justifies — and
the two copies had drifted to opposite polarities. The tree now spells these
tests as the plain `gStat->unk_934 & SF934_x`. Reintroduce an accessor only
together with a spelling that actually closes the residual.

What does **not** work: `!T(b)`, `T(b) == FALSE`, `T(b) == TRUE`, `T(b) & 1`,
`T(b) + 0`, a local for the result at block or function scope, `register`, a
`volatile` local, a second `Not(bool32)` inline (that collapses to the
accumulator `movs r,#0 / … / movs r,#1` form), non-static `inline`, and a
`static` non-inline helper (that becomes a real `bl`). No flag reaches it
either: `-O1`, `-fno-thread-jumps`, `-fno-cse-follow-jumps`,
`-fno-cse-skip-blocks`, `-fno-gcse`, `-fno-rerun-cse-after-loop`,
`-fno-expensive-optimizations`, `-fno-optimize-comparisons`, `-fno-regmove`,
`-fno-peephole`, `-fno-force-mem`, `-fkeep-inline-functions`, and `old_agbcc`
all fold it. The fold happens during RTL expansion, not in a pass that can be
switched off.

The two places it *does* survive are the clue to finish this: when the inlined
predicate's body contains a **loop**, so its result is not a two-way constant
(`FUN_08234660` inlines a linear search and gets `movs r0,#1 / b / movs r0,#0 /
cmp r0,#1`), and when the result has a second real use such as a store. A
spelling that makes the simple mask test opaque the same way is still missing;
until then these functions stay NON_MATCH at a 5-instruction residual, and
writing more spellings of the same four shapes is not worth the build.

---

## 3. Tier B — types and signedness

Still source-level, still defensible.

- **`lsr` vs `asr` is the shifted operand's signedness and nothing else**
  (`agbcc-internals.md` §5.1). Cast at the shift site. Remember `u8`/`u16`
  promote to signed `int`, so a logical-looking shift on a small unsigned type
  is an `asr` unless re-cast.
- **Signed `/` by a power of two is not `>>`**, and `/2` does not look like
  `/4` (§5.3). Signed `% 2^n` is not `& mask`.
- **A 32-bit mask narrows to 16 bits over a `u16` operand.**
  `gStagedDISPCNT & ~(DISPCNT_BG1_ON | …)` puts `0x0000F1FF` in the pool, because
  the `ldrh` tells gcc the high bits are zero. The target's `0xFFFFF1FF` means
  the operand reached the `and` as a plain register: route it through a
  `static inline` with a `u32` parameter (`ShowOnlyBG0(u32 hide)`,
  `HideBG(u32 bits)`) and the full mask survives (`TextSlideshow_Init`).
- **A `u16` read shifted in place still gives `lsr`**, because the value's range
  is known where it is loaded. Route it through an `s32` local
  (`r = *(gRandomTable + i); ... r >> 3`) to get the `asr` the target has
  (`VM_Random`). Passing the value through a `static inline`'s return does the
  same thing, so an `asr` is not by itself evidence of a helper.
- **Widen once at entry.** When the target sign-extends a narrow parameter or
  field once at the top and reuses the wide value, write `int v = narrowThing;`
  instead of letting each use re-extend.
- **Keep it narrow.** The opposite case: when the target operates in the
  shifted domain (`lsl #24` … `asr #24` around the operation, constants shifted
  into the top byte), the value stayed narrow. Do not widen it.
- **`/ 4096` is not how the original divides a fixed-point product.** agbcc
  expands `v / 4096` into the bias form — `cmp v, #0 / bge / add v, #0xfff /
  asr #12`, four instructions with the positive case falling through. Many
  targets instead have `cmp r0, #0 / blt / asr #12 / b / neg / asr #12 / neg`,
  which is the hand-written truncating shift and needs the positive arm in the
  `if` body:

  ```c
  static inline s32 Fix12ToInt(s32 v) {
    if (v >= 0) {
      return v >> 12;
    }
    return -(-v >> 12);
  }
  ```

  `FUN_080700a4` closed on it (two uses, one per axis); `v < 0` as the `if`
  condition swaps the two arms and does not match. Any `gSineTable[...] * dist /
  4096` written the C way is a candidate for the same substitution.
- **Narrowing at a boundary.** A trailing `lsl`/`asr` pair at the end of a
  function is a narrow return type; the same pair after a `bl` is a cast of the
  call's result; a plain `strh`/`strb` with no shifts is a store-only
  truncation.
- **Where a parameter's truncation sits says whose parameter is narrow.** A `u8`
  or `u16` parameter of *this* function is truncated once at entry, before the
  body's first load. The same `lsl`/`lsr` pair sitting *between* two argument
  setups, right before the `str` that places it, is the **callee's** narrow
  parameter instead: this function's parameter is `s32` and the conversion
  happens at the call. `FUN_08066e9c` closed only after its own `s16`/`u8`
  parameters were widened to `s32` and `FUN_08240cf0` was declared with `s16`
  and `u8` ones — and for the same reason its sound id has to stay `SoundID32`,
  since `PlaySound_082406e0` takes the wide type and the target never truncates
  it.

---

- **A signed branch on an address means the source compared ints.** Comparing
  two pointers emits the unsigned form (`bcs`/`bcc`); `bge`/`blt` on two
  address-valued registers means both operands were declared as an integer type,
  not as a pointer (`Entity08001610_ClearTable`, still open).

---

## 4. Tier C — order

For allocation differences. These change which pseudo wins which register
without changing what the function computes.

The three inputs to the priority formula (`agbcc-internals.md` §4.3) are
reference count, live range length, and — only on a tie — creation order.

- **Move a use across a call.** The single strongest lever: a value that spans
  a `bl` can only get `r4`-`r7`, one that does not prefers `r0`-`r3` (§4.2).
  Caching a field into a local before a calling loop, or reading it after the
  call instead, flips the class.
- **Change the reference count.** Hoisting a repeated sub-expression into one
  named temp raises its reference count and pulls it to a lower register. This
  also changes instruction *count*, so use it when the `.text` size differs by
  the width of a repeated computation.
- **Move the first or last use** to shorten or lengthen a live range.
- **Declaration and first-computation order** decides ties. Swapping two
  statements that produce two otherwise-symmetric locals swaps their
  registers.
- **Split or merge a local.** Changing how many quantities exist changes the
  whole permutation, not just one register.
- **Read back through the same local.** If the target keeps one pointer or one
  destination field live across several phases, assign it once and read through
  that local rather than re-spelling an equivalent expression. Re-spelling
  creates a second pseudo with a different role.
- **...but re-spell a value that is only tested.** The reverse case: a local
  holding a word tested against several masks needs a copy to survive the
  `ands`, so you get an extra `adds rN, rM, #0` and `ands` writing into the
  value register. Re-spelling the load in each test (`gInput[0].pressed & MASK`)
  lets CSE hold it in one register and each `ands` writes into the mask register
  (`FUN_080b3e80`).

### Materialization order: where a constant or address is set up

A residual of one or two instructions where **the opcodes and registers agree
but a `movs`/`ldr =pool`/`add rN, sp` sits one slot earlier or later** is not
an allocation problem. It is a question of *when* the operand became a pseudo,
and the answer is almost always the shape of the source, not a compiler flag.
Four positions, cheapest first:

- **A declaration with an initializer materializes at block entry.**
  `MainSprite* spr = &p->sprites[5];` at the top of a block emits the address
  computation before the block's first statement; `MainSprite* spr;` followed
  by `spr = ...` emits it where the assignment is. Same for `Vec3* dst = &pos;`.
- **A `static inline` helper materializes its arguments before its body.**
  `HideBG(DISPCNT_BG1_ON)` with `static inline void HideBG(u32 bits) {
  gStagedDISPCNT &= ~bits; }` emits the folded mask **before** the `ldrh` of
  the global; the same statement written out in full emits it after. This one
  lever closed `FUN_0801f214`, `FUN_0801f328` and `FUN_0801f38c`, each of which
  had sat at a one-instruction residual.
- **A mask local is not the same lever as an inline parameter.**
  `PlayerFlag378 mask = FLAG378_FAIRY; if (p->flag378 & mask)` materializes the
  constant where the `&` needs it, i.e. *after* the field's offset and load, and
  that is what `Player_ApplyDarkbug` matches. When the target materializes the
  mask *before* the offset constant, only an inline with the mask as a parameter
  reaches it: `static inline PlayerFlag378 Player_GetFlag378(Player* p,
  PlayerFlag378 bits) { return p->flag378 & bits; }` closed `FUN_0806f900`,
  where the local spelling stayed four instructions out of order. Note the
  accessor returns the masked value, not a `bool32` — a `bool32` one adds the
  0/1 materialization described in Tier A.
- **So the converse is a lever too.** If the target loads the memory operand
  *first* and only then materializes the constant, the original did **not**
  route that constant through an inline parameter — write the statement out
  against a pointer local (`spr->flags |= SPRFLAG_HIDDEN;`) instead. A
  two-argument `XXX_SetFlags(&p->sprites[5], SPRFLAG_HIDDEN)` puts the bits
  before the load and will not match; a bit computed inside the body
  (`p->flags &= ~bits;`) is folded and stays after it, which is why the
  `ClearFlags` form can match where `SetFlags` does not.
- **`arr[i]`, `*(arr + i)` and `*(i + arr)` are not interchangeable.** The tree
  keeps the source's operand order, so the subscript form materializes the base
  *before* the scaled index, and only `*(i + arr)` emits the index first and
  brings the base in between it and the `add`. Both `VM_Random`
  (`*(gRandTableIdx + gRandomTable)`) and `Player_WeaponEffectStatCond`
  (`*(p->isSabata + gStat->unk_2c8)`, where the target reads the index before
  loading `gStat`) only closed on the index-first spelling, which is also what
  the rest of `src/` uses for `gRandomTable`.
- **Mixing a walked pointer and an indexed access in one loop creates a second
  induction variable.** `elem->field` alone strength-reduces to one register;
  writing `p->elems[i].other` in the same body makes gcc keep a separate byte
  offset and compute `p + constant + offset` for it. `FUN_08084b5c` needed
  exactly that mix — the test through the walked `elem`, the call through
  `p->elems[i].fn`.
- **A local copy of a field suppresses re-reads and their side effects.**
  Reading `p->unk_24` twice is not the same as caching it in a local: the
  repeated read lets CSE keep one pseudo and copy it, and for a `u16` it keeps
  the `lsl #16` truncation that a local's known-zero-extended value removes.
  `FUN_0801e6a0` and `FUN_0801ed18` both closed by *deleting* the local.

Two paired field writes that always travel together (`p->state = n;
p->timer = 0;`) belong in a `static inline` for the same reason: the callee's
argument is set up first, which is what puts a `movs r0, #4` ahead of the
`movs r1, #0` that the written-out form emits in the other order.

A zero-instruction `do { } while (0);` between two statements creates a basic
block boundary and can change emission order without emitting anything. It is
source, not asm, but it is also not something a person writes — treat it as
tier D in spirit: a signal that the real answer is a statement-order or
block-structure difference you have not found yet. A 2-byte residual that resisted
about twenty source forms, eight flags and 130k permuter iterations closed on
exactly this — the callee-save copy order between two adjacent stores
(`AddAttr2dBitMap` in laqieer/fireemblem8j, `docs/agbcc_codegen_levers.md`).

---

## 5. Tier D — per-translation-unit compiler flags

### Keep a new `static inline` out of shared headers

Moving `HideBG` (`gStagedDISPCNT &= ~bits;`) from `src/bg.c` into `include/video.h`
so a third file could call it changed the register allocation of
`GameOverManager_StateShowLogo` in `src/gameover.c`, which neither calls it nor
mentions `gStagedDISPCNT`. Merely being declared in an included header is enough.
Define the helper per translation unit instead — which is what `bg.c` and
`entity_ef6f.c` already do with identical copies.


Per-file overrides go in `Makefile` after line 107, next to the existing
`sprite_main_arm.o` and `agb_eeprom.o` rules.

A flag is only a legitimate answer when a *whole translation unit* wants it,
because a flag is a property of how a file was built, not of one function. If
one function in a file wants a flag and the others break under it, the flag is
the wrong explanation.

Defaults at `-O2` (`toplev.c`, verified): `flag_gcse`, `flag_caller_saves`,
`flag_expensive_optimizations`, `flag_strength_reduce`, `flag_regmove`,
`flag_strict_aliasing`, `flag_force_mem`, `flag_cse_follow_jumps`,
`flag_rerun_cse_after_loop`, `flag_rerun_loop_opt` are all **on**;
`flag_inline_functions` turns on only at `-O3`.

Worth trying, in rough order of plausibility:

| flag | what it changes |
|---|---|
| `-O1` / `-Os` | genuinely different instruction selection and stack usage on small functions. This project already does it for `lib/agb_eeprom.o`. |
| `-fno-gcse` | stops a loop-invariant load (typically a lookup table's base address) being hoisted into a callee-saved register, which otherwise evicts a live pointer. |
| `-fno-caller-saves` | pushes a value toward callee-saved or spill instead of a caller-save around a call. `CALLER_SAVE_PROFITABLE` is `4 * CALLS < REFS` (`regs.h:201`). |
| `-fno-strict-aliasing` | shortens register lifetimes. |
| `-fno-expensive-optimizations` | broad; try last of this group. |

Known dead ends, so nobody re-tries them:

- `-ffixed-rN`, `-fcall-used-rN`, `-fcall-saved-rN` do **not** steer Thumb
  register allocation. There is no `REG_ALLOC_ORDER` for them to interact with
  (`agbcc-internals.md` §4.1).
- There is no `-fschedule-insns`. This compiler has no scheduler at all (§1).
- `-fpromote-function-args` was implemented, measured, and removed: 0 of 283
  objects, and the official 03-OCT-03 `cc1.exe` does not define
  `PROMOTE_FUNCTION_ARGS` either (§2.2).

### Measuring a flag's reach

```sh
tools/flag_blast.sh -fno-gcse             # 数える
tools/flag_blast.sh --baseline            # 健全性確認、0 でなければ何かおかしい
```

It builds with the flag appended to `CFLAGS` (through the `EXTRA_CFLAGS` hook in
the Makefile), compares every object against `expected/`, skips `src/lib`
(library code, built under conditions we do not control), and cleans `build/`
afterwards so the next `make compare` is not reading poisoned objects.

A flag reaching 40+ of 283 is almost certainly not what the original used; a
flag reaching 0–3 is a candidate worth checking by hand.

**This is a locator, not a verdict.** Every `.c` in `src/` was written to match
under the *current* flags, so turning a flag on will show differences even
where the original had it on — the source would simply have been written
differently. A zero-reach flag is indistinguishable from an absent one; a
small-reach flag gives you a short list of functions to inspect.

Measured so far, with `tools/flag_blast.sh` (denominator 283, `src/lib`
excluded):

| flag | reach | status |
|---|---|---|
| (baseline, no flag) | 0 / 283 | sanity check — anything else means a stale `expected/` |
| `-fsigned-narrow-modes` | 2 / 283 (`armor.o`, `vm_ctrl2.o`) | candidate; `SwapArmorSlot` argues against it for that TU |
| `-ffix-shift-compare` | 0 / 283 | neutral, indistinguishable |
| `-fpromote-function-args` | 0 / 283 | removed from the compiler |
| `-finline-functions` | wide | disproven — the ROM keeps small helpers as separate functions |
| `-foptimize-comparisons` | — | disproven — `VM_RunOperator` case 20 matches only with it off |
| `-fargument-noalias` | 1 | unverified; measured in an earlier session against a different denominator — re-measure |
| `-fargument-noalias-global` | 3 | same |

---

## 6. Tier E — diagnostic only, never committed

`register T x asm("rN")`, `asm("" : "=r"(x) : "0"(x))`, `asm("" : "+m"(a))`,
and inline instructions all work on this compiler. The pin is honoured and does
end up in the prologue push mask (`agbcc-internals.md` §4.4).

Use them to **ask a question**, not to answer one:

- Pin a local to the register the target uses. If the function then matches,
  you have learned that the only difference was that one allocation — so the
  real answer is in tier C, and you now know exactly which value needs to win
  which register.
- If pinning does *not* make it match, the difference is not allocation and
  tier C will not help either. That is worth knowing early.

Then remove the pin and find the source shape. If no source shape reaches it,
the function stays `NON_MATCH` with the best natural C in its
`NONMATCHING_C` block. A committed pin would hide an unsolved problem behind
something nobody wrote.

---

## 7. When to stop

Two outcomes are honest, and they are not the same thing:

- **Hand-written assembly.** The target contains something this compiler cannot
  emit (`tst`, flag reuse across a branch, ARM mode). No C exists. Record it and
  move on permanently.
- **Unsolved.** Everything else. A Thumb function compiled from C has C that
  reproduces it; you have not found it yet. Leave the best candidate as
  `NON_MATCH` and record the exact differing instructions.

Do not promote the second into the first. A permuter that plateaus proves only
that its mutation vocabulary did not contain the relevant change — usually a
basic-block boundary or a declaration order it never tries. When you stop,
record **which levers you actually exhausted**, so the next attempt starts
above that line instead of repeating it.

The stop condition in `decomp-func` (4 iterations, or 20k tokens) is about
budget, not about proof. Hitting it means "not now", never "impossible".

---

## 8. Recording the outcome

- **The matched C is the record.** It is committed in `src/` and the diff that
  closed it is in git. Nothing needs copying into a document, and a paraphrase
  of it is worth less than the code.
- An explanation for *why* it works goes into `agbcc-internals.md`, and only
  with the compiler source file and line that proves it. If you cannot point at
  the code, do not write the explanation anywhere.
- Which levers you exhausted **without** success goes in the function's
  `NONMATCHING_C` block, so the next attempt starts above that line. This is the
  one thing git does not record, because it is about what is *not* there.
- A tier-E experiment goes in neither. Say what it told you in the report and
  delete it.
