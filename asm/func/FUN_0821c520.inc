	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	movs r1, #0x20
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821C542
	ldr r2, _0821C568 @ =0x00080004
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0821C542:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r3, r4, r0
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r1, [r0]
	movs r2, #4
	subs r0, #0x13
	ldr r0, [r0]
	ands r0, r2
	orrs r1, r0
	cmp r1, #0
	beq _0821C56C
	ldrh r1, [r3, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3, #6]
	b _0821C592
	.align 2, 0
_0821C568: .4byte 0x00080004
_0821C56C:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r3, #6]
	ands r0, r1
	strh r0, [r3, #6]
	adds r1, r4, #0
	adds r1, #0x50
	adds r0, r3, #0
	movs r2, #0
	bl FUN_082364c4
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xcf
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_0821C592:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r4, r0
	adds r0, r5, #0
	adds r0, #0xab
	ldrb r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xc
	subs r0, #0x13
	ldr r0, [r0]
	ands r0, r2
	orrs r1, r0
	cmp r1, #0
	beq _0821C5B8
	ldrh r1, [r3, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3, #6]
	b _0821C5CE
_0821C5B8:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r3, #6]
	ands r0, r1
	strh r0, [r3, #6]
	adds r1, r4, #0
	adds r1, #0x50
	adds r0, r3, #0
	movs r2, #0
	bl FUN_082364c4
_0821C5CE:
	pop {r4, r5}
	pop {r0}
	bx r0
