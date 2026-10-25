	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0x96
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x12
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802D158
	strb r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa7
	strb r2, [r0]
	movs r0, #1
	b _0802D15A
_0802D158:
	movs r0, #0
_0802D15A:
	cmp r0, #0
	beq _0802D17A
	movs r0, #0x11
	adds r2, r5, #0
	adds r2, #0xa2
	movs r1, #0
	strb r0, [r2]
	ldr r2, _0802D1A8 @ =0x00000898
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _0802D1AC @ =0x000008D4
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_0802D17A:
	ldr r1, _0802D1B0 @ =0x00000864
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0802D1B8
	movs r2, #0x5a
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802D1B4 @ =0x0000089C
	adds r0, r4, r1
	strh r2, [r0]
	b _0802D28E
	.align 2, 0
_0802D1A8: .4byte 0x00000898
_0802D1AC: .4byte 0x000008D4
_0802D1B0: .4byte 0x00000864
_0802D1B4: .4byte 0x0000089C
_0802D1B8:
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r2, [r0]
	cmp r2, #0
	beq _0802D1D8
	movs r0, #0x12
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	b _0802D1F8
_0802D1D8:
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r0, r5, #0
	adds r0, #0x98
	ldr r3, [r0]
	ands r3, r1
	cmp r3, #0
	beq _0802D1FE
	movs r0, #0x10
	adds r1, r5, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xbc
	str r2, [r0]
	adds r1, #2
_0802D1F8:
	movs r0, #1
	strb r0, [r1]
	b _0802D28E
_0802D1FE:
	ldr r2, _0802D244 @ =0x00000894
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r2, #0x42
	adds r0, r4, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _0802D270
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0802D248
	subs r2, #0x3d
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0
	strb r0, [r2]
	movs r0, #5
	adds r2, r5, #0
	adds r2, #0xa6
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r3, [r0]
	b _0802D266
	.align 2, 0
_0802D244: .4byte 0x00000894
_0802D248:
	ldr r1, _0802D26C @ =0x00000899
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #5
	adds r2, r5, #0
	adds r2, #0xa6
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r6, [r0]
_0802D266:
	subs r0, #0x14
	strb r1, [r0]
	b _0802D28E
	.align 2, 0
_0802D26C: .4byte 0x00000899
_0802D270:
	adds r0, r4, #0
	bl FUN_080280cc
	cmp r0, #0
	bne _0802D28E
	adds r0, r4, #0
	bl FUN_080281ec
	cmp r0, #0
	bne _0802D28E
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0802D28E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
