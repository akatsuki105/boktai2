	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08007694
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800768C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08007690 @ =0x0000FFFF
	ldr r1, [sp, #0x28]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x28]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x28
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _080076A0
	.align 2, 0
_0800768C: .4byte 0xFFFF0000
_08007690: .4byte 0x0000FFFF
_08007694:
	ldr r2, _080076B8 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_080076A0:
	movs r0, #0x49
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080076BC
	bl VM_GetValue
	str r0, [sp, #0x34]
	bl VM_GetValue
	b _080076C0
	.align 2, 0
_080076B8: .4byte 0xFFFF0000
_080076BC:
	movs r0, #0
	str r0, [sp, #0x34]
_080076C0:
	mov sl, r0
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x30]
	movs r0, #0x67
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x38]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x3c]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r0, #0x53
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	movs r0, #0x63
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x24
_0800770C:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x1c
	cmp r0, r2
	bge _0800770C
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800773A
	movs r4, #0
	add r5, sp, #0x1c
	b _0800772E
_08007726:
	bl VM_GetValue
	stm r5!, {r0}
	adds r4, #1
_0800772E:
	bl VM_GetPC
	cmp r0, #0
	beq _0800773A
	cmp r4, #2
	ble _08007726
_0800773A:
	mov r0, r8
	str r0, [sp]
	ldr r2, [sp, #0x38]
	str r2, [sp, #4]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #8]
	add r2, sp, #0x1c
	str r2, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	add r0, sp, #0x28
	ldr r1, [sp, #0x34]
	mov r2, sl
	ldr r3, [sp, #0x30]
	bl FUN_08007310
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
