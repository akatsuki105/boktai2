# Ghidra + pyghidra-mcp — m2c の補助デコンパイラ

m2c が苦手とする PC-relative リテラルや複雑な制御フローを持つ関数に対して、
Ghidra の疑似 C を second-opinion として使うための設定メモ。

## 導入済み環境

- **Ghidra** — `GHIDRA_INSTALL_DIR` を `~/.zshrc` に設定済み
- **JDK** — `JAVA_HOME` を `~/.zshrc` に設定済み
- **pyghidra 3.1.0 + pyghidra-mcp 0.2.3** — `tools/.venv-ghidra/` に venv として導入

```bash
# 初回セットアップ（venv 再構築が必要な場合）
python3 -m venv tools/.venv-ghidra
tools/.venv-ghidra/bin/pip install pyghidra-mcp
```

## MCP サーバーとして使う（推奨）

`.mcp.json` がプロジェクトルートに置いてあり、`ghidra` という名前の MCP サーバーを
登録している。Claude Code を再起動すると自動で起動する。

手動解析済みの Ghidra プロジェクトをそのまま開くため、
**関数名・型情報・コメントが反映された状態**でデコンパイルできる。
プロジェクトキャッシュが既に存在するので起動は速い。

起動後は Claude Code から以下のツールが使える（MCP 経由）:
- `decompile_function` — 関数名またはアドレスで疑似 C を取得
- `disassemble` — アドレス範囲の逆アセンブル
- `search_symbols_by_name` — シンボル検索
- `list_xrefs` — クロスリファレンス

## スタンドアロンスクリプトとして使う

MCP サーバーを起動せずに 1 関数だけデコンパイルしたい場合:

```bash
GHIDRA_INSTALL_DIR=$GHIDRA_INSTALL_DIR \
JAVA_HOME=$JAVA_HOME \
GHIDRA_PROJECT_DIR=/path/to/ghidra/Projects \
  tools/.venv-ghidra/bin/python tools/ghidra_decompile.py 0x08XXXXXX
```

既存の Ghidra プロジェクト（`$GHIDRA_PROJECT_DIR/$GHIDRA_PROJECT_NAME`）を直接開くため、
手動で付けた関数名やコメントがそのまま反映される。再解析は行わない。

## 環境変数

| 変数 | 意味 | デフォルト |
|---|---|---|
| `GHIDRA_INSTALL_DIR` | Ghidra のインストールディレクトリ | (必須) |
| `JAVA_HOME` | JDK のインストールディレクトリ | (必須) |
| `GHIDRA_PROJECT_DIR` | Ghidra プロジェクトの親ディレクトリ | (必須) |
| `GHIDRA_PROJECT_NAME` | プロジェクト名（`.gpr` の拡張子なし）| `Boktai` |
| `GHIDRA_PROGRAM_PATH` | プロジェクト内のプログラムパス | `/Boktai2B.gba` |

## Ghidra プロジェクト設定

| 項目 | 値 |
|---|---|
| 言語 | `ARM:LE:32:v4t` (設定済み) |
| イメージベース | `0x08000000` (設定済み) |

## 使い所と限界

| 用途 | 向き |
|---|---|
| PC-relative リテラル（m2c が `M2C_ERROR` を出す）| ◎ |
| 複雑な制御フロー（ループカウンタ、オブジェクト配列）| ○ |
| レジスタ割り当ての一致 | ✕（agbcc の癖には対応不可）|

m2c と Ghidra の疑似 C が同じ構造を示す場合、その reconstructions は信頼度が高い。
その後 `tools/diff.sh` で一致を確認し、`decomp-permuter` で細部を調整する。
