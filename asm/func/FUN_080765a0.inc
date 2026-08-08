	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _080765C0 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _080765C4
	cmp r0, #1
	bne _080765BC
	b _08076750
_080765BC:
	b _0807687C
	.align 2, 0
_080765C0: .4byte 0x0000037D
_080765C4:
	ldr r2, _080765F8 @ =0x0000037E
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807661E
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08076604
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080765FC @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _08076600 @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _08076614
	.align 2, 0
_080765F8: .4byte 0x0000037E
_080765FC: .4byte 0x000002E6
_08076600: .4byte 0x000002E7
_08076604:
	lsrs r0, r1, #0x19
	ldr r2, _08076674 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _08076678 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_08076614:
	ldr r0, _0807667C @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807661E:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _08076680
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08076688
	.align 2, 0
_08076674: .4byte 0x000002E6
_08076678: .4byte 0x000002E7
_0807667C: .4byte 0x0000037E
_08076680:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076688:
	str r0, [r5]
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
	beq _080766AC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080766B4
_080766AC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080766B4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080766EC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076724
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080766F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080766E4
	ldrb r0, [r4, #5]
_080766E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08076700
	.align 2, 0
_080766EC: .4byte 0x0000FFFF
_080766F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08076700
	strh r1, [r4, #8]
_08076700:
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
	bne _08076724
	movs r0, #1
	strb r0, [r4, #7]
_08076724:
	ldr r0, _08076734 @ =0x000003F6
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _08076738
	subs r0, #0x1e
	strh r0, [r1]
	b _0807687C
	.align 2, 0
_08076734: .4byte 0x000003F6
_08076738:
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0x17
	movs r2, #1
	bl FUN_08060b84
	b _0807687C
_08076750:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _080767A4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080767AC
_080767A4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080767AC:
	str r0, [r5]
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
	beq _080767D0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080767D8
_080767D0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080767D8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08076810 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076856
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0807681A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076814
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08076830
	.align 2, 0
_08076810: .4byte 0x0000FFFF
_08076814:
	subs r0, #1
	strh r0, [r4, #8]
	b _0807682E
_0807681A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0807682E
	strh r1, [r4, #8]
	movs r2, #1
	b _08076830
_0807682E:
	movs r2, #0
_08076830:
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
	bne _08076858
	movs r0, #1
	strb r0, [r4, #7]
	b _08076858
_08076856:
	movs r2, #0
_08076858:
	cmp r2, #0
	beq _0807687C
	adds r0, r7, #0
	bl FUN_080609dc
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _08076888 @ =FUN_08075df8
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080726b4
_0807687C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076888: .4byte FUN_08075df8
