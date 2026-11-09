	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818BF00 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818BF04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818BF06
	.align 2, 0
_0818BF00: .4byte 0x0000046C
_0818BF04:
	movs r0, #0
_0818BF06:
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r4, r5, r7
	cmp r0, #0
	beq _0818BFD6
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0818BF68 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818BF6C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	ldr r7, _0818BF70 @ =0x00000553
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r7, _0818BF74 @ =0x000001DD
	adds r0, r5, r7
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r3, r5, r1
	ldrb r4, [r0]
	ldr r2, _0818BF78 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0818BF7C
	asrs r1, r0, #0xc
	b _0818BF82
	.align 2, 0
_0818BF68: .4byte 0x0000046D
_0818BF6C: .4byte 0x0000046B
_0818BF70: .4byte 0x00000553
_0818BF74: .4byte 0x000001DD
_0818BF78: .4byte gSineTable
_0818BF7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818BF82:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0818BF9C
	asrs r0, r0, #0xc
	b _0818BFA2
_0818BF9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0818BFA2:
	strh r0, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0x20
	strh r0, [r1]
	movs r7, #0xde
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	movs r0, #0x80
	ldr r1, _0818C058 @ =0x00000F2C
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r4, r3, #0
_0818BFD6:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_0818fdd8
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0818C06C
	adds r0, r5, #0
	bl FUN_0818e6fc
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0818C05C @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r3, [r0]
	ldr r7, _0818C060 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r3, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #0x14
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _0818C064 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _0818C068 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r3, [r0]
	ldr r0, _0818C058 @ =0x00000F2C
	adds r2, r6, r0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0818C076
	.align 2, 0
_0818C058: .4byte 0x00000F2C
_0818C05C: .4byte 0x0000046D
_0818C060: .4byte 0x0000046B
_0818C064: .4byte 0x0000046A
_0818C068: .4byte 0x00000484
_0818C06C:
	ldr r2, _0818C07C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818C076:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818C07C: .4byte 0x00000484
