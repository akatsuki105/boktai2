	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _080F6588 @ =0x0000049C
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _080F6512
	movs r0, #0x20
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080F6512:
	ldr r1, _080F658C @ =0x000005CC
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #0x12
	ldr r2, _080F6590 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _080F6594 @ =0x0000046B
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
	ldr r1, _080F6598 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _080F659C @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _080F65A0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, _080F65A4 @ =0xFFFFF636
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080F6588: .4byte 0x0000049C
_080F658C: .4byte 0x000005CC
_080F6590: .4byte 0x0000046D
_080F6594: .4byte 0x0000046B
_080F6598: .4byte 0x00000469
_080F659C: .4byte 0x0000046C
_080F65A0: .4byte 0xFEFFFFFF
_080F65A4: .4byte 0xFFFFF636
