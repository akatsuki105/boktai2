	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r4, r1, #0x10
	lsrs r4, r4, #0x10
	ldrh r0, [r5, #0xe]
	ldrh r1, [r5, #0xc]
	muls r1, r4, r1
	bl DivArm
	strh r0, [r5, #0xc]
	strh r4, [r5, #0xe]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
