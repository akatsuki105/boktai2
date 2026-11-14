	push {r4, r5, lr}
	adds r3, r1, #0
	adds r5, r0, #0
	movs r0, #1
	adds r2, r3, #0
	adds r2, #0xad
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08224E30
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #1
	b _08224E32
_08224E30:
	movs r0, #0
_08224E32:
	cmp r0, #0
	beq _08224E78
	ldr r1, _08224E58 @ =0x00000F58
	adds r0, r5, r1
	movs r1, #0xa
	str r1, [r0]
	ldr r0, _08224E5C @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _08224E64
	cmp r0, #0
	beq _08224E64
	cmp r0, #4
	beq _08224E64
	ldr r2, _08224E60 @ =0x00000F2B
	adds r1, r5, r2
	movs r0, #1
	b _08224E6A
	.align 2, 0
_08224E58: .4byte 0x00000F58
_08224E5C: .4byte 0x030047E0
_08224E60: .4byte 0x00000F2B
_08224E64:
	ldr r0, _08224EF4 @ =0x00000F2B
	adds r1, r5, r0
	movs r0, #0
_08224E6A:
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xca
	ldrb r1, [r0]
	ldr r2, _08224EF8 @ =0x00000F33
	adds r0, r5, r2
	strb r1, [r0]
_08224E78:
	ldr r1, _08224EFC @ =0x00000F58
	adds r0, r5, r1
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08224EEC
	ldr r2, _08224F00 @ =0x00000F16
	adds r4, r5, r2
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08224F04 @ =0x00000F18
	adds r3, r5, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08224EDE
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08224EDE
	ldr r2, _08224F08 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r2, _08224F0C @ =0x00000F42
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08224F10 @ =0x00000DF2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
_08224EDE:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08224EEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08224EF4: .4byte 0x00000F2B
_08224EF8: .4byte 0x00000F33
_08224EFC: .4byte 0x00000F58
_08224F00: .4byte 0x00000F16
_08224F04: .4byte 0x00000F18
_08224F08: .4byte 0x00000DEC
_08224F0C: .4byte 0x00000F42
_08224F10: .4byte 0x00000DF2
