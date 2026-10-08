	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r0, _0804437C @ =0x03002B50
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08044328
	b _0804453C
_08044328:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08044388
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08044380 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08044384 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08044392
	.align 2, 0
_0804437C: .4byte 0x03002B50
_08044380: .4byte 0xFFFF0000
_08044384: .4byte 0x0000FFFF
_08044388:
	ldr r1, _080444F8 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08044392:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x6f
	movs r1, #2
	bl VM_GetNamedArgValue
	str r0, [sp, #0xc]
	ldr r1, _080444FC @ =0x0000DE23
	movs r0, #0x74
	bl VM_GetNamedArgValue
	mov sl, r0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x63
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	mov r0, sb
	adds r1, r5, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _080443D6
	b _0804453C
_080443D6:
	mov r1, sb
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _080443E6
	b _0804453C
_080443E6:
	movs r5, #0
	str r5, [sp]
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	mov r2, sl
	mov r3, r8
	bl FUN_08040f48
	cmp r0, #0
	bge _080443FC
	b _0804453C
_080443FC:
	cmp r7, #0
	blt _08044408
	adds r0, r4, #0
	adds r1, r7, #0
	bl Entity286FNode_SetPltt
_08044408:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r1, sb
	movs r2, #5
	bl MsgQueue_Register
	adds r0, r4, #0
	adds r0, #0x61
	strb r6, [r0]
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	ldr r1, _08044500 @ =FUN_08044168
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044504 @ =FUN_080442d4
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044508 @ =FUN_0804415c
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0804450C @ =FUN_080441a4
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044510 @ =FUN_080442f4
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08044514 @ =FUN_08044300
	adds r2, #4
	adds r0, r4, r2
	str r1, [r0]
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
	movs r6, #1
	strb r6, [r4, #8]
	ldr r1, _08044518 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
	str r5, [r4, #0x10]
	strb r6, [r4, #9]
	strb r5, [r4, #0x18]
	mov r0, sl
	movs r1, #0
	bl Entity286F_FindSpriteData
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r0, sl
	movs r1, #0
	bl FUN_08040dc0
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x62
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08044520
	bl VM_GetValue
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r2, _0804451C @ =0x000001E9
	adds r1, r4, r2
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	b _08044534
	.align 2, 0
_080444F8: .4byte 0xFFFF0000
_080444FC: .4byte 0x0000DE23
_08044500: .4byte FUN_08044168
_08044504: .4byte FUN_080442d4
_08044508: .4byte FUN_0804415c
_0804450C: .4byte FUN_080441a4
_08044510: .4byte FUN_080442f4
_08044514: .4byte FUN_08044300
_08044518: .4byte FUN_080421bc
_0804451C: .4byte 0x000001E9
_08044520:
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_08044534:
	ldr r0, [sp, #0x10]
	adds r1, r4, #0
	bl Entity286F_LinkNode
_0804453C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
