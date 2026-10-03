	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
_080BFCF2:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080BFCF2
	pop {r0}
	bx r0
