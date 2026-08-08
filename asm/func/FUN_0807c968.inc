	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807b7a4
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0807C9A4 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r4, r4, r0
	ldr r0, _0807C9A8 @ =FUN_080749b0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807C9A4: .4byte 0x000002E6
_0807C9A8: .4byte FUN_080749b0
