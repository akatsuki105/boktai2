	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	adds r5, r3, #0
	cmp r1, #0
	blt _0807C75C
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C75C:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	ldr r2, _0807C790 @ =0x000004A7
	adds r0, r4, r2
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C794 @ =FUN_080744bc
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C790: .4byte 0x000004A7
_0807C794: .4byte FUN_080744bc
