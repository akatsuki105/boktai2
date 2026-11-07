	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08163BD4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08163BD8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08163BDA
	.align 2, 0
_08163BD4: .4byte 0x0000046C
_08163BD8:
	movs r0, #0
_08163BDA:
	cmp r0, #0
	beq _08163C24
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r4, #1
	ldr r3, _08163C1C @ =0x0000046D
	adds r0, r5, r3
	movs r1, #0
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r1, [r5, #5]
	adds r0, r5, #0
	bl FUN_08164120
	ldr r3, _08163C20 @ =0x00000482
	adds r0, r5, r3
	strh r4, [r0]
	b _08163D88
	.align 2, 0
_08163C1C: .4byte 0x0000046D
_08163C20: .4byte 0x00000482
_08163C24:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08163C60 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08163C68
	ldr r0, _08163C64 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08163C78
	.align 2, 0
_08163C60: .4byte 0x0000A02F
_08163C64: .4byte 0x00000482
_08163C68:
	ldr r1, _08163C9C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08163C78
	movs r0, #1
	strh r0, [r2]
_08163C78:
	ldr r3, _08163CA0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08163CA4
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
	b _08163CBC
	.align 2, 0
_08163C9C: .4byte 0x00000482
_08163CA0: .4byte 0x0000025D
_08163CA4:
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
_08163CBC:
	ldr r1, _08163CF4 @ =0x000004A4
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
	bge _08163CDE
	rsbs r2, r2, #0
_08163CDE:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08163CF8
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08163CEC
	rsbs r2, r2, #0
_08163CEC:
	cmp r2, #0x20
	bgt _08163CF8
	movs r0, #1
	b _08163D62
	.align 2, 0
_08163CF4: .4byte 0x000004A4
_08163CF8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08163D04
	cmp r1, #0
	beq _08163D60
_08163D04:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _08163D28 @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08163D2C
	asrs r1, r0, #0xc
	b _08163D32
	.align 2, 0
_08163D28: .4byte gSineTable
_08163D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08163D32:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08163D50 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08163D54
	asrs r1, r0, #0xc
	b _08163D5A
	.align 2, 0
_08163D50: .4byte gSineTable
_08163D54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08163D5A:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08163D60:
	movs r0, #0
_08163D62:
	cmp r0, #0
	beq _08163D6E
	ldrb r1, [r5, #5]
	adds r0, r5, #0
	bl FUN_08164120
_08163D6E:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08163D90 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08163D88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08163D90: .4byte 0x00000484
