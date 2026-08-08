	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0xd9
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DFCBC
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r1, #0
	ldrsh r0, [r4, r1]
	subs r2, #0x18
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	bl FUN_0823785c
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	adds r6, r4, #0
	movs r4, #0xc
	ldr r2, _080DFC3C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080DFC40
	asrs r1, r0, #0xc
	b _080DFC46
	.align 2, 0
_080DFC3C: .4byte 0x085B0A08
_080DFC40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DFC46:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _080DFC64 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080DFC68
	asrs r0, r0, #0xc
	b _080DFC6E
	.align 2, 0
_080DFC64: .4byte 0x085B0A08
_080DFC68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DFC6E:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r2, _080DFD18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DFD1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080DFD20 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #8
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0xf4
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0xf2
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0xd9
	lsls r1, r1, #1
	adds r0, r5, r1
	strb r4, [r0]
_080DFCBC:
	adds r0, r5, #0
	bl FUN_080df6d4
	adds r2, r5, #0
	adds r2, #0x1c
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	movs r0, #0xcb
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	ldrh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080DFD14
	cmp r1, #0
	blt _080DFD14
	ldr r0, _080DFD24 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080DFD14
	ldr r0, _080DFD28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DFD2C
_080DFD14:
	movs r4, #0
	b _080DFD3A
	.align 2, 0
_080DFD18: .4byte 0x030046B8
_080DFD1C: .4byte 0x000003FF
_080DFD20: .4byte 0x0203B400
_080DFD24: .4byte 0x030046A8
_080DFD28: .4byte 0x030046AC
_080DFD2C:
	ldr r0, _080DFD4C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080DFD3A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DFD50
	adds r0, #4
	b _080DFD5C
	.align 2, 0
_080DFD4C: .4byte 0x030046A4
_080DFD50:
	ldr r0, _080DFDD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DFD5C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r2, r1, #8
	movs r1, #0x1e
	ldrsh r0, [r5, r1]
	cmp r0, r2
	bge _080DFD84
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	strh r2, [r5, #0x1e]
_080DFD84:
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r1, [r4]
	adds r0, r5, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DFDDC
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_08236424
	adds r0, r5, #0
	bl FUN_080df714
	adds r0, r5, #0
	bl FUN_0822a4e0
	ldr r3, _080DFDD8 @ =0x000001AF
	adds r2, r5, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r0, #0xaf
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _080DFDE2
	.align 2, 0
_080DFDD4: .4byte 0x030046A4
_080DFDD8: .4byte 0x000001AF
_080DFDDC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_080DFDE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
