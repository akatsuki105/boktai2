	ldr r1, _08223D14 @ =0x00000F44
	adds r2, r0, r1
	movs r1, #0xc
	strb r1, [r2]
	ldr r1, _08223D18 @ =0x00000F54
	adds r0, r0, r1
	ldr r1, _08223D1C @ =FUN_08223d20
	str r1, [r0]
	bx lr
	.align 2, 0
_08223D14: .4byte 0x00000F44
_08223D18: .4byte 0x00000F54
_08223D1C: .4byte FUN_08223d20
