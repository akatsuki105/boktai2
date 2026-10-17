	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08007260
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007258 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800725C @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _0800726C
	.align 2, 0
_08007258: .4byte 0xFFFF0000
_0800725C: .4byte 0x0000FFFF
_08007260:
	ldr r2, _08007284 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_0800726C:
	movs r0, #0x49
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08007288
	bl VM_GetValue
	mov sb, r0
	bl VM_GetValue
	b _0800728C
	.align 2, 0
_08007284: .4byte 0xFFFF0000
_08007288:
	movs r0, #0
	mov sb, r0
_0800728C:
	mov r8, r0
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x24]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetNamedArgValue
	mov sl, r0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	movs r0, #0x4f
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x18
_080072BA:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x10
	cmp r0, r2
	bge _080072BA
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080072E8
	movs r4, #0
	add r5, sp, #0x10
	b _080072DC
_080072D4:
	bl VM_GetValue
	stm r5!, {r0}
	adds r4, #1
_080072DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080072E8
	cmp r4, #2
	ble _080072D4
_080072E8:
	add r0, sp, #0x10
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x1c
	mov r1, sb
	mov r2, r8
	ldr r3, [sp, #0x24]
	bl FUN_080070a8
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
