	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x24
	adds r0, r0, r6
	mov r8, r0
	adds r0, r6, #0
	bl DurathrorElem_EnterState
	cmp r0, #0
	beq _080386F8
	ldrb r0, [r6]
	cmp r0, #0
	beq _080386E8
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r2, r7, #0
	adds r2, #0x4d
	movs r1, #0
	mov sb, r1
	strb r0, [r2]
	ldrb r0, [r2]
	adds r0, #0x20
	movs r4, #0xff
	ands r0, r4
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	mov sl, r3
	mov r1, sl
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r4
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x44
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r2, #4
	ldrsh r3, [r3, r2]
	subs r1, r1, r3
	bl ArcTan2_8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r2, #0x20
	ands r2, r4
	asrs r2, r2, #6
	adds r2, #1
	mov r3, sl
	ands r2, r3
	subs r2, #1
	movs r0, #3
	ands r2, r0
	movs r4, #0x98
	lsls r4, r4, #2
	adds r1, r7, r4
	adds r2, #0x13
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r3, #1
	bl MainSprite_SetAnim
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r4, #1
	strb r4, [r0]
	adds r0, r7, #0
	bl FUN_0803781c
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080386DC @ =0x00000161
	adds r0, r7, r2
	mov r3, sb
	strb r3, [r0]
	ldr r0, _080386E0 @ =0x00000179
	bl PlaySound_0824078c
	ldr r0, _080386E4 @ =0x00000173
	bl PlaySound_0824078c
	b _080386F0
	.align 2, 0
_080386DC: .4byte 0x00000161
_080386E0: .4byte 0x00000179
_080386E4: .4byte 0x00000173
_080386E8:
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0803767c
_080386F0:
	movs r0, #0xbf
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080386F8:
	adds r0, r6, #0
	movs r1, #1
	bl DurathrorElem_SetFlags
	ldrb r0, [r6]
	cmp r0, #0
	bne _08038708
	b _08038852
_08038708:
	ldr r0, [r6, #0x10]
	cmp r0, #0x3f
	bls _08038720
	adds r0, r6, #0
	bl FUN_080375bc
	adds r1, r6, #0
	adds r1, #0x44
	adds r0, r7, #0
	bl FUN_08036858
	b _08038744
_08038720:
	cmp r0, #0x30
	bne _08038744
	adds r0, r7, #0
	bl FUN_0803784c
	ldr r4, _080387A0 @ =0x00000DF8
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _08038744
	movs r1, #0
	bl VM_ExecByID
	movs r5, #0xe0
	lsls r5, r5, #4
	adds r1, r7, r5
	movs r0, #0
	str r0, [r1]
_08038744:
	ldr r0, [r6, #0x10]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08038750
	b _08038852
_08038750:
	ldr r4, _080387A4 @ =0x0203B400
	ldr r3, _080387A8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080387AC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	mov ip, r5
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	add r4, sp, #0xc
	adds r1, #0x20
	mov r8, r1
	ldr r1, _080387B0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _080387B4
	asrs r2, r0, #0xc
	b _080387BA
	.align 2, 0
_080387A0: .4byte 0x00000DF8
_080387A4: .4byte 0x0203B400
_080387A8: .4byte 0x030046B8
_080387AC: .4byte 0x000003FF
_080387B0: .4byte gSineTable
_080387B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080387BA:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r5, r8
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _080387D6
	asrs r0, r0, #0xc
	b _080387DC
_080387D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080387DC:
	strh r0, [r4, #4]
	add r3, sp, #0xc
	adds r2, r6, #0
	adds r2, #0x44
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	adds r1, #0x80
	strh r1, [r3, #2]
	ldr r4, _0803886C @ =0x0203B400
	mov r3, ip
	ldr r0, [r3]
	adds r0, #1
	ldr r3, _08038870 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r3
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r2, [r2]
	movs r5, #0xf
	ands r2, r5
	adds r2, #0x10
	adds r0, #1
	ands r0, r3
	mov r3, ip
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	ands r3, r5
	adds r3, #4
	ldr r4, _08038874 @ =0x00000DE8
	adds r0, r7, r4
	ldr r0, [r0]
	movs r4, #0x3c
	str r4, [sp]
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrb r4, [r4]
	str r4, [sp, #4]
	add r4, sp, #0xc
	str r4, [sp, #8]
	bl FUN_08060220
_08038852:
	ldr r0, [r6, #0x10]
	cmp r0, #0x1d
	bhi _0803885C
	movs r0, #8
	strb r0, [r6, #8]
_0803885C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803886C: .4byte 0x0203B400
_08038870: .4byte 0x000003FF
_08038874: .4byte 0x00000DE8
