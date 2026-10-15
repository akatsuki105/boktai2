	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov sb, r0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C105C
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C1054 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080C1058 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	b _080C1066
	.align 2, 0
_080C1054: .4byte 0xFFFF0000
_080C1058: .4byte 0x0000FFFF
_080C105C:
	ldr r1, _080C1078 @ =0xFFFF0000
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
_080C1066:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C107C
	bl VM_GetValue
	adds r0, #0x2c
	b _080C107E
	.align 2, 0
_080C1078: .4byte 0xFFFF0000
_080C107C:
	movs r0, #0x2c
_080C107E:
	mov r8, r0
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C1092
	bl VM_GetValue
	adds r7, r0, #0
	b _080C1094
_080C1092:
	movs r7, #0
_080C1094:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10A6
	bl VM_GetValue
	adds r6, r0, #0
	b _080C10A8
_080C10A6:
	movs r6, #0
_080C10A8:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10BA
	bl VM_GetValue
	adds r5, r0, #0
	b _080C10BC
_080C10BA:
	movs r5, #0x20
_080C10BC:
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10CE
	bl VM_GetValue
	adds r4, r0, #0
	b _080C10D0
_080C10CE:
	movs r4, #0
_080C10D0:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10E0
	bl VM_GetValue
	b _080C10E2
_080C10E0:
	movs r0, #0x5a
_080C10E2:
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x10
	mov r2, r8
	adds r3, r7, #0
	bl Entity080c0fa0_Init
	movs r0, #0
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
