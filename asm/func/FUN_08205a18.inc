	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _08205A84 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08205A30
	b _08205C96
_08205A30:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0xd
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08205A90
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08205A88 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08205A8C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _08205A9A
	.align 2, 0
_08205A84: .4byte 0x03002B50
_08205A88: .4byte 0xFFFF0000
_08205A8C: .4byte 0x0000FFFF
_08205A90:
	ldr r1, _08205BB0 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_08205A9A:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	mov r0, r8
	adds r1, r6, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _08205AB4
	b _08205C96
_08205AB4:
	ldr r0, _08205BB4 @ =0x03002C90
	str r4, [r0]
	adds r0, r4, #0
	mov r1, r8
	add r2, sp, #8
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08205ACA
	b _08205C96
_08205ACA:
	ldr r0, _08205BB8 @ =0x000097D3
	mov sl, r0
	ldr r3, _08205BBC @ =0x0000C6A0
	movs r7, #0
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #1
	mov r2, sl
	bl FUN_08040f48
	cmp r0, #0
	bge _08205AE4
	b _08205C96
_08205AE4:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r6, #0
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	subs r1, #0x34
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
	mov r1, r8
	movs r2, #5
	bl MsgQueue_Register
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r2, r5, #0x10
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
	ldr r1, _08205BC0 @ =FUN_08205664
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08205BC4 @ =FUN_082058d8
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08205BC8 @ =FUN_082059d8
	subs r3, #0x10
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08205BCC @ =FUN_082059e4
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08205BD0 @ =FUN_08205990
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08205BD4 @ =FUN_082059bc
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	mov r2, sl
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl Entity286F_LinkNode
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	adds r0, r4, #0
	adds r0, #0x20
	strh r7, [r4, #0xc]
	strb r6, [r0, #8]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	cmp r2, #1
	beq _08205BF4
	cmp r2, #1
	bgt _08205BD8
	cmp r2, #0
	beq _08205BDE
	b _08205C50
	.align 2, 0
_08205BB0: .4byte 0xFFFF0000
_08205BB4: .4byte 0x03002C90
_08205BB8: .4byte 0x000097D3
_08205BBC: .4byte 0x0000C6A0
_08205BC0: .4byte FUN_08205664
_08205BC4: .4byte FUN_082058d8
_08205BC8: .4byte FUN_082059d8
_08205BCC: .4byte FUN_082059e4
_08205BD0: .4byte FUN_08205990
_08205BD4: .4byte FUN_082059bc
_08205BD8:
	cmp r2, #2
	beq _08205C28
	b _08205C50
_08205BDE:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08205BF0 @ =FUN_080421bc
	movs r0, #2
	b _08205C40
	.align 2, 0
_08205BF0: .4byte FUN_080421bc
_08205BF4:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	strb r2, [r4, #8]
	ldr r0, _08205C24 @ =FUN_08042178
	strb r2, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r1, r4, r3
	str r0, [r1]
	str r7, [r4, #0x10]
	strb r2, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
	b _08205C50
	.align 2, 0
_08205C24: .4byte FUN_08042178
_08205C28:
	ldr r1, _08205CA8 @ =0x00000217
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x12
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08205CAC @ =FUN_08205178
	movs r0, #0x10
_08205C40:
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	str r7, [r4, #0x10]
	strb r1, [r4, #9]
	strb r6, [r4, #0x18]
_08205C50:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0804135c
	movs r1, #0x10
	movs r2, #0x14
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r1]
	adds r3, #0xc
	adds r1, r4, r3
	adds r0, #0x90
	str r0, [r1]
_08205C96:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08205CA8: .4byte 0x00000217
_08205CAC: .4byte FUN_08205178
