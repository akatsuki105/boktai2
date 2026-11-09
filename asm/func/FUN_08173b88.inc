	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08173BB0 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08173BB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08173BB6
	.align 2, 0
_08173BB0: .4byte 0x0000046C
_08173BB4:
	movs r0, #0
_08173BB6:
	cmp r0, #0
	bne _08173BBC
	b _08173D24
_08173BBC:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08173C30 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	ldr r2, _08173C34 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08173C38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08173C3C @ =0x0203B400
	adds r0, r0, r4
	movs r2, #0xff
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08173C74
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r7, r4
	ldrb r4, [r0]
	movs r5, #0x14
	ldr r1, _08173C40 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173C44
	asrs r2, r0, #0xc
	b _08173C4A
	.align 2, 0
_08173C30: .4byte 0x0000046D
_08173C34: .4byte 0x030046B8
_08173C38: .4byte 0x000003FF
_08173C3C: .4byte 0x0203B400
_08173C40: .4byte gSineTable
_08173C44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173C4A:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173C62
	asrs r0, r0, #0xc
	b _08173C68
_08173C62:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08173C68:
	strh r0, [r3, #4]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	b _08173CD8
_08173C74:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x20
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r7, r0
	ands r3, r2
	movs r5, #0x14
	ldr r1, _08173CA4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173CA8
	asrs r2, r0, #0xc
	b _08173CAE
	.align 2, 0
_08173CA4: .4byte gSineTable
_08173CA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08173CAE:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08173CC6
	asrs r0, r0, #0xc
	b _08173CCC
_08173CC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08173CCC:
	strh r0, [r4, #4]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x20
_08173CD8:
	strb r0, [r7, #5]
	ldr r0, _08173D5C @ =0x00000472
	adds r4, r7, r0
	ldr r1, _08173D60 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	movs r5, #0
	strh r0, [r7, #0xa]
	adds r1, r7, #0
	adds r1, #8
	mov r0, r8
	bl FUN_08177f7c
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x2a
	strh r0, [r1]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r5, [r0]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r0, #4
	ldr r2, _08173D64 @ =0x00001008
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08173D68 @ =0x000003E6
	bl PlaySound_082406e0
_08173D24:
	ldr r2, _08173D6C @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #9
	bgt _08173D74
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173D70 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r6, r7, r3
_08173D4A:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #3
	ble _08173D4A
	b _08173E2C
	.align 2, 0
_08173D5C: .4byte 0x00000472
_08173D60: .4byte 0xFFFFFF00
_08173D64: .4byte 0x00001008
_08173D68: .4byte 0x000003E6
_08173D6C: .4byte 0x00000484
_08173D70: .4byte 0x05000002
_08173D74:
	cmp r0, #0x13
	bgt _08173DAC
	add r4, sp, #0xc
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173DA8 @ =0x05000002
	bl CpuSet
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r6, r7, r0
_08173D94:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08173D94
	b _08173E2C
	.align 2, 0
_08173DA8: .4byte 0x05000002
_08173DAC:
	cmp r0, #0x3b
	bgt _08173DE4
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173DE0 @ =0x05000002
	bl CpuSet
	movs r0, #0x40
	strh r0, [r4, #2]
	movs r5, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r6, r7, r1
_08173DCC:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	adds r5, #1
	cmp r5, #7
	ble _08173DCC
	b _08173E2C
	.align 2, 0
_08173DE0: .4byte 0x05000002
_08173DE4:
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r6, r7, r2
	cmp r0, #0x4f
	bgt _08173E2C
	add r4, sp, #0x1c
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08173E14 @ =0x05000002
	bl CpuSet
	movs r5, #0
_08173E00:
	cmp r5, #3
	bgt _08173E18
	movs r0, #0x54
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
	b _08173E26
	.align 2, 0
_08173E14: .4byte 0x05000002
_08173E18:
	movs r0, #0x94
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081779cc
_08173E26:
	adds r5, #1
	cmp r5, #7
	ble _08173E00
_08173E2C:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_08177d34
	mov r0, r8
	bl FUN_08176c60
	ldr r0, [r7, #0x44]
	ldr r0, [r0]
	movs r3, #1
	mov r8, r3
	ands r0, r3
	cmp r0, #0
	bne _08173E58
	movs r4, #0xaa
	lsls r4, r4, #2
	adds r0, r7, r4
	bl AuxShadow_Show
_08173E58:
	movs r0, #0x10
	ldr r1, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08173F10
	ldr r0, _08173EF8 @ =0xFFEFFFFF
	ands r1, r0
	str r1, [r6]
	adds r0, r7, #0
	bl FUN_08175898
	add r2, sp, #0x24
	adds r4, r7, #0
	adds r4, #8
	ldr r1, _08173EFC @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08176530
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	mov r3, r8
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r5, [r0]
	ldr r2, _08173F00 @ =0x00000469
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _08173F04 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r6, [r0]
	ldr r1, _08173F08 @ =0x0000046C
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, _08173F0C @ =0x00000145
	bl PlaySound_082406e0
	movs r3, #0xaa
	lsls r3, r3, #2
	adds r0, r7, r3
	bl AuxShadow_Hide
	b _08173F1A
	.align 2, 0
_08173EF8: .4byte 0xFFEFFFFF
_08173EFC: .4byte 0x000004A4
_08173F00: .4byte 0x00000469
_08173F04: .4byte 0x0000046A
_08173F08: .4byte 0x0000046C
_08173F0C: .4byte 0x00000145
_08173F10:
	ldr r4, _08173F28 @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08173F1A:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08173F28: .4byte 0x00000484
