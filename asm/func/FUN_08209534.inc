	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	ldr r0, _082095A0 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820954E
	b _082097C6
_0820954E:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #5
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _082095AC
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _082095A4 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _082095A8 @ =0x0000FFFF
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
	b _082095B6
	.align 2, 0
_082095A0: .4byte 0x03002B50
_082095A4: .4byte 0xFFFF0000
_082095A8: .4byte 0x0000FFFF
_082095AC:
	ldr r1, _082096CC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_082095B6:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r7, #0
	mov r0, r8
	adds r1, r6, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _082095D2
	b _082097C6
_082095D2:
	mov r1, r8
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _082095E2
	b _082097C6
_082095E2:
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _082096D0 @ =0x0000E00E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _082095F6
	b _082097C6
_082095F6:
	adds r0, r4, #0
	adds r0, #0x20
	movs r6, #0
	mov r1, sl
	strh r1, [r4, #0x20]
	strh r7, [r0, #0x16]
	str r7, [r0, #0x18]
	str r7, [r0, #0x1c]
	adds r0, #0x3c
	movs r1, #0xc8
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r0, r4, r3
	mov r1, r8
	movs r2, #5
	bl MsgQueue_Register
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov r8, r3
	mov r3, r8
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _082096D4 @ =FUN_08209134
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082096D8 @ =FUN_082094f8
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082096DC @ =FUN_08208344
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082096E0 @ =FUN_0820919c
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082096E4 @ =FUN_08209518
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082096E8 @ =FUN_08209524
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	strb r5, [r4, #0x1b]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _082096D0 @ =0x0000E00E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl Entity286F_LinkNode
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820971C
	cmp r5, #1
	bgt _082096EC
	cmp r5, #0
	beq _082096F6
	b _082097C6
	.align 2, 0
_082096CC: .4byte 0xFFFF0000
_082096D0: .4byte 0x0000E00E
_082096D4: .4byte FUN_08209134
_082096D8: .4byte FUN_082094f8
_082096DC: .4byte FUN_08208344
_082096E0: .4byte FUN_0820919c
_082096E4: .4byte FUN_08209518
_082096E8: .4byte FUN_08209524
_082096EC:
	cmp r5, #2
	beq _08209750
	cmp r5, #3
	beq _082097A4
	b _082097C6
_082096F6:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08209718 @ =FUN_0820848c
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	str r7, [r4, #0x10]
	strb r1, [r4, #9]
	b _082097C4
	.align 2, 0
_08209718: .4byte FUN_0820848c
_0820971C:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820974C @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl SpriteHolder_SetFlags
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
	b _082097C6
	.align 2, 0
_0820974C: .4byte FUN_08042178
_08209750:
	ldr r3, _08209780 @ =0x00000217
	adds r0, r4, r3
	movs r2, #1
	strb r2, [r0]
	ldr r1, _08209784 @ =0x000001EF
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820978C
	adds r0, r4, #0
	str r2, [sp, #0xc]
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	ldr r2, [sp, #0xc]
	strb r2, [r4, #8]
	ldr r1, _08209788 @ =FUN_080421bc
	strb r5, [r4, #6]
	b _082097B8
	.align 2, 0
_08209780: .4byte 0x00000217
_08209784: .4byte 0x000001EF
_08209788: .4byte FUN_080421bc
_0820978C:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	strb r2, [r4, #8]
	ldr r1, _082097A0 @ =FUN_08042868
	mov r0, r8
	b _082097B6
	.align 2, 0
_082097A0: .4byte FUN_08042868
_082097A4:
	movs r0, #0x14
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _082097D8 @ =FUN_082088f8
	movs r0, #0x12
_082097B6:
	strb r0, [r4, #6]
_082097B8:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	str r7, [r4, #0x10]
	strb r2, [r4, #9]
_082097C4:
	strb r6, [r4, #0x18]
_082097C6:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082097D8: .4byte FUN_082088f8
