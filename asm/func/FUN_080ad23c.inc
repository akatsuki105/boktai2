	push {r4, r5, r6, r7, lr}
	movs r1, #0xac
	lsls r1, r1, #3
	adds r6, r0, r1
	ldr r1, _080AD284 @ =0x00000BE4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AD2C4
	movs r7, #0
	movs r5, #0
_080AD252:
	movs r0, #0x34
	muls r0, r5, r0
	adds r0, #4
	adds r2, r6, r0
	adds r3, r2, #0
	adds r3, #0x30
	ldrb r0, [r3]
	cmp r0, #0
	beq _080AD2B8
	adds r4, r2, #0
	adds r4, #0x31
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080AD288
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080AD2B8
	.align 2, 0
_080AD284: .4byte 0x00000BE4
_080AD288:
	movs r7, #1
	ldrh r0, [r2, #0x28]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r2, #0x2a]
	ldrh r1, [r2, #0x1a]
	adds r0, r0, r1
	strh r0, [r2, #0x1a]
	ldrh r0, [r2, #0x2c]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	ldrb r0, [r4]
	cmp r0, #6
	bne _080AD2B2
	ldr r1, [r6]
	adds r0, r2, #0
	movs r2, #3
	bl FUN_0822dafc
_080AD2B2:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080AD2B8:
	adds r5, #1
	cmp r5, #0x1f
	ble _080AD252
	ldr r1, _080AD2CC @ =0x00000684
	adds r0, r6, r1
	strb r7, [r0]
_080AD2C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD2CC: .4byte 0x00000684
