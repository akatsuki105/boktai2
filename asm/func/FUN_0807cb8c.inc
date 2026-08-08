	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	blt _0807CB9C
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_0807CB9C:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	movs r1, #1
	orrs r1, r0
	strb r1, [r3]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807CBD0
	ldrb r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r3, _0807CBC8 @ =0x000002E6
	adds r1, r4, r3
	strb r0, [r1]
	ldr r0, _0807CBCC @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0807CBDE
	.align 2, 0
_0807CBC8: .4byte 0x000002E6
_0807CBCC: .4byte 0x000002E7
_0807CBD0:
	lsrs r1, r1, #0x19
	ldr r3, _0807CC08 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r0, _0807CC0C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0807CBDE:
	strb r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0x93
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, _0807CC10 @ =FUN_080729e0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807CC08: .4byte 0x000002E6
_0807CC0C: .4byte 0x000002E7
_0807CC10: .4byte FUN_080729e0
