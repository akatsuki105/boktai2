# agbcc internals — decision rules read from the compiler's source

Every rule here was read out of the compiler that builds this project, and
every claim carries the file and line it came from. This file answers *why a
pass decides what it decides*; `agbcc-levers.md` answers *what to try next*.
The corpus of C that is already known to produce given bytes is `src/` itself —
every `MATCHING` function in it, and `git log -p` on that function. Keep the
three apart:

- **Internals proposes.** A pass's source tells you what inputs it reads, so it
  tells you which levers exist — including ones nobody has tried yet.
- **The ROM disposes.** Source reading cannot tell you what survives the
  remaining passes. Nothing here is confirmed until `make compare` prints the
  OK line.

Reading a rule here and asserting it about a real function is the mistake this
file is meant to prevent. Use a rule to pick the next experiment, then let the
ROM decide.

**The compiler.** `tools/agbcc/bin/agbcc`, built from `../agbcc`
(`akatsuki105/agbcc` = `pret/agbcc` plus `-fsigned-narrow-modes` and
`-ffix-shift-compare`). Paths below are relative to that tree's `gcc/`
directory. Line numbers are from commit `9915d1b`; they drift, so grep for the
quoted code rather than trusting the number.

**Confidence markers.** `[source]` — stated unconditionally in the code quoted.
`[derived]` — follows from several quoted facts. `[unverified]` — plausible but
not yet checked here; treat as a question, not a fact.

---

## 0. Build configuration (ground truth for everything below)

`[source]` `Makefile:74,84`, `Makefile:203-206`, `Makefile:113-121`

```
CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -undef -std=gnu89
CFLAGS   := -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm
```

- The pipeline is `cpp -> tools/preproc -> agbcc -> as`, and each `.s` gets
  `.text` + `.align 2, 0` appended, so inter-function padding is **zero**, not
  `0x46C0`. Padding is the assembler's decision, not the compiler's.
- Three files do not use the default: `sprite_main_arm.c` and
  `lib/librfu_intr.c` are compiled by **`agbcc_arm`** (ARM mode, a different
  machine description), and `lib/agb_eeprom.c` uses `-O`. Every Thumb rule
  below is silent about those.

---

## 1. There is no instruction scheduler

`[source]` `thumb.md` has no `define_function_unit` (0 matches), and the
scheduler itself is not in the tree — there is no `sched.c` or `haifa-sched.c`,
and `flag_schedule_insns` does not exist anywhere in `gcc/`.

So an "out of order" instruction sequence is never a scheduler artifact. It is
expansion order, CSE, combine, or register allocation. `-fschedule-insns` and
friends are not options this compiler has; do not reach for them.

---

## 2. Values narrower than a word

### 2.1 They are held in registers as unsigned

`[source]` `thumb.h:349-359`

```c
#define PROMOTE_MODE(MODE,UNSIGNEDP,TYPE)       \
{                                               \
  if (GET_MODE_CLASS (MODE) == MODE_INT         \
      && GET_MODE_SIZE (MODE) < 4)              \
    {                                           \
      if (! flag_signed_narrow_modes)           \
        (UNSIGNEDP) = 1;                        \
      (MODE) = SImode;                          \
    }                                           \
}
```

A `s8`/`s16` value promoted into a register loses its declared signedness
unless `-fsigned-narrow-modes` is passed. This is the 03-OCT-03 AGB kit change;
it is **off by default** because the original build does not appear to have had
it (see §2.4).

Two other macros push the same way, and are *not* behind a flag:

`[source]` `thumb.h:1058,1060`

```c
#define WORD_REGISTER_OPERATIONS
#define LOAD_EXTEND_OP(MODE) ZERO_EXTEND
```

so a narrow load is assumed to zero-extend to the full word.

**From C.** The only lever is the declared type at the point of use. A cast
applied *after* a load does not change the load instruction — the load
mnemonic is fixed by the type of the object being read.

### 2.2 Every sub-word function argument is already `int`

`[source]` `thumb.h:632` `#define PROMOTE_PROTOTYPES 1`, consumed at
`c-typeck.c:1750` (call site) and `c-decl.c:5473` (parameter declaration).

The front end converts a `char`/`short` actual argument to `int` before the
call is expanded, and rewrites the parameter's `DECL_ARG_TYPE` to
`integer_type_node`. By the time `calls.c` or `function.c` sees the argument
it is `SImode`.

**Consequence worth knowing.** `PROMOTE_FUNCTION_ARGS` and
`PROMOTE_FUNCTION_RETURN` are **undefined** for this target (0 matches in
`thumb.h`). Defining them changes nothing, because `PROMOTE_PROTOTYPES` already
did the widening — measured at 0 of 283 objects. The official 03-OCT-03
`cc1.exe` also leaves both undefined: its `setup_incoming_promotions` is an
empty function, it has no `promoted_input_arg`, its `expand_call` never calls
`promote_mode`, and its one `assign_parms` call passes `for_call = 0`.

Do not re-open this. It is a closed question.

### 2.3 Narrow arithmetic keeps its width by shifting

`[derived]` from §2.1 plus `expmed.c` expansion.

A value declared `s8`/`s16` and *kept* narrow across an operation is handled by
a `lsl`/`asr` (or `lsl`/`lsr`) pair around the operation, not by a narrow
register. Whether the pair lands before or after the operation is a real
codegen distinction; grep `src/` for functions with the same access pattern.

### 2.4 What is known about the 03-OCT-03 patch

`[source]` The official patched `cc1.exe` (`thumb_patch03-OCT-03`) was
disassembled: its `promote_mode` writes `*punsignedp` back unchanged, which is
exactly `-fsigned-narrow-modes`. The 30-May-2003 revision is in
`simplify_comparison`'s `case LSHIFTRT:` block and is `-ffix-shift-compare`.

`[derived]` Enabling `-fsigned-narrow-modes` globally changes 2 of 283 objects
(`src/armor.o`, `src/vm_ctrl2.o`); `-ffix-shift-compare` changes 0. In
`SwapArmorSlot` the natural source plus the flag emits `ldrsh` where the ROM
has `ldrh`, so **that translation unit** behaves as if unpatched. Whether the
whole ROM was built unpatched is open — the game shipped 2004-07-22, well after
the patch date, and FE8J (2004-10) needed promote-preserving behaviour for a
*subset* of its translation units.

---

## 3. Function call ABI

### 3.1 Arguments are evaluated and loaded left to right

`[source]` Neither `PUSH_ARGS_REVERSED` nor `LOAD_ARGS_REVERSED` is defined
anywhere in `gcc/`, so every guarded loop in `calls.c:expand_call` takes its
forward branch: the argument array is filled front to back, expressions are
expanded arg0-first in `precompute_register_parameters`, and pseudos are moved
into `r0`..`r3` in ascending order.

**From C.** The order is not selectable. If the target's `mov r0..r3` sequence
differs from yours, the cause is the argument *expressions* or the *prototype*,
never an ordering knob. `PROMOTE_PROTOTYPES` (§2.2) means a wrong narrow
parameter type shifts nothing about which register an argument lands in, but it
does change the extension emitted inside the callee.

### 3.2 The epilogue never pops into `pc`

`[source]` `thumb.c:560-577` (`thumb_exit`) and `thumb.c:686-698`
(`thumb_pushpop`). Under `-mthumb-interwork` the return address is popped into
a scratch register and `bx`'d:

```
pop {r4, r5}
pop {r1}
bx  r1
```

The scratch register is chosen from the return value's mode — a void function
can use any argument register, a value-returning one cannot use `r0`.

Seeing `pop {..., pc}` in the target means that function was **not** built with
`-mthumb-interwork`, i.e. not by this build's default rule.

---

## 4. Register allocation

### 4.1 Lowest free register wins

`[source]` There is no `REG_ALLOC_ORDER` and no `ORDER_REGS_FOR_LOCAL_ALLOC`
(0 matches in `gcc/`). Both allocators scan hard registers in ascending
numeric order and take the first free one: `local-alloc.c:1947`
(`find_free_reg`) and `global.c:991` (`find_reg`).

There is no allocation order to fight. Every register permutation difference
traces back to §4.2 and §4.3.

### 4.2 Crossing a call decides the register class

`[source]` `local-alloc.c:1896-1901` and `global.c:948-953`:

```c
else if (qty_n_calls_crossed[qty] == 0)
  COPY_HARD_REG_SET (used, fixed_reg_set);
else
  COPY_HARD_REG_SET (used, call_used_reg_set);
```

With `CALL_USED_REGISTERS` marking `r0`-`r3` call-clobbered (`thumb.h:411-417`):

- a value whose live range never spans a `bl` competes for `r0`..`r7`, so it
  tends to land in a low scratch register;
- a value that must survive a `bl` can only get `r4`..`r7`.

**From C, this is the strongest lever.** Moving a use across a call — caching a
field into a local before a loop that calls something, or reading it after the
call instead — flips a value between scratch and callee-saved.

### 4.3 Order among competitors: references, live range, then creation order

`[source]` `local-alloc.c:1435`:

```c
#define QTY_CMP_PRI(q) \
  ((int) (((double) (floor_log2 (qty_n_refs[q]) * qty_n_refs[q] * qty_size[q]) \
          / (qty_death[q] - qty_birth[q])) * 10000))
```

and the same shape in `global.c:618-622`. Higher priority is allocated first,
so it gets the lower register. Ties break on the pseudo/allocno number, which
follows creation order (roughly source order).

**From C.** Three inputs, all reachable: how many times a local is referenced,
how long it stays live (move its first or last use), and — only when the first
two tie — the order the values are first computed. Splitting one local into two
or merging two into one changes the quantity count and therefore the whole
permutation.

When two locals are genuinely symmetric in all three, the only remaining
tiebreak is an artifact of how the RTL was walked. That is the residual case
where the permuter is the right tool rather than another rewrite.

### 4.4 The prologue push mask is a function of what was referenced

`[source]` `thumb.c:781-789`:

```c
for (regno = 0; regno < 8; regno++)
    if (regs_ever_live[regno] && !call_used_regs[regno])
        live_regs_mask |= 1 << regno;

if (live_regs_mask || !leaf_function_p() || far_jump_used_p())
    live_regs_mask |= 1 << 14;
```

Only `r4`-`r7` satisfy `!call_used_regs`. `lr` is added when any low register
is saved, or the function is not a leaf, or it uses a far jump. High registers
`r8`-`r12` are handled separately (`thumb.c:791-797`) by copying them down into low
registers and pushing those.

`regs_ever_live` is set for *any* referenced hard register, so a
`register T x asm("rN")` pin does end up in the mask. There is no
"asm-pinned registers are not saved" behaviour here.

**From C.** A push-mask difference of one register is a live-value-count
difference, not a cosmetic one. The `lr` bit is decided purely by leaf-ness, so
adding or removing a call changes it.

---

## 5. Shifts, multiplication, division

### 5.1 `lsr` vs `asr` is decided by one flag

`[source]` `expmed.c:1571` picks `lshr_optab` when `unsignedp`, `expmed.c:1590`
picks `ashr_optab` otherwise. `unsignedp` is the signedness of the shifted
operand's C type at the shift site.

Remember the integer promotions: `u8` and `u16` promote to signed `int`, so
`someU8 >> n` is an `asr` on the promoted value unless it is re-cast unsigned.

### 5.2 Division by a non-power-of-two is always a library call

`[source]` `thumb.md:652` defines `mulsi3` and nothing else in that family —
no `mulsidi3`/`umulsidi3`, no `smulsi3_highpart`/`umulsi3_highpart`, no
`divsi3`/`udivsi3`. `expand_divmod`'s magic-multiplier paths are all guarded by
`if (t1 == 0) goto fail1;` and `expand_mult_highpart` cannot produce anything
without one of those patterns, so control falls through to the libcalls
registered at `optabs.c:4134-4139`: `__divsi3`, `__udivsi3`, `__modsi3`,
`__umodsi3`.

**Two directions.** Write the plain `/` or `%` when the target has the libcall.
And when the target has a magic constant plus a high multiply, that was *not*
produced by a `/` in the source — it is hand-written asm or a literal
multiplication.

### 5.3 Signed division by a power of two carries a bias

`[source]` `expmed.c:2810` selects between two forms with
`if (abs_d != 2 && BRANCH_COST < 3)`, and `thumb.h:966` sets
`#define BRANCH_COST (optimize > 1 ? 1 : 0)`, which is 1 at `-O2`.

- `N > 2`: `cmp #0; bge L; add #(N-1); L: asr #log2(N)`
- `N == 2`: the branchless form (`abs_d == 2` takes the other branch)
- unsigned: a single `lsr`

So `x / 4` and `x >> 2` are different instruction sequences for a signed `x`,
and `x / 2` does not look like `x / 4`.

---

## 6. Switch lowering

`[source]` `stmt.c:4915-4924` and `stmt.c:4926-4931`. `thumb.md` has no
`casesi` (0 matches) but does have `tablejump` (`thumb.md:979`), and the
generated `insn-flags.h` has `HAVE_tablejump 1` with no `HAVE_casesi`, so the
`#else` applies and `CASE_VALUES_THRESHOLD` is **5**. `thumb.h` does not
override it.

A switch becomes a jump table only when **all** of:

- `count >= 5` (a case *range* counts as two), and
- `maxval - minval <= 10 * count`, and
- the span fits one host word, and
- the index is not a compile-time constant.

Otherwise it is a compare chain — and the compare chain is a **binary search**
over the case values, not a linear scan (`emit_case_nodes` /
`balance_case_nodes`).

**From C.** Only the shape of the case set is reachable: the number of labels
and their density. The thresholds are compiled in. Read the truth off the
target — a jump table's entry count is `range + 1`, which hands you
`minval..maxval` directly.

---

## 7. Branches and jump optimization

`[source]` `insn-config.h:12` defines `HAVE_cc0` and `thumb.md` uses `cc0`
throughout, so the `#ifdef HAVE_cc0` transforms in `jump.c` are live and the
`#ifndef HAVE_cc0` ones are dead. `flag_thread_jumps` is set to 1 whenever
`optimize >= 1` (`toplev.c:3610`).

The transform that matters most for hand decompilation is
**branch-around-branch** (`jump.c:1730-1780`): a conditional jump over an
unconditional jump is rewritten by `invert_jump (insn, JUMP_LABEL
(reallabelprev))` at `jump.c:1750` and the unconditional jump is deleted. So

```c
if (c) goto over; goto L; over:
```

becomes a single inverted conditional branch.

**From C.** None of these is a switch you can flip; the lever is the shape of
the control-flow graph. A conditional branch whose polarity is inverted from
the target almost always means the `if`/`else` arms are assigned the other way
round. Inverting the condition and swapping the two bodies is semantically
identical and changes the emitted branch.

### `tst` is never emitted

`[source]` `thumb.md:818` defines a pattern named `tstsi` — but it prints
`cmp %0, #0`:

```
(define_insn "tstsi"
  [(set (cc0) (match_operand:SI 0 "s_register_operand" "l"))]
  ""
  "cmp\\t%0, #0")
```

No pattern in `thumb.md` emits the Thumb `tst` instruction. A mask test
therefore lowers to `mov #mask; and; cmp #0; b<cc>`.

**Triage value.** A `tst` in a **Thumb** function cannot have come from this
compiler, so that function is hand-written asm and is not worth grinding on.
This does not apply to ARM-mode functions — `agbcc_arm` uses a different
machine description, and this project compiles `sprite_main_arm.c` and
`lib/librfu_intr.c` with it.

---

## 8. Constants and register moves

`[source]` `thumb.md` `*movsi_insn` and the two `define_split`s after it, with
`CONST_OK_FOR_LETTER_P` at `thumb.h`:

| source operand | emitted |
|---|---|
| a low register | `add %0, %1, #0` |
| `I`: `0 <= v < 256` | `mov %0, #v` |
| `J`: `-256 < v <= 0` | `mov` then `neg` (split) |
| `K`: `thumb_shiftable_const` — `v == imm8 << i`, `i < 25` | `mov #imm8` then `lsl #i` (split) |
| anything else | `ldr %0, =v` from the literal pool |

Two consequences:

- A register-to-register move between low registers is **`add rD, rS, #0`**, not
  `mov`. A real `mov` appears only when a high register is involved, which makes
  the mnemonic a readable signal about where a value landed.
- A constant is not always pooled. `0x05000000` is `0xA0 << 19`, so it is built
  with `mov`+`lsl`. Read the pool word before assuming the target's constant
  differs from yours.

---

## 9. Inline functions are emitted at the end of the translation unit

`[source]` `toplev.c:2638` and `toplev.c:2658` set `DECL_DEFER_OUTPUT (decl) = 1`
for an inlinable function at file scope, which postpones the decision to emit
its out-of-line body until end-of-file processing.

So a **non-static** `inline` function's out-of-line copy lands after every
normally emitted function in the same file. The official `cc1.exe` does the same
(checked directly). This is why `src/album_menu.c` cannot use the natural single
`inline` spelling: the body would be correct but would sit at the wrong offset.

A `static inline` whose every call was inlined emits no standalone copy at all.

`[unverified]` `function_cannot_inline_p` (`integrate.c:113`, called from
`toplev.c:2599`) can reject an explicitly `inline` function, which would keep it
in source position. The rejection conditions have not been read here.

---

## Adding an entry

Three requirements, in order of importance:

1. **Quote the source.** File, line, and the code itself. An entry without a
   quotation is not an internals entry. A procedure belongs in
   `agbcc-levers.md`; an observation about which C shape matched belongs
   nowhere but `src/`, where the matched function already is.
2. **Mark the confidence.** `[source]` only when the quoted code states the rule
   unconditionally. `[derived]` when you combined facts. `[unverified]` for
   anything you are reasoning about but have not read.
3. **Say what C reaches it.** A rule nobody can act on from the source file is
   trivia. If the answer is "nothing", say that — it saves the next attempt.

Do not copy a rule from another project's documentation without re-reading
this tree. FE8J's `-mjp-promote` is documented there as needing
`PROMOTE_FUNCTION_ARGS`; here that half is provably inert and absent from the
official compiler. Their "agbcc cannot emit `tst`" does hold, but for a
different reason than stated — the pattern exists and prints something else.
A rule that is wrong here is worse than no rule.
