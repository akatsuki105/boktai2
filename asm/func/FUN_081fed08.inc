	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r7, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FED50
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0x10
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	bl NestedState_Reset0
_081FED50:
	movs r0, #0xf
	ands r0, r4
	cmp r0, #0
	bne _081FED90
	ldr r2, _081FED7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FED80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FED84 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FED88
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FED90
	.align 2, 0
_081FED7C: .4byte 0x030046B8
_081FED80: .4byte 0x000003FF
_081FED84: .4byte 0x0203B400
_081FED88:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FED90:
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r6, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	cmp r0, #0
	beq _081FEDCA
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x11
	movs r3, #1
	bl MainSprite_SetAnim
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FEDCA:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
