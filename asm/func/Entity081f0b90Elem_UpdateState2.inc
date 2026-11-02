	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	mov r8, r1
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F04B4
	movs r7, #0
	movs r0, #0xf8
	add r0, r8
	mov sb, r0
	add r5, sp, #4
	mov r4, r8
	mov r6, r8
	adds r6, #0xb0
_081F03D0:
	ldr r0, [r4]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	lsls r3, r7, #6
	ldr r2, _081F0404 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _081F0408
	asrs r1, r0, #0xc
	b _081F040E
	.align 2, 0
_081F0404: .4byte gSineTable
_081F0408:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F040E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r2, _081F0430 @ =gSineTable
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _081F0434
	asrs r2, r0, #0xc
	b _081F043A
	.align 2, 0
_081F0430: .4byte gSineTable
_081F0434:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F043A:
	strh r2, [r5, #4]
	ldrh r0, [r4, #0x1c]
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #2]
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	ldrh r0, [r4, #0x20]
	adds r0, r2, r0
	strh r0, [r4, #0x20]
	cmp r7, #1
	beq _081F046A
	cmp r7, #1
	bgt _081F0460
	cmp r7, #0
	beq _081F0466
	b _081F0476
_081F0460:
	cmp r7, #2
	beq _081F0470
	b _081F0476
_081F0466:
	movs r2, #2
	b _081F0478
_081F046A:
	movs r2, #2
	movs r0, #1
	b _081F047A
_081F0470:
	movs r2, #0
	movs r0, #1
	b _081F047A
_081F0476:
	movs r2, #0
_081F0478:
	movs r0, #0
_081F047A:
	mov r3, sl
	ldr r1, [r3, #0x34]
	orrs r2, r0
	str r2, [sp]
	adds r0, r6, #0
	movs r2, #0x10
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r4, #0x2c
	adds r6, #0x10
	adds r7, #1
	cmp r7, #3
	ble _081F03D0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	strb r2, [r0]
_081F04B4:
	movs r7, #0
	movs r4, #0xf8
	add r4, r8
	mov sb, r4
	movs r0, #1
	mov ip, r0
	movs r1, #2
	mov sl, r1
	mov r3, r8
	adds r3, #0xb0
_081F04C8:
	movs r0, #0x2c
	adds r4, r7, #0
	muls r4, r0, r4
	add r4, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r3, #4]
	mov r2, ip
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, ip
	ands r0, r1
	cmp r2, r0
	beq _081F04FC
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F0504
_081F04FC:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F0504:
	str r0, [r4]
	ldrb r0, [r3, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081F0528
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F0530
_081F0528:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F0530:
	str r0, [r4]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _081F0568 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _081F05AE
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F0572
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F056C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r6, #1
	b _081F0588
	.align 2, 0
_081F0568: .4byte 0x0000FFFF
_081F056C:
	subs r0, #1
	strh r0, [r3, #8]
	b _081F0586
_081F0572:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F0586
	strh r1, [r3, #8]
	movs r6, #1
	b _081F0588
_081F0586:
	movs r6, #0
_081F0588:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F05B0
	mov r4, ip
	strb r4, [r3, #7]
	b _081F05B0
_081F05AE:
	movs r6, #0
_081F05B0:
	adds r3, #0x10
	adds r7, #1
	cmp r7, #3
	ble _081F04C8
	movs r4, #0x80
	lsls r4, r4, #1
	add r4, r8
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	cmp r6, #0
	beq _081F05E8
	movs r1, #0xa9
	lsls r1, r1, #1
	add r1, r8
	movs r0, #3
	strb r0, [r1]
	movs r1, #0xad
	lsls r1, r1, #1
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _081F05F4
_081F05E8:
	movs r1, #0xac
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F05F4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
