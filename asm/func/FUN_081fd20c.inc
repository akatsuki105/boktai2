	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r6, r0, #0
	adds r7, r6, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x48]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FD294
	movs r0, #0
	strb r0, [r1]
	ldr r0, [sp, #0x48]
	bl NestedState_Reset0
	ldr r0, _081FD2B4 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x50
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	ldr r5, _081FD2B8 @ =0x000007CC
	adds r0, r6, r5
	ldr r0, [r0]
	movs r1, #2
	bl FUN_08203d0c
_081FD294:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	cmp r0, #8
	bls _081FD2AA
	b _081FD7EA
_081FD2AA:
	lsls r0, r0, #2
	ldr r1, _081FD2BC @ =_081FD2C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FD2B4: .4byte 0x03002BE0
_081FD2B8: .4byte 0x000007CC
_081FD2BC: .4byte _081FD2C0
_081FD2C0: @ jump table
	.4byte _081FD2E4 @ case 0
	.4byte _081FD314 @ case 1
	.4byte _081FD336 @ case 2
	.4byte _081FD358 @ case 3
	.4byte _081FD73A @ case 4
	.4byte _081FD75A @ case 5
	.4byte _081FD794 @ case 6
	.4byte _081FD7D0 @ case 7
	.4byte _081FD7E2 @ case 8
_081FD2E4:
	ldr r2, [sp, #0x48]
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FD30C
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #2
_081FD304:
	bl Boss_PlayAnimFacing
	ldr r5, [sp, #0x48]
	str r4, [r5, #4]
_081FD30C:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	b _081FD7C4
_081FD314:
	ldr r4, [sp, #0x48]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD30C
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #4
	b _081FD304
_081FD336:
	ldr r4, [sp, #0x48]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD30C
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #6
	b _081FD304
_081FD358:
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r5, #0x87
	lsls r5, r5, #2
	adds r2, r7, r5
	adds r0, r6, #0
	bl Boss_AdvanceAnim
	ldr r1, [sp, #0x48]
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _081FD374
	b _081FD584
_081FD374:
	cmp r0, #1
	bgt _081FD37E
	cmp r0, #0
	beq _081FD386
	b _081FD7EA
_081FD37E:
	cmp r0, #2
	bne _081FD384
	b _081FD614
_081FD384:
	b _081FD7EA
_081FD386:
	adds r2, r6, #0
	adds r2, #0x4d
	ldrb r0, [r2]
	subs r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x40
	ldrb r0, [r2]
	subs r0, #0x20
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x40
	add r5, sp, #0x28
	ldr r2, _081FD3C8 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov r8, r2
	cmp r0, #0
	blt _081FD3CC
	asrs r1, r0, #0xc
	b _081FD3D2
	.align 2, 0
_081FD3C8: .4byte gSineTable
_081FD3CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD3D2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081FD3F2
	asrs r0, r0, #0xc
	b _081FD3F8
_081FD3F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FD3F8:
	strh r0, [r5, #4]
	add r4, sp, #0x30
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #8
	cmp r0, #0
	blt _081FD416
	asrs r1, r0, #0xc
	b _081FD41C
_081FD416:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD41C:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081FD43C
	asrs r0, r0, #0xc
	b _081FD442
_081FD43C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FD442:
	movs r2, #0
	strh r0, [r4, #4]
	add r0, sp, #0x38
	movs r1, #0xf0
	lsls r1, r1, #3
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r1, [r0, #4]
	adds r5, r0, #0
	movs r1, #7
	mov r8, r5
	ldr r0, _081FD46C @ =0x030046A8
	ldr r0, [r0]
	cmp r1, r0
	bhs _081FD468
	ldr r0, _081FD470 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FD474
_081FD468:
	movs r4, #0
	b _081FD47C
	.align 2, 0
_081FD46C: .4byte 0x030046A8
_081FD470: .4byte 0x030046AC
_081FD474:
	ldr r0, _081FD48C @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, #7
_081FD47C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FD490
	adds r0, #4
	b _081FD49C
	.align 2, 0
_081FD48C: .4byte 0x030046A4
_081FD490:
	ldr r0, _081FD548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FD49C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r3, #0x82
	lsls r3, r3, #4
	adds r6, r7, r3
	add r1, sp, #0x28
	add r0, sp, #0x38
	ldrh r5, [r0]
	adds r0, r1, #0
	ldrh r0, [r0]
	mov sl, r0
	mov r4, sl
	adds r0, r5, r4
	strh r0, [r6]
	mov r0, r8
	ldrh r4, [r0, #2]
	ldrh r2, [r1, #2]
	mov sb, r2
	mov r3, sb
	adds r0, r4, r3
	strh r0, [r6, #2]
	mov r0, r8
	ldrh r3, [r0, #4]
	ldrh r1, [r1, #4]
	mov r8, r1
	mov r1, r8
	adds r0, r3, r1
	strh r0, [r6, #4]
	ldr r0, _081FD54C @ =0x00000828
	adds r2, r7, r0
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r7, r1
	mov r2, sl
	subs r5, r5, r2
	strh r5, [r0]
	mov r5, sb
	subs r4, r4, r5
	strh r4, [r0, #2]
	mov r1, r8
	subs r3, r3, r1
	strh r3, [r0, #4]
	ldr r2, _081FD550 @ =0x030046B8
	add r4, sp, #0x30
	adds r5, r4, #0
	movs r7, #2
_081FD506:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FD554 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081FD558 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	str r2, [sp, #0x4c]
	bl Mod
	ldr r2, [sp, #0x4c]
	cmp r0, #1
	beq _081FD55C
	cmp r0, #1
	bgt _081FD574
	cmp r0, #0
	bne _081FD574
	ldrh r0, [r5]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r4, #2]
	ldrh r3, [r6, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	b _081FD572
	.align 2, 0
_081FD548: .4byte 0x030046A4
_081FD54C: .4byte 0x00000828
_081FD550: .4byte 0x030046B8
_081FD554: .4byte 0x000003FF
_081FD558: .4byte 0x0203B400
_081FD55C:
	ldrh r0, [r6]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
_081FD572:
	strh r0, [r6, #4]
_081FD574:
	adds r6, #8
	subs r7, #1
	cmp r7, #0
	bge _081FD506
	ldr r0, [sp, #0x48]
	bl NestedState_Advance1
	b _081FD7EA
_081FD584:
	adds r0, r6, #0
	adds r0, #0x50
	ldr r2, [sp, #0x48]
	ldr r1, [r2, #4]
	lsls r1, r1, #3
	movs r3, #0x82
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r1, r7, r1
	ldr r4, _081FD600 @ =0x000007F6
	adds r2, r7, r4
	ldrh r2, [r2]
	ldr r5, _081FD604 @ =0x000007EC
	adds r3, r7, r5
	movs r5, #0
	ldrsh r4, [r3, r5]
	mov r8, r4
	movs r4, #0xf
	str r4, [sp]
	movs r6, #2
	str r6, [sp, #4]
	movs r5, #0xa
	str r5, [sp, #8]
	ldr r4, _081FD608 @ =0x00000BB8
	str r4, [sp, #0xc]
	movs r4, #0x12
	str r4, [sp, #0x10]
	ldr r3, _081FD60C @ =0x000007EE
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0
	ldrsh r3, [r3, r4]
	str r3, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r5, [sp, #0x20]
	movs r4, #0x96
	lsls r4, r4, #2
	str r4, [sp, #0x24]
	mov r3, r8
	bl FUN_0820361c
	movs r0, #0xdc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r5, [sp, #0x48]
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	ldr r0, [sp, #0x48]
	bl NestedState_Advance1
	ldr r1, _081FD610 @ =0x000007CC
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08203c4c
	b _081FD7EA
	.align 2, 0
_081FD600: .4byte 0x000007F6
_081FD604: .4byte 0x000007EC
_081FD608: .4byte 0x00000BB8
_081FD60C: .4byte 0x000007EE
_081FD610: .4byte 0x000007CC
_081FD614:
	ldr r2, _081FD64C @ =0x000007CC
	adds r4, r7, r2
	ldr r0, [r4]
	movs r1, #1
	bl FUN_08203c4c
	ldr r3, [sp, #0x48]
	ldr r0, [r3, #8]
	adds r5, r0, #1
	str r5, [r3, #8]
	movs r1, #0xff
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	bls _081FD65A
	ldr r0, [r4]
	movs r1, #1
	bl FUN_08203c58
	ldr r2, [sp, #0x48]
	ldr r0, [r2, #4]
	cmp r0, #2
	bls _081FD650
	adds r0, r2, #0
	bl NestedState_Advance0
	b _081FD7EA
	.align 2, 0
_081FD64C: .4byte 0x000007CC
_081FD650:
	ldr r0, [sp, #0x48]
	movs r1, #1
	bl NestedState_Set1
	b _081FD7EA
_081FD65A:
	cmp r5, #1
	bne _081FD6B4
	adds r0, r6, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	movs r3, #0xc0
	lsls r3, r3, #0x18
	adds r0, r0, r3
	add r4, sp, #0x40
	lsrs r5, r0, #0x18
	movs r7, #0x3c
	rsbs r7, r7, #0
	ldr r2, _081FD694 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov r8, r2
	adds r2, r4, #0
	cmp r0, #0
	blt _081FD698
	asrs r1, r0, #0xc
	b _081FD69E
	.align 2, 0
_081FD694: .4byte gSineTable
_081FD698:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD69E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	bge _081FD70E
	b _081FD712
_081FD6B4:
	cmp r5, #9
	bls _081FD6BA
	b _081FD7EA
_081FD6BA:
	adds r0, r6, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	movs r3, #0xc0
	lsls r3, r3, #0x18
	adds r0, r0, r3
	add r4, sp, #0x40
	lsrs r5, r0, #0x18
	movs r7, #6
	ldr r2, _081FD6F0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov r8, r2
	adds r2, r4, #0
	cmp r0, #0
	blt _081FD6F4
	asrs r1, r0, #0xc
	b _081FD6FA
	.align 2, 0
_081FD6F0: .4byte gSineTable
_081FD6F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD6FA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _081FD712
_081FD70E:
	asrs r0, r0, #0xc
	b _081FD718
_081FD712:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FD718:
	strh r0, [r4, #4]
	adds r1, r6, #0
	adds r1, #0x50
	add r0, sp, #0x40
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	b _081FD7EA
_081FD73A:
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r7, r4
	adds r0, r6, #0
	bl Boss_AdvanceAnim
	ldr r5, [sp, #0x48]
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0x64
	bls _081FD7EA
	b _081FD7DA
_081FD75A:
	ldr r1, [sp, #0x48]
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FD7BE
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #4
	bl Boss_PlayAnimFacing
	ldr r5, [sp, #0x48]
	str r4, [r5, #4]
	ldr r1, _081FD790 @ =0x000007CC
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_08203d38
	b _081FD7BE
	.align 2, 0
_081FD790: .4byte 0x000007CC
_081FD794:
	ldr r4, [sp, #0x48]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD7BE
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #2
	bl Boss_PlayAnimFacing
	ldr r1, [sp, #0x48]
	str r4, [r1, #4]
_081FD7BE:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
_081FD7C4:
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	adds r0, r6, #0
	bl Boss_AdvanceAnim
_081FD7D0:
	adds r0, r6, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FD7EA
_081FD7DA:
	ldr r0, [sp, #0x48]
	bl NestedState_Advance0
	b _081FD7EA
_081FD7E2:
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FD7EA:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
