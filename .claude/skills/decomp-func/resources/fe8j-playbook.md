# The fe8j playbook — everything transferable from the 100% JP decomp

Source: laqieer/fireemblem8j (100.00% matching C, 8692/8692 functions, the
only completed Japanese GBA agbcc decomp) and its docs
(`docs/agbcc-matching-playbook.md`, `docs/agbcc_codegen_levers.md`,
`docs/agbcc_internals.md`, `docs/decisions.md`). Deep-dived 2026-07-23; all
claims verified against clones. This corrects and supersedes the fe8j lines
in extracted-practices.md §1/§7b.

## 0. Corrections to our earlier survey notes

- There is **no `fe8j` branch of laqieer/agbcc** — the compiler mod is
  `scripts/agbcc_jp_promote.patch` in the game repo, applied onto pret/agbcc
  pinned `da598c1` at toolchain build time.
- `-mjp-promote` is applied to **180 TUs** (not 8) — the repo is
  one-function-per-TU, so flagging is function-granular and purely
  empirical (compile both ways, byte-diff, gate on ROM sha1).
- `-mjp-regorder` and `-mjp-nocrossjump` are **shipped but unused — zero
  yield** (their own decisions log D277: 5 worse / 11 no-change / 0
  improved; "DO NOT USE"). Don't chase prologue high-reg push order or
  cross-jump knobs.

## 1. What -mjp-promote actually is

Two coupled behaviors, default-off (= byte-identical to stock):

1. `PROMOTE_MODE` signedness preservation — stock agbcc forces sub-word
   ints to be held **zero-extended** in registers; the flag holds s8/s16
   **sign-extended** (`asrs` once at entry, reused).
2. `PROMOTE_FUNCTION_ARGS` — callee extends incoming narrow params at
   entry, in declaration order (stock thumb config had this stripped).

Their attribution discipline: "some TUs were built under a
signedness-preserving promotion profile", NOT "JP used this everywhere" —
most JP functions match stock. decomp.me ships this compiler as
`agbcc-fe8j`, so the hypothesis can be A/B'd on any scratch for free.

## 2. The sub-word signedness checklist

Your function probably has a promote-shaped diff if the byte diff shows:

1. **Entry-extension mismatch** — target does ONE `asrs #16` (s16) or
   `lsls #24; asrs #24` (s8) near entry and reuses it; ours re-extends
   before each signed use (+4 bytes per site), or the pair sits at use
   sites instead of entry.
2. **`ldrsh/ldrsb` vs `ldrh/ldrb`+extend** for the same operand.
3. **Shifted-domain counters** — target keeps an s8/s16 counter
   pre-shifted (`<<16`/`<<24`): adds of `0x10000`/`0x01000000`-class
   constants, compares in the shifted domain.
4. **asr vs lsr tails** — same shift counts, wrong signedness ("JP defers
   s16 sign-extension vs eager US").
5. **Signed vs unsigned branches** (`bge/blt` where we emit `bcs/bhi`) —
   the held representation's signedness leaked into condition selection.
6. **Arg-extension order at entry** — target extends ≥2 narrow params in
   declaration order before any body code.
7. **Un-merged duplicate switch arms** — sign-extended values in each arm
   stopped a tail-merge our build performs.

**Stock-compiler levers per signature** (byte-proven in fe8j; no flag
needed): (1)(2) `int v = s8param;` widen at entry, or `(s16)`/`(u32)` cast
at the exact shift/use site — note u8/u16 promote to *signed* int, so
`someU8 >> n` is ASR unless re-cast; (3) hold the counter `<<16`, add
`0xFFFF0000`, re-narrow explicitly; (4) cast the shifted operand at the
site; (5) fix the local's type, not the compare; (6) copy narrow params to
int locals in declaration order; (7) make tails textually non-identical
(per-arm temp) or identical (shared goto) — cross-jumping is purely
rtx-identity-driven. If an explicit extend-pair keeps collapsing into
`ldrsh`, `volatile` on the pointer/field blocks the fold.

## 3. The P-lever catalog (escalation order, cleanest first)

- **signedness cast at the shift site** — `lsr` vs `asr` is chosen only by
  the shifted operand's C signedness; same rule drives ldrb/ldrsb.
- **int-local widen** (highest yield): `int v = s8param;`.
- **P5 shift-domain extraction**: `((u32)x << 26) >> 26` instead of
  `& 0x3F`; `flag <<= 30; if (flag >= 0)` instead of `& 2`.
- **P6 shifted-domain loop counter** (see checklist 3).
- **P7 return/param widen**: `s16 f()` → `unsigned int f()` drops the
  trailing sign-extend; `volatile short g()` blocks return-truncation CSE.
- **P8 source shape**: hoist next-iteration pointers/IVs to temps before
  an inner loop.
- **P9 zero-instruction BB separator**: `do { } while (0);` between two
  statements flips independent callee-save copy emission order with zero
  code bytes — cracked a function after ~40 source variants, an 11-flag
  matrix, and a 130k-iteration permuter plateau.
- **P10** `&x` forces a stack home. **P11** materialize a repeated cast
  once. **P12** re-read the just-stored `dst->field` instead of the source
  expression. **P13** route reads through one long-lived pointer local.
  **P14** `x = a; asm("" : "+r"(x)); x += b;` beats `a + b` when agbcc
  canonicalizes the DAG.
- **P1/P2/P3 fences** (flagged non-idiomatic, match-forcing):
  `asm("" : "=r"(x) : "0"(x))` register fence; `asm("" : "+m"(a))` forces
  a spill where the target spills.
- **P23–P27 endgame**: stacked narrow arg + delayed re-narrow; caller-side
  widening + `index[base]` vs `base[index]` to flip a commutative add;
  **removing** pin swarms in favor of natural aggregate shapes (their last
  three matches were *cleaner* C than the failed pinned versions); libcall
  retarget via byte-neutral `asm(".set __divsi3, DivArm")` only with
  disassembly proof.
- Also: branch-polarity swap `if ((cond)==0)`; `static` vs extern linkage
  changes the reader's codegen; `volatile` as anti-fold.

## 4. Compiler doctrine (source-verified, straight to our pain points)

- **Args evaluate/load strictly left-to-right** — not source-flippable.
- **Register allocation**: no REG_ALLOC_ORDER; lowest-free ascending;
  priority = `floor_log2(n_refs)*n_refs*size/live_length`, ties by pseudo
  creation order ≈ declaration order. Levers: reference count, live-range
  length, copy-preference (`int t = arg;`), declaration order.
- **Jump threading** (our dead-compare class): `thread_jumps` runs twice at
  -O1+, keyed on `comparison_dominates_p` over rtx-identical operands.
  **Not flag-controllable — the only lever is CFG shape.** Replicate
  `&&`/`||` nesting exactly; fix inverted-branch near-misses by flipping
  `if(cond)`↔`if(!cond)` + swapping arms. (Independently confirms our
  unused_080e14d4 analysis and today's negative flag A/B.)
- **No Thumb scheduler exists** — every "scheduling" diff is
  allocator/CSE/statement-order, hence source-steerable in principle.
- Switch → table iff count≥5 AND span≤10×count AND non-const index;
  div-by-constant is always a libcall; signed pow2 division emits
  `cmp;bge;add;asr` at -O2 except N=2 branchless.
- **The register-coloring floor is upstream of the allocator** (flow
  ref-counts/live ranges) — allocator tie-break patches were rejected as
  no-ops (D290b). Matches our RTL-dump conclusions on readKeyInput-class
  ties.

## 5. Per-TU flag axis — legitimate and precedented

fe8j ships per-TU: `old_agbcc` (28 m4a TUs + newlib fflush), `-O1` (SRAM),
`-Os` (2 JP link-arena fns: "only -Os yields the byte-match"),
`-fno-gcse` (table-base GCSE hoist evicted a live pointer),
`-fno-strength-reduce` (up-counting inner loop preserved), non-interwork
(fflush: `pop {pc}` epilogue), `-mjp-promote` (180). **Sweep
{-O1,-O2,-Os} × {-fno-gcse, -fno-strength-reduce} per stubborn function
before source surgery** — all supported by our stock binary.

## 6. Process patterns worth copying wholesale

- **Decisions log with negative results** — their D-numbered log
  (D276/D277/D284/D290b…) prevents re-testing dead knobs. Ours: keep
  retractions/negative A/Bs in backlog-truth.md and this folder.
- **Shift-JIS pipeline**: `cpp | iconv -f UTF-8 -t CP932 | cc1` — sources
  stay UTF-8, literals byte-match CP932. If we ever decompile boktai2's text
  handling with inline JP literals, this is the recipe.
- **decomp.me integration files**: registry.tsv (fn→scratch),
  rejected_matches.tsv (score-0-but-wrong-ABI rejects — verify every
  community match against the real ABI and the linked ROM; they caught a
  scratch calling a 5-arg function with 4 args).
- **Equivalence-proving before accepting fakematch-looking harvests**:
  CBMC bounded proofs + differential testing.
- **Meta**: a permuter plateau is evidence about the mutation vocabulary,
  not a compiler ceiling; the last-mile matches got cleaner, not hackier.
