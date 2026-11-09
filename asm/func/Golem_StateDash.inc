	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	mov sl, r7
	ldr r2, _081186D4 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081186D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081186DA
	.align 2, 0
_081186D4: .4byte 0x0000046D
_081186D8:
	movs r0, #0
_081186DA:
	cmp r0, #0
	beq _081186E6
	adds r0, r7, #0
	movs r1, #4
	bl PlayGolemSound
_081186E6:
	adds r0, r7, #0
	movs r1, #0x10
	bl Enemy_PlayAnim
	movs r6, #0x20
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
	subs r3, #0xa
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [sp, #0x2c]
	ldr r1, _081187E4 @ =0x000006B6
	adds r3, r0, r1
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r4, _081187E8 @ =gSineTable
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #0x10
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	strh r0, [r7, #0x10]
	movs r0, #0
	ldrsh r1, [r3, r0]
	mov r2, sl
	ldrb r0, [r2, #5]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	asrs r0, r0, #0x10
	ldrh r1, [r7, #0x14]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r4, #3
	ands r5, r4
	cmp r5, #0
	bne _081187AC
	ldrh r0, [r2, #0x10]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	ldr r3, _081187EC @ =0xFFFF0000
	ldr r2, _081187F0 @ =0x0000FFFF
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r5, sl
	ldrh r0, [r5, #0x14]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r6
	ands r0, r2
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r6
	str r0, [r2, #4]
	mov r0, sl
	adds r0, #8
	str r4, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0xc
	movs r3, #1
	bl DustManager_Spawn
_081187AC:
	adds r0, r7, #0
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081187BC
	b _0811899E
_081187BC:
	ldr r0, [sp, #0x2c]
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, [sp, #0x2c]
	ldr r5, _081187F4 @ =0x000006E2
	adds r1, r3, r5
	movs r0, #0x14
	strh r0, [r1]
	mov r1, sl
	movs r2, #0x14
	ldrsh r0, [r1, r2]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	blt _081187F8
	asrs r0, r1, #0x12
	b _081187FE
	.align 2, 0
_081187E4: .4byte 0x000006B6
_081187E8: .4byte gSineTable
_081187EC: .4byte 0xFFFF0000
_081187F0: .4byte 0x0000FFFF
_081187F4: .4byte 0x000006E2
_081187F8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081187FE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08118844 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x1c]
	ldr r3, _08118848 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0811884C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r5, _08118850 @ =0x0203B400
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08118854 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	mov r1, sl
	movs r2, #0x10
	ldrsh r0, [r1, r2]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	mov ip, r3
	cmp r0, #0
	blt _08118858
	asrs r0, r1, #0x12
	b _0811885E
	.align 2, 0
_08118844: .4byte 0xFFFF0000
_08118848: .4byte 0x030046B8
_0811884C: .4byte 0x000003FF
_08118850: .4byte 0x0203B400
_08118854: .4byte 0x0000FFFF
_08118858:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0811885E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08118924 @ =0xFFFF0000
	mov r8, r3
	add r5, sp, #0x1c
	mov sb, r5
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	ldr r6, _08118928 @ =0x0203B400
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _0811892C @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #0xf
	ldr r0, [sp, #0x24]
	mov r5, r8
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r3, _08118930 @ =0x0000FFFF
	ldr r0, [sp, #0x24]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	ands r2, r4
	mov r1, ip
	str r2, [r1]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	movs r2, #3
	ands r1, r2
	adds r1, #0xf
	add r5, sp, #0x24
	ldr r0, [r5, #4]
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	movs r0, #3
	ands r4, r0
	adds r4, #4
	adds r0, r7, #0
	bl FUN_080f8abc
	adds r1, r0, #0
	mov r2, sl
	adds r2, #8
	str r5, [sp]
	movs r0, #0x2d
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r3, sb
	bl ScatterEffect_Spawn
	adds r0, r7, #0
	movs r1, #5
	bl PlayGolemSound
	ldr r2, [sp, #0x2c]
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r0, r2, r3
	ldrh r4, [r0]
	cmp r4, #0
	beq _08118938
	ldr r5, _08118934 @ =0x0000046B
	adds r1, r7, r5
	movs r0, #1
	strb r0, [r1]
	b _0811899E
	.align 2, 0
_08118924: .4byte 0xFFFF0000
_08118928: .4byte 0x0203B400
_0811892C: .4byte 0x000003FF
_08118930: .4byte 0x0000FFFF
_08118934: .4byte 0x0000046B
_08118938:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r3, #0
	movs r0, #0xb4
	strh r0, [r1]
	movs r2, #1
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r5, #3
	strb r5, [r0]
	adds r1, #1
	adds r0, r7, r1
	strb r3, [r0]
	ldr r5, _081189B0 @ =0x0000046A
	adds r0, r7, r5
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _081189B4 @ =0x00000594
	adds r0, r7, r1
	ldr r1, [r0]
	adds r5, #1
	adds r0, r7, r5
	strb r2, [r0]
	ldr r2, _081189B8 @ =0x0000046B
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081189BC @ =0x00000553
	adds r0, r7, r3
	movs r5, #7
	strb r5, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
_0811899E:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081189B0: .4byte 0x0000046A
_081189B4: .4byte 0x00000594
_081189B8: .4byte 0x0000046B
_081189BC: .4byte 0x00000553
