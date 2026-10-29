	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	mov sb, r1
	mov r8, r5
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FF3AC
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #6
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
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	ldr r4, _081FF42C @ =0x000003C6
	adds r1, r5, r4
	movs r0, #4
	strh r0, [r1]
_081FF3AC:
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
	mov sl, r0
	movs r2, #0x10
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r4, _081FF430 @ =0x085AE660
	mov ip, r4
	ldr r0, _081FF42C @ =0x000003C6
	adds r3, r5, r0
	ldrh r0, [r3]
	lsls r0, r0, #3
	add ip, r0
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldrh r1, [r2]
	mov r4, ip
	ldr r0, [r4]
	cmp r1, r0
	bls _081FF406
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r3]
	cmp r0, #0
	beq _081FF406
	subs r0, #1
	strh r0, [r3]
_081FF406:
	movs r6, #0xcf
	lsls r6, r6, #2
	add r6, r8
	adds r2, r5, #0
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
	blt _081FF434
	asrs r0, r0, #8
	b _081FF43A
	.align 2, 0
_081FF42C: .4byte 0x000003C6
_081FF430: .4byte 0x085AE660
_081FF434:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF43A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF44C
	asrs r0, r0, #8
	b _081FF452
_081FF44C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF452:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081FF466
	asrs r0, r0, #8
	b _081FF46C
_081FF466:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF46C:
	subs r2, r4, r0
	movs r7, #0
	adds r4, r4, r0
	ldr r3, _081FF560 @ =0x030047C8
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
	movs r3, #0xcf
	lsls r3, r3, #2
	add r3, r8
	mov r1, ip
	ldrh r0, [r1, #4]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldr r1, _081FF564 @ =0x0000033E
	add r1, r8
	mov r4, ip
	ldrh r0, [r4, #6]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0xed
	lsls r2, r2, #2
	add r2, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r6, #0xc7
	lsls r6, r6, #2
	add r6, r8
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r4, #0xe6
	lsls r4, r4, #2
	add r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	mov r0, r8
	mov r1, sb
	bl FUN_081fedec
	mov r0, sl
	cmp r0, #0
	beq _081FF57C
	adds r0, r5, #0
	adds r0, #0xa7
	movs r2, #1
	strb r2, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	add r1, r8
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r6, #8]
	orrs r0, r2
	str r0, [r6, #8]
	ldr r0, [r4]
	orrs r0, r2
	str r0, [r4]
	ldr r1, _081FF568 @ =FUN_081febb8
	movs r0, #0xb
	adds r3, r5, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	add r4, sp, #0x3c
	str r7, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FF56C @ =0x05000002
	bl CpuSet
	movs r0, #0xaf
	lsls r0, r0, #2
	add r0, r8
	ldr r2, _081FF570 @ =0x0000F422
	ldr r3, _081FF574 @ =0x0000121B
	movs r1, #6
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #9
	str r1, [sp, #8]
	ldr r1, _081FF578 @ =0x00000237
	str r1, [sp, #0xc]
	movs r1, #2
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	str r7, [sp, #0x1c]
	str r7, [sp, #0x20]
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	str r7, [sp, #0x2c]
	str r7, [sp, #0x30]
	str r7, [sp, #0x34]
	adds r1, r4, #0
	bl Entity081f26bc_Spawn
	b _081FF5BC
	.align 2, 0
_081FF560: .4byte 0x030047C8
_081FF564: .4byte 0x0000033E
_081FF568: .4byte FUN_081febb8
_081FF56C: .4byte 0x05000002
_081FF570: .4byte 0x0000F422
_081FF574: .4byte 0x0000121B
_081FF578: .4byte 0x00000237
_081FF57C:
	movs r0, #0xf
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne _081FF5BC
	ldr r2, _081FF5A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FF5AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FF5B0 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FF5B4
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FF5BC
	.align 2, 0
_081FF5A8: .4byte 0x030046B8
_081FF5AC: .4byte 0x000003FF
_081FF5B0: .4byte 0x0203B400
_081FF5B4:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FF5BC:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
