	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08188A1C
	b _081890EC
_08188A1C:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x20
	ldr r2, _08188A38 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188A3C
	movs r0, #1
	b _08188A3E
	.align 2, 0
_08188A38: .4byte 0x00000F2C
_08188A3C:
	movs r0, #0
_08188A3E:
	cmp r0, #0
	beq _08188A44
	b _081890EC
_08188A44:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08188A54
	b _081890D8
_08188A54:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _08188A7C
	ldr r4, _08188A78 @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08188A6C
	b _081890D8
_08188A6C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081890D8
	.align 2, 0
_08188A78: .4byte 0x0000048C
_08188A7C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08188A8C
	b _081890D8
_08188A8C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08188A9C
	b _08188DA8
_08188A9C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08188AAE
	b _081890D8
_08188AAE:
	ldr r2, _08188B40 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08188AC2
	b _081890D8
_08188AC2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08188AD0
	b _081890D8
_08188AD0:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _08188AE8
	b _08188C30
_08188AE8:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08188B50
	ands r3, r1
	cmp r3, #0
	beq _08188B50
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08188B0E
	rsbs r1, r1, #0
_08188B0E:
	cmp r1, #0x20
	bgt _08188B50
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08188B44 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08188B48 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08188B4C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081890D8
	.align 2, 0
_08188B40: .4byte 0x0000A007
_08188B44: .4byte 0x000004BE
_08188B48: .4byte 0x0000048C
_08188B4C: .4byte 0x0000044E
_08188B50:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08188B78 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08188B80
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188B7C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188B78: .4byte 0x0000048A
_08188B7C: .4byte 0x03002BE0
_08188B80:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08188B9C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08188B98 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188B98: .4byte 0x03002BE0
_08188B9C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08188BB8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08188BB4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188BB4: .4byte 0x03002BE0
_08188BB8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08188BD4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08188BD0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08188BEE
	.align 2, 0
_08188BD0: .4byte 0x03002BE0
_08188BD4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08188BE6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08188BEE
_08188BE6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08188BF0
_08188BEE:
	movs r3, #1
_08188BF0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08188C24 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08188C12
	b _08188D68
_08188C12:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188C28
	movs r0, #1
	b _08188C2A
	.align 2, 0
_08188C24: .4byte 0x0000049C
_08188C28:
	movs r0, #0
_08188C2A:
	cmp r0, #0
	bne _08188D0E
	b _08188D24
_08188C30:
	strh r2, [r7, #0x3e]
	ldr r1, _08188C58 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08188C60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188C5C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188C58: .4byte 0x0000048A
_08188C5C: .4byte 0x03002BE0
_08188C60:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08188C7C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08188C78 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188C78: .4byte 0x03002BE0
_08188C7C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08188C98
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08188C94 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188C94: .4byte 0x03002BE0
_08188C98:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08188CB4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08188CB0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08188CCE
	.align 2, 0
_08188CB0: .4byte 0x03002BE0
_08188CB4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08188CC6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08188CCE
_08188CC6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08188CD0
_08188CCE:
	movs r3, #1
_08188CD0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08188D04 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08188D68
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188D08
	movs r0, #1
	b _08188D0A
	.align 2, 0
_08188D04: .4byte 0x0000049C
_08188D08:
	movs r0, #0
_08188D0A:
	cmp r0, #0
	beq _08188D24
_08188D0E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188D20 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08188D30
	.align 2, 0
_08188D20: .4byte 0x03002BE0
_08188D24:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08188D68
_08188D30:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08188D68:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08188D94
	ldr r5, _08188DA0 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08188D94
	strh r1, [r2]
_08188D94:
	ldr r5, _08188DA4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081890D8
	.align 2, 0
_08188DA0: .4byte 0x0000024E
_08188DA4: .4byte 0x0000048C
_08188DA8:
	ldr r0, _08188DBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08188DC0
	movs r0, #1
	b _08188DC2
	.align 2, 0
_08188DBC: .4byte 0x030047A4
_08188DC0:
	movs r0, #0
_08188DC2:
	cmp r0, #0
	beq _08188DD0
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08188DD8
_08188DD0:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08188DD8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08188E10 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08188E14 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08188E06
	cmp r2, #0x17
	bne _08188E18
_08188E06:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08188E3A
	.align 2, 0
_08188E10: .4byte 0x0000048C
_08188E14: .4byte 0x000001DF
_08188E18:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08188E06
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08188E68 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08188E3A
	movs r1, #0
_08188E3A:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08188E76
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08188E6C
	asrs r0, r0, #1
	b _08188E72
	.align 2, 0
_08188E68: .4byte 0x00000187
_08188E6C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08188E72:
	mov r2, sb
	strh r0, [r2]
_08188E76:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08188E94
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08188E90 @ =0x000001DD
	adds r1, r6, r4
	b _08188F08
	.align 2, 0
_08188E90: .4byte 0x000001DD
_08188E94:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08188EF4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08188EF4
	ldr r2, _08188EE4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08188EE8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08188EEC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08188EF0 @ =0x000001DD
	adds r1, r6, r4
	b _08188F08
	.align 2, 0
_08188EE4: .4byte 0x030046B8
_08188EE8: .4byte 0x000003FF
_08188EEC: .4byte 0x0203B400
_08188EF0: .4byte 0x000001DD
_08188EF4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08188F28 @ =0x000001DD
	adds r1, r6, r3
_08188F08:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08188F30
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08188F2C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F28: .4byte 0x000001DD
_08188F2C: .4byte 0x03002BE0
_08188F30:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08188F4C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08188F48 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F48: .4byte 0x03002BE0
_08188F4C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08188F68
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188F64 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F64: .4byte 0x03002BE0
_08188F68:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08188F84
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08188F80 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08188F9E
	.align 2, 0
_08188F80: .4byte 0x03002BE0
_08188F84:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08188F96
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08188F9E
_08188F96:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08188FA0
_08188F9E:
	movs r3, #1
_08188FA0:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _08188FD4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0818903C
	movs r1, #2
	ldr r2, _08188FD8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08188FDC
	movs r0, #1
	b _08188FDE
	.align 2, 0
_08188FD4: .4byte 0x0000049C
_08188FD8: .4byte 0x00000474
_08188FDC:
	movs r0, #0
_08188FDE:
	cmp r0, #0
	beq _08188FF8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08188FF4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08189004
	.align 2, 0
_08188FF4: .4byte 0x03002BE0
_08188FF8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0818903C
_08189004:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0818903C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08189070
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08189070
	ldr r0, _08189088 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08189070
	strh r1, [r2]
_08189070:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0818908C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08189090 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08189094
	movs r0, #1
	b _08189096
	.align 2, 0
_08189088: .4byte 0x0000024E
_0818908C: .4byte 0x030046A0
_08189090: .4byte 0x00000934
_08189094:
	movs r0, #0
_08189096:
	ldr r1, _081890FC @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081890AE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081890AE:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081890D8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r2, _08189100 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
_081890EC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081890FC: .4byte 0x0000048A
_08189100: .4byte 0x00000F2C
