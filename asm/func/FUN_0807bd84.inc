	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #0
	blt _0807BD96
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BD96:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #3
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807BDC4 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BDC4: .4byte FUN_08073574
