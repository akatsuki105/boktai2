	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #6
_081DB2FE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DB2FE
	pop {r0}
	bx r0
