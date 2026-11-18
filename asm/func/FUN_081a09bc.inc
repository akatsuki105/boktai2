	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081A0A10 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A09CE
	movs r0, #0
	strb r0, [r1]
_081A09CE:
	ldr r1, _081A0A14 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0A20
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A0A18 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _081A0A1C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081A0A2A
	.align 2, 0
_081A0A10: .4byte 0x0000046C
_081A0A14: .4byte 0x0000046B
_081A0A18: .4byte 0xFFFFFEFF
_081A0A1C: .4byte 0x00000484
_081A0A20:
	ldr r0, _081A0A30 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0A2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A0A30: .4byte 0x00000484
