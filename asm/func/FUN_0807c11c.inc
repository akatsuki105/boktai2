	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	cmp r1, #0
	blt _0807C12E
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
_0807C12E:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0807C164
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0807C15C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _0807C160 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _0807C172
	.align 2, 0
_0807C15C: .4byte 0x000002E6
_0807C160: .4byte 0x000002E7
_0807C164:
	lsrs r1, r1, #0x19
	ldr r2, _0807C1C8 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0807C1CC @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_0807C172:
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0807b7a4
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	ldr r2, _0807C1C8 @ =0x000002E6
	adds r1, r6, r2
	ldrb r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	ldr r1, _0807C1CC @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807C1D0
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _0807C1DC
	.align 2, 0
_0807C1C8: .4byte 0x000002E6
_0807C1CC: .4byte 0x000002E7
_0807C1D0:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0807C1DC:
	str r1, [r0]
	adds r0, r6, #0
	movs r1, #0x18
	movs r2, #2
	bl FUN_08060b84
	movs r2, #0x93
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, _0807C1FC @ =FUN_08073e18
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807C1FC: .4byte FUN_08073e18
