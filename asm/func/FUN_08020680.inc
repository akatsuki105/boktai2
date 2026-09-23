	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _080206AA
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0801faa8
	cmp r0, #0
	bne _080206AA
	ldrb r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r4, #0x2e]
	strh r0, [r1]
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
_080206AA:
	pop {r4}
	pop {r0}
	bx r0
