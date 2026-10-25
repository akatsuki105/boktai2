	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov sl, r1
	mov r7, sb
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8588
	movs r4, #0
	mov r1, r8
	strb r4, [r1]
	movs r0, #0x89
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C8588:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	bne _080C8618
	ldr r0, _080C8628 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _080C862C @ =0x000002FA
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x10
	ldr r3, [r1, #0x2c]
	ldr r4, [r1, #0x30]
	ldrh r1, [r1, #0x2c]
	adds r3, r1, #0
	orrs r3, r0
	ldr r6, _080C8630 @ =0xFFFFFC00
	adds r1, r4, r6
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	ldr r5, _080C8634 @ =0xFFFF0000
	adds r2, r5, #0
	ands r2, r4
	orrs r2, r0
	adds r4, r2, #0
	movs r6, #0xbf
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r1, r0
	bge _080C85DE
	lsrs r0, r0, #0x10
	ands r2, r5
	adds r4, r2, #0
	orrs r4, r0
_080C85DE:
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r7, r1
	str r3, [r0]
	str r4, [r0, #4]
	ldr r2, _080C8638 @ =0x00000DBC
	adds r1, r7, r2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C863C @ =0x0000012B
	cmp sl, r0
	ble _080C8612
	ldr r1, _080C8640 @ =FUN_080c8644
	movs r0, #0x13
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r6, ip
	str r6, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C8612:
	mov r0, sb
	bl FUN_080c4990
_080C8618:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8628: .4byte 0x03002BE0
_080C862C: .4byte 0x000002FA
_080C8630: .4byte 0xFFFFFC00
_080C8634: .4byte 0xFFFF0000
_080C8638: .4byte 0x00000DBC
_080C863C: .4byte 0x0000012B
_080C8640: .4byte FUN_080c8644
