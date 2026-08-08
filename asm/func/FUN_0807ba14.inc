	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807BA24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807BA24:
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807BA4C @ =FUN_08072724
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BA4C: .4byte FUN_08072724
