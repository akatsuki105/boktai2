	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0820C9AC @ =0x03002B50
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _0820C958
	b _0820CBC8
_0820C958:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x6b
	movs r1, #0xe
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820C9B8
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820C9B0 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820C9B4 @ =0x0000FFFF
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
	b _0820C9C2
	.align 2, 0
_0820C9AC: .4byte 0x03002B50
_0820C9B0: .4byte 0xFFFF0000
_0820C9B4: .4byte 0x0000FFFF
_0820C9B8:
	ldr r1, _0820CAD8 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820C9C2:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	ldr r1, _0820CADC @ =0x0000DFCE
	movs r0, #0x63
	bl VM_GetNamedArgValue
	str r0, [sp, #0xc]
	movs r7, #0
	movs r0, #1
	mov r8, r0
	mov r0, sb
	adds r1, r6, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _0820C9EC
	b _0820CBC8
_0820C9EC:
	mov r1, sb
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820C9FC
	b _0820CBC8
_0820C9FC:
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820CA10
	b _0820CBC8
_0820CA10:
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
	mov r1, sb
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
	mov sb, r3
	mov r3, sb
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820CAE0 @ =FUN_0820c658
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820CAE4 @ =FUN_0820c904
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820CAE8 @ =FUN_0820c728
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820CAEC @ =FUN_0820c694
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820CAF0 @ =FUN_0820c924
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820CAF4 @ =FUN_0820c930
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sl
	adds r1, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #1
	bl FUN_08040df4
	mov r0, sl
	adds r1, r4, #0
	bl Entity286F_LinkNode
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820CB24
	cmp r5, #1
	bgt _0820CAF8
	cmp r5, #0
	beq _0820CAFE
	b _0820CBC8
	.align 2, 0
_0820CAD8: .4byte 0xFFFF0000
_0820CADC: .4byte 0x0000DFCE
_0820CAE0: .4byte FUN_0820c658
_0820CAE4: .4byte FUN_0820c904
_0820CAE8: .4byte FUN_0820c728
_0820CAEC: .4byte FUN_0820c694
_0820CAF0: .4byte FUN_0820c924
_0820CAF4: .4byte FUN_0820c930
_0820CAF8:
	cmp r5, #2
	beq _0820CB5C
	b _0820CBC8
_0820CAFE:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	mov r0, r8
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	strb r0, [r4, #8]
	ldr r0, _0820CB20 @ =FUN_080421bc
	movs r1, #2
	strb r1, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #9]
	b _0820CBC6
	.align 2, 0
_0820CB20: .4byte FUN_080421bc
_0820CB24:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	mov r0, r8
	strb r0, [r4, #8]
	ldr r0, _0820CB58 @ =FUN_08042178
	mov r1, r8
	strb r1, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
	b _0820CBC8
	.align 2, 0
_0820CB58: .4byte FUN_08042178
_0820CB5C:
	ldr r1, _0820CB98 @ =0x00000217
	adds r0, r4, r1
	mov r2, r8
	strb r2, [r0]
	ldr r3, _0820CB9C @ =0x000001EF
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820CBA4
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	mov r0, r8
	strb r0, [r4, #8]
	ldr r1, _0820CBA0 @ =FUN_080421bc
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r7, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #9]
	b _0820CBC6
	.align 2, 0
_0820CB98: .4byte 0x00000217
_0820CB9C: .4byte 0x000001EF
_0820CBA0: .4byte FUN_080421bc
_0820CBA4:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	mov r0, r8
	strb r0, [r4, #8]
	ldr r1, _0820CBD8 @ =FUN_08042868
	mov r2, sb
	strb r2, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	str r7, [r4, #0x10]
	mov r0, r8
	strb r0, [r4, #9]
_0820CBC6:
	strb r6, [r4, #0x18]
_0820CBC8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820CBD8: .4byte FUN_08042868
