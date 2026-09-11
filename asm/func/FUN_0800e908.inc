	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x20]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x50
	movs r1, #0xc8
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x46
	movs r1, #0x32
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800E9B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800E9A8 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800E9AC @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x18]
	b _0800E9BA
	.align 2, 0
_0800E9A8: .4byte 0xFFFF0000
_0800E9AC: .4byte 0x0000FFFF
_0800E9B0:
	ldr r1, _0800E9E4 @ =0xFFFF0000
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r1
	str r0, [sp, #0x18]
_0800E9BA:
	mov r0, r8
	str r0, [sp]
	str r7, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	add r0, sp, #0x14
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	mov r2, sl
	mov r3, sb
	bl FUN_0800e594
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E9E4: .4byte 0xFFFF0000
