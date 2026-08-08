	ldr r2, _0807B8B8 @ =0x0000096C
	adds r3, r0, r2
	movs r2, #2
	strh r2, [r3]
	ldr r2, _0807B8BC @ =0x0000095E
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0807B8B8: .4byte 0x0000096C
_0807B8BC: .4byte 0x0000095E
