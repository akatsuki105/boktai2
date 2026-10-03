	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov sl, r0
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0x80
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0x14]
_080BB3AA:
	movs r2, #0
	mov sb, r2
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [sp, #0x14]
	adds r6, r1, r0
	ldr r2, [sp, #0xc]
	mov r8, r2
	ldr r1, [sp, #0x10]
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r5, r0, r1
_080BB3CA:
	ldr r7, [sp, #0x10]
	add r7, sb
	ldr r0, _080BB404 @ =0x030046A0
	ldr r0, [r0]
	add r0, r8
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r4, [r0, r1]
	cmp r4, #0
	blt _080BB408
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080BB410
	.align 2, 0
_080BB404: .4byte 0x030046A0
_080BB408:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BB410:
	ldr r0, _080BB438 @ =0x08DAA7B0
	lsls r1, r4, #3
	adds r1, r1, r0
	movs r2, #6
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080BB42C
	ldr r0, _080BB43C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bne _080BB440
_080BB42C:
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BB448
	.align 2, 0
_080BB438: .4byte 0x08DAA7B0
_080BB43C: .4byte 0x030046A0
_080BB440:
	adds r0, r6, #0
	ldr r1, _080BB504 @ =0x000002DF
	bl FUN_080b95bc
_080BB448:
	adds r6, #0x60
	movs r2, #2
	add r8, r2
	adds r5, #0x60
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _080BB3CA
	ldr r2, [sp, #0xc]
	adds r2, #8
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, #4
	str r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #0x14]
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #3
	ble _080BB3AA
	movs r1, #0
	str r1, [sp]
_080BB47E:
	movs r2, #0
	mov sb, r2
	ldr r0, [sp]
	lsls r0, r0, #2
	mov r8, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp, #4]
	mov r2, r8
	adds r2, #0x13
	ldr r1, [sp]
	lsls r0, r1, #3
	add r0, r8
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, sl
	adds r6, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r2, [sp, #8]
	adds r5, r0, r2
_080BB4AC:
	mov r7, r8
	add r7, sb
	ldr r0, _080BB508 @ =0x00001304
	add r0, sl
	adds r0, r0, r7
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BB524
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _080BB50C @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0x91
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r2, _080BB510 @ =0x08DAA7B0
	lsls r0, r4, #3
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #6
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _080BB514
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BB52C
	.align 2, 0
_080BB504: .4byte 0x000002DF
_080BB508: .4byte 0x00001304
_080BB50C: .4byte 0x030046A0
_080BB510: .4byte 0x08DAA7B0
_080BB514:
	adds r0, r6, #0
	ldr r1, _080BB520 @ =0x000002DF
	bl FUN_080b95bc
	b _080BB52C
	.align 2, 0
_080BB520: .4byte 0x000002DF
_080BB524:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BB52C:
	adds r5, #0x60
	adds r6, #0x60
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	ble _080BB4AC
	movs r5, #3
	ldr r2, [sp, #4]
	str r2, [sp]
	cmp r2, #2
	ble _080BB47E
	ldr r0, _080BB568 @ =0x030046A0
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x5c
	ldrh r4, [r3]
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bge _080BB56C
	movs r0, #0xd4
	lsls r0, r0, #4
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080BB5A2
	.align 2, 0
_080BB568: .4byte 0x030046A0
_080BB56C:
	movs r2, #0xd4
	lsls r2, r2, #4
	add r2, sl
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r5, #0
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r1, _080BB5B4 @ =0x00000D58
	add r1, sl
	strh r0, [r1]
	ldrh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r1, _080BB5B8 @ =0x00000D5A
	add r1, sl
	strh r0, [r1]
_080BB5A2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BB5B4: .4byte 0x00000D58
_080BB5B8: .4byte 0x00000D5A
