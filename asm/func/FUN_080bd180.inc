	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0
	mov sl, r0
	mov r1, r8
	adds r1, #0x80
	str r1, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
_080BD19C:
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	lsls r1, r1, #2
	mov sb, r1
	movs r0, #0xcc
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [sp, #0xc]
	adds r7, r2, r0
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r6, r0, r1
_080BD1BC:
	ldr r5, [sp]
	add r5, sb
	adds r0, r5, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	ble _080BD1E8
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, r8
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	b _080BD1F0
_080BD1E8:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BD1F0:
	adds r0, r5, #0
	bl FUN_082430d4
	cmp r0, #0
	bne _080BD204
	adds r0, r5, #0
	bl FUN_080bce64
	cmp r0, #0
	bne _080BD210
_080BD204:
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BD218
_080BD210:
	adds r0, r7, #0
	ldr r1, _080BD2D8 @ =0x000002DF
	bl FUN_080b95bc
_080BD218:
	adds r7, #0x60
	adds r6, #0x60
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	cmp r2, #3
	ble _080BD1BC
	ldr r0, [sp, #0xc]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #0xc]
	movs r2, #1
	add sl, r2
	mov r0, sl
	cmp r0, #3
	ble _080BD19C
	movs r1, #0
	mov sl, r1
_080BD23E:
	movs r2, #0
	str r2, [sp]
	mov r0, sl
	lsls r0, r0, #2
	mov sb, r0
	mov r1, sl
	adds r1, #1
	str r1, [sp, #4]
	mov r2, sb
	adds r2, #0x13
	mov r1, sl
	lsls r0, r1, #3
	add r0, sb
	lsls r0, r0, #5
	movs r1, #0xf3
	lsls r1, r1, #3
	add r1, r8
	adds r7, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r2, [sp, #8]
	adds r6, r0, r2
_080BD26C:
	ldr r5, [sp]
	add r5, sb
	ldr r0, _080BD2DC @ =0x00001654
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r5, r0
	ldr r1, _080BD2E0 @ =0x0000165C
	add r1, r8
	adds r1, r1, r0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080BD2E4 @ =0x08DA9E68
	adds r0, r0, r1
	ldrb r4, [r0]
	cmp r4, #0
	ble _080BD2FC
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	mov r1, r8
	adds r1, #0x38
	adds r2, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _080BD2E8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r2, _080BD2E4 @ =0x08DA9E68
	adds r0, r0, r2
	ldrh r0, [r0, #0xa]
	cmp r1, r0
	bge _080BD2EC
	adds r0, r7, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BD304
	.align 2, 0
_080BD2D8: .4byte 0x000002DF
_080BD2DC: .4byte 0x00001654
_080BD2E0: .4byte 0x0000165C
_080BD2E4: .4byte 0x08DA9E68
_080BD2E8: .4byte 0x030046A0
_080BD2EC:
	adds r0, r7, #0
	ldr r1, _080BD2F8 @ =0x000002DF
	bl FUN_080b95bc
	b _080BD304
	.align 2, 0
_080BD2F8: .4byte 0x000002DF
_080BD2FC:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
_080BD304:
	adds r6, #0x60
	adds r7, #0x60
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #3
	ble _080BD26C
	ldr r1, [sp, #4]
	mov sl, r1
	cmp r1, #2
	ble _080BD23E
	ldr r0, _080BD344 @ =0x030046A0
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x60
	ldr r5, _080BD348 @ =0x00000D58
	add r5, r8
	ldr r0, [sp, #8]
	movs r1, #0xcc
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r6, #3
_080BD330:
	ldrh r3, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080BD34C
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080BD374
	.align 2, 0
_080BD344: .4byte 0x030046A0
_080BD348: .4byte 0x00000D58
_080BD34C:
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r5]
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x12
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r5, #2]
_080BD374:
	adds r4, #2
	adds r5, #0x60
	adds r2, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080BD330
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
