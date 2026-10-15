	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r2, r4, #0
	adds r2, #0xf8
	movs r5, #1
	movs r3, #3
_0805A6FC:
	ldr r1, [r2]
	orrs r1, r5
	str r1, [r2]
	subs r3, #1
	adds r2, #0x2c
	cmp r3, #0
	bge _0805A6FC
	adds r3, r4, #0
	adds r3, #0x98
	ldrh r2, [r3, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r3, #6]
	movs r2, #1
	lsls r2, r7
	ldr r1, [r6, #0x18]
	bics r1, r2
	str r1, [r6, #0x18]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
