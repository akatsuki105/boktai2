	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	beq _0807CC44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807CC3C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807CC40 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807CC5A
	.align 2, 0
_0807CC3C: .4byte 0x000002E6
_0807CC40: .4byte 0x000002E7
_0807CC44:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CC7C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
_0807CC5A:
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CC80 @ =FUN_08072a0c
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CC7C: .4byte 0x000002E6
_0807CC80: .4byte FUN_08072a0c
