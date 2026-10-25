	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	mov r8, r1
	adds r5, r7, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FF1A4
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
	movs r2, #0x11
	movs r3, #1
	bl MainSprite_SetAnim
	movs r6, #0xaf
	lsls r6, r6, #2
	adds r2, r5, r6
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
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	ldr r6, _081FF1EC @ =0x000003C6
	adds r0, r5, r6
	strh r4, [r0]
_081FF1A4:
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	bl MainSprite_AdvanceAnim
	adds r4, r0, #0
	movs r0, #0xf
	mov r6, r8
	ands r0, r6
	cmp r0, #0
	bne _081FF204
	ldr r2, _081FF1F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FF1F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FF1F8 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FF1FC
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FF204
	.align 2, 0
_081FF1EC: .4byte 0x000003C6
_081FF1F0: .4byte 0x030046B8
_081FF1F4: .4byte 0x000003FF
_081FF1F8: .4byte 0x0203B400
_081FF1FC:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FF204:
	cmp r4, #0
	beq _081FF220
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #0
	strh r1, [r0]
	ldr r6, _081FF28C @ =0x000003C6
	adds r0, r5, r6
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FF220:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081FF290 @ =0x085AE688
	mov ip, r0
	ldr r1, _081FF28C @ =0x000003C6
	adds r3, r5, r1
	ldrh r0, [r3]
	lsls r0, r0, #3
	add ip, r0
	movs r6, #0xf1
	lsls r6, r6, #2
	adds r2, r5, r6
	ldrh r0, [r2]
	adds r0, #1
	movs r4, #0
	strh r0, [r2]
	ldrh r1, [r2]
	mov r6, ip
	ldr r0, [r6]
	cmp r1, r0
	blo _081FF264
	strh r4, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _081FF264
	strh r4, [r3]
_081FF264:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r6, r5, r0
	adds r2, r7, #0
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
	blt _081FF294
	asrs r0, r0, #8
	b _081FF29A
	.align 2, 0
_081FF28C: .4byte 0x000003C6
_081FF290: .4byte 0x085AE688
_081FF294:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF29A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF2AC
	asrs r0, r0, #8
	b _081FF2B2
_081FF2AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF2B2:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081FF2C6
	asrs r0, r0, #8
	b _081FF2CC
_081FF2C6:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF2CC:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _081FF344 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r3, r5, r1
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r6, [r3]
	adds r0, r0, r6
	strh r0, [r3]
	ldr r0, _081FF348 @ =0x0000033E
	adds r1, r5, r0
	ldrh r0, [r2, #6]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r6, #0xc7
	lsls r6, r6, #2
	adds r1, r5, r6
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	mov r1, r8
	bl FUN_081fedec
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FF344: .4byte 0x030047C8
_081FF348: .4byte 0x0000033E
