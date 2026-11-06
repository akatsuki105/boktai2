	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _081EFC88
	adds r0, r5, #0
	adds r0, #0x9b
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	adds r4, r2, #0
	cmp r1, #1
	bls _081EFC5E
	movs r0, #1
	strb r0, [r4]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081EFC64
_081EFC5E:
	movs r0, #0
	strb r0, [r4]
	strb r1, [r3]
_081EFC64:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x34]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0x13
	bl AuxAnim_SetAnim
	adds r1, r5, #0
	adds r1, #0x98
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x9a
	strb r2, [r0]
_081EFC88:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EFCB8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081EFCC0
_081EFCB8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EFCC0:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EFCE4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081EFCEC
_081EFCE4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EFCEC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EFD24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EFD5C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EFD28
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EFD1C
	ldrb r0, [r4, #5]
_081EFD1C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EFD38
	.align 2, 0
_081EFD24: .4byte 0x0000FFFF
_081EFD28:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EFD38
	strh r1, [r4, #8]
_081EFD38:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081EFD5C
	movs r0, #1
	strb r0, [r4, #7]
_081EFD5C:
	adds r0, r7, #0
	adds r1, r5, #0
	bl Entity081f0298_BlinkOut
	adds r1, r5, #0
	adds r1, #0x98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
