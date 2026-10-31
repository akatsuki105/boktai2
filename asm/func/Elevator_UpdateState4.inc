	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D2D96
	ldr r0, _081D2D3C @ =0x03000194
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd4
	ldr r2, _081D2D40 @ =0x000012B0
	adds r0, r0, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2D88
	adds r0, r4, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081D2D88
	adds r0, #0x25
	ldrb r1, [r0]
	cmp r1, #2
	bne _081D2D52
	subs r0, #0x33
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2D44
	movs r0, #1
	b _081D2D46
	.align 2, 0
_081D2D3C: .4byte 0x03000194
_081D2D40: .4byte 0x000012B0
_081D2D44:
	movs r0, #0
_081D2D46:
	cmp r0, #0
	beq _081D2D4E
	movs r0, #2
	b _081D2D58
_081D2D4E:
	movs r0, #1
	b _081D2D58
_081D2D52:
	adds r0, r4, #0
	adds r0, #0xea
	ldrb r0, [r0]
_081D2D58:
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xfc
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _081D2DF0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_081D2D88:
	adds r1, r4, #0
	adds r1, #0xb6
	movs r0, #0
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strh r0, [r1]
_081D2D96:
	adds r0, r4, #0
	bl FUN_081d27c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2DA4
	b _081D2EFA
_081D2DA4:
	adds r0, r4, #0
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D2E78
	adds r0, r4, #0
	adds r0, #0xb8
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0xbc
	adds r5, r0, #0
	adds r6, r1, #0
	ldrh r0, [r6]
	cmp r2, r0
	blt _081D2E60
	adds r0, r4, #0
	bl FUN_081d2c60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D2E60
	adds r0, r4, #0
	adds r0, #0xb2
	movs r2, #2
	strh r2, [r0]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081D2DF4
	movs r0, #1
	b _081D2DF6
	.align 2, 0
_081D2DF0: .4byte 0xFFFF0000
_081D2DF4:
	movs r0, #0
_081D2DF6:
	cmp r0, #0
	beq _081D2E04
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	b _081D2E0A
_081D2E04:
	movs r0, #2
	ldrh r1, [r2]
	orrs r0, r1
_081D2E0A:
	strh r0, [r2]
	movs r0, #0
	strh r0, [r5]
	adds r0, r4, #0
	adds r0, #0xb6
	movs r5, #1
	strb r5, [r0]
	ldr r0, _081D2E54 @ =0x03000194
	ldr r0, [r0]
	adds r3, r4, #0
	adds r3, #0xd4
	ldr r1, _081D2E58 @ =0x000012B0
	adds r0, r0, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bne _081D2EFA
	adds r2, r4, #0
	adds r2, #0xc4
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D2EFA
	adds r0, r1, #0
	str r0, [sp, #0x14]
	ldr r1, _081D2E5C @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r5
	str r0, [sp, #0x18]
	add r0, sp, #0x14
	add r1, sp, #0x18
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
	b _081D2EFA
	.align 2, 0
_081D2E54: .4byte 0x03000194
_081D2E58: .4byte 0x000012B0
_081D2E5C: .4byte 0xFFFF0000
_081D2E60:
	movs r2, #0
	ldrsh r1, [r5, r2]
	ldrh r0, [r6]
	subs r0, #0xa
	cmp r1, r0
	ble _081D2E78
	movs r0, #0x20
	adds r2, r4, #0
	adds r2, #0xb4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D2E78:
	ldr r0, _081D2EAC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x2c
	bl Elevator_FindAtPos
	adds r3, r0, #0
	cmp r3, #0
	beq _081D2EF0
	adds r0, #0xd4
	adds r1, r4, #0
	adds r1, #0xd4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D2EFA
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D2EB0
	movs r0, #1
	b _081D2EB2
	.align 2, 0
_081D2EAC: .4byte 0x03002BE0
_081D2EB0:
	movs r0, #0
_081D2EB2:
	adds r5, r4, #0
	adds r5, #0xb8
	cmp r0, #0
	bne _081D2ED0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _081D2ED0
	adds r0, r4, #0
	adds r0, #0xc6
	ldr r1, _081D2EE4 @ =0x0000FFE0
	strh r1, [r0]
	ldr r0, _081D2EE8 @ =0x00000222
	bl PlaySound_082406e0
_081D2ED0:
	ldrh r2, [r5]
	movs r0, #0
	ldrsh r1, [r5, r0]
	ldr r0, _081D2EEC @ =0x00007CFF
	cmp r1, r0
	bgt _081D2EFA
	adds r0, r2, #1
	strh r0, [r5]
	b _081D2EFA
	.align 2, 0
_081D2EE4: .4byte 0x0000FFE0
_081D2EE8: .4byte 0x00000222
_081D2EEC: .4byte 0x00007CFF
_081D2EF0:
	adds r0, r4, #0
	adds r0, #0xb8
	strh r3, [r0]
	adds r0, #0xe
	strh r3, [r0]
_081D2EFA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
