	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	ldr r5, [sp, #0x10]
	strh r1, [r0, #0x3c]
	adds r1, r0, #0
	adds r1, #0x40
	strh r2, [r1]
	str r3, [r0, #0x34]
	str r4, [r0, #0x38]
	adds r0, #0x44
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
