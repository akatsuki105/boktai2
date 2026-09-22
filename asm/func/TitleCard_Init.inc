	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r1, _0800F5D4 @ =0x03004250
	movs r4, #0
	ldr r0, _0800F5D8 @ =0x00001084
	strh r0, [r1]
	ldr r1, _0800F5DC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	str r4, [sp, #0x10]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	strh r4, [r0]
	strh r4, [r5, #0x38]
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x44
	strh r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x46
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800F5E0
	adds r1, #4
	movs r0, #0x40
	strh r0, [r1]
	b _0800F5E6
	.align 2, 0
_0800F5D4: .4byte 0x03004250
_0800F5D8: .4byte 0x00001084
_0800F5DC: .4byte 0xFFFF0000
_0800F5E0:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r4, [r0]
_0800F5E6:
	adds r1, r5, #0
	adds r1, #0x4e
	movs r0, #0x40
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0x80
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x4c
	strh r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x73
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #0x40]
	movs r0, #0x6f
	adds r1, r4, #0
	bl VM_GetKeywordValue
	ldr r2, _0800F688 @ =0x000002DE
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	ldr r3, _0800F68C @ =0x000002DF
	adds r1, r5, r3
	strb r0, [r1]
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0xb8
	lsls r4, r4, #2
	adds r1, r5, r4
	strb r0, [r1]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800F662
	bl FUN_0823d340
_0800F662:
	str r0, [r5, #0x50]
	movs r0, #0x79
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0800F694
	bl Script_GetValue
	ldr r7, _0800F690 @ =0x000002DA
	adds r1, r5, r7
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _0800F6A2
	.align 2, 0
_0800F688: .4byte 0x000002DE
_0800F68C: .4byte 0x000002DF
_0800F690: .4byte 0x000002DA
_0800F694:
	ldr r3, _0800F6B8 @ =0x000002DA
	adds r0, r5, r3
	strh r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
_0800F6A2:
	ldr r0, _0800F6BC @ =0x0000CB05
	ldr r1, _0800F6C0 @ =0x0000E89F
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0800F6C4
	movs r0, #1
	rsbs r0, r0, #0
	b _0800F942
	.align 2, 0
_0800F6B8: .4byte 0x000002DA
_0800F6BC: .4byte 0x0000CB05
_0800F6C0: .4byte 0x0000E89F
_0800F6C4:
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r2, #0
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r4, r7}
	stm r0!, {r3, r4, r7}
	ldm r1!, {r3, r7}
	stm r0!, {r3, r7}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	mov sl, r4
	cmp r6, #0
	blt _0800F710
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r5, r4
	adds r2, r6, #0
	adds r2, #0x17
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0x87
	lsls r3, r3, #4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl MainSprite_Add
	b _0800F72E
_0800F710:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _0800F7D4 @ =0x00000871
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0x17
	bl MainSprite_Add
_0800F72E:
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r4, _0800F7D4 @ =0x00000871
	mov r8, r4
	movs r6, #0
	str r6, [sp]
	str r6, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	movs r2, #0x16
	mov r3, r8
	bl MainSprite_Add
	mov r0, sb
	cmp r0, #0
	beq _0800F766
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F766:
	ldr r2, _0800F7D8 @ =0x0000040C
	adds r1, r5, r2
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r7, r5, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r2, #1
	cmp r0, #0
	beq _0800F77C
	movs r2, #0x26
_0800F77C:
	str r6, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r0, r1, #0
	mov r1, sl
	mov r3, r8
	bl MainSprite_Add
	ldr r0, _0800F7DC @ =0x000002DE
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0800F7E4
	ldr r1, _0800F7E0 @ =0x00000414
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Mod
	str r0, [sp, #0x18]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #0xa
	bl Div
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	ldr r0, [r1, #4]
	adds r0, #0xc
	str r0, [r1, #4]
	adds r0, r1, #0
	b _0800F804
	.align 2, 0
_0800F7D4: .4byte 0x00000871
_0800F7D8: .4byte 0x0000040C
_0800F7DC: .4byte 0x000002DE
_0800F7E0: .4byte 0x00000414
_0800F7E4:
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #0
	beq _0800F7FA
	ldr r2, _0800F8EC @ =0x00000414
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F7FA:
	movs r0, #2
	str r0, [sp, #0x18]
	movs r1, #0xc
	add r0, sp, #0x18
	str r1, [r0, #4]
_0800F804:
	adds r3, r5, #0
	adds r3, #0x46
	str r3, [sp, #0x24]
	adds r6, r0, #0
	ldr r7, _0800F8F0 @ =0x0000046C
	adds r4, r5, r7
	movs r0, #0
	mov sb, r0
	movs r1, #1
	mov r8, r1
_0800F818:
	ldrh r2, [r6]
	movs r7, #0
	str r7, [sp]
	str r7, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	ldr r3, _0800F8F4 @ =0x00000871
	bl MainSprite_Add
	ldr r1, _0800F8F8 @ =0x000002DE
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0800F850
	ldr r2, _0800F8FC @ =0x00000474
	adds r0, r5, r2
	add r0, sb
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F850:
	adds r6, #4
	adds r4, #0x60
	movs r3, #0x60
	add sb, r3
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0800F818
	ldr r2, _0800F900 @ =0x000002DF
	adds r6, r5, r2
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r2, #0
	cmp r0, #0
	blt _0800F874
	adds r2, r0, #0
_0800F874:
	movs r3, #0xeb
	lsls r3, r3, #2
	adds r0, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _0800F8F4 @ =0x00000871
	str r7, [sp]
	str r7, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	mov r1, sl
	bl MainSprite_Add
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0800F8AA
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0800F8AA:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	beq _0800F90C
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, _0800F904 @ =0x0000539C
	bl TextBox_SetBgPltt
	ldr r0, [r5, #0x50]
	bl TextBox_Start
	ldr r0, [sp, #0x20]
	bl TextBox_ShowLine
	movs r0, #0
	movs r1, #7
	movs r2, #0x1a
	movs r3, #2
	bl TextBox_SetRect
	bl FUN_080488dc
	ldr r1, _0800F908 @ =0x03003ED0
	lsls r0, r0, #2
	subs r0, #0x78
	strh r0, [r1, #0x20]
	movs r0, #0
	movs r1, #0
	movs r2, #0x11
	bl Video_SetMosaic
	b _0800F916
	.align 2, 0
_0800F8EC: .4byte 0x00000414
_0800F8F0: .4byte 0x0000046C
_0800F8F4: .4byte 0x00000871
_0800F8F8: .4byte 0x000002DE
_0800F8FC: .4byte 0x00000474
_0800F900: .4byte 0x000002DF
_0800F904: .4byte 0x0000539C
_0800F908: .4byte 0x03003ED0
_0800F90C:
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Video_SetMosaic
_0800F916:
	ldr r2, [sp, #0x24]
	movs r4, #0
	ldrsh r3, [r2, r4]
	cmp r3, #0
	bne _0800F940
	ldr r0, _0800F954 @ =0x03004040
	str r3, [r0]
	ldr r0, _0800F958 @ =0x03004494
	ldr r7, _0800F95C @ =0x00001084
	adds r2, r7, #0
	strh r2, [r0]
	ldr r1, _0800F960 @ =0x03004454
	ldr r4, _0800F964 @ =0x0000FFFF
	adds r0, r4, #0
	strh r0, [r1]
	ldr r0, _0800F968 @ =0x0300445C
	str r3, [r0]
	ldr r0, _0800F96C @ =0x03004464
	strh r2, [r0]
	ldr r0, _0800F970 @ =0x03004490
	strh r3, [r0]
_0800F940:
	movs r0, #0
_0800F942:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800F954: .4byte 0x03004040
_0800F958: .4byte 0x03004494
_0800F95C: .4byte 0x00001084
_0800F960: .4byte 0x03004454
_0800F964: .4byte 0x0000FFFF
_0800F968: .4byte 0x0300445C
_0800F96C: .4byte 0x03004464
_0800F970: .4byte 0x03004490
