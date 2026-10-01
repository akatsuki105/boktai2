	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809E880
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E880
	movs r6, #1
	adds r2, r4, #0
	adds r2, #0xc9
	adds r1, r4, #0
	adds r5, r0, #0
_0809E868:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E874
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809E874:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E868
_0809E880:
	ldr r0, [r4, #0x18]
	movs r2, #0x20
	ldr r1, [r0, #0x20]
	ands r1, r2
	rsbs r1, r1, #0
	asrs r1, r1, #0x1f
	movs r0, #2
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6}
	pop {r0}
	bx r0
