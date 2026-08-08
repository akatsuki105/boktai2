	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080F208C @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F2090
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F2092
	.align 2, 0
_080F208C: .4byte 0x0000046C
_080F2090:
	movs r0, #0
_080F2092:
	adds r5, r0, #0
	cmp r5, #0
	beq _080F20D4
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _080F20C8 @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _080F20CC @ =0x0000046B
	adds r0, r4, r5
	strb r2, [r0]
	ldr r6, _080F20D0 @ =0x00000553
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r4, r5
	strh r2, [r0]
	b _080F2156
	.align 2, 0
_080F20C8: .4byte 0x0000046D
_080F20CC: .4byte 0x0000046B
_080F20D0: .4byte 0x00000553
_080F20D4:
	ldr r6, _080F2138 @ =0x0000046B
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080F214C
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
	ldr r1, _080F213C @ =0x000005A4
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _080F2140 @ =0x0000046D
	adds r0, r4, r2
	movs r3, #1
	strb r3, [r0]
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r5, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r2, #0
	strh r5, [r0]
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r2, [r0]
	ldr r2, _080F2144 @ =0x0000046A
	adds r0, r4, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r5, [r0]
	ldr r1, _080F2148 @ =0x0000046C
	adds r0, r4, r1
	strb r3, [r0]
	b _080F2156
	.align 2, 0
_080F2138: .4byte 0x0000046B
_080F213C: .4byte 0x000005A4
_080F2140: .4byte 0x0000046D
_080F2144: .4byte 0x0000046A
_080F2148: .4byte 0x0000046C
_080F214C:
	ldr r2, _080F215C @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2156:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F215C: .4byte 0x00000484
