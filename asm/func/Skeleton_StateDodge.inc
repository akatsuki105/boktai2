	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	adds r7, r0, #0
	ldr r0, _08109240 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08109244
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08109246
	.align 2, 0
_08109240: .4byte 0x0000046D
_08109244:
	movs r0, #0
_08109246:
	cmp r0, #0
	bne _0810924C
	b _08109962
_0810924C:
	ldr r2, _0810938C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08109390 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08109394 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r6, r0, #0
	adds r6, #0xa
	ldr r2, _08109398 @ =0x000001DD
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r0, r7, #0
	bl Skeleton_FindWalkableDir
	adds r5, r0, #0
	cmp r5, #0
	blt _0810927C
	b _081098DC
_0810927C:
	adds r0, r7, #0
	movs r1, #0xf
	bl Enemy_PlayAnim
	ldr r3, _0810939C @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _0810929A
	movs r0, #4
	ldr r4, _081093A0 @ =0x00000222
	adds r2, r7, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810929A:
	movs r0, #0x80
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrh r1, [r4]
	movs r2, #0
	orrs r0, r1
	strh r0, [r4]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r3, _081093A4 @ =0x0000024E
	adds r0, r7, r3
	strh r1, [r0]
	movs r0, #0xc
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r2, [r5]
	ldr r6, _081093A8 @ =0x00000469
	adds r6, r7, r6
	str r6, [sp, #0x14]
	strb r2, [r6]
	ldr r1, _081093AC @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x18]
	strb r0, [r1]
	ldr r3, _081093B0 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	movs r5, #0
	str r5, [r3]
	ldr r6, _081093B4 @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x20]
	movs r1, #1
	strb r1, [r6]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x1a
	ldr r6, _081093B8 @ =0x0000046D
	adds r5, r7, r6
	strb r1, [r5]
	ldr r1, _081093BC @ =0x0000046B
	adds r1, r1, r7
	mov sl, r1
	strb r2, [r1]
	ldr r2, _081093C0 @ =0x00000553
	adds r2, r2, r7
	mov sb, r2
	strb r0, [r2]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r3, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x80]
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r6, [r3]
	str r6, [sp, #0x24]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r5, [sp, #0x70]
	str r4, [sp, #0x58]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x5c]
	ldr r4, [sp, #0x14]
	str r4, [sp, #0x60]
	ldr r5, [sp, #0x18]
	str r5, [sp, #0x64]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x6c]
	mov r4, sl
	str r4, [sp, #0x68]
	mov r5, sb
	str r5, [sp, #0x4c]
	mov r6, r8
	str r6, [sp, #0x50]
	ldr r0, [sp, #0x80]
	str r0, [sp, #0x7c]
	adds r6, r3, #0
	mov r8, r2
	mov r2, ip
	cmp r2, #0
	blt _08109388
	cmp r1, #0
	blt _08109388
	ldr r0, _081093C4 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08109388
	ldr r0, _081093C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081093CC
_08109388:
	movs r4, #0
	b _081093DC
	.align 2, 0
_0810938C: .4byte 0x030046B8
_08109390: .4byte 0x000003FF
_08109394: .4byte 0x0203B400
_08109398: .4byte 0x000001DD
_0810939C: .4byte 0x000001DF
_081093A0: .4byte 0x00000222
_081093A4: .4byte 0x0000024E
_081093A8: .4byte 0x00000469
_081093AC: .4byte 0x0000046A
_081093B0: .4byte 0x00000484
_081093B4: .4byte 0x0000046C
_081093B8: .4byte 0x0000046D
_081093BC: .4byte 0x0000046B
_081093C0: .4byte 0x00000553
_081093C4: .4byte 0x030046A8
_081093C8: .4byte 0x030046AC
_081093CC:
	ldr r0, _081093EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, ip
	adds r4, r0, r3
_081093DC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081093F0
	adds r0, #4
	b _081093FC
	.align 2, 0
_081093EC: .4byte 0x030046A4
_081093F0:
	ldr r0, _08109410 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081093FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109414
	cmp r2, #2
	beq _0810941A
	b _08109420
	.align 2, 0
_08109410: .4byte 0x030046A4
_08109414:
	ldr r4, [sp, #0x24]
	ldrb r0, [r4, #4]
	b _0810941E
_0810941A:
	ldr r5, [sp, #0x24]
	ldrb r0, [r5]
_0810941E:
	subs r1, r1, r0
_08109420:
	ldr r0, [sp, #0x24]
	strh r1, [r0, #2]
	ldr r0, _08109438 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810943C
	movs r0, #1
	b _0810943E
	.align 2, 0
_08109438: .4byte 0x030047A4
_0810943C:
	movs r0, #0
_0810943E:
	cmp r0, #0
	beq _08109484
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810945E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810945A
	adds r2, r0, #0
_0810945A:
	cmp r2, #0
	bge _08109470
_0810945E:
	ldr r2, _0810946C @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081098BC
	.align 2, 0
_0810946C: .4byte 0x000005C4
_08109470:
	ldr r1, _08109480 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081094CC
	.align 2, 0
_08109480: .4byte 0x03002BE0
_08109484:
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
	blt _081094B0
	cmp r1, #0
	blt _081094B0
	ldr r0, _081094B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081094B0
	ldr r0, _081094B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081094BC
_081094B0:
	movs r5, #0
	b _081094CA
	.align 2, 0
_081094B4: .4byte 0x030046A8
_081094B8: .4byte 0x030046AC
_081094BC:
	ldr r0, _0810955C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081094CA:
	movs r2, #0
_081094CC:
	ldr r4, _08109560 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081094EC
	ldr r1, _08109564 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081094EC
	b _081097F4
_081094EC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08109500
	b _081098BC
_08109500:
	ldr r0, _08109568 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0810956C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x70]
	strb r2, [r3]
	ldr r6, [sp, #0x68]
	strb r5, [r6]
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r6, [sp, #0x50]
	str r1, [r6]
	ldr r0, [sp, #0x7c]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x5c]
	strb r5, [r1]
	ldr r3, [sp, #0x60]
	strb r5, [r3]
	ldr r5, [sp, #0x64]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	str r4, [r6]
	ldr r0, [sp, #0x6c]
	strb r2, [r0]
	b _081096BA
	.align 2, 0
_0810955C: .4byte 0x030046A4
_08109560: .4byte 0x00000256
_08109564: .4byte 0x03002BE0
_08109568: .4byte 0x00000222
_0810956C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x70]
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	str r1, [r4]
	ldr r1, [sp, #0x7c]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x5c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r5, [r4]
	ldr r5, [sp, #0x64]
	strb r1, [r5]
	ldr r1, [sp, #0x78]
	str r3, [r1]
	ldr r2, [sp, #0x6c]
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
	blt _081095D0
	cmp r1, #0
	blt _081095D0
	ldr r0, _081095D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081095D0
	ldr r0, _081095D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081095DC
_081095D0:
	movs r4, #0
	b _081095EA
	.align 2, 0
_081095D4: .4byte 0x030046A8
_081095D8: .4byte 0x030046AC
_081095DC:
	ldr r0, _081095FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081095EA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08109600
	adds r0, #4
	b _0810960C
	.align 2, 0
_081095FC: .4byte 0x030046A4
_08109600:
	ldr r0, _08109620 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810960C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109624
	cmp r2, #2
	beq _08109628
	b _0810962C
	.align 2, 0
_08109620: .4byte 0x030046A4
_08109624:
	ldrb r0, [r5, #4]
	b _0810962A
_08109628:
	ldrb r0, [r5]
_0810962A:
	subs r1, r1, r0
_0810962C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08109654
	cmp r1, #0
	blt _08109654
	ldr r0, _08109658 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109654
	ldr r0, _0810965C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109660
_08109654:
	movs r4, #0
	b _0810966E
	.align 2, 0
_08109658: .4byte 0x030046A8
_0810965C: .4byte 0x030046AC
_08109660:
	ldr r0, _08109680 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810966E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08109684
	adds r0, #4
	b _08109690
	.align 2, 0
_08109680: .4byte 0x030046A4
_08109684:
	ldr r0, _081096A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109690:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081096A8
	cmp r3, #2
	beq _081096AC
	b _081096B0
	.align 2, 0
_081096A4: .4byte 0x030046A4
_081096A8:
	ldrb r0, [r5, #4]
	b _081096AE
_081096AC:
	ldrb r0, [r5]
_081096AE:
	subs r2, r2, r0
_081096B0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081096BA:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x28]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _081096E4 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x74]
	cmp r0, #0
	bne _081097C2
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081096E8
	movs r0, #1
	b _081096EA
	.align 2, 0
_081096E4: .4byte 0x00000482
_081096E8:
	movs r0, #0
_081096EA:
	ldr r3, _081097D0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x74]
	cmp r0, #0
	bne _081097C2
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081097D4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	adds r4, #0xc
	adds r4, r4, r7
	mov sb, r4
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081097D8 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r4, _081097DC @ =0x00000541
	adds r4, r4, r7
	mov ip, r4
	ldr r0, _081097E0 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _081097E4 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r1, _081097E8 @ =0x030046B8
	str r5, [sp, #0x84]
_08109730:
	ldr r0, [r1]
	adds r0, #1
	ldr r4, _081097EC @ =0x000003FF
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	ldr r4, _081097F0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	lsls r0, r0, #6
	ldr r4, [sp, #0x84]
	cmp r0, r4
	bne _08109756
	adds r3, #1
	cmp r3, #3
	ble _08109730
	adds r0, r5, #0
_08109756:
	movs r3, #0
	strb r0, [r2]
	ldr r5, [sp, #0x50]
	ldr r0, [r5]
	str r0, [r6]
	ldr r6, [sp, #0x4c]
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x5c]
	ldrb r0, [r2]
	mov r4, sb
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	add r4, sp, #0x28
	ldrb r5, [r4]
	mov r4, ip
	strb r5, [r4]
	ldr r5, [sp, #0x54]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x70]
	strb r1, [r6]
	ldr r4, [sp, #0x68]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x7c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x5c]
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r1, [r5]
	ldr r6, [sp, #0x64]
	strb r2, [r6]
	ldr r0, [sp, #0x78]
	str r3, [r0]
	ldr r2, [sp, #0x6c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x44]
	strb r0, [r3]
_081097C2:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x74]
	strh r0, [r4]
	b _081098BC
	.align 2, 0
_081097D0: .4byte 0x00000482
_081097D4: .4byte 0x0000054F
_081097D8: .4byte 0x0000054E
_081097DC: .4byte 0x00000541
_081097E0: .4byte 0x000005BC
_081097E4: .4byte 0x00000542
_081097E8: .4byte 0x030046B8
_081097EC: .4byte 0x000003FF
_081097F0: .4byte 0x0203B400
_081097F4:
	mov sb, sp
	ldr r6, _08109830 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
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
	beq _08109834
	adds r0, #4
	b _0810983E
	.align 2, 0
_08109830: .4byte 0x030046A4
_08109834:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810983E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08109878 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08109880
	ldr r0, _0810987C @ =0xFFFFFDFF
	ldr r2, [sp, #0x58]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081098AA
	.align 2, 0
_08109878: .4byte 0x000004A4
_0810987C: .4byte 0xFFFFFDFF
_08109880:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081098A0
	cmp r0, #2
	beq _0810989C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810989C:
	movs r0, #1
	b _081098AC
_081098A0:
	ldr r0, _081098D4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x58]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081098AA:
	movs r0, #0
_081098AC:
	cmp r0, #0
	bne _081098BC
	ldr r4, _081098D8 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_081098BC:
	movs r5, #0xe6
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0x80
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r0, r6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _08109F70
	.align 2, 0
_081098D4: .4byte 0xFFFFFDFF
_081098D8: .4byte 0x000005C4
_081098DC:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r7, r0
	lsls r3, r5, #6
	ldr r2, _08109900 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08109904
	asrs r1, r0, #0xc
	b _0810990A
	.align 2, 0
_08109900: .4byte gSineTable
_08109904:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810990A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08109926
	asrs r0, r0, #0xc
	b _0810992C
_08109926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810992C:
	strh r0, [r4, #4]
	adds r0, r5, #2
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	strb r0, [r7, #5]
	ldr r2, _08109A4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08109A50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08109A54 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xc
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r7, r4
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0xe
	bl Enemy_PlayAnim
_08109962:
	movs r1, #0x10
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08109974
	b _08109F70
_08109974:
	adds r0, r7, #0
	movs r1, #0xf
	bl Enemy_PlayAnim
	movs r0, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x2c]
	movs r1, #0
	strb r1, [r6]
	ldr r2, _08109A58 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x30]
	strb r1, [r2]
	ldr r3, _08109A5C @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x34]
	strb r0, [r3]
	ldr r4, _08109A60 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x38]
	str r1, [r4]
	ldr r5, _08109A64 @ =0x0000046C
	adds r5, r5, r7
	mov sl, r5
	movs r2, #1
	strb r2, [r5]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r0, #0x1a
	ldr r5, _08109A68 @ =0x0000046D
	adds r4, r7, r5
	strb r2, [r4]
	ldr r6, _08109A6C @ =0x0000046B
	adds r6, r6, r7
	mov sb, r6
	strb r1, [r6]
	ldr r2, _08109A70 @ =0x00000553
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x80]
	str r3, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	strh r1, [r5]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r1, [r3]
	str r1, [sp, #0x3c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x3c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0x70]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x5c]
	ldr r4, [sp, #0x30]
	str r4, [sp, #0x60]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x64]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x78]
	mov r4, sl
	str r4, [sp, #0x6c]
	mov r6, sb
	str r6, [sp, #0x68]
	mov r0, r8
	str r0, [sp, #0x4c]
	ldr r4, [sp, #0x80]
	str r4, [sp, #0x50]
	str r5, [sp, #0x7c]
	adds r6, r3, #0
	mov r8, r2
	mov r5, ip
	cmp r5, #0
	blt _08109A46
	cmp r1, #0
	blt _08109A46
	ldr r0, _08109A74 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08109A46
	ldr r0, _08109A78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109A7C
_08109A46:
	movs r4, #0
	b _08109A8C
	.align 2, 0
_08109A4C: .4byte 0x030046B8
_08109A50: .4byte 0x000003FF
_08109A54: .4byte 0x0203B400
_08109A58: .4byte 0x00000469
_08109A5C: .4byte 0x0000046A
_08109A60: .4byte 0x00000484
_08109A64: .4byte 0x0000046C
_08109A68: .4byte 0x0000046D
_08109A6C: .4byte 0x0000046B
_08109A70: .4byte 0x00000553
_08109A74: .4byte 0x030046A8
_08109A78: .4byte 0x030046AC
_08109A7C:
	ldr r0, _08109A9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08109A8C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08109AA0
	adds r0, #4
	b _08109AAC
	.align 2, 0
_08109A9C: .4byte 0x030046A4
_08109AA0:
	ldr r0, _08109AC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109AAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109AC4
	cmp r2, #2
	beq _08109ACA
	b _08109AD0
	.align 2, 0
_08109AC0: .4byte 0x030046A4
_08109AC4:
	ldr r2, [sp, #0x3c]
	ldrb r0, [r2, #4]
	b _08109ACE
_08109ACA:
	ldr r3, [sp, #0x3c]
	ldrb r0, [r3]
_08109ACE:
	subs r1, r1, r0
_08109AD0:
	ldr r4, [sp, #0x3c]
	strh r1, [r4, #2]
	ldr r0, _08109AE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08109AEC
	movs r0, #1
	b _08109AEE
	.align 2, 0
_08109AE8: .4byte 0x030047A4
_08109AEC:
	movs r0, #0
_08109AEE:
	cmp r0, #0
	beq _08109B34
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08109B0E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08109B0A
	adds r2, r0, #0
_08109B0A:
	cmp r2, #0
	bge _08109B20
_08109B0E:
	ldr r6, _08109B1C @ =0x000005C4
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08109F70
	.align 2, 0
_08109B1C: .4byte 0x000005C4
_08109B20:
	ldr r1, _08109B30 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08109B7C
	.align 2, 0
_08109B30: .4byte 0x03002BE0
_08109B34:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08109B60
	cmp r1, #0
	blt _08109B60
	ldr r0, _08109B64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109B60
	ldr r0, _08109B68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109B6C
_08109B60:
	movs r5, #0
	b _08109B7A
	.align 2, 0
_08109B64: .4byte 0x030046A8
_08109B68: .4byte 0x030046AC
_08109B6C:
	ldr r0, _08109C10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08109B7A:
	movs r2, #0
_08109B7C:
	ldr r3, _08109C14 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08109B9C
	ldr r1, _08109C18 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08109B9C
	b _08109EA8
_08109B9C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	str r2, [sp, #0x58]
	cmp r4, #0
	beq _08109BB6
	b _08109F70
_08109BB6:
	ldr r5, _08109C1C @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _08109C20
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x70]
	strb r2, [r3]
	ldr r6, [sp, #0x68]
	strb r5, [r6]
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r6, [sp, #0x50]
	str r1, [r6]
	ldr r0, [sp, #0x7c]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x5c]
	strb r5, [r1]
	ldr r3, [sp, #0x60]
	strb r5, [r3]
	ldr r5, [sp, #0x64]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	str r4, [r6]
	ldr r0, [sp, #0x6c]
	strb r2, [r0]
	b _08109D6E
	.align 2, 0
_08109C10: .4byte 0x030046A4
_08109C14: .4byte 0x00000256
_08109C18: .4byte 0x03002BE0
_08109C1C: .4byte 0x00000222
_08109C20:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x70]
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	str r1, [r4]
	ldr r1, [sp, #0x7c]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x5c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r5, [r4]
	ldr r5, [sp, #0x64]
	strb r1, [r5]
	ldr r1, [sp, #0x78]
	str r3, [r1]
	ldr r2, [sp, #0x6c]
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
	blt _08109C84
	cmp r1, #0
	blt _08109C84
	ldr r0, _08109C88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109C84
	ldr r0, _08109C8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109C90
_08109C84:
	movs r4, #0
	b _08109C9E
	.align 2, 0
_08109C88: .4byte 0x030046A8
_08109C8C: .4byte 0x030046AC
_08109C90:
	ldr r0, _08109CB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08109C9E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08109CB4
	adds r0, #4
	b _08109CC0
	.align 2, 0
_08109CB0: .4byte 0x030046A4
_08109CB4:
	ldr r0, _08109CD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109CC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109CD8
	cmp r2, #2
	beq _08109CDC
	b _08109CE0
	.align 2, 0
_08109CD4: .4byte 0x030046A4
_08109CD8:
	ldrb r0, [r5, #4]
	b _08109CDE
_08109CDC:
	ldrb r0, [r5]
_08109CDE:
	subs r1, r1, r0
_08109CE0:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08109D08
	cmp r1, #0
	blt _08109D08
	ldr r0, _08109D0C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109D08
	ldr r0, _08109D10 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109D14
_08109D08:
	movs r4, #0
	b _08109D22
	.align 2, 0
_08109D0C: .4byte 0x030046A8
_08109D10: .4byte 0x030046AC
_08109D14:
	ldr r0, _08109D34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08109D22:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08109D38
	adds r0, #4
	b _08109D44
	.align 2, 0
_08109D34: .4byte 0x030046A4
_08109D38:
	ldr r0, _08109D58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109D44:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08109D5C
	cmp r3, #2
	beq _08109D60
	b _08109D64
	.align 2, 0
_08109D58: .4byte 0x030046A4
_08109D5C:
	ldrb r0, [r5, #4]
	b _08109D62
_08109D60:
	ldrb r0, [r5]
_08109D62:
	subs r2, r2, r0
_08109D64:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08109D6E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x40]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _08109D98 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x74]
	cmp r0, #0
	bne _08109E76
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08109D9C
	movs r0, #1
	b _08109D9E
	.align 2, 0
_08109D98: .4byte 0x00000482
_08109D9C:
	movs r0, #0
_08109D9E:
	ldr r3, _08109E84 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x74]
	cmp r0, #0
	bne _08109E76
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _08109E88 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	adds r4, #0xc
	adds r4, r4, r7
	mov sb, r4
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08109E8C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r4, _08109E90 @ =0x00000541
	adds r4, r4, r7
	mov ip, r4
	ldr r0, _08109E94 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _08109E98 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r1, _08109E9C @ =0x030046B8
	str r5, [sp, #0x84]
_08109DE4:
	ldr r0, [r1]
	adds r0, #1
	ldr r4, _08109EA0 @ =0x000003FF
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	ldr r4, _08109EA4 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	lsls r0, r0, #6
	ldr r4, [sp, #0x84]
	cmp r0, r4
	bne _08109E0A
	adds r3, #1
	cmp r3, #3
	ble _08109DE4
	adds r0, r5, #0
_08109E0A:
	movs r3, #0
	strb r0, [r2]
	ldr r5, [sp, #0x50]
	ldr r0, [r5]
	str r0, [r6]
	ldr r6, [sp, #0x4c]
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x5c]
	ldrb r0, [r2]
	mov r4, sb
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	add r4, sp, #0x40
	ldrb r5, [r4]
	mov r4, ip
	strb r5, [r4]
	ldr r5, [sp, #0x54]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x70]
	strb r1, [r6]
	ldr r4, [sp, #0x68]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x7c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x5c]
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r1, [r5]
	ldr r6, [sp, #0x64]
	strb r2, [r6]
	ldr r0, [sp, #0x78]
	str r3, [r0]
	ldr r2, [sp, #0x6c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x44]
	strb r0, [r3]
_08109E76:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x74]
	strh r0, [r4]
	b _08109F70
	.align 2, 0
_08109E84: .4byte 0x00000482
_08109E88: .4byte 0x0000054F
_08109E8C: .4byte 0x0000054E
_08109E90: .4byte 0x00000541
_08109E94: .4byte 0x000005BC
_08109E98: .4byte 0x00000542
_08109E9C: .4byte 0x030046B8
_08109EA0: .4byte 0x000003FF
_08109EA4: .4byte 0x0203B400
_08109EA8:
	add r6, sp, #8
	ldr r0, _08109EE8 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _08109EEC
	adds r0, #4
	b _08109EF8
	.align 2, 0
_08109EE8: .4byte 0x030046A4
_08109EEC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08109EF8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08109F2C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08109F30
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _08109F56
	.align 2, 0
_08109F2C: .4byte 0x000004A4
_08109F30:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08109F50
	cmp r0, #2
	beq _08109F4C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08109F4C:
	movs r0, #1
	b _08109F60
_08109F50:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_08109F56:
	ldr r1, _08109F80 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08109F60:
	cmp r0, #0
	bne _08109F70
	ldr r2, _08109F84 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_08109F70:
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08109F80: .4byte 0xFFFFFDFF
_08109F84: .4byte 0x000005C4
