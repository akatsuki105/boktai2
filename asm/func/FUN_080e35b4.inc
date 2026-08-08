	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080E35D6
	b _080E37D2
_080E35D6:
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, _080E35EC @ =0x00000474
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E35F0
	movs r0, #1
	b _080E35F2
	.align 2, 0
_080E35EC: .4byte 0x00000474
_080E35F0:
	movs r0, #0
_080E35F2:
	cmp r0, #0
	beq _080E3624
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, _080E361C @ =0xFFFFBFFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r7, r2, #0
	ldr r0, _080E3620 @ =0x000001DF
	adds r0, r0, r5
	mov sb, r0
	b _080E373A
	.align 2, 0
_080E361C: .4byte 0xFFFFBFFF
_080E3620: .4byte 0x000001DF
_080E3624:
	ldr r1, _080E3648 @ =0x000001DF
	adds r0, r5, r1
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #0xd
	beq _080E3634
	cmp r1, #0x17
	bne _080E3650
_080E3634:
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, _080E364C @ =0xFFFFBFFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r7, r0, #0
	b _080E373A
	.align 2, 0
_080E3648: .4byte 0x000001DF
_080E364C: .4byte 0xFFFFBFFF
_080E3650:
	ldr r3, _080E3694 @ =0x00000553
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r0, #0x15
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080E3674
	movs r2, #0x80
	lsls r2, r2, #8
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _080E369C
_080E3674:
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r0, _080E3698 @ =0xFFFFBFFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r7, r2, #0
	b _080E373A
	.align 2, 0
_080E3694: .4byte 0x00000553
_080E3698: .4byte 0xFFFFBFFF
_080E369C:
	movs r2, #0x80
	lsls r2, r2, #7
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _080E36B4
	movs r0, #1
	b _080E36B6
_080E36B4:
	movs r0, #0
_080E36B6:
	cmp r0, #0
	bne _080E36C8
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _080E373A
_080E36C8:
	adds r2, r5, #0
	adds r2, #0xd8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldr r0, _080E374C @ =0xFFFFBFFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r1, #0x88
	lsls r1, r1, #1
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	bne _080E3706
	adds r0, r5, #0
	bl FUN_080e7078
	lsls r0, r0, #0x18
	adds r6, r5, #0
	adds r6, #8
	cmp r0, #0
	beq _080E3730
	movs r1, #6
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	bne _080E3730
_080E3706:
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	adds r6, r5, #0
	adds r6, #8
	cmp r0, #0
	bne _080E3730
	movs r2, #0x94
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080E3730:
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
_080E373A:
	mov r3, sb
	ldrb r0, [r3]
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _080E3750
	movs r0, #1
	b _080E3752
	.align 2, 0
_080E374C: .4byte 0xFFFFBFFF
_080E3750:
	movs r0, #0
_080E3752:
	adds r2, r0, #0
	cmp r2, #0
	bne _080E37D2
	movs r1, #0x80
	lsls r1, r1, #6
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E3778
	ldr r1, _080E3774 @ =0x0000048D
	adds r0, r5, r1
	strb r2, [r0]
	b _080E37AA
	.align 2, 0
_080E3774: .4byte 0x0000048D
_080E3778:
	ldr r3, _080E37E0 @ =0x000004BE
	adds r2, r5, r3
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080E379C
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080E3796
	movs r0, #0x20
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
_080E3796:
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_080E379C:
	ldr r0, _080E37E4 @ =0x0000048D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080E37AA
	subs r0, #1
	strb r0, [r1]
_080E37AA:
	movs r1, #0x97
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r0, [r6]
	cmp r0, #0
	beq _080E37D2
	bl FUN_080f8d20
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080E37D2
	movs r2, #0xbe
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	str r4, [r6]
_080E37D2:
	movs r0, #1
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E37E0: .4byte 0x000004BE
_080E37E4: .4byte 0x0000048D
