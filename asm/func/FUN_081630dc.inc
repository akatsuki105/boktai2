	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081630F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081630F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081630FA
	.align 2, 0
_081630F4: .4byte 0x0000046D
_081630F8:
	movs r0, #0
_081630FA:
	cmp r0, #0
	beq _08163188
	ldr r1, _0816312C @ =0x000004FC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _08163130 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0816313C
	ldr r1, _08163134 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r0, _08163138 @ =0x0000046E
	adds r4, r5, r0
	b _08163184
	.align 2, 0
_0816312C: .4byte 0x000004FC
_08163130: .4byte 0x0000025D
_08163134: .4byte 0x000004B7
_08163138: .4byte 0x0000046E
_0816313C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, #1
	ldr r1, _081631C4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081631C8 @ =0x0000046E
	adds r4, r5, r0
	cmp r1, r2
	bne _08163164
	ldrb r0, [r4]
	cmp r0, #0
	bne _08163164
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08163188
_08163164:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
_08163184:
	movs r0, #0
	strb r0, [r4]
_08163188:
	ldr r1, _081631C8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081631BA
	ldr r4, _081631CC @ =FUN_081631d8
	movs r3, #0x23
	ldr r0, _081631D0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081631D4 @ =0x0000046B
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
_081631BA:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081631C4: .4byte 0x000004B7
_081631C8: .4byte 0x0000046E
_081631CC: .4byte FUN_081631d8
_081631D0: .4byte 0x0000046D
_081631D4: .4byte 0x0000046B
