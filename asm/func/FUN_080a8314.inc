	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldrh r0, [r3, #0x3a]
	adds r4, r0, #1
	strh r4, [r3, #0x3a]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A8336
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x38]
	b _080A837E
_080A8336:
	ldrh r1, [r3, #0x32]
	ldrh r0, [r3, #0x2a]
	adds r1, r1, r0
	strh r1, [r3, #0x2a]
	ldr r0, _080A8370 @ =0x03002BE0
	ldr r2, [r0]
	ldrh r0, [r3, #0x28]
	ldrh r6, [r2, #0x2c]
	adds r0, r0, r6
	strh r0, [r3, #0x18]
	ldrh r0, [r2, #0x2e]
	adds r0, r0, r1
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r2, [r2, #0x30]
	adds r0, r0, r2
	strh r0, [r3, #0x1c]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A8374
	adds r0, r3, #0
	adds r1, r5, #0
	movs r2, #3
	bl FUN_0822dafc
	b _080A837E
	.align 2, 0
_080A8370: .4byte 0x03002BE0
_080A8374:
	adds r0, r3, #0
	adds r1, r5, #0
	movs r2, #2
	bl FUN_0822dafc
_080A837E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
