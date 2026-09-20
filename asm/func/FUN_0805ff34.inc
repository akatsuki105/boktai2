	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	adds r0, #0x10
	bl AuxSprite_Remove
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x1c]
	bics r0, r1
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
