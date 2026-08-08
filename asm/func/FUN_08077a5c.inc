	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _08077A88 @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08077B24
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _08077A8C @ =0x0000043E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08077A90
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x20
	b _08077B22
	.align 2, 0
_08077A88: .4byte 0x0000037E
_08077A8C: .4byte 0x0000043E
_08077A90:
	ldr r1, _08077AB4 @ =0x0000038E
	adds r0, r6, r1
	ldrb r0, [r0]
	ldr r1, _08077AB8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	ble _08077ABC
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x21
	b _08077B22
	.align 2, 0
_08077AB4: .4byte 0x0000038E
_08077AB8: .4byte 0x030046A0
_08077ABC:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08077AD8
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x94
	lsls r0, r0, #1
	b _08077B22
_08077AD8:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08077AF0
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _08077AEC @ =0x00000129
	b _08077B22
	.align 2, 0
_08077AEC: .4byte 0x00000129
_08077AF0:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08077B04
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x95
	lsls r0, r0, #1
	b _08077B22
_08077B04:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08077B1C
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _08077B18 @ =0x0000012B
	b _08077B22
	.align 2, 0
_08077B18: .4byte 0x0000012B
_08077B1C:
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x26
_08077B22:
	strh r0, [r1]
_08077B24:
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, #0x28
	ldr r0, _08077BB8 @ =0x03003584
	adds r1, r6, #0
	adds r1, #0xc2
	ldrh r1, [r1]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _08077BBC @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bls _08077B64
	b _08077C66
_08077B64:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r6, r2
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r2, #0x4b
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, #8
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077BC0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08077BC8
	.align 2, 0
_08077BB8: .4byte 0x03003584
_08077BBC: .4byte 0x0000037E
_08077BC0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08077BC8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08077BEC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08077BF4
_08077BEC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08077BF4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08077C2C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08077C78
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08077C30
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08077C24
	ldrb r0, [r4, #5]
_08077C24:
	subs r0, #1
	strh r0, [r4, #8]
	b _08077C40
	.align 2, 0
_08077C2C: .4byte 0x0000FFFF
_08077C30:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08077C40
	strh r1, [r4, #8]
_08077C40:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _08077C78
	movs r0, #1
	strb r0, [r4, #7]
	b _08077C78
_08077C66:
	lsrs r0, r1, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08077C78
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
_08077C78:
	ldr r0, _08077CB0 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _08077CA6
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	ldr r2, _08077CB4 @ =0x00000381
	adds r0, r6, r2
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_08072620
	ldr r1, _08077CB8 @ =0x000004AF
	adds r0, r6, r1
	strb r4, [r0]
_08077CA6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08077CB0: .4byte 0x0000037E
_08077CB4: .4byte 0x00000381
_08077CB8: .4byte 0x000004AF
