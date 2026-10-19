	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl Entity3117_FindEntry
	adds r5, r0, #0
	cmp r5, #0
	beq _080A51CC
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	adds r7, r5, #0
	adds r7, #0x98
	strb r0, [r7]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	adds r6, r5, #0
	adds r6, #0x99
	strb r0, [r6]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	strb r0, [r5, #3]
	movs r4, #0
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5130
	bl VM_GetValue
	adds r4, r0, #0
_080A5130:
	cmp r4, #0
	beq _080A514E
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_RestartAnim
	b _080A5166
_080A514E:
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
_080A5166:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5180
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
_080A5180:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A519A
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A51A0
_080A519A:
	adds r0, r5, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A51A0:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A51BE
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A51BE
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A51C4
_080A51BE:
	adds r0, r5, #0
	adds r0, #0xb0
	str r1, [r0]
_080A51C4:
	ldrb r1, [r5, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #2]
_080A51CC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
