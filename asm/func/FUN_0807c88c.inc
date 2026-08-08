	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0807C8CC @ =0x0000049C
	adds r5, r4, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r5]
	str r1, [r5, #4]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	subs r1, #7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C8D0 @ =FUN_080746ec
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807C8CC: .4byte 0x0000049C
_0807C8D0: .4byte FUN_080746ec
