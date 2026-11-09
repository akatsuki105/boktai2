	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _0814C2F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814C2F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814C2FA
	.align 2, 0
_0814C2F4: .4byte 0x0000046D
_0814C2F8:
	movs r0, #0
_0814C2FA:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _0814C308
	b _0814C78E
_0814C308:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r3, _0814C358 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _0814C35C
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0814C35C
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _0814C364
	.align 2, 0
_0814C358: .4byte 0x0000046A
_0814C35C:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_0814C364:
	cmp r1, #0
	blt _0814C36C
	asrs r0, r1, #1
	b _0814C372
_0814C36C:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0814C372:
	cmp r2, r0
	bne _0814C3FE
	ldr r2, _0814C3E4 @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0814C3F4
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0814C3E8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _0814C3EC @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _0814C3F0 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _0814C958
	.align 2, 0
_0814C3E4: .4byte 0x0000046B
_0814C3E8: .4byte 0x00000469
_0814C3EC: .4byte 0x0000046A
_0814C3F0: .4byte 0x000005BC
_0814C3F4:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _0814C958
_0814C3FE:
	cmp r2, #1
	beq _0814C4BC
	cmp r2, #1
	bgt _0814C40C
	cmp r2, #0
	beq _0814C41A
	b _0814C786
_0814C40C:
	cmp r2, #2
	bne _0814C412
	b _0814C594
_0814C412:
	cmp r2, #3
	bne _0814C418
	b _0814C664
_0814C418:
	b _0814C786
_0814C41A:
	subs r0, r1, #2
	cmp r0, #3
	bhi _0814C46C
	movs r2, #0xd
	ldr r3, _0814C440 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C448
	ldr r1, _0814C444 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _0814C686
	.align 2, 0
_0814C440: .4byte 0x0000025D
_0814C444: .4byte 0x000004B7
_0814C448:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xe
	ldr r3, _0814C464 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C468 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	beq _0814C462
	b _0814C6C2
_0814C462:
	b _0814C6B2
	.align 2, 0
_0814C464: .4byte 0x000004B7
_0814C468: .4byte 0x0000046E
_0814C46C:
	movs r2, #0xd
	ldr r1, _0814C490 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C498
	ldr r3, _0814C494 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #0
	b _0814C71E
	.align 2, 0
_0814C490: .4byte 0x0000025D
_0814C494: .4byte 0x000004B7
_0814C498:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	ldr r1, _0814C4B4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C4B8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	beq _0814C4B0
	b _0814C75C
_0814C4B0:
	b _0814C74C
	.align 2, 0
_0814C4B4: .4byte 0x000004B7
_0814C4B8: .4byte 0x0000046E
_0814C4BC:
	subs r0, r1, #4
	cmp r0, #3
	bhi _0814C510
	movs r2, #0xd
	ldr r3, _0814C4E4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C4EC
	ldr r1, _0814C4E8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _0814C686
	.align 2, 0
_0814C4E4: .4byte 0x0000025D
_0814C4E8: .4byte 0x000004B7
_0814C4EC:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xf
	ldr r3, _0814C508 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C50C @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _0814C506
	b _0814C6C2
_0814C506:
	b _0814C6B2
	.align 2, 0
_0814C508: .4byte 0x000004B7
_0814C50C: .4byte 0x0000046E
_0814C510:
	movs r2, #0xd
	ldr r1, _0814C538 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C544
	ldr r1, _0814C53C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #3
	bl AuxAnim_SetAnim
	ldr r2, _0814C540 @ =0x0000046E
	adds r6, r5, r2
	b _0814C774
	.align 2, 0
_0814C538: .4byte 0x0000025D
_0814C53C: .4byte 0x000004B7
_0814C540: .4byte 0x0000046E
_0814C544:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0x10
	ldr r3, _0814C58C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C590 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _0814C56E
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C56E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0814C56E
	b _0814C778
_0814C56E:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _0814C774
	.align 2, 0
_0814C58C: .4byte 0x000004B7
_0814C590: .4byte 0x0000046E
_0814C594:
	subs r0, r1, #1
	cmp r0, #4
	bls _0814C614
	movs r2, #0xd
	ldr r3, _0814C5C0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C5C8
	ldr r1, _0814C5C4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #3
	b _0814C686
	.align 2, 0
_0814C5C0: .4byte 0x0000025D
_0814C5C4: .4byte 0x000004B7
_0814C5C8:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0x10
	ldr r3, _0814C60C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C610 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _0814C5F2
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C5F2
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0814C5F2
	b _0814C6E2
_0814C5F2:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	b _0814C6DE
	.align 2, 0
_0814C60C: .4byte 0x000004B7
_0814C610: .4byte 0x0000046E
_0814C614:
	movs r2, #0xd
	ldr r1, _0814C638 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C640
	ldr r3, _0814C63C @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #2
	b _0814C71E
	.align 2, 0
_0814C638: .4byte 0x0000025D
_0814C63C: .4byte 0x000004B7
_0814C640:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xf
	ldr r1, _0814C65C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C660 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _0814C65A
	b _0814C75C
_0814C65A:
	b _0814C74C
	.align 2, 0
_0814C65C: .4byte 0x000004B7
_0814C660: .4byte 0x0000046E
_0814C664:
	cmp r1, #3
	bhi _0814C6FC
	movs r2, #0xd
	ldr r3, _0814C690 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C69C
	ldr r1, _0814C694 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_0814C686:
	bl AuxAnim_SetAnim
	ldr r2, _0814C698 @ =0x0000046E
	adds r6, r5, r2
	b _0814C6DE
	.align 2, 0
_0814C690: .4byte 0x0000025D
_0814C694: .4byte 0x000004B7
_0814C698: .4byte 0x0000046E
_0814C69C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _0814C6F4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C6F8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	bne _0814C6C2
_0814C6B2:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C6C2
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0814C6E2
_0814C6C2:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0814C6DE:
	movs r0, #0
	strb r0, [r6]
_0814C6E2:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0814C786
	.align 2, 0
_0814C6F4: .4byte 0x000004B7
_0814C6F8: .4byte 0x0000046E
_0814C6FC:
	movs r2, #0xd
	ldr r1, _0814C728 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C734
	ldr r3, _0814C72C @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #1
_0814C71E:
	bl AuxAnim_SetAnim
	ldr r0, _0814C730 @ =0x0000046E
	adds r6, r5, r0
	b _0814C774
	.align 2, 0
_0814C728: .4byte 0x0000025D
_0814C72C: .4byte 0x000004B7
_0814C730: .4byte 0x0000046E
_0814C734:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xe
	ldr r1, _0814C7B4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C7B8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	bne _0814C75C
_0814C74C:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C75C
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0814C778
_0814C75C:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_0814C774:
	movs r0, #0
	strb r0, [r6]
_0814C778:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0814C7BC @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814C786:
	ldr r2, _0814C7B8 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0814C78E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #1
	bne _0814C7C8
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814C7C0
	mov r1, r8
	ldrb r0, [r1, #5]
	adds r0, #0x20
	strb r0, [r1, #5]
	b _0814C7C8
	.align 2, 0
_0814C7B4: .4byte 0x000004B7
_0814C7B8: .4byte 0x0000046E
_0814C7BC: .4byte 0xFFFEFFFF
_0814C7C0:
	mov r2, r8
	ldrb r0, [r2, #5]
	subs r0, #0x20
	strb r0, [r2, #5]
_0814C7C8:
	ldr r3, _0814C7F8 @ =0x00000482
	adds r2, r5, r3
	ldrh r6, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0814C7DE
	movs r0, #3
	strh r0, [r2]
_0814C7DE:
	ldr r1, _0814C7FC @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814C800
	ldr r3, _0814C7F8 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0814C810
	.align 2, 0
_0814C7F8: .4byte 0x00000482
_0814C7FC: .4byte 0x0000A02F
_0814C800:
	ldr r1, _0814C834 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0814C810
	movs r0, #1
	strh r0, [r2]
_0814C810:
	ldr r3, _0814C838 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C83C
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
	b _0814C854
	.align 2, 0
_0814C834: .4byte 0x00000482
_0814C838: .4byte 0x0000025D
_0814C83C:
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
_0814C854:
	ldr r1, _0814C910 @ =0x00000482
	adds r0, r5, r1
	movs r7, #0
	movs r2, #0
	mov r8, r2
	strh r6, [r0]
	ldr r3, _0814C914 @ =0x0000046E
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814C958
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814C88A
	rsbs r1, r1, #0
_0814C88A:
	cmp r1, #0
	bgt _0814C928
	ldr r1, _0814C918 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814C958
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0814C91C @ =0x0000046A
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0814C920 @ =0x000005BC
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0x1b
	ldr r3, _0814C924 @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r3, r8
	strh r3, [r0]
	b _0814C958
	.align 2, 0
_0814C910: .4byte 0x00000482
_0814C914: .4byte 0x0000046E
_0814C918: .4byte 0x0000046B
_0814C91C: .4byte 0x0000046A
_0814C920: .4byte 0x000005BC
_0814C924: .4byte 0x0000046D
_0814C928:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #2
	ldr r0, _0814C968 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814C96C @ =0x0000046B
	adds r0, r5, r1
	strb r7, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	mov r1, r8
	strh r1, [r0]
_0814C958:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814C968: .4byte 0x0000046D
_0814C96C: .4byte 0x0000046B
