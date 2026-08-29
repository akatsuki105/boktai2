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

- **Frequency**: 1 function confirmed in this project's own log —
  `RemoveSpecifiedItem` (`src/item_082421f0.c`) — but known from prior
  experience decompiling another GBA game to be one of the
  most-frequently-occurring idioms in agbcc-style codebases generally.
  Expect this project's own count to climb quickly once logging catches
  up — don't read the low number so far as "rare," it's an artifact of
  when tracking began, not of true frequency. Log the function every time
  this idiom is what fixes an if/else fall-through mismatch.
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

### Load/declaration order sets register & load order

- **Frequency**: 3 functions confirmed — `FUN_0824c128` (`src/code_0824beb8.c`),
  `FUN_08230860` (`src/code_0823071c.c`), `FUN_08060e90` (`src/player.c`,
  see also the shared-base-pointer entry above — `FUN_08060e90` combined
  both idioms)
  (this project's own log; treat the class of idiom as established more
  broadly from prior experience, per the note above).
- Declaration order of plain locals sets which register each lands in and
  the load order. To evaluate a field load *before* another compare
  operand, hoist it to a local right before the `if`
  (`s32 val = Struct.val; if (val > ...)`). For "compute address early,
  defer the load," use a *pointer* local
  (`s32* ppx = (s32*)((u8*)p+0xb4); ... cx - *ppx`).
- Same principle applies to **operand order within a single expression**,
  not just separate local declarations: `a | (b << 8)` vs `(b << 8) | a`
  can compile to a different load/compute order even though the value is
  identical. `FUN_0824c128`
  (`return p[0] | ((p[1] & 0x1f) << 8);`) only matched once rewritten as
  `return ((p[1] & 0x1f) << 8) | p[0];` — original evaluated the
  mask/shift side first and deferred the plain byte load to just before
  the final combine.
- **Caveat found in `FUN_08230860`**: writing both operands of a
  commutative `|` inline in one expression (`(hash << 5) | (hash >> 0xB)`
  or the reverse) did **not** let source order control register order —
  both textual orders compiled to the identical (wrong) result, unlike the
  `FUN_0824c128` case above. What actually worked was hoisting each
  operand to its own **widened-type** (`s32`, not the narrow `u16` target
  type) local in the desired order:
  ```c
  s32 lo = hash << 5;
  s32 hi = hash >> 0xB;
  hash = lo | hi;       // truncation to u16 happens once, here
  hash = hash + (u8)*s;  // separate statement — its own truncation
  ```
  Two things mattered together: (1) splitting the rotate-combine and the
  add into **separate statements**, because the original had a truncate
  to `u16` after *each* — writing it as one combined expression
  `((hash<<5)|(hash>>0xB)) + byte` loses one of the two truncations; (2)
  declaring the shift results as `s32` rather than `u16` — declaring them
  as `u16` let agbcc fold each local's own truncation into the shift
  immediate (`lsls r0, r1, #21` instead of `#5`), producing extra/wrong
  instructions instead of one shared truncation after the `orrs`.
- **Constant-vs-load order in a mask expression** (`FUN_08060e90`,
  `src/player.c`): for `x & 0xFFFF0000`, plain operand reordering in the
  source (`x & mask` vs `mask & x`) had **no effect** (consistent with the
  `FUN_08230860` caveat above — commutative-op source order isn't always
  load order). What worked was hoisting the constant into its own local
  (`u32 mask = 0xFFFF0000; ... x & mask`) declared *before* the
  read-modify-write — this made agbcc load the constant before the
  variable, matching the original's pool-load-then-variable-load order.
- **Reusing one local for two unrelated temporaries can be the correct
  translation, not a stylistic choice** (`SwapNormalItem`,
  `src/item_082421f0.c`): declaring two separate `s32` locals for (a) the
  swap-temp holding one item slot's old value and (b) a later, logically
  unrelated temp holding a `GetRotCount()` result put (a) in a
  caller-saved register (`r3`) while original kept it in a callee-saved
  register (`r6`) — the same register (b)'s value ends up in later,
  since by the time (b) is computed (a) is already dead. Declaring only
  *one* local and reusing it for both purposes made agbcc allocate it to
  the same persistent register for both uses, matching original exactly.
  When two temporaries in the real source never overlap in lifetime, the
  original C likely reused one variable for both — worth trying before
  assuming distinct locals when a lone register-letter mismatch persists
  on an otherwise-matching function.
- **Swap-temp holding a narrow struct-field value needs a widened local
  type to get a sign-extending load** (`SwapArmorSlot`, `src/armor.c`):
  `armor16_t a = ARMORS(slot1);` (narrow-typed local, same width as the
  field) compiled to a plain `ldrh` (no sign extension) — one instruction
  short of original's `ldrsh`. Declaring the temp as the wider `s32`
  instead (`s32 a = ARMORS(slot1);`) reproduced the sign-extending load;
  the later store back through `ARMORS(slot2) = a;` truncates regardless,
  so no other instruction changed. Same lever as `FUN_08230860`'s
  `s32 lo/hi` truncation-folding note above, but here the trigger is a
  temp that just *carries* a narrow field's value across a couple of
  statements, not one built from a shift/mask expression. Confirmed twice
  now (`SwapNormalItem` used the identical fix for its own swap-temp)
  — worth trying by default whenever a narrow-field swap-temp's load is
  one instruction short.

### Hoist each pool-constant global-pointer access to its own local, declared together

- **Frequency**: 1 function confirmed — `sound_082402f8` (`src/sound.c`).
- When a function's body needs the addresses of two different globals
  (e.g. two array/table pointers, each needing its own `ldr rN, =POOL`)
  and neither address computation depends on the other, agbcc schedules
  *both* pool loads back-to-back, ahead of any other computation that
  doesn't need them yet (like an unrelated shift on a parameter) — even
  though nothing in a naive reading of control flow requires that
  ordering. Writing the second global access inline as part of a larger
  expression (`gSongTable + id * 8`) let the compiler interleave the
  shift (`id * 8`) *between* the two pool loads instead. Fix: give each
  global its own local pointer variable, declared as consecutive
  statements before anything else uses either of them:
  ```c
  u8* base = (u8*)gSoundIDs;
  u8* table = gSongTable;
  u8* entry = table + id * 8;
  ```
  matched only once *both* globals had their own hoisted local — hoisting
  just one still left the other's load displaced.
- Related: when a narrow-typed comparison (`if ((u16)cast == ...)`) isn't
  actually present in the original — i.e. the original just compares the
  full-width parameter directly and only truncates it later, at an actual
  narrow-parameter *call site* — adding an explicit narrowing cast for
  the comparison itself inserts an extra `lsls/lsrs` pair that isn't in
  the original. Removing the cast and letting the truncation happen
  naturally at the call (per the "narrow NAKED-callee parameter" entry
  above) fixed it here (`sound_082402f8`'s `if (id == *q)`, not
  `if ((u16)id == *q)`).

### Declare-with-initializer commits a local to a persistent register too early

- **Frequency**: 2 functions confirmed — `FUN_0824213c` (`src/code_08241f6c.c`),
  `Entity080de11c_Create` (`src/entity_080ddf88.c`, identical singleton-entity-creation
  shape — same lever applied first-try).
- `T* p = someGlobal; if (p == NULL) { ...create/use p across calls...; return p; } return p;`
  keeps `p` live across the *entire* function (including the early-return
  path that doesn't need it to survive any calls), so agbcc allocates it
  a callee-saved register (e.g. `r4`) immediately at entry — even for the
  branch that just re-reads the global and returns right away without
  needing a persistent register at all. Original instead only introduces
  the persistent-register variable on the branch that actually needs a
  value to survive a call (`CreateEntity`/`SetEntityRoutine`/etc.); the
  early-return branch just re-reads the global directly into a scratch
  register (`r0`) and returns it, no local variable involved. Fix:
  restructure so the "already have a value, return early" path returns
  the global directly (`if (X == NULL) { ...; return p; } return X;`)
  instead of assigning it to a shared local up front — this deferred the
  register promotion to only the branch that needs it.

### Multiple writes to nearby fixed addresses need one shared base pointer

- **Frequency**: 3 functions confirmed — `InitHeap` (`src/code_0823071c.c`,
  raw `s32*`), `FUN_082324b0` (`src/vm.c`, struct-typed pointer — see below),
  `FUN_08060e90` (`src/player.c`, `s32*` reused for one field write and the
  call argument together).
- Writing to several nearby fixed/absolute addresses as separate
  `*(s32*)0x02000000 = ...; *(s32*)0x02000004 = ...;` casts makes agbcc
  recompute each address independently (extra `add`/pool-load
  instructions per store). Original reused a single base register with
  immediate offsets (`str r1, [r0, #4]`, `str r1, [r0, #8]`) computed once.
  To get that, declare one pointer local and index through it:
  ```c
  s32* p = (s32*)0x02000000;
  p[0] = 0;
  p[1] = 0;
  p[2] = 0x80020400;
  ```
  rather than three independent absolute-address dereferences.
- The shared base pointer doesn't have to be a raw type — if a fixed
  address's field-write shape (offsets/sizes) matches an *already-known*
  struct from elsewhere in the codebase (found via sibling search, Step
  2), casting to that struct type and writing through named fields works
  identically, even at a different address than that struct's other known
  instance. `FUN_082324b0` writes `0x03000770` in the exact
  `{void* unk; u32 len; Subroutine* arr;}` shape already defined as
  `struct SubroutineTable` (used elsewhere at `gUnk030016e8`, a *different*
  fixed address) — casting `(struct SubroutineTable*)0x03000770` and writing
  `p->unk`/`p->len`/`p->arr` matched first try.

### Narrow NAKED-callee parameter forces truncation at a single call site

- **Frequency**: 3 functions confirmed — `FUN_082402c8`/`FUN_082402e0`
  (`src/sound.c`, callee `sound_08240264`), `FUN_08240428`
  (`src/sound.c`, callee `FUN_082403d0`), `sound_082403b8`
  (`src/sound.c`, callee `FUN_08240360`).
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

## Value materialization

### Signedness & width

- **Frequency**: not yet tracked in this project's own log (this scheme
  just started here), but known from prior experience decompiling another
  GBA game to be one of the most frequently-occurring idioms in agbcc-style
  codebases generally. Expect this project's own count to climb quickly
  once logging catches up — don't read the low number so far as "rare,"
  it's an artifact of when tracking began, not of true frequency. Log the
  function every time this idiom is the deciding signal for a
  parameter/return type, in `/decomp-func` or `/decomp-naked` alike.
- When working with variables of type `u8`, you frequently encounter
  machine code instructions like:
  ```asm
  	lsls rN, rN, #0x18
  	lsrs rN, rN, #0x18
  ```
  to clear the higher bits.

  For `u16` values, the equivalent instructions would be:

  ```asm
  lsls rN, rN, #0x10
  lsrs rN, rN, #0x10
  ```

  For `s8` and `s16` values, the instructions become:

  ```asm
  # s8
  lsls rN, rN, #0x18
  asrs rN, rN, #0x18

  # s16
  lsls rN, rN, #0x10
  asrs rN, rN, #0x10
  ```

  When encountering such shift operations, you can infer that the C code
  likely contains variables or properties with types `u8`, `u16`, `s8`, or
  `s16`.

## The intractable categories — what's actually hard

"Intractable" is a spectrum. The inverse problem is: *find the source whose
agbcc output equals these bytes.* It's hard when the bytes encode a
compiler decision no surface C reliably reproduces.
