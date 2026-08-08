	movs r7, #0x94
	lsls r7, r7, #1
	adds r3, r6, r7
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r6, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _080F5154 @ =0xFFFF7FFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r3, r6, r1
	ldrb r4, [r6, #5]
	ldr r2, _080F5158 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	ldr r1, [sp]
	muls r0, r1, r0
	cmp r0, #0
	blt _080F515C
	asrs r1, r0, #0xc
	b _080F5162
	.align 2, 0
_080F5154: .4byte 0xFFFF7FFF
_080F5158: .4byte 0x085B0A08
_080F515C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080F5162:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r7, [sp]
	muls r0, r7, r0
	cmp r0, #0
	blt _080F517C
	asrs r0, r0, #0xc
	b _080F5182
_080F517C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080F5182:
	movs r2, #0
	movs r5, #0
	strh r0, [r3, #4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r1, [r0]
	ldr r7, _080F51F4 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _080F51F8 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	str r5, [r0]
	adds r7, #3
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	ldr r3, _080F51FC @ =0x000005EC
	adds r0, r6, r3
	ldr r4, [r0]
	movs r3, #0x20
	adds r7, #1
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _080F5200 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _080F5204 @ =0x00000553
	adds r0, r6, r2
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	strh r5, [r0]
_080F51E0:
	movs r0, #1
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F51F4: .4byte 0x00000469
_080F51F8: .4byte 0x0000046A
_080F51FC: .4byte 0x000005EC
_080F5200: .4byte 0x0000046B
_080F5204: .4byte 0x00000553
