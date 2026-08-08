	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	adds r4, r1, #0
	str r2, [sp, #0x2c]
	str r3, [sp, #0x30]
	ldr r0, _080E69C0 @ =0x000004BE
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	mov sl, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	bl FUN_080e64e4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r0, _080E69C4 @ =0xFFFFDFFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	cmp r4, #0
	bge _080E69B4
	b _080E7060
_080E69B4:
	cmp r4, #1
	ble _080E69C8
	cmp r4, #2
	bne _080E69BE
	b _080E6B44
_080E69BE:
	b _080E7060
	.align 2, 0
_080E69C0: .4byte 0x000004BE
_080E69C4: .4byte 0xFFFFDFFF
_080E69C8:
	ldr r3, _080E6AE4 @ =0x00000553
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	cmp r0, #0x15
	beq _080E6A3C
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	subs r3, #0xea
	adds r0, r7, r3
	mov r4, sl
	strb r4, [r0]
	ldr r1, _080E6AE8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	ldr r4, _080E6AEC @ =0x000005D4
	adds r0, r7, r4
	ldr r3, [r0]
	movs r2, #0x15
	ldr r4, _080E6AF0 @ =0x0000046D
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _080E6AF4 @ =0x0000046B
	adds r0, r7, r1
	mov r4, sl
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
	mov r4, sb
	strh r6, [r4]
	movs r1, #0x80
	lsls r1, r1, #0xa
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_080E6A3C:
	movs r1, #4
	mov r3, r8
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r1, _080E6AF8 @ =0xFFBFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _080E6AFC @ =0x00000482
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080E6B00 @ =0x00000222
	adds r0, r7, r1
	strh r6, [r0]
	ldr r3, _080E6B04 @ =0x0000024E
	adds r0, r7, r3
	strh r6, [r0]
	ldr r0, _080E6B08 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r1, _080E6B0C @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _080E6AAA
	ldr r1, _080E6B10 @ =0xFEFFFFFF
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _080E6B14 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, sl
	strb r2, [r0]
	subs r3, #0x30
	adds r0, r7, r3
	strh r6, [r0]
	ldr r4, _080E6B18 @ =0x00000202
	adds r0, r7, r4
	strh r6, [r0]
_080E6AAA:
	ldr r0, _080E6B1C @ =0xFFFFFBFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r6, _080E6B20 @ =0x00000542
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, [sp, #0x2c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	ldrh r0, [r7, #0xa]
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	strh r0, [r7, #0xa]
	ldr r4, _080E6B24 @ =0x0000025D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080E6B28
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _080E6B32
	.align 2, 0
_080E6AE4: .4byte 0x00000553
_080E6AE8: .4byte 0x0000046A
_080E6AEC: .4byte 0x000005D4
_080E6AF0: .4byte 0x0000046D
_080E6AF4: .4byte 0x0000046B
_080E6AF8: .4byte 0xFFBFFFFF
_080E6AFC: .4byte 0x00000482
_080E6B00: .4byte 0x00000222
_080E6B04: .4byte 0x0000024E
_080E6B08: .4byte 0xFFFFFC7F
_080E6B0C: .4byte 0xF3FFFFFF
_080E6B10: .4byte 0xFEFFFFFF
_080E6B14: .4byte 0xFFFFFDFF
_080E6B18: .4byte 0x00000202
_080E6B1C: .4byte 0xFFFFFBFF
_080E6B20: .4byte 0x00000542
_080E6B24: .4byte 0x0000025D
_080E6B28:
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_080E6B32:
	movs r0, #0x80
	lsls r0, r0, #6
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080E7060
_080E6B44:
	movs r1, #4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_080136b4
	movs r2, #1
	ldr r3, _080E6B74 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0
	bne _080E6B78
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080E6B82
	.align 2, 0
_080E6B74: .4byte 0x0000025D
_080E6B78:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_080E6B82:
	ldr r0, [sp, #0x54]
	cmp r0, #0
	bgt _080E6B8A
	b _080E6F38
_080E6B8A:
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	movs r4, #0
	strh r4, [r0]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r6, _080E6C64 @ =0x0000048A
	adds r0, r7, r6
	strh r1, [r0]
	strh r4, [r2]
	movs r0, #8
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r3, #0x62
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xa0
	lsls r1, r1, #0xc
	mov r6, r8
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r1, #0xba
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x11
	ldr r3, _080E6C68 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _080E6C6C @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
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
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _080E6C70 @ =0x00000469
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _080E6C74 @ =0x0000046A
	adds r0, r7, r2
	strb r5, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r0, _080E6C78 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080E6C7C
	movs r0, #1
	b _080E6C7E
	.align 2, 0
_080E6C64: .4byte 0x0000048A
_080E6C68: .4byte 0x0000046D
_080E6C6C: .4byte 0x0000046B
_080E6C70: .4byte 0x00000469
_080E6C74: .4byte 0x0000046A
_080E6C78: .4byte 0x030047A4
_080E6C7C:
	movs r0, #0
_080E6C7E:
	cmp r0, #0
	beq _080E6CEC
	movs r2, #0x94
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080E6CEC
	cmp r2, #0
	beq _080E6CEC
	ldr r0, _080E6CA4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080E6CA8
	movs r0, #1
	rsbs r0, r0, #0
	b _080E6CAC
	.align 2, 0
_080E6CA4: .4byte 0x03002C68
_080E6CA8:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080E6CAC:
	cmp r0, #1
	beq _080E6CCE
	cmp r0, #1
	bgt _080E6CBA
	cmp r0, #0
	beq _080E6CC4
	b _080E6CEC
_080E6CBA:
	cmp r0, #2
	beq _080E6CD8
	cmp r0, #3
	beq _080E6CE2
	b _080E6CEC
_080E6CC4:
	ldr r0, [r1]
	cmp r0, #1
	beq _080E6CEC
	movs r0, #0
	b _080E6CEE
_080E6CCE:
	ldr r0, [r1]
	cmp r0, #2
	beq _080E6CEC
	movs r0, #0
	b _080E6CEE
_080E6CD8:
	ldr r0, [r1]
	cmp r0, #4
	beq _080E6CEC
	movs r0, #0
	b _080E6CEE
_080E6CE2:
	ldr r0, [r1]
	cmp r0, #8
	beq _080E6CEC
	movs r0, #0
	b _080E6CEE
_080E6CEC:
	movs r0, #1
_080E6CEE:
	cmp r0, #0
	beq _080E6D54
	ldrh r0, [r7]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r6, #0
	ldrsh r1, [r1, r6]
	movs r3, #0x95
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r2, [r2]
	adds r4, #0xd6
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r5, sp, #0x14
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _080E6D68 @ =0x05000002
	bl CpuSet
	ldr r6, _080E6D6C @ =0x0000048A
	adds r2, r7, r6
	ldrh r0, [r2]
	cmp r0, #0
	bne _080E6D3E
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080E6D54
_080E6D3E:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_080E6D54:
	ldr r0, _080E6D70 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080E6D74
	movs r0, #1
	b _080E6D76
	.align 2, 0
_080E6D68: .4byte 0x05000002
_080E6D6C: .4byte 0x0000048A
_080E6D70: .4byte 0x030047A4
_080E6D74:
	movs r0, #0
_080E6D76:
	cmp r0, #0
	bne _080E6D92
	movs r1, #0x80
	lsls r1, r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _080E6D92
	ldr r0, _080E6F1C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
_080E6D92:
	ldr r3, _080E6F20 @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #4
	beq _080E6DA2
	cmp r0, #1
	beq _080E6DA2
	b _080E7060
_080E6DA2:
	ldr r2, _080E6F24 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _080E6F28 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r5, sp, #0x1c
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _080E6F2C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r6, _080E6F30 @ =0x000003FF
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080E6F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	movs r3, #8
	adds r3, r3, r7
	mov sl, r3
	movs r6, #4
	str r6, [sp]
	movs r0, #0x14
	mov sb, r0
	str r0, [sp, #4]
	movs r2, #2
	mov r8, r2
	str r2, [sp, #8]
	movs r6, #1
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080E6F30 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080E6F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	movs r3, #4
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080E6F30 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080E6F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	movs r3, #4
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080E6F30 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080E6F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	movs r3, #4
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080E6F30 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080E6F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	movs r3, #4
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080E6F30 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r4, _080E6F34 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #4
	str r2, [sp]
	mov r3, sb
	str r3, [sp, #4]
	mov r4, r8
	str r4, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r6, _080E6F20 @ =0x000001DF
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #4
	beq _080E6F12
	cmp r0, #1
	beq _080E6F12
	cmp r0, #5
	beq _080E6F12
	cmp r0, #7
	beq _080E6F12
	cmp r0, #6
	beq _080E6F12
	cmp r0, #0x18
	beq _080E6F12
	b _080E7060
_080E6F12:
	movs r0, #0xe5
	bl PlaySound_082406e0
	b _080E7060
	.align 2, 0
_080E6F1C: .4byte 0x03002B28
_080E6F20: .4byte 0x000001DF
_080E6F24: .4byte 0xFFFF0000
_080E6F28: .4byte 0x0000FFFF
_080E6F2C: .4byte 0x030046B8
_080E6F30: .4byte 0x000003FF
_080E6F34: .4byte 0x0203B400
_080E6F38:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080E6F4A
	asrs r1, r0, #1
	b _080E6F50
_080E6F4A:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_080E6F50:
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r3, r7, r4
	strh r1, [r3]
	ldr r6, _080E6F80 @ =0x0000048A
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r2]
	ldr r0, _080E6F84 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080E6F88
	movs r0, #1
	b _080E6F8A
	.align 2, 0
_080E6F80: .4byte 0x0000048A
_080E6F84: .4byte 0x030047A4
_080E6F88:
	movs r0, #0
_080E6F8A:
	cmp r0, #0
	beq _080E6FF8
	movs r2, #0x94
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080E6FF8
	cmp r2, #0
	beq _080E6FF8
	ldr r0, _080E6FB0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080E6FB4
	movs r0, #1
	rsbs r0, r0, #0
	b _080E6FB8
	.align 2, 0
_080E6FB0: .4byte 0x03002C68
_080E6FB4:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080E6FB8:
	cmp r0, #1
	beq _080E6FDA
	cmp r0, #1
	bgt _080E6FC6
	cmp r0, #0
	beq _080E6FD0
	b _080E6FF8
_080E6FC6:
	cmp r0, #2
	beq _080E6FE4
	cmp r0, #3
	beq _080E6FEE
	b _080E6FF8
_080E6FD0:
	ldr r0, [r1]
	cmp r0, #1
	beq _080E6FF8
	movs r0, #0
	b _080E6FFA
_080E6FDA:
	ldr r0, [r1]
	cmp r0, #2
	beq _080E6FF8
	movs r0, #0
	b _080E6FFA
_080E6FE4:
	ldr r0, [r1]
	cmp r0, #4
	beq _080E6FF8
	movs r0, #0
	b _080E6FFA
_080E6FEE:
	ldr r0, [r1]
	cmp r0, #8
	beq _080E6FF8
	movs r0, #0
	b _080E6FFA
_080E6FF8:
	movs r0, #1
_080E6FFA:
	cmp r0, #0
	beq _080E7060
	ldrh r0, [r7]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r6, #0
	ldrsh r1, [r1, r6]
	movs r3, #0x95
	lsls r3, r3, #2
	adds r2, r7, r3
	ldrh r2, [r2]
	adds r4, #0xd6
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r5, sp, #0x24
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _080E7070 @ =0x05000002
	bl CpuSet
	ldr r6, _080E7074 @ =0x0000048A
	adds r2, r7, r6
	ldrh r0, [r2]
	cmp r0, #0
	bne _080E704A
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080E7060
_080E704A:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r7, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_080E7060:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E7070: .4byte 0x05000002
_080E7074: .4byte 0x0000048A
