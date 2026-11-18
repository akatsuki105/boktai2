	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _081C8A44 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C8A48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C8A4A
	.align 2, 0
_081C8A44: .4byte 0x0000046D
_081C8A48:
	movs r0, #0
_081C8A4A:
	cmp r0, #0
	beq _081C8AA8
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081C8A60
	asrs r1, r0, #2
	b _081C8A66
_081C8A60:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081C8A66:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _081C8A80
	asrs r1, r0, #2
	b _081C8A86
_081C8A80:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081C8A86:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081C8AD8 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_081C8AA8:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081C8ADC
	asrs r0, r0, #2
	b _081C8AE2
	.align 2, 0
_081C8AD8: .4byte 0xFFFFFEFF
_081C8ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081C8AE2:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081C8B02
	asrs r0, r0, #2
	b _081C8B08
_081C8B02:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081C8B08:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081C8B12
	movs r3, #0xc8
	b _081C8B1C
_081C8B12:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081C8B1C
	adds r3, r0, #0
_081C8B1C:
	cmp r2, #0xc8
	ble _081C8B24
	movs r2, #0xc8
	b _081C8B2E
_081C8B24:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081C8B2E
	adds r2, r0, #0
_081C8B2E:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081C8B52
	cmp r2, #0
	bne _081C8B52
	movs r0, #1
	b _081C8B54
_081C8B52:
	movs r0, #0
_081C8B54:
	cmp r0, #0
	bne _081C8B5C
	bl _081C9A40
_081C8B5C:
	ldr r6, _081C8BA8 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8B6A
	bl _081C9A40
_081C8B6A:
	ldr r0, _081C8BAC @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	strh r3, [r2]
	ldr r4, _081C8BB0 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x9c]
	cmp r0, #0
	beq _081C8BB4
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081C9A50
	.align 2, 0
_081C8BA8: .4byte 0x0000046E
_081C8BAC: .4byte 0x0000046B
_081C8BB0: .4byte 0x0000049C
_081C8BB4:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _081C8BC4
	b _081C92F4
_081C8BC4:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081C8C20 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081C8C1A
	cmp r1, #0
	blt _081C8C1A
	ldr r0, _081C8C24 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C8C1A
	ldr r0, _081C8C28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8C2C
_081C8C1A:
	movs r4, #0
	b _081C8C3A
	.align 2, 0
_081C8C20: .4byte 0x03002BE0
_081C8C24: .4byte 0x030046A8
_081C8C28: .4byte 0x030046AC
_081C8C2C:
	ldr r0, _081C8C4C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C8C3A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C8C50
	adds r0, #4
	b _081C8C5C
	.align 2, 0
_081C8C4C: .4byte 0x030046A4
_081C8C50:
	ldr r0, _081C8C70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C8C5C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C8C74
	cmp r2, #2
	beq _081C8C78
	b _081C8C7C
	.align 2, 0
_081C8C70: .4byte 0x030046A4
_081C8C74:
	ldrb r0, [r5, #4]
	b _081C8C7A
_081C8C78:
	ldrb r0, [r5]
_081C8C7A:
	subs r1, r1, r0
_081C8C7C:
	strh r1, [r5, #2]
	ldr r0, _081C8C90 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C8C94
	movs r0, #1
	b _081C8C96
	.align 2, 0
_081C8C90: .4byte 0x030047A4
_081C8C94:
	movs r0, #0
_081C8C96:
	cmp r0, #0
	beq _081C8CD4
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081C8CB6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C8CB2
	adds r2, r0, #0
_081C8CB2:
	cmp r2, #0
	bge _081C8CC0
_081C8CB6:
	ldr r3, _081C8CBC @ =0x000005C4
	adds r0, r7, r3
	b _081C91F0
	.align 2, 0
_081C8CBC: .4byte 0x000005C4
_081C8CC0:
	ldr r1, _081C8CD0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C8D1C
	.align 2, 0
_081C8CD0: .4byte 0x03002BE0
_081C8CD4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C8D00
	cmp r1, #0
	blt _081C8D00
	ldr r0, _081C8D04 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C8D00
	ldr r0, _081C8D08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8D0C
_081C8D00:
	movs r5, #0
	b _081C8D1A
	.align 2, 0
_081C8D04: .4byte 0x030046A8
_081C8D08: .4byte 0x030046AC
_081C8D0C:
	ldr r0, _081C8D54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C8D1A:
	movs r2, #0
_081C8D1C:
	ldr r6, _081C8D58 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C8D3C
	ldr r1, _081C8D5C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C8D3C
	b _081C9130
_081C8D3C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x9c]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	cmp r0, #0
	beq _081C8D60
	movs r0, #0
	b _081C9206
	.align 2, 0
_081C8D54: .4byte 0x030046A4
_081C8D58: .4byte 0x00000256
_081C8D5C: .4byte 0x03002BE0
_081C8D60:
	ldr r3, _081C8E04 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _081C8E1C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081C8E08 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x14]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081C8E0C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x18]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081C8E10 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C8E14 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x10]
	str r6, [r1]
	ldr r6, _081C8E18 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xb0]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081C8FEE
	.align 2, 0
_081C8E04: .4byte 0x00000222
_081C8E08: .4byte 0x0000046D
_081C8E0C: .4byte 0x0000046B
_081C8E10: .4byte 0x00000469
_081C8E14: .4byte 0x00000484
_081C8E18: .4byte 0x0000046C
_081C8E1C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081C8EE0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _081C8EE4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081C8EE8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081C8EEC @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081C8EF0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081C8EF4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _081C8EDA
	cmp r1, #0
	blt _081C8EDA
	ldr r0, _081C8EF8 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081C8EDA
	ldr r0, _081C8EFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8F00
_081C8EDA:
	movs r4, #0
	b _081C8F10
	.align 2, 0
_081C8EE0: .4byte 0x0000046D
_081C8EE4: .4byte 0x0000046B
_081C8EE8: .4byte 0x00000553
_081C8EEC: .4byte 0x00000469
_081C8EF0: .4byte 0x00000484
_081C8EF4: .4byte 0x0000046C
_081C8EF8: .4byte 0x030046A8
_081C8EFC: .4byte 0x030046AC
_081C8F00:
	ldr r0, _081C8F20 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081C8F10:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C8F24
	adds r0, #4
	b _081C8F30
	.align 2, 0
_081C8F20: .4byte 0x030046A4
_081C8F24:
	ldr r0, _081C8F44 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C8F30:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C8F48
	cmp r2, #2
	beq _081C8F4E
	b _081C8F54
	.align 2, 0
_081C8F44: .4byte 0x030046A4
_081C8F48:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _081C8F52
_081C8F4E:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_081C8F52:
	subs r1, r1, r0
_081C8F54:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C8F80
	cmp r1, #0
	blt _081C8F80
	ldr r0, _081C8F84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C8F80
	ldr r0, _081C8F88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8F8C
_081C8F80:
	movs r4, #0
	b _081C8F9A
	.align 2, 0
_081C8F84: .4byte 0x030046A8
_081C8F88: .4byte 0x030046AC
_081C8F8C:
	ldr r0, _081C8FB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C8F9A:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C8FB4
	adds r0, #4
	b _081C8FC0
	.align 2, 0
_081C8FB0: .4byte 0x030046A4
_081C8FB4:
	ldr r0, _081C8FD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C8FC0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C8FD8
	cmp r3, #2
	beq _081C8FDC
	b _081C8FE0
	.align 2, 0
_081C8FD4: .4byte 0x030046A4
_081C8FD8:
	ldrb r0, [r5, #4]
	b _081C8FDE
_081C8FDC:
	ldrb r0, [r5]
_081C8FDE:
	subs r2, r2, r0
_081C8FE0:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C8FEE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081C9018 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081C90F8
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C901C
	movs r0, #1
	b _081C901E
	.align 2, 0
_081C9018: .4byte 0x00000482
_081C901C:
	movs r0, #0
_081C901E:
	ldr r1, _081C9108 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081C90F8
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081C910C @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081C9110 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081C9114 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081C9118 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081C911C @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081C9120 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081C9124 @ =0x030046B8
	adds r2, r4, #0
_081C9066:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081C9128 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081C912C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081C908A
	adds r3, #1
	cmp r3, #3
	ble _081C9066
	adds r0, r4, #0
_081C908A:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081C90F8:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081C9206
	.align 2, 0
_081C9108: .4byte 0x00000482
_081C910C: .4byte 0x0000054F
_081C9110: .4byte 0x0000054C
_081C9114: .4byte 0x0000054E
_081C9118: .4byte 0x00000541
_081C911C: .4byte 0x000005BC
_081C9120: .4byte 0x00000542
_081C9124: .4byte 0x030046B8
_081C9128: .4byte 0x000003FF
_081C912C: .4byte 0x0203B400
_081C9130:
	mov sb, sp
	ldr r6, _081C916C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C9170
	adds r0, #4
	b _081C917A
	.align 2, 0
_081C916C: .4byte 0x030046A4
_081C9170:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C917A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081C91B4 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C91BC
	ldr r0, _081C91B8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C91E6
	.align 2, 0
_081C91B4: .4byte 0x000004A4
_081C91B8: .4byte 0xFFFFFDFF
_081C91BC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C91DC
	cmp r0, #2
	beq _081C91D8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C91D8:
	movs r0, #1
	b _081C91E8
_081C91DC:
	ldr r0, _081C91FC @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C91E6:
	movs r0, #0
_081C91E8:
	cmp r0, #0
	bne _081C9204
	ldr r4, _081C9200 @ =0x000005C4
	adds r0, r7, r4
_081C91F0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C9206
	.align 2, 0
_081C91FC: .4byte 0xFFFFFDFF
_081C9200: .4byte 0x000005C4
_081C9204:
	movs r0, #1
_081C9206:
	cmp r0, #0
	bne _081C9276
	ldr r5, _081C923C @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C9244
	ldr r0, _081C9240 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C926E
	.align 2, 0
_081C923C: .4byte 0x000004A4
_081C9240: .4byte 0xFFFFFDFF
_081C9244:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C9264
	cmp r0, #2
	beq _081C9260
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C9260:
	movs r0, #1
	b _081C9270
_081C9264:
	ldr r0, _081C92D8 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C926E:
	movs r0, #0
_081C9270:
	cmp r0, #0
	bne _081C9276
	b _081C99B8
_081C9276:
	movs r0, #4
	ldr r5, _081C92DC @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081C92E0 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081C92E4 @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081C92E8 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081C92EC @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081C92F0 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _081C9A50
	.align 2, 0
_081C92D8: .4byte 0xFFFFFDFF
_081C92DC: .4byte 0x00000222
_081C92E0: .4byte 0x0000046D
_081C92E4: .4byte 0x0000046B
_081C92E8: .4byte 0x00000469
_081C92EC: .4byte 0x0000046A
_081C92F0: .4byte 0x0000046C
_081C92F4:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _081C9358 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r3, [r0, #6]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081C9352
	cmp r1, #0
	blt _081C9352
	ldr r0, _081C935C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C9352
	ldr r0, _081C9360 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C9364
_081C9352:
	movs r4, #0
	b _081C9372
	.align 2, 0
_081C9358: .4byte 0x03002BE0
_081C935C: .4byte 0x030046A8
_081C9360: .4byte 0x030046AC
_081C9364:
	ldr r0, _081C9384 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C9372:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C9388
	adds r0, #4
	b _081C9394
	.align 2, 0
_081C9384: .4byte 0x030046A4
_081C9388:
	ldr r0, _081C93A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C9394:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C93AC
	cmp r2, #2
	beq _081C93B0
	b _081C93B4
	.align 2, 0
_081C93A8: .4byte 0x030046A4
_081C93AC:
	ldrb r0, [r5, #4]
	b _081C93B2
_081C93B0:
	ldrb r0, [r5]
_081C93B2:
	subs r1, r1, r0
_081C93B4:
	strh r1, [r5, #2]
	ldr r0, _081C93C8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C93CC
	movs r0, #1
	b _081C93CE
	.align 2, 0
_081C93C8: .4byte 0x030047A4
_081C93CC:
	movs r0, #0
_081C93CE:
	cmp r0, #0
	beq _081C940C
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081C93EE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C93EA
	adds r2, r0, #0
_081C93EA:
	cmp r2, #0
	bge _081C93F8
_081C93EE:
	ldr r1, _081C93F4 @ =0x000005C4
	adds r0, r7, r1
	b _081C9934
	.align 2, 0
_081C93F4: .4byte 0x000005C4
_081C93F8:
	ldr r1, _081C9408 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C9454
	.align 2, 0
_081C9408: .4byte 0x03002BE0
_081C940C:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C9438
	cmp r1, #0
	blt _081C9438
	ldr r0, _081C943C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C9438
	ldr r0, _081C9440 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C9444
_081C9438:
	movs r5, #0
	b _081C9452
	.align 2, 0
_081C943C: .4byte 0x030046A8
_081C9440: .4byte 0x030046AC
_081C9444:
	ldr r0, _081C948C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C9452:
	movs r2, #0
_081C9454:
	ldr r3, _081C9490 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C9474
	ldr r1, _081C9494 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C9474
	b _081C9870
_081C9474:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _081C9498
	movs r0, #0
	b _081C994A
	.align 2, 0
_081C948C: .4byte 0x030046A4
_081C9490: .4byte 0x00000256
_081C9494: .4byte 0x03002BE0
_081C9498:
	ldr r5, _081C953C @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x9c]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xac]
	cmp r0, #0
	beq _081C955C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081C9540 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081C9544 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081C9548 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x50]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081C954C @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081C9550 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C9554 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _081C9558 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081C972E
	.align 2, 0
_081C953C: .4byte 0x00000222
_081C9540: .4byte 0x0000046D
_081C9544: .4byte 0x0000046B
_081C9548: .4byte 0x00000553
_081C954C: .4byte 0x00000469
_081C9550: .4byte 0x0000046A
_081C9554: .4byte 0x00000484
_081C9558: .4byte 0x0000046C
_081C955C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081C9620 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _081C9624 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081C9628 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _081C962C @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081C9630 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081C9634 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _081C961C
	cmp r1, #0
	blt _081C961C
	ldr r0, _081C9638 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081C961C
	ldr r0, _081C963C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C9640
_081C961C:
	movs r4, #0
	b _081C9650
	.align 2, 0
_081C9620: .4byte 0x0000046D
_081C9624: .4byte 0x0000046B
_081C9628: .4byte 0x00000553
_081C962C: .4byte 0x00000469
_081C9630: .4byte 0x0000046A
_081C9634: .4byte 0x00000484
_081C9638: .4byte 0x030046A8
_081C963C: .4byte 0x030046AC
_081C9640:
	ldr r0, _081C9660 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081C9650:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C9664
	adds r0, #4
	b _081C9670
	.align 2, 0
_081C9660: .4byte 0x030046A4
_081C9664:
	ldr r0, _081C9684 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C9670:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C9688
	cmp r2, #2
	beq _081C968E
	b _081C9694
	.align 2, 0
_081C9684: .4byte 0x030046A4
_081C9688:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _081C9692
_081C968E:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_081C9692:
	subs r1, r1, r0
_081C9694:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C96C0
	cmp r1, #0
	blt _081C96C0
	ldr r0, _081C96C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C96C0
	ldr r0, _081C96C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C96CC
_081C96C0:
	movs r4, #0
	b _081C96DA
	.align 2, 0
_081C96C4: .4byte 0x030046A8
_081C96C8: .4byte 0x030046AC
_081C96CC:
	ldr r0, _081C96F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C96DA:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C96F4
	adds r0, #4
	b _081C9700
	.align 2, 0
_081C96F0: .4byte 0x030046A4
_081C96F4:
	ldr r0, _081C9714 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C9700:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C9718
	cmp r3, #2
	beq _081C971C
	b _081C9720
	.align 2, 0
_081C9714: .4byte 0x030046A4
_081C9718:
	ldrb r0, [r5, #4]
	b _081C971E
_081C971C:
	ldrb r0, [r5]
_081C971E:
	subs r2, r2, r0
_081C9720:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C972E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081C9758 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081C9838
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C975C
	movs r0, #1
	b _081C975E
	.align 2, 0
_081C9758: .4byte 0x00000482
_081C975C:
	movs r0, #0
_081C975E:
	ldr r1, _081C9848 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081C9838
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081C984C @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081C9850 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081C9854 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081C9858 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081C985C @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081C9860 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081C9864 @ =0x030046B8
	adds r2, r4, #0
_081C97A6:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081C9868 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081C986C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081C97CA
	adds r3, #1
	cmp r3, #3
	ble _081C97A6
	adds r0, r4, #0
_081C97CA:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081C9838:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081C994A
	.align 2, 0
_081C9848: .4byte 0x00000482
_081C984C: .4byte 0x0000054F
_081C9850: .4byte 0x0000054C
_081C9854: .4byte 0x0000054E
_081C9858: .4byte 0x00000541
_081C985C: .4byte 0x000005BC
_081C9860: .4byte 0x00000542
_081C9864: .4byte 0x030046B8
_081C9868: .4byte 0x000003FF
_081C986C: .4byte 0x0203B400
_081C9870:
	add r6, sp, #8
	ldr r0, _081C98B0 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _081C98B4
	adds r0, #4
	b _081C98C0
	.align 2, 0
_081C98B0: .4byte 0x030046A4
_081C98B4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C98C0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C98F8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C9900
	ldr r0, _081C98FC @ =0xFFFFFDFF
	ldr r6, [sp, #0x9c]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C992A
	.align 2, 0
_081C98F8: .4byte 0x000004A4
_081C98FC: .4byte 0xFFFFFDFF
_081C9900:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C9920
	cmp r0, #2
	beq _081C991C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C991C:
	movs r0, #1
	b _081C992C
_081C9920:
	ldr r0, _081C9940 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C992A:
	movs r0, #0
_081C992C:
	cmp r0, #0
	bne _081C9948
	ldr r3, _081C9944 @ =0x000005C4
	adds r0, r7, r3
_081C9934:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C994A
	.align 2, 0
_081C9940: .4byte 0xFFFFFDFF
_081C9944: .4byte 0x000005C4
_081C9948:
	movs r0, #1
_081C994A:
	cmp r0, #0
	bne _081C99D0
	ldr r4, _081C9980 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C9988
	ldr r0, _081C9984 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C99B2
	.align 2, 0
_081C9980: .4byte 0x000004A4
_081C9984: .4byte 0xFFFFFDFF
_081C9988:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C99A8
	cmp r0, #2
	beq _081C99A4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C99A4:
	movs r0, #1
	b _081C99B4
_081C99A8:
	ldr r0, _081C99C8 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C99B2:
	movs r0, #0
_081C99B4:
	cmp r0, #0
	bne _081C99D0
_081C99B8:
	ldr r4, _081C99CC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081C9A50
	.align 2, 0
_081C99C8: .4byte 0xFFFFFDFF
_081C99CC: .4byte 0x000005C4
_081C99D0:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081C9A2C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081C9A30 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081C9A34 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C9A38 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081C9A3C @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #4
	strh r0, [r1]
	b _081C9A50
	.align 2, 0
_081C9A2C: .4byte 0x0000046D
_081C9A30: .4byte 0x0000046B
_081C9A34: .4byte 0x00000469
_081C9A38: .4byte 0x0000046A
_081C9A3C: .4byte 0x00000484

_081C9A40:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C9A50:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
