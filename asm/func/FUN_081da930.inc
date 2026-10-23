	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA97A
	bl Marquee_Clear
	ldr r1, _081DA998 @ =0x00000286
	adds r0, r5, r1
	ldrb r4, [r0]
	movs r3, #0x9c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	adds r4, #0x19
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl Marquee_SetText
	adds r0, r5, #0
	bl FUN_081da730
	ldr r1, _081DA99C @ =0x0000029D
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081DA9A0 @ =0x0000029E
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	strb r1, [r6]
_081DA97A:
	ldr r0, _081DA9A0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DA9A4
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DAC98
	.align 2, 0
_081DA998: .4byte 0x00000286
_081DA99C: .4byte 0x0000029D
_081DA9A0: .4byte 0x0000029E
_081DA9A4:
	ldr r1, _081DA9C0 @ =0x0000029D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r3, _081DA9C4 @ =0x00000285
	adds r6, r5, r3
	movs r3, #0
	ldr r1, _081DA9C8 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DA9CC
	movs r3, #1
	b _081DAA06
	.align 2, 0
_081DA9C0: .4byte 0x0000029D
_081DA9C4: .4byte 0x00000285
_081DA9C8: .4byte 0x030044E0
_081DA9CC:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DA9D8
	movs r3, #2
	b _081DAA06
_081DA9D8:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DA9E4
	movs r3, #4
	b _081DAA06
_081DA9E4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DA9F0
	movs r3, #8
	b _081DAA06
_081DA9F0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DA9FC
	movs r3, #0x20
	b _081DAA06
_081DA9FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DAA06
	movs r3, #0x10
_081DAA06:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DAA4E
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DAA4C
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DAA22
	movs r0, #1
	b _081DAA2C
_081DAA22:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DAA2E
	movs r0, #2
_081DAA2C:
	orrs r3, r0
_081DAA2E:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DAA3C
	movs r0, #4
	b _081DAA46
_081DAA3C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DAA48
	movs r0, #8
_081DAA46:
	orrs r3, r0
_081DAA48:
	movs r0, #0
	b _081DAA4E
_081DAA4C:
	adds r0, #1
_081DAA4E:
	strb r0, [r6]
	movs r6, #1
	adds r0, r3, #0
	ands r0, r6
	cmp r0, #0
	beq _081DAA70
	cmp r4, #0
	bne _081DAA62
	movs r4, #2
	b _081DAA64
_081DAA62:
	subs r4, #1
_081DAA64:
	ldr r0, _081DAA6C @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAA6C: .4byte 0x00000285
_081DAA70:
	movs r2, #2
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _081DAA86
	cmp r4, #2
	bne _081DAA82
	movs r4, #0
	b _081DABE8
_081DAA82:
	adds r4, #1
	b _081DABE8
_081DAA86:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DAB54
	ldr r1, _081DAAA4 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAAD8
	cmp r0, #1
	bgt _081DAAA8
	cmp r0, #0
	beq _081DAAAE
	b _081DAB42
	.align 2, 0
_081DAAA4: .4byte 0x0000029D
_081DAAA8:
	cmp r0, #2
	beq _081DAB0C
	b _081DAB42
_081DAAAE:
	ldr r3, _081DAAC4 @ =0x00000286
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAACC
	ldr r1, _081DAAC8 @ =0x00000289
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAACE
	.align 2, 0
_081DAAC4: .4byte 0x00000286
_081DAAC8: .4byte 0x00000289
_081DAACC:
	subs r1, r2, #1
_081DAACE:
	ldr r3, _081DAAD4 @ =0x00000286
	b _081DAAF8
	.align 2, 0
_081DAAD4: .4byte 0x00000286
_081DAAD8:
	ldr r1, _081DAAEC @ =0x00000287
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAAF4
	ldr r3, _081DAAF0 @ =0x0000028A
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAAF6
	.align 2, 0
_081DAAEC: .4byte 0x00000287
_081DAAF0: .4byte 0x0000028A
_081DAAF4:
	subs r1, r2, #1
_081DAAF6:
	ldr r3, _081DAB08 @ =0x00000287
_081DAAF8:
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB42
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DAB42
	.align 2, 0
_081DAB08: .4byte 0x00000287
_081DAB0C:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAB28
	ldr r3, _081DAB24 @ =0x0000028B
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAB2A
	.align 2, 0
_081DAB24: .4byte 0x0000028B
_081DAB28:
	subs r1, r2, #1
_081DAB2A:
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB3C
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAB3C:
	adds r0, r5, #0
	bl FUN_081da814
_081DAB42:
	adds r0, r5, #0
	bl FUN_081da730
	ldr r0, _081DAB50 @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAB50: .4byte 0x00000285
_081DAB54:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DABFC
	ldr r1, _081DAB70 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAB8C
	cmp r0, #1
	bgt _081DAB74
	cmp r0, #0
	beq _081DAB7A
	b _081DABE2
	.align 2, 0
_081DAB70: .4byte 0x0000029D
_081DAB74:
	cmp r0, #2
	beq _081DABB8
	b _081DABE2
_081DAB7A:
	ldr r0, _081DAB84 @ =0x00000286
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DAB88 @ =0x00000289
	b _081DAB94
	.align 2, 0
_081DAB84: .4byte 0x00000286
_081DAB88: .4byte 0x00000289
_081DAB8C:
	ldr r0, _081DABB0 @ =0x00000287
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABB4 @ =0x0000028A
_081DAB94:
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABA2
	movs r1, #0
_081DABA2:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABE2
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DABE2
	.align 2, 0
_081DABB0: .4byte 0x00000287
_081DABB4: .4byte 0x0000028A
_081DABB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABF4 @ =0x0000028B
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABD0
	movs r1, #0
_081DABD0:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABDC
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DABDC:
	adds r0, r5, #0
	bl FUN_081da814
_081DABE2:
	adds r0, r5, #0
	bl FUN_081da730
_081DABE8:
	ldr r3, _081DABF8 @ =0x00000285
	adds r1, r5, r3
_081DABEC:
	movs r0, #0
	strb r0, [r1]
	b _081DAC74
	.align 2, 0
_081DABF4: .4byte 0x0000028B
_081DABF8: .4byte 0x00000285
_081DABFC:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DAC28
	ldr r1, _081DAC24 @ =FUN_081da890
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC24: .4byte FUN_081da890
_081DAC28:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DAC74
	ldr r0, _081DAC44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAC48
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DAC48
	movs r0, #1
	b _081DAC4A
	.align 2, 0
_081DAC44: .4byte 0x03002C68
_081DAC48:
	movs r0, #0
_081DAC4A:
	cmp r0, #0
	bne _081DAC74
	ldr r1, _081DAC70 @ =FUN_081da8d4
	movs r2, #1
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC70: .4byte FUN_081da8d4
_081DAC74:
	ldr r0, _081DACA0 @ =0x0000029D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DAC8C
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081da468
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAC8C:
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
_081DAC98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DACA0: .4byte 0x0000029D
