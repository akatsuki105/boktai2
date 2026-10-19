	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08207864 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08207810
	b _08207AAE
_08207810:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	movs r0, #0x6b
	movs r1, #3
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08207870
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08207868 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820786C @ =0x0000FFFF
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
	b _0820787A
	.align 2, 0
_08207864: .4byte 0x03002B50
_08207868: .4byte 0xFFFF0000
_0820786C: .4byte 0x0000FFFF
_08207870:
	ldr r1, _0820798C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820787A:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _08207898
	b _08207AAE
_08207898:
	adds r1, r7, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _082078A8
	b _08207AAE
_082078A8:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _08207990 @ =0x0000DFEE
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _082078BE
	b _08207AAE
_082078BE:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xaf
	lsls r1, r1, #1
	movs r6, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r7, #0
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
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _08207994 @ =FUN_082073dc
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08207998 @ =FUN_082077bc
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820799C @ =FUN_0820759c
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082079A0 @ =FUN_08207418
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082079A4 @ =FUN_082077dc
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082079A8 @ =FUN_082077e8
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _08207990 @ =0x0000DFEE
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
	beq _082079E0
	cmp r5, #1
	bgt _082079AC
	cmp r5, #0
	beq _082079B6
	b _08207AAE
	.align 2, 0
_0820798C: .4byte 0xFFFF0000
_08207990: .4byte 0x0000DFEE
_08207994: .4byte FUN_082073dc
_08207998: .4byte FUN_082077bc
_0820799C: .4byte FUN_0820759c
_082079A0: .4byte FUN_08207418
_082079A4: .4byte FUN_082077dc
_082079A8: .4byte FUN_082077e8
_082079AC:
	cmp r5, #2
	beq _08207A18
	cmp r5, #3
	beq _08207A88
	b _08207AAE
_082079B6:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _082079DC @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _08207AAC
	.align 2, 0
_082079DC: .4byte FUN_080421bc
_082079E0:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _08207A14 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
	b _08207AAE
	.align 2, 0
_08207A14: .4byte FUN_08042178
_08207A18:
	ldr r1, _08207A54 @ =0x00000217
	adds r0, r4, r1
	movs r7, #1
	strb r7, [r0]
	ldr r2, _08207A58 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08207A60
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r7, [r4, #8]
	ldr r1, _08207A5C @ =FUN_080421bc
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r7, [r4, #9]
	b _08207AAC
	.align 2, 0
_08207A54: .4byte 0x00000217
_08207A58: .4byte 0x000001EF
_08207A5C: .4byte FUN_080421bc
_08207A60:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r7, [r4, #8]
	ldr r1, _08207A84 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r7, [r4, #9]
	b _08207AAC
	.align 2, 0
_08207A84: .4byte FUN_08042868
_08207A88:
	movs r0, #0x15
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _08207AC0 @ =FUN_082072f0
	movs r0, #0x13
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r2, [r4, #9]
_08207AAC:
	strb r6, [r4, #0x18]
_08207AAE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08207AC0: .4byte FUN_082072f0
