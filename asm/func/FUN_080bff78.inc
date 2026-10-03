	push {lr}
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #6
_080BFF86:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080BFF86
	pop {r0}
	bx r0
