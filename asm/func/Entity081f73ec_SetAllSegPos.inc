	push {r4, r5, lr}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r3, r0, r4
	movs r5, #0x92
	lsls r5, r5, #1
	movs r4, #5
_081F5B1E:
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	str r1, [r3]
	str r2, [r3, #4]
	adds r3, r3, r5
	adds r0, r0, r5
	subs r4, #1
	cmp r4, #0
	bge _081F5B1E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
