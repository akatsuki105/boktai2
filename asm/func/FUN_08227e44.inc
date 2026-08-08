	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r6, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08227E74
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08227E70 @ =0x00000F14
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	b _08227E76
	.align 2, 0
_08227E70: .4byte 0x00000F14
_08227E74:
	movs r0, #0
_08227E76:
	cmp r0, #0
	beq _08227EB0
	ldr r3, _08227EF4 @ =0x00000F15
	adds r1, r6, r3
	movs r0, #4
	strb r0, [r1]
	ldr r1, _08227EF8 @ =0x00000DE4
	adds r0, r6, r1
	ldr r2, _08227EFC @ =0x00000E34
	adds r1, r6, r2
	ldr r1, [r1]
	adds r3, #0x13
	adds r2, r6, r3
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	adds r0, r6, #0
	bl FUN_08223998
	ldr r1, _08227F00 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080136b4
	adds r0, r6, #0
	bl FUN_082239fc
_08227EB0:
	ldr r2, _08227F04 @ =0x00000F4C
	adds r0, r6, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08227EC0
	adds r0, r6, #0
	bl _call_via_r1
_08227EC0:
	ldr r0, _08227F08 @ =0x00000D9C
	adds r3, r6, r0
	ldr r2, _08227F0C @ =0x00000E38
	adds r1, r6, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08227F6A
	ldr r2, _08227F10 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _08227F18
	cmp r2, #1
	bge _08227F40
	cmp r2, #0
	beq _08227F20
	ldr r0, _08227F14 @ =0x00000E3A
	adds r1, r6, r0
	b _08227F60
	.align 2, 0
_08227EF4: .4byte 0x00000F15
_08227EF8: .4byte 0x00000DE4
_08227EFC: .4byte 0x00000E34
_08227F00: .4byte 0x00000DF4
_08227F04: .4byte 0x00000F4C
_08227F08: .4byte 0x00000D9C
_08227F0C: .4byte 0x00000E38
_08227F10: .4byte 0x00000DEC
_08227F14: .4byte 0x00000E3A
_08227F18:
	ldr r0, _08227F34 @ =0x00000E3A
	adds r1, r6, r0
	cmp r2, #3
	bne _08227F60
_08227F20:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08227F38
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08227F5E
	.align 2, 0
_08227F34: .4byte 0x00000E3A
_08227F38:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08227F5E
_08227F40:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08227F58
	ldr r2, _08227F54 @ =0x00000E3A
	adds r1, r6, r2
	movs r0, #0xff
	b _08227F5E
	.align 2, 0
_08227F54: .4byte 0x00000E3A
_08227F58:
	ldr r0, _08227FA0 @ =0x00000E3A
	adds r1, r6, r0
	movs r0, #8
_08227F5E:
	strb r0, [r1]
_08227F60:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08227F6A:
	ldr r2, _08227FA4 @ =0x00000D9C
	adds r5, r6, r2
	ldr r3, _08227FA8 @ =0x00000DE4
	adds r4, r6, r3
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08227FAC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08227FB4
	.align 2, 0
_08227FA0: .4byte 0x00000E3A
_08227FA4: .4byte 0x00000D9C
_08227FA8: .4byte 0x00000DE4
_08227FAC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08227FB4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08227FD8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08227FE0
_08227FD8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08227FE0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08228018 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0822805E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08228022
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0822801C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08228038
	.align 2, 0
_08228018: .4byte 0x0000FFFF
_0822801C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08228036
_08228022:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08228036
	strh r1, [r4, #8]
	movs r2, #1
	b _08228038
_08228036:
	movs r2, #0
_08228038:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08228060
	movs r0, #1
	strb r0, [r4, #7]
	b _08228060
_0822805E:
	movs r2, #0
_08228060:
	ldr r3, _08228070 @ =0x00000F14
	adds r0, r6, r3
	strb r2, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08228070: .4byte 0x00000F14
