	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823C34C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823C354 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r5, _0823C358 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823C34C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #8
	ldr r2, [r1, #4]
	ands r2, r4
	orrs r2, r0
	str r2, [r1, #4]
	mov r0, sp
	bl FUN_0823c260
_0823C34C:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823C354: .4byte 0xFFFF0000
_0823C358: .4byte 0x0000FFFF
