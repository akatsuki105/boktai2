	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5, r6}
	stm r3!, {r4, r5, r6}
	ldm r2!, {r4, r5}
	stm r3!, {r4, r5}
	ldr r2, [r0, #0xc]
	adds r2, r2, r1
	str r2, [r0, #0xc]
	ldr r2, [r0, #0x10]
	adds r2, r2, r1
	str r2, [r0, #0x10]
	ldr r2, [r0, #0x14]
	adds r2, r2, r1
	str r2, [r0, #0x14]
	ldr r2, [r0, #0x18]
	adds r2, r2, r1
	str r2, [r0, #0x18]
	ldr r2, [r0, #0x1c]
	adds r2, r2, r1
	str r2, [r0, #0x1c]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
