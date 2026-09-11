	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0800A324 @ =0x03000040
	ldr r7, [r0]
	cmp r7, #0
	bne _0800A312
	movs r0, #0
	movs r1, #0
	bl Entity0866_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _0800A31E
_0800A312:
	adds r0, r7, #0
	bl FUN_08009b10
	adds r6, r0, #0
	cmp r6, #0
	bne _0800A328
_0800A31E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800A40C
	.align 2, 0
_0800A324: .4byte 0x03000040
_0800A328:
	adds r0, r6, #0
	movs r1, #0x9c
	bl ClearMemory
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	movs r5, #0
	strh r0, [r6]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #3]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #4]
	strb r4, [r6, #8]
	strb r4, [r6, #2]
	strh r5, [r6, #0xa]
	movs r0, #1
	strb r0, [r6, #7]
	strh r5, [r6, #0xc]
	strb r4, [r6, #6]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08009b6c
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800A3B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800A3A8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800A3AC @ =0x0000FFFF
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
	b _0800A3BA
	.align 2, 0
_0800A3A8: .4byte 0xFFFF0000
_0800A3AC: .4byte 0x0000FFFF
_0800A3B0:
	ldr r1, _0800A3F8 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_0800A3BA:
	adds r0, r6, #0
	adds r0, #0x14
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r6, #0
	adds r1, #0x7e
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800A3FC
	bl Script_GetValue
	strh r0, [r6, #0xe]
	bl Script_GetValue
	strh r0, [r6, #0x10]
	bl Script_GetValue
	b _0800A408
	.align 2, 0
_0800A3F8: .4byte 0xFFFF0000
_0800A3FC:
	movs r0, #0x32
	strh r0, [r6, #0xe]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r6, #0x10]
	movs r0, #0x64
_0800A408:
	strh r0, [r6, #0x12]
	movs r0, #0
_0800A40C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
