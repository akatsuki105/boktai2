	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0812FCF0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FCF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812FCF6
	.align 2, 0
_0812FCF0: .4byte 0x0000046C
_0812FCF4:
	movs r0, #0
_0812FCF6:
	adds r4, r0, #0
	cmp r4, #0
	beq _0812FD3C
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0812FD30 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0812FD34 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0812FD38 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	b _0812FDAE
	.align 2, 0
_0812FD30: .4byte 0x0000046D
_0812FD34: .4byte 0x0000046B
_0812FD38: .4byte 0x00000553
_0812FD3C:
	ldr r2, _0812FD98 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812FDA4
	movs r1, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0812FD9C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r3, [r0]
	movs r2, #0x1a
	ldr r6, _0812FDA0 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0812FD98 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0812FDAE
	.align 2, 0
_0812FD98: .4byte 0x0000046B
_0812FD9C: .4byte 0x00000484
_0812FDA0: .4byte 0x0000046D
_0812FDA4:
	ldr r6, _0812FDB4 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812FDAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812FDB4: .4byte 0x00000484
