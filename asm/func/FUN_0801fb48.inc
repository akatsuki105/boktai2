	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	ldr r0, _0801FB68 @ =0x000085E6
	bl FUN_08230e70
	str r0, [sp, #0x3c]
	cmp r0, #0
	bne _0801FB6C
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FC76
	.align 2, 0
_0801FB68: .4byte 0x000085E6
_0801FB6C:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x44]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x48]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x4c]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x50]
	movs r0, #0x76
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x54]
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #0x68
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #0x6b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801FBFC
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	adds r7, r0, #0
	add r6, sp, #0x34
	add r5, sp, #0x24
	movs r4, #3
_0801FBEE:
	bl Script_GetValue
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0801FBEE
	b _0801FC04
_0801FBFC:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	add r6, sp, #0x34
_0801FC04:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801FC1E
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234cf8
	b _0801FC48
_0801FC1E:
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0801FC40
	bl Script_GetValue
	strh r0, [r6]
	bl Script_GetValue
	add r4, sp, #0x34
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	b _0801FC48
_0801FC40:
	strh r1, [r6]
	add r0, sp, #0x34
	strh r1, [r0, #2]
	strh r1, [r0, #4]
_0801FC48:
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	str r7, [sp, #0x18]
	add r0, sp, #0x24
	str r0, [sp, #0x1c]
	mov r0, sb
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0x40]
	adds r2, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_0801f8e8
_0801FC76:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
