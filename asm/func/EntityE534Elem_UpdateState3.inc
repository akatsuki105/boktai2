	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	ldr r0, _080125BC @ =0x00000CC8
	add r0, sb
	ldr r0, [r0]
	cmp r0, #0
	beq _08012500
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
_08012500:
	ldrb r0, [r6]
	adds r7, r6, #0
	adds r7, #0x10
	movs r1, #0x18
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _08012566
	movs r0, #0
	strb r0, [r6]
	movs r2, #0x18
	ldrsh r0, [r6, r2]
	movs r3, #0x10
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
	ldr r5, _080125C0 @ =0x0203B400
	ldr r3, _080125C4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _080125C8 @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #6]
	subs r0, #0x10
	movs r1, #0x1f
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #6]
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
_08012566:
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _080125CC
	movs r1, #0x18
	ldrsh r0, [r6, r1]
	movs r2, #0x10
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	mov r3, r8
	movs r2, #4
	ldrsh r1, [r3, r2]
	movs r3, #4
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
	ldr r5, _080125C0 @ =0x0203B400
	ldr r2, _080125C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _080125C8 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldrb r0, [r6, #6]
	subs r0, #8
	movs r3, #0xf
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r6, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x10
	b _080125CE
	.align 2, 0
_080125BC: .4byte 0x00000CC8
_080125C0: .4byte 0x0203B400
_080125C4: .4byte 0x030046B8
_080125C8: .4byte 0x000003FF
_080125CC:
	subs r0, #1
_080125CE:
	strb r0, [r6, #8]
	movs r0, #0x18
	ldrsh r2, [r6, r0]
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	subs r2, r2, r0
	mov r3, r8
	movs r1, #4
	ldrsh r0, [r3, r1]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08012608 @ =0x00000FFF
	cmp r1, r0
	bgt _0801260C
	movs r0, #4
	movs r1, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _0801268A
	.align 2, 0
_08012608: .4byte 0x00000FFF
_0801260C:
	mov r4, sp
	movs r3, #6
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _08012630 @ =0x085B0A08
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
	blt _08012634
	asrs r1, r0, #0xc
	b _0801263A
	.align 2, 0
_08012630: .4byte 0x085B0A08
_08012634:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801263A:
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
	blt _08012656
	asrs r0, r0, #0xc
	b _0801265C
_08012656:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801265C:
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
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl EntityE534Elem_SetAnim
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_0801268A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
