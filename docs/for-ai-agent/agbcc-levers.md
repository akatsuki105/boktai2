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
- **`if (a && b) return X; return Y;` and `if (!a) return Y; if (b) return X; return Y;`
  put different arms on the fallthrough.** The `&&` chain emits the `X` block
  first and branches over it; the split form emits `Y` right after the second
  compare and puts `X` last, cross-jumping the two `Y` returns into one.
  `FUN_08084710` only closed on the split form.
- **Do not collapse a duplicated body into `||`.** `if (a) {X} else if (b) {X}`
  and `if (a || b) {X}` emit different condition tests; the shared tails are
  cross-jumped but the branches stay distinct. Write the structure the target
  actually has.
- **Shared tails.** If the target reaches one `bl` from two arms and you emit
  two, your two tails are not textually identical. Compute a common local in
  each arm and call once.
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
  guard and takes a different register (`VM_Loop`).

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
- **Narrowing at a boundary.** A trailing `lsl`/`asr` pair at the end of a
  function is a narrow return type; the same pair after a `bl` is a cast of the
  call's result; a plain `strh`/`strb` with no shifts is a store-only
  truncation.

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
block-structure difference you have not found yet.

---

## 5. Tier D — per-translation-unit compiler flags

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
