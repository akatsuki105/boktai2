	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x44
	ldr r1, _080A8700 @ =0x00001C1D
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822b20c
	ldr r0, [r5, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x18]
	strb r1, [r5, #0x1f]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8700: .4byte 0x00001C1D
