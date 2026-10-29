	ldr r2, _0820CF68 @ =0x030046A0
	ldr r2, [r2]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r2, r2, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	lsrs r1, r0, #5
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0820CF68: .4byte 0x030046A0
