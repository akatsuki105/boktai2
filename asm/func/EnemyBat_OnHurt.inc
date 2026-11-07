	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813E964
	b _0813F04A
_0813E964:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0813E972
	b _0813F04A
_0813E972:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x40
	add r0, r8
	mov sb, r0
	cmp r2, #0
	beq _0813E988
	b _0813F00A
_0813E988:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0813E9B4
	ldr r3, _0813E9B0 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813E9A0
	b _0813F00A
_0813E9A0:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _0813F00A
	.align 2, 0
_0813E9B0: .4byte 0x0000048C
_0813E9B4:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0813E9C4
	b _0813F00A
_0813E9C4:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0813E9D2
	b _0813ECDC
_0813E9D2:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _0813E9E2
	b _0813F00A
_0813E9E2:
	ldr r2, _0813EA74 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0813E9F6
	b _0813F00A
_0813E9F6:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0813EA04
	b _0813F00A
_0813EA04:
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
	bne _0813EA1C
	b _0813EB64
_0813EA1C:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0813EA84
	ands r3, r1
	cmp r3, #0
	beq _0813EA84
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813EA44
	rsbs r1, r1, #0
_0813EA44:
	cmp r1, #0x20
	bgt _0813EA84
	ldrh r0, [r7, #0x3c]
	ldr r3, _0813EA78 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _0813EA7C @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0813EA80 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0813F00A
	.align 2, 0
_0813EA74: .4byte 0x0000A007
_0813EA78: .4byte 0x000004BE
_0813EA7C: .4byte 0x0000048C
_0813EA80: .4byte 0x0000044E
_0813EA84:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0813EAAC @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813EAB4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EAB0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EAAC: .4byte 0x0000048A
_0813EAB0: .4byte 0x03002BE0
_0813EAB4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813EAD0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EACC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EACC: .4byte 0x03002BE0
_0813EAD0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813EAEC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813EAE8 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EAE8: .4byte 0x03002BE0
_0813EAEC:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813EB08
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EB04 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EB04: .4byte 0x03002BE0
_0813EB08:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813EB1A
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0813EB22
_0813EB1A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813EB24
_0813EB22:
	movs r3, #1
_0813EB24:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _0813EB44
	b _0813EC98
_0813EB44:
	movs r1, #2
	ldr r3, _0813EB58 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EB5C
	movs r0, #1
	b _0813EB5E
	.align 2, 0
_0813EB58: .4byte 0x00000474
_0813EB5C:
	movs r0, #0
_0813EB5E:
	cmp r0, #0
	bne _0813EC3E
	b _0813EC54
_0813EB64:
	mov r3, r8
	strh r2, [r3, #0x3e]
	ldr r1, _0813EB8C @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0813EB94
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EB90 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EB8C: .4byte 0x0000048A
_0813EB90: .4byte 0x03002BE0
_0813EB94:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813EBB0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EBAC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EBAC: .4byte 0x03002BE0
_0813EBB0:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0813EBCC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813EBC8 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EBC8: .4byte 0x03002BE0
_0813EBCC:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813EBE8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EBE4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EBE4: .4byte 0x03002BE0
_0813EBE8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813EBFA
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0813EC02
_0813EBFA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813EC04
_0813EC02:
	movs r3, #1
_0813EC04:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _0813EC98
	movs r1, #2
	ldr r3, _0813EC34 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EC38
	movs r0, #1
	b _0813EC3A
	.align 2, 0
_0813EC34: .4byte 0x00000474
_0813EC38:
	movs r0, #0
_0813EC3A:
	cmp r0, #0
	beq _0813EC54
_0813EC3E:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EC50 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813EC60
	.align 2, 0
_0813EC50: .4byte 0x03002BE0
_0813EC54:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0813EC98
_0813EC60:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
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
_0813EC98:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813ECC4
	ldr r0, _0813ECD4 @ =0x0000024E
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
	bls _0813ECC4
	strh r1, [r2]
_0813ECC4:
	ldr r0, _0813ECD8 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	add r1, r8
	mov sb, r1
	b _0813F00A
	.align 2, 0
_0813ECD4: .4byte 0x0000024E
_0813ECD8: .4byte 0x0000048C
_0813ECDC:
	ldr r0, _0813ECF0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813ECF4
	movs r0, #1
	b _0813ECF6
	.align 2, 0
_0813ECF0: .4byte 0x030047A4
_0813ECF4:
	movs r0, #0
_0813ECF6:
	cmp r0, #0
	beq _0813ED04
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _0813ED0C
_0813ED04:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
_0813ED0C:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0813ED44 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0813ED48 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0813ED3A
	cmp r2, #0x17
	bne _0813ED4C
_0813ED3A:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0813ED6C
	.align 2, 0
_0813ED44: .4byte 0x0000048C
_0813ED48: .4byte 0x000001DF
_0813ED4C:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0813ED3A
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0813ED9C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813ED6C
	movs r1, #0
_0813ED6C:
	mov r0, r8
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
	beq _0813EDAA
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _0813EDA0
	asrs r0, r0, #1
	b _0813EDA6
	.align 2, 0
_0813ED9C: .4byte 0x00000187
_0813EDA0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0813EDA6:
	mov r3, sb
	strh r0, [r3]
_0813EDAA:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0813EDC8
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0813EDC4 @ =0x000001DD
	adds r1, r6, r4
	b _0813EE3C
	.align 2, 0
_0813EDC4: .4byte 0x000001DD
_0813EDC8:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldrh r1, [r7, #0xc]
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
	bne _0813EE28
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0813EE28
	ldr r2, _0813EE18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813EE1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0813EE20 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0813EE24 @ =0x000001DD
	adds r1, r6, r4
	b _0813EE3C
	.align 2, 0
_0813EE18: .4byte 0x030046B8
_0813EE1C: .4byte 0x000003FF
_0813EE20: .4byte 0x0203B400
_0813EE24: .4byte 0x000001DD
_0813EE28:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0813EE5C @ =0x000001DD
	adds r1, r6, r3
_0813EE3C:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813EE64
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EE60 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EE5C: .4byte 0x000001DD
_0813EE60: .4byte 0x03002BE0
_0813EE64:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813EE80
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813EE7C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EE7C: .4byte 0x03002BE0
_0813EE80:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813EE9C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EE98 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EE98: .4byte 0x03002BE0
_0813EE9C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813EEB8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EEB4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EEB4: .4byte 0x03002BE0
_0813EEB8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813EECA
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813EED2
_0813EECA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813EED4
_0813EED2:
	movs r3, #1
_0813EED4:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0813EF04 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0813EF6C
	movs r1, #2
	ldr r2, _0813EF08 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EF0C
	movs r0, #1
	b _0813EF0E
	.align 2, 0
_0813EF04: .4byte 0x0000049C
_0813EF08: .4byte 0x00000474
_0813EF0C:
	movs r0, #0
_0813EF0E:
	cmp r0, #0
	beq _0813EF28
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EF24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813EF34
	.align 2, 0
_0813EF24: .4byte 0x03002BE0
_0813EF28:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813EF6C
_0813EF34:
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
_0813EF6C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0813EFA0
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0813EFA0
	ldr r3, _0813EFB8 @ =0x0000024E
	adds r2, r6, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0813EFA0
	strh r1, [r2]
_0813EFA0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0813EFBC @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0813EFC0 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EFC4
	movs r0, #1
	b _0813EFC6
	.align 2, 0
_0813EFB8: .4byte 0x0000024E
_0813EFBC: .4byte 0x030046A0
_0813EFC0: .4byte 0x00000934
_0813EFC4:
	movs r0, #0
_0813EFC6:
	ldr r1, _0813F05C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0813EFE0
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_0813EFE0:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	strh r0, [r4]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r7, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813F00A:
	ldr r2, _0813F060 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813F064 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813F068 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	ldrh r2, [r3]
	movs r1, #0xf
	ands r0, r1
	subs r2, r2, r0
	cmp r2, #0x14
	bge _0813F02E
	movs r2, #0x14
_0813F02E:
	mov r4, sb
	strh r2, [r4]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #9
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0813F04A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F05C: .4byte 0x0000048A
_0813F060: .4byte 0x030046B8
_0813F064: .4byte 0x000003FF
_0813F068: .4byte 0x0203B400
