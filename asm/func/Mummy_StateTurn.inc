	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov sl, r0
	ldr r0, _081224E0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081224E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081224E6
	.align 2, 0
_081224E0: .4byte 0x0000046D
_081224E4:
	movs r0, #0
_081224E6:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081224F4
	b _081229EA
_081224F4:
	mov r2, r8
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	mov r3, r8
	strb r0, [r3, #5]
	ldrb r0, [r3, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r1, _08122544 @ =0x0000046A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08122548
	adds r1, #0x16
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _08122548
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _08122550
	.align 2, 0
_08122544: .4byte 0x0000046A
_08122548:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_08122550:
	asrs r0, r1, #1
	cmp r2, r0
	bne _081225BE
	ldr r2, _081225A4 @ =0x0000046B
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
	beq _081225B4
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081225A8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081225AC @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081225B0 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	b _08122B4E
	.align 2, 0
_081225A4: .4byte 0x0000046B
_081225A8: .4byte 0x00000469
_081225AC: .4byte 0x0000046A
_081225B0: .4byte 0x000005BC
_081225B4:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	b _08122BB0
_081225BE:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, #1
	bne _081225CC
	b _08122700
_081225CC:
	cmp r2, #1
	bgt _081225D6
	cmp r2, #0
	beq _081225E4
	b _081229E2
_081225D6:
	cmp r2, #2
	bne _081225DC
	b _08122808
_081225DC:
	cmp r2, #3
	bne _081225E2
	b _081228DC
_081225E2:
	b _081229E2
_081225E4:
	subs r0, r1, #2
	cmp r0, #3
	bhi _0812267C
	movs r2, #2
	ldr r1, _08122614 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08122620
	ldr r1, _08122618 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r2, _0812261C @ =0x0000046E
	adds r6, r5, r2
	b _08122664
	.align 2, 0
_08122614: .4byte 0x0000025D
_08122618: .4byte 0x000004B7
_0812261C: .4byte 0x0000046E
_08122620:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _08122674 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08122678 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _08122648
	ldrb r0, [r6]
	cmp r0, #0
	bne _08122648
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08122668
_08122648:
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
_08122664:
	movs r0, #0
	strb r0, [r6]
_08122668:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	b _08122948
	.align 2, 0
_08122674: .4byte 0x000004B7
_08122678: .4byte 0x0000046E
_0812267C:
	movs r2, #2
	ldr r1, _081226A4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081226B0
	ldr r1, _081226A8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r2, _081226AC @ =0x0000046E
	adds r6, r5, r2
	b _081229D0
	.align 2, 0
_081226A4: .4byte 0x0000025D
_081226A8: .4byte 0x000004B7
_081226AC: .4byte 0x0000046E
_081226B0:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081226F8 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081226FC @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _081226D8
	ldrb r0, [r6]
	cmp r0, #0
	bne _081226D8
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081226D8
	b _081229D4
_081226D8:
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
	b _081229D0
	.align 2, 0
_081226F8: .4byte 0x000004B7
_081226FC: .4byte 0x0000046E
_08122700:
	subs r0, r1, #4
	cmp r0, #3
	bhi _08122798
	movs r2, #2
	ldr r3, _08122730 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0812273C
	ldr r1, _08122734 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	bl AuxAnim_SetAnim
	ldr r2, _08122738 @ =0x0000046E
	adds r6, r5, r2
	b _0812277E
	.align 2, 0
_08122730: .4byte 0x0000025D
_08122734: .4byte 0x000004B7
_08122738: .4byte 0x0000046E
_0812273C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #4
	ldr r3, _08122790 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08122794 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #4
	bne _08122762
	ldrb r0, [r6]
	cmp r0, #0
	bne _08122762
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08122782
_08122762:
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
_0812277E:
	movs r0, #0
	strb r0, [r6]
_08122782:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	b _08122948
	.align 2, 0
_08122790: .4byte 0x000004B7
_08122794: .4byte 0x0000046E
_08122798:
	movs r1, #2
	ldr r2, _081227C0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081227C8
	ldr r3, _081227C4 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	b _081227F0
	.align 2, 0
_081227C0: .4byte 0x0000025D
_081227C4: .4byte 0x000004B7
_081227C8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08122800 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081227F0:
	ldr r3, _08122804 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081229DA
	.align 2, 0
_08122800: .4byte 0x000004B7
_08122804: .4byte 0x0000046E
_08122808:
	subs r0, r1, #2
	cmp r0, #3
	bls _0812286C
	movs r1, #2
	ldr r2, _08122838 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122840
	ldr r3, _0812283C @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	b _08122936
	.align 2, 0
_08122838: .4byte 0x0000025D
_0812283C: .4byte 0x000004B7
_08122840:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08122868 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _08122934
	.align 2, 0
_08122868: .4byte 0x000004B7
_0812286C:
	movs r2, #4
	ldr r1, _08122894 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812289C
	ldr r3, _08122898 @ =0x000004B7
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl AuxAnim_SetAnim
	b _081228C2
	.align 2, 0
_08122894: .4byte 0x0000025D
_08122898: .4byte 0x000004B7
_0812289C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081228D4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #4
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081228C2:
	ldr r2, _081228D8 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	b _081229DA
	.align 2, 0
_081228D4: .4byte 0x000004B7
_081228D8: .4byte 0x0000046E
_081228DC:
	cmp r1, #3
	bhi _08122958
	movs r1, #2
	ldr r2, _08122908 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122910
	ldr r3, _0812290C @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	b _08122936
	.align 2, 0
_08122908: .4byte 0x0000025D
_0812290C: .4byte 0x000004B7
_08122910:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _08122950 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08122934:
	str r0, [r4, #8]
_08122936:
	ldr r3, _08122954 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
_08122948:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081229E2
	.align 2, 0
_08122950: .4byte 0x000004B7
_08122954: .4byte 0x0000046E
_08122958:
	movs r2, #2
	ldr r1, _08122984 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122990
	ldr r3, _08122988 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl AuxAnim_SetAnim
	ldr r0, _0812298C @ =0x0000046E
	adds r6, r5, r0
	b _081229D0
	.align 2, 0
_08122984: .4byte 0x0000025D
_08122988: .4byte 0x000004B7
_0812298C: .4byte 0x0000046E
_08122990:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #3
	ldr r1, _08122A1C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08122A20 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _081229B8
	ldrb r0, [r6]
	cmp r0, #0
	bne _081229B8
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081229D4
_081229B8:
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
_081229D0:
	movs r0, #0
	strb r0, [r6]
_081229D4:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_081229DA:
	ldr r1, _08122A24 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081229E2:
	ldr r2, _08122A20 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081229EA:
	mov r3, sl
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _08122A4C
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r3, r8
	ldrb r2, [r3, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _08122A10
	rsbs r0, r0, #0
_08122A10:
	cmp r0, #0x15
	bgt _08122A28
	mov r0, r8
	strb r1, [r0, #5]
	b _08122A4C
	.align 2, 0
_08122A1C: .4byte 0x000004B7
_08122A20: .4byte 0x0000046E
_08122A24: .4byte 0xFFFEFFFF
_08122A28:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08122A44
	adds r0, r2, #0
	adds r0, #0x15
	mov r1, r8
	strb r0, [r1, #5]
	b _08122A4C
_08122A44:
	adds r0, r2, #0
	subs r0, #0x15
	mov r2, r8
	strb r0, [r2, #5]
_08122A4C:
	ldr r1, _08122A64 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08122A6C
	ldr r0, _08122A68 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08122A7C
	.align 2, 0
_08122A64: .4byte 0x0000A02F
_08122A68: .4byte 0x00000482
_08122A6C:
	ldr r1, _08122AA0 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08122A7C
	movs r0, #1
	strh r0, [r2]
_08122A7C:
	ldr r3, _08122AA4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122AA8
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
	b _08122AC0
	.align 2, 0
_08122AA0: .4byte 0x00000482
_08122AA4: .4byte 0x0000025D
_08122AA8:
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
_08122AC0:
	ldr r1, _08122B70 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08122BB0
	mov r2, r8
	ldrb r0, [r2, #5]
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
	bge _08122AEC
	rsbs r1, r1, #0
_08122AEC:
	cmp r1, #0
	bgt _08122B80
	ldr r1, _08122B74 @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
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
	beq _08122BB0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08122B78 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08122B7C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_08122B4E:
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
	b _08122BB0
	.align 2, 0
_08122B70: .4byte 0x0000046E
_08122B74: .4byte 0x0000046B
_08122B78: .4byte 0x0000046A
_08122B7C: .4byte 0x000005BC
_08122B80:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _08122BC0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08122BC4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08122BB0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08122BC0: .4byte 0x0000046D
_08122BC4: .4byte 0x0000046B
