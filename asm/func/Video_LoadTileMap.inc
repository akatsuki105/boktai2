	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetTilemapFile
	adds r6, r0, #0
	add r4, sp, #0x1c
	adds r1, r4, #0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r4, #0xc]
	adds r0, r0, r6
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x10]
	adds r0, r0, r6
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x14]
	adds r0, r0, r6
	str r0, [r4, #0x14]
	movs r0, #0x74
	movs r1, #1
	bl VM_GetNamedArgValue
	mov sl, r0
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000D24
	bl VM_GetPC
	cmp r0, #0
	beq _08000D10
	bl VM_GetValueAt
	lsls r0, r0, #7
	b _08000D12
_08000D10:
	movs r0, #0
_08000D12:
	mov r8, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08000D28
	bl VM_GetValueAt
	lsls r7, r0, #7
	b _08000D2A
_08000D24:
	movs r2, #0
	mov r8, r2
_08000D28:
	movs r7, #0
_08000D2A:
	movs r0, #0x6e
	movs r1, #1
	bl VM_GetNamedArgValue
	mov sb, r0
	movs r5, #0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08000D6C
	bl VM_GetPC
	adds r2, r0, #0
	movs r5, #1
	add r4, sp, #0xc
_08000D4C:
	cmp r2, #0
	beq _08000D60
	adds r0, r2, #0
	bl VM_GetValueAt
	str r0, [r4]
	bl VM_GetPC
	adds r2, r0, #0
	b _08000D62
_08000D60:
	str r2, [r4]
_08000D62:
	adds r4, #4
	add r1, sp, #0x18
	cmp r4, r1
	ble _08000D4C
	b _08000D7A
_08000D6C:
	movs r4, #3
	add r1, sp, #0x18
_08000D70:
	str r4, [r1]
	subs r1, #4
	subs r4, #1
	cmp r4, #0
	bge _08000D70
_08000D7A:
	cmp r5, #0
	bne _08000DBA
	movs r0, #0x63
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08000DBA
	bl VM_GetPC
	adds r1, r0, #0
	add r5, sp, #0xc
	movs r4, #3
_08000D94:
	cmp r1, #0
	beq _08000DB2
	adds r0, r1, #0
	bl VM_GetValueAt
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r0, sp, #0x1c
	bl FUN_08000c84
	str r0, [r5]
	bl VM_GetPC
	adds r1, r0, #0
_08000DB2:
	adds r5, #4
	subs r4, #1
	cmp r4, #0
	bge _08000D94
_08000DBA:
	ldrb r1, [r6]
	cmp r1, #0x4d
	bne _08000DE4
	ldrb r1, [r6, #1]
	cmp r1, #0x50
	bne _08000DE4
	mov r5, r8
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	add r2, sp, #0xc
	str r2, [sp, #8]
	mov r0, sl
	movs r1, #0
	adds r2, r6, #0
	bl Video_SetupBGLayout
_08000DE4:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
