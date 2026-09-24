	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D59A8 @ =0x03000198
	ldr r6, [r0]
	cmp r6, #0
	bne _081D5944
	bl EntityF1F9_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081D5944
	b _081D5C9C
_081D5944:
	adds r0, r6, #0
	bl FUN_081d5864
	adds r5, r0, #0
	cmp r5, #0
	bne _081D5952
	b _081D5C9C
_081D5952:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r1, _081D59AC @ =0x00009385
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0x6d
	bl VM_GetKeywordValue
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D59B0
	movs r0, #0xa4
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _081D59B8
	.align 2, 0
_081D59A8: .4byte 0x03000198
_081D59AC: .4byte 0x00009385
_081D59B0:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081D59B8:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D59D4
	bl Script_GetValue
	strh r0, [r7, #0x1c]
	bl Script_GetValue
	strh r0, [r7, #0x1e]
	bl Script_GetValue
	strh r0, [r7, #0x20]
_081D59D4:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x61
	bl VM_GetKeywordValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	str r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081D5A44 @ =0x0000013D
	adds r1, r5, r2
	strb r0, [r1]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D5AC2
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A48
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5A4A
	.align 2, 0
_081D5A44: .4byte 0x0000013D
_081D5A48:
	movs r1, #0
_081D5A4A:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A60
	bl Script_GetValue
	b _081D5A62
_081D5A60:
	movs r0, #0
_081D5A62:
	ldr r2, _081D5A78 @ =0x00000147
	adds r1, r5, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A7C
	bl Script_GetValue
	b _081D5A7E
	.align 2, 0
_081D5A78: .4byte 0x00000147
_081D5A7C:
	movs r0, #0
_081D5A7E:
	movs r3, #0xa3
	lsls r3, r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081D5A94
	bl Script_GetValue
	b _081D5A96
_081D5A94:
	movs r0, #0
_081D5A96:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _081D5AA8
	bl Script_GetValue
	mov sb, r0
	b _081D5AAC
_081D5AA8:
	movs r1, #0
	mov sb, r1
_081D5AAC:
	bl VM_GetPC
	cmp r0, #0
	beq _081D5ABC
	bl Script_GetValue
	mov r8, r0
	b _081D5AE6
_081D5ABC:
	movs r2, #0
	mov r8, r2
	b _081D5AE6
_081D5AC2:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x64
	strh r0, [r1]
	adds r0, #0xe3
	adds r1, r5, r0
	movs r0, #3
	strb r0, [r1]
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	mov sl, r3
	mov sb, r3
	mov r8, r3
_081D5AE6:
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r3, #5
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, #1
	bl Div
	movs r2, #0x9d
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D5B32
	bl VM_GetPC
	cmp r0, #0
	beq _081D5B28
	bl Script_GetValue
	adds r1, r0, #0
	b _081D5B2A
_081D5B28:
	movs r1, #0
_081D5B2A:
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_081D5B32:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d5848
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _081D5B76
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x60
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	movs r2, #0xa7
	lsls r2, r2, #1
	adds r1, r5, r2
	b _081D5BA6
_081D5B76:
	adds r0, r5, #0
	adds r0, #0xa8
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x80
	str r2, [sp]
	movs r2, #0x64
	str r2, [sp, #4]
	movs r2, #0xa0
	lsls r2, r2, #4
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x10
	bl AuxShadow_Init
	movs r3, #0xa7
	lsls r3, r3, #1
	adds r1, r5, r3
_081D5BA6:
	strb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r1, [r6, #0x18]
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D5BEE
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D5BF6
_081D5BEE:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D5BF6:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D5C1A
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D5C22
_081D5C1A:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D5C22:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081D5C58 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D5C90
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D5C5C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D5C52
	ldrb r0, [r4, #5]
_081D5C52:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D5C6C
	.align 2, 0
_081D5C58: .4byte 0x0000FFFF
_081D5C5C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D5C6C
	strh r1, [r4, #8]
_081D5C6C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D5C90
	movs r0, #1
	strb r0, [r4, #7]
_081D5C90:
	adds r0, r5, #0
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl FUN_081d66c0
_081D5C9C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
