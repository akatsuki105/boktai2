	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov r6, r8
	movs r0, #0xa9
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8730
	movs r4, #0
	mov r1, sb
	strb r4, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C87C0 @ =0x000002F2
	adds r1, r6, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0x2f
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x11
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8730:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C87AE
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, sl
	cmp r0, #5
	ble _080C8788
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	str r7, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x12
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	str r5, [sp]
	str r7, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8788:
	mov r0, r8
	bl Jormungandr_EasePos
	mov r0, sl
	cmp r0, #0x29
	ble _080C87AE
	ldr r1, _080C87C4 @ =FUN_080c87c8
	movs r0, #0x15
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C87AE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C87C0: .4byte 0x000002F2
_080C87C4: .4byte FUN_080c87c8
