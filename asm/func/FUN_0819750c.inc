	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r3, r0, r1
	subs r1, #6
	adds r0, r0, r1
	movs r1, #3
_0819751C:
	strh r2, [r0]
	str r4, [r3]
	adds r3, #0x1c
	adds r0, #0x1c
	subs r1, #1
	cmp r1, #0
	bge _0819751C
	pop {r4}
	pop {r0}
	bx r0
