	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	bl Time_GetSpanOfTime
	adds r2, r0, #0
	ldr r1, _080AD768 @ =0x00000C0B
	add r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	beq _080AD6D0
	strb r2, [r1]
	ldrb r1, [r1]
	mov r0, r8
	bl FUN_080ad3e8
_080AD6D0:
	ldr r0, _080AD76C @ =0x00001426
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AD6DC
	b _080AD914
_080AD6DC:
	ldr r1, _080AD770 @ =0x00001428
	add r1, r8
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080AD774 @ =0x00001424
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080AD784
	ldr r0, _080AD778 @ =0x0000022D
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x88
	lsls r1, r1, #2
	add r1, r8
	adds r1, r1, r0
	mov r5, r8
	adds r5, #0x20
	ldr r4, [r1]
	movs r6, #0xf
_080AD70E:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080AD77C @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _080AD70E
	ldr r0, _080AD76C @ =0x00001426
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	bne _080AD73C
	b _080AD952
_080AD73C:
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD780 @ =0x000002BE
	add r2, r8
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080AD778 @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r2, r2, r3
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	b _080AD952
	.align 2, 0
_080AD768: .4byte 0x00000C0B
_080AD76C: .4byte 0x00001426
_080AD770: .4byte 0x00001428
_080AD774: .4byte 0x00001424
_080AD778: .4byte 0x0000022D
_080AD77C: .4byte 0x04000008
_080AD780: .4byte 0x000002BE
_080AD784:
	ldrh r1, [r1]
	movs r0, #0x40
	subs r0, r0, r1
	mov sl, r0
	mov sb, r1
	movs r0, #0x8b
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x88
	lsls r1, r1, #2
	add r1, r8
	adds r0, r1, r0
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _080AD90C @ =0x0000022D
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r7, [r1]
	movs r0, #0
	mov r5, r8
	adds r5, #0x20
	str r5, [sp, #0x14]
_080AD7B8:
	movs r1, #0
	str r1, [sp]
	lsls r2, r0, #5
	str r2, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0xc]
_080AD7C4:
	mov r5, ip
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r0, #0x1f
	ands r6, r0
	lsrs r3, r3, #0x1a
	ands r3, r0
	ldrh r1, [r7]
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	movs r5, #0x1f
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sl
	muls r5, r2, r5
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #6
	mov r2, sl
	muls r2, r6, r2
	mov r0, sb
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	mov r0, sl
	muls r0, r3, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #6
	ldr r3, [sp]
	lsls r1, r3, #1
	ldr r3, [sp, #0x10]
	adds r1, r1, r3
	ldr r3, [sp, #0x14]
	adds r1, r3, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r5, #2
	add ip, r5
	adds r7, #2
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #0xf
	ble _080AD7C4
	ldr r0, [sp, #0xc]
	cmp r0, #0xf
	ble _080AD7B8
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	bne _080AD84E
	b _080AD952
_080AD84E:
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD910 @ =0x03003584
	movs r1, #0x8b
	lsls r1, r1, #2
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r2, [r2]
	adds r1, r2, r1
	str r1, [sp, #4]
	ldr r1, _080AD90C @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	mov ip, r2
	movs r7, #0xa7
	lsls r7, r7, #2
	add r7, r8
	movs r5, #0xf
	str r5, [sp, #8]
_080AD88A:
	ldr r0, [sp, #4]
	ldrh r3, [r0]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r1, #0x1f
	ands r6, r1
	lsrs r3, r3, #0x1a
	ands r3, r1
	mov r5, ip
	ldrh r1, [r5]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	movs r5, #0x1f
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sl
	muls r5, r2, r5
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #6
	mov r2, sl
	muls r2, r6, r2
	mov r0, sb
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	mov r0, sl
	muls r0, r3, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r7]
	ldr r5, [sp, #4]
	adds r5, #2
	str r5, [sp, #4]
	movs r0, #2
	add ip, r0
	adds r7, #2
	ldr r1, [sp, #8]
	subs r1, #1
	str r1, [sp, #8]
	cmp r1, #0
	bge _080AD88A
	movs r1, #0xa3
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0xa7
	lsls r0, r0, #2
	add r0, r8
	str r0, [r1]
	b _080AD952
	.align 2, 0
_080AD90C: .4byte 0x0000022D
_080AD910: .4byte 0x03003584
_080AD914:
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	beq _080AD952
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD964 @ =0x000002BE
	add r2, r8
	ldrh r3, [r2]
	cmp r0, r3
	beq _080AD952
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080AD968 @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r2, r2, r5
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
_080AD952:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD964: .4byte 0x000002BE
_080AD968: .4byte 0x0000022D
