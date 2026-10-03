	movs r3, #0xb7
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BFA70 @ =0x000005B6
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BFA70: .4byte 0x000005B6
