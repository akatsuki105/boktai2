	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xf8
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
