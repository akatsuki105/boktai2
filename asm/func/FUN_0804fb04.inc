	push {lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #2
	adds r2, #0x3c
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	adds r0, r1, #3
_0804FB18:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _0804FB18
	pop {r0}
	bx r0
