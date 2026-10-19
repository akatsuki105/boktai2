	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _082064A0 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820644C
	b _082066B2
_0820644C:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #1
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _082064AC
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _082064A4 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _082064A8 @ =0x0000FFFF
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
	b _082064B6
	.align 2, 0
_082064A0: .4byte 0x03002B50
_082064A4: .4byte 0xFFFF0000
_082064A8: .4byte 0x0000FFFF
_082064AC:
	ldr r1, _082065CC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_082064B6:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _082064D4
	b _082066B2
_082064D4:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _082064E4
	b _082066B2
_082064E4:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _082065D0 @ =0x0000D3EA
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _082064FA
	b _082066B2
_082064FA:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xac
	lsls r3, r3, #2
	adds r1, r4, r3
	ldr r2, [r4, #0x64]
	ldr r3, [r4, #0x68]
	str r2, [r1]
	str r3, [r1, #4]
	movs r0, #0x30
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #7
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
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
	ldr r1, _082065D4 @ =FUN_08206118
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082065D8 @ =FUN_082063ec
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082065DC @ =FUN_08205fd4
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082065E0 @ =FUN_08206154
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082065E4 @ =FUN_0820640c
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082065E8 @ =FUN_08206424
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _082065D0 @ =0x0000D3EA
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
	beq _0820661C
	cmp r5, #1
	bgt _082065EC
	cmp r5, #0
	beq _082065F2
	b _082066B2
	.align 2, 0
_082065CC: .4byte 0xFFFF0000
_082065D0: .4byte 0x0000D3EA
_082065D4: .4byte FUN_08206118
_082065D8: .4byte FUN_082063ec
_082065DC: .4byte FUN_08205fd4
_082065E0: .4byte FUN_08206154
_082065E4: .4byte FUN_0820640c
_082065E8: .4byte FUN_08206424
_082065EC:
	cmp r5, #2
	beq _08206654
	b _082066B2
_082065F2:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08206618 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _082066B0
	.align 2, 0
_08206618: .4byte FUN_080421bc
_0820661C:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _08206650 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
	b _082066B2
	.align 2, 0
_08206650: .4byte FUN_08042178
_08206654:
	ldr r1, _08206684 @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _08206688 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08206690
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820668C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _082066A4
	.align 2, 0
_08206684: .4byte 0x00000217
_08206688: .4byte 0x000001EF
_0820668C: .4byte FUN_080421bc
_08206690:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _082066C4 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_082066A4:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_082066B0:
	strb r7, [r4, #0x18]
_082066B2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082066C4: .4byte FUN_08042868
