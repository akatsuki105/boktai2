	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _08229418 @ =0x03000248
	ldr r6, [r0]
	cmp r6, #0
	bne _082293B8
	ldr r0, _0822941C @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _082293B8
	b _082296FC
_082293B8:
	movs r2, #0
	ldr r0, _08229420 @ =0x00000F18
	adds r4, r6, r0
	movs r1, #0
	str r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0xd4
	str r0, [sp, #0xc]
	movs r1, #0x64
	adds r1, r1, r6
	mov sb, r1
	movs r0, #0xca
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x1c
	adds r1, r1, r6
	mov sl, r1
	adds r0, r6, #0
	adds r0, #0xc9
	str r0, [sp, #0x10]
	adds r7, r6, #0
	adds r7, #0xc4
	movs r3, #1
	mov r5, sp
_082293E8:
	ldrb r1, [r7, #5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _082293F4
	b _082296D8
_082293F4:
	movs r2, #0
	movs r0, #4
	strb r0, [r7, #5]
	movs r0, #0x74
	movs r1, #0
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	cmp r0, #1
	beq _08229438
	cmp r0, #1
	bgt _08229424
	cmp r0, #0
	beq _0822942A
	b _0822953A
	.align 2, 0
_08229418: .4byte 0x03000248
_0822941C: .4byte 0x0000BB34
_08229420: .4byte 0x00000F18
_08229424:
	cmp r0, #2
	beq _082294BC
	b _0822953A
_0822942A:
	movs r0, #0x49
	strh r0, [r7, #0x24]
	ldr r1, _08229434 @ =0x00000F16
	adds r2, r6, r1
	b _082294D2
	.align 2, 0
_08229434: .4byte 0x00000F16
_08229438:
	ldrb r0, [r7, #5]
	movs r1, #8
	orrs r0, r1
	strb r0, [r7, #5]
	movs r0, #0x49
	strh r0, [r7, #0x24]
	ldr r1, _082294A8 @ =0x00000F16
	adds r2, r6, r1
	ldrb r0, [r2]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	strh r0, [r4]
	ldrb r0, [r2]
	movs r1, #0x10
	rsbs r1, r1, #0
	mov ip, r1
	mov r1, ip
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	cmp r0, #3
	bne _08229496
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08229496
	ldr r2, _082294AC @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r2, _082294B0 @ =0x00000F42
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _082294B4 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_08229496:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _082294B8 @ =FUN_08224f74
	b _08229530
	.align 2, 0
_082294A8: .4byte 0x00000F16
_082294AC: .4byte 0x00000DEC
_082294B0: .4byte 0x00000F42
_082294B4: .4byte 0x00000DF2
_082294B8: .4byte FUN_08224f74
_082294BC:
	ldrb r0, [r7, #5]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r7, #5]
	movs r0, #0x4c
	strh r0, [r7, #0x24]
	movs r2, #1
	mov r1, sl
	strh r2, [r1, #0x10]
	ldr r0, _0822956C @ =0x00000F16
	adds r2, r6, r0
_082294D2:
	ldrb r0, [r2]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	strh r0, [r4]
	ldrb r0, [r2]
	movs r1, #0x10
	rsbs r1, r1, #0
	mov ip, r1
	mov r1, ip
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	ldrh r1, [r2]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	cmp r0, #3
	bne _08229520
	ldrb r1, [r2]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #3
	bne _08229520
	ldr r2, _08229570 @ =0x00000DEC
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r2, _08229574 @ =0x00000F42
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08229578 @ =0x00000DF2
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
_08229520:
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0822957C @ =FUN_08224dd0
_08229530:
	str r0, [r7]
	ldrb r1, [r7, #5]
	movs r0, #1
	orrs r0, r1
	strb r0, [r7, #5]
_0822953A:
	mov r4, sl
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r7, #6]
	movs r0, #0x41
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r7, #7]
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08229580
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FUN_08234cf8
	b _082295A0
	.align 2, 0
_0822956C: .4byte 0x00000F16
_08229570: .4byte 0x00000DEC
_08229574: .4byte 0x00000F42
_08229578: .4byte 0x00000DF2
_0822957C: .4byte FUN_08224dd0
_08229580:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0822958C
	b _082296FC
_0822958C:
	bl Script_GetValue
	strh r0, [r5]
	bl Script_GetValue
	subs r0, #0x40
	strh r0, [r5, #2]
	bl Script_GetValue
	strh r0, [r5, #4]
_082295A0:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _082295C4
	ldrh r0, [r5]
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r5]
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #2]
	strh r0, [r2, #2]
	ldrh r0, [r5, #2]
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #4]
	strh r0, [r2, #4]
	ldrh r0, [r5, #4]
	subs r0, #0x80
	b _082295DE
_082295C4:
	ldrh r0, [r5]
	mov r1, sb
	strh r0, [r1]
	ldrh r0, [r5]
	subs r0, #0x80
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #2]
	strh r0, [r1, #2]
	ldrh r0, [r5, #2]
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #4]
	strh r0, [r1, #4]
	ldrh r0, [r5, #4]
_082295DE:
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x1c]
	adds r0, #0x3c
	movs r5, #0
	strh r0, [r4, #0x1c]
	ldrh r0, [r4, #0x20]
	adds r0, #0x3c
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, #0x54
	strh r0, [r4, #0x1e]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08229632
	str r5, [r7, #0xc]
	mov r5, sl
	adds r5, #0xb4
	adds r4, r6, #0
	adds r4, #0xbc
	movs r2, #0xc0
	adds r2, r2, r6
	mov r8, r2
	b _08229628
_08229614:
	bl Script_GetValue
	ldr r1, [r5]
	lsls r1, r1, #2
	ldr r2, [sp, #0xc]
	adds r1, r2, r1
	str r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
_08229628:
	bl VM_GetPC
	cmp r0, #0
	bne _08229614
	b _0822964C
_08229632:
	movs r0, #1
	str r0, [r7, #0xc]
	mov r0, sp
	bl FUN_08241574
	str r0, [r7, #0x10]
	mov r5, sl
	adds r5, #0xb4
	adds r4, r6, #0
	adds r4, #0xbc
	movs r1, #0xc0
	adds r1, r1, r6
	mov r8, r1
_0822964C:
	movs r0, #0x43
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08229664
	bl Script_GetValue
	ldr r2, [sp, #8]
	adds r1, r4, r2
	str r0, [r1]
	b _0822966A
_08229664:
	ldr r2, [sp, #8]
	adds r0, r4, r2
	str r1, [r0]
_0822966A:
	movs r0, #0x61
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08229682
	bl Script_GetValue
	ldr r1, [sp, #8]
	add r1, r8
	str r0, [r1]
	b _08229688
_08229682:
	ldr r0, [sp, #8]
	add r0, r8
	str r1, [r0]
_08229688:
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x10]
	strb r0, [r1, #0x1d]
	ldrb r0, [r7, #6]
	cmp r0, #0
	bne _082296AC
	ldr r2, _082296A4 @ =0x00000F1E
	adds r1, r6, r2
	ldr r0, _082296A8 @ =0x0000FFC0
	b _082296C2
	.align 2, 0
_082296A4: .4byte 0x00000F1E
_082296A8: .4byte 0x0000FFC0
_082296AC:
	adds r2, r6, #0
	adds r2, #0x1c
	ldr r0, [sp, #8]
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	ldr r2, _082296D4 @ =0x00000F1E
	adds r1, r6, r2
	movs r0, #0x40
_082296C2:
	strh r0, [r1]
	ldr r0, [r5]
	cmp r0, #0
	ble _082296FC
_082296CA:
	subs r0, #1
	cmp r0, #0
	bne _082296CA
	b _082296FC
	.align 2, 0
_082296D4: .4byte 0x00000F1E
_082296D8:
	ldr r0, [sp, #8]
	adds r0, #0xd8
	str r0, [sp, #8]
	ldr r1, [sp, #0xc]
	adds r1, #0xd8
	str r1, [sp, #0xc]
	movs r0, #0xd8
	add sb, r0
	add r8, r0
	add sl, r0
	ldr r1, [sp, #0x10]
	adds r1, #0xd8
	str r1, [sp, #0x10]
	adds r7, #0xd8
	adds r2, #1
	cmp r2, #0xf
	bgt _082296FC
	b _082293E8
_082296FC:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
