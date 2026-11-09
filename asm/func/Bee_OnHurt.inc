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
	beq _08166914
	b _08166FFA
_08166914:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08166922
	b _08166FFA
_08166922:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x40
	add r0, r8
	mov sb, r0
	cmp r2, #0
	beq _08166938
	b _08166FBA
_08166938:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08166964
	ldr r3, _08166960 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08166950
	b _08166FBA
_08166950:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _08166FBA
	.align 2, 0
_08166960: .4byte 0x0000048C
_08166964:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08166974
	b _08166FBA
_08166974:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08166982
	b _08166C8C
_08166982:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _08166992
	b _08166FBA
_08166992:
	ldr r2, _08166A24 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081669A6
	b _08166FBA
_081669A6:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081669B4
	b _08166FBA
_081669B4:
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
	bne _081669CC
	b _08166B14
_081669CC:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _08166A34
	ands r3, r1
	cmp r3, #0
	beq _08166A34
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081669F4
	rsbs r1, r1, #0
_081669F4:
	cmp r1, #0x20
	bgt _08166A34
	ldrh r0, [r7, #0x3c]
	ldr r3, _08166A28 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _08166A2C @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08166A30 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08166FBA
	.align 2, 0
_08166A24: .4byte 0x0000A007
_08166A28: .4byte 0x000004BE
_08166A2C: .4byte 0x0000048C
_08166A30: .4byte 0x0000044E
_08166A34:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _08166A5C @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08166A64
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166A60 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166A5C: .4byte 0x0000048A
_08166A60: .4byte 0x03002BE0
_08166A64:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08166A80
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166A7C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166A7C: .4byte 0x03002BE0
_08166A80:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08166A9C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08166A98 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166A98: .4byte 0x03002BE0
_08166A9C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08166AB8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166AB4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166AB4: .4byte 0x03002BE0
_08166AB8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08166ACA
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08166AD2
_08166ACA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08166AD4
_08166AD2:
	movs r3, #1
_08166AD4:
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
	bne _08166AF4
	b _08166C48
_08166AF4:
	movs r1, #2
	ldr r3, _08166B08 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166B0C
	movs r0, #1
	b _08166B0E
	.align 2, 0
_08166B08: .4byte 0x00000474
_08166B0C:
	movs r0, #0
_08166B0E:
	cmp r0, #0
	bne _08166BEE
	b _08166C04
_08166B14:
	mov r3, r8
	strh r2, [r3, #0x3e]
	ldr r1, _08166B3C @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08166B44
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166B40 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B3C: .4byte 0x0000048A
_08166B40: .4byte 0x03002BE0
_08166B44:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08166B60
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166B5C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B5C: .4byte 0x03002BE0
_08166B60:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08166B7C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08166B78 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B78: .4byte 0x03002BE0
_08166B7C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08166B98
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166B94 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B94: .4byte 0x03002BE0
_08166B98:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08166BAA
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08166BB2
_08166BAA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08166BB4
_08166BB2:
	movs r3, #1
_08166BB4:
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
	beq _08166C48
	movs r1, #2
	ldr r3, _08166BE4 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166BE8
	movs r0, #1
	b _08166BEA
	.align 2, 0
_08166BE4: .4byte 0x00000474
_08166BE8:
	movs r0, #0
_08166BEA:
	cmp r0, #0
	beq _08166C04
_08166BEE:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166C00 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08166C10
	.align 2, 0
_08166C00: .4byte 0x03002BE0
_08166C04:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08166C48
_08166C10:
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
_08166C48:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08166C74
	ldr r0, _08166C84 @ =0x0000024E
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
	bls _08166C74
	strh r1, [r2]
_08166C74:
	ldr r0, _08166C88 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	add r1, r8
	mov sb, r1
	b _08166FBA
	.align 2, 0
_08166C84: .4byte 0x0000024E
_08166C88: .4byte 0x0000048C
_08166C8C:
	ldr r0, _08166CA0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08166CA4
	movs r0, #1
	b _08166CA6
	.align 2, 0
_08166CA0: .4byte 0x030047A4
_08166CA4:
	movs r0, #0
_08166CA6:
	cmp r0, #0
	beq _08166CB4
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamageAlt
	b _08166CBC
_08166CB4:
	adds r0, r7, #0
	mov r1, r8
	bl Hitbox_ApplyDamage
_08166CBC:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08166CF4 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08166CF8 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08166CEA
	cmp r2, #0x17
	bne _08166CFC
_08166CEA:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _08166D1C
	.align 2, 0
_08166CF4: .4byte 0x0000048C
_08166CF8: .4byte 0x000001DF
_08166CFC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08166CEA
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _08166D4C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08166D1C
	movs r1, #0
_08166D1C:
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
	beq _08166D5A
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _08166D50
	asrs r0, r0, #1
	b _08166D56
	.align 2, 0
_08166D4C: .4byte 0x00000187
_08166D50:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08166D56:
	mov r3, sb
	strh r0, [r3]
_08166D5A:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08166D78
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08166D74 @ =0x000001DD
	adds r1, r6, r4
	b _08166DEC
	.align 2, 0
_08166D74: .4byte 0x000001DD
_08166D78:
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
	bne _08166DD8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08166DD8
	ldr r2, _08166DC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08166DCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08166DD0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08166DD4 @ =0x000001DD
	adds r1, r6, r4
	b _08166DEC
	.align 2, 0
_08166DC8: .4byte 0x030046B8
_08166DCC: .4byte 0x000003FF
_08166DD0: .4byte 0x0203B400
_08166DD4: .4byte 0x000001DD
_08166DD8:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08166E0C @ =0x000001DD
	adds r1, r6, r3
_08166DEC:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08166E14
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166E10 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E0C: .4byte 0x000001DD
_08166E10: .4byte 0x03002BE0
_08166E14:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08166E30
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08166E2C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E2C: .4byte 0x03002BE0
_08166E30:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08166E4C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166E48 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E48: .4byte 0x03002BE0
_08166E4C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08166E68
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166E64 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E64: .4byte 0x03002BE0
_08166E68:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08166E7A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08166E82
_08166E7A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08166E84
_08166E82:
	movs r3, #1
_08166E84:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _08166EB4 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _08166F1C
	movs r1, #2
	ldr r2, _08166EB8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166EBC
	movs r0, #1
	b _08166EBE
	.align 2, 0
_08166EB4: .4byte 0x0000049C
_08166EB8: .4byte 0x00000474
_08166EBC:
	movs r0, #0
_08166EBE:
	cmp r0, #0
	beq _08166ED8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166ED4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08166EE4
	.align 2, 0
_08166ED4: .4byte 0x03002BE0
_08166ED8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08166F1C
_08166EE4:
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
_08166F1C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08166F50
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08166F50
	ldr r3, _08166F68 @ =0x0000024E
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
	bls _08166F50
	strh r1, [r2]
_08166F50:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08166F6C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08166F70 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166F74
	movs r0, #1
	b _08166F76
	.align 2, 0
_08166F68: .4byte 0x0000024E
_08166F6C: .4byte 0x030046A0
_08166F70: .4byte 0x00000934
_08166F74:
	movs r0, #0
_08166F76:
	ldr r1, _0816700C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08166F90
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_08166F90:
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
_08166FBA:
	ldr r2, _08167010 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08167014 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08167018 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	ldrh r2, [r3]
	movs r1, #0xf
	ands r0, r1
	subs r2, r2, r0
	cmp r2, #0x14
	bge _08166FDE
	movs r2, #0x14
_08166FDE:
	mov r4, sb
	strh r2, [r4]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #5
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_08166FFA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816700C: .4byte 0x0000048A
_08167010: .4byte 0x030046B8
_08167014: .4byte 0x000003FF
_08167018: .4byte 0x0203B400
