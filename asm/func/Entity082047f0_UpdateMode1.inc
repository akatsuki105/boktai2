	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r6, [r0]
	cmp r6, #1
	bne _08203D5C
	b _08203EF0
_08203D5C:
	cmp r6, #1
	bgt _08203D66
	cmp r6, #0
	beq _08203D6E
	b _082040C0
_08203D66:
	cmp r6, #2
	bne _08203D6C
	b _082040A4
_08203D6C:
	b _082040C0
_08203D6E:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _08203DE8
	cmp r2, #0
	bne _08203D86
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0xe2
	b _08203D8C
_08203D86:
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0x1e
_08203D8C:
	strb r0, [r1]
	movs r0, #0xfa
	strh r0, [r4, #0x3c]
	adds r0, r7, #0
	bl Entity082047f0_ShowElems
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r3, r0
	adds r0, r7, #0
	adds r0, #0xc9
	strb r3, [r0]
	ldr r2, _08203E18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08203E1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08203E20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #1
	ands r5, r0
	ldr r1, [r7, #0x18]
	movs r0, #0
	cmp r3, #1
	bls _08203DD6
	movs r0, #1
_08203DD6:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #7
	adds r3, r5, #0
	bl AuxAnim_SetAnim
	movs r0, #1
	mov r2, r8
	strb r0, [r2]
_08203DE8:
	adds r6, r4, #0
	adds r6, #0x10
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _08203E24
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08203E2C
	.align 2, 0
_08203E18: .4byte 0x030046B8
_08203E1C: .4byte 0x000003FF
_08203E20: .4byte 0x0203B400
_08203E24:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203E2C:
	str r0, [r4, #0x10]
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
	beq _08203E50
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08203E58
_08203E50:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08203E58:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08203E90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08203ED6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08203E9A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08203E94
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08203EB0
	.align 2, 0
_08203E90: .4byte 0x0000FFFF
_08203E94:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203EAE
_08203E9A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203EAE
	strh r1, [r4, #8]
	movs r2, #1
	b _08203EB0
_08203EAE:
	movs r2, #0
_08203EB0:
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
	bne _08203ED8
	movs r0, #1
	strb r0, [r4, #7]
	b _08203ED8
_08203ED6:
	movs r2, #0
_08203ED8:
	adds r0, r4, #0
	adds r0, #0x3f
	strb r2, [r0]
	cmp r2, #0
	bne _08203EE4
	b _082040C0
_08203EE4:
	adds r1, r4, #0
	adds r1, #0x42
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _082040C0
_08203EF0:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _08203F4A
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r3, r0
	adds r0, r7, #0
	adds r0, #0xc9
	strb r3, [r0]
	ldr r2, _08203F7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08203F80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08203F84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #1
	ands r5, r0
	ldr r1, [r7, #0x18]
	movs r0, #0
	cmp r3, #1
	bls _08203F3A
	movs r0, #1
_08203F3A:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #7
	adds r3, r5, #0
	bl AuxAnim_SetAnim
	mov r2, r8
	strb r6, [r2]
_08203F4A:
	adds r6, r4, #0
	adds r6, #0x10
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _08203F88
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08203F90
	.align 2, 0
_08203F7C: .4byte 0x030046B8
_08203F80: .4byte 0x000003FF
_08203F84: .4byte 0x0203B400
_08203F88:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203F90:
	str r0, [r4, #0x10]
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
	beq _08203FB4
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08203FBC
_08203FB4:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08203FBC:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08203FF4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0820403A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08203FFE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08203FF8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204014
	.align 2, 0
_08203FF4: .4byte 0x0000FFFF
_08203FF8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204012
_08203FFE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204012
	strh r1, [r4, #8]
	movs r2, #1
	b _08204014
_08204012:
	movs r2, #0
_08204014:
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
	bne _0820403C
	movs r0, #1
	strb r0, [r4, #7]
	b _0820403C
_0820403A:
	movs r2, #0
_0820403C:
	adds r6, r4, #0
	adds r6, #0x3f
	strb r2, [r6]
	cmp r2, #0
	beq _082040C0
	adds r0, r7, #0
	adds r0, #0xcb
	ldrb r5, [r0]
	cmp r5, #0
	beq _08204060
	adds r0, r4, #0
	adds r0, #0x42
	movs r1, #2
	strb r1, [r0]
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	b _082040C0
_08204060:
	ldr r2, _08204098 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0820409C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _082040A0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #1
	ands r3, r0
	ldr r1, [r7, #0x18]
	movs r2, #0
	adds r0, r7, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #1
	bls _08204088
	movs r2, #1
_08204088:
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #7
	bl AuxAnim_SetAnim
	strb r5, [r6]
	b _082040C0
	.align 2, 0
_08204098: .4byte 0x030046B8
_0820409C: .4byte 0x000003FF
_082040A0: .4byte 0x0203B400
_082040A4:
	adds r0, r4, #0
	adds r0, #0x2c
	bl Entity082047f0_SpawnEffect
	movs r0, #0xdb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #1
	b _082040C2
_082040C0:
	movs r0, #0
_082040C2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
