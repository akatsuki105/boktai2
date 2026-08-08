	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r1, r2, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl FUN_08240b98
	adds r5, r0, #0
	ldr r0, _080FA380 @ =0x0000B546
	cmp r5, r0
	bne _080FA376
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r4, #0
	bl FUN_080e8ae4
_080FA376:
	adds r0, r5, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080FA380: .4byte 0x0000B546
