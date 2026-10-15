	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r2, r0, #0
	adds r2, #0xa4
	adds r1, r0, #0
	movs r3, #3
_080C17F6:
	strb r5, [r2]
	ldr r0, [r1, #0x7c]
	orrs r0, r4
	str r0, [r1, #0x7c]
	adds r2, #0x30
	adds r1, #0x30
	subs r3, #1
	cmp r3, #0
	bge _080C17F6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
