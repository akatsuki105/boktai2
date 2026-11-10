	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0815EC3C
	b _0815F2BA
_0815EC3C:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0815EC68
	ldr r3, _0815EC64 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815EC54
	b _0815F2BA
_0815EC54:
	movs r0, #0
	mov r4, r8
	strh r1, [r4, #0x3e]
	mov r1, r8
	adds r1, #0x43
	strb r0, [r1]
	b _0815F2BA
	.align 2, 0
_0815EC64: .4byte 0x0000048C
_0815EC68:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0815EC78
	b _0815F2BA
_0815EC78:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0815EC86
	b _0815EF8C
_0815EC86:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0815EC96
	b _0815F2BA
_0815EC96:
	ldr r2, _0815ED28 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0815ECAA
	b _0815F2BA
_0815ECAA:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0815ECB8
	b _0815F2BA
_0815ECB8:
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
	bne _0815ECD0
	b _0815EE18
_0815ECD0:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0815ED38
	ands r3, r1
	cmp r3, #0
	beq _0815ED38
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0815ECF8
	rsbs r1, r1, #0
_0815ECF8:
	cmp r1, #0x20
	bgt _0815ED38
	ldrh r0, [r7, #0x3c]
	ldr r3, _0815ED2C @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _0815ED30 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0815ED34 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0815F2BA
	.align 2, 0
_0815ED28: .4byte 0x0000A007
_0815ED2C: .4byte 0x000004BE
_0815ED30: .4byte 0x0000048C
_0815ED34: .4byte 0x0000044E
_0815ED38:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0815ED60 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0815ED68
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815ED64 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815ED60: .4byte 0x0000048A
_0815ED64: .4byte 0x03002BE0
_0815ED68:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0815ED84
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815ED80 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815ED80: .4byte 0x03002BE0
_0815ED84:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0815EDA0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0815ED9C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815ED9C: .4byte 0x03002BE0
_0815EDA0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0815EDBC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815EDB8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815EDB8: .4byte 0x03002BE0
_0815EDBC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0815EDCE
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0815EDD6
_0815EDCE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0815EDD8
_0815EDD6:
	movs r3, #1
_0815EDD8:
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
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _0815EDF8
	b _0815EF4C
_0815EDF8:
	movs r1, #2
	ldr r3, _0815EE0C @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815EE10
	movs r0, #1
	b _0815EE12
	.align 2, 0
_0815EE0C: .4byte 0x00000474
_0815EE10:
	movs r0, #0
_0815EE12:
	cmp r0, #0
	bne _0815EEF2
	b _0815EF08
_0815EE18:
	mov r1, r8
	strh r2, [r1, #0x3e]
	ldr r3, _0815EE40 @ =0x0000048A
	adds r0, r6, r3
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0815EE48
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815EE44 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE40: .4byte 0x0000048A
_0815EE44: .4byte 0x03002BE0
_0815EE48:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0815EE64
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0815EE60 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE60: .4byte 0x03002BE0
_0815EE64:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0815EE80
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815EE7C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE7C: .4byte 0x03002BE0
_0815EE80:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0815EE9C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815EE98 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE98: .4byte 0x03002BE0
_0815EE9C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0815EEAE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0815EEB6
_0815EEAE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0815EEB8
_0815EEB6:
	movs r3, #1
_0815EEB8:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _0815EF4C
	movs r1, #2
	ldr r3, _0815EEE8 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815EEEC
	movs r0, #1
	b _0815EEEE
	.align 2, 0
_0815EEE8: .4byte 0x00000474
_0815EEEC:
	movs r0, #0
_0815EEEE:
	cmp r0, #0
	beq _0815EF08
_0815EEF2:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815EF04 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0815EF14
	.align 2, 0
_0815EF04: .4byte 0x03002BE0
_0815EF08:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0815EF4C
_0815EF14:
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
_0815EF4C:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0815EF78
	ldr r0, _0815EF84 @ =0x0000024E
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
	bls _0815EF78
	strh r1, [r2]
_0815EF78:
	ldr r0, _0815EF88 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _0815F2BA
	.align 2, 0
_0815EF84: .4byte 0x0000024E
_0815EF88: .4byte 0x0000048C
_0815EF8C:
	ldr r0, _0815EFA0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815EFA4
	movs r0, #1
	b _0815EFA6
	.align 2, 0
_0815EFA0: .4byte 0x030047A4
_0815EFA4:
	movs r0, #0
_0815EFA6:
	cmp r0, #0
	beq _0815EFB4
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _0815EFBC
_0815EFB4:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
_0815EFBC:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0815EFF4 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0815EFF8 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x1c]
	cmp r0, #2
	bls _0815EFEA
	cmp r2, #0x17
	bne _0815EFFC
_0815EFEA:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0815F01C
	.align 2, 0
_0815EFF4: .4byte 0x0000048C
_0815EFF8: .4byte 0x000001DF
_0815EFFC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0815EFEA
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0815F04C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0815F01C
	movs r1, #0
_0815F01C:
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
	beq _0815F05A
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _0815F050
	asrs r0, r0, #1
	b _0815F056
	.align 2, 0
_0815F04C: .4byte 0x00000187
_0815F050:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0815F056:
	mov r3, sb
	strh r0, [r3]
_0815F05A:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0815F078
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0815F074 @ =0x000001DD
	adds r1, r6, r4
	b _0815F0EC
	.align 2, 0
_0815F074: .4byte 0x000001DD
_0815F078:
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
	bne _0815F0D8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0815F0D8
	ldr r2, _0815F0C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815F0CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0815F0D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0815F0D4 @ =0x000001DD
	adds r1, r6, r4
	b _0815F0EC
	.align 2, 0
_0815F0C8: .4byte 0x030046B8
_0815F0CC: .4byte 0x000003FF
_0815F0D0: .4byte 0x0203B400
_0815F0D4: .4byte 0x000001DD
_0815F0D8:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0815F10C @ =0x000001DD
	adds r1, r6, r3
_0815F0EC:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0815F114
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815F110 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F10C: .4byte 0x000001DD
_0815F110: .4byte 0x03002BE0
_0815F114:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0815F130
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0815F12C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F12C: .4byte 0x03002BE0
_0815F130:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0815F14C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815F148 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F148: .4byte 0x03002BE0
_0815F14C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0815F168
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815F164 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F164: .4byte 0x03002BE0
_0815F168:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0815F17A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0815F182
_0815F17A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0815F184
_0815F182:
	movs r3, #1
_0815F184:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0815F1B4 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0815F21C
	movs r1, #2
	ldr r2, _0815F1B8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F1BC
	movs r0, #1
	b _0815F1BE
	.align 2, 0
_0815F1B4: .4byte 0x0000049C
_0815F1B8: .4byte 0x00000474
_0815F1BC:
	movs r0, #0
_0815F1BE:
	cmp r0, #0
	beq _0815F1D8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815F1D4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0815F1E4
	.align 2, 0
_0815F1D4: .4byte 0x03002BE0
_0815F1D8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0815F21C
_0815F1E4:
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
_0815F21C:
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0815F250
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815F250
	ldr r3, _0815F268 @ =0x0000024E
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
	bls _0815F250
	strh r1, [r2]
_0815F250:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0815F26C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0815F270 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F274
	movs r0, #1
	b _0815F276
	.align 2, 0
_0815F268: .4byte 0x0000024E
_0815F26C: .4byte 0x030046A0
_0815F270: .4byte 0x00000934
_0815F274:
	movs r0, #0
_0815F276:
	ldr r1, _0815F31C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0815F290
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_0815F290:
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
_0815F2BA:
	ldr r1, _0815F320 @ =0x00000472
	adds r0, r6, r1
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0815F324 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #8
	add r2, sp, #0x10
	adds r4, r7, #0
	adds r4, #0x24
	ldrh r0, [r7, #0x24]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0815F304
	b _0815F490
_0815F304:
	movs r2, #2
	ldr r4, [sp, #0x18]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0815F328
	movs r0, #1
	b _0815F32A
	.align 2, 0
_0815F31C: .4byte 0x0000048A
_0815F320: .4byte 0x00000472
_0815F324: .4byte 0x0000FFFF
_0815F328:
	movs r0, #0
_0815F32A:
	cmp r0, #0
	bne _0815F330
	b _0815F490
_0815F330:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bgt _0815F344
	b _0815F490
_0815F344:
	ldrh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	ble _0815F354
	b _0815F490
_0815F354:
	movs r2, #0
	movs r1, #0
	mov r3, r8
	strh r1, [r3, #0x3e]
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	ldr r3, _0815F38C @ =0x0000048A
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0815F390 @ =0x0000048C
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0815F394 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815F398
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0815F3A6
	.align 2, 0
_0815F38C: .4byte 0x0000048A
_0815F390: .4byte 0x0000048C
_0815F394: .4byte 0x0000025D
_0815F398:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_0815F3A6:
	ldr r3, _0815F3EC @ =0x0000044C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815F3BA
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl ParticleShadow_Show
_0815F3BA:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	bne _0815F490
	movs r2, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x20]
	cmp r0, #0
	bne _0815F490
	movs r1, #8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0815F3F0
	movs r0, #1
	b _0815F3F2
	.align 2, 0
_0815F3EC: .4byte 0x0000044C
_0815F3F0:
	movs r0, #0
_0815F3F2:
	cmp r0, #0
	bne _0815F490
	movs r2, #0x80
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _0815F40C
	movs r0, #1
	b _0815F40E
_0815F40C:
	movs r0, #0
_0815F40E:
	adds r5, r0, #0
	cmp r5, #0
	bne _0815F490
	movs r0, #0x80
	lsls r0, r0, #5
	mov r8, r0
	mov r1, sl
	ldrh r0, [r1]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0815F43E
	movs r3, #0x97
	lsls r3, r3, #3
	adds r4, r6, r3
	ldr r0, [r4]
	bl EnemyTargetManager_Release
	mov r1, sl
	ldrh r0, [r1]
	mov r2, r8
	bics r0, r2
	strh r0, [r1]
	str r5, [r4]
_0815F43E:
	movs r1, #0x80
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r4, _0815F4A0 @ =0x00000202
	adds r1, r6, r4
	movs r0, #0xb4
	strh r0, [r1]
	ldr r0, [sp, #0x18]
	ldr r1, _0815F4A4 @ =0x000006F4
	adds r2, r0, r1
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r7, #0x22]
	adds r0, #9
	movs r1, #7
	ands r0, r1
	ldr r2, _0815F4A8 @ =0x000001DD
	adds r1, r6, r2
	strb r0, [r1]
	adds r3, #7
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #1
	bl Enemy_SetEmote
_0815F490:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815F4A0: .4byte 0x00000202
_0815F4A4: .4byte 0x000006F4
_0815F4A8: .4byte 0x000001DD
