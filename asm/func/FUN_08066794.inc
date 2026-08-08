	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080612d8
	ldr r0, _080667AC @ =0x00000376
	adds r4, r4, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080667AC: .4byte 0x00000376
