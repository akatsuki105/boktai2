	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08172868 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817286C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0817286E
	.align 2, 0
_08172868: .4byte 0x0000046C
_0817286C:
	movs r0, #0
_0817286E:
	cmp r0, #0
	beq _081728B4
	ldr r3, _081728E0 @ =0x0000100C
	adds r0, r6, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r7, _081728E4 @ =0x00001010
	adds r0, r6, r7
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r7, _081728E8 @ =0x0000046D
	adds r0, r5, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081728EC @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_081776ac
_081728B4:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081728F0 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081728F8
	ldr r0, _081728F4 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08172908
	.align 2, 0
_081728E0: .4byte 0x0000100C
_081728E4: .4byte 0x00001010
_081728E8: .4byte 0x0000046D
_081728EC: .4byte 0x00000553
_081728F0: .4byte 0x0000A02F
_081728F4: .4byte 0x00000482
_081728F8:
	ldr r1, _0817292C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08172908
	movs r0, #1
	strh r0, [r2]
_08172908:
	ldr r3, _08172930 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172934
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
	b _0817294C
	.align 2, 0
_0817292C: .4byte 0x00000482
_08172930: .4byte 0x0000025D
_08172934:
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
_0817294C:
	ldr r1, _08172984 @ =0x000004A4
	adds r0, r5, r1
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
	bge _0817296E
	rsbs r2, r2, #0
_0817296E:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08172988
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0817297C
	rsbs r2, r2, #0
_0817297C:
	cmp r2, #0x20
	bgt _08172988
	movs r0, #1
	b _081729F2
	.align 2, 0
_08172984: .4byte 0x000004A4
_08172988:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08172994
	cmp r1, #0
	beq _081729F0
_08172994:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _081729B8 @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081729BC
	asrs r1, r0, #0xc
	b _081729C2
	.align 2, 0
_081729B8: .4byte gSineTable
_081729BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081729C2:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081729E0 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _081729E4
	asrs r1, r0, #0xc
	b _081729EA
	.align 2, 0
_081729E0: .4byte gSineTable
_081729E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081729EA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_081729F0:
	movs r0, #0
_081729F2:
	cmp r0, #0
	beq _08172A9C
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08172A4C @ =0x000004A4
	adds r0, r5, r1
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08172A54
	ldr r3, _08172A50 @ =0xFFFFFF00
	adds r1, r1, r3
	b _08172A62
	.align 2, 0
_08172A4C: .4byte 0x000004A4
_08172A50: .4byte 0xFFFFFF00
_08172A54:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08172A62
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08172A62:
	cmp r1, #0
	bge _08172A68
	rsbs r1, r1, #0
_08172A68:
	cmp r1, #0x20
	ble _08172A9C
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08172A94 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _08172A98 @ =0x0000046A
	adds r0, r5, r7
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	b _08172B3E
	.align 2, 0
_08172A94: .4byte 0x00000469
_08172A98: .4byte 0x0000046A
_08172A9C:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08178640
	ldr r0, _08172AC4 @ =0x0000101C
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08172AC8
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0xc
	bl FUN_08177d34
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08172AD6
	.align 2, 0
_08172AC4: .4byte 0x0000101C
_08172AC8:
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
_08172AD6:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	movs r2, #0xfb
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0x3c
	bls _08172B30
	movs r2, #0x12
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r7, _08172B20 @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r1, [r0]
	ldr r0, _08172B24 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08172B28 @ =0x00000FA6
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08172B2C @ =0x00000F96
	adds r0, r6, r2
	strb r1, [r0]
	b _08172B3E
	.align 2, 0
_08172B20: .4byte 0x00000469
_08172B24: .4byte 0x0000046C
_08172B28: .4byte 0x00000FA6
_08172B2C: .4byte 0x00000F96
_08172B30:
	adds r0, #1
	strh r0, [r1]
	ldr r3, _08172B48 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08172B3E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08172B48: .4byte 0x00000484
