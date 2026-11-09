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
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08121C52
	b _081222D8
_08121C52:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08121C7C
	ldr r3, _08121C78 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08121C6A
	b _081222D8
_08121C6A:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081222D8
	.align 2, 0
_08121C78: .4byte 0x0000048C
_08121C7C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08121C8C
	b _081222D8
_08121C8C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08121C9C
	b _08121FA8
_08121C9C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08121CAE
	b _081222D8
_08121CAE:
	ldr r2, _08121D40 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08121CC2
	b _081222D8
_08121CC2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08121CD0
	b _081222D8
_08121CD0:
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
	bne _08121CE8
	b _08121E30
_08121CE8:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08121D50
	ands r3, r1
	cmp r3, #0
	beq _08121D50
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08121D0E
	rsbs r1, r1, #0
_08121D0E:
	cmp r1, #0x20
	bgt _08121D50
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08121D44 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08121D48 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08121D4C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081222D8
	.align 2, 0
_08121D40: .4byte 0x0000A007
_08121D44: .4byte 0x000004BE
_08121D48: .4byte 0x0000048C
_08121D4C: .4byte 0x0000044E
_08121D50:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08121D78 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08121D80
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08121D7C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121D78: .4byte 0x0000048A
_08121D7C: .4byte 0x03002BE0
_08121D80:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08121D9C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08121D98 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121D98: .4byte 0x03002BE0
_08121D9C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08121DB8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08121DB4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121DB4: .4byte 0x03002BE0
_08121DB8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08121DD4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08121DD0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121DD0: .4byte 0x03002BE0
_08121DD4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08121DE6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08121DEE
_08121DE6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08121DF0
_08121DEE:
	movs r3, #1
_08121DF0:
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
	ldr r5, _08121E24 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08121E12
	b _08121F68
_08121E12:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08121E28
	movs r0, #1
	b _08121E2A
	.align 2, 0
_08121E24: .4byte 0x0000049C
_08121E28:
	movs r0, #0
_08121E2A:
	cmp r0, #0
	bne _08121F0E
	b _08121F24
_08121E30:
	strh r2, [r7, #0x3e]
	ldr r1, _08121E58 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08121E60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08121E5C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121E58: .4byte 0x0000048A
_08121E5C: .4byte 0x03002BE0
_08121E60:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08121E7C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08121E78 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121E78: .4byte 0x03002BE0
_08121E7C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08121E98
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08121E94 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121E94: .4byte 0x03002BE0
_08121E98:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08121EB4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08121EB0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121EB0: .4byte 0x03002BE0
_08121EB4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08121EC6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08121ECE
_08121EC6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08121ED0
_08121ECE:
	movs r3, #1
_08121ED0:
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
	ldr r5, _08121F04 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08121F68
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08121F08
	movs r0, #1
	b _08121F0A
	.align 2, 0
_08121F04: .4byte 0x0000049C
_08121F08:
	movs r0, #0
_08121F0A:
	cmp r0, #0
	beq _08121F24
_08121F0E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08121F20 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08121F30
	.align 2, 0
_08121F20: .4byte 0x03002BE0
_08121F24:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08121F68
_08121F30:
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
_08121F68:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08121F94
	ldr r5, _08121FA0 @ =0x0000024E
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
	bls _08121F94
	strh r1, [r2]
_08121F94:
	ldr r5, _08121FA4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081222D8
	.align 2, 0
_08121FA0: .4byte 0x0000024E
_08121FA4: .4byte 0x0000048C
_08121FA8:
	ldr r0, _08121FBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08121FC0
	movs r0, #1
	b _08121FC2
	.align 2, 0
_08121FBC: .4byte 0x030047A4
_08121FC0:
	movs r0, #0
_08121FC2:
	cmp r0, #0
	beq _08121FD0
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08121FD8
_08121FD0:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08121FD8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08122010 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08122014 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08122006
	cmp r2, #0x17
	bne _08122018
_08122006:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0812203A
	.align 2, 0
_08122010: .4byte 0x0000048C
_08122014: .4byte 0x000001DF
_08122018:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08122006
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08122068 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812203A
	movs r1, #0
_0812203A:
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
	beq _08122076
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0812206C
	asrs r0, r0, #1
	b _08122072
	.align 2, 0
_08122068: .4byte 0x00000187
_0812206C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08122072:
	mov r2, sb
	strh r0, [r2]
_08122076:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08122094
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08122090 @ =0x000001DD
	adds r1, r6, r4
	b _08122108
	.align 2, 0
_08122090: .4byte 0x000001DD
_08122094:
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
	bne _081220F4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081220F4
	ldr r2, _081220E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081220E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081220EC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081220F0 @ =0x000001DD
	adds r1, r6, r4
	b _08122108
	.align 2, 0
_081220E4: .4byte 0x030046B8
_081220E8: .4byte 0x000003FF
_081220EC: .4byte 0x0203B400
_081220F0: .4byte 0x000001DD
_081220F4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _08122128 @ =0x000001DD
	adds r1, r6, r3
_08122108:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08122130
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0812212C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122128: .4byte 0x000001DD
_0812212C: .4byte 0x03002BE0
_08122130:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812214C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08122148 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122148: .4byte 0x03002BE0
_0812214C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08122168
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08122164 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122164: .4byte 0x03002BE0
_08122168:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08122184
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08122180 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122180: .4byte 0x03002BE0
_08122184:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08122196
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0812219E
_08122196:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081221A0
_0812219E:
	movs r3, #1
_081221A0:
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
	ldr r5, _081221D4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0812223C
	movs r1, #2
	ldr r2, _081221D8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081221DC
	movs r0, #1
	b _081221DE
	.align 2, 0
_081221D4: .4byte 0x0000049C
_081221D8: .4byte 0x00000474
_081221DC:
	movs r0, #0
_081221DE:
	cmp r0, #0
	beq _081221F8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081221F4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08122204
	.align 2, 0
_081221F4: .4byte 0x03002BE0
_081221F8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812223C
_08122204:
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
_0812223C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08122270
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08122270
	ldr r0, _08122288 @ =0x0000024E
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
	bls _08122270
	strh r1, [r2]
_08122270:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0812228C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08122290 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08122294
	movs r0, #1
	b _08122296
	.align 2, 0
_08122288: .4byte 0x0000024E
_0812228C: .4byte 0x030046A0
_08122290: .4byte 0x00000934
_08122294:
	movs r0, #0
_08122296:
	ldr r1, _081222E8 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081222AE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081222AE:
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
_081222D8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081222E8: .4byte 0x0000048A
