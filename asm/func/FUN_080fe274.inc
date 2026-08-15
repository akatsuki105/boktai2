	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	str r0, [sp, #0x48]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _080FE2A0 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FE2A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FE2A6
	.align 2, 0
_080FE2A0: .4byte 0x0000046D
_080FE2A4:
	movs r0, #0
_080FE2A6:
	cmp r0, #0
	beq _080FE33E
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r4, _080FE3D0 @ =0x0000046E
	adds r0, r7, r4
	movs r4, #0
	strb r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e64b4
	ldr r1, [sp, #0x48]
	ldr r0, [r1]
	movs r1, #2
	orrs r0, r1
	ldr r2, [sp, #0x48]
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_080e8360
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080FE310
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080FE310:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _080FE3D4 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _080FE3D8 @ =0x0000021E
	adds r0, r7, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	subs r1, #0x1c
	adds r0, r7, r1
	strh r4, [r0]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080FE33E:
	adds r0, r7, #0
	bl FUN_080e499c
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _080FE3B4
	movs r5, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _080FE3B4
	ldr r3, _080FE3DC @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _080FE3E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x30]
	add r2, sp, #0x30
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	ldr r3, _080FE3E4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080FE3E8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _080FE3EC @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r4, #0xa
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_080ddcc8
_080FE3B4:
	cmp r6, #0x22
	bgt _080FE3BE
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0xe]
_080FE3BE:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #2
	bhi _080FE3F0
	movs r0, #0x46
	ldr r2, [sp, #0x48]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	b _080FE3F8
	.align 2, 0
_080FE3D0: .4byte 0x0000046E
_080FE3D4: .4byte 0xFFFEBE3F
_080FE3D8: .4byte 0x0000021E
_080FE3DC: .4byte 0xFFFF0000
_080FE3E0: .4byte 0x0000FFFF
_080FE3E4: .4byte 0x030046B8
_080FE3E8: .4byte 0x000003FF
_080FE3EC: .4byte 0x0203B400
_080FE3F0:
	movs r0, #0x40
	ldr r4, [sp, #0x48]
	strb r0, [r4, #8]
	strb r0, [r4, #9]
_080FE3F8:
	ldr r6, _080FE630 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FE404
	b _080FE6DE
_080FE404:
	ldr r1, _080FE634 @ =0x0000046B
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	subs r1, #0x6b
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	ldr r6, _080FE638 @ =0x000001DF
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	cmp r0, #0
	beq _080FE424
	b _080FE5A6
_080FE424:
	adds r0, r7, #0
	bl FUN_080e6658
	ldr r2, _080FE63C @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _080FE640 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r5, sp, #0x38
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _080FE644 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080FE648 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080FE64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r6, #3
	ands r1, r6
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r2, #0x14
	mov r8, r2
	str r2, [sp, #4]
	movs r0, #2
	mov sl, r0
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080FE648 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080FE64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080FE648 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080FE64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080FE648 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080FE64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080FE648 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080FE64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r2, sb
	str r2, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080FE648 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080FE64C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r4, #3
	ands r1, r4
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r4, sl
	str r4, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	cmp r0, #4
	beq _080FE5A0
	cmp r0, #1
	beq _080FE5A0
	cmp r0, #5
	beq _080FE5A0
	cmp r0, #7
	beq _080FE5A0
	cmp r0, #6
	beq _080FE5A0
	cmp r0, #0x18
	bne _080FE5A6
_080FE5A0:
	movs r0, #0xe5
	bl PlaySound_082406e0
_080FE5A6:
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r0, [r2]
	cmp r0, #0
	beq _080FE608
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x14]
	movs r4, #0xc
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x18]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r4, #0xd2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r6, #0x94
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _080FE63C @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x40
	add r0, sp, #0x10
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_080FE608:
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _080FE654
	ldr r0, _080FE650 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _080FE666
	.align 2, 0
_080FE630: .4byte 0x0000046E
_080FE634: .4byte 0x0000046B
_080FE638: .4byte 0x000001DF
_080FE63C: .4byte 0xFFFF0000
_080FE640: .4byte 0x0000FFFF
_080FE644: .4byte 0x030046B8
_080FE648: .4byte 0x000003FF
_080FE64C: .4byte 0x0203B400
_080FE650: .4byte 0x030046A0
_080FE654:
	ldr r0, _080FE6F0 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_080FE666:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #0
	movs r3, #0
	strh r3, [r0]
	movs r0, #0x40
	ldr r2, [sp, #0x48]
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _080FE6F4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _080FE6F8 @ =0x0000046D
	adds r0, r7, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r4, _080FE6FC @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _080FE700 @ =0x00000484
	adds r0, r7, r2
	str r3, [r0]
	adds r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r7, r6
	bl FUN_080136b4
_080FE6DE:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FE6F0: .4byte 0x030046A0
_080FE6F4: .4byte FUN_080e48d0
_080FE6F8: .4byte 0x0000046D
_080FE6FC: .4byte 0x00000469
_080FE700: .4byte 0x00000484
