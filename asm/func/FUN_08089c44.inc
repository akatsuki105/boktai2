	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0xa0
	movs r2, #3
_08089C4E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08089C4E
	pop {r0}
	bx r0
