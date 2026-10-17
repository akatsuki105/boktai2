	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r0, [r5, #0x3c]
	cmp r0, #0
	ble _080D7576
	adds r0, r5, #0
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _080D757A
_080D7576:
	movs r0, #0
	strh r0, [r7, #0x3e]
_080D757A:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r0, #0
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D75AC
	ldr r1, _080D75A4 @ =0x000003D6
	adds r0, r4, r1
	mov r2, r8
	strh r2, [r0]
	ldr r0, _080D75A8 @ =0x00000446
	adds r6, r4, r0
	b _080D761C
	.align 2, 0
_080D75A4: .4byte 0x000003D6
_080D75A8: .4byte 0x00000446
_080D75AC:
	ldr r2, _080D7664 @ =0x000003D6
	adds r1, r4, r2
	movs r0, #0xe6
	strh r0, [r1]
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D75DA
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _080D75DA
	subs r2, #0x56
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	adds r6, #0x29
	adds r0, r4, r6
	strb r1, [r0]
_080D75DA:
	ldr r1, _080D7668 @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r6, r0, #0
	cmp r1, #0
	beq _080D75F4
	ldr r1, _080D766C @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _080D75F4
	movs r2, #1
_080D75F4:
	cmp r2, #0
	beq _080D7612
	ldr r2, _080D766C @ =0x00000442
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xe8
	ldr r0, [r2]
	ldr r1, _080D7670 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
_080D7612:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_080cc4f4
_080D761C:
	movs r1, #0x10
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7630
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r4, #0x18]
	bl FUN_081df698
_080D7630:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _080D7644
	ldr r2, _080D766C @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D7644
	movs r1, #1
_080D7644:
	cmp r1, #0
	beq _080D7674
	movs r0, #0
	strh r0, [r7, #0x3e]
	movs r6, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080D765C
	b _080D784E
_080D765C:
	adds r0, r4, #0
	bl FUN_080cdda8
	b _080D784E
	.align 2, 0
_080D7664: .4byte 0x000003D6
_080D7668: .4byte 0x00000446
_080D766C: .4byte 0x00000442
_080D7670: .4byte 0xFFFFFBFF
_080D7674:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _080D7688
	ldr r6, _080D76DC @ =0x00000442
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D7688
	movs r1, #1
_080D7688:
	cmp r1, #0
	bne _080D76A4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D76A4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D76A8
_080D76A4:
	movs r6, #1
	add r8, r6
_080D76A8:
	movs r0, #4
	ldr r1, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D76EC
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D773C
	ldr r1, _080D76E0 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D76D2
	ldr r2, _080D76E4 @ =0x000003D6
	adds r1, r4, r2
	ldr r0, _080D76E8 @ =0x00000191
	strh r0, [r1]
_080D76D2:
	adds r0, r4, #0
	movs r1, #1
	bl Player_StartFormEffect
	b _080D773C
	.align 2, 0
_080D76DC: .4byte 0x00000442
_080D76E0: .4byte 0x000003D2
_080D76E4: .4byte 0x000003D6
_080D76E8: .4byte 0x00000191
_080D76EC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D772C
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D773C
	ldr r6, _080D7720 @ =0x000003D2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D7714
	ldr r0, _080D7724 @ =0x000003D6
	adds r1, r4, r0
	ldr r0, _080D7728 @ =0x00000133
	strh r0, [r1]
_080D7714:
	adds r0, r4, #0
	movs r1, #2
	bl Player_StartFormEffect
	b _080D773C
	.align 2, 0
_080D7720: .4byte 0x000003D2
_080D7724: .4byte 0x000003D6
_080D7728: .4byte 0x00000133
_080D772C:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _080D773C
	adds r0, r4, #0
	bl FUN_080cdda8
_080D773C:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7754
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r4, #0
	movs r1, #1
	bl Player_ApplyBadCondition
_080D7754:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D776C
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r4, #0
	movs r1, #2
	bl Player_ApplyBadCondition
_080D776C:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D77FA
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D77A8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080D77AC
	asrs r0, r0, #0xc
	b _080D77B2
	.align 2, 0
_080D77A8: .4byte gSineTable
_080D77AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D77B2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080D77D4
	asrs r0, r0, #0xc
	b _080D77DA
_080D77D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D77DA:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D786C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
_080D77FA:
	ldrh r6, [r7, #0x3e]
	mov r0, r8
	lsls r6, r0
	movs r0, #0
	strh r0, [r7, #0x3e]
	ldr r0, [r5, #0x34]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080D7844
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080D7844
	movs r1, #0x20
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D782E
	adds r0, r5, #0
	bl FUN_080d7444
	adds r1, r6, #0
	bl FUN_080d7474
_080D782E:
	movs r1, #2
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7844
	adds r0, r5, #0
	bl FUN_080d7444
	adds r1, r6, #0
	bl FUN_080d74e8
_080D7844:
	ldr r2, _080D7870 @ =0x00000376
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, r0, r6
	strh r0, [r1]
_080D784E:
	ldrh r1, [r5, #0xa]
	ldr r2, _080D7874 @ =0x0000045A
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080D7878 @ =0x0000045C
	adds r1, r4, r0
	ldr r0, [r5, #0x34]
	str r0, [r1]
	adds r0, r6, #0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D786C: .4byte 0xFFFF0000
_080D7870: .4byte 0x00000376
_080D7874: .4byte 0x0000045A
_080D7878: .4byte 0x0000045C
