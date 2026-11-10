	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _081191E0 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081191E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081191E6
	.align 2, 0
_081191E0: .4byte 0x0000046D
_081191E4:
	movs r0, #0
_081191E6:
	cmp r0, #0
	beq _081191F2
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081191F2:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r5, #0x13
	bgt _0811921E
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _0811921E
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _0811921E
	cmp r2, #1
	beq _0811921E
	strh r3, [r4, #0xe]
_0811921E:
	ldr r2, _08119310 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811922C
	bl _08119A0C
_0811922C:
	ldr r3, _08119314 @ =0x0000046B
	adds r0, r7, r3
	movs r4, #0
	movs r5, #1
	strb r5, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r0, [r1]
	ldr r2, _08119318 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r5, [r2]
	ldr r3, _0811931C @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r4, [r3]
	ldr r5, _08119320 @ =0x00000484
	adds r5, r5, r7
	mov ip, r5
	str r4, [r5]
	ldr r0, _08119324 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r1, #1
	strb r1, [r0]
	ldr r1, _08119328 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r2, _0811932C @ =0x0000046D
	adds r3, r7, r2
	movs r5, #1
	strb r5, [r3]
	subs r2, #2
	adds r2, r2, r7
	mov sb, r2
	strb r4, [r2]
	ldr r5, _08119330 @ =0x00000553
	adds r5, r5, r7
	mov r8, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r6, r7, r0
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	strh r4, [r5]
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	str r3, [sp, #0x2c]
	ldr r0, [sp, #8]
	str r0, [sp, #0x18]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x1c]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x20]
	mov r0, ip
	str r0, [sp, #0x34]
	mov r3, sl
	str r3, [sp, #0x28]
	mov r4, sb
	str r4, [sp, #0x24]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r6, [sp, #0x54]
	str r5, [sp, #0x50]
	mov sl, r2
	cmp r1, #0
	bne _081192CE
	b _0811987C
_081192CE:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
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
	blt _0811930A
	cmp r1, #0
	blt _0811930A
	ldr r0, _08119334 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811930A
	ldr r0, _08119338 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811933C
_0811930A:
	movs r4, #0
	b _0811934A
	.align 2, 0
_08119310: .4byte 0x0000046E
_08119314: .4byte 0x0000046B
_08119318: .4byte 0x00000469
_0811931C: .4byte 0x0000046A
_08119320: .4byte 0x00000484
_08119324: .4byte 0x0000046C
_08119328: .4byte Enemy_WaitPendingState
_0811932C: .4byte 0x0000046D
_08119330: .4byte 0x00000553
_08119334: .4byte 0x030046A8
_08119338: .4byte 0x030046AC
_0811933C:
	ldr r0, _0811935C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811934A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08119360
	adds r0, #4
	b _0811936C
	.align 2, 0
_0811935C: .4byte 0x030046A4
_08119360:
	ldr r0, _08119380 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811936C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119384
	cmp r2, #2
	beq _08119388
	b _0811938C
	.align 2, 0
_08119380: .4byte 0x030046A4
_08119384:
	ldrb r0, [r5, #4]
	b _0811938A
_08119388:
	ldrb r0, [r5]
_0811938A:
	subs r1, r1, r0
_0811938C:
	strh r1, [r5, #2]
	ldr r0, _081193A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081193A4
	movs r0, #1
	b _081193A6
	.align 2, 0
_081193A0: .4byte 0x030047A4
_081193A4:
	movs r0, #0
_081193A6:
	cmp r0, #0
	beq _081193E4
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081193C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081193C2
	adds r2, r0, #0
_081193C2:
	cmp r2, #0
	bge _081193D0
_081193C6:
	ldr r3, _081193CC @ =0x000005C4
	adds r0, r7, r3
	b _08119824
	.align 2, 0
_081193CC: .4byte 0x000005C4
_081193D0:
	ldr r1, _081193E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811942C
	.align 2, 0
_081193E0: .4byte 0x03002BE0
_081193E4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08119410
	cmp r1, #0
	blt _08119410
	ldr r0, _08119414 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119410
	ldr r0, _08119418 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811941C
_08119410:
	movs r5, #0
	b _0811942A
	.align 2, 0
_08119414: .4byte 0x030046A8
_08119418: .4byte 0x030046AC
_0811941C:
	ldr r0, _08119464 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811942A:
	movs r2, #0
_0811942C:
	ldr r1, _08119468 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811944C
	ldr r1, _0811946C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811944C
	b _08119764
_0811944C:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08119470
	movs r0, #0
	b _0811983A
	.align 2, 0
_08119464: .4byte 0x030046A4
_08119468: .4byte 0x00000256
_0811946C: .4byte 0x03002BE0
_08119470:
	ldr r3, _081194CC @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081194D0
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
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r0, [sp, #0x54]
	str r1, [r0]
	ldr r1, [sp, #0x50]
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
	b _0811961E
	.align 2, 0
_081194CC: .4byte 0x00000222
_081194D0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x24]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	str r1, [r4]
	ldr r1, [sp, #0x50]
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
	blt _08119534
	cmp r1, #0
	blt _08119534
	ldr r0, _08119538 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08119534
	ldr r0, _0811953C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08119540
_08119534:
	movs r4, #0
	b _0811954E
	.align 2, 0
_08119538: .4byte 0x030046A8
_0811953C: .4byte 0x030046AC
_08119540:
	ldr r0, _08119560 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811954E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08119564
	adds r0, #4
	b _08119570
	.align 2, 0
_08119560: .4byte 0x030046A4
_08119564:
	ldr r0, _08119584 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08119570:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119588
	cmp r2, #2
	beq _0811958C
	b _08119590
	.align 2, 0
_08119584: .4byte 0x030046A4
_08119588:
	ldrb r0, [r5, #4]
	b _0811958E
_0811958C:
	ldrb r0, [r5]
_0811958E:
	subs r1, r1, r0
_08119590:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081195B8
	cmp r1, #0
	blt _081195B8
	ldr r0, _081195BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081195B8
	ldr r0, _081195C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081195C4
_081195B8:
	movs r4, #0
	b _081195D2
	.align 2, 0
_081195BC: .4byte 0x030046A8
_081195C0: .4byte 0x030046AC
_081195C4:
	ldr r0, _081195E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081195D2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081195E8
	adds r0, #4
	b _081195F4
	.align 2, 0
_081195E4: .4byte 0x030046A4
_081195E8:
	ldr r0, _08119608 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081195F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811960C
	cmp r3, #2
	beq _08119610
	b _08119614
	.align 2, 0
_08119608: .4byte 0x030046A4
_0811960C:
	ldrb r0, [r5, #4]
	b _08119612
_08119610:
	ldrb r0, [r5]
_08119612:
	subs r2, r2, r0
_08119614:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811961E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _08119728
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08119648
	movs r0, #1
	b _0811964A
_08119648:
	movs r0, #0
_0811964A:
	ldr r3, _08119738 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x30]
	cmp r0, #0
	bne _08119728
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _0811973C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08119740 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _08119744 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r4, _08119748 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x48]
	ldr r5, _0811974C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r0, _08119750 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x58]
	ldr r1, _08119754 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r6, _08119758 @ =0x0203B400
	ldr r1, _0811975C @ =0x030046B8
	ldr r5, _08119760 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811969A:
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
	bne _081196B8
	adds r3, #1
	cmp r3, #3
	ble _0811969A
	mov r0, r8
_081196B8:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x18]
	ldrb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r1, [sp, #0x1c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r4, [sp, #0x20]
	ldrb r0, [r4]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x58]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x2c]
	strb r1, [r5]
	ldr r4, [sp, #0x24]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r0, [sp, #0x54]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x50]
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
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
_08119728:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r2, [sp, #0x30]
	strh r0, [r2]
	movs r0, #0
	b _0811983A
	.align 2, 0
_08119738: .4byte 0x00000482
_0811973C: .4byte 0x0000054F
_08119740: .4byte 0x0000054C
_08119744: .4byte 0x0000054D
_08119748: .4byte 0x0000054E
_0811974C: .4byte 0x00000541
_08119750: .4byte 0x000005BC
_08119754: .4byte 0x00000542
_08119758: .4byte 0x0203B400
_0811975C: .4byte 0x030046B8
_08119760: .4byte 0x000003FF
_08119764:
	mov sb, sp
	ldr r6, _081197A0 @ =0x030046A4
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
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081197A4
	adds r0, #4
	b _081197AE
	.align 2, 0
_081197A0: .4byte 0x030046A4
_081197A4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081197AE:
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
	ldr r5, _081197E8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081197F0
	ldr r0, _081197EC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811981A
	.align 2, 0
_081197E8: .4byte 0x000004A4
_081197EC: .4byte 0xFFFFFDFF
_081197F0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08119810
	cmp r0, #2
	beq _0811980C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811980C:
	movs r0, #1
	b _0811981C
_08119810:
	ldr r0, _08119830 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811981A:
	movs r0, #0
_0811981C:
	cmp r0, #0
	bne _08119838
	ldr r4, _08119834 @ =0x000005C4
	adds r0, r7, r4
_08119824:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811983A
	.align 2, 0
_08119830: .4byte 0xFFFFFDFF
_08119834: .4byte 0x000005C4
_08119838:
	movs r0, #1
_0811983A:
	cmp r0, #0
	bne _08119840
	b _08119A0C
_08119840:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r5, #0x64
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08119874 @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08119878 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	b _08119A0C
	.align 2, 0
_08119874: .4byte 0x00000551
_08119878: .4byte 0x00000552
_0811987C:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x28
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
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081198FC @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08119900 @ =0x00000482
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	subs r3, #0xa9
	adds r0, r7, r3
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081198F8
	cmp r1, #0
	blt _081198F8
	ldr r0, _08119904 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081198F8
	ldr r0, _08119908 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811990C
_081198F8:
	movs r4, #0
	b _0811991A
	.align 2, 0
_081198FC: .4byte 0x00000551
_08119900: .4byte 0x00000482
_08119904: .4byte 0x030046A8
_08119908: .4byte 0x030046AC
_0811990C:
	ldr r0, _0811992C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811991A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08119930
	adds r0, #4
	b _0811993C
	.align 2, 0
_0811992C: .4byte 0x030046A4
_08119930:
	ldr r0, _08119950 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811993C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08119954
	cmp r2, #2
	beq _08119958
	b _0811995C
	.align 2, 0
_08119950: .4byte 0x030046A4
_08119954:
	ldrb r0, [r5, #4]
	b _0811995A
_08119958:
	ldrb r0, [r5]
_0811995A:
	subs r1, r1, r0
_0811995C:
	strh r1, [r5, #2]
	ldr r4, _0811998C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08119994
	ldr r0, _08119990 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081199BE
	.align 2, 0
_0811998C: .4byte 0x000004A4
_08119990: .4byte 0xFFFFFDFF
_08119994:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081199B4
	cmp r0, #2
	beq _081199B0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081199B0:
	movs r0, #1
	b _081199C0
_081199B4:
	ldr r0, _081199F8 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081199BE:
	movs r0, #0
_081199C0:
	adds r3, r0, #0
	cmp r3, #0
	bne _08119A00
	ldr r0, _081199FC @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r4, [sp, #0x2c]
	strb r2, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x4c]
	strb r3, [r1]
	ldr r4, [sp, #0x54]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x50]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	ldr r5, [sp, #0x1c]
	strb r1, [r5]
	ldr r0, [sp, #0x20]
	strb r1, [r0]
	ldr r1, [sp, #0x34]
	str r3, [r1]
	ldr r3, [sp, #0x28]
	strb r2, [r3]
	b _08119A0C
	.align 2, 0
_081199F8: .4byte 0xFFFFFDFF
_081199FC: .4byte Enemy_ClearStateBegun
_08119A00:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_08119A0C:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
