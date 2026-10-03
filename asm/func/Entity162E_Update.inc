	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08089A50 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08089A98
	ldr r0, [r0, #0x1c]
	cmp r0, #1
	bne _08089A98
	movs r7, #0
	ldr r6, _08089A54 @ =0x030046A0
	ldr r0, [r6]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _08089A58
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #0x1a]
	cmp r0, r2
	blo _08089A5A
	strh r7, [r5, #0x18]
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r4
	ldr r0, [r0]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #1
	bl FUN_0809c3c0
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bgt _08089A5A
	b _08089A5E
	.align 2, 0
_08089A50: .4byte 0x03002BE0
_08089A54: .4byte 0x030046A0
_08089A58:
	movs r7, #1
_08089A5A:
	cmp r7, #0
	beq _08089A98
_08089A5E:
	ldr r4, _08089AA0 @ =0x03002BE0
	ldr r1, [r4]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _08089A98
	adds r0, r1, #0
	bl FUN_0807e854
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _08089AA4 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl KillEntity
_08089A98:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08089AA0: .4byte 0x03002BE0
_08089AA4: .4byte 0x0000037D
