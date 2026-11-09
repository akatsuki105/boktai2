	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08162FC0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162FC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162FC6
	.align 2, 0
_08162FC0: .4byte 0x0000046D
_08162FC4:
	movs r0, #0
_08162FC6:
	cmp r0, #0
	beq _0816307E
	ldr r1, _08162FF8 @ =0x000004FC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _08162FFC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08163008
	ldr r1, _08163000 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r2, _08163004 @ =0x0000046E
	adds r6, r5, r2
	b _0816304A
	.align 2, 0
_08162FF8: .4byte 0x000004FC
_08162FFC: .4byte 0x0000025D
_08163000: .4byte 0x000004B7
_08163004: .4byte 0x0000046E
_08163008:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _081630B8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081630BC @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0816302E
	ldrb r0, [r6]
	cmp r0, #0
	bne _0816302E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816304E
_0816302E:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0816304A:
	movs r0, #0
	strb r0, [r6]
_0816304E:
	ldr r2, _081630C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081630C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081630C8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldr r2, _081630CC @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	cmp r0, #0
	bne _08163074
	movs r0, #1
	strh r0, [r1]
_08163074:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r1, [r1]
	bl AuxAnim_SetAnimSpeed
_0816307E:
	ldr r1, _081630BC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081630B0
	ldr r4, _081630D0 @ =FUN_081630dc
	movs r3, #0x22
	ldr r2, _081630D4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081630D8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081630B0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081630B8: .4byte 0x000004B7
_081630BC: .4byte 0x0000046E
_081630C0: .4byte 0x030046B8
_081630C4: .4byte 0x000003FF
_081630C8: .4byte 0x0203B400
_081630CC: .4byte 0x00000482
_081630D0: .4byte FUN_081630dc
_081630D4: .4byte 0x0000046D
_081630D8: .4byte 0x0000046B
