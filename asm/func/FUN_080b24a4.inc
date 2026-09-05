	push {lr}
	adds r3, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2518
	ldrb r0, [r3, #0x1f]
	cmp r0, #0
	beq _080B2518
	ldr r2, _080B2504 @ =0x000004FC
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0xa
	beq _080B24C8
	cmp r0, #0xe
	bne _080B2518
_080B24C8:
	movs r0, #0xa3
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strh r0, [r2, #0x10]
	ldr r2, _080B2508 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B250C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B2510 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x48
	ldr r2, _080B2514 @ =0x00000521
	adds r1, r3, r2
	strb r0, [r1]
	subs r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _080B2526
	.align 2, 0
_080B2504: .4byte 0x000004FC
_080B2508: .4byte 0x030046B8
_080B250C: .4byte 0x000003FF
_080B2510: .4byte 0x0203B400
_080B2514: .4byte 0x00000521
_080B2518:
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B2526:
	pop {r0}
	bx r0
	.align 2, 0
