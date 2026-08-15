	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r6, [sp, #0x14]
	movs r5, #0
	strh r1, [r4]
	strh r5, [r4, #2]
	strb r0, [r4, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	strb r3, [r4, #5]
	strh r5, [r4, #0x10]
	strh r5, [r4, #0x12]
	strh r5, [r4, #0x14]
	movs r0, #0x10
	strh r0, [r4, #0x16]
	str r5, [r4, #0x18]
	str r5, [r4, #0x20]
	str r5, [r4, #0x28]
	str r5, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_0823b1f8
	str r6, [r4, #0x38]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
