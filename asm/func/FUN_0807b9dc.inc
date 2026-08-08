	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _0807BA0C @ =0x000004A9
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	subs r3, #0x11
	adds r1, r4, r3
	ldr r0, _0807BA10 @ =FUN_080727d4
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BA0C: .4byte 0x000004A9
_0807BA10: .4byte FUN_080727d4
