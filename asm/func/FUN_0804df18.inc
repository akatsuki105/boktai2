	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0804DFA0 @ =0x030000DC
_0804DF26:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804DF26
	movs r0, #0
	bl rfu_LMAN_manager_entity
	adds r3, r4, #0
	adds r3, #0xe9
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804DF56
	adds r2, r4, #0
	adds r2, #0xe8
	ldrb r0, [r2]
	cmp r0, #0
	beq _0804DF56
	movs r1, #0
	strb r1, [r2]
	subs r2, #1
	movs r0, #1
	strb r0, [r2]
	subs r2, #1
	strb r0, [r2]
	strb r1, [r3]
_0804DF56:
	adds r0, r4, #0
	bl FUN_0804bb70
	adds r0, r4, #0
	bl FUN_0804cf4c
	ldr r0, _0804DFA4 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804DFAC
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804DFAC
	ldr r1, _0804DFA0 @ =0x030000DC
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xe8
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804DFA8
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x70
	movs r2, #0x10
	bl rfu_UNI_changeAndReadySendData
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804DFAC
	.align 2, 0
_0804DFA0: .4byte 0x030000DC
_0804DFA4: .4byte 0x03005800
_0804DFA8:
	bl rfu_REQ_PARENT_resumeRetransmitAndChange
_0804DFAC:
	adds r0, r4, #0
	bl FUN_0804bb98
	ldr r0, _0804DFF4 @ =0x085AB5E0
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r2, [r1]
	cmp r2, #0
	beq _0804E01A
	ldr r2, _0804DFF8 @ =0x030044D0
	movs r1, #1
	str r1, [r2]
	movs r5, #0
	movs r1, #0x80
	lsls r1, r1, #6
	mov ip, r1
	ldr r7, _0804DFFC @ =0x00000FFF
	ldr r3, _0804E000 @ =0x03004510
	ldr r1, _0804E004 @ =0x0000FFFF
	adds r6, r1, #0
	adds r4, #0xf0
_0804DFE4:
	ldrh r2, [r4]
	mov r1, ip
	ands r1, r2
	cmp r1, #0
	beq _0804E008
	adds r1, r7, #0
	ands r1, r2
	b _0804E00C
	.align 2, 0
_0804DFF4: .4byte 0x085AB5E0
_0804DFF8: .4byte 0x030044D0
_0804DFFC: .4byte 0x00000FFF
_0804E000: .4byte 0x03004510
_0804E004: .4byte 0x0000FFFF
_0804E008:
	ldrh r1, [r3]
	orrs r1, r6
_0804E00C:
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _0804DFE4
	b _0804E01E
_0804E01A:
	ldr r1, _0804E024 @ =0x030044D0
	str r2, [r1]
_0804E01E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804E024: .4byte 0x030044D0
