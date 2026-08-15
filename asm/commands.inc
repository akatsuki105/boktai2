@ https://boktaihacking.net/wiki/Bytecode

  @ 制御、呼び出し、およびブロック命令を終了
  .macro end
  .byte 0x00 @ Opcode
  .endm

	.macro s16 val
  .byte 0x01 @ Opcode
	.2byte \val
	.endm

	.macro u8 val
  .byte 0x02 @ Opcode
	.byte \val
	.endm

	.macro u16 val
  .byte 0x06 @ Opcode
	.2byte \val
	.endm

  @ Opcode が 0x10 以上の場合は、 上位4bitが Opcode、 下位4bitは引数として使われる

  @ プログラミング言語でいう"予約語"?
  @ length: keyword が作るブロックのバイトサイズ(ただし、 keyword命令 と end命令のバイトは含まない)
  @ val:
  @  0x63: "case"
  @  0x64: "default"
  @  0x65: "else"
  @  0x69: "elif"
  @  0x6D: "unk6d"
  .macro keyword length val
  .byte (0x50 | \length) @ Opcode(0x5X)
  .byte \val
  .endm

