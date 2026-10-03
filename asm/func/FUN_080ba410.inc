	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	movs r7, #0
	adds r0, #0x80
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
_080BA428:
	movs r0, #0
	mov sl, r0
	lsls r1, r7, #2
	mov r8, r1
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [sp, #8]
	adds r6, r1, r0
	mov r1, r8
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r4, r0, r1
_080BA448:
	mov r1, r8
	add r1, sl
	adds r0, r1, #0
	bl GetNormalItemID
	adds r5, r0, #0
	cmp r5, #0
	blt _080BA478
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080BA480
_080BA478:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080BA480:
	adds r0, r6, #0
	ldr r1, _080BA524 @ =0x000002DF
	bl FUN_080b95bc
	adds r6, #0x60
	adds r4, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080BA448
	ldr r0, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #8]
	adds r7, #1
	cmp r7, #3
	ble _080BA428
	movs r7, #0
_080BA4A8:
	movs r0, #0
	mov sl, r0
	lsls r1, r7, #2
	mov r8, r1
	adds r0, r7, #1
	str r0, [sp, #4]
	mov r2, r8
	adds r2, #0x13
	lsls r0, r7, #3
	add r0, r8
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, sb
	adds r7, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r6, r0, r1
_080BA4D0:
	mov r1, r8
	add r1, sl
	ldr r0, _080BA528 @ =0x000012F4
	add r0, sb
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	blt _080BA540
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r5, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, sb
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _080BA52C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r5, #0
	bl FUN_080ba220
	cmp r4, r0
	bge _080BA530
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BA548
	.align 2, 0
_080BA524: .4byte 0x000002DF
_080BA528: .4byte 0x000012F4
_080BA52C: .4byte 0x030046A0
_080BA530:
	adds r0, r7, #0
	ldr r1, _080BA53C @ =0x000002DF
	bl FUN_080b95bc
	b _080BA548
	.align 2, 0
_080BA53C: .4byte 0x000002DF
_080BA540:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BA548:
	adds r6, #0x60
	adds r7, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _080BA4D0
	ldr r7, [sp, #4]
	cmp r7, #2
	ble _080BA4A8
	movs r0, #0xd4
	lsls r0, r0, #4
	add r0, sb
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
