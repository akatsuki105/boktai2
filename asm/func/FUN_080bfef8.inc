	push {lr}
	movs r3, #1
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #5
_080BFF04:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF04
	pop {r0}
	bx r0
	.align 2, 0
