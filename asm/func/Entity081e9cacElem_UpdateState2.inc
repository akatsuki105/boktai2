	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _081E9380 @ =0x030001B4
	ldr r0, [r0]
	mov sb, r0
	adds r5, r6, #0
	adds r5, #0xbc
	adds r7, r6, #0
	adds r7, #0x64
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081E932A
	ldrh r1, [r6, #0xc]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	ldrh r0, [r6, #0xe]
	ldrh r3, [r6, #6]
	adds r0, r0, r3
	strh r0, [r6, #6]
	ldrh r0, [r6, #0x10]
	ldrh r2, [r6, #8]
	adds r0, r0, r2
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x80
	strh r1, [r0]
	ldrh r0, [r6, #6]
	adds r1, r6, #0
	adds r1, #0x82
	strh r0, [r1]
	ldrh r1, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x84
	strh r1, [r0]
_081E932A:
	adds r0, r6, #0
	bl Entity081e9cacElem_UpdateHitPos
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl Entity081e9cac_GetAnimVariant
	mov r3, sb
	ldr r1, [r3, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9384
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E938C
	.align 2, 0
_081E9380: .4byte 0x030001B4
_081E9384:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E938C:
	str r0, [r6, #0x64]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E93B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E93B8
_081E93B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E93B8:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E93F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _081E9428
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E93F4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E93E8
	ldrb r0, [r5, #5]
_081E93E8:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9404
	.align 2, 0
_081E93F0: .4byte 0x0000FFFF
_081E93F4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9404
	strh r1, [r5, #8]
_081E9404:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9428
	movs r0, #1
	strb r0, [r5, #7]
_081E9428:
	adds r0, r6, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r1, #1
	bne _081E9438
	b _081E953E
_081E9438:
	adds r7, r6, #0
	adds r7, #0x90
	adds r4, r6, #0
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E9474
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _081E9480
_081E9474:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081E9480:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E94A2
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E94AA
_081E94A2:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E94AA:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E94E4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E952A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E94EE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E94E8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9504
	.align 2, 0
_081E94E4: .4byte 0x0000FFFF
_081E94E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9502
_081E94EE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9502
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9504
_081E9502:
	movs r2, #0
_081E9504:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E952C
	movs r0, #1
	strb r0, [r4, #7]
	b _081E952C
_081E952A:
	movs r2, #0
_081E952C:
	cmp r2, #0
	beq _081E953E
	mov r3, ip
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r0, r8
	strh r1, [r0]
_081E953E:
	adds r5, r6, #0
	adds r5, #0xec
	ldrh r0, [r5]
	cmp r0, #0
	beq _081E955E
	adds r4, r6, #0
	adds r4, #0x14
	adds r1, r6, #0
	adds r1, #0xdc
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081E955E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	adds r0, r6, #0
	bl Entity081e9cacElem_CheckFloor
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9596
	adds r1, r6, #0
	adds r1, #0xf0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081E9582
	subs r0, r2, #1
	b _081E958C
_081E9582:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
_081E958C:
	strh r0, [r1]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_081e8f2c
_081E9596:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
