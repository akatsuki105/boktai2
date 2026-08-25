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

