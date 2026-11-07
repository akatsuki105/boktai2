	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08162E0C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162E10
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08162E12
	.align 2, 0
_08162E0C: .4byte 0x0000046D
_08162E10:
	movs r0, #0
_08162E12:
	cmp r0, #0
	beq _08162E30
	ldr r0, _08162E4C @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efe38
_08162E30:
	ldr r0, _08162E50 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _08162E54 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _08162E58 @ =0x0203B400
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #7
	bgt _08162E5C
	movs r0, #0x10
	b _08162E62
	.align 2, 0
_08162E4C: .4byte 0x00000482
_08162E50: .4byte 0x030046B8
_08162E54: .4byte 0x000003FF
_08162E58: .4byte 0x0203B400
_08162E5C:
	cmp r0, #0xd
	bgt _08162E6E
	movs r0, #0x20
_08162E62:
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08162E6E:
	pop {r4}
	pop {r0}
	bx r0
