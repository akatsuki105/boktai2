	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x28]
	adds r2, r0, #1
	strh r2, [r3, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080A9828
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x2a]
	b _080A983A
_080A9828:
	ldr r1, [r3, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl FUN_0822dafc
_080A983A:
	pop {r0}
	bx r0
	.align 2, 0
