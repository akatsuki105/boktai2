	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_0807b7a4
	cmp r5, #0
	blt _0807BCC8
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807BCC8:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r6, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BCF8 @ =FUN_08073574
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807BCF8: .4byte FUN_08073574
