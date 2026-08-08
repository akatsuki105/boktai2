	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r1, #4
	bl FUN_0807b910
	ldr r1, _0807BC04 @ =0x000004A6
	adds r0, r4, r1
	movs r2, #0
	strb r5, [r0]
	adds r1, #0xa
	adds r0, r4, r1
	str r6, [r0]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0807BC08 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807BC0C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807BC10 @ =FUN_0807304c
	str r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807BC04: .4byte 0x000004A6
_0807BC08: .4byte 0x000002E6
_0807BC0C: .4byte 0x000002E7
_0807BC10: .4byte FUN_0807304c
