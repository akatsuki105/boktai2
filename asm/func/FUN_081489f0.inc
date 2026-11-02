	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x11
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r5, #0
	strb r5, [r0]
	ldr r6, _08148AC4 @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r5, [r0]
	ldr r1, _08148AC8 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08148ACC @ =Enemy_ClearStateBegun
	movs r2, #0x10
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r5, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r4, r2
	str r5, [r0]
	ldr r6, _08148AD0 @ =0x00000482
	adds r0, r4, r6
	strh r1, [r0]
	ldr r1, _08148AD4 @ =0x00000222
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #0x76
	adds r0, r4, r2
	strh r5, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r3, r4, r6
	ldr r0, _08148AD8 @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08148ADC @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08148AAC
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08148AE0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08148AE4 @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r6, #0x9e
	adds r0, r4, r6
	strh r5, [r0]
	ldr r1, _08148AE8 @ =0x00000202
	adds r0, r4, r1
	strh r5, [r0]
_08148AAC:
	ldr r0, _08148AEC @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r2, _08148AF0 @ =0x00000542
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08148AC4: .4byte 0x00000469
_08148AC8: .4byte 0x0000046C
_08148ACC: .4byte Enemy_ClearStateBegun
_08148AD0: .4byte 0x00000482
_08148AD4: .4byte 0x00000222
_08148AD8: .4byte 0xFFFFFC7F
_08148ADC: .4byte 0xF3FFFFFF
_08148AE0: .4byte 0xFEFFFFFF
_08148AE4: .4byte 0xFFFFFDFF
_08148AE8: .4byte 0x00000202
_08148AEC: .4byte 0xFFFFFBFF
_08148AF0: .4byte 0x00000542
