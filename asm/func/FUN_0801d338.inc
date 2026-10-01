	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r6, #0x66
	ldrb r1, [r6]
	lsls r5, r1, #2
	adds r5, #0xc4
	adds r5, r0, r5
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #5
	ldr r1, _0801D390 @ =0x00001104
	adds r4, r4, r1
	adds r4, r0, r4
	adds r1, r0, #0
	adds r1, #0xd8
	adds r0, #0x92
	ldrb r2, [r0]
	adds r2, #0x14
	adds r0, r4, #0
	movs r3, #0
	bl MainSprite_SetPose
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0
	movs r0, #1
	strh r0, [r5]
	strh r1, [r5, #2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0801D388
	movs r0, #0
	strb r0, [r6]
_0801D388:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D390: .4byte 0x00001104
