	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	adds r6, r7, #0
	movs r0, #0xa9
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C7FB2
	movs r4, #0
	mov r1, r8
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
	ldr r0, _080C8004 @ =0x000002F2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0x13
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C7FB2:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C7FF6
	adds r0, r7, #0
	bl Jormungandr_EasePos
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080c4a40
	mov r0, sb
	cmp r0, #0x18
	ble _080C7FF6
	ldr r1, _080C8008 @ =FUN_080c800c
	movs r0, #0xd
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C7FF6:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8004: .4byte 0x000002F2
_080C8008: .4byte FUN_080c800c
