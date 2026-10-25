	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C65A2
	movs r1, #0
	strb r1, [r2]
	ldr r2, _080C6698 @ =0x000025FE
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _080C669C @ =0x00002602
	adds r0, r6, r3
	movs r2, #0
	strh r1, [r0]
	ldr r4, _080C66A0 @ =0x000025FF
	adds r0, r6, r4
	strb r2, [r0]
	movs r5, #0x98
	lsls r5, r5, #6
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _080C66A4 @ =0x00002606
	adds r0, r6, r1
	bl HUD_StartCountdown
	ldr r2, _080C66A8 @ =0x00002604
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r6, #0
	adds r2, #0x90
	strh r0, [r2]
	ldr r3, _080C66AC @ =0x030046A0
	ldr r0, [r3]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r2, r5]
	str r1, [r0]
	ldr r0, [r3]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	str r1, [r0]
_080C65A2:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0
	mov sl, r4
	adds r0, r6, #0
	bl FUN_080c4114
	ldr r5, _080C66AC @ =0x030046A0
	ldr r0, [r5]
	ldr r1, _080C66B0 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r7, [r0, r2]
	ldr r0, _080C66B4 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C66BC
	cmp r7, #0
	ble _080C66BC
	movs r3, #0x98
	lsls r3, r3, #6
	adds r4, r6, r3
	ldrb r0, [r4]
	cmp r0, #0
	bne _080C65F8
	ldr r1, _080C66B8 @ =0x085AD0FA
	ldr r2, _080C6698 @ =0x000025FE
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
_080C65F8:
	ldr r3, _080C669C @ =0x00002602
	adds r2, r6, r3
	ldrh r0, [r2]
	adds r0, r0, r7
	strh r0, [r2]
	ldr r1, [r5]
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x90
	strh r1, [r0]
	lsls r1, r1, #0x10
	cmp r1, #0
	bge _080C661E
	mov r5, sl
	strh r5, [r0]
_080C661E:
	ldrh r4, [r2]
	ldr r0, _080C6698 @ =0x000025FE
	adds r5, r6, r0
	ldrb r0, [r5]
	adds r0, #1
	ldr r2, _080C66A8 @ =0x00002604
	adds r1, r6, r2
	ldrh r1, [r1]
	muls r0, r1, r0
	movs r1, #6
	bl Div
	cmp r4, r0
	blt _080C667A
	movs r3, #1
	mov sl, r3
	ldrb r1, [r5]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _080C665E
	cmp r1, #5
	beq _080C665E
	ldrb r0, [r5]
	adds r0, #1
	asrs r0, r0, #1
	ldr r1, _080C66B8 @ =0x085AD0FA
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
_080C665E:
	ldr r4, _080C669C @ =0x00002602
	adds r0, r6, r4
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r5, _080C66A8 @ =0x00002604
	adds r1, r6, r5
	ldrh r1, [r1]
	bl Div
	ldr r2, _080C6698 @ =0x000025FE
	adds r1, r6, r2
	strb r0, [r1]
_080C667A:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080c3fd0
	ldr r3, _080C66A0 @ =0x000025FF
	adds r4, r6, r3
	ldrb r0, [r4]
	cmp r0, #0
	bne _080C66CA
	movs r0, #0xd9
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
	b _080C66CA
	.align 2, 0
_080C6698: .4byte 0x000025FE
_080C669C: .4byte 0x00002602
_080C66A0: .4byte 0x000025FF
_080C66A4: .4byte 0x00002606
_080C66A8: .4byte 0x00002604
_080C66AC: .4byte 0x030046A0
_080C66B0: .4byte 0x00000942
_080C66B4: .4byte 0x030044E0
_080C66B8: .4byte 0x085AD0FA
_080C66BC:
	movs r0, #0xd9
	bl sound_08240740
	ldr r4, _080C67C4 @ =0x000025FF
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_080C66CA:
	ldr r5, _080C67C8 @ =0x00002601
	adds r7, r6, r5
	ldr r0, _080C67CC @ =0x000025FE
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	ldrb r1, [r7]
	adds r0, r0, r1
	movs r2, #0
	mov sb, r2
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _080C677A
	ldr r4, _080C67D0 @ =0xFFFF0000
	ldr r3, _080C67D4 @ =0x0000FFFF
	mov ip, r3
	str r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	str r0, [sp, #0x14]
	ldr r2, _080C67D8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C67DC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080C67E0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r3, [r0]
	asrs r3, r3, #3
	movs r2, #0x7f
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	ldr r5, _080C67E4 @ =0x000002EA
	adds r0, r6, r5
	ldrh r0, [r0]
	ands r3, r2
	adds r0, r3, r0
	lsls r0, r0, #0x10
	mov r2, ip
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x18]
	adds r5, #2
	adds r1, r6, r5
	ldr r2, _080C67E8 @ =0xFFFFFE00
	adds r0, r2, #0
	adds r3, r3, r0
	ldrh r2, [r1]
	subs r2, r2, r3
	subs r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x18
	ldr r1, [r0, #4]
	ands r1, r4
	orrs r1, r2
	str r1, [r0, #4]
	mov r3, sb
	str r3, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	add r2, sp, #0x10
	movs r3, #0
	bl EmitSmoke
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080c4a54
	ldrb r0, [r7]
	subs r0, #0x10
	strb r0, [r7]
_080C677A:
	ldr r4, _080C67EC @ =0x00002606
	adds r0, r6, r4
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	mov r5, r8
	ldrb r0, [r5]
	cmp r0, #6
	bne _080C67F4
	bl HUD_RemoveCountdown
	ldr r1, _080C67F0 @ =FUN_080c6a5c
	movs r0, #0x3a
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r1, sb
	str r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080c4254
	movs r0, #0xd9
	bl sound_08240740
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080c6500
	b _080C6840
	.align 2, 0
_080C67C4: .4byte 0x000025FF
_080C67C8: .4byte 0x00002601
_080C67CC: .4byte 0x000025FE
_080C67D0: .4byte 0xFFFF0000
_080C67D4: .4byte 0x0000FFFF
_080C67D8: .4byte 0x030046B8
_080C67DC: .4byte 0x000003FF
_080C67E0: .4byte 0x0203B400
_080C67E4: .4byte 0x000002EA
_080C67E8: .4byte 0xFFFFFE00
_080C67EC: .4byte 0x00002606
_080C67F0: .4byte FUN_080c6a5c
_080C67F4:
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _080C6830
	bl HUD_RemoveCountdown
	adds r0, r6, #0
	bl FUN_080c4254
	movs r0, #0xd9
	bl sound_08240740
	ldr r1, _080C682C @ =FUN_080c6850
	movs r0, #0x39
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080C6840
	.align 2, 0
_080C682C: .4byte FUN_080c6850
_080C6830:
	mov r2, sl
	cmp r2, #0
	beq _080C6840
	mov r3, r8
	ldrb r1, [r3]
	adds r0, r6, #0
	bl FUN_080c6500
_080C6840:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
