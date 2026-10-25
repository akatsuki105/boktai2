	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FEF8A
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0x12
	movs r3, #2
	bl MainSprite_SetAnim
	movs r7, #0xaf
	lsls r7, r7, #2
	adds r2, r5, r7
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	bl NestedState_Reset0
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	ldr r7, _081FEFB8 @ =0x000003C6
	adds r0, r5, r7
	strh r4, [r0]
_081FEF8A:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _081FEFD0
	ldr r2, _081FEFBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FEFC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FEFC4 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FEFC8
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FEFD0
	.align 2, 0
_081FEFB8: .4byte 0x000003C6
_081FEFBC: .4byte 0x030046B8
_081FEFC0: .4byte 0x000003FF
_081FEFC4: .4byte 0x0203B400
_081FEFC8:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FEFD0:
	movs r7, #0xa7
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	bl MainSprite_AdvanceAnim
	cmp r0, #0
	beq _081FF010
	adds r0, r6, #0
	adds r0, #0xa7
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _081FF084 @ =FUN_081ff148
	movs r0, #0x10
	adds r4, r6, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_081FF010:
	movs r2, #0x10
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r7, r8
	cmp r7, #0xd
	bgt _081FF024
	b _081FF132
_081FF024:
	ldr r0, _081FF088 @ =0x085AE708
	mov ip, r0
	ldr r1, _081FF08C @ =0x000003C6
	adds r3, r5, r1
	ldrh r0, [r3]
	lsls r0, r0, #3
	add ip, r0
	movs r7, #0xf1
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r0, [r2]
	adds r0, #1
	movs r4, #0
	strh r0, [r2]
	ldrh r1, [r2]
	mov r7, ip
	ldr r0, [r7]
	cmp r1, r0
	blo _081FF05C
	strh r4, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bls _081FF05C
	strh r4, [r3]
_081FF05C:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r7, r5, r0
	adds r2, r6, #0
	adds r2, #0x50
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF090
	asrs r0, r0, #8
	b _081FF096
	.align 2, 0
_081FF084: .4byte FUN_081ff148
_081FF088: .4byte 0x085AE708
_081FF08C: .4byte 0x000003C6
_081FF090:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF096:
	strh r0, [r7]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF0A8
	asrs r0, r0, #8
	b _081FF0AE
_081FF0A8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF0AE:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081FF0C2
	asrs r0, r0, #8
	b _081FF0C8
_081FF0C2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF0C8:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _081FF140 @ =0x030047C8
	ldrh r0, [r7]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r7]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r7, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r7, #4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r3, r5, r1
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r7, [r3]
	adds r0, r0, r7
	strh r0, [r3]
	ldr r0, _081FF144 @ =0x0000033E
	adds r1, r5, r0
	ldrh r0, [r2, #6]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r7, #0xed
	lsls r7, r7, #2
	adds r2, r5, r7
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	mov r1, r8
	bl FUN_081fedec
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	subs r7, #0x1c
	adds r1, r5, r7
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_081FF132:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FF140: .4byte 0x030047C8
_081FF144: .4byte 0x0000033E
