	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _0807BC5C @ =0x000004A6
	adds r0, r4, r3
	movs r3, #0
	strb r1, [r0]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r3, [r0]
	subs r1, #2
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r4, r4, r3
	ldr r0, _0807BC60 @ =FUN_0807304c
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC5C: .4byte 0x000004A6
_0807BC60: .4byte FUN_0807304c
