	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080D97A4 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080D97F4
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x5c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_080d96b8
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strh r0, [r5, #0x10]
	ldr r0, [r4]
	cmp r0, #0
	beq _080D97DC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r2, [r4, #0x2a]
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D97A8
	movs r0, #1
	b _080D97AA
	.align 2, 0
_080D97A4: .4byte 0x0300015C
_080D97A8:
	movs r0, #0
_080D97AA:
	cmp r0, #0
	bne _080D97C2
	ldr r0, _080D97FC @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	asrs r0, r0, #8
	adds r2, r2, r0
_080D97C2:
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r2
	ldrh r3, [r5, #0x1e]
	adds r0, r0, r3
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_080D97DC:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080d8788
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D97F4
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_080D97F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D97FC: .4byte 0x085B0A08
