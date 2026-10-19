	push {r4, r5, lr}
	sub sp, #0x40
	adds r5, r0, #0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r1, sp
	strb r0, [r1]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r1, sp
	strb r0, [r1, #1]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r1, sp
	strh r0, [r1, #2]
	movs r0, #0x72
	movs r1, #0x80
	bl VM_GetNamedArgValue
	str r0, [sp, #0x14]
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _08000B48
	cmp r0, #1
	bgt _08000B32
	cmp r0, #0
	beq _08000B3C
	b _08000B52
_08000B32:
	cmp r0, #2
	beq _08000B42
	cmp r0, #3
	beq _08000B48
	b _08000B52
_08000B3C:
	movs r0, #0x70
	movs r1, #0
	b _08000B4C
_08000B42:
	movs r0, #0x70
	movs r1, #3
	b _08000B4C
_08000B48:
	movs r0, #0x70
	movs r1, #1
_08000B4C:
	bl VM_GetNamedArgValue
	str r0, [sp, #0x30]
_08000B52:
	movs r0, #0x61
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x34]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000B82
	bl VM_GetPC
	cmp r0, #0
	beq _08000B72
	bl VM_GetValueAt
_08000B72:
	str r0, [sp, #4]
	bl VM_GetPC
	cmp r0, #0
	beq _08000B84
	bl VM_GetValueAt
	b _08000B84
_08000B82:
	str r0, [sp, #4]
_08000B84:
	str r0, [sp, #8]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000BAC
	bl VM_GetPC
	cmp r0, #0
	beq _08000B9C
	bl VM_GetValueAt
_08000B9C:
	str r0, [sp, #0xc]
	bl VM_GetPC
	cmp r0, #0
	beq _08000BAE
	bl VM_GetValueAt
	b _08000BAE
_08000BAC:
	str r0, [sp, #0xc]
_08000BAE:
	str r0, [sp, #0x10]
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000BD6
	bl VM_GetPC
	cmp r0, #0
	beq _08000BC6
	bl VM_GetValueAt
_08000BC6:
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _08000BD8
	bl VM_GetValueAt
	b _08000BD8
_08000BD6:
	str r0, [sp, #0x18]
_08000BD8:
	str r0, [sp, #0x1c]
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000C04
	bl VM_GetPC
	cmp r0, #0
	beq _08000BF2
	bl VM_GetValueAt
	b _08000BF4
_08000BF2:
	movs r0, #0x78
_08000BF4:
	str r0, [sp, #0x20]
	bl VM_GetPC
	cmp r0, #0
	beq _08000C08
	bl VM_GetValueAt
	b _08000C0A
_08000C04:
	movs r0, #0x78
	str r0, [sp, #0x20]
_08000C08:
	movs r0, #0x5a
_08000C0A:
	str r0, [sp, #0x24]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000C32
	bl VM_GetPC
	cmp r0, #0
	beq _08000C22
	bl VM_GetValueAt
_08000C22:
	str r0, [sp, #0x28]
	bl VM_GetPC
	cmp r0, #0
	beq _08000C34
	bl VM_GetValueAt
	b _08000C34
_08000C32:
	str r0, [sp, #0x28]
_08000C34:
	str r0, [sp, #0x2c]
	movs r0, #0x62
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08000C72
	bl VM_GetPC
	cmp r0, #0
	beq _08000C50
	bl VM_GetValueAt
	adds r4, r0, #0
	b _08000C52
_08000C50:
	movs r4, #0
_08000C52:
	bl VM_GetPC
	cmp r0, #0
	beq _08000C62
	bl VM_GetValueAt
	adds r2, r0, #0
	b _08000C64
_08000C62:
	movs r2, #8
_08000C64:
	str r4, [sp, #0x38]
	str r2, [sp, #0x3c]
	mov r0, sp
	ldrb r0, [r0, #1]
	adds r1, r4, #0
	bl FUN_0822f178
_08000C72:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl Entity08000a94_Create
	add sp, #0x40
	pop {r4, r5}
	pop {r1}
	bx r1
