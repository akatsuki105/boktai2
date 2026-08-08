	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0x10
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	bne _0806F9A2
	b _0806FAC6
_0806F9A2:
	ldr r6, [r7, #0x4c]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08236524
	movs r4, #0
_0806F9AE:
	lsls r1, r4, #2
	ldr r2, _0806FA80 @ =0x00000AB4
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _0806F9CC
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl _call_via_r3
	ldrh r1, [r5, #0x3e]
	adds r1, r1, r0
	strh r1, [r5, #0x3e]
_0806F9CC:
	adds r4, #1
	cmp r4, #2
	ble _0806F9AE
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806FAC6
	ldr r2, _0806FA84 @ =0x00000A8D
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0806FA22
	adds r0, r6, #0
	bl FUN_08060e1c
	cmp r0, #0
	beq _0806FA22
	adds r2, r5, #0
	adds r2, #0x43
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0806FA22
	ldrh r1, [r5, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r5, #0x3e]
	ldrh r1, [r5, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806FA22
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_0806FA22:
	movs r1, #0xf8
	lsls r1, r1, #4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0806FAC6
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806FAC6
	ldr r3, _0806FA88 @ =0x030046A0
	ldr r1, [r3]
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r3]
	adds r2, r0, r2
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	ldr r2, [r2]
	cmp r2, r0
	bne _0806FA94
	ldr r0, _0806FA8C @ =0x00000302
	bl PlaySound_082406e0
	ldr r2, _0806FA90 @ =0x0000095E
	adds r1, r6, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r2, #0x40
	movs r0, #0x40
	b _0806FAB4
	.align 2, 0
_0806FA80: .4byte 0x00000AB4
_0806FA84: .4byte 0x00000A8D
_0806FA88: .4byte 0x030046A0
_0806FA8C: .4byte 0x00000302
_0806FA90: .4byte 0x0000095E
_0806FA94:
	asrs r0, r1, #1
	cmp r2, r0
	bne _0806FABC
	ldr r0, _0806FACC @ =0x00000302
	bl PlaySound_082406e0
	ldr r2, _0806FAD0 @ =0x0000095E
	adds r1, r6, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r2, #0x20
	movs r0, #0x20
_0806FAB4:
	strh r0, [r1]
	ldr r1, _0806FAD4 @ =0x0000044B
	adds r0, r6, r1
	strb r2, [r0]
_0806FABC:
	movs r2, #0x89
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0806FAC6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806FACC: .4byte 0x00000302
_0806FAD0: .4byte 0x0000095E
_0806FAD4: .4byte 0x0000044B
