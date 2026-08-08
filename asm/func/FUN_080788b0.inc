	push {lr}
	adds r3, r0, #0
	adds r3, #0x2c
	ldr r2, _080788CC @ =0x00000392
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl FUN_08086294
	pop {r1}
	bx r1
	.align 2, 0
_080788CC: .4byte 0x00000392
