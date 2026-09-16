	push {r4, r5, lr}
	sub sp, #0x30
	movs r0, #0x6e
	movs r1, #1
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08015F44
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08015F3C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08015F40 @ =0x0000FFFF
	ldr r1, [sp, #0x28]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x28
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r2, #0
	b _08015F52
	.align 2, 0
_08015F3C: .4byte 0xFFFF0000
_08015F40: .4byte 0x0000FFFF
_08015F44:
	ldr r2, _08015FA4 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r1, #0
_08015F52:
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sp
	strh r0, [r1]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #2]
	movs r0, #0x61
	movs r1, #0x40
	bl VM_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #6]
	movs r0, #0x73
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08015FA8
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #8]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xa]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xc]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xe]
	b _08015FB2
	.align 2, 0
_08015FA4: .4byte 0xFFFF0000
_08015FA8:
	mov r0, sp
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
_08015FB2:
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08015FE0
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x10]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x12]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x14]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x16]
	b _08015FEA
_08015FE0:
	mov r0, sp
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	strh r1, [r0, #0x14]
	strh r1, [r0, #0x16]
_08015FEA:
	movs r0, #0x63
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08016038
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x18]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1a]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1c]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1e]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x20]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x22]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x24]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x26]
	b _0801604C
_08016038:
	mov r0, sp
	movs r1, #0xff
	strh r1, [r0, #0x18]
	strh r2, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r2, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r2, [r0, #0x26]
_0801604C:
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
