	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B00D0 @ =0x0000068A
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	ldr r1, _080B00D4 @ =0x0000068E
	adds r0, r4, r1
	ldrh r3, [r0]
	ldr r2, _080B00D8 @ =0x085B0A08
	subs r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080B00DC
	asrs r3, r0, #0xc
	b _080B00E2
	.align 2, 0
_080B00D0: .4byte 0x0000068A
_080B00D4: .4byte 0x0000068E
_080B00D8: .4byte 0x085B0A08
_080B00DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080B00E2:
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _080B010C @ =0x0000068E
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _080B0110 @ =0x0000068D
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080B0114
	asrs r2, r0, #0xc
	b _080B011A
	.align 2, 0
_080B010C: .4byte 0x0000068E
_080B0110: .4byte 0x0000068D
_080B0114:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080B011A:
	ldr r3, _080B0174 @ =0x0000061C
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r2, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r3, _080B0178 @ =0x00000674
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080B017C @ =0x00077A0F
	cmp r1, r0
	ble _080B0188
	ldr r3, _080B0180 @ =0x0000068E
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080B0168
	movs r0, #0x1e
	strh r0, [r1]
_080B0168:
	ldr r0, _080B0184 @ =0x0000068D
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #0x80
	strb r0, [r1]
	b _080B0196
	.align 2, 0
_080B0174: .4byte 0x0000061C
_080B0178: .4byte 0x00000674
_080B017C: .4byte 0x00077A0F
_080B0180: .4byte 0x0000068E
_080B0184: .4byte 0x0000068D
_080B0188:
	ldr r1, _080B01B0 @ =0x0000068E
	adds r2, r4, r1
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_080B0196:
	ldr r2, _080B01B0 @ =0x0000068E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B01A8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080af374
_080B01A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B01B0: .4byte 0x0000068E
