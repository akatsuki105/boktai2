	push {lr}
	movs r2, #0
	strb r1, [r0, #0x1c]
	movs r1, #1
	strb r1, [r0, #0x1d]
	str r2, [r0, #0x18]
	strb r2, [r0, #0x1e]
	adds r1, r0, #0
	adds r1, #0x40
	movs r3, #1
	movs r2, #3
_080522A6:
	ldr r0, [r1, #8]
	orrs r0, r3
	str r0, [r1, #8]
	subs r2, #1
	adds r1, #0x60
	cmp r2, #0
	bge _080522A6
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
