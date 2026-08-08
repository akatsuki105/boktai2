	push {r4, lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r4, #1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0xb
_082143D2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _082143D2
	movs r1, #0x91
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
