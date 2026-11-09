	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08172B6C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08172B70
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08172B72
	.align 2, 0
_08172B6C: .4byte 0x0000046C
_08172B70:
	movs r0, #0
_08172B72:
	cmp r0, #0
	beq _08172BD0
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08172C0C @ =0x0000046D
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
	bl FUN_081776ac
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _08172C10 @ =0x00001021
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #5
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_08175898
_08172BD0:
	ldr r4, _08172C14 @ =0x00000544
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _08172BDE
	movs r0, #1
	strh r0, [r1]
_08172BDE:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08172C18 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08172C20
	ldr r3, _08172C1C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08172C30
	.align 2, 0
_08172C0C: .4byte 0x0000046D
_08172C10: .4byte 0x00001021
_08172C14: .4byte 0x00000544
_08172C18: .4byte 0x0000A02F
_08172C1C: .4byte 0x00000482
_08172C20:
	ldr r4, _08172C54 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08172C30
	movs r0, #1
	strh r0, [r2]
_08172C30:
	ldr r1, _08172C58 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08172C5C
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
	b _08172C74
	.align 2, 0
_08172C54: .4byte 0x00000482
_08172C58: .4byte 0x0000025D
_08172C5C:
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
_08172C74:
	ldr r2, _08172CAC @ =0x000004A4
	adds r0, r5, r2
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
	bge _08172C96
	rsbs r2, r2, #0
_08172C96:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08172CB0
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08172CA4
	rsbs r2, r2, #0
_08172CA4:
	cmp r2, #0x20
	bgt _08172CB0
	movs r0, #1
	b _08172D1A
	.align 2, 0
_08172CAC: .4byte 0x000004A4
_08172CB0:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08172CBC
	cmp r1, #0
	beq _08172D18
_08172CBC:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _08172CE0 @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08172CE4
	asrs r1, r0, #0xc
	b _08172CEA
	.align 2, 0
_08172CE0: .4byte gSineTable
_08172CE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08172CEA:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08172D08 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _08172D0C
	asrs r1, r0, #0xc
	b _08172D12
	.align 2, 0
_08172D08: .4byte gSineTable
_08172D0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08172D12:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08172D18:
	movs r0, #0
_08172D1A:
	cmp r0, #0
	beq _08172D64
	adds r0, r5, #0
	bl FUN_08175898
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08172D8C @ =0x000004A4
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
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_08172D64:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08178640
	ldr r3, _08172D90 @ =0x0000101C
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _08172D94
	subs r3, #0x1c
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0xc
	bl FUN_08177d34
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08172DA2
	.align 2, 0
_08172D8C: .4byte 0x000004A4
_08172D90: .4byte 0x0000101C
_08172D94:
	movs r3, #0xc8
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_08177d34
_08172DA2:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08177890
	ldr r4, _08172DE0 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	cmp r0, #0x50
	ble _08172DE8
	movs r2, #8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08172DE4 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #0x1a
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08172DE0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08172DEC
	.align 2, 0
_08172DE0: .4byte 0x00000484
_08172DE4: .4byte 0x00000469
_08172DE8:
	adds r0, #1
	str r0, [r1]
_08172DEC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
