	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823BF5E
	bl Script_GetValue
	adds r5, r0, #0
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823BF44
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0823BF3C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0823BF40 @ =0x0000FFFF
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
	b _0823BF4E
	.align 2, 0
_0823BF3C: .4byte 0xFFFF0000
_0823BF40: .4byte 0x0000FFFF
_0823BF44:
	ldr r1, _0823BF68 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_0823BF4E:
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0823bbd4
	ldr r0, _0823BF6C @ =gCamera
	ldr r0, [r0]
	bl FUN_0823bd98
_0823BF5E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823BF68: .4byte 0xFFFF0000
_0823BF6C: .4byte gCamera
