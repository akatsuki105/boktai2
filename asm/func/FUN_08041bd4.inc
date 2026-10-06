	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _08041C00 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08041BFA
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r7, r0, #0
	cmp r7, #0
	bne _08041C04
_08041BFA:
	movs r0, #1
	rsbs r0, r0, #0
	b _08041D4E
	.align 2, 0
_08041C00: .4byte 0x03002B50
_08041C04:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041C3C
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x61
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r7, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r7, #0x19]
_08041C3C:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041C98
	bl VM_GetValue
	ldr r1, _08041D24 @ =0x000001EF
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	bl VM_GetValue
	movs r2, #0x83
	lsls r2, r2, #2
	adds r4, r7, r2
	strh r0, [r4]
	bl VM_GetValue
	movs r3, #0x84
	lsls r3, r3, #2
	adds r6, r7, r3
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x5c
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r5, #0
	bl Mover_SetPath
	adds r0, r7, #0
	adds r0, #0x64
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r1, [r1]
	ldrb r2, [r6]
	bl Map_ReadPathNodePos
_08041C98:
	movs r0, #0x62
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041CC4
	bl VM_GetValue
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetValue
	ldr r2, _08041D28 @ =0x000001E9
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetValue
	movs r3, #0xf5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
_08041CC4:
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041CD4
	bl VM_GetValue
	str r0, [r7, #0x40]
_08041CD4:
	movs r0, #0x48
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041CFC
	bl VM_GetValue
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r3, _08041D2C @ =0x00000239
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _08041D30 @ =0x0000023B
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
_08041CFC:
	movs r0, #0x75
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041D0C
	bl VM_GetValue
	strb r0, [r7, #0xb]
_08041D0C:
	ldr r1, _08041D24 @ =0x000001EF
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08041D34
	adds r0, r7, #0
	bl FUN_08043510
	b _08041D36
	.align 2, 0
_08041D24: .4byte 0x000001EF
_08041D28: .4byte 0x000001E9
_08041D2C: .4byte 0x00000239
_08041D30: .4byte 0x0000023B
_08041D34:
	movs r0, #6
_08041D36:
	movs r1, #0
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	movs r0, #1
	strb r0, [r7, #8]
	ldr r2, _08041D5C @ =0x00000217
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_08041D4E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08041D5C: .4byte 0x00000217
