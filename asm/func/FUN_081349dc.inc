	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081349FC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08134A00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08134A02
	.align 2, 0
_081349FC: .4byte 0x0000046C
_08134A00:
	movs r0, #0
_08134A02:
	cmp r0, #0
	beq _08134A5E
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08134A8C @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08136ac8
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08134A90 @ =0x00000B49
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _08134A94 @ =0x00000B48
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081355f0
_08134A5E:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08134AA4
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08134A98 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08134A9C @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08134AA0 @ =0x00000484
	b _08134CA4
	.align 2, 0
_08134A8C: .4byte 0x0000046D
_08134A90: .4byte 0x00000B49
_08134A94: .4byte 0x00000B48
_08134A98: .4byte 0x00000469
_08134A9C: .4byte 0x0000046A
_08134AA0: .4byte 0x00000484
_08134AA4:
	ldr r2, _08134AE0 @ =0x00000544
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _08134AB2
	movs r0, #1
	strh r0, [r1]
_08134AB2:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08134AE4 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08134AEC
	ldr r0, _08134AE8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08134AFC
	.align 2, 0
_08134AE0: .4byte 0x00000544
_08134AE4: .4byte 0x0000A02F
_08134AE8: .4byte 0x00000482
_08134AEC:
	ldr r1, _08134B20 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08134AFC
	movs r0, #1
	strh r0, [r2]
_08134AFC:
	ldr r3, _08134B24 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08134B28
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _08134B40
	.align 2, 0
_08134B20: .4byte 0x00000482
_08134B24: .4byte 0x0000025D
_08134B28:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_08134B40:
	ldr r4, _08134B78 @ =0x000004A4
	adds r0, r5, r4
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08134B62
	rsbs r2, r2, #0
_08134B62:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08134B7C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08134B70
	rsbs r2, r2, #0
_08134B70:
	cmp r2, #0x20
	bgt _08134B7C
	movs r0, #1
	b _08134BE6
	.align 2, 0
_08134B78: .4byte 0x000004A4
_08134B7C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08134B88
	cmp r1, #0
	beq _08134BE4
_08134B88:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _08134BAC @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08134BB0
	asrs r1, r0, #0xc
	b _08134BB6
	.align 2, 0
_08134BAC: .4byte gSineTable
_08134BB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08134BB6:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08134BD4 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08134BD8
	asrs r1, r0, #0xc
	b _08134BDE
	.align 2, 0
_08134BD4: .4byte gSineTable
_08134BD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08134BDE:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08134BE4:
	movs r0, #0
_08134BE6:
	cmp r0, #0
	beq _08134C30
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r3, _08134C58 @ =0x000004A4
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
_08134C30:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08137a30
	ldr r0, _08134C5C @ =0x00000B44
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08134C60
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081370f4
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08134C6C
	.align 2, 0
_08134C58: .4byte 0x000004A4
_08134C5C: .4byte 0x00000B44
_08134C60:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_081370f4
_08134C6C:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08136ca0
	ldr r1, _08134CB4 @ =0x00000484
	adds r2, r5, r1
	ldr r1, [r2]
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r1, r0
	ble _08134CC0
	adds r0, r5, #0
	bl FUN_081355f0
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08134CB8 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
_08134CA4:
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _08134CBC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08134CC4
	.align 2, 0
_08134CB4: .4byte 0x00000484
_08134CB8: .4byte 0x00000469
_08134CBC: .4byte 0x0000046C
_08134CC0:
	adds r0, r1, #1
	str r0, [r2]
_08134CC4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
