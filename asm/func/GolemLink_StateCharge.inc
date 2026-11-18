	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	str r5, [sp, #0x1c]
	ldr r2, _081BB514 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BB518
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BB51A
	.align 2, 0
_081BB514: .4byte 0x0000046D
_081BB518:
	movs r0, #0
_081BB51A:
	cmp r0, #0
	beq _081BB52E
	ldr r3, _081BB580 @ =0x0000046E
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
_081BB52E:
	mov r4, sp
	adds r4, #9
	adds r0, r5, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _081BB584 @ =0x085ADFA8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _081BB588 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _081BB590
	ldr r2, _081BB58C @ =0x000004B7
	adds r0, r5, r2
	mov r1, ip
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #8
	bl AuxAnim_SetAnim
	ldr r2, _081BB580 @ =0x0000046E
	adds r7, r5, r2
	b _081BB612
	.align 2, 0
_081BB580: .4byte 0x0000046E
_081BB584: .4byte 0x085ADFA8
_081BB588: .4byte 0x0000025D
_081BB58C: .4byte 0x000004B7
_081BB590:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _081BB600 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081BB604 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _081BB5CC
	ldrb r0, [r7]
	cmp r0, #0
	bne _081BB5CC
	cmp r4, #1
	bne _081BB5BE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081BB616
_081BB5BE:
	cmp r4, #0
	bne _081BB5CC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081BB616
_081BB5CC:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081BB5E0
	movs r3, #6
_081BB5E0:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	mov r2, ip
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081BB608
	ldr r0, [r6, #8]
	mov r3, r8
	orrs r0, r3
	b _081BB610
	.align 2, 0
_081BB600: .4byte 0x000004B7
_081BB604: .4byte 0x0000046E
_081BB608:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081BB610:
	str r0, [r6, #8]
_081BB612:
	movs r0, #0
	strb r0, [r7]
_081BB616:
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	mov r1, sb
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	bne _081BB702
	ldr r2, _081BB674 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081BB678 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081BB67C @ =0x0203B400
	adds r0, r0, r3
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r3, _081BB680 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	adds r6, r2, #0
	cmp r0, #0
	blt _081BB684
	asrs r0, r1, #0x18
	b _081BB68A
	.align 2, 0
_081BB674: .4byte 0x030046B8
_081BB678: .4byte 0x000003FF
_081BB67C: .4byte 0x0203B400
_081BB680: .4byte gSineTable
_081BB684:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081BB68A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r2, r0, #0x10
	asrs r0, r2, #0x10
	cmp r0, #0
	blt _081BB6AC
	asrs r0, r2, #0x18
	b _081BB6B2
_081BB6AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081BB6B2:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _081BB738 @ =0xFFFF0000
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r4, #0x30
	orrs r0, r4
	ldr r2, _081BB73C @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _081BB740 @ =0x000003FF
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _081BB744 @ =0x0203B400
	adds r0, r0, r3
	ldrh r3, [r0]
	movs r0, #1
	ands r3, r0
	adds r3, #2
	ldr r0, [sp, #0x1c]
	adds r0, #8
	str r3, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #2
	bl DustManager_Spawn
_081BB702:
	ldr r2, _081BB748 @ =0x000006B6
	add r2, sl
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081BB74C @ =0x0000017F
	cmp r1, r0
	bgt _081BB718
	adds r0, r3, #0
	adds r0, #0x10
	strh r0, [r2]
_081BB718:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _081BB750 @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081BB754 @ =0x0000A02F
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081BB758
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081BB768
	.align 2, 0
_081BB738: .4byte 0xFFFF0000
_081BB73C: .4byte 0x0000FFFF
_081BB740: .4byte 0x000003FF
_081BB744: .4byte 0x0203B400
_081BB748: .4byte 0x000006B6
_081BB74C: .4byte 0x0000017F
_081BB750: .4byte 0x00000482
_081BB754: .4byte 0x0000A02F
_081BB758:
	ldr r3, _081BB78C @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081BB768
	movs r0, #1
	strh r0, [r2]
_081BB768:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _081BB790
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _081BB7A8
	.align 2, 0
_081BB78C: .4byte 0x00000482
_081BB790:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_081BB7A8:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
