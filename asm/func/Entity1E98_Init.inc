	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldrb r1, [r0, #0x18]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x3c
	mov r1, sb
	adds r5, r1, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4B82
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
	mov sl, r1
	b _080A4B8A
_080A4B82:
	adds r0, r5, #0
	adds r0, #0xe6
	strh r1, [r0]
	mov sl, r0
_080A4B8A:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4BB8
	bl VM_GetValue
	adds r4, r5, #0
	adds r4, #0xdc
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xde
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe0
	strh r0, [r1]
	adds r6, r4, #0
	b _080A4BCA
_080A4BB8:
	adds r1, r5, #0
	adds r1, #0xdc
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xde
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r6, r1, #0
_080A4BCA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A4BEE
	cmp r1, #0
	blt _080A4BEE
	ldr r0, _080A4BF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A4BEE
	ldr r0, _080A4BF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A4BFC
_080A4BEE:
	movs r0, #0
	b _080A4C0A
	.align 2, 0
_080A4BF4: .4byte 0x030046A8
_080A4BF8: .4byte 0x030046AC
_080A4BFC:
	ldr r0, _080A4C24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A4C0A:
	adds r2, r5, #0
	adds r2, #0xea
	strh r0, [r2]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4C28
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe4
	b _080A4C2E
	.align 2, 0
_080A4C24: .4byte 0x030046A4
_080A4C28:
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
_080A4C2E:
	strb r0, [r1]
	mov r8, r1
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _080A4CB8 @ =0x0000D166
	cmp r0, #0
	bne _080A4C3E
	ldr r1, _080A4CBC @ =0x0000C3C3
_080A4C3E:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strb r0, [r5, #7]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4C72
	bl VM_GetValue
	cmp r0, #0
	beq _080A4C72
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A4C72:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CC0
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4CC6
	adds r4, r5, #0
	adds r4, #0x98
	mov r0, sl
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A4CC6
	.align 2, 0
_080A4CB8: .4byte 0x0000D166
_080A4CBC: .4byte 0x0000C3C3
_080A4CC0:
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
_080A4CC6:
	adds r0, r5, #0
	adds r0, #0xf0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CE2
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xf2
	b _080A4CE8
_080A4CE2:
	adds r1, r5, #0
	adds r1, #0xf2
	movs r0, #0xa
_080A4CE8:
	strh r0, [r1]
	movs r0, #0x57
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CF8
	bl VM_GetValue
_080A4CF8:
	adds r1, r5, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r5, #0
	bl Entity1E98_InitHurtbox
	adds r1, r5, #0
	adds r1, #0xf4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4D26
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xf6
	strb r0, [r1]
	adds r0, r1, #0
	b _080A4D2C
_080A4D26:
	adds r0, r5, #0
	adds r0, #0xf6
	strb r1, [r0]
_080A4D2C:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A4D64
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r7, #0x10]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _080A4D5C
	movs r0, #2
	strb r0, [r7, #7]
	ldr r1, _080A4D58 @ =0x080A4729
	b _080A4D7A
	.align 2, 0
_080A4D58: .4byte 0x080A4729
_080A4D5C:
	ldr r1, _080A4D60 @ =FUN_080a4854
	b _080A4D7A
	.align 2, 0
_080A4D60: .4byte FUN_080a4854
_080A4D64:
	adds r1, r5, #0
	adds r1, #0xf7
	strb r0, [r1]
	strh r0, [r7, #0x10]
	movs r0, #3
	strb r0, [r7, #7]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A4D88
	ldr r1, _080A4D84 @ =FUN_080a4670
_080A4D7A:
	adds r0, r5, #0
	bl Entity1E98_SetUpdateCallback
	b _080A4D90
	.align 2, 0
_080A4D84: .4byte FUN_080a4670
_080A4D88:
	ldr r1, _080A4DB4 @ =FUN_080a472c
	adds r0, r5, #0
	bl Entity1E98_SetUpdateCallback
_080A4D90:
	movs r0, #0x67
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4DB8
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe8
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	b _080A4DC8
	.align 2, 0
_080A4DB4: .4byte FUN_080a472c
_080A4DB8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, _080A4DE0 @ =0x0000FFFF
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080A4DC8:
	mov r2, sb
	ldrb r0, [r2, #0x18]
	adds r0, #1
	strb r0, [r2, #0x18]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4DE0: .4byte 0x0000FFFF
