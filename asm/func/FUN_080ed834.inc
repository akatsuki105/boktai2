	push {r4, r5, r6, lr}
	movs r0, #0x6e
	movs r1, #0
	bl FUN_0823174c
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl FUN_0823174c
	adds r5, r0, #0
	cmp r4, #0
	beq _080ED8DA
	adds r0, r4, #0
	bl FUN_080edda0
	adds r3, r0, #0
	cmp r3, #0
	beq _080ED8DA
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, _080ED870 @ =0x00000474
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080ED874
	movs r0, #1
	b _080ED876
	.align 2, 0
_080ED870: .4byte 0x00000474
_080ED874:
	movs r0, #0
_080ED876:
	cmp r0, #0
	beq _080ED8DA
	movs r2, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	strb r2, [r0]
	ldr r6, _080ED8E0 @ =0x00000469
	adds r0, r3, r6
	strb r1, [r0]
	ldr r2, _080ED8E4 @ =0x0000046A
	adds r0, r3, r2
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r3, r4
	str r1, [r0]
	adds r6, #3
	adds r0, r3, r6
	movs r4, #1
	strb r4, [r0]
	cmp r5, #0
	bne _080ED8CA
	ldr r2, _080ED8E8 @ =FUN_080e48d0
	movs r1, #0x10
	adds r6, #1
	adds r0, r3, r6
	strb r4, [r0]
	ldr r4, _080ED8EC @ =0x0000046B
	adds r0, r3, r4
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r3, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r3, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r3, r2
	strh r5, [r0]
_080ED8CA:
	movs r0, #0x80
	lsls r0, r0, #7
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r3, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080ED8DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ED8E0: .4byte 0x00000469
_080ED8E4: .4byte 0x0000046A
_080ED8E8: .4byte FUN_080e48d0
_080ED8EC: .4byte 0x0000046B
