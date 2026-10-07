	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08012236
	movs r0, #0
	strb r0, [r4]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r4, r3]
	movs r5, #0x14
	ldrsh r2, [r4, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	ldr r3, _080121F4 @ =0x030046B8
	ldr r0, [r3]
	adds r1, r0, #1
	ldr r2, _080121F8 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r0, r1, #1
	ldr r5, _080121FC @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08012200
	adds r0, r1, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r4, #7]
	adds r0, #0x40
	movs r1, #0x3f
	ands r2, r1
	subs r0, r0, r2
	b _08012218
	.align 2, 0
_080121F4: .4byte 0x030046B8
_080121F8: .4byte 0x000003FF
_080121FC: .4byte 0x0203B400
_08012200:
	adds r0, r1, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08012260 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldrb r0, [r4, #7]
	adds r0, #0x40
	movs r1, #0x3f
	ands r2, r1
	adds r0, r0, r2
_08012218:
	strb r0, [r4, #7]
	ldr r2, _08012264 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08012268 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08012260 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r4, #8]
_08012236:
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080122DE
	mov r5, sp
	movs r3, #7
	ldrsb r3, [r4, r3]
	ldrh r6, [r4, #0xc]
	ldr r2, _0801226C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08012270
	asrs r1, r0, #0xc
	b _08012276
	.align 2, 0
_08012260: .4byte 0x0203B400
_08012264: .4byte 0x030046B8
_08012268: .4byte 0x000003FF
_0801226C: .4byte 0x085B0A08
_08012270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08012276:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08012292
	asrs r0, r0, #0xc
	b _08012298
_08012292:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012298:
	strh r0, [r5, #4]
	adds r3, r4, #0
	adds r3, #0x10
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r4, #0x10]
	adds r0, r0, r5
	strh r0, [r4, #0x10]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	ldr r0, _08012308 @ =0x00000CCC
	adds r2, r7, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0x10
	ldrsh r1, [r4, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
	ldrb r0, [r4, #8]
	subs r0, #1
	strb r0, [r4, #8]
_080122DE:
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl EntityE534Elem_SetAnim
	ldrh r0, [r4, #4]
	cmp r0, #0x5f
	bls _080122F8
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r1, [r4, #4]
_080122F8:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012308: .4byte 0x00000CCC
