	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08228EC0
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08228EBC @ =0x00000F14
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _08228EC2
	.align 2, 0
_08228EBC: .4byte 0x00000F14
_08228EC0:
	movs r0, #0
_08228EC2:
	cmp r0, #0
	beq _08228ECE
	ldr r3, _08228F04 @ =0x00000DF4
	adds r0, r4, r3
	bl FUN_080136b4
_08228ECE:
	ldr r0, _08228F08 @ =0x00000D9C
	adds r3, r4, r0
	ldr r2, _08228F0C @ =0x00000E38
	adds r1, r4, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08228F6A
	ldr r2, _08228F10 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _08228F18
	cmp r2, #1
	bge _08228F40
	cmp r2, #0
	beq _08228F20
	ldr r0, _08228F14 @ =0x00000E3A
	adds r1, r4, r0
	b _08228F60
	.align 2, 0
_08228F04: .4byte 0x00000DF4
_08228F08: .4byte 0x00000D9C
_08228F0C: .4byte 0x00000E38
_08228F10: .4byte 0x00000DEC
_08228F14: .4byte 0x00000E3A
_08228F18:
	ldr r0, _08228F34 @ =0x00000E3A
	adds r1, r4, r0
	cmp r2, #3
	bne _08228F60
_08228F20:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228F38
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08228F5E
	.align 2, 0
_08228F34: .4byte 0x00000E3A
_08228F38:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08228F5E
_08228F40:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228F58
	ldr r2, _08228F54 @ =0x00000E3A
	adds r1, r4, r2
	movs r0, #0xff
	b _08228F5E
	.align 2, 0
_08228F54: .4byte 0x00000E3A
_08228F58:
	ldr r0, _08228F90 @ =0x00000E3A
	adds r1, r4, r0
	movs r0, #8
_08228F5E:
	strb r0, [r1]
_08228F60:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08228F6A:
	ldr r2, _08228F94 @ =0x00000DA4
	adds r1, r4, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	ldr r3, _08228F98 @ =0x00000DA5
	adds r0, r4, r3
	movs r3, #0
	ldrsb r3, [r0, r3]
	subs r2, #1
	subs r3, #1
	cmp r2, #0x3f
	bgt _08228F86
	movs r3, #0x40
	movs r2, #0x40
_08228F86:
	strb r2, [r1]
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08228F90: .4byte 0x00000E3A
_08228F94: .4byte 0x00000DA4
_08228F98: .4byte 0x00000DA5
