	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r4, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r7, #0x60]
	str r1, [r7, #0x64]
	adds r0, r7, #0
	adds r0, #0xce
	strb r4, [r0]
	movs r0, #0xcc
	adds r0, r0, r7
	mov sl, r0
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xcd
	str r1, [sp, #4]
	strb r3, [r1]
	adds r0, r7, #0
	adds r0, #0xdc
	mov r2, sp
	ldrh r2, [r2, #0x38]
	strh r2, [r0]
	movs r0, #0xd4
	adds r0, r0, r7
	mov r8, r0
	strh r6, [r0]
	ldrh r0, [r0]
	movs r1, #6
	bl Div
	adds r1, r7, #0
	adds r1, #0xd8
	strh r0, [r1]
	movs r1, #0x18
	adds r1, r1, r7
	mov sb, r1
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080B35F8 @ =0x0000C038
	adds r0, r4, #0
	bl Video_GetAuxSprite
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, _080B35FC @ =0x0000922E
	ldr r1, _080B3600 @ =0x00003449
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xc8
	str r0, [r6]
	adds r0, r7, #0
	ldr r1, [sp, #0x34]
	bl Generator_InitHitbox
	adds r0, r7, #0
	ldr r1, [sp, #0x28]
	bl Generator_SetState
	adds r0, r7, #0
	adds r0, #0xcf
	ldrb r5, [r0]
	cmp r5, #2
	beq _080B3634
	cmp r5, #2
	bgt _080B3604
	cmp r5, #0
	beq _080B3612
	movs r0, #0xee
	adds r0, r0, r7
	mov r8, r0
	b _080B3854
	.align 2, 0
_080B35F8: .4byte 0x0000C038
_080B35FC: .4byte 0x0000922E
_080B3600: .4byte 0x00003449
_080B3604:
	cmp r5, #4
	bne _080B360A
	b _080B3746
_080B360A:
	movs r1, #0xee
	adds r1, r1, r7
	mov r8, r1
	b _080B3854
_080B3612:
	adds r0, r7, #0
	adds r0, #0xd2
	strh r5, [r0]
	adds r2, r7, #0
	adds r2, #0xee
	ldr r0, _080B3630 @ =0x000001C3
	strh r0, [r2]
	movs r0, #3
	strb r0, [r7, #0x1f]
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	mov r8, r2
	b _080B3854
	.align 2, 0
_080B3630: .4byte 0x000001C3
_080B3634:
	adds r1, r7, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xee
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080B3690 @ =0x000001C3
	strh r0, [r2]
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r1, [r6]
	mov r0, sl
	ldrb r3, [r0]
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	mov ip, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B3694
	ldr r0, [r7, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B369C
	.align 2, 0
_080B3690: .4byte 0x000001C3
_080B3694:
	ldr r0, [r7, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B369C:
	str r0, [r7, #0x18]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B36C2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080B36CE
_080B36C2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_080B36CE:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3704 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B373C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3708
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B36FE
	ldrb r0, [r4, #5]
_080B36FE:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3718
	.align 2, 0
_080B3704: .4byte 0x0000FFFF
_080B3708:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3718
	strh r1, [r4, #8]
_080B3718:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B373C
	movs r0, #1
	strb r0, [r4, #7]
_080B373C:
	adds r0, r7, #0
	adds r0, #0x68
	bl Hitbox_Register
	b _080B3854
_080B3746:
	mov r1, r8
	ldrh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xd2
	strh r0, [r1]
	movs r2, #0xee
	adds r2, r2, r7
	mov r8, r2
	movs r0, #0xe2
	lsls r0, r0, #1
	strh r0, [r2]
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r1, [r6]
	mov r0, sl
	ldrb r3, [r0]
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	mov ip, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B37A2
	ldr r0, [r7, #0x18]
	orrs r0, r5
	b _080B37AA
_080B37A2:
	ldr r0, [r7, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B37AA:
	str r0, [r7, #0x18]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B37D0
	mov r2, ip
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080B37DC
_080B37D0:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_080B37DC:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3814 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B384C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3818
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B380C
	ldrb r0, [r4, #5]
_080B380C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3828
	.align 2, 0
_080B3814: .4byte 0x0000FFFF
_080B3818:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3828
	strh r1, [r4, #8]
_080B3828:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B384C
	movs r0, #1
	strb r0, [r4, #7]
_080B384C:
	adds r0, r7, #0
	adds r0, #0x68
	bl Hitbox_Register
_080B3854:
	adds r0, r7, #0
	adds r0, #0x44
	mov r2, r8
	ldrh r1, [r2]
	bl Video_SetAuxSpritePltt
	adds r0, r7, #0
	adds r0, #0xda
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	adds r0, #0x12
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0x34
	str r2, [sp]
	movs r3, #0
	bl FUN_0824742c
	adds r0, r7, #0
	adds r0, #0xea
	strb r4, [r0]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
