	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x33
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08060c40
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
