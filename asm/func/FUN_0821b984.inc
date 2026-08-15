	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	bl FUN_0821b860
	ldr r0, [r4, #0x70]
	adds r0, #1
	str r0, [r4, #0x70]
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bne _0821BA32
	ldr r0, _0821B9B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0821B9D4
	ldr r0, [r4, #0x6c]
	cmp r0, #0
	beq _0821B9B8
	str r5, [r4, #0x6c]
	b _0821B9BC
	.align 2, 0
_0821B9B4: .4byte 0x030047A4
_0821B9B8:
	movs r0, #4
	str r0, [r4, #0x6c]
_0821B9BC:
	str r5, [r4, #0x70]
	movs r0, #1
	str r0, [r4, #0x78]
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	beq _0821BA32
	movs r0, #1
	bl FUN_082405c0
	movs r0, #0
	str r0, [r4, #0x7c]
	b _0821BA20
_0821B9D4:
	bl FUN_0821b90c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0821B9FA
	str r5, [r4, #0x6c]
	str r5, [r4, #0x70]
	movs r0, #1
	str r0, [r4, #0x78]
	str r5, [r4, #0x68]
	bl Camera_Translate
	movs r0, #0x79
	bl PlaySound_082406e0
	movs r0, #0x79
	bl sound_08240740
	b _0821BA1E
_0821B9FA:
	bl FUN_0821b948
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0821BA20
	str r5, [r4, #0x6c]
	str r5, [r4, #0x70]
	movs r0, #1
	str r0, [r4, #0x78]
	str r5, [r4, #0x68]
	bl Camera_Translate
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	beq _0821BA32
	movs r0, #1
	bl FUN_082405c0
_0821BA1E:
	str r5, [r4, #0x7c]
_0821BA20:
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	beq _0821BA32
	movs r0, #0x79
	bl sound_08240960
	cmp r0, #0
	bne _0821BA32
	str r0, [r4, #0x7c]
_0821BA32:
	ldr r0, [r4, #0x6c]
	cmp r0, #7
	bls _0821BA3A
	b _0821BC4E
_0821BA3A:
	lsls r0, r0, #2
	ldr r1, _0821BA44 @ =_0821BA48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821BA44: .4byte _0821BA48
_0821BA48: @ jump table
	.4byte _0821BA68 @ case 0
	.4byte _0821BAC6 @ case 1
	.4byte _0821BB34 @ case 2
	.4byte _0821BB4A @ case 3
	.4byte _0821BBA0 @ case 4
	.4byte _0821BBC2 @ case 5
	.4byte _0821BC04 @ case 6
	.4byte _0821BC08 @ case 7
_0821BA68:
	ldr r0, [r4, #0x78]
	movs r3, #0
	str r3, [r4, #0x78]
	cmp r0, #0
	beq _0821BA90
	ldr r2, _0821BA9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0821BAA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0821BAA4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r1, r0
	ldr r0, [r4, #0x54]
	adds r0, r0, r1
	str r0, [r4, #0x74]
_0821BA90:
	ldr r0, _0821BAA8 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	ble _0821BAAC
	str r3, [r4, #0x70]
	b _0821BC4E
	.align 2, 0
_0821BA9C: .4byte 0x030046B8
_0821BAA0: .4byte 0x000003FF
_0821BAA4: .4byte 0x0203B400
_0821BAA8: .4byte 0x030044BC
_0821BAAC:
	ldr r2, [r4, #0x50]
	cmp r2, #0
	beq _0821BAB4
	b _0821BC4E
_0821BAB4:
	ldr r1, [r4, #0x70]
	ldr r0, [r4, #0x74]
	cmp r1, r0
	bge _0821BABE
	b _0821BC4E
_0821BABE:
	movs r0, #1
	str r0, [r4, #0x6c]
	str r2, [r4, #0x70]
	b _0821BC4C
_0821BAC6:
	ldr r1, [r4, #0x78]
	movs r0, #0
	str r0, [r4, #0x78]
	cmp r1, #0
	beq _0821BAEE
	movs r0, #0x79
	bl FUN_082404b0
	ldr r0, [r4, #0x58]
	cmp r0, #0
	blt _0821BAE0
	asrs r0, r0, #4
	b _0821BAE6
_0821BAE0:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_0821BAE6:
	bl FUN_082404fc
	movs r0, #1
	str r0, [r4, #0x7c]
_0821BAEE:
	ldr r0, [r4, #0x70]
	lsls r0, r0, #6
	ldr r1, [r4, #0x58]
	bl Div
	adds r2, r0, #0
	ldr r1, _0821BB14 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x64]
	muls r0, r1, r0
	cmp r0, #0
	blt _0821BB18
	asrs r0, r0, #0xc
	b _0821BB1E
	.align 2, 0
_0821BB14: .4byte 0x085B0A08
_0821BB18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821BB1E:
	adds r5, r0, #0
	str r5, [r4, #0x68]
	ldr r1, [r4, #0x70]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	bge _0821BB2C
	b _0821BC4E
_0821BB2C:
	movs r0, #2
	str r0, [r4, #0x6c]
	movs r0, #0
	b _0821BC48
_0821BB34:
	ldr r5, [r4, #0x64]
	str r5, [r4, #0x68]
	ldr r1, [r4, #0x70]
	ldr r0, [r4, #0x5c]
	cmp r1, r0
	bge _0821BB42
	b _0821BC4E
_0821BB42:
	movs r0, #3
	str r0, [r4, #0x6c]
	movs r0, #0
	b _0821BC48
_0821BB4A:
	ldr r1, [r4, #0x78]
	movs r0, #0
	str r0, [r4, #0x78]
	cmp r1, #0
	beq _0821BB68
	ldr r0, [r4, #0x60]
	cmp r0, #0
	blt _0821BB5E
	asrs r0, r0, #4
	b _0821BB64
_0821BB5E:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_0821BB64:
	bl FUN_082405c0
_0821BB68:
	ldr r0, [r4, #0x70]
	lsls r0, r0, #6
	ldr r1, [r4, #0x60]
	bl Div
	adds r2, r0, #0
	adds r2, #0x40
	ldr r1, _0821BB90 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x64]
	muls r0, r1, r0
	cmp r0, #0
	blt _0821BB94
	asrs r0, r0, #0xc
	b _0821BB9A
	.align 2, 0
_0821BB90: .4byte 0x085B0A08
_0821BB94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821BB9A:
	adds r5, r0, #0
	str r5, [r4, #0x68]
	b _0821BC3C
_0821BBA0:
	ldr r1, [r4, #0x68]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _0821BBAE
	asrs r0, r0, #2
	b _0821BBB4
_0821BBAE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0821BBB4:
	str r0, [r4, #0x68]
	adds r5, r0, #0
	cmp r5, #0
	bne _0821BC4E
	str r5, [r4, #0x6c]
	str r5, [r4, #0x70]
	b _0821BC4A
_0821BBC2:
	ldr r0, [r4, #0x70]
	lsls r0, r0, #6
	ldr r1, [r4, #0x58]
	bl Div
	adds r2, r0, #0
	ldr r1, _0821BBE8 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x64]
	muls r0, r1, r0
	cmp r0, #0
	blt _0821BBEC
	asrs r0, r0, #0xc
	b _0821BBF2
	.align 2, 0
_0821BBE8: .4byte 0x085B0A08
_0821BBEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821BBF2:
	adds r5, r0, #0
	ldr r1, [r4, #0x70]
	ldr r0, [r4, #0x58]
	cmp r1, r0
	blt _0821BC4E
	movs r0, #6
	str r0, [r4, #0x6c]
	movs r0, #0
	b _0821BC48
_0821BC04:
	ldr r5, [r4, #0x64]
	b _0821BC4E
_0821BC08:
	ldr r0, [r4, #0x70]
	lsls r0, r0, #6
	ldr r1, [r4, #0x60]
	bl Div
	adds r2, r0, #0
	adds r2, #0x40
	ldr r1, _0821BC30 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4, #0x64]
	muls r0, r1, r0
	cmp r0, #0
	blt _0821BC34
	asrs r0, r0, #0xc
	b _0821BC3A
	.align 2, 0
_0821BC30: .4byte 0x085B0A08
_0821BC34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821BC3A:
	adds r5, r0, #0
_0821BC3C:
	ldr r1, [r4, #0x70]
	ldr r0, [r4, #0x60]
	cmp r1, r0
	blt _0821BC4E
	movs r0, #0
	str r0, [r4, #0x6c]
_0821BC48:
	str r0, [r4, #0x70]
_0821BC4A:
	movs r0, #1
_0821BC4C:
	str r0, [r4, #0x78]
_0821BC4E:
	adds r0, r5, #0
	bl FUN_0823b9cc
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
