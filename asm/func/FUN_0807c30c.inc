	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0807C32E
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0807c200
_0807C32E:
	cmp r5, #0
	blt _0807C33A
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
_0807C33A:
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r6, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #7
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807C368 @ =FUN_0807317c
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C368: .4byte FUN_0807317c
