# .bokc の文法

`data/scripts/scripts.bokc` に入っているスクリプト言語の文法をまとめる。
言語そのものに名前は無いので、ここでは拡張子にあわせて .bokc と呼ぶ。

.bokc は ROM のバイトコードを人間が読める形に書き直したものであって、
オリジナルのソースコードではない。表記は `tools/bokcc` が決めているので、
**バイトコードに戻せる範囲でしか表記を選べない**。
読みやすさのために情報を落とすことはできない。
`.bokc` の見た目はなるべくC言語に寄せるようにしている。

このバイトコードは src/vm.c や src/vm_xxxx.c に実装されている実機側のインタプリタが解釈するものである。

## 関係するコード

| 場所 | 役割 |
| --- | --- |
| `tools/bokcc/instruction_reader.ts` | バイト列 → 命令木 |
| `tools/bokcc/instruction.ts` | 命令木 → テキスト (**表記を決めているのはここ**) |
| `tools/bokcc/parser.ts` | テキスト → 命令木 |
| `tools/bokcc/compiler.ts` | 命令木 → バイト列 |
| `tools/bokcc/main.ts` | スクリプト1本を対象にした CLI |
| `tools/dumper/bokcc.ts` | 全スクリプトを一括で吐いて `scripts.bokc` を作る |
| `src/vm.c` | 実機側のインタプリタ。意味の一次情報源 |

VM 側の opcode 定数は `include/vm.h` に `OP_*` / `CLAUSE_*` として定義してある。

## 用語

### Script

バイトコードの実行単位。1本がブロック (`0x80`) 1つに対応する。
ID で引くもので、ID は `ScriptDirectory.script_entries` の添字 + 1 (ROM には 11539 本ある)。
`scripts.bokc` の `Script_XXXX` の番号がこの ID である。

`.bokc` からは `ScriptCall(0x0003)` で呼ぶ。引数は最大16個渡せて、
呼ばれた側は `p0` `p1` ... で読む。`return` で値を返せる。
戻り値は呼び出した側の `result` に入る (`result` は直前の文の値を指すので、
式の結果でも上書きされる)。

### Subroutine

スクリプトから呼べるエンジン側の関数で、VM にとってのシステムコールに当たる。
16bit の ID と関数ポインタの組 (`Subroutine`) を ID 順に並べた
`gSubroutineTable` (`data/subroutine.inc`, 643件) を二分探索して引く。

`.bokc` からは `SubroutineCall` / `EntityCreate` の第1引数がこの ID である。
引数の渡し方は決まっていない。呼ばれた側が `VM_GetValue` や `VM_SeekToNamedArg` で
スクリプトから自分で読むので、個数も形も関数ごとに違う。

ややこしいことに、制御命令 (`0x60`) のハンドラも同じ `Subroutine` 型で登録されている。
こちらは `gCtrlHandlers` (`src/vm_ctrl1.c` の6件 + `src/vm_ctrl2.c` の8件) を
線形に探すもので、`gSubroutineTable` とは別の ID 空間である。
`if` の `0x0D86` や `SubroutineCall` の `0xB745` はこちら側の ID。

### Label

`0x50` の命令で、1バイトの ASCII 文字 + 本体 (値は0個以上) という形をしている。
名前の付いた入れ物でしかなく、用途は2つある。

**名前付き引数** — `.n = 16` や `.m = [0, 1, 2]` のように書く。
位置が決まっているわけではなく、呼ばれた側が `VM_SeekToNamedArg('n')` や
`VM_GetNamedArgValue('n', fallback)` で自分で探して読む。
そのため同じ文字でも意味は呼び出し先ごとに違う。ラベルのほとんどはこちらである。

**節のラベル** — `if` / `switch` の中に現れる `else` (`'e'`) / `else if` (`'i'`) /
`case` (`'c'`) / `default` (`'d'`) の4つ。仕組みは同じだが、こちらは
`if` / `switch` のハンドラが固定の文字を探すので意味が確定している。
`include/vm.h` の `CLAUSE_*` がこれで、`.bokc` では C と同じ綴りで出している。

boktaihacking の wiki はこの命令を keyword と呼んでいる。
`if` / `else` を表すのに使われているのを見て予約語と解釈したのだと思われるが、
文字は固定ではなく意味も呼び出し先ごとに違うので、ここではラベルと呼ぶ。

## バイトコードの基本形

命令は1バイトの opcode で始まり、**上位ニブルが命令の種別**を表す。

| 上位ニブル | 命令 | .bokc での姿 |
| --- | --- | --- |
| `0x00` | 定数リテラル・文字列・終端 | `123` `"abc"` `}` |
| `0x10` | メモリ参照 | `*((s16 *)(stat + 0x250))` |
| `0x20` | 添字つきメモリ参照 | `((s16 *)(stat + 0x18))[4, 0]` |
| `0x30` | 式 | `a + b` |
| `0x40` | 引数参照 | `result` `p0` |
| `0x50` | ラベル | `.p = 1` `case 3:` `else` |
| `0x60` | 制御命令 | `if` `switch` `return` `SubroutineCall(...)` |
| `0x70` | スクリプト呼び出し | `ScriptCall(0x0003)` |
| `0x80` | ブロック | `{ ... }` |
| `0x90` | 変数参照 | `v0` |
| `0xA0` `0xB0` | 演算子 | `+` `==` `=` |
| `0xC0`-`0xFF` | 小さい整数リテラル (値が opcode に埋まっている) | `0` `62` |

下位ニブルの意味は種別によって2通りある。

- 定数リテラルとメモリ参照では**型タグ**。
- `0x30` / `0x50` / `0x60` / `0x70` / `0x80` では、続く中身の**バイト数**。
  `0xD` / `0xE` / `0xF` は長さが入りきらない場合の拡張で、それぞれ後ろに
  1 / 2 / 3 バイトのリトルエンディアンの長さが続く (`VM_ReadContainerLength`)。
  中身の長さが分かるので、VM は中身を読まずに次の命令へ飛べる。


## 制御命令 (0x60)

2バイトの ID でハンドラを引いて呼ぶ命令。
`if` や `return` のような構文も、エンジン関数の呼び出しも、すべてこの形で表される。
ハンドラは `gCtrlHandlers` に14件登録されていて
(`src/vm_ctrl1.c` に6件、`src/vm_ctrl2.c` に8件)、`VM_RunControl` が ID で引いて呼ぶ。

バイト列はこうなっている。

| 長さ | 内容 |
| --- | --- |
| 1バイト | opcode `0x60 \| 中身のバイト数` |
| 2バイト | ID (リトルエンディアン) |
| 1-2バイト | 最初のラベル命令、無ければ終端までのバイト数 |
| 可変 | オペランド、続いてラベル |
| 1バイト | `0x00` (終端) |

3番目の欄は `0x60` だけが持つ (`VM_ReadCtrlLabelOffset`)。
上位ビットが立っていると2バイト形式で、残り15bitが距離になる。
VM はこの距離でラベルの始まる位置を知り、そこを `VM_SeekToNamedArg` 用のスタックに
積んでからハンドラを呼ぶ。これでハンドラは自分のラベルだけを辿れる。
bokcc はコンテナ長から同じ情報を導けるので、この欄はテキストに出さずコンパイル時に計算し直す。

ハンドラの戻り値は「スクリプトを終わらせるか」を表す。
`VM_ExecBlock` は 1 が返るとブロックの実行を打ち切る。
`VM_Ctrl_If` / `VM_Ctrl_Switch` は選んだ節の `VM_ExecBlock` の結果をそのまま返すので、
ネストの内側の `return` はここを伝わって外まで抜ける。

### 登録されている制御命令

| ID | ハンドラ | `.bokc` での姿 | 出現 | 内容 |
| --- | --- | --- | --- | --- |
| `0x0D86` | `VM_Ctrl_If` | `if` / `else if` / `else` | 4044 | 条件が真になった最初の分岐のブロックを実行する |
| `0x4A6F` | `VM_Ctrl_Switch` | `switch` | 346 | 値が一致した `case`、無ければ `default` の節を実行する |
| `0xCD3A` | `VM_Ctrl_Return` | `return` | 648 | `result` に値を入れてスクリプトを終える |
| `0x121F` | `VM_Ctrl_CallScriptIndirect` | `ScriptCall(式, ...)` | 37 | 呼び先を式で指定するスクリプト呼び出し |
| `0xB745` | `VM_Ctrl_CallSubroutine` | `SubroutineCall(ID, ...)` | 7057 | サブルーチンを呼ぶ。戻り値は `result` に入る |
| `0x9906` | `VM_Ctrl_CreateEntity` | `EntityCreate(ID, 値)` | 2130 | 値1つを C の実引数として渡し Entity を生成する。戻り値は捨てる |
| `0xC8BB` | `VM_Ctrl_LoadMap` | `LoadMap(ID, ...)` | 96 | マップ初期化スクリプトIDを設定してマップ遷移を要求する |
| `0xD4CB` | `VM_Ctrl_SetZoneCallback` | `SetZoneCallback(...)` | 208 | Zone に重なったときのコールバックを登録する |
| `0xB96E` | `VM_Ctrl_DebugPrint` | `DebugPrint(...)` | 107 | 文字列を Shift-JIS に変換する。出力先は残っていない |
| `0x22FF` | `VM_Ctrl_22FF` | `Ctrl_22FF(...)` | 115 | ID と可変個の u16 を1件のレコードとして登録する |
| `0xE43C` | `VM_Ctrl_E43C` | `Ctrl_E43C(...)` | 17 | `.s` / `.r` を見て `u32_03004798` にフラグを立てる |
| `0x64C0` | `VM_Ctrl_Unused_64C0` | `Ctrl_64C0(...)` | 0 | 第1オペランドを `result` に入れるだけ |
| `0x0BB3` | `VM_Ctrl_Unused_0BB3` | `Ctrl_0BB3(...)` | 0 | 何もしない |
| `0xC091` | `VM_Ctrl_Unused_C091` | `Ctrl_C091(...)` | 0 | 引数をそのまま返すだけ |

出現は `scripts.bokc` をテキスト検索した件数。
名前を付けていない ID は `Ctrl_XXXX` として出す。
`scripts.bokc` に出てくるのはこの表の9種類だけで、登録されていない ID は現れない。

### 構文に見える制御命令

`if` / `switch` / `return` が C の構文に見えるのは bokcc がそう描いているからで、
バイトコード上は `SubroutineCall` と同じ制御命令である。
`if` のオペランドは条件とブロックの組で、2つめ以降の分岐は
`else if` (`'i'`) / `else` (`'e'`) のラベルとして後ろに並ぶ。

`switch` は C と違って**フォールスルーしない**。
`break` に当たる命令は無く、一致した節を1つ実行したら終わる。

### サブルーチン呼び出しの2種類

`0xB745` は引数なしで `fn()` を呼ぶ。
2つめ以降のオペランドやラベルは、呼ばれたサブルーチンが
`VM_GetValue` / `VM_SeekToNamedArg` で自分でスクリプトから読む。
`0x9906` は2つめのオペランドを u16 にして第1引数として渡し (`fn(値, NULL)`)、
戻り値を `result` に入れない。

### ScriptCall の2つの形

呼び先が定数なら `0x70`、式なら `0x121F` になる。
どちらも `ScriptCall(...)` と書くが、前者は呼び先を必ず16進リテラルで書き、
後者の第1オペランドは16進リテラルにならないので、テキストから区別できる。
