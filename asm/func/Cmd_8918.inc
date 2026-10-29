	push {r4, r5, lr}
	ldr r4, _08205CE8 @ =0x03002C90
	ldr r0, [r4]
	cmp r0, #0
	bne _08205CBC
	b _08205DDC
_08205CBC:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08205CF0
	ldr r0, _08205CEC @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	bne _08205CD0
	b _08205DDC
_08205CD0:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Entity286F_FindNodeByMoverID
	adds r4, r0, #0
	cmp r4, #0
	beq _08205DDC
	b _08205CF2
	.align 2, 0
_08205CE8: .4byte 0x03002C90
_08205CEC: .4byte 0x03002B50
_08205CF0:
	ldr r4, [r4]
_08205CF2:
	movs r0, #0x10
	movs r1, #0
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r3, #1
	strb r3, [r4, #8]
	ldr r2, _08205DE4 @ =FUN_08205018
	movs r0, #0xe
	strb r0, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r2, [r0]
	str r1, [r4, #0x10]
	strb r3, [r4, #9]
	strb r1, [r4, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08205D3E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x66
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x68
	strh r0, [r1]
_08205D3E:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08205D7E
	bl VM_GetValue
	movs r1, #0x61
	adds r1, r1, r4
	mov ip, r1
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
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
	mov r5, ip
	ldrb r0, [r5]
	strb r0, [r4, #0x1b]
_08205D7E:
	movs r0, #0x77
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	ble _08205DDC
	ldr r0, _08205DE8 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r4, #0
	adds r3, #0x64
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	movs r1, #0x61
	adds r1, r1, r4
	mov ip, r1
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
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
	mov r5, ip
	ldrb r0, [r5]
	strb r0, [r4, #0x1b]
_08205DDC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08205DE4: .4byte FUN_08205018
_08205DE8: .4byte 0x03002BE0
