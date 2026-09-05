	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _080DE074
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DE074
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080DE020 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r6, _080DE024 @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r6
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r4, sp, #0x14
	ldr r1, [r4, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r4, #4]
	movs r0, #0x6f
	bl VM_SeekToKeyword
	mov sb, r4
	cmp r0, #0
	beq _080DE028
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r1, [sp, #0x1c]
	ands r1, r6
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r2, #4]
	mov r8, r2
	b _080DE038
	.align 2, 0
_080DE020: .4byte 0xFFFF0000
_080DE024: .4byte 0x0000FFFF
_080DE028:
	add r4, sp, #0x1c
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _080DE084 @ =0x05000002
	bl CpuSet
	mov r8, r4
_080DE038:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x6b
	movs r1, #1
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x72
	movs r1, #2
	bl VM_GetKeywordValue
	str r5, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r4, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, sb
	adds r1, r7, #0
	mov r2, r8
	adds r3, r6, #0
	bl FUN_080ddcc8
_080DE074:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE084: .4byte 0x05000002
