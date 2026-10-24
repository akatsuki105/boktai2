	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf0
	adds r1, r4, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A46A4
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080a45a8
	adds r2, r4, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A46AC @ =FUN_080a46b0
	adds r0, r4, #0
	bl Entity1E98_SetUpdateCallback
_080A46A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A46AC: .4byte FUN_080a46b0
