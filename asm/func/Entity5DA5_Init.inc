	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r1
	ldr r0, _08008EA0 @ =0x03000038
	str r7, [r0]
	ldr r0, _08008EA4 @ =0x0000CB05
	ldr r1, _08008EA8 @ =0x0000F099
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008EAC
	movs r0, #1
	rsbs r0, r0, #0
	b _08009000
	.align 2, 0
_08008EA0: .4byte 0x03000038
_08008EA4: .4byte 0x0000CB05
_08008EA8: .4byte 0x0000F099
_08008EAC:
	adds r1, r7, #0
	adds r1, #0x4c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x4c
	adds r0, r6, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r4, #0
	movs r5, #0
	mov r0, r8
	strh r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r7, #0x1a]
	strh r5, [r7, #0x1c]
	strb r4, [r7, #0x1e]
	strb r4, [r7, #0x1f]
	str r5, [r7, #0x20]
	movs r0, #0x61
	bl VM_SeekToNamedArg
	str r6, [sp, #0x10]
	subs r6, #0xc
	movs r1, #0x44
	adds r1, r1, r7
	mov sb, r1
	movs r3, #0x3c
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0x6c
	adds r4, r4, r7
	mov sl, r4
	adds r5, r7, #0
	adds r5, #0xcc
	str r5, [sp, #0x14]
	cmp r0, #0
	beq _08008F24
	subs r5, #0xa8
	movs r4, #3
_08008F0E:
	bl VM_GetPC
	cmp r0, #0
	beq _08008F1C
	bl VM_GetValue
	str r0, [r5]
_08008F1C:
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _08008F0E
_08008F24:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08008F40
	bl VM_GetValue
	strh r0, [r7, #0x3c]
	bl VM_GetValue
	strh r0, [r7, #0x3e]
	bl VM_GetValue
	b _08008F44
_08008F40:
	strh r0, [r7, #0x3c]
	strh r0, [r7, #0x3e]
_08008F44:
	strh r0, [r6]
	mov r6, sb
	mov r5, r8
	ldrh r0, [r7, #0x3c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F66
	asrs r0, r0, #8
	b _08008F6C
_08008F66:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F6C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008F7E
	asrs r0, r0, #8
	b _08008F84
_08008F7E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F84:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008F98
	asrs r0, r0, #8
	b _08008F9E
_08008F98:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008F9E:
	subs r2, r4, r0
	movs r5, #0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _08009010 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #2
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	str r5, [sp]
	mov r0, sl
	ldr r1, [sp, #0x10]
	movs r2, #6
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r5, [sp, #0x14]
	movs r4, #0
_08008FEE:
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity5DA5Elem_Init
	adds r4, #1
	adds r5, #0xb8
	cmp r4, #3
	ble _08008FEE
_08009000:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08009010: .4byte 0x030047C8
