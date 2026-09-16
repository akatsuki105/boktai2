	adds r2, r0, #0
	ldr r0, _080916CC @ =0x03002C10
	ldrh r0, [r0]
	movs r1, #1
	lsls r1, r2
	ands r0, r1
	bx lr
	.align 2, 0
_080916CC: .4byte 0x03002C10
