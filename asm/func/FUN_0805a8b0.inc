	push {lr}
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #2
_0805A8BE:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	subs r2, #1
	adds r1, #0x2c
	cmp r2, #0
	bge _0805A8BE
	pop {r0}
	bx r0
