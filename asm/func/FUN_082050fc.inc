	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08205124
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	ldr r0, _08205170 @ =0x0000011F
	bl PlaySound_082406e0
_08205124:
	ldrh r0, [r4, #0xe]
	movs r5, #1
	movs r6, #0
	orrs r0, r5
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08205166
	adds r0, r4, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08205166
	strb r5, [r4, #7]
	ldr r0, _08205174 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0
	str r0, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
_08205166:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08205170: .4byte 0x0000011F
_08205174: .4byte FUN_08042178
