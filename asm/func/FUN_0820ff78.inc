	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0820ff44
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_0820fedc
	movs r1, #0
	cmp r5, r0
	blt _0820FF90
	movs r1, #1
_0820FF90:
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
