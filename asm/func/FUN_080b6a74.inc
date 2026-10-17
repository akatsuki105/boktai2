	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B6AF8 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _080B6AFC @ =0x00001413
	adds r1, r7, r3
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #0
	mov sb, r0
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #4]
	movs r3, #0
	str r3, [sp, #8]
_080B6AA2:
	movs r0, #0
	mov sl, r0
	mov r1, sb
	lsls r1, r1, #2
	mov r8, r1
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [sp, #8]
	adds r5, r1, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B6AC4:
	mov r6, r8
	add r6, sl
	ldr r1, _080B6B00 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	ble _080B6B04
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080B6B1A
	.align 2, 0
_080B6AF8: .4byte 0x00001412
_080B6AFC: .4byte 0x00001413
_080B6B00: .4byte 0x00001458
_080B6B04:
	ldr r3, _080B6B30 @ =0x00001412
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B6B12
	strb r6, [r1]
_080B6B12:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B6B1A:
	adds r0, r6, #0
	bl FUN_082430d4
	cmp r0, #0
	beq _080B6B34
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080B6B3C
	.align 2, 0
_080B6B30: .4byte 0x00001412
_080B6B34:
	adds r0, r5, #0
	ldr r1, _080B6BC4 @ =0x000002DF
	bl FUN_080b95bc
_080B6B3C:
	adds r5, #0x60
	adds r4, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080B6AC4
	ldr r3, [sp, #8]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r3, r0
	str r3, [sp, #8]
	movs r1, #1
	add sb, r1
	mov r3, sb
	cmp r3, #3
	ble _080B6AA2
	movs r0, #0
	mov sb, r0
_080B6B62:
	movs r1, #0
	mov sl, r1
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	mov r0, sb
	adds r0, #1
	str r0, [sp]
	mov r2, r8
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
_080B6B94:
	ldr r3, _080B6BC8 @ =0x00001458
	adds r0, r7, r3
	adds r0, r0, r5
	ldrb r0, [r0]
	bl GetWeaponID
	adds r2, r0, #0
	cmp r2, #0
	ble _080B6BCC
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080B6BE2
	.align 2, 0
_080B6BC4: .4byte 0x000002DF
_080B6BC8: .4byte 0x00001458
_080B6BCC:
	ldr r0, _080B6C44 @ =0x00001413
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B6BDA
	strb r5, [r1]
_080B6BDA:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B6BE2:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r1, #1
	add sl, r1
	mov r3, sl
	cmp r3, #3
	ble _080B6B94
	ldr r0, [sp]
	mov sb, r0
	cmp r0, #3
	ble _080B6B62
	ldr r0, _080B6C48 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, [sp, #4]
	movs r3, #0xf0
	lsls r3, r3, #4
	adds r2, r1, r3
	adds r3, r0, #0
	adds r3, #0x60
	ldr r0, _080B6C4C @ =0x00000F98
	adds r5, r7, r0
	movs r6, #3
_080B6C10:
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _080B6C50
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r5]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
	b _080B6C58
	.align 2, 0
_080B6C44: .4byte 0x00001413
_080B6C48: .4byte 0x030046A0
_080B6C4C: .4byte 0x00000F98
_080B6C50:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080B6C58:
	adds r2, #0x60
	adds r3, #2
	adds r5, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080B6C10
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
