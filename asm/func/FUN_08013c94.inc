	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0x38
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, #0xc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a4fc
	strh r6, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
