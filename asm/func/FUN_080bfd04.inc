	push {lr}
	movs r3, #1
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFD10:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFD10
	pop {r0}
	bx r0
	.align 2, 0
