	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08162E8C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162E90
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162E92
	.align 2, 0
_08162E8C: .4byte 0x0000046D
_08162E90:
	movs r0, #0
_08162E92:
	cmp r0, #0
	beq _08162EB0
	adds r0, r5, #0
	movs r1, #0x11
	bl Enemy_PlayAnimNoFacing
	ldr r0, _08162EE8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
_08162EB0:
	ldr r1, _08162EEC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08162EE2
	ldr r4, _08162EF0 @ =FUN_08162fa8
	movs r3, #0x21
	ldr r0, _08162EF4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08162EF8 @ =0x0000046B
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
_08162EE2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08162EE8: .4byte 0x00000482
_08162EEC: .4byte 0x0000046E
_08162EF0: .4byte FUN_08162fa8
_08162EF4: .4byte 0x0000046D
_08162EF8: .4byte 0x0000046B
