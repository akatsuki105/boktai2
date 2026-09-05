	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823BED4
	bl Script_GetValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823BED4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823BEDC @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0823BEE0 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0823bb7c
	ldr r0, _0823BEE4 @ =gCamera
	ldr r0, [r0]
	bl FUN_0823bd98
_0823BED4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823BEDC: .4byte 0xFFFF0000
_0823BEE0: .4byte 0x0000FFFF
_0823BEE4: .4byte gCamera
