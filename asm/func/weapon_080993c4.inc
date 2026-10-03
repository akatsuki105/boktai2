	ldr r1, [r0, #0x5c]
	ldr r0, _080993E0 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r1, [r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	bx lr
	.align 2, 0
_080993E0: .4byte 0x030046A0
