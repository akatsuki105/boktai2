	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D7D18 @ =0x0300019C
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _081D7CC0
	b _081D7FD2
_081D7CC0:
	bl FUN_081d6f64
	adds r7, r0, #0
	cmp r7, #0
	bne _081D7CCC
	b _081D7FD2
_081D7CCC:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	str r1, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r2, r7, #0
	adds r2, #0x9c
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081D7D02
	bl Script_GetValue
	ldr r1, [sp, #0x14]
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa0
	strh r0, [r1]
_081D7D02:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D7D1C
	bl Script_GetValue
	str r0, [sp, #8]
	bl Script_GetValue
	b _081D7D22
	.align 2, 0
_081D7D18: .4byte 0x0300019C
_081D7D1C:
	movs r2, #0
	str r2, [sp, #8]
	movs r0, #0
_081D7D22:
	str r0, [sp, #0xc]
	movs r0, #0x68
	movs r1, #0
	bl VM_GetKeywordValue
	movs r1, #0xf4
	adds r1, r1, r7
	mov sb, r1
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xf6
	strh r0, [r1]
	mov r8, r7
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r6, r7, #0
	adds r6, #0x8c
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r1, sb
	str r1, [sp, #0x18]
	mov sb, r4
	str r6, [sp, #0x10]
	cmp r2, r0
	beq _081D7D8C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D7D94
_081D7D8C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7D94:
	str r0, [r7]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7DBA
	mov r2, r8
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _081D7DC6
_081D7DBA:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D7DC6:
	str r0, [r2]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081D7DFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081D7E34
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7E00
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081D7DF6
	ldrb r0, [r6, #5]
_081D7DF6:
	subs r0, #1
	strh r0, [r6, #8]
	b _081D7E10
	.align 2, 0
_081D7DFC: .4byte 0x0000FFFF
_081D7E00:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081D7E10
	strh r1, [r6, #8]
_081D7E10:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7E34
	movs r0, #1
	strb r0, [r6, #7]
_081D7E34:
	mov r1, r8
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081D7E60 @ =0x00000109
	adds r1, r7, r2
	movs r6, #0
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D7E64
	cmp r0, #1
	beq _081D7E94
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r7, r0
	b _081D7EC8
	.align 2, 0
_081D7E60: .4byte 0x00000109
_081D7E64:
	ldr r1, _081D7E90 @ =0x00004FDA
	mov r0, sb
	bl Video_GetAuxSprite
	mov r2, sl
	ldr r1, [r2, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0xfe
	strh r4, [r0]
	movs r0, #3
	mov r1, r8
	strb r0, [r1, #7]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r7, r2
	b _081D7EC8
	.align 2, 0
_081D7E90: .4byte 0x00004FDA
_081D7E94:
	ldr r1, _081D7F1C @ =0x0000863A
	mov r0, sb
	bl Video_GetAuxSprite
	mov r0, sl
	ldr r1, [r0, #0x1c]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r1, r7, #0
	adds r1, #0xfe
	movs r3, #2
	movs r0, #2
	strh r0, [r1]
	movs r2, #4
	adds r0, #0xfe
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	strb r3, [r2, #7]
	adds r4, r1, #0
_081D7EC8:
	ldr r0, _081D7F20 @ =0x00000105
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #3
	bl Div
	adds r1, r7, #0
	adds r1, #0xf8
	str r0, [r1]
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r7, #0
	bl FUN_081d6eb8
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D7F18
	cmp r1, #0
	blt _081D7F18
	ldr r0, _081D7F24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D7F18
	ldr r0, _081D7F28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D7F2C
_081D7F18:
	movs r2, #0
	b _081D7F3A
	.align 2, 0
_081D7F1C: .4byte 0x0000863A
_081D7F20: .4byte 0x00000105
_081D7F24: .4byte 0x030046A8
_081D7F28: .4byte 0x030046AC
_081D7F2C:
	ldr r0, _081D7FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_081D7F3A:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r3, [r7, #0x1e]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0
	str r1, [sp]
	movs r5, #0x80
	str r5, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x50
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D7F70
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_081D7F70:
	ldr r0, [sp, #0x14]
	bl FUN_08241574
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D7FC8
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	adds r4, r7, #0
	adds r4, #0x48
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	adds r1, #0x6f
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0x14]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_0823b46c
	adds r0, r4, #0
	bl FUN_08002a48
	b _081D7FD2
	.align 2, 0
_081D7FC4: .4byte 0x030046A4
_081D7FC8:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081D7FD2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
