	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r1, #0
	adds r5, r2, #0
	ldr r1, [r0, #0xc]
	movs r4, #1
	orrs r1, r4
	str r1, [r0, #0xc]
	adds r0, #0xc
	bl AuxSprite_Remove
	lsls r4, r5
	ldr r0, [r6, #0x18]
	bics r0, r4
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
