	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x39
_080BE9EA:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BE9EA
	ldr r1, _080BEA10 @ =0x00001690
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080BEA14 @ =0x000017B4
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEA10: .4byte 0x00001690
_080BEA14: .4byte 0x000017B4
