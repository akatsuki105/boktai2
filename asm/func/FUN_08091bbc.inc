	ldr r1, _08091BD4 @ =0x00003FA2
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r2, _08091BD8 @ =0x0000401D
	adds r1, r0, r2
	movs r2, #1
	strb r2, [r1]
	ldr r1, _08091BDC @ =0x00003AE4
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_08091BD4: .4byte 0x00003FA2
_08091BD8: .4byte 0x0000401D
_08091BDC: .4byte 0x00003AE4
