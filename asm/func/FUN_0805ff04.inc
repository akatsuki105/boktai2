	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r4, #0x10
	movs r2, #0
	strb r2, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	movs r0, #0
	strh r2, [r1, #2]
	strb r0, [r1, #8]
	strh r2, [r1, #4]
	strh r2, [r1, #6]
	strb r0, [r1, #9]
	adds r3, #0x28
	adds r0, r4, #0
	adds r1, r3, #0
	bl AuxSprite_Setup
	movs r0, #0x36
	strh r0, [r4, #0x10]
	pop {r4}
	pop {r0}
	bx r0
