	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080ABCA6
	adds r0, r4, #0
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080ABCA6
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080ABCA6
	adds r0, r4, #0
	bl FUN_080ab018
_080ABCA6:
	adds r0, r4, #0
	bl FUN_080abb08
	adds r0, r4, #0
	bl FUN_080ab8ec
	adds r0, r4, #0
	bl FUN_080ab6d8
	ldrb r1, [r4, #0x19]
	cmp r1, #0
	beq _080ABCC6
	ldr r2, _080ABCCC @ =0x03002BF0
	ldrh r1, [r2]
	subs r1, #1
	strh r1, [r2]
_080ABCC6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ABCCC: .4byte 0x03002BF0
