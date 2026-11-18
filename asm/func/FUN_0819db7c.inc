	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0819DB94 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819DB98
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819DB9A
	.align 2, 0
_0819DB94: .4byte 0x0000046C
_0819DB98:
	movs r0, #0
_0819DB9A:
	cmp r0, #0
	beq _0819DBC8
	ldr r4, _0819DC24 @ =FUN_0819bd2c
	movs r3, #0x22
	ldr r6, _0819DC28 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819DC2C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_0819DBC8:
	ldr r6, _0819DC2C @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819DC3C
	ldr r1, _0819DC30 @ =0x000005A4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0
	ldr r3, _0819DC28 @ =0x0000046D
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0819DC34 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0819DC38 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _0819DC46
	.align 2, 0
_0819DC24: .4byte FUN_0819bd2c
_0819DC28: .4byte 0x0000046D
_0819DC2C: .4byte 0x0000046B
_0819DC30: .4byte 0x000005A4
_0819DC34: .4byte 0x0000046A
_0819DC38: .4byte 0x00000484
_0819DC3C:
	ldr r0, _0819DC4C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0819DC46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819DC4C: .4byte 0x00000484
