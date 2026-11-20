	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819AAC2
	b _0819B1FC
_0819AAC2:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819AAD2
	b _0819B14E
_0819AAD2:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0819AAFC
	ldr r3, _0819AAF8 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0819AAEA
	b _0819B14E
_0819AAEA:
	movs r0, #0
	mov r4, r8
	strh r1, [r4, #0x3e]
	mov r1, r8
	adds r1, #0x43
	strb r0, [r1]
	b _0819B14E
	.align 2, 0
_0819AAF8: .4byte 0x0000048C
_0819AAFC:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0819AB0C
	b _0819B14E
_0819AB0C:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0819AB1A
	b _0819AE20
_0819AB1A:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0819AB2A
	b _0819B14E
_0819AB2A:
	ldr r2, _0819ABBC @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0819AB3E
	b _0819B14E
_0819AB3E:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819AB4C
	b _0819B14E
_0819AB4C:
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
	bne _0819AB64
	b _0819ACAC
_0819AB64:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0819ABCC
	ands r3, r1
	cmp r3, #0
	beq _0819ABCC
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0819AB8C
	rsbs r1, r1, #0
_0819AB8C:
	cmp r1, #0x20
	bgt _0819ABCC
	ldrh r0, [r7, #0x3c]
	ldr r3, _0819ABC0 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r7, _0819ABC4 @ =0x0000048C
	adds r0, r6, r7
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r2, _0819ABC8 @ =0x0000044E
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r3, sl
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	b _0819B14E
	.align 2, 0
_0819ABBC: .4byte 0x0000A007
_0819ABC0: .4byte 0x000004BE
_0819ABC4: .4byte 0x0000048C
_0819ABC8: .4byte 0x0000044E
_0819ABCC:
	movs r1, #0
	mov r4, r8
	strh r1, [r4, #0x3e]
	ldr r2, _0819ABF4 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0819ABFC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819ABF8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819ABF4: .4byte 0x0000048A
_0819ABF8: .4byte 0x03002BE0
_0819ABFC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0819AC18
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819AC14 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819AC14: .4byte 0x03002BE0
_0819AC18:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0819AC34
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0819AC30 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819AC30: .4byte 0x03002BE0
_0819AC34:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0819AC50
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AC4C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819AC4C: .4byte 0x03002BE0
_0819AC50:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0819AC62
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0819AC6A
_0819AC62:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0819AC6C
_0819AC6A:
	movs r3, #1
_0819AC6C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r7, _0819ACA0 @ =0x0000049C
	adds r0, r6, r7
	str r1, [r0]
	cmp r3, #0
	bne _0819AC8C
	b _0819ADE0
_0819AC8C:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819ACA4
	movs r0, #1
	b _0819ACA6
	.align 2, 0
_0819ACA0: .4byte 0x0000049C
_0819ACA4:
	movs r0, #0
_0819ACA6:
	cmp r0, #0
	bne _0819AD86
	b _0819AD9C
_0819ACAC:
	mov r0, r8
	strh r2, [r0, #0x3e]
	ldr r1, _0819ACD4 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0819ACDC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819ACD8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819ACD4: .4byte 0x0000048A
_0819ACD8: .4byte 0x03002BE0
_0819ACDC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0819ACF8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819ACF4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819ACF4: .4byte 0x03002BE0
_0819ACF8:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0819AD14
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0819AD10 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819AD10: .4byte 0x03002BE0
_0819AD14:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0819AD30
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AD2C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819AD2C: .4byte 0x03002BE0
_0819AD30:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0819AD42
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0819AD4A
_0819AD42:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0819AD4C
_0819AD4A:
	movs r3, #1
_0819AD4C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r7, _0819AD7C @ =0x0000049C
	adds r0, r6, r7
	str r1, [r0]
	cmp r3, #0
	beq _0819ADE0
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819AD80
	movs r0, #1
	b _0819AD82
	.align 2, 0
_0819AD7C: .4byte 0x0000049C
_0819AD80:
	movs r0, #0
_0819AD82:
	cmp r0, #0
	beq _0819AD9C
_0819AD86:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AD98 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0819ADA8
	.align 2, 0
_0819AD98: .4byte 0x03002BE0
_0819AD9C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0819ADE0
_0819ADA8:
	ldr r1, [r0]
	movs r7, #8
	ldrsh r5, [r1, r7]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r7, #0xc
	ldrsh r0, [r6, r7]
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
_0819ADE0:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0819AE0C
	ldr r7, _0819AE18 @ =0x0000024E
	adds r2, r6, r7
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
	bls _0819AE0C
	strh r1, [r2]
_0819AE0C:
	ldr r7, _0819AE1C @ =0x0000048C
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	b _0819B14E
	.align 2, 0
_0819AE18: .4byte 0x0000024E
_0819AE1C: .4byte 0x0000048C
_0819AE20:
	ldr r0, _0819AE34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0819AE38
	movs r0, #1
	b _0819AE3A
	.align 2, 0
_0819AE34: .4byte 0x030047A4
_0819AE38:
	movs r0, #0
_0819AE3A:
	cmp r0, #0
	beq _0819AE48
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _0819AE50
_0819AE48:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
_0819AE50:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0819AE88 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0819AE8C @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0xc]
	cmp r0, #2
	bls _0819AE7E
	cmp r2, #0x17
	bne _0819AE90
_0819AE7E:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0819AEB0
	.align 2, 0
_0819AE88: .4byte 0x0000048C
_0819AE8C: .4byte 0x000001DF
_0819AE90:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0819AE7E
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0819AEE0 @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0819AEB0
	movs r1, #0
_0819AEB0:
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
	beq _0819AEEE
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _0819AEE4
	asrs r0, r0, #1
	b _0819AEEA
	.align 2, 0
_0819AEE0: .4byte 0x00000187
_0819AEE4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819AEEA:
	mov r3, sb
	strh r0, [r3]
_0819AEEE:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0819AF0C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0819AF08 @ =0x000001DD
	adds r1, r6, r4
	b _0819AF80
	.align 2, 0
_0819AF08: .4byte 0x000001DD
_0819AF0C:
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
	bne _0819AF6C
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0819AF6C
	ldr r2, _0819AF5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819AF60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0819AF64 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0819AF68 @ =0x000001DD
	adds r1, r6, r4
	b _0819AF80
	.align 2, 0
_0819AF5C: .4byte 0x030046B8
_0819AF60: .4byte 0x000003FF
_0819AF64: .4byte 0x0203B400
_0819AF68: .4byte 0x000001DD
_0819AF6C:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0819AFA0 @ =0x000001DD
	adds r1, r6, r3
_0819AF80:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0819AFA8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819AFA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFA0: .4byte 0x000001DD
_0819AFA4: .4byte 0x03002BE0
_0819AFA8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0819AFC4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0819AFC0 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFC0: .4byte 0x03002BE0
_0819AFC4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0819AFE0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AFDC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFDC: .4byte 0x03002BE0
_0819AFE0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0819AFFC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819AFF8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFF8: .4byte 0x03002BE0
_0819AFFC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0819B00E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0819B016
_0819B00E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0819B018
_0819B016:
	movs r3, #1
_0819B018:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0819B048 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0819B0B0
	movs r1, #2
	ldr r2, _0819B04C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819B050
	movs r0, #1
	b _0819B052
	.align 2, 0
_0819B048: .4byte 0x0000049C
_0819B04C: .4byte 0x00000474
_0819B050:
	movs r0, #0
_0819B052:
	cmp r0, #0
	beq _0819B06C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819B068 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0819B078
	.align 2, 0
_0819B068: .4byte 0x03002BE0
_0819B06C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0819B0B0
_0819B078:
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
_0819B0B0:
	ldr r4, [sp, #0xc]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0819B0E4
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819B0E4
	ldr r3, _0819B0FC @ =0x0000024E
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
	bls _0819B0E4
	strh r1, [r2]
_0819B0E4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0819B100 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0819B104 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819B108
	movs r0, #1
	b _0819B10A
	.align 2, 0
_0819B0FC: .4byte 0x0000024E
_0819B100: .4byte 0x030046A0
_0819B104: .4byte 0x00000934
_0819B108:
	movs r0, #0
_0819B10A:
	ldr r1, _0819B20C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0819B124
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #0xc]
	strb r0, [r1]
_0819B124:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
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
_0819B14E:
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	cmp r0, #0
	bne _0819B17A
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	mov r0, r8
	adds r0, #0x43
	ldrb r1, [r0]
	ldr r4, _0819B210 @ =0x0000048C
	adds r0, r6, r4
	strb r1, [r0]
	mov r0, r8
	adds r0, #0x44
	ldrh r0, [r0]
	strh r0, [r2]
_0819B17A:
	ldr r7, [sp, #8]
	ldr r1, _0819B214 @ =0x00000CBB
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0819B1FC
	ldr r2, _0819B218 @ =0x00000EAC
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	bls _0819B1FC
	ldr r3, _0819B21C @ =Ax_StateCloneBlink
	mov sb, r3
	ldr r4, _0819B220 @ =0x0000046D
	adds r4, r6, r4
	str r4, [sp, #0x10]
	ldr r7, _0819B224 @ =0x0000046B
	adds r5, r6, r7
	ldr r0, _0819B228 @ =0x00000553
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r1, r6
	mov ip, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r6, r6, r2
	movs r4, #4
	ldr r7, [sp, #8]
	ldr r0, _0819B22C @ =0x00000ABE
	adds r2, r7, r0
	movs r3, #2
	adds r0, #0xf0
	adds r1, r7, r0
_0819B1C4:
	ldrh r0, [r2]
	orrs r0, r4
	strh r0, [r2]
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r2, #0x50
	adds r1, #0x50
	subs r3, #1
	cmp r3, #0
	bge _0819B1C4
	movs r2, #0
	movs r1, #0x2e
	movs r0, #1
	ldr r3, [sp, #0x10]
	strb r0, [r3]
	strb r2, [r5]
	mov r4, r8
	strb r1, [r4]
	mov r7, sb
	mov r0, ip
	str r7, [r0]
	movs r1, #0
	strh r2, [r6]
	ldr r2, [sp, #8]
	ldr r3, _0819B218 @ =0x00000EAC
	adds r0, r2, r3
	strb r1, [r0]
_0819B1FC:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819B20C: .4byte 0x0000048A
_0819B210: .4byte 0x0000048C
_0819B214: .4byte 0x00000CBB
_0819B218: .4byte 0x00000EAC
_0819B21C: .4byte Ax_StateCloneBlink
_0819B220: .4byte 0x0000046D
_0819B224: .4byte 0x0000046B
_0819B228: .4byte 0x00000553
_0819B22C: .4byte 0x00000ABE
