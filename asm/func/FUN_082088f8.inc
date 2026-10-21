	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r7, r2, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820893E
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	adds r0, #0xfc
	adds r1, r5, #0
	adds r1, #0xdc
	bl MainSprite_AdvanceAnim
_0820893E:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208986
	ldrh r0, [r6, #0x16]
	cmp r0, #0
	beq _08208986
	cmp r7, #0
	ble _08208986
	adds r0, r7, #0
	movs r1, #0x46
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08208986
	ldr r0, [r6, #0x18]
	adds r1, r5, #0
	adds r1, #0x5c
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl Emote_Show
	str r0, [r6, #0x18]
_08208986:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
