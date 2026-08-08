	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807C8E4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_0807C8E4:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r0, _0807C924 @ =FUN_08074994
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C924: .4byte FUN_08074994
