	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0818F9A8 @ =0x00000ECC
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0818F9A8: .4byte 0x00000ECC
