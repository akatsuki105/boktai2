	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081102B8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081102BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081102BE
	.align 2, 0
_081102B8: .4byte 0x0000046C
_081102BC:
	movs r0, #0
_081102BE:
	cmp r0, #0
	beq _081102EC
	ldr r4, _081103C0 @ =Skeleton_StateKeepDistance
	movs r3, #0x25
	ldr r6, _081103C4 @ =0x0000046D
	adds r1, r7, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081103C8 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_081102EC:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081102FC
	b _0811090C
_081102FC:
	movs r0, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r1, #0
	strb r1, [r4]
	ldr r6, _081103CC @ =0x00000469
	adds r6, r7, r6
	str r6, [sp, #0x14]
	strb r1, [r6]
	ldr r2, _081103D0 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	ldr r4, _081103D4 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	str r1, [r4]
	ldr r6, _081103D8 @ =0x0000046C
	adds r6, r6, r7
	mov sl, r6
	strb r3, [r6]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r4, _081103C4 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r3, [r4]
	ldr r6, _081103C8 @ =0x0000046B
	adds r6, r6, r7
	mov ip, r6
	strb r1, [r6]
	ldr r3, _081103DC @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r4, r7, r6
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, [r1]
	str r2, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x20]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r6, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sl
	str r0, [sp, #0x2c]
	mov r0, sb
	str r0, [sp, #0x30]
	mov r0, ip
	str r0, [sp, #0x28]
	str r5, [sp, #0x54]
	str r4, [sp, #0x58]
	str r3, [sp, #0x38]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x64]
	ldr r4, [sp, #0x14]
	str r4, [sp, #0x68]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x6c]
	ldr r3, [sp, #0x1c]
	str r3, [sp, #0x34]
	mov sb, r2
	cmp r6, #0
	blt _081103BC
	cmp r1, #0
	blt _081103BC
	ldr r0, _081103E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r6, r0
	bhs _081103BC
	ldr r0, _081103E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081103E8
_081103BC:
	movs r4, #0
	b _081103F6
	.align 2, 0
_081103C0: .4byte Skeleton_StateKeepDistance
_081103C4: .4byte 0x0000046D
_081103C8: .4byte 0x0000046B
_081103CC: .4byte 0x00000469
_081103D0: .4byte 0x0000046A
_081103D4: .4byte 0x00000484
_081103D8: .4byte 0x0000046C
_081103DC: .4byte 0x00000553
_081103E0: .4byte 0x030046A8
_081103E4: .4byte 0x030046AC
_081103E8:
	ldr r0, _08110408 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r6
_081103F6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811040C
	adds r0, #4
	b _08110418
	.align 2, 0
_08110408: .4byte 0x030046A4
_0811040C:
	ldr r0, _0811042C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08110418:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08110430
	cmp r2, #2
	beq _08110436
	b _0811043C
	.align 2, 0
_0811042C: .4byte 0x030046A4
_08110430:
	ldr r4, [sp, #0x20]
	ldrb r0, [r4, #4]
	b _0811043A
_08110436:
	ldr r6, [sp, #0x20]
	ldrb r0, [r6]
_0811043A:
	subs r1, r1, r0
_0811043C:
	ldr r0, [sp, #0x20]
	strh r1, [r0, #2]
	ldr r0, _08110454 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08110458
	movs r0, #1
	b _0811045A
	.align 2, 0
_08110454: .4byte 0x030047A4
_08110458:
	movs r0, #0
_0811045A:
	cmp r0, #0
	beq _081104A0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811047A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08110476
	adds r2, r0, #0
_08110476:
	cmp r2, #0
	bge _0811048C
_0811047A:
	ldr r2, _08110488 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081108EC
	.align 2, 0
_08110488: .4byte 0x000005C4
_0811048C:
	ldr r1, _0811049C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081104E8
	.align 2, 0
_0811049C: .4byte 0x03002BE0
_081104A0:
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
	blt _081104CC
	cmp r1, #0
	blt _081104CC
	ldr r0, _081104D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081104CC
	ldr r0, _081104D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081104D8
_081104CC:
	movs r5, #0
	b _081104E6
	.align 2, 0
_081104D0: .4byte 0x030046A8
_081104D4: .4byte 0x030046AC
_081104D8:
	ldr r0, _0811057C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081104E6:
	movs r2, #0
_081104E8:
	ldr r4, _08110580 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08110508
	ldr r1, _08110584 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08110508
	b _08110828
_08110508:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r6, r2, #0
	cmp r4, #0
	beq _08110522
	b _081108EC
_08110522:
	ldr r0, _08110588 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x5c]
	cmp r3, #0
	beq _0811058C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x30]
	strb r2, [r3]
	ldr r3, [sp, #0x28]
	strb r5, [r3]
	ldr r3, [sp, #0x54]
	strb r0, [r3]
	ldr r0, [sp, #0x58]
	str r1, [r0]
	ldr r1, [sp, #0x38]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x64]
	strb r5, [r3]
	ldr r1, [sp, #0x68]
	strb r5, [r1]
	ldr r3, [sp, #0x6c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r4, [r0]
	ldr r1, [sp, #0x2c]
	strb r2, [r1]
	b _081106EA
	.align 2, 0
_0811057C: .4byte 0x030046A4
_08110580: .4byte 0x00000256
_08110584: .4byte 0x03002BE0
_08110588: .4byte 0x00000222
_0811058C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r2, [sp, #0x28]
	strb r5, [r2]
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r2, [sp, #0x58]
	str r1, [r2]
	ldr r4, [sp, #0x38]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x64]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r5, [r4]
	ldr r2, [sp, #0x6c]
	strb r1, [r2]
	ldr r4, [sp, #0x34]
	str r3, [r4]
	ldr r1, [sp, #0x2c]
	strb r0, [r1]
	mov r2, r8
	ldr r5, [r2]
	mov r3, sb
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
	blt _081105F2
	cmp r1, #0
	blt _081105F2
	ldr r0, _081105F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081105F2
	ldr r0, _081105FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08110600
_081105F2:
	movs r4, #0
	b _0811060E
	.align 2, 0
_081105F8: .4byte 0x030046A8
_081105FC: .4byte 0x030046AC
_08110600:
	ldr r0, _08110620 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811060E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08110624
	adds r0, #4
	b _08110630
	.align 2, 0
_08110620: .4byte 0x030046A4
_08110624:
	ldr r0, _08110644 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08110630:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08110648
	cmp r2, #2
	beq _0811064C
	b _08110650
	.align 2, 0
_08110644: .4byte 0x030046A4
_08110648:
	ldrb r0, [r5, #4]
	b _0811064E
_0811064C:
	ldrb r0, [r5]
_0811064E:
	subs r1, r1, r0
_08110650:
	strh r1, [r5, #2]
	mov r4, r8
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811067A
	cmp r1, #0
	blt _0811067A
	ldr r0, _08110680 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811067A
	ldr r0, _08110684 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08110688
_0811067A:
	movs r4, #0
	b _08110696
	.align 2, 0
_08110680: .4byte 0x030046A8
_08110684: .4byte 0x030046AC
_08110688:
	ldr r0, _081106AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08110696:
	mov r0, r8
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081106B0
	adds r0, #4
	b _081106BC
	.align 2, 0
_081106AC: .4byte 0x030046A4
_081106B0:
	ldr r0, _081106D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081106BC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081106D4
	cmp r3, #2
	beq _081106D8
	b _081106DC
	.align 2, 0
_081106D0: .4byte 0x030046A4
_081106D4:
	ldrb r0, [r5, #4]
	b _081106DA
_081106D8:
	ldrb r0, [r5]
_081106DA:
	subs r2, r2, r0
_081106DC:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	mov r2, r8
	ldr r0, [r2]
	strh r1, [r0, #6]
_081106EA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r6]
	ands r0, r1
	mov sl, r3
	ldr r4, _08110710 @ =0x00000482
	adds r5, r7, r4
	cmp r0, #0
	bne _081107F4
	movs r1, #4
	ldr r6, [sp, #0x5c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08110714
	movs r0, #1
	b _08110716
	.align 2, 0
_08110710: .4byte 0x00000482
_08110714:
	movs r0, #0
_08110716:
	ldr r1, _08110800 @ =0x00000482
	adds r5, r7, r1
	cmp r0, #0
	bne _081107F4
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov ip, r4
	ldr r6, _08110804 @ =0x0000054F
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r0, _08110808 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x44]
	adds r1, #0xcb
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _0811080C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r4, _08110810 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x3c]
	ldr r6, _08110814 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x60]
	ldr r0, _08110818 @ =0x00000542
	adds r0, r7, r0
	str r0, [sp, #0x40]
	ldr r1, _0811081C @ =0x0203B400
	mov r8, r1
	ldr r1, _08110820 @ =0x030046B8
	ldr r6, _08110824 @ =0x000003FF
	movs r4, #3
	mov r2, sl
_08110766:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _08110784
	adds r3, #1
	cmp r3, #3
	ble _08110766
	mov r0, sl
_08110784:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x58]
	ldr r0, [r4]
	mov r6, ip
	str r0, [r6]
	ldr r1, [sp, #0x54]
	ldrb r0, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r4, [sp, #0x64]
	ldrb r0, [r4]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	ldr r1, [sp, #0x68]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x6c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x4c]
	strb r0, [r6]
	add r0, sp, #0x24
	ldrb r1, [r0]
	ldr r0, [sp, #0x3c]
	strb r1, [r0]
	ldr r1, [sp, #0x60]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x30]
	strb r1, [r4]
	ldr r6, [sp, #0x28]
	strb r3, [r6]
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r6, [sp, #0x58]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x38]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x64]
	strb r0, [r4]
	ldr r6, [sp, #0x68]
	strb r1, [r6]
	ldr r0, [sp, #0x6c]
	strb r2, [r0]
	ldr r2, [sp, #0x34]
	str r3, [r2]
	ldr r3, [sp, #0x2c]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x40]
	strb r0, [r4]
_081107F4:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	b _081108EC
	.align 2, 0
_08110800: .4byte 0x00000482
_08110804: .4byte 0x0000054F
_08110808: .4byte 0x0000054C
_0811080C: .4byte 0x0000054E
_08110810: .4byte 0x00000541
_08110814: .4byte 0x000005BC
_08110818: .4byte 0x00000542
_0811081C: .4byte 0x0203B400
_08110820: .4byte 0x030046B8
_08110824: .4byte 0x000003FF
_08110828:
	mov sb, sp
	ldr r6, _08110864 @ =0x030046A4
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
	beq _08110868
	adds r0, #4
	b _08110872
	.align 2, 0
_08110864: .4byte 0x030046A4
_08110868:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08110872:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _081108A8 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081108AC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _081108D2
	.align 2, 0
_081108A8: .4byte 0x000004A4
_081108AC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081108CC
	cmp r0, #2
	beq _081108C8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081108C8:
	movs r0, #1
	b _081108DC
_081108CC:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_081108D2:
	ldr r1, _08110904 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081108DC:
	cmp r0, #0
	bne _081108EC
	ldr r4, _08110908 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_081108EC:
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	movs r1, #0x80
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _08110ABA
	.align 2, 0
_08110904: .4byte 0xFFFFFDFF
_08110908: .4byte 0x000005C4
_0811090C:
	add r2, sp, #8
	adds r4, r7, #0
	adds r4, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl ArcTan2_8
	adds r6, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, _08110968 @ =0x0000075C
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08110970
	adds r6, #0x80
	movs r0, #0xff
	ands r6, r0
	ldr r2, _0811096C @ =0x00000482
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	b _08110986
	.align 2, 0
_08110968: .4byte 0x0000075C
_0811096C: .4byte 0x00000482
_08110970:
	movs r0, #0xec
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bls _08110986
	ldr r3, _081109BC @ =0x00000482
	adds r1, r7, r3
	movs r0, #2
	strh r0, [r1]
	strb r6, [r7, #5]
_08110986:
	adds r0, r7, #0
	movs r1, #1
	bl Enemy_PlayAnim
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	mov sb, r0
	ldr r1, _081109C0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081109C4
	ldr r3, _081109BC @ =0x00000482
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
	adds r5, r1, #0
	b _081109D4
	.align 2, 0
_081109BC: .4byte 0x00000482
_081109C0: .4byte 0x0000A02F
_081109C4:
	ldr r4, _081109F8 @ =0x00000482
	adds r0, r7, r4
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _081109D4
	movs r0, #1
	strh r0, [r5]
_081109D4:
	ldr r1, _081109FC @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08110A00
	ldr r4, [r7, #0x44]
	adds r4, #0x48
	ldrh r1, [r5]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _08110A18
	.align 2, 0
_081109F8: .4byte 0x00000482
_081109FC: .4byte 0x0000025D
_08110A00:
	ldr r4, [r7, #0x44]
	adds r4, #0x20
	ldrh r1, [r5]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_08110A18:
	ldr r2, _08110A38 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r0, #0
	blt _08110A3C
	asrs r1, r0, #0x10
	b _08110A42
	.align 2, 0
_08110A38: .4byte gSineTable
_08110A3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_08110A42:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r1
	strh r0, [r7, #0x10]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08110A62
	asrs r2, r0, #0x10
	b _08110A68
_08110A62:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r2, r0, #0
_08110A68:
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, _08110AAC @ =0x0000075C
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _08110AB0
	movs r0, #0xec
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08110AB0
	movs r0, #0x80
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08110ABA
	.align 2, 0
_08110AAC: .4byte 0x0000075C
_08110AB0:
	ldr r0, _08110ACC @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110ABA:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08110ACC: .4byte 0x00000484
