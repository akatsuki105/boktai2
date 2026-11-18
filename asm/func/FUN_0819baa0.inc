	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0819BAC0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BAC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BAC6
	.align 2, 0
_0819BAC0: .4byte 0x0000046D
_0819BAC4:
	movs r0, #0
_0819BAC6:
	cmp r0, #0
	beq _0819BB16
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	ldr r1, _0819BBA8 @ =0x00000CBB
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0819BBAC @ =0x00000A5D
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0819BBB0 @ =0x00000A4C
	adds r2, r5, r0
	ldr r1, _0819BBB4 @ =0x00000A7C
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0819BBB8 @ =0x00000CB8
	adds r0, r5, r2
	ldrb r1, [r0]
	ldr r2, _0819BBBC @ =0x00000A5C
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0819BBC0 @ =0x00000A5E
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	ldr r1, _0819BBC4 @ =0x00000CBC
	adds r0, r5, r1
	bl ParticleShadow_Hide
	movs r0, #1
	str r0, [r4]
_0819BB16:
	ldr r2, _0819BBBC @ =0x00000A5C
	adds r0, r5, r2
	ldrb r2, [r0]
	ldr r1, _0819BBC0 @ =0x00000A5E
	adds r4, r5, r1
	ldrb r1, [r4]
	subs r1, r2, r1
	strb r1, [r0]
	cmp r2, r1
	bge _0819BB30
	ldr r0, _0819BBC8 @ =0x00000169
	bl PlaySound_082406e0
_0819BB30:
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _0819BB42
	ldrb r0, [r4]
	cmp r0, #0x13
	bhi _0819BB42
	adds r0, #1
	strb r0, [r4]
_0819BB42:
	ldr r2, _0819BBB0 @ =0x00000A4C
	adds r1, r5, r2
	ldr r4, _0819BBBC @ =0x00000A5C
	adds r0, r5, r4
	ldrb r2, [r0]
	adds r0, r6, #0
	bl FUN_0819f150
	adds r0, r6, #0
	bl FUN_0819fdf0
	adds r0, r6, #0
	bl FUN_0819fc5c
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0819BBA0
	cmp r7, #0x1e
	ble _0819BBA0
	adds r0, r6, #0
	bl FUN_0819fca4
	ldr r3, _0819BBCC @ =FUN_0819cc04
	movs r2, #0x33
	ldr r1, _0819BBD0 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	strb r4, [r0]
	ldr r4, _0819BBD4 @ =0x0000046B
	adds r0, r6, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
_0819BBA0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819BBA8: .4byte 0x00000CBB
_0819BBAC: .4byte 0x00000A5D
_0819BBB0: .4byte 0x00000A4C
_0819BBB4: .4byte 0x00000A7C
_0819BBB8: .4byte 0x00000CB8
_0819BBBC: .4byte 0x00000A5C
_0819BBC0: .4byte 0x00000A5E
_0819BBC4: .4byte 0x00000CBC
_0819BBC8: .4byte 0x00000169
_0819BBCC: .4byte FUN_0819cc04
_0819BBD0: .4byte 0x0000046D
_0819BBD4: .4byte 0x0000046B
