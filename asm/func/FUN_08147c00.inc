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
	beq _08147C22
	b _081482A8
_08147C22:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08147C4C
	ldr r3, _08147C48 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08147C3A
	b _081482A8
_08147C3A:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081482A8
	.align 2, 0
_08147C48: .4byte 0x0000048C
_08147C4C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08147C5C
	b _081482A8
_08147C5C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08147C6C
	b _08147F78
_08147C6C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08147C7E
	b _081482A8
_08147C7E:
	ldr r2, _08147D10 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08147C92
	b _081482A8
_08147C92:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08147CA0
	b _081482A8
_08147CA0:
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
	bne _08147CB8
	b _08147E00
_08147CB8:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08147D20
	ands r3, r1
	cmp r3, #0
	beq _08147D20
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08147CDE
	rsbs r1, r1, #0
_08147CDE:
	cmp r1, #0x20
	bgt _08147D20
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08147D14 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08147D18 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08147D1C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081482A8
	.align 2, 0
_08147D10: .4byte 0x0000A007
_08147D14: .4byte 0x000004BE
_08147D18: .4byte 0x0000048C
_08147D1C: .4byte 0x0000044E
_08147D20:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08147D48 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08147D50
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08147D4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147D48: .4byte 0x0000048A
_08147D4C: .4byte 0x03002BE0
_08147D50:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08147D6C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08147D68 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147D68: .4byte 0x03002BE0
_08147D6C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08147D88
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08147D84 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147D84: .4byte 0x03002BE0
_08147D88:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08147DA4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08147DA0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147DA0: .4byte 0x03002BE0
_08147DA4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08147DB6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08147DBE
_08147DB6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08147DC0
_08147DBE:
	movs r3, #1
_08147DC0:
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
	ldr r5, _08147DF4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08147DE2
	b _08147F38
_08147DE2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08147DF8
	movs r0, #1
	b _08147DFA
	.align 2, 0
_08147DF4: .4byte 0x0000049C
_08147DF8:
	movs r0, #0
_08147DFA:
	cmp r0, #0
	bne _08147EDE
	b _08147EF4
_08147E00:
	strh r2, [r7, #0x3e]
	ldr r1, _08147E28 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08147E30
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08147E2C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E28: .4byte 0x0000048A
_08147E2C: .4byte 0x03002BE0
_08147E30:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08147E4C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08147E48 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E48: .4byte 0x03002BE0
_08147E4C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08147E68
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08147E64 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E64: .4byte 0x03002BE0
_08147E68:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08147E84
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08147E80 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E80: .4byte 0x03002BE0
_08147E84:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08147E96
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08147E9E
_08147E96:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08147EA0
_08147E9E:
	movs r3, #1
_08147EA0:
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
	ldr r5, _08147ED4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08147F38
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08147ED8
	movs r0, #1
	b _08147EDA
	.align 2, 0
_08147ED4: .4byte 0x0000049C
_08147ED8:
	movs r0, #0
_08147EDA:
	cmp r0, #0
	beq _08147EF4
_08147EDE:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08147EF0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08147F00
	.align 2, 0
_08147EF0: .4byte 0x03002BE0
_08147EF4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08147F38
_08147F00:
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
_08147F38:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08147F64
	ldr r5, _08147F70 @ =0x0000024E
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
	bls _08147F64
	strh r1, [r2]
_08147F64:
	ldr r5, _08147F74 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081482A8
	.align 2, 0
_08147F70: .4byte 0x0000024E
_08147F74: .4byte 0x0000048C
_08147F78:
	ldr r0, _08147F8C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08147F90
	movs r0, #1
	b _08147F92
	.align 2, 0
_08147F8C: .4byte 0x030047A4
_08147F90:
	movs r0, #0
_08147F92:
	cmp r0, #0
	beq _08147FA0
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _08147FA8
_08147FA0:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_08147FA8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08147FE0 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08147FE4 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08147FD6
	cmp r2, #0x17
	bne _08147FE8
_08147FD6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0814800A
	.align 2, 0
_08147FE0: .4byte 0x0000048C
_08147FE4: .4byte 0x000001DF
_08147FE8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08147FD6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08148038 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814800A
	movs r1, #0
_0814800A:
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
	beq _08148046
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0814803C
	asrs r0, r0, #1
	b _08148042
	.align 2, 0
_08148038: .4byte 0x00000187
_0814803C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08148042:
	mov r2, sb
	strh r0, [r2]
_08148046:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08148064
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08148060 @ =0x000001DD
	adds r1, r6, r4
	b _081480D8
	.align 2, 0
_08148060: .4byte 0x000001DD
_08148064:
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
	bne _081480C4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081480C4
	ldr r2, _081480B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081480B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081480BC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081480C0 @ =0x000001DD
	adds r1, r6, r4
	b _081480D8
	.align 2, 0
_081480B4: .4byte 0x030046B8
_081480B8: .4byte 0x000003FF
_081480BC: .4byte 0x0203B400
_081480C0: .4byte 0x000001DD
_081480C4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081480F8 @ =0x000001DD
	adds r1, r6, r3
_081480D8:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08148100
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081480FC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_081480F8: .4byte 0x000001DD
_081480FC: .4byte 0x03002BE0
_08148100:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814811C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08148118 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_08148118: .4byte 0x03002BE0
_0814811C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08148138
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08148134 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_08148134: .4byte 0x03002BE0
_08148138:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08148154
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08148150 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_08148150: .4byte 0x03002BE0
_08148154:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08148166
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0814816E
_08148166:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08148170
_0814816E:
	movs r3, #1
_08148170:
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
	ldr r5, _081481A4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0814820C
	movs r1, #2
	ldr r2, _081481A8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081481AC
	movs r0, #1
	b _081481AE
	.align 2, 0
_081481A4: .4byte 0x0000049C
_081481A8: .4byte 0x00000474
_081481AC:
	movs r0, #0
_081481AE:
	cmp r0, #0
	beq _081481C8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081481C4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081481D4
	.align 2, 0
_081481C4: .4byte 0x03002BE0
_081481C8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0814820C
_081481D4:
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
_0814820C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08148240
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08148240
	ldr r0, _08148258 @ =0x0000024E
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
	bls _08148240
	strh r1, [r2]
_08148240:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0814825C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08148260 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08148264
	movs r0, #1
	b _08148266
	.align 2, 0
_08148258: .4byte 0x0000024E
_0814825C: .4byte 0x030046A0
_08148260: .4byte 0x00000934
_08148264:
	movs r0, #0
_08148266:
	ldr r1, _081482B8 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0814827E
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_0814827E:
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
_081482A8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081482B8: .4byte 0x0000048A
