	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0x96
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C7C4 @ =FUN_080744bc
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C7C4: .4byte FUN_080744bc
