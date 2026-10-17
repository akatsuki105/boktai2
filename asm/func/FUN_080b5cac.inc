	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B5D30 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080B5D34 @ =0x00001413
	adds r1, r7, r2
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r0, r7, #0
	adds r0, #0x80
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
_080B5CDA:
	movs r2, #0
	mov sl, r2
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #8]
	adds r6, r2, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B5CFC:
	mov r5, r8
	add r5, sl
	ldr r1, _080B5D38 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r2, r0, #0
	cmp r2, #0
	blt _080B5D3C
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080B5D52
	.align 2, 0
_080B5D30: .4byte 0x00001412
_080B5D34: .4byte 0x00001413
_080B5D38: .4byte 0x00001458
_080B5D3C:
	ldr r2, _080B5DE0 @ =0x00001412
	adds r1, r7, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B5D4A
	strb r5, [r1]
_080B5D4A:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B5D52:
	adds r0, r6, #0
	ldr r1, _080B5DE4 @ =0x000002DF
	bl FUN_080b95bc
	adds r6, #0x60
	adds r4, #0x60
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #3
	ble _080B5CFC
	ldr r1, [sp, #8]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #8]
	add sb, r3
	mov r3, sb
	cmp r3, #3
	ble _080B5CDA
	movs r0, #0
	mov sb, r0
_080B5D7E:
	movs r1, #0
	mov sl, r1
	mov r2, sb
	lsls r2, r2, #2
	mov r8, r2
	mov r3, sb
	adds r3, #1
	str r3, [sp]
	adds r2, #0x13
	mov r1, sb
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r6, r0, r1
	mov r5, r8
	adds r5, #0x10
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #4]
	adds r4, r0, r1
_080B5DAE:
	ldr r2, _080B5DE8 @ =0x00001458
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetNormalItemID
	adds r2, r0, #0
	cmp r2, #0
	blt _080B5DEC
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080B5E02
	.align 2, 0
_080B5DE0: .4byte 0x00001412
_080B5DE4: .4byte 0x000002DF
_080B5DE8: .4byte 0x00001458
_080B5DEC:
	ldr r3, _080B5E44 @ =0x00001413
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B5DFA
	strb r5, [r1]
_080B5DFA:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B5E02:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080B5DAE
	ldr r2, [sp]
	mov sb, r2
	cmp r2, #3
	ble _080B5D7E
	movs r3, #1
	ldr r0, [sp, #4]
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r1, r0, r2
	movs r2, #3
_080B5E26:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B5E26
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B5E44: .4byte 0x00001413
