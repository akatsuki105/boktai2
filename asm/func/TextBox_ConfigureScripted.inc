	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08047E84 @ =0x030000C4
	ldr r7, [r0]
	cmp r7, #0
	beq _08047E7C
	movs r0, #0x18
	adds r0, r0, r7
	mov r8, r0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047E36
	bl FUN_0823d340
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	cmp r1, #0
	beq _08047E7C
	adds r0, r1, #0
	bl TextBox_Start
_08047E36:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047E62
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r3, r0, #0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl TextBox_SetRect
_08047E62:
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0x63
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r7, #0
	bl TextBox_LoadBgPltt
	cmp r0, #0
	bge _08047E88
_08047E7C:
	movs r0, #1
	rsbs r0, r0, #0
	b _08047F72
	.align 2, 0
_08047E84: .4byte 0x030000C4
_08047E88:
	adds r0, r7, #0
	bl TextBox_UploadBgPltt
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r7, r0
	ldrh r1, [r4]
	movs r0, #0x69
	bl VM_GetKeywordValue
	strh r0, [r4]
	mov r2, r8
	ldrb r1, [r2, #0x11]
	movs r0, #0x6d
	bl VM_GetKeywordValue
	mov r3, r8
	strb r0, [r3, #0x11]
	ldr r0, _08047EF0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	movs r0, #0x77
	bl VM_GetKeywordValue
	mov r3, r8
	strb r0, [r3, #9]
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08047EF4
	bl Script_GetValue
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl Script_GetValue
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	str r0, [r1]
	b _08047F0C
	.align 2, 0
_08047EF0: .4byte 0x030046A0
_08047EF4:
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
	adds r3, #0x12
	adds r0, r7, r3
	str r2, [r0]
_08047F0C:
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08047F48
	movs r0, #0
	mov r1, r8
	strb r0, [r1, #0xd]
	b _08047F40
_08047F28:
	bl Script_GetValue
	mov r3, r8
	ldrb r2, [r3, #0xd]
	lsls r2, r2, #2
	mov r1, r8
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r3, #0xd]
	adds r0, #1
	strb r0, [r3, #0xd]
_08047F40:
	bl VM_GetPC
	cmp r0, #0
	bne _08047F28
_08047F48:
	movs r0, #0x61
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08047F6C
	bl Script_GetValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08047F72
	ldr r1, _08047F68 @ =0x0000017F
	adds r2, r7, r1
	movs r1, #0
	strb r1, [r2]
	b _08047F72
	.align 2, 0
_08047F68: .4byte 0x0000017F
_08047F6C:
	ldr r3, _08047F7C @ =0x0000017F
	adds r1, r7, r3
	strb r2, [r1]
_08047F72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08047F7C: .4byte 0x0000017F
