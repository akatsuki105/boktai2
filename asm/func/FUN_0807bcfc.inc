	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_0807b7a4
	cmp r5, #0
	blt _0807BD12
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807BD12:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r0, #0xc6
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BD40 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807BD40: .4byte FUN_08073574
