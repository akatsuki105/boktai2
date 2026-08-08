	ldr r1, _082110F0 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xea
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	bx lr
	.align 2, 0
_082110F0: .4byte 0x030046A0
