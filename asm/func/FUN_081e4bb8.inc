	ldr r1, _081E4BD0 @ =FUN_081e6458
	movs r3, #0x19
	str r1, [r0, #0x18]
	ldr r1, _081E4BD4 @ =0x00001614
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081E4BD8 @ =0x00001616
	adds r0, r0, r1
	strb r3, [r0]
	bx lr
	.align 2, 0
_081E4BD0: .4byte FUN_081e6458
_081E4BD4: .4byte 0x00001614
_081E4BD8: .4byte 0x00001616
