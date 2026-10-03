	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xda
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_080baa40
	ldr r2, _080BAAD8 @ =0x000012F2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080BAADC @ =0x00001408
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r2, _080BAAE0 @ =0x00000D98
	adds r1, r5, r2
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080ba410
	adds r0, r5, #0
	bl FUN_080ba57c
	adds r0, r5, #0
	bl FUN_080ba2d8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ba85c
	ldr r1, _080BAAE4 @ =FUN_080baae8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080ba054
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BAAD8: .4byte 0x000012F2
_080BAADC: .4byte 0x00001408
_080BAAE0: .4byte 0x00000D98
_080BAAE4: .4byte FUN_080baae8
