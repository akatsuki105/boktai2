	push {r4, lr}
	adds r4, r0, #0
	bl rfu_clearAllSlot
	adds r0, r4, #0
	bl FUN_0804ba64
	pop {r4}
	pop {r1}
	bx r1
