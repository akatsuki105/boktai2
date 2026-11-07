	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08162D30 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162D34
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162D36
	.align 2, 0
_08162D30: .4byte 0x0000046D
_08162D34:
	movs r0, #0
_08162D36:
	cmp r0, #0
	beq _08162D54
	adds r0, r5, #0
	movs r1, #1
	bl Enemy_PlayAnimNoFacing
	ldr r0, _08162D9C @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
_08162D54:
	ldr r1, _08162DA0 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08162DE0
	ldr r2, _08162DA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x6f
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08162DA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x17
	bgt _08162DB8
	ldr r3, _08162DAC @ =FUN_08162df4
	movs r2, #0
	ldr r0, _08162DB0 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08162DB4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r3, [r0]
	b _08162DD8
	.align 2, 0
_08162D9C: .4byte 0x00000482
_08162DA0: .4byte 0x0000046E
_08162DA4: .4byte 0x030046B8
_08162DA8: .4byte 0x0203B400
_08162DAC: .4byte FUN_08162df4
_08162DB0: .4byte 0x0000046D
_08162DB4: .4byte 0x0000046B
_08162DB8:
	ldr r4, _08162DE8 @ =FUN_08162d18
	movs r3, #0x28
	ldr r0, _08162DEC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08162DF0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
_08162DD8:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08162DE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08162DE8: .4byte FUN_08162d18
_08162DEC: .4byte 0x0000046D
_08162DF0: .4byte 0x0000046B
