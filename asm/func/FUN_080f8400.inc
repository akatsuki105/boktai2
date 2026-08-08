	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _080F8424 @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	ldr r2, _080F8428 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _080F842C
	cmp r0, #0x13
	beq _080F8436
	b _080F843C
	.align 2, 0
_080F8424: .4byte 0xFFFFFEFF
_080F8428: .4byte 0x000001DF
_080F842C:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080F843C
_080F8436:
	ldr r0, _080F84B4 @ =0x00000109
	bl PlaySound_082406e0
_080F843C:
	ldr r6, _080F84B8 @ =0x000005CC
	adds r0, r5, r6
	ldr r3, [r0]
	movs r1, #0x12
	ldr r2, _080F84BC @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _080F84C0 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080F84C4 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _080F84C8 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r0, _080F84CC @ =0xFFFFF636
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _080F84D0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080F84B4: .4byte 0x00000109
_080F84B8: .4byte 0x000005CC
_080F84BC: .4byte 0x0000046D
_080F84C0: .4byte 0x0000046B
_080F84C4: .4byte 0x00000469
_080F84C8: .4byte 0x0000046C
_080F84CC: .4byte 0xFFFFF636
_080F84D0: .4byte 0xFEFFFFFF
