	push {r4, r5, lr}
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_08061DBE:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _08061DBE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
