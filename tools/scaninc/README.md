# scaninc

> [!WARNING]
> このREADMEはツールの作者 (YamaArashi) によって書かれたものではなく、ツールのユーザ (Akatsuki105) によって書かれたものです。

agbcc (GBA時代のgcc) に 依存関係ファイル `.d` を出力する機能がない(っぽい？)のでそれを行うプログラム

## Usage

```sh
Usage:
  scaninc [OPTIONS] SRC_FILE

Arguments:
  SRC_FILE is the file to scan

Options:
  -I <DIR>    includeディレクトリを指定
  -M <FILE>   依存関係をファイル(".d")の出力先のパス  
              このオプションを指定しない場合、依存関係は標準出力に出力される (依存関係がただしく出力されているかを確認する用途？)
```

## Example

```sh
$ ./tools/scaninc/scaninc -I include -M tmp/output.d src/libs/agb_sram.c
```

このコマンドを実行すると、 `tmp/output.d` に以下のような内容が出力される

```makefile
# 依存先のファイルを scaninc が見つけられなかった場合は、ここには記述されない
tmp/output.o: include/gba/agb_sram.h include/gba/defines.h include/gba/gba.h include/gba/io_reg.h include/gba/macro.h include/gba/syscall.h include/gba/types.h 
tmp/output.d: include/gba/agb_sram.h include/gba/defines.h include/gba/gba.h include/gba/io_reg.h include/gba/macro.h include/gba/syscall.h include/gba/types.h 
```

`scaninc` では `#include` だけでなく、`INCBIN_U8` と `INCASM`, `INCFUNC` で指定されたファイルも依存関係として認識される
`INCBIN_U8` 自体の処理は `preproc` で行われる, `scaninc` はあくまで `INCBIN_U8(<path>)` というパターンを認識して、依存関係として記録するだけ
`INCASM`, `INCFUNC` はただのCプリプロセッサのマクロ (Akatsuki105 が定義し、`scaninc` が依存関係として認識するように加えた)

## Note

アセンブリファイルに対しての`scaninc`で`.include`, `.incbin` の前に、タブ、スペース以外の文字がある場合は、依存関係として認識されない

つまり、

```asm
label: .incbin "xxx"
```

ではなく

```asm
label:
  .incbin "xxx"
```

と書かないと、"xxx" が依存関係として認識されないので注意すること
