	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _08012394
	movs r0, #0
	strb r0, [r6]
	adds r4, r6, #0
	adds r4, #0x10
	ldr r2, _080123CC @ =0x00000CCC
	add r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
	movs r1, #0x18
	ldrsh r0, [r6, r1]
	movs r2, #0x10
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x1c
	ldrsh r1, [r6, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #7]
	ldr r5, _080123D0 @ =0x0203B400
	ldr r3, _080123D4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _080123D8 @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #7]
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #7]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r6, #8]
_08012394:
	adds r2, r6, #0
	adds r2, #0x10
	movs r0, #0x18
	ldrsh r1, [r6, r0]
	movs r3, #0x10
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r1, r0
	ldr r0, _080123DC @ =0x00009C3F
	adds r7, r2, #0
	cmp r1, r0
	bgt _080123E0
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _080124D0
	.align 2, 0
_080123CC: .4byte 0x00000CCC
_080123D0: .4byte 0x0203B400
_080123D4: .4byte 0x030046B8
_080123D8: .4byte 0x000003FF
_080123DC: .4byte 0x00009C3F
_080123E0:
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _08012430
	adds r0, r4, #0
	adds r1, r3, #0
	bl ArcTan2_8
	strb r0, [r6, #7]
	ldr r5, _08012424 @ =0x0203B400
	ldr r2, _08012428 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0801242C @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r6, #7]
	subs r0, #0x10
	movs r3, #0x1f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r6, #7]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x20
	b _08012432
	.align 2, 0
_08012424: .4byte 0x0203B400
_08012428: .4byte 0x030046B8
_0801242C: .4byte 0x000003FF
_08012430:
	subs r0, #1
_08012432:
	strb r0, [r6, #8]
	mov r4, sp
	movs r3, #7
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _08012458 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0801245C
	asrs r1, r0, #0xc
	b _08012462
	.align 2, 0
_08012458: .4byte 0x085B0A08
_0801245C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08012462:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0801247E
	asrs r0, r0, #0xc
	b _08012484
_0801247E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08012484:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	ldr r2, _080124DC @ =0x00000CCC
	add r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl EntityE534Elem_SetAnim
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_080124D0:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080124DC: .4byte 0x00000CCC
