	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r1, r0, #0
	adds r1, #0xd4
	adds r2, r0, #0
	adds r2, #0xfc
	movs r3, #3
_08080630:
	strb r5, [r2]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x30
	adds r2, #0x30
	subs r3, #1
	cmp r3, #0
	bge _08080630
	pop {r4, r5}
	pop {r0}
	bx r0
