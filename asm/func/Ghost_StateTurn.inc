	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	ldr r0, _0816B60C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816B610
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816B612
	.align 2, 0
_0816B60C: .4byte 0x0000046D
_0816B610:
	movs r0, #0
_0816B612:
	cmp r0, #0
	beq _0816B6B0
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r3, r0, #3
	movs r1, #7
	ands r3, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	ands r0, r1
	cmp r3, r0
	bne _0816B680
	movs r1, #0
	strb r4, [r5, #5]
	ldr r2, _0816B674 @ =0x000005A4
	adds r0, r5, r2
	ldr r3, [r0]
	ldr r4, _0816B678 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _0816B67C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	b _0816B872
	.align 2, 0
_0816B674: .4byte 0x000005A4
_0816B678: .4byte 0x0000046D
_0816B67C: .4byte 0x0000046B
_0816B680:
	subs r0, #8
	subs r0, r3, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	bgt _0816B6A0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0816B69C @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0816B6B0
	.align 2, 0
_0816B69C: .4byte 0xFFFEFFFF
_0816B6A0:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816B6B0:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r1, _0816B6D4 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B6DC
	ldr r0, _0816B6D8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0816B6EC
	.align 2, 0
_0816B6D4: .4byte 0x0000A02F
_0816B6D8: .4byte 0x00000482
_0816B6DC:
	ldr r1, _0816B714 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0816B6EC
	movs r0, #1
	strh r0, [r2]
_0816B6EC:
	ldr r3, _0816B718 @ =0x0000025D
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _0816B71C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0816B734
	.align 2, 0
_0816B714: .4byte 0x00000482
_0816B718: .4byte 0x0000025D
_0816B71C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0816B734:
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B746
	b _0816B872
_0816B746:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0816B790 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816B794 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816B798
	ldrb r0, [r6, #5]
	adds r0, #0x20
	b _0816B79C
	.align 2, 0
_0816B790: .4byte 0x0000046D
_0816B794: .4byte 0x0000046B
_0816B798:
	ldrb r0, [r6, #5]
	subs r0, #0x20
_0816B79C:
	strb r0, [r6, #5]
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl Ghost_GetAnimVariant
	movs r0, #0
	mov r3, r8
	strb r0, [r3, #5]
	ldr r4, _0816B7E0 @ =0x000004C4
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B7EC
	ldr r1, _0816B7E4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r2, _0816B7E8 @ =0x0000046E
	adds r7, r5, r2
	b _0816B86E
	.align 2, 0
_0816B7E0: .4byte 0x000004C4
_0816B7E4: .4byte 0x000004B7
_0816B7E8: .4byte 0x0000046E
_0816B7EC:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r3, _0816B85C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0816B860 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0816B826
	ldrb r0, [r7]
	cmp r0, #0
	bne _0816B826
	cmp r4, #1
	bne _0816B818
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816B872
_0816B818:
	cmp r4, #0
	bne _0816B826
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816B872
_0816B826:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0816B838
	movs r3, #6
_0816B838:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0816B864
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0816B86C
	.align 2, 0
_0816B85C: .4byte 0x000004B7
_0816B860: .4byte 0x0000046E
_0816B864:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816B86C:
	str r0, [r6, #8]
_0816B86E:
	movs r0, #0
	strb r0, [r7]
_0816B872:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
