# agbcc の呼び出し規約 (Thumb)

このROMのコードを読むときの前提知識のメモ。

**3行まとめ**

- agbcc は **APCS-32** ベース。AAPCS ではない
- 引数は r0-r3 → スタック、**ワード単位で詰めるだけ**(アラインメントの詰め物なし)
- フレームポインタは使わない。フレームの境界は「その時点の SP」でしか表現されない

---

## 用語の整理

混乱しやすいので先に。**時系列の後継関係**と**包含関係**という2つの軸が混ざっている。

### 時系列: APCS → ATPCS → AAPCS

いずれも関数呼び出し規約を定める文書で、後のものが前を置き換えた。

| | 時期 | 内容 |
|---|---|---|
| APCS | 1990年代前半 | ARM Procedure Call Standard。最初の呼び出し規約 |
| ATPCS | 1990年代後半 | ARM-**Thumb** PCS。APCS に Thumb 対応と ARM/Thumb 相互呼び出しを追加 |
| AAPCS | 2003年〜 | Procedure Call Standard for the **ARM Architecture**。現行版 |

### 包含: EABI ⊃ AAPCS

EABI は呼び出し規約そのものではなく、ARM が定めた**仕様書の束**の名前。AAPCS はその中の1冊。

```
ARM EABI (仕様群)
├── AAPCS    ← 呼び出し規約はここ
├── AAELF    ← ELFの形式、リロケーション種別
├── EHABI    ← 例外テーブル
├── CPPABI   ← C++ の vtable / 名前修飾
└── RTABI    ← __aeabi_* ランタイムヘルパ
```

**APCS と ATPCS は EABI の一部ではない。** EABI 制定より前の独立した規格。ここが一番混乱しやすい。

### ELFヘッダの2つのフィールド

`readelf -h` に出てくる似た名前の2つは、まったく別物。

| 表示 | フィールド | 位置 | 意味 |
|---|---|---|---|
| `ABI Version: 0` | `e_ident[8]` | ヘッダ先頭16バイト内 | `OS/ABI`(System V)のバージョン。System V では常に0で情報量なし。ARM とは無関係 |
| `Flags: Version5 EABI` | `e_flags` 上位8bit | オフセット 0x24 | ARM 固有。EABI 仕様群の第5版 |

`e_flags` = 0x05000200 の下位 0x200 は `EF_ARM_ABI_FLOAT_SOFT`(浮動小数点引数を汎用レジスタで渡す)。これは呼び出し規約そのものの情報。

**注意:** この `Version5 EABI` を押しているのは binutils のリンカであって agbcc ではない。ROM のコードが EABI5 準拠である証明にはならない。

---

## agbcc はどっちなのか

**APCS-32 + interworking。** 根拠は3つ。

1. `agbcc_arm` のオプションに `apcs-26` / `apcs-32` / `apcs-float` / `apcs-frame` / `apcs-reentrant` が並んでいる。ATPCS も AAPCS も `-mabi` も存在しない
2. バージョンが `2.9-arm-000512`(2000年5月のGCC 2.9スナップショット)。AAPCS 制定(2003年)より前
3. `agbcc`(Thumb用)のオプションは `thumb-interwork` / `long-calls` / `omit-frame-pointer` のみ。GCC 2.x の Thumb バックエンドは ARM バックエンドと別実装でオプションが絞られている

確認コマンド:

```sh
strings tools/agbcc/bin/agbcc_arm | grep -iE "apcs|interwork|abi" | sort -u
strings tools/agbcc/bin/agbcc | grep -E "^2\.[0-9]"
```

ATPCS という規格名に準拠しているわけではなく、ATPCS が後に標準化する ARM/Thumb 相互呼び出しを個別に実装している、という位置づけ。

---

## レジスタの役割

| レジスタ | 用途 |
|---|---|
| `r0`-`r3` | 引数(第1〜第4ワード)、`r0` は戻り値も兼ねる。**呼び出し元保存** |
| `r4`-`r7` | **呼び出し先保存**。`push {r4-r7}` で直接退避できる |
| `r8`-`r11` (`sb`/`sl`) | 呼び出し先保存。Thumb では直接 push できないので `mov` で低位レジスタに移してから push |
| `r12` (`ip`), `lr` | 呼び出し元保存(スクラッチ) |

r8以上の退避はこの形になる。

```asm
push {r4, r5, r6, r7, lr}
mov  r7, sl
mov  r6, sb
mov  r5, r8
push {r5, r6, r7}
```

---

## 引数の渡し方

**ワード単位で r0→r1→r2→r3 の順に詰め、あふれた分を [sp] から順にスタックへ。** 詰め物は一切入らない。

```asm
; f5(1, 2, 3, 4, 5, 6)
mov r0,#1 / r1,#2 / r2,#3 / r3,#4
str <5>, [sp]
str <6>, [sp, #4]
```

### 64bit値も詰め物なしで分割される

AAPCS との一番わかりやすい違い。

```c
fmix(s32, s64, s32);   // → r0 = 第1引数, r1:r2 = 64bit値, r3 = 第3引数
```

AAPCS なら64bit引数は偶数レジスタ対に揃える(r2:r3)決まりなので、`r1:r2` という**奇数対**に置くのは APCS の挙動。`f64(s64, s32, s64)` では第3引数が `r3` と `[sp]` にまたがった。

### 構造体も値渡しでワード分割される

20バイトの構造体は r0-r3 に4ワード、残り1ワードが `[sp]` に置かれた。

---

## 戻り値

- 32bit以下 → `r0`
- 64bit(`s64`)→ **`r0`(下位)+ `r1`(上位)**
- **構造体はサイズを問わずメモリ返し**。呼び出し元が隠し第1引数として領域のアドレスを `r0` に入れて渡す

```asm
; S8 s = ret8();  ← 8バイトでもレジスタ返しにはならない
mov r0, sp
bl  ret8
```

---

## 狭い型は両側が切り詰める

引数はレジスタ上では32bitだが、**呼び出し側と受け側の両方**が切り詰める。受け側は渡された値を信用しない。

```asm
; GetParticleGroup(u16 ptclID) の入口
lsl r0, r0, #0x10
lsr r4, r0, #0x10
```

呼び出し側にも同じ `lsls`/`lsrs` のペアが出る。NAKED 関数の引数型を実際より狭く宣言していると、呼び出し側に余分な切り詰めが生まれて一致しなくなる。

---

## 復帰シーケンス

`-mthumb-interwork` があるので `pop {pc}` ではなく、lr を低位レジスタに取り出して `bx` する。ARMv4T の `pop {pc}` は Thumb 状態のままでしか戻れないため。

```asm
pop {r0}   ; void 関数なら r0
bx  r0

pop {r2}   ; s64 を返す関数は r0,r1 が埋まっているので r2
bx  r2
```

---

## スタックフレーム

境界は **4バイト**(APCS)。AAPCS の8バイト境界要求はないので、`sub sp, #0xC` のような4の倍数が普通に出る。

`FUN_0822ea60`(4引数、r8以上まで使う関数)の実物。**アドレスが小さいほうが上**。

```
                        低位アドレス
  SP+0x00 ────────>┌──────────────────────┐ ← 関数本体実行中の SP
                   │  一時領域ワード0      │ ┐
  SP+0x04          ├──────────────────────┤ │  sub sp, #8
                   │  一時領域ワード1      │ ┘
  SP+0x08          ├──────────────────────┤
                   │  r8                  │ ┐  mov r5, r8
  SP+0x0C          ├──────────────────────┤ │  mov r6, sb
                   │  sb (r9)             │ │  mov r7, sl
  SP+0x10          ├──────────────────────┤ │  push {r5,r6,r7}
                   │  sl (r10)            │ ┘
  SP+0x14          ├──────────────────────┤
                   │  r4                  │ ┐
  SP+0x18          ├──────────────────────┤ │
                   │  r5                  │ │
  SP+0x1C          ├──────────────────────┤ │ push {r4,r5,r6,r7,lr}
                   │  r6                  │ │
  SP+0x20          ├──────────────────────┤ │
                   │  r7                  │ │
  SP+0x24          ├──────────────────────┤ │
                   │  lr                  │ ┘
  SP+0x28 ────────>├──────────────────────┤ ← 入口時点の SP
                   │  呼び出し元のフレーム  │
                   └──────────────────────┘
                        高位アドレス
```

スタックはこの図では上に向かって伸びる。**高位レジスタ(r8以上)が低位レジスタより上(=低位アドレス側)に来る**のは、2回目の push で積まれるため。復帰は逆順で `pop {r3,r4,r5}` → `mov r8, r3` と戻す。

### フレームの範囲とネスト

**「Xのスタックフレーム」= X の prologue 完了後の SP から、X の入口時点の SP(＝呼び出し元が `bl` した瞬間の SP)まで。** フレーム同士は重ならない。

`GetAssetFile` → `FindFile` の実物。

```
                              低位アドレス
  FindFile SP+0x00 ─>┌──────────────────────┐ ┐
                     │  r4                  │ │
  FindFile SP+0x04   ├──────────────────────┤ │ FindFile の
                     │  r5                  │ │ スタックフレーム
  FindFile SP+0x08   ├──────────────────────┤ │ (12バイト)
                     │  lr                  │ │
                     ├──────────────────────┤ ┘ ← 境界 = GetAssetFile の SP
  GetAsset SP+0x00   │  第5引数 (end)        │ ┐   FindFile SP+0x0C
                     ├──────────────────────┤ │
  GetAsset SP+0x04   │                      │ │
        〜           │  ローカル (16バイト)   │ │ GetAssetFile の
  GetAsset SP+0x10   │                      │ │ スタックフレーム
                     ├──────────────────────┤ │ (40バイト)
  GetAsset SP+0x14   │  r4                  │ │
  GetAsset SP+0x18   │  r5                  │ │
  GetAsset SP+0x1C   │  r6                  │ │
  GetAsset SP+0x20   │  r7                  │ │
  GetAsset SP+0x24   │  lr                  │ ┘
                     ├──────────────────────┤ ← 境界 = さらに呼び出し元の SP
                     │  呼び出し元のフレーム  │
                     └──────────────────────┘
                              高位アドレス
```

**第5引数は `GetAssetFile` のフレームに属する。** `GetAssetFile` が `sub sp, #0x14` で確保し `str r3, [sp]` で書き込んだものだから。受け側から見ると自分のフレームの外(下側)にあるが、確保も解放も呼び出し元の責任。

```asm
; GetAssetFile 側
sub sp, #0x14
str r3, [sp]        ← 自分のフレームの底に第5引数を置く
bl  FindFile

; FindFile 側
push {r4, r5, lr}   ← 12バイト積んだので
ldr r1, [sp, #0xc]  ← 呼び出し元の [sp+0] を跨いで読む
```

保存された lr や callee-saved レジスタは、**それを push した関数自身のフレーム**。区切りは「誰が SP を動かしたか」で決まる。

### フレームポインタは無い

Thumb バックエンドは `-momit-frame-pointer` 相当が既定で `fp`(r11)を使わない。**境界を辿るには各関数の prologue を解析するしかない**ので、デバッガのスタックトレースは当てにならない。

---

## スピル

レジスタが足りなくなったとき、コンパイラが値を一時的にスタックへ追い出すこと。`sub sp, #N` の領域が置き場になる。

`FUN_0822ea60` の内側ループ:

```asm
	ldrh r0, [r4]
	ands r0, r2
	str  r1, [sp]        ← 退避
	str  r2, [sp, #4]    ← 退避
	bl   FUN_0822ea10
	ldr  r1, [sp]        ← 復帰
	ldr  r2, [sp, #4]    ← 復帰
```

r1(ループ上限)と r2(定数 0x3FF)はループを跨いで生きるが、呼び出し元保存なので `bl` で壊される。呼び出し先保存の r4-r7 は既に埋まっているため、呼び出しの前後だけメモリに逃がしている。

`sub sp, #N` の領域には**ローカル変数とスピルが同居**する。デコンパイル時、この領域が ROM より大きければC側に不要なローカルがあるサイン、小さければ元コードのほうが変数を多く使っていたサインになる。

---

## 自分で確かめる方法

プローブを書いてコンパイルすれば確認できる。

```sh
arm-none-eabi-cpp -I tools/agbcc -I tools/agbcc/include -iquote include \
  -nostdinc -undef -std=gnu89 -DMODERN=0 probe.c -o probe.i
tools/preproc/preproc probe.i charmap.txt \
  | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit -Wparentheses -O2 -fhex-asm -o probe.s
```

`-fhex-asm` を外すと即値が10進で出る。ビルド本体のフラグは Makefile の `CFLAGS`(80行目付近)を参照。
