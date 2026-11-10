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
	beq _0816AADC
	b _0816B17A
_0816AADC:
	movs r5, #0x80
	lsls r5, r5, #7
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r5
	mov sl, r1
	cmp r0, #0
	beq _0816AAF2
	b _0816B17A
_0816AAF2:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816AB00
	b _0816B17A
_0816AB00:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0816AB10
	b _0816B17A
_0816AB10:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0816AB3C
	ldr r3, _0816AB38 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816AB28
	b _0816B17A
_0816AB28:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _0816B17A
	.align 2, 0
_0816AB38: .4byte 0x0000048C
_0816AB3C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r1, #4
	mov sb, r1
	ldrh r0, [r0, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816AB4E
	b _0816B17A
_0816AB4E:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0816AB5C
	b _0816AE54
_0816AB5C:
	ldr r1, [r7, #0x34]
	adds r0, r1, #0
	ands r0, r5
	adds r5, r1, #0
	cmp r0, #0
	bne _0816AB6A
	b _0816B17A
_0816AB6A:
	ldr r1, _0816ABF4 @ =0x0000A007
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816AB78
	b _0816B17A
_0816AB78:
	movs r0, #0x91
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0816AB86
	b _0816B17A
_0816AB86:
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
	bne _0816AB9E
	b _0816ACE0
_0816AB9E:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0816AC04
	ands r3, r1
	cmp r3, #0
	beq _0816AC04
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816ABC6
	rsbs r1, r1, #0
_0816ABC6:
	cmp r1, #0x20
	bgt _0816AC04
	ldrh r0, [r7, #0x3c]
	ldr r3, _0816ABF8 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _0816ABFC @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0816AC00 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0816B17A
	.align 2, 0
_0816ABF4: .4byte 0x0000A007
_0816ABF8: .4byte 0x000004BE
_0816ABFC: .4byte 0x0000048C
_0816AC00: .4byte 0x0000044E
_0816AC04:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0816AC2C @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0816AC34
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816AC30 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC2C: .4byte 0x0000048A
_0816AC30: .4byte 0x03002BE0
_0816AC34:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0816AC50
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AC4C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC4C: .4byte 0x03002BE0
_0816AC50:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0816AC6C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0816AC68 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC68: .4byte 0x03002BE0
_0816AC6C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0816AC88
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816AC84 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0816ACA2
	.align 2, 0
_0816AC84: .4byte 0x03002BE0
_0816AC88:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0816AC9A
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0816ACA2
_0816AC9A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0816ACA4
_0816ACA2:
	movs r3, #1
_0816ACA4:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	ldr r4, _0816ACD4 @ =0x0000049C
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	bne _0816ACC2
	b _0816AE14
_0816ACC2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816ACD8
	movs r0, #1
	b _0816ACDA
	.align 2, 0
_0816ACD4: .4byte 0x0000049C
_0816ACD8:
	movs r0, #0
_0816ACDA:
	cmp r0, #0
	bne _0816ADB8
	b _0816ADD0
_0816ACE0:
	mov r1, r8
	strh r2, [r1, #0x3e]
	ldr r3, _0816AD08 @ =0x0000048A
	adds r0, r6, r3
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0816AD10
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AD0C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD08: .4byte 0x0000048A
_0816AD0C: .4byte 0x03002BE0
_0816AD10:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0816AD2C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0816AD28 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD28: .4byte 0x03002BE0
_0816AD2C:
	adds r0, r2, #0
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0816AD4C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816AD48 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD48: .4byte 0x03002BE0
_0816AD4C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0816AD68
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AD64 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0816AD82
	.align 2, 0
_0816AD64: .4byte 0x03002BE0
_0816AD68:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0816AD7A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0816AD82
_0816AD7A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0816AD84
_0816AD82:
	movs r3, #1
_0816AD84:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	beq _0816AE14
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816ADB2
	movs r0, #1
	b _0816ADB4
_0816ADB2:
	movs r0, #0
_0816ADB4:
	cmp r0, #0
	beq _0816ADD0
_0816ADB8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816ADCC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0816ADDC
	.align 2, 0
_0816ADCC: .4byte 0x03002BE0
_0816ADD0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0816AE14
_0816ADDC:
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
_0816AE14:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0816AE40
	ldr r0, _0816AE4C @ =0x0000024E
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
	bls _0816AE40
	strh r1, [r2]
_0816AE40:
	ldr r0, _0816AE50 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _0816B17A
	.align 2, 0
_0816AE4C: .4byte 0x0000024E
_0816AE50: .4byte 0x0000048C
_0816AE54:
	ldr r0, _0816AE68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0816AE6C
	movs r0, #1
	b _0816AE6E
	.align 2, 0
_0816AE68: .4byte 0x030047A4
_0816AE6C:
	movs r0, #0
_0816AE6E:
	cmp r0, #0
	beq _0816AE7C
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _0816AE84
_0816AE7C:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
_0816AE84:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0816AEBC @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0816AEC0 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0816AEB2
	cmp r2, #0x17
	bne _0816AEC4
_0816AEB2:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0816AEE4
	.align 2, 0
_0816AEBC: .4byte 0x0000048C
_0816AEC0: .4byte 0x000001DF
_0816AEC4:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0816AEB2
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0816AF0C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0816AEE4
	movs r1, #0
_0816AEE4:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r1, #6
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816AF1A
	mov r3, r8
	ldrh r0, [r3, #0x3e]
	lsls r0, r0, #1
	strh r0, [r3, #0x3e]
	mov r4, sb
	ldrh r0, [r4]
	cmp r0, #0
	blt _0816AF10
	asrs r0, r0, #1
	b _0816AF16
	.align 2, 0
_0816AF0C: .4byte 0x00000187
_0816AF10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0816AF16:
	mov r1, sb
	strh r0, [r1]
_0816AF1A:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0816AF38
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r2, _0816AF34 @ =0x000001DD
	adds r1, r6, r2
	b _0816AFAC
	.align 2, 0
_0816AF34: .4byte 0x000001DD
_0816AF38:
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
	bne _0816AF98
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0816AF98
	ldr r2, _0816AF88 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816AF8C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0816AF90 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0816AF94 @ =0x000001DD
	adds r1, r6, r4
	b _0816AFAC
	.align 2, 0
_0816AF88: .4byte 0x030046B8
_0816AF8C: .4byte 0x000003FF
_0816AF90: .4byte 0x0203B400
_0816AF94: .4byte 0x000001DD
_0816AF98:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0816AFCC @ =0x000001DD
	adds r1, r6, r3
_0816AFAC:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0816AFD4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816AFD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816AFCC: .4byte 0x000001DD
_0816AFD0: .4byte 0x03002BE0
_0816AFD4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0816AFF0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0816AFEC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816AFEC: .4byte 0x03002BE0
_0816AFF0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0816B00C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816B008 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816B008: .4byte 0x03002BE0
_0816B00C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0816B028
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0816B024 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0816B042
	.align 2, 0
_0816B024: .4byte 0x03002BE0
_0816B028:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0816B03A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0816B042
_0816B03A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0816B044
_0816B042:
	movs r3, #1
_0816B044:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0816B074 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0816B0DC
	movs r1, #2
	ldr r2, _0816B078 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B07C
	movs r0, #1
	b _0816B07E
	.align 2, 0
_0816B074: .4byte 0x0000049C
_0816B078: .4byte 0x00000474
_0816B07C:
	movs r0, #0
_0816B07E:
	cmp r0, #0
	beq _0816B098
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0816B094 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0816B0A4
	.align 2, 0
_0816B094: .4byte 0x03002BE0
_0816B098:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0816B0DC
_0816B0A4:
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
_0816B0DC:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0816B110
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0816B110
	ldr r3, _0816B128 @ =0x0000024E
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
	bls _0816B110
	strh r1, [r2]
_0816B110:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0816B12C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0816B130 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B134
	movs r0, #1
	b _0816B136
	.align 2, 0
_0816B128: .4byte 0x0000024E
_0816B12C: .4byte 0x030046A0
_0816B130: .4byte 0x00000934
_0816B134:
	movs r0, #0
_0816B136:
	ldr r1, _0816B18C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0816B150
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_0816B150:
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
_0816B17A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816B18C: .4byte 0x0000048A
