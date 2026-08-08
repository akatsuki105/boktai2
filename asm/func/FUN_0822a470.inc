	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	ldrb r5, [r4, #4]
	cmp r5, #0
	bne _0822A4A8
	str r6, [r4]
	movs r0, #1
	strb r0, [r4, #5]
	str r5, [r4, #0x18]
	movs r0, #0x40
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	strb r5, [r4, #6]
	movs r0, #2
	strb r0, [r4, #7]
	adds r0, r4, #0
	bl FUN_0822a4fc
	movs r1, #0x80
	ands r1, r6
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	str r5, [r4, #0x24]
	str r5, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_0822a340
_0822A4A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
