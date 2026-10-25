	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov r7, r8
	movs r0, #0xa9
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C61F8
	movs r6, #0
	mov r1, sb
	strb r6, [r1]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #8
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
	ldr r1, _080C6240 @ =0x000002FA
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
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C61F8:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	mov r1, r8
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, r8
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x3b
	ble _080C622E
	ldr r2, _080C6244 @ =FUN_080c6248
	movs r0, #0x34
	mov r3, r8
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C622E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6240: .4byte 0x000002FA
_080C6244: .4byte FUN_080c6248
