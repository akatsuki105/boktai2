	ldr r1, _080749A8 @ =0x0000095E
	adds r2, r0, r1
	ldr r1, _080749AC @ =0x00000127
	strh r1, [r2]
	movs r1, #0x96
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0x18
	strh r1, [r0]
	bx lr
	.align 2, 0
_080749A8: .4byte 0x0000095E
_080749AC: .4byte 0x00000127
