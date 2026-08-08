	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	movs r5, #0x80
	lsls r5, r5, #5
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #8]
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080E7402
	movs r1, #0x97
	lsls r1, r1, #3
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldr r2, [sp, #8]
	ldrh r0, [r2]
	bics r0, r5
	movs r1, #0
	strh r0, [r2]
	str r1, [r4]
_080E7402:
	ldr r3, _080E74DC @ =0x00000482
	adds r0, r7, r3
	movs r4, #1
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _080E74E0 @ =FUN_080e6794
	movs r0, #0xe
	ldr r5, _080E74E4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r4, [r5]
	ldr r2, _080E74E8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x10]
	movs r3, #0
	strb r3, [r2]
	ldr r5, _080E74EC @ =0x00000553
	adds r5, r5, r7
	mov ip, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sl, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0
	strh r2, [r1]
	movs r0, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r8, r3
	strb r0, [r3]
	ldr r5, _080E74F0 @ =0x00000469
	adds r6, r7, r5
	strb r4, [r6]
	ldr r0, _080E74F4 @ =0x0000046A
	adds r5, r7, r0
	movs r1, #0
	strb r1, [r5]
	ldr r2, _080E74F8 @ =0x00000484
	adds r3, r7, r2
	movs r0, #0
	str r0, [r3]
	ldr r1, _080E74FC @ =0x0000046C
	adds r2, r7, r1
	strb r4, [r2]
	movs r0, #0x80
	ldr r4, [sp, #8]
	ldrh r1, [r4]
	ands r1, r0
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x2c]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x24]
	mov r0, ip
	str r0, [sp, #0x50]
	mov r4, sl
	str r4, [sp, #0x54]
	mov r0, sb
	str r0, [sp, #0x38]
	mov r4, r8
	str r4, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r5, [sp, #0x20]
	str r3, [sp, #0x34]
	str r2, [sp, #0x28]
	cmp r1, #0
	bne _080E749C
	b _080E7A58
_080E749C:
	movs r5, #0x95
	lsls r5, r5, #3
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _080E74D8
	cmp r1, #0
	blt _080E74D8
	ldr r0, _080E7500 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080E74D8
	ldr r0, _080E7504 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E7508
_080E74D8:
	movs r4, #0
	b _080E7516
	.align 2, 0
_080E74DC: .4byte 0x00000482
_080E74E0: .4byte 0x080e6794+1
_080E74E4: .4byte 0x0000046D
_080E74E8: .4byte 0x0000046B
_080E74EC: .4byte 0x00000553
_080E74F0: .4byte 0x00000469
_080E74F4: .4byte 0x0000046A
_080E74F8: .4byte 0x00000484
_080E74FC: .4byte 0x0000046C
_080E7500: .4byte 0x030046A8
_080E7504: .4byte 0x030046AC
_080E7508:
	ldr r0, _080E7528 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080E7516:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E752C
	adds r0, #4
	b _080E7538
	.align 2, 0
_080E7528: .4byte 0x030046A4
_080E752C:
	ldr r0, _080E754C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E7538:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E7550
	cmp r2, #2
	beq _080E7554
	b _080E7558
	.align 2, 0
_080E754C: .4byte 0x030046A4
_080E7550:
	ldrb r0, [r5, #4]
	b _080E7556
_080E7554:
	ldrb r0, [r5]
_080E7556:
	subs r1, r1, r0
_080E7558:
	strh r1, [r5, #2]
	ldr r0, _080E756C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080E7570
	movs r0, #1
	b _080E7572
	.align 2, 0
_080E756C: .4byte 0x030047A4
_080E7570:
	movs r0, #0
_080E7572:
	cmp r0, #0
	beq _080E75B0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080E7592
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _080E758E
	adds r2, r0, #0
_080E758E:
	cmp r2, #0
	bge _080E759C
_080E7592:
	ldr r2, _080E7598 @ =0x000005C4
	adds r0, r7, r2
	b _080E79F0
	.align 2, 0
_080E7598: .4byte 0x000005C4
_080E759C:
	ldr r1, _080E75AC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _080E75F8
	.align 2, 0
_080E75AC: .4byte 0x03002BE0
_080E75B0:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080E75DC
	cmp r1, #0
	blt _080E75DC
	ldr r0, _080E75E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E75DC
	ldr r0, _080E75E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E75E8
_080E75DC:
	movs r5, #0
	b _080E75F6
	.align 2, 0
_080E75E0: .4byte 0x030046A8
_080E75E4: .4byte 0x030046AC
_080E75E8:
	ldr r0, _080E7634 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080E75F6:
	movs r2, #0
_080E75F8:
	ldr r4, _080E7638 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _080E7618
	ldr r1, _080E763C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080E7618
	b _080E7934
_080E7618:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	beq _080E7640
	movs r0, #0
	b _080E7A06
	.align 2, 0
_080E7634: .4byte 0x030046A4
_080E7638: .4byte 0x00000256
_080E763C: .4byte 0x03002BE0
_080E7640:
	ldr r0, _080E769C @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _080E76A0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x2c]
	strb r2, [r3]
	ldr r3, [sp, #0x24]
	strb r5, [r3]
	ldr r3, [sp, #0x50]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x38]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x18]
	strb r5, [r3]
	ldr r1, [sp, #0x1c]
	strb r5, [r1]
	ldr r3, [sp, #0x20]
	strb r0, [r3]
	ldr r5, [sp, #0x34]
	str r4, [r5]
	ldr r0, [sp, #0x28]
	strb r2, [r0]
	b _080E77EE
	.align 2, 0
_080E769C: .4byte 0x00000222
_080E76A0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x38]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x18]
	strb r5, [r2]
	ldr r4, [sp, #0x1c]
	strb r5, [r4]
	ldr r5, [sp, #0x20]
	strb r1, [r5]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080E7704
	cmp r1, #0
	blt _080E7704
	ldr r0, _080E7708 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E7704
	ldr r0, _080E770C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E7710
_080E7704:
	movs r4, #0
	b _080E771E
	.align 2, 0
_080E7708: .4byte 0x030046A8
_080E770C: .4byte 0x030046AC
_080E7710:
	ldr r0, _080E7730 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080E771E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7734
	adds r0, #4
	b _080E7740
	.align 2, 0
_080E7730: .4byte 0x030046A4
_080E7734:
	ldr r0, _080E7754 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E7740:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E7758
	cmp r2, #2
	beq _080E775C
	b _080E7760
	.align 2, 0
_080E7754: .4byte 0x030046A4
_080E7758:
	ldrb r0, [r5, #4]
	b _080E775E
_080E775C:
	ldrb r0, [r5]
_080E775E:
	subs r1, r1, r0
_080E7760:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080E7788
	cmp r1, #0
	blt _080E7788
	ldr r0, _080E778C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E7788
	ldr r0, _080E7790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E7794
_080E7788:
	movs r4, #0
	b _080E77A2
	.align 2, 0
_080E778C: .4byte 0x030046A8
_080E7790: .4byte 0x030046AC
_080E7794:
	ldr r0, _080E77B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080E77A2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E77B8
	adds r0, #4
	b _080E77C4
	.align 2, 0
_080E77B4: .4byte 0x030046A4
_080E77B8:
	ldr r0, _080E77D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E77C4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080E77DC
	cmp r3, #2
	beq _080E77E0
	b _080E77E4
	.align 2, 0
_080E77D8: .4byte 0x030046A4
_080E77DC:
	ldrb r0, [r5, #4]
	b _080E77E2
_080E77E0:
	ldrb r0, [r5]
_080E77E2:
	subs r2, r2, r0
_080E77E4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_080E77EE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _080E78F8
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080E7818
	movs r0, #1
	b _080E781A
_080E7818:
	movs r0, #0
_080E781A:
	ldr r3, _080E7908 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _080E78F8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _080E790C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _080E7910 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _080E7914 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r4, _080E7918 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _080E791C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x3c]
	ldr r0, _080E7920 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _080E7924 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r6, _080E7928 @ =0x0203B400
	ldr r1, _080E792C @ =0x030046B8
	ldr r5, _080E7930 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_080E786A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _080E7888
	adds r3, #1
	cmp r3, #3
	ble _080E786A
	mov r0, sb
_080E7888:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x50]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x3c]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x38]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x20]
	strb r2, [r4]
	ldr r5, [sp, #0x34]
	str r3, [r5]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x40]
	strb r0, [r1]
_080E78F8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	movs r0, #0
	b _080E7A06
	.align 2, 0
_080E7908: .4byte 0x00000482
_080E790C: .4byte 0x0000054F
_080E7910: .4byte 0x0000054C
_080E7914: .4byte 0x0000054D
_080E7918: .4byte 0x0000054E
_080E791C: .4byte 0x00000541
_080E7920: .4byte 0x000005BC
_080E7924: .4byte 0x00000542
_080E7928: .4byte 0x0203B400
_080E792C: .4byte 0x030046B8
_080E7930: .4byte 0x000003FF
_080E7934:
	mov sb, sp
	ldr r6, _080E7970 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E7974
	adds r0, #4
	b _080E797E
	.align 2, 0
_080E7970: .4byte 0x030046A4
_080E7974:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E797E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _080E79B4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _080E79B8
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _080E79DE
	.align 2, 0
_080E79B4: .4byte 0x000004A4
_080E79B8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080E79D8
	cmp r0, #2
	beq _080E79D4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080E79D4:
	movs r0, #1
	b _080E79E8
_080E79D8:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_080E79DE:
	ldr r1, _080E79FC @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080E79E8:
	cmp r0, #0
	bne _080E7A04
	ldr r3, _080E7A00 @ =0x000005C4
	adds r0, r7, r3
_080E79F0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _080E7A06
	.align 2, 0
_080E79FC: .4byte 0xFFFFFDFF
_080E7A00: .4byte 0x000005C4
_080E7A04:
	movs r0, #1
_080E7A06:
	cmp r0, #0
	bne _080E7A0C
	b _080E7B50
_080E7A0C:
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080E7A4C @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _080E7A50 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	ldr r4, _080E7A54 @ =0x00000222
	adds r2, r7, r4
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _080E7B50
	.align 2, 0
_080E7A4C: .4byte 0x00000551
_080E7A50: .4byte 0x00000552
_080E7A54: .4byte 0x00000222
_080E7A58:
	movs r5, #0x95
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, [r1]
	movs r2, #1
	strh r2, [r0, #6]
	ldr r3, _080E7A8C @ =0x000004A4
	adds r0, r7, r3
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	ldr r6, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080E7A94
	ldr r0, _080E7A90 @ =0xFFFFFDFF
	ldr r4, [sp, #8]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _080E7ABE
	.align 2, 0
_080E7A8C: .4byte 0x000004A4
_080E7A90: .4byte 0xFFFFFDFF
_080E7A94:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080E7AB4
	cmp r0, #2
	beq _080E7AB0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080E7AB0:
	movs r0, #1
	b _080E7AC0
_080E7AB4:
	ldr r0, _080E7AD4 @ =0xFFFFFDFF
	ldr r5, [sp, #8]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_080E7ABE:
	movs r0, #0
_080E7AC0:
	cmp r0, #0
	bne _080E7ADC
	ldr r1, _080E7AD8 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080E7B50
	.align 2, 0
_080E7AD4: .4byte 0xFFFFFDFF
_080E7AD8: .4byte 0x000005C4
_080E7ADC:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r3, #0
	strb r3, [r0]
	ldr r2, _080E7B60 @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E7B50
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r1, _080E7B64 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _080E7B68 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r4, #0xa2
	adds r0, r7, r4
	strh r3, [r0]
	adds r5, #0x82
	adds r0, r7, r5
	strh r3, [r0]
_080E7B50:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E7B60: .4byte 0x00000551
_080E7B64: .4byte 0xFEFFFFFF
_080E7B68: .4byte 0xFFFFFDFF
