	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081BEB88 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BEB8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BEB8E
	.align 2, 0
_081BEB88: .4byte 0x0000046C
_081BEB8C:
	movs r0, #0
_081BEB8E:
	cmp r0, #0
	beq _081BEBC4
	ldr r4, _081BEC28 @ =GolemLink_StateWindUp
	movs r3, #0x21
	ldr r2, _081BEC2C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081BEC30 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081BEC34 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081BEC30 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
_081BEBC4:
	adds r0, r5, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081BEC4E
	ldr r3, _081BEC30 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081BEC44
	ldr r2, _081BEC38 @ =GolemLink_StateRoll
	movs r1, #0x22
	ldr r6, _081BEC2C @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081BEC3C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081BEC40 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	b _081BEC4E
	.align 2, 0
_081BEC28: .4byte GolemLink_StateWindUp
_081BEC2C: .4byte 0x0000046D
_081BEC30: .4byte 0x0000046B
_081BEC34: .4byte 0x00000553
_081BEC38: .4byte GolemLink_StateRoll
_081BEC3C: .4byte 0x00000469
_081BEC40: .4byte 0x0000046A
_081BEC44:
	ldr r2, _081BEC54 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BEC4E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081BEC54: .4byte 0x00000484
