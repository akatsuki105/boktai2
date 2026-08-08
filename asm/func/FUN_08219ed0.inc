	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08219F2C @ =0x0000CB05
	ldr r1, _08219F30 @ =0x000042E2
	bl FUN_082310cc
	adds r1, r0, #0
	adds r2, r4, #0
	adds r2, #0x18
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0822f284
	adds r0, r4, #0
	bl FUN_082138d4
	adds r0, r4, #0
	bl FUN_08213ce4
	adds r0, r4, #0
	bl FUN_08214160
	adds r0, r4, #0
	bl FUN_082150e8
	adds r0, r4, #0
	bl FUN_082157d4
	adds r0, r4, #0
	bl FUN_08215db4
	adds r0, r4, #0
	bl FUN_08218c30
	adds r0, r4, #0
	bl FUN_082169a0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08219F2C: .4byte 0x0000CB05
_08219F30: .4byte 0x000042E2
