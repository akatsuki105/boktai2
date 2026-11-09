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
	ldr r2, _08118400 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08118404
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08118406
	.align 2, 0
_08118400: .4byte 0x0000046D
_08118404:
	movs r0, #0
_08118406:
	cmp r0, #0
	beq _0811841A
	ldr r3, _0811846C @ =0x0000046E
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, sl
	strh r1, [r0]
_0811841A:
	mov r4, sp
	adds r4, #9
	adds r0, r5, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl Enemy_SetAnimFacing
	add r0, sp, #8
	ldrb r3, [r0]
	ldrb r2, [r4]
	ldr r1, _08118470 @ =0x085AD608
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #8
	mov ip, r0
	orrs r4, r2
	ldr r1, _08118474 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _0811847C
	ldr r2, _08118478 @ =0x000004B7
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
	ldr r2, _0811846C @ =0x0000046E
	adds r7, r5, r2
	b _081184FE
	.align 2, 0
_0811846C: .4byte 0x0000046E
_08118470: .4byte 0x085AD608
_08118474: .4byte 0x0000025D
_08118478: .4byte 0x000004B7
_0811847C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r3, #8
	mov ip, r3
	ldr r3, _081184EC @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r0, _081184F0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, ip
	bne _081184B8
	ldrb r0, [r7]
	cmp r0, #0
	bne _081184B8
	cmp r4, #1
	bne _081184AA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08118502
_081184AA:
	cmp r4, #0
	bne _081184B8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08118502
_081184B8:
	mov r1, ip
	strb r1, [r2]
	movs r2, #4
	mov r8, r2
	adds r0, r4, #0
	ands r0, r2
	movs r3, #4
	cmp r0, #0
	beq _081184CC
	movs r3, #6
_081184CC:
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
	beq _081184F4
	ldr r0, [r6, #8]
	mov r3, r8
	orrs r0, r3
	b _081184FC
	.align 2, 0
_081184EC: .4byte 0x000004B7
_081184F0: .4byte 0x0000046E
_081184F4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081184FC:
	str r0, [r6, #8]
_081184FE:
	movs r0, #0
	strb r0, [r7]
_08118502:
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
	bne _081185EE
	ldr r2, _08118560 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08118564 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08118568 @ =0x0203B400
	adds r0, r0, r3
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r3, _0811856C @ =gSineTable
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
	blt _08118570
	asrs r0, r1, #0x18
	b _08118576
	.align 2, 0
_08118560: .4byte 0x030046B8
_08118564: .4byte 0x000003FF
_08118568: .4byte 0x0203B400
_0811856C: .4byte gSineTable
_08118570:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08118576:
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
	blt _08118598
	asrs r0, r2, #0x18
	b _0811859E
_08118598:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0811859E:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08118624 @ =0xFFFF0000
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r4, #0x30
	orrs r0, r4
	ldr r2, _08118628 @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _0811862C @ =0x000003FF
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08118630 @ =0x0203B400
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
_081185EE:
	ldr r2, _08118634 @ =0x000006B6
	add r2, sl
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08118638 @ =0x0000017F
	cmp r1, r0
	bgt _08118604
	adds r0, r3, #0
	adds r0, #0x10
	strh r0, [r2]
_08118604:
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	ldr r2, _0811863C @ =0x00000482
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _08118640 @ =0x0000A02F
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08118644
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08118654
	.align 2, 0
_08118624: .4byte 0xFFFF0000
_08118628: .4byte 0x0000FFFF
_0811862C: .4byte 0x000003FF
_08118630: .4byte 0x0203B400
_08118634: .4byte 0x000006B6
_08118638: .4byte 0x0000017F
_0811863C: .4byte 0x00000482
_08118640: .4byte 0x0000A02F
_08118644:
	ldr r3, _08118678 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08118654
	movs r0, #1
	strh r0, [r2]
_08118654:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0811867C
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
	b _08118694
	.align 2, 0
_08118678: .4byte 0x00000482
_0811867C:
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
_08118694:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
