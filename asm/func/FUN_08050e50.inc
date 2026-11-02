	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_0804f820
	cmp r0, #0
	beq _08050E78
	adds r2, r0, #0
	adds r2, #0xc8
	lsls r1, r4, #1
	movs r3, #0xd7
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r5, r1
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
_08050E78:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
