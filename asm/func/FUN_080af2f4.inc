	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x68
	movs r2, #7
_080AF308:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x68
	subs r2, #1
	cmp r2, #0
	bge _080AF308
	movs r4, #1
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #5
_080AF320:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x68
	subs r2, #1
	cmp r2, #0
	bge _080AF320
	pop {r4}
	pop {r0}
	bx r0
