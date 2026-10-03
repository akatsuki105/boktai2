	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	str r1, [sp]
	movs r0, #0
	mov r8, r0
	movs r7, #0xff
	ldr r1, _080B03F0 @ =0x085B0A08
	mov sl, r1
	movs r2, #1
	mov sb, r2
_080B03B6:
	movs r0, #0x68
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x68
	adds r0, r0, r6
	mov ip, r0
	mov r4, ip
	ldr r2, _080B03F0 @ =0x085B0A08
	adds r0, #0x64
	ldrh r1, [r0]
	adds r0, r7, #0
	ands r0, r1
	adds r0, #0x40
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	cmp r1, #0
	bge _080B03E2
	rsbs r1, r1, #0
_080B03E2:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080B03F4
	asrs r0, r0, #0xc
	b _080B03FA
	.align 2, 0
_080B03F0: .4byte 0x085B0A08
_080B03F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B03FA:
	adds r3, r0, #0
	adds r3, #0x3c
	mov r0, ip
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #0x40
	ands r1, r7
	lsls r1, r1, #1
	add r1, sl
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r3, r1
	adds r2, r0, #0
	cmp r1, #0
	blt _080B041C
	asrs r1, r1, #0xc
	b _080B0422
_080B041C:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080B0422:
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r1, _080B0450 @ =0x0000061A
	adds r0, r6, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	ldrh r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	cmp r0, #0
	blt _080B0454
	asrs r1, r0, #0xc
	b _080B045A
	.align 2, 0
_080B0450: .4byte 0x0000061A
_080B0454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080B045A:
	ldr r3, _080B047C @ =0x0000061C
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	movs r5, #0xcf
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r0, #2
	bne _080B0480
	mov r1, ip
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #4
	b _080B0488
	.align 2, 0
_080B047C: .4byte 0x0000061C
_080B0480:
	mov r1, ip
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #2
_080B0488:
	strh r0, [r1]
	mov r0, r8
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _080B049A
	ldrh r0, [r2]
	adds r0, #1
	b _080B049E
_080B049A:
	ldrh r0, [r2]
	adds r0, #0xff
_080B049E:
	ands r0, r7
	strh r0, [r2]
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _080B04DA
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080B04E6
_080B04DA:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080B04E6:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B050C
	mov r5, ip
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	str r0, [r5]
	b _080B051A
_080B050C:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080B051A:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080B0550 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _080B0588
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0554
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B0548
	ldrb r0, [r4, #5]
_080B0548:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0564
	.align 2, 0
_080B0550: .4byte 0x0000FFFF
_080B0554:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0564
	strh r1, [r4, #8]
_080B0564:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	ands r0, r7
	cmp r0, #0
	bne _080B0588
	mov r3, sb
	strb r3, [r4, #7]
_080B0588:
	mov r0, ip
	adds r0, #0x2c
	ldr r1, [sp]
	bl Video_SetAuxSpritePltt
	movs r5, #1
	add r8, r5
	mov r0, r8
	cmp r0, #7
	bgt _080B059E
	b _080B03B6
_080B059E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
