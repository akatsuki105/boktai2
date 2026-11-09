	push {lr}
	ldr r1, _081833D8 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r3, #0x92
	lsls r3, r3, #3
	adds r1, r0, r3
	strh r2, [r1]
	bl Enemy_Update
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081833D8: .4byte 0x030046A0
