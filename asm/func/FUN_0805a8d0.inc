	push {lr}
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #1
	movs r2, #2
_0805A8DC:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	subs r2, #1
	adds r1, #0x2c
	cmp r2, #0
	bge _0805A8DC
	pop {r0}
	bx r0
	.align 2, 0
