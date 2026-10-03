	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D0E4 @ =0x03002B58
	ldr r4, [r0]
	cmp r4, #0
	bne _0804D0BE
	b _0804D20A
_0804D0BE:
	cmp r3, #0x41
	bne _0804D0C4
	b _0804D20A
_0804D0C4:
	cmp r3, #0x41
	bgt _0804D0E8
	cmp r3, #0x30
	beq _0804D158
	cmp r3, #0x30
	bgt _0804D0D2
	b _0804D20A
_0804D0D2:
	cmp r3, #0x32
	beq _0804D144
	cmp r3, #0x32
	blt _0804D130
	cmp r3, #0x33
	beq _0804D158
	cmp r3, #0x40
	beq _0804D19C
	b _0804D20A
	.align 2, 0
_0804D0E4: .4byte 0x03002B58
_0804D0E8:
	cmp r3, #0x50
	beq _0804D118
	cmp r3, #0x50
	bgt _0804D100
	cmp r3, #0x43
	bne _0804D0F6
	b _0804D20A
_0804D0F6:
	cmp r3, #0x43
	blt _0804D1D0
	cmp r3, #0x44
	beq _0804D1D8
	b _0804D20A
_0804D100:
	cmp r3, #0xf1
	beq _0804D1EC
	cmp r3, #0xf1
	bgt _0804D10E
	cmp r3, #0xf0
	beq _0804D1EC
	b _0804D20A
_0804D10E:
	cmp r1, #0xf2
	beq _0804D1EC
	cmp r1, #0xff
	beq _0804D1EC
	b _0804D20A
_0804D118:
	adds r0, r4, #0
	bl FUN_0804ccd0
	adds r0, r4, #0
	bl FUN_0804ce3c
	ldr r1, _0804D12C @ =0x030000DC
	movs r0, #0
	strb r0, [r1]
	b _0804D20A
	.align 2, 0
_0804D12C: .4byte 0x030000DC
_0804D130:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D140 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D20A
	.align 2, 0
_0804D140: .4byte 0x03004740
_0804D144:
	adds r2, r4, #0
	adds r2, #0x25
	ldr r0, _0804D154 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D20A
	.align 2, 0
_0804D154: .4byte 0x03004740
_0804D158:
	adds r3, r4, #0
	adds r3, #0x25
	ldr r2, _0804D194 @ =0x03004740
	ldrb r1, [r2, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r6, #0
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0xe9
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r2, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D198 @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D20A
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r6, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r6, [r4, #0x44]
	b _0804D1C0
	.align 2, 0
_0804D194: .4byte 0x03004740
_0804D198: .4byte 0x00000137
_0804D19C:
	ldr r0, _0804D1C8 @ =0x03004740
	ldrb r1, [r0, #0x14]
	adds r0, r4, #0
	bl FUN_0804d05c
	ldr r1, _0804D1CC @ =0x00000137
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _0804D20A
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1d
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
_0804D1C0:
	adds r0, r4, #0
	adds r0, #0x32
	strb r5, [r0]
	b _0804D20A
	.align 2, 0
_0804D1C8: .4byte 0x03004740
_0804D1CC: .4byte 0x00000137
_0804D1D0:
	adds r0, r4, #0
	bl FUN_0804ba64
	b _0804D20A
_0804D1D8:
	movs r1, #0x1e
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	b _0804D20A
_0804D1EC:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r4, #0x1c]
	movs r2, #0
	strh r1, [r4, #0x38]
	str r0, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0804D210 @ =0x030000DC
	strb r2, [r0]
_0804D20A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D210: .4byte 0x030000DC
