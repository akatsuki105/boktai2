	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x31
	movs r0, #0
	strb r0, [r5]
	bl rfu_LMAN_manager_entity
	bl rfu_getMasterSlave
	adds r0, r4, #0
	bl FUN_0804bb70
	adds r0, r4, #0
	bl FUN_0804bb98
	ldr r1, _0804E088 @ =0x085AB5E0
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r2, [r5]
	cmp r2, #0
	beq _0804E0AE
	ldr r2, _0804E08C @ =0x030044D0
	movs r1, #1
	str r1, [r2]
	movs r5, #0
	movs r1, #0x80
	lsls r1, r1, #6
	mov ip, r1
	ldr r7, _0804E090 @ =0x00000FFF
	ldr r3, _0804E094 @ =0x03004510
	ldr r1, _0804E098 @ =0x0000FFFF
	adds r6, r1, #0
	adds r4, #0xf0
_0804E076:
	ldrh r2, [r4]
	mov r1, ip
	ands r1, r2
	cmp r1, #0
	beq _0804E09C
	adds r1, r7, #0
	ands r1, r2
	b _0804E0A0
	.align 2, 0
_0804E088: .4byte 0x085AB5E0
_0804E08C: .4byte 0x030044D0
_0804E090: .4byte 0x00000FFF
_0804E094: .4byte 0x03004510
_0804E098: .4byte 0x0000FFFF
_0804E09C:
	ldrh r1, [r3]
	orrs r1, r6
_0804E0A0:
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _0804E076
	b _0804E0B2
_0804E0AE:
	ldr r1, _0804E0B8 @ =0x030044D0
	str r2, [r1]
_0804E0B2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804E0B8: .4byte 0x030044D0
