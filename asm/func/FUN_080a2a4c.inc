	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2A88 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2A68
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080A2A68:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2A78
	adds r0, #1
	strh r0, [r1]
_080A2A78:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2A8C
	adds r0, #2
	b _080A2A8E
	.align 2, 0
_080A2A88: .4byte 0x00000382
_080A2A8C:
	movs r0, #0x18
_080A2A8E:
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2AA6
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2AC0
_080A2AA6:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2AC0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2ADE
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A2B06
_080A2ADE:
	cmp r0, #0
	beq _080A2AF6
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2B06
_080A2AF6:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A2B06:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x17
	bls _080A2B24
	ldr r1, _080A2B2C @ =FUN_080a2b30
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
_080A2B24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2B2C: .4byte FUN_080a2b30
