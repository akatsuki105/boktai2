	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	movs r2, #0x15
	ldrsb r2, [r5, r2]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r2, r1
	bne _080477B0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1, #8]
	movs r3, #1
	orrs r2, r3
	str r2, [r1, #8]
	b _080477D4
_080477B0:
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x9b
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x15
	ldrsb r2, [r5, r2]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl MainSprite_SetPose
_080477D4:
	ldrb r2, [r5, #0x15]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	strb r2, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
