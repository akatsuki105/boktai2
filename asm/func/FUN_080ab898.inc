	push {lr}
	adds r2, r0, #0
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AB8E8
	ldr r1, [r2, #0x1c]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #9
	bne _080AB8D6
	adds r3, #1
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #2
	bhi _080AB8D6
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080AB8D6
	adds r0, r2, #0
	adds r0, #0xc0
	bl FUN_080ab7f0
	b _080AB8E8
_080AB8D6:
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc0
	bl FUN_080ab848
_080AB8E8:
	pop {r0}
	bx r0
