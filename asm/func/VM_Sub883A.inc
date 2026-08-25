	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0800990C @ =0x0300003C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _08009868
	b _08009A00
_08009868:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	mov r0, r8
	ldr r5, [r0, #0x20]
	movs r1, #0
	mov sl, r1
	ldrb r3, [r0, #0x18]
	cmp sl, r3
	blt _08009882
	b _080099F4
_08009882:
	mov sb, sp
_08009884:
	movs r1, #1
	mov r0, sl
	lsls r1, r0
	mov r3, r8
	ldr r0, [r3, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08009896
	b _080099E4
_08009896:
	adds r7, r5, #0
	adds r7, #0x24
	movs r4, #0
	strh r2, [r5]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #2]
	strb r4, [r5, #3]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #4]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #8]
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0xc]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0xe]
	movs r0, #0x44
	movs r1, #0xe6
	bl Script_GetKeywordValue
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	str r0, [r5, #0x10]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08009910
	adds r6, r5, #0
	adds r6, #0x14
	adds r4, r6, #0
_080098F2:
	bl VM_GetPC
	cmp r0, #0
	beq _080098FE
	bl Script_GetValue
_080098FE:
	strh r0, [r4]
	adds r4, #2
	adds r0, r6, #6
	cmp r4, r0
	ble _080098F2
	b _08009922
	.align 2, 0
_0800990C: .4byte 0x0300003C
_08009910:
	adds r1, r5, #0
	adds r1, #0x14
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x1a
_0800991A:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0800991A
_08009922:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0800996C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp]
	ldr r2, _08009964 @ =0xFFFF0000
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08009968 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sb
	ldr r1, [r3, #4]
	ldr r2, _08009964 @ =0xFFFF0000
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #4]
	b _0800997A
	.align 2, 0
_08009964: .4byte 0xFFFF0000
_08009968: .4byte 0x0000FFFF
_0800996C:
	movs r0, #0
	str r0, [sp]
	mov r3, sb
	ldr r0, [r3, #4]
	ldr r1, _08009994 @ =0xFFFF0000
	ands r0, r1
	str r0, [r3, #4]
_0800997A:
	mov r0, r8
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08009298
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _08009998
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_08241574
	b _0800999C
	.align 2, 0
_08009994: .4byte 0xFFFF0000
_08009998:
	movs r0, #1
	rsbs r0, r0, #0
_0800999C:
	str r0, [r5, #8]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08009278
	ldrb r1, [r5, #4]
	cmp r1, #1
	bne _080099B2
	ldr r0, [r7]
	orrs r0, r1
	b _080099BA
_080099B2:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_080099BA:
	str r0, [r7]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _080099CC
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	b _080099D2
_080099CC:
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
_080099D2:
	str r0, [r7]
	movs r1, #1
	mov r3, sl
	lsls r1, r3
	mov r2, r8
	ldr r0, [r2, #0x1c]
	orrs r0, r1
	str r0, [r2, #0x1c]
	b _080099F4
_080099E4:
	movs r3, #1
	add sl, r3
	adds r5, #0x6c
	mov r0, r8
	ldrb r0, [r0, #0x18]
	cmp sl, r0
	bge _080099F4
	b _08009884
_080099F4:
	mov r1, r8
	ldrb r1, [r1, #0x18]
	cmp sl, r1
	beq _08009A00
	movs r0, #0
	b _08009A04
_08009A00:
	movs r0, #1
	rsbs r0, r0, #0
_08009A04:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
