	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08228DB8
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08228DB4 @ =0x00000F14
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _08228DBA
	.align 2, 0
_08228DB4: .4byte 0x00000F14
_08228DB8:
	movs r0, #0
_08228DBA:
	cmp r0, #0
	beq _08228DC6
	ldr r3, _08228DFC @ =0x00000DF4
	adds r0, r4, r3
	bl FUN_080136b4
_08228DC6:
	ldr r0, _08228E00 @ =0x00000D9C
	adds r3, r4, r0
	ldr r2, _08228E04 @ =0x00000E38
	adds r1, r4, r2
	ldrh r2, [r1]
	adds r0, r2, #1
	strh r0, [r1]
	movs r1, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	bne _08228E62
	ldr r2, _08228E08 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #2
	bgt _08228E10
	cmp r2, #1
	bge _08228E38
	cmp r2, #0
	beq _08228E18
	ldr r0, _08228E0C @ =0x00000E3A
	adds r1, r4, r0
	b _08228E58
	.align 2, 0
_08228DFC: .4byte 0x00000DF4
_08228E00: .4byte 0x00000D9C
_08228E04: .4byte 0x00000E38
_08228E08: .4byte 0x00000DEC
_08228E0C: .4byte 0x00000E3A
_08228E10:
	ldr r0, _08228E2C @ =0x00000E3A
	adds r1, r4, r0
	cmp r2, #3
	bne _08228E58
_08228E18:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228E30
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #1
	b _08228E56
	.align 2, 0
_08228E2C: .4byte 0x00000E3A
_08228E30:
	adds r1, r3, #0
	adds r1, #0x9e
	movs r0, #0xf8
	b _08228E56
_08228E38:
	ldr r0, [r3]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08228E50
	ldr r2, _08228E4C @ =0x00000E3A
	adds r1, r4, r2
	movs r0, #0xff
	b _08228E56
	.align 2, 0
_08228E4C: .4byte 0x00000E3A
_08228E50:
	ldr r0, _08228E88 @ =0x00000E3A
	adds r1, r4, r0
	movs r0, #8
_08228E56:
	strb r0, [r1]
_08228E58:
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
_08228E62:
	ldr r2, _08228E8C @ =0x00000DA4
	adds r1, r4, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	ldr r3, _08228E90 @ =0x00000DA5
	adds r0, r4, r3
	movs r3, #0
	ldrsb r3, [r0, r3]
	adds r2, #1
	adds r3, #1
	cmp r2, #0x7f
	ble _08228E7E
	movs r3, #0x7f
	movs r2, #0x7f
_08228E7E:
	strb r2, [r1]
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08228E88: .4byte 0x00000E3A
_08228E8C: .4byte 0x00000DA4
_08228E90: .4byte 0x00000DA5
