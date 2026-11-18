	push {lr}
	movs r2, #3
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r0, r3
_081974FE:
	str r1, [r0]
	subs r0, #0x1c
	subs r2, #1
	cmp r2, #0
	bge _081974FE
	pop {r0}
	bx r0
