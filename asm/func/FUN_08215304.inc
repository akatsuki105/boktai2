	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r7, r6, r0
	movs r1, #1
	mov r8, r1
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	mov r4, r8
	ands r1, r4
	cmp r1, #0
	beq _08215326
	movs r1, #1
_08215326:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	bne _08215334
	b _0821542C
_08215334:
	ldr r0, [r6, #0x40]
	cmp r0, #0
	bne _08215340
	adds r0, r6, #0
	bl FUN_082143c0
_08215340:
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r5, #3
	ldr r1, [r6, #0x38]
	movs r0, #2
	movs r2, #3
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r5, [r6, #0x64]
	ldr r1, [r6, #0x40]
	cmp r1, #0
	bne _082153B4
	ldr r2, _082153B0 @ =0x00000DB4
	adds r0, r6, r2
	mov r4, r8
	strh r4, [r0]
	adds r2, #6
	adds r0, r6, r2
	strh r1, [r0]
	b _0821541A
	.align 2, 0
_082153B0: .4byte 0x00000DB4
_082153B4:
	ldr r0, _082153D0 @ =gSystemSaveData
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	cmp r1, #0
	bne _082153F0
	ldr r4, _082153D4 @ =0x00000DB4
	adds r0, r6, r4
	mov r2, r8
	strh r2, [r0]
	adds r4, #6
	adds r0, r6, r4
	strh r1, [r0]
	b _0821541A
	.align 2, 0
_082153D0: .4byte gSystemSaveData
_082153D4: .4byte 0x00000DB4
_082153D8:
	ldr r1, _082153E8 @ =0x000006F4
	adds r0, r7, r1
	strh r2, [r0]
	ldr r2, _082153EC @ =0x000006FA
	adds r0, r7, r2
	strh r3, [r0]
	b _0821541A
	.align 2, 0
_082153E8: .4byte 0x000006F4
_082153EC: .4byte 0x000006FA
_082153F0:
	subs r3, r1, #1
	movs r2, #0
	ldr r4, _08215450 @ =0x00000DB6
	adds r0, r6, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _0821541A
	adds r4, r0, #0
	ldr r0, _08215454 @ =0x000007B4
	adds r1, r6, r0
_08215406:
	movs r0, #1
	ldrsb r0, [r1, r0]
	subs r0, r3, r0
	cmp r0, #0
	blt _082153D8
	adds r3, r0, #0
	adds r1, #0x34
	adds r2, #1
	cmp r2, r4
	blt _08215406
_0821541A:
	adds r0, r6, #0
	bl FUN_082151d8
	adds r0, r6, #0
	bl FUN_082152c0
	adds r0, r6, #0
	bl FUN_082152ec
_0821542C:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	bgt _08215470
	ldr r0, _08215458 @ =0x030044E0
	ldrh r3, [r0, #2]
	movs r0, #1
	adds r1, r0, #0
	ands r1, r3
	cmp r1, #0
	beq _0821545C
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	movs r1, #2
	ldr r0, [r6, #0x44]
	orrs r0, r1
	b _0821546E
	.align 2, 0
_08215450: .4byte 0x00000DB6
_08215454: .4byte 0x000007B4
_08215458: .4byte 0x030044E0
_0821545C:
	movs r2, #2
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _08215470
	str r2, [r6, #0x5c]
	str r1, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r2
_0821546E:
	str r0, [r6, #0x44]
_08215470:
	ldr r3, [r6, #0x5c]
	cmp r3, #1
	bne _08215478
	b _08215588
_08215478:
	cmp r3, #1
	bgt _08215482
	cmp r3, #0
	beq _08215490
	b _0821569C
_08215482:
	cmp r3, #2
	bne _08215488
	b _082155C4
_08215488:
	cmp r3, #0x63
	bne _0821548E
	b _08215608
_0821548E:
	b _0821569C
_08215490:
	movs r0, #2
	ldr r1, [r6, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r0, _082154D4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x88
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _082154E0
	ldr r2, _082154D8 @ =0x000006F4
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _082154C6
	ldr r4, _082154DC @ =0x000006F6
	adds r0, r7, r4
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r1]
_082154C6:
	adds r0, r6, #0
	bl FUN_082151d8
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08215512
	.align 2, 0
_082154D4: .4byte 0x030044E0
_082154D8: .4byte 0x000006F4
_082154DC: .4byte 0x000006F6
_082154E0:
	movs r0, #0x88
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08215512
	ldr r0, _08215540 @ =0x000006F4
	adds r2, r7, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r4, _08215544 @ =0x000006F6
	adds r1, r7, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r0, r1
	blt _08215506
	strh r3, [r2]
_08215506:
	adds r0, r6, #0
	bl FUN_082151d8
	movs r0, #0xdc
	bl PlaySound_082406e0
_08215512:
	ldr r0, _08215548 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08215550
	ldr r0, _0821554C @ =0x000006FA
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08215576
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r1]
	b _08215576
	.align 2, 0
_08215540: .4byte 0x000006F4
_08215544: .4byte 0x000006F6
_08215548: .4byte 0x030044E0
_0821554C: .4byte 0x000006FA
_08215550:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0821555A
	b _0821569C
_0821555A:
	ldr r4, _08215584 @ =0x000006FA
	adds r2, r7, r4
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	subs r4, #2
	adds r1, r7, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r0, r1
	blt _08215576
	strh r3, [r2]
_08215576:
	adds r0, r6, #0
	bl FUN_082152ec
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0821569C
	.align 2, 0
_08215584: .4byte 0x000006FA
_08215588:
	movs r4, #2
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r4
	cmp r1, #0
	beq _08215596
	movs r1, #1
_08215596:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082155AE
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_082156bc
_082155AE:
	ldr r0, [r6, #0x60]
	cmp r0, #0x1d
	ble _0821569C
	movs r0, #0x63
	str r0, [r6, #0x5c]
	movs r0, #0
	str r0, [r6, #0x60]
	ldr r0, [r6, #0x44]
	orrs r0, r4
	str r0, [r6, #0x44]
	b _0821569C
_082155C4:
	ldr r2, [r6, #0x44]
	adds r1, r2, #0
	ands r1, r3
	cmp r1, #0
	beq _082155D0
	movs r1, #1
_082155D0:
	movs r0, #3
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6, #0x44]
	cmp r1, #0
	beq _082155E2
	movs r0, #0xde
	bl PlaySound_082406e0
_082155E2:
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r1
	str r0, [r7, #0x68]
	ldr r0, [r6, #0x40]
	cmp r0, #0
	bne _082155FE
	adds r0, r6, #0
	bl FUN_08219f34
	b _0821569C
_082155FE:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08219f34
	b _0821569C
_08215608:
	movs r0, #2
	ldr r1, [r6, #0x44]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x44]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	ldr r0, [r7, #0x68]
	orrs r0, r1
	str r0, [r7, #0x68]
	ldr r4, [r6, #0x40]
	cmp r4, #0
	bne _08215694
	ldr r0, [r6, #0x50]
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _08215688 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0821568C @ =0x0000093E
	adds r0, r0, r1
	ldr r2, _08215690 @ =0x00000E7C
	adds r1, r6, r2
	ldr r1, [r1]
	strh r1, [r0]
	adds r0, r6, #0
	bl KillEntity
	b _082156AE
	.align 2, 0
_08215688: .4byte 0x030046A0
_0821568C: .4byte 0x0000093E
_08215690: .4byte 0x00000E7C
_08215694:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08219f34
_0821569C:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	bgt _082156AE
	adds r0, r7, #0
	adds r0, #0x60
	adds r1, r6, #0
	adds r1, #0x18
	bl FUN_082372cc
_082156AE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
