# CLAUDE.md

このファイルは、Claude Code がこのリポジトリで作業する際のガイドラインです。
本プロジェクトは GBAソフト『続・ボクらの太陽 太陽少年ジャンゴ』の**一致デコンパイル(matching decompile)**を目的としています。

---

## プロジェクト概要

- **対象タイトル**: 続・ボクらの太陽 太陽少年ジャンゴ(Boktai 2: Solar Boy Django の日本語版/続編にあたるタイトル, ID: `AGB-U32J-1`)
- **プラットフォーム**: Game Boy Advance(ARM7TDMI, ARMv4T)
- **目的**: オリジナル ROM とビルド後の ROM が**バイト単位で完全一致**するデコンパイル成果物を作ること

一致デコンパイルの大原則:
1. **常に元 ROM とのバイナリ一致を最優先する。** 可読性やモダンな書き方を優先して一致を崩さない。
2. コンパイラの癖(古い ARM 向け mwcc / agbcc 等)を理解し、意図的にそれに合わせたコードを書く。
3. 「動くコード」ではなく「同じ機械語を吐くコード」を書く。

---

## AI 協働ワークフロー

### ツール一覧

| ツール | 用途 |
|---|---|
| `tools/diff.sh` | ビルド後に expected vs build の差分を表示 |
| `tools/context.sh` | Claude へ渡すコンテキストを生成（m2c変換含む） |
| `tools/permuter/compile.sh` | decomp-permuter 用 agbcc ラッパー |
| `tools/refresh-expected.sh` | sha1 一致後にベースラインを更新 |

### 初回セットアップ

```bash
# 1. m2c をクローン（初回のみ）
# PyPI の m2c とは別物。tools/ 以下に clone して使う
git clone https://github.com/matt-kempster/m2c.git tools/m2c

# 2. decomp-permuter をクローン（初回のみ）
cd tools && git clone https://github.com/simonlindholm/decomp-permuter && cd ..

# 3. ベースラインを確立（sha1 一致ビルドが存在する状態で実行）
./tools/refresh-expected.sh
```

### 関数1つのデコンパイル手順

```
① tools/context.sh <FUNCTION_NAME>  の出力を Claude に貼り付ける
   （ターゲットアセンブリ + m2c 初期変換 + 現在の差分 が出力される）

② Claude が C コードを提案する

③ src/*.c を編集：NAKED スタブ / WIP の #else INCCODE ブロックを
   Claude の C コードに置き換える（WIP/#if MODERN ラッパーも外す）

   ※ WIP は MODERN=0 で __attribute__((naked)) になるため、
     C コードをテストするにはスタブを完全に外す必要がある

④ tools/diff.sh <src.c> <FUNCTION_NAME>  を実行して差分を確認
   → "OK: 一致" なら ⑦ へ
   → 差分があれば Claude に貼り付ける

⑤ Claude が差分を見て修正案を提示する

⑥ ③ に戻る（一致するまでループ）
   [並行] decomp-permuter でバックグラウンド探索もできる（後述）

⑦ make && sha1sum -c boktai2.sha1  で ROM 全体の一致を確認
   ./tools/refresh-expected.sh <src.c>  でベースラインを更新
```

### decomp-permuter の使い方

C コードが近いが一致しない場合、permuter がランダム変種を自動探索する。

```bash
# 1. 関数ごとのワーク用ディレクトリをセットアップ
tools/permuter/setup.sh FUN_08242b88 src/weapon.c

# 2. バックグラウンドで起動（-j4 で 4 スレッド並列）
tools/permuter.sh /tmp/perm_FUN_08242b88 -j4 &
```

permuter が完全一致（スコア 0）を見つけたらその C コードを採用する。

---

## agbcc の癖（一致させるために重要）

agbcc は gcc 2.95 ベースの古い ARM コンパイラ。以下の癖がある：

- **ゼロ初期化**: `a = 0` は `movs rN, #0` で表現される
- **加算ゼロ**: 値のコピーに `adds rN, rM, #0` を使う（`mov` ではない）
- **ループカウンタ**: `for` ループのカウンタは最後に `adds rN, #1` でインクリメント
- **bool 返値**: `TRUE`/`FALSE` を返す関数は r0 に 1/0 をセットして return
- **スタック変数**: ローカル変数は `sub sp, #N` で確保。引数が多い場合は sp 経由
- **`-Wimplicit` 必須**: 暗黙的な関数宣言はエラーになる。使う関数は必ず宣言すること
- **`NAKED` 関数**: `__attribute__((naked))` 相当。関数プロローグ/エピローグが生成されない

### コードスタブの形式

| マクロ | 意味 |
|---|---|
| `NAKED void FN(void) { INCCODE("asm/wip/FN.inc"); }` | まだアセンブリのまま (TODO) |
| `WIP void FN(...) { ... }` | C 実装済みだが一致未確認 |
| `NON_MATCH void FN(...) { ... }` | 一致しないと分かっている |
| ※マクロなし | 一致確認済み |

