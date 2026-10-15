	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetNamedArgValue
	strb r0, [r5, #0x18]
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080199FC
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r4, r7, #0
_080199E4:
	bl VM_GetPC
	cmp r0, #0
	beq _080199F0
	bl VM_GetValue
_080199F0:
	strb r0, [r4]
	adds r4, #1
	adds r0, r7, #1
	cmp r4, r0
	ble _080199E4
	b _08019A16
_080199FC:
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r1, r7, #0
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x1a
_08019A0E:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A0E
_08019A16:
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08019A42
	movs r6, #0
	mov r4, r8
_08019A24:
	bl VM_GetPC
	cmp r0, #0
	beq _08019A36
	bl VM_GetValue
	adds r1, r7, r6
	ldrb r1, [r1]
	subs r0, r0, r1
_08019A36:
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	cmp r6, #1
	ble _08019A24
	b _08019A50
_08019A42:
	mov r1, r8
	movs r2, #0
	adds r0, r1, #1
_08019A48:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A48
_08019A50:
	movs r0, #0x73
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r4, #0
	strh r0, [r5, #0x20]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r5, #0x22]
	movs r0, #0x74
	movs r1, #0x3c
	bl VM_GetNamedArgValue
	str r0, [r5, #0x28]
	str r4, [r5, #0x24]
	cmp r0, #0
	bne _08019A7A
	movs r0, #0x3c
	str r0, [r5, #0x28]
_08019A7A:
	ldrb r0, [r5, #0x18]
	ldrh r1, [r5, #0x20]
	ldrh r2, [r5, #0x22]
	bl Video_SetBLDCNTDirect
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _08019A98
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	movs r1, #0x1a
	ldrsb r1, [r5, r1]
	bl Video_SetBLDALPHADirect
	b _08019AA0
_08019A98:
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	bl Video_SetBLDYDirect
_08019AA0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
