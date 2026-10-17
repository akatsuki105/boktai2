	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080B7A68 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _080B7A6C @ =0x00001413
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
_080B7A06:
	movs r2, #0
	mov sl, r2
	mov r3, sb
	lsls r3, r3, #2
	mov r8, r3
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r2, [sp, #8]
	adds r5, r2, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, [sp, #4]
	adds r4, r0, r3
_080B7A28:
	mov r6, r8
	add r6, sl
	ldr r1, _080B7A70 @ =0x00001458
	adds r0, r7, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	ldr r1, _080B7A74 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	blt _080B7A78
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080B7A8E
	.align 2, 0
_080B7A68: .4byte 0x00001412
_080B7A6C: .4byte 0x00001413
_080B7A70: .4byte 0x00001458
_080B7A74: .4byte 0x030046A0
_080B7A78:
	ldr r0, _080B7AA8 @ =0x00001412
	adds r1, r7, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B7A86
	strb r6, [r1]
_080B7A86:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B7A8E:
	ldr r0, _080B7AAC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bne _080B7AB0
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080B7AB8
	.align 2, 0
_080B7AA8: .4byte 0x00001412
_080B7AAC: .4byte 0x030046A0
_080B7AB0:
	adds r0, r5, #0
	ldr r1, _080B7B4C @ =0x000002DF
	bl FUN_080b95bc
_080B7AB8:
	adds r5, #0x60
	adds r4, #0x60
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _080B7A28
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #8]
	add sb, r2
	mov r2, sb
	cmp r2, #3
	ble _080B7A06
	movs r3, #0
	mov sb, r3
_080B7ADC:
	movs r0, #0
	mov sl, r0
	mov r1, sb
	lsls r1, r1, #2
	mov r8, r1
	mov r2, sb
	adds r2, #1
	str r2, [sp]
	mov r2, r8
	adds r2, #0x13
	mov r3, sb
	lsls r0, r3, #3
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
_080B7B0E:
	ldr r2, _080B7B50 @ =0x00001458
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	ldr r1, _080B7B54 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	blt _080B7B58
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080B7B6E
	.align 2, 0
_080B7B4C: .4byte 0x000002DF
_080B7B50: .4byte 0x00001458
_080B7B54: .4byte 0x030046A0
_080B7B58:
	ldr r2, _080B7BD0 @ =0x00001413
	adds r1, r7, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080B7B66
	strb r5, [r1]
_080B7B66:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080B7B6E:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #3
	ble _080B7B0E
	ldr r1, [sp]
	mov sb, r1
	cmp r1, #3
	ble _080B7ADC
	ldr r0, _080B7BD4 @ =0x030046A0
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x5c
	ldrh r4, [r3]
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _080B7BE0
	movs r0, #0xf8
	lsls r0, r0, #4
	adds r2, r7, r0
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
	ldr r2, _080B7BD8 @ =0x00000F98
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, _080B7BDC @ =0x00000F9A
	adds r1, r7, r3
	strh r0, [r1]
	b _080B7BEE
	.align 2, 0
_080B7BD0: .4byte 0x00001413
_080B7BD4: .4byte 0x030046A0
_080B7BD8: .4byte 0x00000F98
_080B7BDC: .4byte 0x00000F9A
_080B7BE0:
	movs r1, #0xf8
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B7BEE:
	movs r3, #1
	ldr r2, [sp, #4]
	movs r0, #0xf6
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r2, #2
_080B7BFA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B7BFA
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
