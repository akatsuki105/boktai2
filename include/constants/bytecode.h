#ifndef __INCLUDE_CONSTANTS_BYTECODE_H__
#define __INCLUDE_CONSTANTS_BYTECODE_H__

// Opcode が 0x10 以上の場合は、 上位4bitが Opcode、 下位4bitは引数として使われる

#define OP_END 0x00
#define OP_S16 0x01
#define OP_U8 0x02
#define OP_U16 0x06

// プログラミング言語でいう"予約語"
#define OP_KEYWORD 0x50  // 下位4bitは キーワードの長さ(コンテナ長) を指定する
#define KW_CASE 0x63
#define KW_DEFAULT 0x64
#define KW_ELSE 0x65
#define KW_ELIF 0x69
#define KW_UNK6D 0x6D

#endif  // __INCLUDE_CONSTANTS_BYTECODE_H__
