	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r4, r6, #0
	adds r4, #0x48
	bl FUN_08022ec0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08024610
	movs r2, #4
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_08024610:
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	ldr r0, _08024640 @ =0x0000027F
	adds r7, r6, #0
	adds r7, #0x98
	cmp r1, r0
	ble _08024626
	movs r1, #4
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_08024626:
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r4, r6, r3
	movs r1, #4
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08024644
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _0802465C
	.align 2, 0
_08024640: .4byte 0x0000027F
_08024644:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
_0802465C:
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r4, r5, r1
	movs r1, #8
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08024676
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _08024694
_08024676:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_08024694:
	ldr r0, _080246D8 @ =0x0000054A
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802473C
	ldr r2, _080246DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080246E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080246E4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r2, _080246E8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldrb r0, [r3]
	lsls r0, r0, #1
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080246EC
	asrs r3, r0, #0xc
	b _080246F2
	.align 2, 0
_080246D8: .4byte 0x0000054A
_080246DC: .4byte 0x030046B8
_080246E0: .4byte 0x000003FF
_080246E4: .4byte 0x0203B400
_080246E8: .4byte gSineTable
_080246EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080246F2:
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0802471C @ =0x0000054A
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _08024720
	asrs r2, r0, #0xc
	b _08024726
	.align 2, 0
_0802471C: .4byte 0x0000054A
_08024720:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08024726:
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r2, _08024758 @ =0x0000054A
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0802473C:
	movs r1, #0x10
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0802475C
	movs r3, #0x96
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	b _08024778
	.align 2, 0
_08024758: .4byte 0x0000054A
_0802475C:
	movs r3, #0x96
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08024788
_08024778:
	ldr r1, _08024784 @ =0x000004D4
	adds r0, r5, r1
	bl AuxShadow_Hide
	b _08024790
	.align 2, 0
_08024784: .4byte 0x000004D4
_08024788:
	ldr r2, _080247C8 @ =0x000004D4
	adds r0, r5, r2
	bl AuxShadow_Show
_08024790:
	movs r3, #0xa9
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080247D8
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	adds r2, r6, #0
	adds r2, #0xe0
	cmp r0, #0
	bne _080247DC
	ldr r0, _080247CC @ =0x00000292
	adds r1, r5, r0
	subs r0, #0x6f
	strh r0, [r1]
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080247D0 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _080247D4 @ =0x00004460
	adds r0, r0, r3
	str r0, [r1]
	b _080247DC
	.align 2, 0
_080247C8: .4byte 0x000004D4
_080247CC: .4byte 0x00000292
_080247D0: .4byte 0x03003584
_080247D4: .4byte 0x00004460
_080247D8:
	adds r2, r6, #0
	adds r2, #0xe0
_080247DC:
	ldr r0, _08024800 @ =0x00000564
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08024800: .4byte 0x00000564
