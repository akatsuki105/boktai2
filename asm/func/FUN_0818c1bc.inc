	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0818C1D4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818C1D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818C1DA
	.align 2, 0
_0818C1D4: .4byte 0x0000046C
_0818C1D8:
	movs r0, #0
_0818C1DA:
	cmp r0, #0
	beq _0818C280
	ldr r1, _0818C230 @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _0818C234 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0818C238 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0818C23C @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r4, [r5, #5]
	ldr r2, _0818C240 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0818C244
	asrs r1, r0, #0xc
	b _0818C24A
	.align 2, 0
_0818C230: .4byte 0x000005A4
_0818C234: .4byte 0x0000046D
_0818C238: .4byte 0x0000046B
_0818C23C: .4byte 0x00000553
_0818C240: .4byte gSineTable
_0818C244:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818C24A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0818C264
	asrs r2, r0, #0xc
	b _0818C26A
_0818C264:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818C26A:
	movs r0, #0
	strh r2, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_0818C280:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818C308
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0818C2F8 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0818C2FC @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0818C300 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _0818C304 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _0818C312
	.align 2, 0
_0818C2F8: .4byte 0x0000046D
_0818C2FC: .4byte 0x0000046B
_0818C300: .4byte 0x0000046A
_0818C304: .4byte 0x00000484
_0818C308:
	ldr r0, _0818C318 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818C312:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0818C318: .4byte 0x00000484
