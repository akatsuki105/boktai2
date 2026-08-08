	ldr r1, _0807B8CC @ =0x0000096C
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807B8CC: .4byte 0x0000096C
