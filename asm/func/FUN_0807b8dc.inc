	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807B90C @ =FUN_080726e0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B90C: .4byte FUN_080726e0
