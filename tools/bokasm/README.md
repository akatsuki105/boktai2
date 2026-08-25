# bokasm

## 使い方

```sh
bokasm script.txt script.bin
```

`INPUT_FILE`(1つ目の引数)をアセンブルし、`OUTPUT_FILE`(2つ目の引数)にバイナリを書き出します。どちらも必須で、拡張子に制限はありません。

引数を省略すると、標準入力からソースを読み込み、標準出力にバイナリを書き出します。

```sh
bokasm < script.txt > script.bin
```
