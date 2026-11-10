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
	beq _081A2BA4
	b _081A325C
_081A2BA4:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A2BC0
	movs r0, #1
	b _081A2BC2
_081A2BC0:
	movs r0, #0
_081A2BC2:
	cmp r0, #0
	beq _081A2BC8
	b _081A325C
_081A2BC8:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081A2BD8
	b _081A325C
_081A2BD8:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081A2C00
	ldr r4, _081A2BFC @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A2BF0
	b _081A325C
_081A2BF0:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081A325C
	.align 2, 0
_081A2BFC: .4byte 0x0000048C
_081A2C00:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081A2C10
	b _081A325C
_081A2C10:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081A2C20
	b _081A2F2C
_081A2C20:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081A2C32
	b _081A325C
_081A2C32:
	ldr r2, _081A2CC4 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081A2C46
	b _081A325C
_081A2C46:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081A2C54
	b _081A325C
_081A2C54:
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
	bne _081A2C6C
	b _081A2DB4
_081A2C6C:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081A2CD4
	ands r3, r1
	cmp r3, #0
	beq _081A2CD4
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081A2C92
	rsbs r1, r1, #0
_081A2C92:
	cmp r1, #0x20
	bgt _081A2CD4
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081A2CC8 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081A2CCC @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081A2CD0 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081A325C
	.align 2, 0
_081A2CC4: .4byte 0x0000A007
_081A2CC8: .4byte 0x000004BE
_081A2CCC: .4byte 0x0000048C
_081A2CD0: .4byte 0x0000044E
_081A2CD4:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081A2CFC @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081A2D04
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A2D00 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2CFC: .4byte 0x0000048A
_081A2D00: .4byte 0x03002BE0
_081A2D04:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A2D20
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A2D1C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2D1C: .4byte 0x03002BE0
_081A2D20:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081A2D3C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A2D38 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2D38: .4byte 0x03002BE0
_081A2D3C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A2D58
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A2D54 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2D54: .4byte 0x03002BE0
_081A2D58:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A2D6A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081A2D72
_081A2D6A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A2D74
_081A2D72:
	movs r3, #1
_081A2D74:
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
	ldr r5, _081A2DA8 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081A2D96
	b _081A2EEC
_081A2D96:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A2DAC
	movs r0, #1
	b _081A2DAE
	.align 2, 0
_081A2DA8: .4byte 0x0000049C
_081A2DAC:
	movs r0, #0
_081A2DAE:
	cmp r0, #0
	bne _081A2E92
	b _081A2EA8
_081A2DB4:
	strh r2, [r7, #0x3e]
	ldr r1, _081A2DDC @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081A2DE4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A2DE0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2DDC: .4byte 0x0000048A
_081A2DE0: .4byte 0x03002BE0
_081A2DE4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A2E00
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A2DFC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2DFC: .4byte 0x03002BE0
_081A2E00:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081A2E1C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A2E18 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2E18: .4byte 0x03002BE0
_081A2E1C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A2E38
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A2E34 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2E34: .4byte 0x03002BE0
_081A2E38:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A2E4A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081A2E52
_081A2E4A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A2E54
_081A2E52:
	movs r3, #1
_081A2E54:
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
	ldr r5, _081A2E88 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081A2EEC
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A2E8C
	movs r0, #1
	b _081A2E8E
	.align 2, 0
_081A2E88: .4byte 0x0000049C
_081A2E8C:
	movs r0, #0
_081A2E8E:
	cmp r0, #0
	beq _081A2EA8
_081A2E92:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081A2EB4
	.align 2, 0
_081A2EA4: .4byte 0x03002BE0
_081A2EA8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081A2EEC
_081A2EB4:
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
_081A2EEC:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081A2F18
	ldr r5, _081A2F24 @ =0x0000024E
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
	bls _081A2F18
	strh r1, [r2]
_081A2F18:
	ldr r5, _081A2F28 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081A325C
	.align 2, 0
_081A2F24: .4byte 0x0000024E
_081A2F28: .4byte 0x0000048C
_081A2F2C:
	ldr r0, _081A2F40 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A2F44
	movs r0, #1
	b _081A2F46
	.align 2, 0
_081A2F40: .4byte 0x030047A4
_081A2F44:
	movs r0, #0
_081A2F46:
	cmp r0, #0
	beq _081A2F54
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081A2F5C
_081A2F54:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081A2F5C:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081A2F94 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081A2F98 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081A2F8A
	cmp r2, #0x17
	bne _081A2F9C
_081A2F8A:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081A2FBE
	.align 2, 0
_081A2F94: .4byte 0x0000048C
_081A2F98: .4byte 0x000001DF
_081A2F9C:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081A2F8A
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081A2FEC @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081A2FBE
	movs r1, #0
_081A2FBE:
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
	beq _081A2FFA
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081A2FF0
	asrs r0, r0, #1
	b _081A2FF6
	.align 2, 0
_081A2FEC: .4byte 0x00000187
_081A2FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081A2FF6:
	mov r2, sb
	strh r0, [r2]
_081A2FFA:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081A3018
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081A3014 @ =0x000001DD
	adds r1, r6, r4
	b _081A308C
	.align 2, 0
_081A3014: .4byte 0x000001DD
_081A3018:
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
	bne _081A3078
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081A3078
	ldr r2, _081A3068 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A306C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A3070 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081A3074 @ =0x000001DD
	adds r1, r6, r4
	b _081A308C
	.align 2, 0
_081A3068: .4byte 0x030046B8
_081A306C: .4byte 0x000003FF
_081A3070: .4byte 0x0203B400
_081A3074: .4byte 0x000001DD
_081A3078:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081A30AC @ =0x000001DD
	adds r1, r6, r3
_081A308C:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081A30B4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A30B0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A30AC: .4byte 0x000001DD
_081A30B0: .4byte 0x03002BE0
_081A30B4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A30D0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A30CC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A30CC: .4byte 0x03002BE0
_081A30D0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081A30EC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A30E8 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A30E8: .4byte 0x03002BE0
_081A30EC:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A3108
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A3104 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A3104: .4byte 0x03002BE0
_081A3108:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A311A
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081A3122
_081A311A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A3124
_081A3122:
	movs r3, #1
_081A3124:
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
	ldr r5, _081A3158 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081A31C0
	movs r1, #2
	ldr r2, _081A315C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A3160
	movs r0, #1
	b _081A3162
	.align 2, 0
_081A3158: .4byte 0x0000049C
_081A315C: .4byte 0x00000474
_081A3160:
	movs r0, #0
_081A3162:
	cmp r0, #0
	beq _081A317C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A3178 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081A3188
	.align 2, 0
_081A3178: .4byte 0x03002BE0
_081A317C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081A31C0
_081A3188:
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
_081A31C0:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081A31F4
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A31F4
	ldr r0, _081A320C @ =0x0000024E
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
	bls _081A31F4
	strh r1, [r2]
_081A31F4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081A3210 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081A3214 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A3218
	movs r0, #1
	b _081A321A
	.align 2, 0
_081A320C: .4byte 0x0000024E
_081A3210: .4byte 0x030046A0
_081A3214: .4byte 0x00000934
_081A3218:
	movs r0, #0
_081A321A:
	ldr r1, _081A326C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081A3232
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081A3232:
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
_081A325C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A326C: .4byte 0x0000048A
