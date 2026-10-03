	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804D244 @ =0x03002B58
	ldr r5, [r0]
	cmp r5, #0
	beq _0804D2FE
	cmp r3, #0x41
	bgt _0804D248
	cmp r3, #0x40
	bge _0804D2FE
	cmp r3, #0x30
	beq _0804D2A0
	cmp r3, #0x30
	ble _0804D2FE
	cmp r3, #0x32
	beq _0804D28C
	cmp r3, #0x32
	blt _0804D276
	cmp r3, #0x33
	beq _0804D2A0
	b _0804D2FE
	.align 2, 0
_0804D244: .4byte 0x03002B58
_0804D248:
	cmp r3, #0x50
	beq _0804D26E
	cmp r3, #0x50
	bgt _0804D256
	cmp r3, #0x42
	beq _0804D2C4
	b _0804D2FE
_0804D256:
	cmp r3, #0xf1
	beq _0804D2E6
	cmp r3, #0xf1
	bgt _0804D264
	cmp r3, #0xf0
	beq _0804D2CC
	b _0804D2FE
_0804D264:
	cmp r1, #0xf2
	beq _0804D2E6
	cmp r1, #0xff
	beq _0804D2E6
	b _0804D2FE
_0804D26E:
	adds r0, r5, #0
	bl FUN_0804cde8
	b _0804D2FE
_0804D276:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D288 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804D2FE
	.align 2, 0
_0804D288: .4byte 0x03004740
_0804D28C:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D29C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804D2FE
	.align 2, 0
_0804D29C: .4byte 0x03004740
_0804D2A0:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804D2C0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r4, #0
	strb r0, [r2]
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r0, #0x1d
	strb r4, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r4, [r5, #0x44]
	b _0804D2F6
	.align 2, 0
_0804D2C0: .4byte 0x03004740
_0804D2C4:
	adds r0, r5, #0
	bl FUN_0804ba64
	b _0804D2FE
_0804D2CC:
	ldr r0, _0804D304 @ =0x03004740
	ldrh r1, [r0, #0x14]
	adds r2, r0, #0
	cmp r1, #0x30
	bne _0804D2E0
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bne _0804D2E0
	movs r0, #0
	strh r0, [r2, #0x16]
_0804D2E0:
	ldrh r0, [r2, #0x16]
	cmp r0, #0
	beq _0804D2FE
_0804D2E6:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
_0804D2F6:
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804D2FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D304: .4byte 0x03004740
