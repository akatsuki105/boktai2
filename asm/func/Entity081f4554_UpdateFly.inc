	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r0, #0
	adds r6, r1, #0
	mov sb, r6
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0
	mov sl, r1
	movs r3, #0xab
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F3B94
	ldr r1, [r2, #0x18]
	mov r0, sl
	str r0, [sp]
	mov r0, r8
	movs r2, #0xe
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	ldr r2, _081F3B2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F3B30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081F3B34 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xad
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r4, [r1]
	movs r5, #0x18
	ldr r2, _081F3B38 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F3B3C
	asrs r1, r0, #0xc
	b _081F3B42
	.align 2, 0
_081F3B2C: .4byte 0x030046B8
_081F3B30: .4byte 0x000003FF
_081F3B34: .4byte 0x0203B400
_081F3B38: .4byte gSineTable
_081F3B3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F3B42:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081F3B5C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F3B60
	asrs r0, r0, #0xc
	b _081F3B66
	.align 2, 0
_081F3B5C: .4byte gSineTable
_081F3B60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F3B66:
	movs r2, #0
	movs r1, #0
	strh r0, [r3, #4]
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r3, r6, r0
	movs r0, #0x8c
	lsls r0, r0, #3
	strh r0, [r3]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r3, #8
	adds r0, r6, r3
	strb r2, [r0]
	adds r0, r6, #0
	bl Entity081f4554_BuildCurve
_081F3B94:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r1, [r0]
	add r4, sp, #4
	adds r3, r6, #0
	adds r3, #0x1c
	lsls r1, r1, #3
	adds r1, r1, r6
	adds r1, #0xd8
	ldrh r0, [r1]
	ldrh r2, [r6, #0x1c]
	subs r0, r0, r2
	adds r2, r4, #0
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r3, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _081F3C70
	adds r0, r4, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	cmp r1, #0
	ble _081F3C70
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _081F3BF6
	asrs r1, r0, #6
	b _081F3BFC
_081F3BF6:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_081F3BFC:
	adds r7, r1, #0
	cmp r7, #1
	bge _081F3C04
	movs r7, #1
_081F3C04:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xd8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r2, #0x1c
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r7, #0
	bl Div
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r5, r6, r3
	strh r0, [r5]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xdc
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x20
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r7, #0
	bl Div
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r5]
	ldrh r2, [r6, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	ldrh r0, [r1]
	ldrh r3, [r6, #0x20]
	adds r0, r0, r3
	strh r0, [r6, #0x20]
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	b _081F3CD6
_081F3C70:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bls _081F3CBA
	adds r0, r6, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r6, #0x1c]
	adds r0, r6, #0
	adds r0, #0xd4
	ldrh r0, [r0]
	strh r0, [r6, #0x20]
	adds r0, r6, #0
	bl Entity081f4554_BuildCurve
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x8c
	lsls r0, r0, #3
	strh r0, [r1]
	strb r4, [r5]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	mov sl, r0
	b _081F3CD6
_081F3CBA:
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xd8
	ldrh r0, [r0]
	strh r0, [r6, #0x1c]
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r6, r0
	adds r0, #0xdc
	ldrh r0, [r0]
	strh r0, [r6, #0x20]
_081F3CD6:
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _081F3CFC @ =gSineTable
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _081F3D00
	asrs r1, r0, #8
	b _081F3D06
	.align 2, 0
_081F3CFC: .4byte gSineTable
_081F3D00:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081F3D06:
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r0, r0, r1
	mov r3, sb
	strh r0, [r3, #0x1e]
	ldrh r1, [r3, #0x1c]
	subs r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r3, #0x20]
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r1]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	mov r2, sb
	strh r0, [r2, #0x10]
	mov r3, r8
	ldrb r0, [r3, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F3D6A
	mov r1, sb
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	b _081F3D76
_081F3D6A:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F3D76:
	mov r1, r8
	ldrb r0, [r1, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F3D9E
	mov r2, sb
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	str r0, [r2]
	b _081F3DAA
_081F3D9E:
	mov r3, sb
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F3DAA:
	mov r1, r8
	ldrh r0, [r1, #0xe]
	adds r0, #1
	strh r0, [r1, #0xe]
	ldr r3, _081F3DE4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #7]
	cmp r0, r1
	blo _081F3E28
	movs r0, #0
	mov r3, r8
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F3DF0
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F3DE8
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	b _081F3E02
	.align 2, 0
_081F3DE4: .4byte 0x0000FFFF
_081F3DE8:
	subs r0, #1
	mov r1, r8
	strh r0, [r1, #8]
	b _081F3E02
_081F3DF0:
	mov r3, r8
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F3E02
	strh r1, [r3, #8]
_081F3E02:
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F3E28
	movs r0, #1
	strb r0, [r3, #7]
_081F3E28:
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F3E3A
	subs r0, #1
	strh r0, [r1]
	b _081F3E54
_081F3E3A:
	mov r1, sl
	cmp r1, #0
	beq _081F3E54
	movs r2, #0xa9
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
_081F3E54:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
