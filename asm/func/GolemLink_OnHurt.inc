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
	beq _081B975E
	b _081B9DE4
_081B975E:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081B9788
	ldr r3, _081B9784 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B9776
	b _081B9DE4
_081B9776:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081B9DE4
	.align 2, 0
_081B9784: .4byte 0x0000048C
_081B9788:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081B9798
	b _081B9DE4
_081B9798:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081B97A8
	b _081B9AB4
_081B97A8:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081B97BA
	b _081B9DE4
_081B97BA:
	ldr r2, _081B984C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081B97CE
	b _081B9DE4
_081B97CE:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B97DC
	b _081B9DE4
_081B97DC:
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
	bne _081B97F4
	b _081B993C
_081B97F4:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081B985C
	ands r3, r1
	cmp r3, #0
	beq _081B985C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081B981A
	rsbs r1, r1, #0
_081B981A:
	cmp r1, #0x20
	bgt _081B985C
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081B9850 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081B9854 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081B9858 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081B9DE4
	.align 2, 0
_081B984C: .4byte 0x0000A007
_081B9850: .4byte 0x000004BE
_081B9854: .4byte 0x0000048C
_081B9858: .4byte 0x0000044E
_081B985C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081B9884 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081B988C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9888 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B9884: .4byte 0x0000048A
_081B9888: .4byte 0x03002BE0
_081B988C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081B98A8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081B98A4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B98A4: .4byte 0x03002BE0
_081B98A8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081B98C4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081B98C0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B98C0: .4byte 0x03002BE0
_081B98C4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081B98E0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081B98DC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081B98FA
	.align 2, 0
_081B98DC: .4byte 0x03002BE0
_081B98E0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081B98F2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081B98FA
_081B98F2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B98FC
_081B98FA:
	movs r3, #1
_081B98FC:
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
	ldr r5, _081B9930 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081B991E
	b _081B9A74
_081B991E:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9934
	movs r0, #1
	b _081B9936
	.align 2, 0
_081B9930: .4byte 0x0000049C
_081B9934:
	movs r0, #0
_081B9936:
	cmp r0, #0
	bne _081B9A1A
	b _081B9A30
_081B993C:
	strh r2, [r7, #0x3e]
	ldr r1, _081B9964 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081B996C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9968 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B9964: .4byte 0x0000048A
_081B9968: .4byte 0x03002BE0
_081B996C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081B9988
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081B9984 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B9984: .4byte 0x03002BE0
_081B9988:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081B99A4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081B99A0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B99A0: .4byte 0x03002BE0
_081B99A4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081B99C0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081B99BC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081B99DA
	.align 2, 0
_081B99BC: .4byte 0x03002BE0
_081B99C0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081B99D2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081B99DA
_081B99D2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B99DC
_081B99DA:
	movs r3, #1
_081B99DC:
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
	ldr r5, _081B9A10 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081B9A74
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9A14
	movs r0, #1
	b _081B9A16
	.align 2, 0
_081B9A10: .4byte 0x0000049C
_081B9A14:
	movs r0, #0
_081B9A16:
	cmp r0, #0
	beq _081B9A30
_081B9A1A:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9A2C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081B9A3C
	.align 2, 0
_081B9A2C: .4byte 0x03002BE0
_081B9A30:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081B9A74
_081B9A3C:
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
_081B9A74:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081B9AA0
	ldr r5, _081B9AAC @ =0x0000024E
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
	bls _081B9AA0
	strh r1, [r2]
_081B9AA0:
	ldr r5, _081B9AB0 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081B9DE4
	.align 2, 0
_081B9AAC: .4byte 0x0000024E
_081B9AB0: .4byte 0x0000048C
_081B9AB4:
	ldr r0, _081B9AC8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B9ACC
	movs r0, #1
	b _081B9ACE
	.align 2, 0
_081B9AC8: .4byte 0x030047A4
_081B9ACC:
	movs r0, #0
_081B9ACE:
	cmp r0, #0
	beq _081B9ADC
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081B9AE4
_081B9ADC:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081B9AE4:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081B9B1C @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081B9B20 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081B9B12
	cmp r2, #0x17
	bne _081B9B24
_081B9B12:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081B9B46
	.align 2, 0
_081B9B1C: .4byte 0x0000048C
_081B9B20: .4byte 0x000001DF
_081B9B24:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081B9B12
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081B9B74 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081B9B46
	movs r1, #0
_081B9B46:
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
	beq _081B9B82
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081B9B78
	asrs r0, r0, #1
	b _081B9B7E
	.align 2, 0
_081B9B74: .4byte 0x00000187
_081B9B78:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081B9B7E:
	mov r2, sb
	strh r0, [r2]
_081B9B82:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081B9BA0
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081B9B9C @ =0x000001DD
	adds r1, r6, r4
	b _081B9C14
	.align 2, 0
_081B9B9C: .4byte 0x000001DD
_081B9BA0:
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
	bne _081B9C00
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081B9C00
	ldr r2, _081B9BF0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081B9BF4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081B9BF8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081B9BFC @ =0x000001DD
	adds r1, r6, r4
	b _081B9C14
	.align 2, 0
_081B9BF0: .4byte 0x030046B8
_081B9BF4: .4byte 0x000003FF
_081B9BF8: .4byte 0x0203B400
_081B9BFC: .4byte 0x000001DD
_081B9C00:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081B9C34 @ =0x000001DD
	adds r1, r6, r3
_081B9C14:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081B9C3C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081B9C38 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C34: .4byte 0x000001DD
_081B9C38: .4byte 0x03002BE0
_081B9C3C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081B9C58
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081B9C54 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C54: .4byte 0x03002BE0
_081B9C58:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081B9C74
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9C70 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C70: .4byte 0x03002BE0
_081B9C74:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081B9C90
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081B9C8C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081B9CAA
	.align 2, 0
_081B9C8C: .4byte 0x03002BE0
_081B9C90:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081B9CA2
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081B9CAA
_081B9CA2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B9CAC
_081B9CAA:
	movs r3, #1
_081B9CAC:
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
	ldr r5, _081B9CE0 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081B9D48
	movs r1, #2
	ldr r2, _081B9CE4 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9CE8
	movs r0, #1
	b _081B9CEA
	.align 2, 0
_081B9CE0: .4byte 0x0000049C
_081B9CE4: .4byte 0x00000474
_081B9CE8:
	movs r0, #0
_081B9CEA:
	cmp r0, #0
	beq _081B9D04
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081B9D00 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081B9D10
	.align 2, 0
_081B9D00: .4byte 0x03002BE0
_081B9D04:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081B9D48
_081B9D10:
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
_081B9D48:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081B9D7C
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081B9D7C
	ldr r0, _081B9D94 @ =0x0000024E
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
	bls _081B9D7C
	strh r1, [r2]
_081B9D7C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081B9D98 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081B9D9C @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081B9DA0
	movs r0, #1
	b _081B9DA2
	.align 2, 0
_081B9D94: .4byte 0x0000024E
_081B9D98: .4byte 0x030046A0
_081B9D9C: .4byte 0x00000934
_081B9DA0:
	movs r0, #0
_081B9DA2:
	ldr r1, _081B9DF4 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081B9DBA
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081B9DBA:
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
_081B9DE4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9DF4: .4byte 0x0000048A
