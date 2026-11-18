	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r0, #6]
	ands r0, r1
	cmp r0, #0
	beq _081C790C
	b _081C7FA0
_081C790C:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081C791C
	b _081C7FA0
_081C791C:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C7944
	ldr r3, _081C7940 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C7934
	b _081C7FA0
_081C7934:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081C7FA0
	.align 2, 0
_081C7940: .4byte 0x0000048C
_081C7944:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081C7954
	b _081C7FA0
_081C7954:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081C7964
	b _081C7C70
_081C7964:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081C7976
	b _081C7FA0
_081C7976:
	ldr r2, _081C7A08 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081C798A
	b _081C7FA0
_081C798A:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C7998
	b _081C7FA0
_081C7998:
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
	bne _081C79B0
	b _081C7AF8
_081C79B0:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081C7A18
	ands r3, r1
	cmp r3, #0
	beq _081C7A18
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081C79D6
	rsbs r1, r1, #0
_081C79D6:
	cmp r1, #0x20
	bgt _081C7A18
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081C7A0C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081C7A10 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081C7A14 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081C7FA0
	.align 2, 0
_081C7A08: .4byte 0x0000A007
_081C7A0C: .4byte 0x000004BE
_081C7A10: .4byte 0x0000048C
_081C7A14: .4byte 0x0000044E
_081C7A18:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081C7A40 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081C7A48
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7A44 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A40: .4byte 0x0000048A
_081C7A44: .4byte 0x03002BE0
_081C7A48:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081C7A64
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081C7A60 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A60: .4byte 0x03002BE0
_081C7A64:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081C7A80
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081C7A7C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A7C: .4byte 0x03002BE0
_081C7A80:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081C7A9C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081C7A98 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A98: .4byte 0x03002BE0
_081C7A9C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081C7AAE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081C7AB6
_081C7AAE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081C7AB8
_081C7AB6:
	movs r3, #1
_081C7AB8:
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
	ldr r5, _081C7AEC @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081C7ADA
	b _081C7C30
_081C7ADA:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7AF0
	movs r0, #1
	b _081C7AF2
	.align 2, 0
_081C7AEC: .4byte 0x0000049C
_081C7AF0:
	movs r0, #0
_081C7AF2:
	cmp r0, #0
	bne _081C7BD6
	b _081C7BEC
_081C7AF8:
	strh r2, [r7, #0x3e]
	ldr r1, _081C7B20 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081C7B28
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7B24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B20: .4byte 0x0000048A
_081C7B24: .4byte 0x03002BE0
_081C7B28:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081C7B44
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081C7B40 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B40: .4byte 0x03002BE0
_081C7B44:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081C7B60
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081C7B5C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B5C: .4byte 0x03002BE0
_081C7B60:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081C7B7C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081C7B78 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B78: .4byte 0x03002BE0
_081C7B7C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081C7B8E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081C7B96
_081C7B8E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081C7B98
_081C7B96:
	movs r3, #1
_081C7B98:
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
	ldr r5, _081C7BCC @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081C7C30
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7BD0
	movs r0, #1
	b _081C7BD2
	.align 2, 0
_081C7BCC: .4byte 0x0000049C
_081C7BD0:
	movs r0, #0
_081C7BD2:
	cmp r0, #0
	beq _081C7BEC
_081C7BD6:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7BE8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081C7BF8
	.align 2, 0
_081C7BE8: .4byte 0x03002BE0
_081C7BEC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081C7C30
_081C7BF8:
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
_081C7C30:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081C7C5C
	ldr r5, _081C7C68 @ =0x0000024E
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
	bls _081C7C5C
	strh r1, [r2]
_081C7C5C:
	ldr r5, _081C7C6C @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081C7FA0
	.align 2, 0
_081C7C68: .4byte 0x0000024E
_081C7C6C: .4byte 0x0000048C
_081C7C70:
	ldr r0, _081C7C84 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C7C88
	movs r0, #1
	b _081C7C8A
	.align 2, 0
_081C7C84: .4byte 0x030047A4
_081C7C88:
	movs r0, #0
_081C7C8A:
	cmp r0, #0
	beq _081C7C98
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081C7CA0
_081C7C98:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081C7CA0:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081C7CD8 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081C7CDC @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081C7CCE
	cmp r2, #0x17
	bne _081C7CE0
_081C7CCE:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081C7D02
	.align 2, 0
_081C7CD8: .4byte 0x0000048C
_081C7CDC: .4byte 0x000001DF
_081C7CE0:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081C7CCE
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081C7D30 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081C7D02
	movs r1, #0
_081C7D02:
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
	beq _081C7D3E
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081C7D34
	asrs r0, r0, #1
	b _081C7D3A
	.align 2, 0
_081C7D30: .4byte 0x00000187
_081C7D34:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081C7D3A:
	mov r2, sb
	strh r0, [r2]
_081C7D3E:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081C7D5C
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081C7D58 @ =0x000001DD
	adds r1, r6, r4
	b _081C7DD0
	.align 2, 0
_081C7D58: .4byte 0x000001DD
_081C7D5C:
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
	bne _081C7DBC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081C7DBC
	ldr r2, _081C7DAC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081C7DB0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081C7DB4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081C7DB8 @ =0x000001DD
	adds r1, r6, r4
	b _081C7DD0
	.align 2, 0
_081C7DAC: .4byte 0x030046B8
_081C7DB0: .4byte 0x000003FF
_081C7DB4: .4byte 0x0203B400
_081C7DB8: .4byte 0x000001DD
_081C7DBC:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081C7DF0 @ =0x000001DD
	adds r1, r6, r3
_081C7DD0:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081C7DF8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081C7DF4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7DF0: .4byte 0x000001DD
_081C7DF4: .4byte 0x03002BE0
_081C7DF8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081C7E14
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081C7E10 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7E10: .4byte 0x03002BE0
_081C7E14:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081C7E30
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7E2C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7E2C: .4byte 0x03002BE0
_081C7E30:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081C7E4C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081C7E48 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7E48: .4byte 0x03002BE0
_081C7E4C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081C7E5E
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081C7E66
_081C7E5E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081C7E68
_081C7E66:
	movs r3, #1
_081C7E68:
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
	ldr r5, _081C7E9C @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081C7F04
	movs r1, #2
	ldr r2, _081C7EA0 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7EA4
	movs r0, #1
	b _081C7EA6
	.align 2, 0
_081C7E9C: .4byte 0x0000049C
_081C7EA0: .4byte 0x00000474
_081C7EA4:
	movs r0, #0
_081C7EA6:
	cmp r0, #0
	beq _081C7EC0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7EBC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081C7ECC
	.align 2, 0
_081C7EBC: .4byte 0x03002BE0
_081C7EC0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081C7F04
_081C7ECC:
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
_081C7F04:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081C7F38
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C7F38
	ldr r0, _081C7F50 @ =0x0000024E
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
	bls _081C7F38
	strh r1, [r2]
_081C7F38:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081C7F54 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081C7F58 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7F5C
	movs r0, #1
	b _081C7F5E
	.align 2, 0
_081C7F50: .4byte 0x0000024E
_081C7F54: .4byte 0x030046A0
_081C7F58: .4byte 0x00000934
_081C7F5C:
	movs r0, #0
_081C7F5E:
	ldr r1, _081C7FB0 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081C7F76
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081C7F76:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
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
_081C7FA0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C7FB0: .4byte 0x0000048A
