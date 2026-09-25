	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #4
_0820EE8A:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EE8A
	movs r4, #1
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #2
_0820EEA2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EEA2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
