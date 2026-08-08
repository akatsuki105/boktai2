	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	cmp r3, #0
	beq _0807CB44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0807CB3C @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _0807CB40 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0807CB5A
	.align 2, 0
_0807CB3C: .4byte 0x000002E6
_0807CB40: .4byte 0x000002E7
_0807CB44:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0807CB84 @ =0x000002E6
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0807CB5A:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	bl FUN_0807b7a4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0807CB88 @ =FUN_080728a8
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807CB84: .4byte 0x000002E6
_0807CB88: .4byte FUN_080728a8
