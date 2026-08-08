	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _08067560 @ =0x0000037D
	adds r0, r7, r2
	ldrb r1, [r0]
	cmp r1, #1
	bne _0806754A
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	ands r1, r0
	cmp r1, #0
	beq _0806754A
	adds r0, r7, #0
	movs r1, #4
	movs r2, #2
	bl FUN_08060b84
_0806754A:
	ldr r1, _08067560 @ =0x0000037D
	adds r0, r7, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _08067610
	cmp r4, #1
	bgt _08067564
	cmp r4, #0
	beq _0806756E
	bl _08067DD4
	.align 2, 0
_08067560: .4byte 0x0000037D
_08067564:
	cmp r4, #2
	bne _0806756A
	b _08067A96
_0806756A:
	bl _08067DD4
_0806756E:
	movs r1, #4
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #2
	bl FUN_08066ee4
	mov r8, r0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, r8
	beq _080675E6
	movs r0, #0xd0
	bl PlaySound_082406e0
	ldr r0, _080675D0 @ =0x000003BD
	adds r2, r7, r0
	ldrb r0, [r2]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080675D8
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080675D4 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _080675E6
	.align 2, 0
_080675D0: .4byte 0x000003BD
_080675D4: .4byte 0x000002E6
_080675D8:
	lsrs r0, r1, #0x19
	ldr r2, _08067608 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _0806760C @ =0x000002E7
	adds r0, r7, r3
	strb r4, [r0]
_080675E6:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080675F8
	bl _08067DD4
_080675F8:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
	bl _08067DD4
	.align 2, 0
_08067608: .4byte 0x000002E6
_0806760C: .4byte 0x000002E7
_08067610:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r6, [r0, r3]
	adds r1, #1
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r4, r1, #7
	movs r0, #7
	ands r4, r0
	adds r5, r1, #1
	ands r5, r0
	adds r2, #0xc8
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #3
	bl FUN_08066ee4
	mov r8, r0
	cmp r6, r4
	beq _080676B8
	cmp r6, r5
	beq _080676B8
	adds r0, r7, #0
	bl FUN_080674dc
	cmp r0, #0
	bne _0806765C
	b _08067A50
_0806765C:
	adds r0, r7, #0
	adds r0, #0x2c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrb r1, [r1]
	bl FUN_08003f24
	cmp r0, #0
	bgt _08067672
	b _08067A50
_08067672:
	ldr r1, _0806769C @ =0x00000446
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r4, #0
	cmp r0, #0
	beq _0806768A
	ldr r2, _080676A0 @ =0x00000442
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _0806768A
	movs r4, #1
_0806768A:
	cmp r4, #0
	beq _080676A4
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	b _08067A50
	.align 2, 0
_0806769C: .4byte 0x00000446
_080676A0: .4byte 0x00000442
_080676A4:
	adds r0, r7, #0
	movs r1, #5
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	b _08067A50
_080676B8:
	ldr r1, _080676F8 @ =0x000003BD
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r0, r6, r1
	lsls r0, r0, #1
	adds r0, #8
	adds r1, r1, r0
	movs r0, #7
	ands r1, r0
	adds r6, r1, #1
	ands r6, r0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, _080676FC @ =0x085B0A08
	lsls r0, r6, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov ip, r2
	cmp r0, #0
	blt _08067700
	asrs r2, r0, #0xc
	b _08067706
	.align 2, 0
_080676F8: .4byte 0x000003BD
_080676FC: .4byte 0x085B0A08
_08067700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08067706:
	add r0, sp, #0xc
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067738 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r2, r6, #5
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov sb, r2
	cmp r0, #0
	blt _0806773C
	asrs r0, r0, #0xc
	b _08067742
	.align 2, 0
_08067738: .4byte 0xFFFF0000
_0806773C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067742:
	add r3, sp, #0xc
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067780 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0806777C
	cmp r1, #0
	blt _0806777C
	ldr r0, _08067784 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0806777C
	ldr r0, _08067788 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0806778C
_0806777C:
	movs r6, #0
	b _0806779A
	.align 2, 0
_08067780: .4byte 0xFFFF0000
_08067784: .4byte 0x030046A8
_08067788: .4byte 0x030046AC
_0806778C:
	ldr r0, _080677C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_0806779A:
	add r5, sp, #0xc
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080677C2
	cmp r1, #0
	blt _080677C2
	ldr r0, _080677CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080677C2
	ldr r0, _080677D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080677D4
_080677C2:
	movs r4, #0
	b _080677E2
	.align 2, 0
_080677C8: .4byte 0x030046A4
_080677CC: .4byte 0x030046A8
_080677D0: .4byte 0x030046AC
_080677D4:
	ldr r0, _080677F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080677E2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080677F8
	adds r0, #4
	b _08067804
	.align 2, 0
_080677F4: .4byte 0x030046A4
_080677F8:
	ldr r0, _08067818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08067804:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0806781C
	cmp r2, #2
	beq _08067820
	b _08067824
	.align 2, 0
_08067818: .4byte 0x030046A4
_0806781C:
	ldrb r0, [r5, #4]
	b _08067822
_08067820:
	ldrb r0, [r5]
_08067822:
	subs r1, r1, r0
_08067824:
	adds r5, r1, #0
	movs r0, #0x2e
	ldrsh r1, [r7, r0]
	adds r0, r1, #0
	subs r0, #0x80
	cmp r5, r0
	bgt _08067834
	b _08067A50
_08067834:
	adds r0, r1, #0
	adds r0, #0x80
	cmp r5, r0
	blt _0806783E
	b _08067A50
_0806783E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0806784E
	adds r0, #4
	b _0806785A
_0806784E:
	ldr r0, _08067894 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0806785A:
	ldrh r0, [r0, #2]
	bl FUN_08065b44
	cmp r0, #0
	beq _08067866
	b _08067A50
_08067866:
	ldr r2, _08067898 @ =0x085B0A08
	ldr r1, _0806789C @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov ip, r2
	cmp r0, #0
	blt _080678A0
	asrs r1, r0, #0xc
	b _080678A6
	.align 2, 0
_08067894: .4byte 0x030046A4
_08067898: .4byte 0x085B0A08
_0806789C: .4byte 0x000003BD
_080678A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080678A6:
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, r0, r1
	add r1, sp, #0xc
	strh r0, [r1]
	ldr r1, _080678D0 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080678D4
	asrs r2, r0, #0xc
	b _080678DA
	.align 2, 0
_080678D0: .4byte 0x000003BD
_080678D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080678DA:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	strh r1, [r0, #4]
	adds r6, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08067906
	cmp r1, #0
	blt _08067906
	ldr r0, _0806790C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08067906
	ldr r0, _08067910 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08067914
_08067906:
	movs r4, #0
	b _08067922
	.align 2, 0
_0806790C: .4byte 0x030046A8
_08067910: .4byte 0x030046AC
_08067914:
	ldr r0, _08067934 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08067922:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08067938
	adds r0, #4
	b _08067944
	.align 2, 0
_08067934: .4byte 0x030046A4
_08067938:
	ldr r0, _08067958 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08067944:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0806795C
	cmp r2, #2
	beq _08067960
	b _08067964
	.align 2, 0
_08067958: .4byte 0x030046A4
_0806795C:
	ldrb r0, [r6, #4]
	b _08067962
_08067960:
	ldrb r0, [r6]
_08067962:
	subs r1, r1, r0
_08067964:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	blt _08067A50
	add r1, sp, #0xc
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08067994
	cmp r1, #0
	blt _08067994
	ldr r0, _08067998 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08067994
	ldr r0, _0806799C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080679A0
_08067994:
	movs r4, #0
	b _080679AE
	.align 2, 0
_08067998: .4byte 0x030046A8
_0806799C: .4byte 0x030046AC
_080679A0:
	ldr r0, _080679C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080679AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080679C4
	adds r0, #4
	b _080679D0
	.align 2, 0
_080679C0: .4byte 0x030046A4
_080679C4:
	ldr r0, _08067A1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080679D0:
	ldrh r0, [r0, #2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08067A50
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	bl FUN_08066ee4
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080679FC
	movs r3, #3
	cmp r0, #2
	bne _080679FC
	movs r3, #6
_080679FC:
	ldr r2, _08067A20 @ =0x085B0A08
	mov r0, sb
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _08067A24
	asrs r0, r0, #0xc
	b _08067A2A
	.align 2, 0
_08067A1C: .4byte 0x030046A4
_08067A20: .4byte 0x085B0A08
_08067A24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067A2A:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	movs r0, #0xff
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08067A46
	asrs r0, r0, #0xc
	b _08067A4C
_08067A46:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067A4C:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
_08067A50:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r4, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r1, #4
	bl FUN_08066ee4
	cmp r4, r0
	beq _08067A76
	b _08067DD4
_08067A76:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _08067A82
	b _08067DD4
_08067A82:
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	beq _08067A8E
	b _08067DD4
_08067A8E:
	movs r0, #0xdb
	bl PlaySound_082406e0
	b _08067DD4
_08067A96:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r1, #5
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08067ABC
	b _08067DD4
_08067ABC:
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldr r3, _08067B20 @ =0x000003BD
	adds r2, r7, r3
	ldrb r2, [r2]
	adds r6, r1, #0
	adds r5, r0, #0
	cmp r2, #1
	bne _08067B2C
	add r4, sp, #0x14
	ldrh r0, [r4]
	adds r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067B24 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _08067B28 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	subs r0, #0x4c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
	add r2, sp, #0x1c
	ldrh r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #4]
	subs r0, #0x80
	b _08067BC2
	.align 2, 0
_08067B20: .4byte 0x000003BD
_08067B24: .4byte 0xFFFF0000
_08067B28: .4byte 0x0000FFFF
_08067B2C:
	cmp r2, #3
	bne _08067B78
	add r4, sp, #0x14
	ldrh r0, [r4]
	subs r0, #0x34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067B70 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08067B74 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r1, [r4, #4]
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r4, #4]
	add r2, sp, #0x1c
	ldrh r0, [r2]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #4]
	adds r0, #0x40
	b _08067BC2
	.align 2, 0
_08067B70: .4byte 0xFFFF0000
_08067B74: .4byte 0x0000FFFF
_08067B78:
	cmp r2, #5
	bne _08067BDC
	add r4, sp, #0x14
	ldrh r0, [r4]
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067BD4 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _08067BD8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
	add r2, sp, #0x1c
	ldrh r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r0, [r2, #4]
	adds r0, #0x80
_08067BC2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
	mov r8, r2
	b _08067C38
	.align 2, 0
_08067BD4: .4byte 0xFFFF0000
_08067BD8: .4byte 0x0000FFFF
_08067BDC:
	add r4, sp, #0x14
	add r0, sp, #0x1c
	mov r8, r0
	cmp r2, #7
	bne _08067C38
	ldrh r0, [r4]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08067C68 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x44
	lsls r1, r1, #0x10
	ldr r0, _08067C6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x1c]
	mov r2, r8
	ldrh r0, [r2, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_08067C38:
	str r5, [sp, #0x24]
	str r6, [sp, #0x28]
	ldr r2, _08067C70 @ =0x085B0A08
	ldr r3, _08067C74 @ =0x000003BD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov ip, r2
	cmp r0, #0
	blt _08067C78
	asrs r0, r0, #0xc
	b _08067C7E
	.align 2, 0
_08067C68: .4byte 0xFFFF0000
_08067C6C: .4byte 0x0000FFFF
_08067C70: .4byte 0x085B0A08
_08067C74: .4byte 0x000003BD
_08067C78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067C7E:
	add r3, sp, #0x24
	ldrh r1, [r3]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067CB4 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r1, _08067CB8 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _08067CBC
	asrs r0, r0, #0xc
	b _08067CC2
	.align 2, 0
_08067CB4: .4byte 0xFFFF0000
_08067CB8: .4byte 0x000003BD
_08067CBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067CC2:
	ldrh r1, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08067D00 @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	add r0, sp, #0x24
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08067CFA
	cmp r1, #0
	blt _08067CFA
	ldr r0, _08067D04 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08067CFA
	ldr r0, _08067D08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08067D0C
_08067CFA:
	movs r5, #0
	b _08067D1A
	.align 2, 0
_08067D00: .4byte 0xFFFF0000
_08067D04: .4byte 0x030046A8
_08067D08: .4byte 0x030046AC
_08067D0C:
	ldr r0, _08067D2C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_08067D1A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08067D30
	adds r0, #4
	b _08067D3C
	.align 2, 0
_08067D2C: .4byte 0x030046A4
_08067D30:
	ldr r0, _08067D60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08067D3C:
	ldrh r0, [r0, #2]
	movs r2, #0x80
	lsls r2, r2, #1
	ands r0, r2
	cmp r0, #0
	beq _08067D64
	adds r1, r7, #0
	adds r1, #0x2c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #0xeb
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08066e9c
	b _08067D78
	.align 2, 0
_08067D60: .4byte 0x030046A4
_08067D64:
	adds r1, r7, #0
	adds r1, #0x2c
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #0xec
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_08066e9c
_08067D78:
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, r8
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08067DA0
	cmp r1, #0
	blt _08067DA0
	ldr r0, _08067DA4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08067DA0
	ldr r0, _08067DA8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08067DAC
_08067DA0:
	movs r0, #0
	b _08067DBA
	.align 2, 0
_08067DA4: .4byte 0x030046A8
_08067DA8: .4byte 0x030046AC
_08067DAC:
	ldr r0, _08067DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08067DBA:
	bl FUN_08020358
	cmp r0, #0
	beq _08067DCA
	movs r0, #0xc2
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08067DCA:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
_08067DD4:
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067DE4: .4byte 0x030046A4
