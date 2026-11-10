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
	beq _0814BBE4
	b _0814C278
_0814BBE4:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0814BBF4
	b _0814C278
_0814BBF4:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814BC1C
	ldr r3, _0814BC18 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814BC0C
	b _0814C278
_0814BC0C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _0814C278
	.align 2, 0
_0814BC18: .4byte 0x0000048C
_0814BC1C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0814BC2C
	b _0814C278
_0814BC2C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0814BC3C
	b _0814BF48
_0814BC3C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0814BC4E
	b _0814C278
_0814BC4E:
	ldr r2, _0814BCE0 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0814BC62
	b _0814C278
_0814BC62:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814BC70
	b _0814C278
_0814BC70:
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
	bne _0814BC88
	b _0814BDD0
_0814BC88:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0814BCF0
	ands r3, r1
	cmp r3, #0
	beq _0814BCF0
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814BCAE
	rsbs r1, r1, #0
_0814BCAE:
	cmp r1, #0x20
	bgt _0814BCF0
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0814BCE4 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _0814BCE8 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0814BCEC @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0814C278
	.align 2, 0
_0814BCE0: .4byte 0x0000A007
_0814BCE4: .4byte 0x000004BE
_0814BCE8: .4byte 0x0000048C
_0814BCEC: .4byte 0x0000044E
_0814BCF0:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _0814BD18 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0814BD20
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814BD1C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD18: .4byte 0x0000048A
_0814BD1C: .4byte 0x03002BE0
_0814BD20:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814BD3C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0814BD38 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD38: .4byte 0x03002BE0
_0814BD3C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0814BD58
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0814BD54 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD54: .4byte 0x03002BE0
_0814BD58:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0814BD74
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0814BD70 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD70: .4byte 0x03002BE0
_0814BD74:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0814BD86
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0814BD8E
_0814BD86:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0814BD90
_0814BD8E:
	movs r3, #1
_0814BD90:
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
	ldr r5, _0814BDC4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0814BDB2
	b _0814BF08
_0814BDB2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814BDC8
	movs r0, #1
	b _0814BDCA
	.align 2, 0
_0814BDC4: .4byte 0x0000049C
_0814BDC8:
	movs r0, #0
_0814BDCA:
	cmp r0, #0
	bne _0814BEAE
	b _0814BEC4
_0814BDD0:
	strh r2, [r7, #0x3e]
	ldr r1, _0814BDF8 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0814BE00
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814BDFC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BDF8: .4byte 0x0000048A
_0814BDFC: .4byte 0x03002BE0
_0814BE00:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814BE1C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0814BE18 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BE18: .4byte 0x03002BE0
_0814BE1C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0814BE38
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0814BE34 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BE34: .4byte 0x03002BE0
_0814BE38:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0814BE54
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0814BE50 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BE50: .4byte 0x03002BE0
_0814BE54:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0814BE66
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0814BE6E
_0814BE66:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0814BE70
_0814BE6E:
	movs r3, #1
_0814BE70:
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
	ldr r5, _0814BEA4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _0814BF08
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814BEA8
	movs r0, #1
	b _0814BEAA
	.align 2, 0
_0814BEA4: .4byte 0x0000049C
_0814BEA8:
	movs r0, #0
_0814BEAA:
	cmp r0, #0
	beq _0814BEC4
_0814BEAE:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814BEC0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0814BED0
	.align 2, 0
_0814BEC0: .4byte 0x03002BE0
_0814BEC4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0814BF08
_0814BED0:
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
_0814BF08:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0814BF34
	ldr r5, _0814BF40 @ =0x0000024E
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
	bls _0814BF34
	strh r1, [r2]
_0814BF34:
	ldr r5, _0814BF44 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0814C278
	.align 2, 0
_0814BF40: .4byte 0x0000024E
_0814BF44: .4byte 0x0000048C
_0814BF48:
	ldr r0, _0814BF5C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814BF60
	movs r0, #1
	b _0814BF62
	.align 2, 0
_0814BF5C: .4byte 0x030047A4
_0814BF60:
	movs r0, #0
_0814BF62:
	cmp r0, #0
	beq _0814BF70
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _0814BF78
_0814BF70:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_0814BF78:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0814BFB0 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0814BFB4 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0814BFA6
	cmp r2, #0x17
	bne _0814BFB8
_0814BFA6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0814BFDA
	.align 2, 0
_0814BFB0: .4byte 0x0000048C
_0814BFB4: .4byte 0x000001DF
_0814BFB8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0814BFA6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0814C008 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814BFDA
	movs r1, #0
_0814BFDA:
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
	beq _0814C016
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0814C00C
	asrs r0, r0, #1
	b _0814C012
	.align 2, 0
_0814C008: .4byte 0x00000187
_0814C00C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0814C012:
	mov r2, sb
	strh r0, [r2]
_0814C016:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0814C034
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0814C030 @ =0x000001DD
	adds r1, r6, r4
	b _0814C0A8
	.align 2, 0
_0814C030: .4byte 0x000001DD
_0814C034:
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
	bne _0814C094
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0814C094
	ldr r2, _0814C084 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0814C088 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0814C08C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0814C090 @ =0x000001DD
	adds r1, r6, r4
	b _0814C0A8
	.align 2, 0
_0814C084: .4byte 0x030046B8
_0814C088: .4byte 0x000003FF
_0814C08C: .4byte 0x0203B400
_0814C090: .4byte 0x000001DD
_0814C094:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _0814C0C8 @ =0x000001DD
	adds r1, r6, r3
_0814C0A8:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0814C0D0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0814C0CC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C0C8: .4byte 0x000001DD
_0814C0CC: .4byte 0x03002BE0
_0814C0D0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814C0EC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0814C0E8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C0E8: .4byte 0x03002BE0
_0814C0EC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0814C108
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814C104 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C104: .4byte 0x03002BE0
_0814C108:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0814C124
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0814C120 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C120: .4byte 0x03002BE0
_0814C124:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0814C136
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0814C13E
_0814C136:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0814C140
_0814C13E:
	movs r3, #1
_0814C140:
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
	ldr r5, _0814C174 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0814C1DC
	movs r1, #2
	ldr r2, _0814C178 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814C17C
	movs r0, #1
	b _0814C17E
	.align 2, 0
_0814C174: .4byte 0x0000049C
_0814C178: .4byte 0x00000474
_0814C17C:
	movs r0, #0
_0814C17E:
	cmp r0, #0
	beq _0814C198
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814C194 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0814C1A4
	.align 2, 0
_0814C194: .4byte 0x03002BE0
_0814C198:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0814C1DC
_0814C1A4:
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
_0814C1DC:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0814C210
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0814C210
	ldr r0, _0814C228 @ =0x0000024E
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
	bls _0814C210
	strh r1, [r2]
_0814C210:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0814C22C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0814C230 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814C234
	movs r0, #1
	b _0814C236
	.align 2, 0
_0814C228: .4byte 0x0000024E
_0814C22C: .4byte 0x030046A0
_0814C230: .4byte 0x00000934
_0814C234:
	movs r0, #0
_0814C236:
	ldr r1, _0814C288 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0814C24E
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_0814C24E:
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
_0814C278:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814C288: .4byte 0x0000048A
