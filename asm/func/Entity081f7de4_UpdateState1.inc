	push {r4, r5, r6, lr}
	mov ip, r1
	mov r3, ip
	adds r3, #0x9a
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F7A32
	mov r0, ip
	adds r0, #0x98
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081F7A32:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F7A8C @ =0x030047A4
	ldr r1, _081F7A90 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _081F7A48
	b _081F7B54
_081F7A48:
	movs r6, #4
	ldr r0, _081F7A94 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	beq _081F7A56
	b _081F7B54
_081F7A56:
	mov r4, ip
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
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
	beq _081F7A98
	mov r1, ip
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _081F7AA4
	.align 2, 0
_081F7A8C: .4byte 0x030047A4
_081F7A90: .4byte 0x030047A0
_081F7A94: .4byte 0x03002BC0
_081F7A98:
	mov r2, ip
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_081F7AA4:
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
	beq _081F7AC8
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F7AD2
_081F7AC8:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F7AD2:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F7B0C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F7B44
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F7B10
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F7B04
	ldrb r0, [r4, #5]
_081F7B04:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F7B20
	.align 2, 0
_081F7B0C: .4byte 0x0000FFFF
_081F7B10:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F7B20
	strh r1, [r4, #8]
_081F7B20:
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
	bne _081F7B44
	movs r0, #1
	strb r0, [r4, #7]
_081F7B44:
	mov r1, ip
	ldrb r0, [r1, #6]
	adds r0, #8
	strb r0, [r1, #6]
	adds r1, #0x98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F7B54:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
