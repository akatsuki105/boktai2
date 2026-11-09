	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _08156468 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0815646C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815646E
	.align 2, 0
_08156468: .4byte 0x0000046D
_0815646C:
	movs r0, #0
_0815646E:
	cmp r0, #0
	beq _08156486
	ldr r3, _081564C0 @ =0x000006EA
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	bl Cockatrice_SpawnShot
	adds r0, r7, #0
	bl Cockatrice_PlayFireAnim
_08156486:
	ldr r4, _081564C4 @ =0x0000046E
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08156494
	bl _08156E9A
_08156494:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r0, _081564C8 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081564C0 @ =0x000006EA
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r2, [sp, #0x50]
	cmp r0, #0
	ble _081564CC
	adds r0, r7, #0
	bl Cockatrice_PlayFireAnim
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	bl _08156E9A
	.align 2, 0
_081564C0: .4byte 0x000006EA
_081564C4: .4byte 0x0000046E
_081564C8: .4byte 0xFFFFFEFF
_081564CC:
	movs r2, #0x99
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	bl Entity081e9cacElem_Launch
	movs r0, #0xe8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0x80
	ldr r3, [sp, #0x50]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _081564EE
	b _08156BEC
_081564EE:
	movs r1, #2
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08156502
	movs r0, #1
	b _08156504
_08156502:
	movs r0, #0
_08156504:
	cmp r0, #0
	beq _0815650C
	bl _08156E9A
_0815650C:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
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
	str r3, [sp, #0x80]
	str r2, [sp, #0x84]
	cmp r4, #0
	blt _08156550
	cmp r1, #0
	blt _08156550
	ldr r0, _08156554 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08156550
	ldr r0, _08156558 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815655C
_08156550:
	movs r4, #0
	b _0815656A
	.align 2, 0
_08156554: .4byte 0x030046A8
_08156558: .4byte 0x030046AC
_0815655C:
	ldr r0, _0815657C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815656A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08156580
	adds r0, #4
	b _0815658C
	.align 2, 0
_0815657C: .4byte 0x030046A4
_08156580:
	ldr r0, _081565A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815658C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081565A4
	cmp r2, #2
	beq _081565A8
	b _081565AC
	.align 2, 0
_081565A0: .4byte 0x030046A4
_081565A4:
	ldrb r0, [r5, #4]
	b _081565AA
_081565A8:
	ldrb r0, [r5]
_081565AA:
	subs r1, r1, r0
_081565AC:
	strh r1, [r5, #2]
	ldr r0, _081565C0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081565C4
	movs r0, #1
	b _081565C6
	.align 2, 0
_081565C0: .4byte 0x030047A4
_081565C4:
	movs r0, #0
_081565C6:
	cmp r0, #0
	beq _08156604
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081565E6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081565E2
	adds r2, r0, #0
_081565E2:
	cmp r2, #0
	bge _081565F0
_081565E6:
	ldr r2, _081565EC @ =0x000005C4
	adds r0, r7, r2
	b _08156B2C
	.align 2, 0
_081565EC: .4byte 0x000005C4
_081565F0:
	ldr r1, _08156600 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815664C
	.align 2, 0
_08156600: .4byte 0x03002BE0
_08156604:
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
	blt _08156630
	cmp r1, #0
	blt _08156630
	ldr r0, _08156634 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08156630
	ldr r0, _08156638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815663C
_08156630:
	movs r5, #0
	b _0815664A
	.align 2, 0
_08156634: .4byte 0x030046A8
_08156638: .4byte 0x030046AC
_0815663C:
	ldr r0, _08156684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815664A:
	movs r2, #0
_0815664C:
	ldr r4, _08156688 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815666C
	ldr r1, _0815668C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815666C
	b _08156A6C
_0815666C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r6, [sp, #0x50]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08156690
	movs r0, #0
	b _08156B42
	.align 2, 0
_08156684: .4byte 0x030046A4
_08156688: .4byte 0x00000256
_0815668C: .4byte 0x03002BE0
_08156690:
	ldr r0, _08156730 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x50]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x5c]
	cmp r6, #0
	beq _08156750
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _08156734 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _08156738 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r6, _0815673C @ =0x00000553
	adds r6, r6, r7
	mov r8, r6
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sl, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sb
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08156740 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08156744 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08156748 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _0815674C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x74]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x6c]
	mov r6, r8
	str r6, [sp, #0x48]
	mov r6, sl
	str r6, [sp, #0x4c]
	str r5, [sp, #0x58]
	str r4, [sp, #0x60]
	str r3, [sp, #0x64]
	str r2, [sp, #0x68]
	str r1, [sp, #0x7c]
	str r0, [sp, #0x70]
	b _08156922
	.align 2, 0
_08156730: .4byte 0x00000222
_08156734: .4byte 0x0000046D
_08156738: .4byte 0x0000046B
_0815673C: .4byte 0x00000553
_08156740: .4byte 0x00000469
_08156744: .4byte 0x0000046A
_08156748: .4byte 0x00000484
_0815674C: .4byte 0x0000046C
_08156750:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _08156810 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	ldr r3, _08156814 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	movs r4, #0
	strb r4, [r3]
	ldr r2, _08156818 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x24]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	strh r6, [r4]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x28]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0815681C @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _08156820 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08156824 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08156828 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x80]
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r1, [sp, #0x84]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x2c]
	strh r1, [r6]
	ldr r6, [sp, #0x84]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x2c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x6c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x4c]
	mov r0, r8
	str r0, [sp, #0x58]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0x60]
	str r5, [sp, #0x64]
	str r4, [sp, #0x68]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x70]
	mov r0, ip
	cmp r0, #0
	blt _0815680C
	cmp r1, #0
	blt _0815680C
	ldr r0, _0815682C @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0815680C
	ldr r0, _08156830 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08156834
_0815680C:
	movs r4, #0
	b _08156844
	.align 2, 0
_08156810: .4byte 0x0000046D
_08156814: .4byte 0x0000046B
_08156818: .4byte 0x00000553
_0815681C: .4byte 0x00000469
_08156820: .4byte 0x0000046A
_08156824: .4byte 0x00000484
_08156828: .4byte 0x0000046C
_0815682C: .4byte 0x030046A8
_08156830: .4byte 0x030046AC
_08156834:
	ldr r0, _08156854 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08156844:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08156858
	adds r0, #4
	b _08156864
	.align 2, 0
_08156854: .4byte 0x030046A4
_08156858:
	ldr r0, _08156878 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08156864:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815687C
	cmp r2, #2
	beq _08156882
	b _08156888
	.align 2, 0
_08156878: .4byte 0x030046A4
_0815687C:
	ldr r2, [sp, #0x2c]
	ldrb r0, [r2, #4]
	b _08156886
_08156882:
	ldr r3, [sp, #0x2c]
	ldrb r0, [r3]
_08156886:
	subs r1, r1, r0
_08156888:
	ldr r4, [sp, #0x2c]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x80]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081568B4
	cmp r1, #0
	blt _081568B4
	ldr r0, _081568B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081568B4
	ldr r0, _081568BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081568C0
_081568B4:
	movs r4, #0
	b _081568CE
	.align 2, 0
_081568B8: .4byte 0x030046A8
_081568BC: .4byte 0x030046AC
_081568C0:
	ldr r0, _081568E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081568CE:
	ldr r0, [sp, #0x80]
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081568E8
	adds r0, #4
	b _081568F4
	.align 2, 0
_081568E4: .4byte 0x030046A4
_081568E8:
	ldr r0, _08156908 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081568F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815690C
	cmp r3, #2
	beq _08156910
	b _08156914
	.align 2, 0
_08156908: .4byte 0x030046A4
_0815690C:
	ldrb r0, [r5, #4]
	b _08156912
_08156910:
	ldrb r0, [r5]
_08156912:
	subs r2, r2, r0
_08156914:
	ldr r1, [sp, #0x80]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x80]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08156922:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x30]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x50]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r6, _0815694C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x78]
	cmp r0, #0
	bne _08156A30
	movs r1, #4
	ldr r2, [sp, #0x5c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08156950
	movs r0, #1
	b _08156952
	.align 2, 0
_0815694C: .4byte 0x00000482
_08156950:
	movs r0, #0
_08156952:
	ldr r3, _08156A40 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x78]
	cmp r0, #0
	bne _08156A30
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08156A44 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08156A48 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r2, _08156A4C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r4, _08156A50 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r6, _08156A54 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x34]
	ldr r0, _08156A58 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _08156A5C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x38]
	ldr r6, _08156A60 @ =0x0203B400
	ldr r1, _08156A64 @ =0x030046B8
	ldr r5, _08156A68 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_081569A2:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _081569C0
	adds r3, #1
	cmp r3, #3
	ble _081569A2
	mov r0, sb
_081569C0:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x60]
	ldrb r0, [r4]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	ldrb r0, [r4]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	add r0, sp, #0x30
	ldrb r1, [r0]
	ldr r0, [sp, #0x34]
	strb r1, [r0]
	ldr r1, [sp, #0x54]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x74]
	strb r1, [r4]
	ldr r6, [sp, #0x6c]
	strb r3, [r6]
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x58]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r6, [sp, #0x64]
	strb r1, [r6]
	ldr r0, [sp, #0x68]
	strb r2, [r0]
	ldr r2, [sp, #0x7c]
	str r3, [r2]
	ldr r3, [sp, #0x70]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x38]
	strb r0, [r4]
_08156A30:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x78]
	strh r0, [r6]
	movs r0, #0
	b _08156B42
	.align 2, 0
_08156A40: .4byte 0x00000482
_08156A44: .4byte 0x0000054F
_08156A48: .4byte 0x0000054C
_08156A4C: .4byte 0x0000054D
_08156A50: .4byte 0x0000054E
_08156A54: .4byte 0x00000541
_08156A58: .4byte 0x000005BC
_08156A5C: .4byte 0x00000542
_08156A60: .4byte 0x0203B400
_08156A64: .4byte 0x030046B8
_08156A68: .4byte 0x000003FF
_08156A6C:
	mov sb, sp
	ldr r6, _08156AA8 @ =0x030046A4
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
	beq _08156AAC
	adds r0, #4
	b _08156AB6
	.align 2, 0
_08156AA8: .4byte 0x030046A4
_08156AAC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08156AB6:
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
	ldr r1, _08156AF0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08156AF8
	ldr r0, _08156AF4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x50]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08156B22
	.align 2, 0
_08156AF0: .4byte 0x000004A4
_08156AF4: .4byte 0xFFFFFDFF
_08156AF8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08156B18
	cmp r0, #2
	beq _08156B14
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156B14:
	movs r0, #1
	b _08156B24
_08156B18:
	ldr r0, _08156B38 @ =0xFFFFFDFF
	ldr r3, [sp, #0x50]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08156B22:
	movs r0, #0
_08156B24:
	cmp r0, #0
	bne _08156B40
	ldr r4, _08156B3C @ =0x000005C4
	adds r0, r7, r4
_08156B2C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08156B42
	.align 2, 0
_08156B38: .4byte 0xFFFFFDFF
_08156B3C: .4byte 0x000005C4
_08156B40:
	movs r0, #1
_08156B42:
	cmp r0, #0
	bne _08156B48
	b _08156E9A
_08156B48:
	ldr r2, _08156BD0 @ =Enemy_WaitPendingState
	movs r1, #0xe
	ldr r6, _08156BD4 @ =0x0000046D
	adds r0, r7, r6
	movs r5, #0
	movs r3, #1
	mov r8, r3
	mov r4, r8
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r3, _08156BD8 @ =0x00000553
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r3, #0
	strh r5, [r0]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	movs r2, #0xc
	mov sb, r2
	movs r1, #0x18
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _08156BDC @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _08156BE0 @ =0x00000552
	adds r0, r7, r4
	mov r6, sb
	strb r6, [r0]
	movs r1, #3
	subs r2, #0xe9
	adds r0, r7, r2
	strb r1, [r0]
	subs r4, #0xe9
	adds r0, r7, r4
	strb r3, [r0]
	ldr r6, _08156BE4 @ =0x0000046A
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _08156BE8 @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	adds r2, #4
	adds r0, r7, r2
	mov r3, r8
	strb r3, [r0]
	b _08156E9A
	.align 2, 0
_08156BD0: .4byte Enemy_WaitPendingState
_08156BD4: .4byte 0x0000046D
_08156BD8: .4byte 0x00000553
_08156BDC: .4byte 0x00000551
_08156BE0: .4byte 0x00000552
_08156BE4: .4byte 0x0000046A
_08156BE8: .4byte 0x00000484
_08156BEC:
	movs r2, #0x20
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r1, r5, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08156C02
	movs r0, #1
	b _08156C04
_08156C02:
	movs r0, #0
_08156C04:
	cmp r0, #0
	beq _08156CD4
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08156C16
	movs r0, #1
	b _08156C18
_08156C16:
	movs r0, #0
_08156C18:
	mov r8, r0
	cmp r0, #0
	beq _08156C20
	b _08156E9A
_08156C20:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	adds r0, r7, #0
	bl Cockatrice_FleeToPathNode
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r2, _08156CB4 @ =Enemy_WaitPendingState
	movs r1, #0xe
	ldr r6, _08156CB8 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	mov sb, r3
	mov r4, sb
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	mov r3, r8
	strb r3, [r0]
	ldr r4, _08156CBC @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r3, #0
	mov r2, r8
	strh r2, [r0]
	ldr r4, _08156CC0 @ =Cockatrice_StateFlee
	movs r5, #0x13
	movs r1, #0x18
	subs r6, #0x20
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _08156CC4 @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _08156CC8 @ =0x00000552
	adds r0, r7, r4
	strb r5, [r0]
	movs r1, #3
	subs r6, #0xec
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156CCC @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	subs r2, #0xe7
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _08156CD0 @ =0x00000484
	adds r0, r7, r3
	mov r4, r8
	str r4, [r0]
	adds r6, #4
	adds r0, r7, r6
	mov r1, sb
	b _08156E98
	.align 2, 0
_08156CB4: .4byte Enemy_WaitPendingState
_08156CB8: .4byte 0x0000046D
_08156CBC: .4byte 0x00000553
_08156CC0: .4byte Cockatrice_StateFlee
_08156CC4: .4byte 0x00000551
_08156CC8: .4byte 0x00000552
_08156CCC: .4byte 0x00000469
_08156CD0: .4byte 0x00000484
_08156CD4:
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08156CE2
	movs r0, #1
	b _08156CE4
_08156CE2:
	movs r0, #0
_08156CE4:
	cmp r0, #0
	beq _08156CEA
	b _08156E9A
_08156CEA:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	add r5, sp, #8
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r1, [r1, #2]
	strh r1, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r5, #0
	cmp r2, #0
	blt _08156D24
	cmp r1, #0
	blt _08156D24
	ldr r0, _08156D28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08156D24
	ldr r0, _08156D2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08156D30
_08156D24:
	movs r4, #0
	b _08156D3E
	.align 2, 0
_08156D28: .4byte 0x030046A8
_08156D2C: .4byte 0x030046AC
_08156D30:
	ldr r0, _08156D50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08156D3E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08156D54
	adds r0, #4
	b _08156D60
	.align 2, 0
_08156D50: .4byte 0x030046A4
_08156D54:
	ldr r0, _08156D74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08156D60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08156D78
	cmp r2, #2
	beq _08156D7C
	b _08156D80
	.align 2, 0
_08156D74: .4byte 0x030046A4
_08156D78:
	ldrb r0, [r5, #4]
	b _08156D7E
_08156D7C:
	ldrb r0, [r5]
_08156D7E:
	subs r1, r1, r0
_08156D80:
	strh r1, [r5, #2]
	ldrh r0, [r7, #0xa]
	strh r0, [r6, #2]
	ldr r2, _08156DAC @ =0x000004A4
	adds r0, r7, r2
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08156DB4
	ldr r0, _08156DB0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x50]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08156DDE
	.align 2, 0
_08156DAC: .4byte 0x000004A4
_08156DB0: .4byte 0xFFFFFDFF
_08156DB4:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08156DD4
	cmp r0, #2
	beq _08156DD0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156DD0:
	movs r0, #1
	b _08156DE0
_08156DD4:
	ldr r0, _08156DF4 @ =0xFFFFFDFF
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08156DDE:
	movs r0, #0
_08156DE0:
	cmp r0, #0
	bne _08156DFC
	ldr r6, _08156DF8 @ =0x000005C4
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08156E9A
	.align 2, 0
_08156DF4: .4byte 0xFFFFFDFF
_08156DF8: .4byte 0x000005C4
_08156DFC:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r4, #0
	movs r2, #0
	mov sb, r2
	movs r3, #1
	mov r8, r3
	movs r0, #1
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08156EAC @ =Enemy_WaitPendingState
	movs r1, #0xe
	ldr r3, _08156EB0 @ =0x0000046D
	adds r0, r7, r3
	mov r6, r8
	strb r6, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _08156EB4 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r3, sb
	strh r3, [r0]
	adds r6, #0x4d
	adds r0, r7, r6
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x18
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r6, #0x4c
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08156EB8 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08156EBC @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
	movs r1, #3
	subs r6, #0xec
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156EC0 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	subs r2, #0xe7
	adds r0, r7, r2
	strb r4, [r0]
	subs r3, #0xce
	adds r0, r7, r3
	mov r4, sb
	str r4, [r0]
	adds r6, #4
	adds r0, r7, r6
	mov r1, r8
_08156E98:
	strb r1, [r0]
_08156E9A:
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08156EAC: .4byte Enemy_WaitPendingState
_08156EB0: .4byte 0x0000046D
_08156EB4: .4byte 0x00000553
_08156EB8: .4byte 0x00000551
_08156EBC: .4byte 0x00000552
_08156EC0: .4byte 0x00000469
