	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r2, #0
	cmp r5, #4
	bhi _0820FF3C
	cmp r4, #0
	blt _0820FF3C
	cmp r4, #3
	bgt _0820FF3C
	bl FUN_0820fedc
	lsls r1, r4, #2
	adds r1, r1, r4
	adds r1, #1
	adds r1, r5, r1
	cmp r0, r1
	blt _0820FF3C
	movs r0, #1
	b _0820FF3E
_0820FF3C:
	movs r0, #0
_0820FF3E:
	pop {r4, r5}
	pop {r1}
	bx r1
