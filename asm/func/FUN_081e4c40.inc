	ldr r1, _081E4C58 @ =FUN_081e64cc
	movs r3, #0x1c
	str r1, [r0, #0x18]
	ldr r1, _081E4C5C @ =0x00001614
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081E4C60 @ =0x00001616
	adds r0, r0, r1
	strb r3, [r0]
	bx lr
	.align 2, 0
_081E4C58: .4byte FUN_081e64cc
_081E4C5C: .4byte 0x00001614
_081E4C60: .4byte 0x00001616
