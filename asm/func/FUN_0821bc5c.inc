	push {lr}
	adds r0, #0x1c
	bl FUN_08022428
	movs r0, #0x6a
	bl sound_08240740
	movs r0, #0
	pop {r1}
	bx r1
