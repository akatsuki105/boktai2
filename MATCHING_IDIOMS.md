# agbcc 一致イディオム集

agbcc (gcc 2.95 ベース, ARM7TDMI Thumb-1, `-O2`) でバイト一致させるためのソースイディオムと、
一致しない原因・対処法のカタログ。

ツール一覧は `CLAUDE.md` を参照。差分確認には `tools/diff.sh <src.c> <FN>`、
一致できない関数の自動探索には `tools/decomp-permuter` を使う。

---

## 0. オラクルと permuter

| ツール | 用途 |
|---|---|
| `tools/diff.sh <src.c> <FN>` | objdump で expected vs build の命令差分を表示 |
| `tools/permuter/setup.sh <FN> <src.c>` | permuter 用ディレクトリをセットアップ |
| `tools/permuter.sh <dir> -j4` | 4スレッドで permuter を実行 |
| `tools/refresh-expected.sh <src.c>` | 一致確認後にベースラインを更新 |

`diff.sh` で差分が出ない ＆ make が "up to date" のときは `touch src/foo.c` を先に実行する（偽 OK 問題）。

---

## 1. レジスタ割り当て

### CSE によるアドレス計算の避け方

asm が「scratch で計算してから callee-saved にコピー」という形になる場合
(`adds r0,r4,#0xbc; ldr r1,[r0]; adds r5,r0,#0` など)、
名前付きポインタ変数を作ると agbcc が直接 r5 に置いてしまう。

**修正**: すべての使用箇所で式をインライン展開する（変数にしない）。
```c
// NG: agbcc が直接 r5 を使ってしまう
struct Foo *fp = (struct Foo *)((u8 *)p + 0xbc);

// OK: 毎回インライン展開させると CSE が scratch→callee-saved のコピーを出す
*(struct Foo **)((u8 *)p + 0xbc)
```

### `bool8` vs `s32` の返値型

呼び出し元の asm に `lsls r0, #0x18` があれば bool8 ゼロ拡張を表す → 宣言を `bool8` に。
`cmp r0, #0` だけなら `s32` のまま（bool8 にすると余分な lsls が出る）。

### `bool8` ガード変数を使わない

2つの分岐が同じ `return;` を持ち、asm で共通の末尾に tail-merge される場合、
ガード変数に格納すると `lsls#24; lsrs#24; cmp` が余分に出る。

**修正**: 変数を使わず、各分岐で別々に `if (helper(p)) return;` を書く。
```c
// NG
bool8 g = helper(p);
if (g) return;

// OK (agbcc が同一の return ブロックに tail-merge する)
if (cond1) { if (helper(p)) return; }
else        { if (helper(p)) return; }
```

### 共有ストアの temp は `u8` ではなく `s32`

2分岐がひとつの u8 フィールドへの書き込みに合流する場合:
```c
// NG: lsls#24; lsrs#24 が余分に出て ROM があふれることがある
u8 v = cond ? a : b;
field = v;

// OK: 最後の strb が切り詰める
s32 v = cond ? a : b;
field = v;
```

---

## 2. 制御フロー・スケジューリング

### 関数全体を複製するほうが goto よりよい場合

2つのデスポーン経路が同じ末尾ブロック（フラグクリア→EXIT→SET_ROUTINE）を持ち、
asm でも tail-merge されているとき、`goto merge` + キャリー変数では再現できない。

**修正**: 2ブロックを完全に複製して書く。agbcc が共通末尾を自動で merge する。

### 連続 int 比較の range-fold を防ぐ

`mode[1]` を `{2, 3}` と比較するとき `if(m==2||m==3)` や `switch` を使うと
agbcc が `(m-2)<=1` の range check に fold する。

**修正**: 1文ずつ分けて asm の `cmp` 順に並べる。
```c
if (m == 2) goto skip;
if (m == 3) goto skip;
```

### 符号付き vs 符号なし比較

`x & 3` が signed `s32` → `ble`/`bgt`。unsigned にしたい場合は `(x & 3U) > 1`。
agbcc は最初に書いた if 分岐を fall-through にするので、
out-of-line にしたいブロックを `else` 側に置く。

### ロード順と宣言順

ローカル変数の宣言順がレジスタ割り当てとロード順に影響する。
フィールドのロードを比較より前に行いたい場合はその直前でローカルに束縛する:

```c
s32 val = SampleStruct.val;
if (val > limit)
```

---

## 3. 値の生成

### `--p->work[N] == 0` の余分な lsl

```c
// NG: cmp 前に redundant lsls が出る
if (--p->work[N] == 0)

// OK: u32 temp で保持すると lsls が消える
u32 w = p->work[N] - 1;
p->work[N] = w;
if (w == 0)
```

---

## 4. 一致できない関数への対処（dual-form）

レジスタ割り当てやスケジューリングの都合で C コードでは再現できない場合は
NAKED スタブに戻すのではなく **dual-form** にする:

```c
NON_MATCH void FUN_xxxxxxxx(struct Foo *p) {
#if MODERN
  /* 可読性の高い正しい C 実装 */
#else
  INCCODE("asm/wip/FUN_xxxxxxxx.inc");  /* バイト一致する元アセンブリ */
#endif
}
```

条件:
- INCCODE パスは `diff.sh` で一致すること
- MODERN=1 でコンパイルエラーが出ないこと
- `asm/wip/FUN_xxxxxxxx.inc` に元の `.inc` を移動して作成すること

permuter でスコア 0 が出なかった関数はこの形にする。
NAKED スタブのままにするより可読性と将来の参考価値が高い。

---

## 5. decomp-permuter の使い方

レジスタ割り当てで近いが一致しない関数に有効。

```bash
# 1. ワークディレクトリをセットアップ
tools/permuter/setup.sh FUN_08242a38 src/weapon.c

# 2. バックグラウンドで実行（4スレッド）
tools/permuter.sh /tmp/perm_FUN_08242a38 -j4 &
```

スコア 0 が出たら `nonmatchings/FUN_08242a38/` 以下の最良 `output-*/source.c` を採用する。

**注意**: 関数が C 実装済みであること（NAKED ではなく WIP や NON_MATCH であること）が必要。
setup.sh が自動的に `base.c` を生成する（WIP/NON_MATCH の MODERN 側から、
またはフォールバックとして m2c から）。

`permuter_settings.toml` がプロジェクトルートにあるので、
`decomp-permuter/import.py` でも自動的に agbcc 設定が使われる。

---

## 6. asm を分割する（split_inc_multi.py）

1つの `.inc` ファイルに複数の関数が含まれている場合、特定の関数だけを C に置き換えるには
まず `.inc` を分割する:

```bash
# asm/foo.inc に FUN_A と FUN_B が含まれている場合
tools/split_inc_multi.py asm/foo.inc FUN_A FUN_B
# → asm/foo_p1.inc (FUN_A の前), asm/foo_p2.inc (FUN_A), asm/foo_p3.inc (FUN_B 以降)
```

`.c` ファイル側:
```c
// 変更前
NAKED void wholeFile(void) { INCCODE("asm/foo.inc"); }

// 変更後
NAKED void FUN_Before(void) { INCCODE("asm/foo_p1.inc"); }
void FUN_A(struct X *p) { /* C 実装 */ }
NAKED void FUN_After(void) { INCCODE("asm/foo_p3.inc"); }
```

`_p1.inc` はヘッダ（`.include "asm/macros.inc"`, `.syntax unified`, `.text`）を含むが、
`_p2.inc` 以降は `split_inc_multi.py` がヘッダを自動補完する。
