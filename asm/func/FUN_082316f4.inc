	push {r4, lr}
	adds r4, r0, #0
	bl VM_GetPC
	adds r1, r4, #0
	bl FUN_082315c0
	pop {r4}
	pop {r1}
	bx r1
