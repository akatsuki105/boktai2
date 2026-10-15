	push {lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x20]
	cmp r3, #0
	beq _080083B8
	ldrh r1, [r3]
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r2, #6]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x58
	strh r1, [r0]
_080083B8:
	pop {r0}
	bx r0
