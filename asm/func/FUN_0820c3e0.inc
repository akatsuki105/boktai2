	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820C44C @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820C3F8
	b _0820C642
_0820C3F8:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0xf
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820C458
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820C450 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820C454 @ =0x0000FFFF
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
	b _0820C462
	.align 2, 0
_0820C44C: .4byte 0x03002B50
_0820C450: .4byte 0xFFFF0000
_0820C454: .4byte 0x0000FFFF
_0820C458:
	ldr r1, _0820C570 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820C462:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	ldr r0, _0820C574 @ =0x0000AF82
	mov sl, r0
	movs r7, #0
	mov r0, r8
	adds r1, r6, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _0820C482
	b _0820C642
_0820C482:
	mov r1, r8
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820C492
	b _0820C642
_0820C492:
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #2
	mov r2, sl
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820C4A6
	b _0820C642
_0820C4A6:
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
	ldr r1, _0820C578 @ =FUN_0820c1a4
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820C57C @ =FUN_0820c3a4
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820C580 @ =FUN_0820bfac
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820C584 @ =FUN_0820c1e0
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820C588 @ =FUN_0820c3c4
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820C58C @ =FUN_0820c3d0
	adds r3, #8
	adds r0, r4, r3
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
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820C5BC
	cmp r5, #1
	bgt _0820C590
	cmp r5, #0
	beq _0820C596
	b _0820C642
	.align 2, 0
_0820C570: .4byte 0xFFFF0000
_0820C574: .4byte 0x0000AF82
_0820C578: .4byte FUN_0820c1a4
_0820C57C: .4byte FUN_0820c3a4
_0820C580: .4byte FUN_0820bfac
_0820C584: .4byte FUN_0820c1e0
_0820C588: .4byte FUN_0820c3c4
_0820C58C: .4byte FUN_0820c3d0
_0820C590:
	cmp r5, #2
	beq _0820C5F0
	b _0820C642
_0820C596:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820C5B8 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	str r7, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820C640
	.align 2, 0
_0820C5B8: .4byte FUN_080421bc
_0820C5BC:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820C5EC @ =FUN_08042178
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
	b _0820C642
	.align 2, 0
_0820C5EC: .4byte FUN_08042178
_0820C5F0:
	ldr r3, _0820C618 @ =0x000001EF
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820C620
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _0820C61C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820C634
	.align 2, 0
_0820C618: .4byte 0x000001EF
_0820C61C: .4byte FUN_080421bc
_0820C620:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _0820C654 @ =FUN_08042868
	mov r0, r8
	strb r0, [r4, #6]
_0820C634:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	str r7, [r4, #0x10]
	strb r2, [r4, #9]
_0820C640:
	strb r6, [r4, #0x18]
_0820C642:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820C654: .4byte FUN_08042868
