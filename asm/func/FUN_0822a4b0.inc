	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #4]
	cmp r5, #0
	bne _0822A4D8
	str r2, [r4]
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
	str r5, [r4, #0x24]
	str r5, [r4, #0x28]
_0822A4D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
