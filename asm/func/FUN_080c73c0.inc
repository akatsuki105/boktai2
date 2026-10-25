	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov sl, r1
	adds r7, r6, #0
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C7450
	movs r1, #0
	mov sb, r1
	mov r0, sb
	mov r2, r8
	strb r0, [r2]
	ldr r0, _080C74A8 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r0, #0x20
	adds r2, #4
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _080C74AC @ =0x000002FA
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r0, #0x80
	subs r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #1
	str r5, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r5, [sp]
	mov r2, sb
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C7450:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C7498
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x25
	ble _080C7498
	ldr r1, _080C74B0 @ =FUN_080c74b4
	movs r0, #4
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C7498:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C74A8: .4byte 0x03002BE0
_080C74AC: .4byte 0x000002FA
_080C74B0: .4byte FUN_080c74b4
