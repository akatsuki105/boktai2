# Matching tooling: oracles & the permuter

The tooling and strategy for verifying a match and searching for one when a
straight decompilation resists. For the *source-level idioms* that explain
*why* a particular C shape matches, see `agbcc-quirks.md` (compiler
behavior) and `c-programmer-habits.md` (original developer style) next to
this file.

## 0. The gate, the working diff, and the rest (use these, don't eyeball)

| Tool | What it is | Use |
| ---- | ---------- | --- |
| `make compare` | full-image SHA-1 of the rebuilt ROM | **the only gate.** Nothing else proves a match |
| `.claude/skills/decomp-func/scripts/streamdiff.py` | canonicalized instruction diff, built object vs the original `.inc` | **the working diff** — `decomp-func` Step 6a, every NON-MATCH iteration |
| `tools/diff.sh <Func>` | objdiff (Rust disassembler) vs `expected/` snapshot | % match + side-by-side, for when you want to *look at* both listings rather than read a canonicalized diff |
| `tools/diff2.sh <Func>` | devkitARM `objdump --disassemble=<Func>` vs `expected/`, reloc-folded | independent second opinion on the above — two disassemblers agreeing is a strong signal; disagreement = tooling bug |
| `tools/refresh-expected.sh <file>` | snapshot the matching `.o` into `expected/` | run after every matching build |
| decomp-permuter | randomized source mutation, or `--debug` to just score one candidate | numeric second opinion when the streamdiff is inconclusive (§1.1); the hammer for register-allocation/scheduling mismatches as a background search (§1.2) |

A residual whose **only** diff is a tail `.word <abs>` vs `.word .rodata` is a real match — those are table relocations resolved at link time.

## 1. The decomp-permuter recipe (the hammer for register-allocation/scheduling mismatches)

Automatically permutes C files to better match a target binary. It also doubles
as a quick scorer for whatever C is currently sitting in `src/*.c` — the setup
script (re)builds `base.c` from the live source each time, so this works
equally well for a candidate Claude just wrote as for one the permuter itself
found.

### 1.1 Quick score check (no search)

Use this when `streamdiff.py` alone leaves you unsure what kind of difference
you are looking at — `decomp-func`'s SKILL.md Step 6b lists the cases. It is
two commands and two compiles, so it is not worth running on an iteration where
the streamdiff already names the difference:

```bash
# 1. (re)setup the per-function work directory from the CURRENT src/*.c
tools/permuter/setup.sh FUN_08242b88 src/weapon.c

# 2. compile + score the candidate only — no random search
# run from tmp/ so decomp-permuter's hardcoded ./debug_source.c dump
# lands there instead of the repo root
(cd tmp && "$DECOMP_PERMUTER/permuter.py" /tmp/perm_FUN_08242b88 --debug)
```

Score 0 means the permuter's own instruction-stream metric considers it a
match (not the ROM gate — still confirm with `make compare`). Otherwise, the
printed penalty breakdown (stack / branch / regalloc / reordering /
insertion / deletion) says what kind of mismatch dominates — e.g. a large
reordering penalty points at statement/declaration order, a pure regalloc
penalty points at which locals get which registers.

### 1.2 Background random search

```bash
# 1. setup a per-function work directory (this example is for FUN_08242b88 in src/weapon.c)
tools/permuter/setup.sh FUN_08242b88 src/weapon.c

# 2. run permuter in the background — cap at -j2 (higher pins all CPU cores);
#    --stop-on-zero exits on its own the moment it finds a match
tools/permuter.sh /tmp/perm_FUN_08242b88 -j2 --stop-on-zero &
```

**Don't leave it running unattended waiting for score 0.** `permuter.py`
has no time-based timeout flag, so even with `--stop-on-zero` still cap it
externally: let it run for about 1 minute, then stop it
(`pkill -f "permuter.py.*perm_FUN_08242b88"` or kill the background job).
If it found score 0, adopt that C code directly. Otherwise, look at its
best-scoring candidate under
`nonmatchings/<dir>/output-<score>-*/source.c` in the perm dir — it's
feedback for the next manual iteration (SKILL.md Step 7), not a
replacement for one. Read what it changed and judge it before adopting
anything:

- **Trustworthy**: statement/declaration reordering, hoisting or
  un-hoisting a loop-invariant expression, splitting/merging an
  assignment — these are genuine C-source-level moves a human could have
  written, and they explain *why* the register allocator made a
  different choice. Adopt these.
- **Not trustworthy**: a score improvement that comes from an unnatural
  type on an intermediate value (e.g. stuffing a `long long` through a
  plain `s32 + 1`) or other nonsensical-looking mutation. This is
  register-allocation noise the randomizer stumbled into, not a
  structural insight — don't adopt it just because the score dropped.
  Treat it as a dead end for that candidate, not as feedback.

## streamdiff が「一致」でも ROM が壊れることがある

`Entity080ac374_Create` は streamdiff が 39 対 39 で "stream identical" と言ったのに、`make compare` が
FAILED になり、ROM は 1000 万バイト以上食い違った。原因は**関数の長さ**で、余分に確保した高位レジスタ
(`push {r7}` が `push {r6, r7}` になり、エピローグも 2 命令増える) のぶん後続のコードが全部ずれていた。
streamdiff は命令列を正規化して比べるので、プロローグ/エピローグのレジスタ本数の違いを差分として
見せないことがある。

- **必ず `make compare` を通すこと。** streamdiff の "identical" は途中経過でしかない。
- 大量のバイトが食い違う (ROM の頭のほうから) ときは、関数の**サイズ**が変わっていて後続が
  ずれていると考える。中身の間違いではない。
- 原因が高位レジスタの本数なら、**引数の型を狭めすぎていないか**を疑う。`u16 param` は入口で
  `lsls`/`lsrs` に展開されてレジスタを 1 本余計に生かす。目標が入口で narrowing していなければ
  `u32` が正しい (`Entity080abd14_Create` / `Entity080ac374_Create` の両方でこれだった)。
