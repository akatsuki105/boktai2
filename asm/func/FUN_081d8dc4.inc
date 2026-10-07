	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	adds r6, r1, #0
	adds r3, r6, #0
	adds r3, #0x74
	ldrb r0, [r3]
	cmp r0, #0
	bne _081D8DDC
	b _081D8F10
_081D8DDC:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r2, r6, #0
	adds r2, #0x72
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
	ldr r5, _081D8E48 @ =0x0203B400
	ldr r2, _081D8E4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8E50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r3, #1
	strb r0, [r3]
	ldrb r4, [r3]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r5, r6, #0
	adds r5, #0x58
	adds r7, r4, #0
	adds r1, #3
	mov ip, r1
	ldr r4, _081D8E54 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E58
	asrs r1, r0, #0xc
	b _081D8E5E
	.align 2, 0
_081D8E48: .4byte 0x0203B400
_081D8E4C: .4byte 0x030046B8
_081D8E50: .4byte 0x000003FF
_081D8E54: .4byte 0x085B0A08
_081D8E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D8E5E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r7, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081D8E7A
	asrs r0, r0, #0xc
	b _081D8E80
_081D8E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D8E80:
	strh r0, [r5, #4]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D8EC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081D8ECC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #4
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D8EC4
	cmp r1, #0
	blt _081D8EC4
	ldr r0, _081D8ED0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8EC4
	ldr r0, _081D8ED4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8ED8
_081D8EC4:
	movs r0, #0
	b _081D8EE6
	.align 2, 0
_081D8EC8: .4byte 0x000003FF
_081D8ECC: .4byte 0x0203B400
_081D8ED0: .4byte 0x030046A8
_081D8ED4: .4byte 0x030046AC
_081D8ED8:
	ldr r0, _081D8F40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D8EE6:
	adds r2, r6, #0
	adds r2, #0x76
	strh r0, [r2]
	ldrb r0, [r3]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	adds r0, r6, #0
	adds r0, #0x2c
	mov r2, r8
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #4
	bl AuxAnim_SetAnim
_081D8F10:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D8F5E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D8F44 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _081D8F48 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8F4C
	movs r0, #1
	b _081D8F4E
	.align 2, 0
_081D8F40: .4byte 0x030046A4
_081D8F44: .4byte 0x030046A0
_081D8F48: .4byte 0x00000934
_081D8F4C:
	movs r0, #0
_081D8F4E:
	cmp r0, #0
	bne _081D8F5E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D8F6E
_081D8F5E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	b _081D918E
_081D8F6E:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _081D8F98
	cmp r1, #0
	blt _081D8F98
	ldr r0, _081D8F9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D8F98
	ldr r0, _081D8FA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D8FA4
_081D8F98:
	movs r4, #0
	b _081D8FB2
	.align 2, 0
_081D8F9C: .4byte 0x030046A8
_081D8FA0: .4byte 0x030046AC
_081D8FA4:
	ldr r0, _081D8FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D8FB2:
	adds r7, r5, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081D8FC8
	adds r0, #4
	b _081D8FD4
	.align 2, 0
_081D8FC4: .4byte 0x030046A4
_081D8FC8:
	ldr r0, _081D8FE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D8FD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081D8FEC
	cmp r2, #2
	beq _081D8FF0
	b _081D8FF4
	.align 2, 0
_081D8FE8: .4byte 0x030046A4
_081D8FEC:
	ldrb r0, [r7, #4]
	b _081D8FF2
_081D8FF0:
	ldrb r0, [r7]
_081D8FF2:
	subs r1, r1, r0
_081D8FF4:
	adds r7, r1, #0
	add r3, sp, #0xc
	adds r2, r6, #0
	adds r2, #0x58
	ldrh r1, [r6, #0x1c]
	ldrh r0, [r2]
	adds r1, r1, r0
	strh r1, [r3]
	ldrh r0, [r5, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r5, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081D9034
	cmp r1, #0
	blt _081D9034
	ldr r0, _081D9038 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081D9034
	ldr r0, _081D903C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D9040
_081D9034:
	movs r1, #0
	b _081D904E
	.align 2, 0
_081D9038: .4byte 0x030046A8
_081D903C: .4byte 0x030046AC
_081D9040:
	ldr r0, _081D9064 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r4
_081D904E:
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, r1
	bne _081D9068
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _081D9076
	.align 2, 0
_081D9064: .4byte 0x030046A4
_081D9068:
	movs r0, #0
	strh r0, [r2]
	adds r1, r6, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r3, #2]
	strh r0, [r6, #0x1e]
_081D9076:
	adds r1, r6, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r7, r0
	blt _081D90B0
	strh r7, [r6, #0x1e]
	add r0, sp, #8
	movs r1, #0
	str r1, [sp, #8]
	adds r1, r2, #0
	ldr r2, _081D90AC @ =0x05000002
	bl CpuSet
	adds r1, r6, #0
	adds r1, #0x68
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x74
	strb r2, [r0]
	b _081D918E
	.align 2, 0
_081D90AC: .4byte 0x05000002
_081D90B0:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D90E0
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D90E8
_081D90E0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D90E8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D910C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9114
_081D910C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9114:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D914C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9184
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9150
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9144
	ldrb r0, [r4, #5]
_081D9144:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D9160
	.align 2, 0
_081D914C: .4byte 0x0000FFFF
_081D9150:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D9160
	strh r1, [r4, #8]
_081D9160:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9184
	movs r0, #1
	strb r0, [r4, #7]
_081D9184:
	adds r1, r6, #0
	adds r1, #0x72
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081D918E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
