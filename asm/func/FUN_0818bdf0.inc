	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818BE10 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818BE14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818BE16
	.align 2, 0
_0818BE10: .4byte 0x0000046C
_0818BE14:
	movs r0, #0
_0818BE16:
	cmp r0, #0
	beq _0818BE66
	ldr r4, _0818BEAC @ =FUN_08189614
	movs r3, #0x25
	ldr r0, _0818BEB0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818BEB4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0818BEB8 @ =0x000003E5
	bl sound_08240740
	ldr r0, _0818BEBC @ =0x00000F2C
	adds r2, r6, r0
	ldr r0, _0818BEC0 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0818BE66:
	ldr r1, _0818BEB4 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0818BECC
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _0818BEC4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0818BEC8 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0818BED6
	.align 2, 0
_0818BEAC: .4byte FUN_08189614
_0818BEB0: .4byte 0x0000046D
_0818BEB4: .4byte 0x0000046B
_0818BEB8: .4byte 0x000003E5
_0818BEBC: .4byte 0x00000F2C
_0818BEC0: .4byte 0xFFFF7FFF
_0818BEC4: .4byte 0x00000484
_0818BEC8: .4byte 0xFFEFFFFF
_0818BECC:
	ldr r2, _0818BEDC @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818BED6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818BEDC: .4byte 0x00000484
