	push {r4, lr}
	adds r4, r0, #0
	str r1, [r4, #0x18]
	adds r0, #0x6c
	movs r1, #0
	strh r2, [r0]
	adds r0, #6
	strh r3, [r0]
	subs r0, #3
	strb r1, [r0]
	adds r0, r4, #0
	bl Entity080c1abc_InitSprite
	adds r0, r4, #0
	bl FUN_080c13f8
	adds r0, r4, #0
	bl Entity080c1abc_InitParticles
	ldr r1, _080C1AB8 @ =FUN_080c1810
	adds r0, r4, #0
	bl Entity080c1abc_SetUpdateCallback
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C1AB8: .4byte FUN_080c1810
