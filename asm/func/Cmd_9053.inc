	push {r4, r5, lr}
	sub sp, #0x3c
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
	str r0, [sp, #0x1c]
	movs r0, #0x61
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [sp, #0x2c]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080016C8
	bl VM_GetPC
	cmp r0, #0
	beq _080016B8
	bl VM_GetValueAt
_080016B8:
	str r0, [sp, #4]
	bl VM_GetPC
	cmp r0, #0
	beq _080016CA
	bl VM_GetValueAt
	b _080016CA
_080016C8:
	str r0, [sp, #4]
_080016CA:
	str r0, [sp, #8]
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080016F6
	bl VM_GetPC
	cmp r0, #0
	beq _080016E4
	bl VM_GetValueAt
	lsls r0, r0, #4
_080016E4:
	str r0, [sp, #0xc]
	bl VM_GetPC
	cmp r0, #0
	beq _080016F8
	bl VM_GetValueAt
	lsls r0, r0, #4
	b _080016F8
_080016F6:
	str r0, [sp, #0xc]
_080016F8:
	str r0, [sp, #0x10]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08001720
	bl VM_GetPC
	cmp r0, #0
	beq _08001710
	bl VM_GetValueAt
_08001710:
	str r0, [sp, #0x14]
	bl VM_GetPC
	cmp r0, #0
	beq _08001722
	bl VM_GetValueAt
	b _08001722
_08001720:
	str r0, [sp, #0x14]
_08001722:
	str r0, [sp, #0x18]
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800174A
	bl VM_GetPC
	cmp r0, #0
	beq _0800173A
	bl VM_GetValueAt
_0800173A:
	str r0, [sp, #0x20]
	bl VM_GetPC
	cmp r0, #0
	beq _0800174C
	bl VM_GetValueAt
	b _0800174C
_0800174A:
	str r0, [sp, #0x20]
_0800174C:
	str r0, [sp, #0x24]
	movs r0, #0x62
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08001786
	bl VM_GetPC
	cmp r0, #0
	beq _0800176A
	bl VM_GetValueAt
	adds r4, r0, #0
	b _0800176C
_0800176A:
	movs r4, #0
_0800176C:
	bl VM_GetPC
	cmp r0, #0
	beq _0800177A
	bl VM_GetValueAt
	b _0800177C
_0800177A:
	movs r0, #8
_0800177C:
	str r4, [sp, #0x34]
	str r0, [sp, #0x38]
	movs r0, #1
	str r0, [sp, #0x30]
	b _0800178E
_08001786:
	movs r0, #0x10
	str r0, [sp, #0x34]
	str r0, [sp, #0x38]
	str r1, [sp, #0x30]
_0800178E:
	mov r0, sp
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080017B6
	cmp r0, #1
	bgt _080017A0
	cmp r0, #0
	beq _080017AA
	b _080017C0
_080017A0:
	cmp r0, #2
	beq _080017B0
	cmp r0, #3
	beq _080017B6
	b _080017C0
_080017AA:
	movs r0, #0x70
	movs r1, #0
	b _080017BA
_080017B0:
	movs r0, #0x70
	movs r1, #3
	b _080017BA
_080017B6:
	movs r0, #0x70
	movs r1, #1
_080017BA:
	bl VM_GetNamedArgValue
	str r0, [sp, #0x28]
_080017C0:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl Entity08001610_Create
	add sp, #0x3c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
