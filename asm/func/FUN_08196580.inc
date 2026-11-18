	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081965A6
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081965A6
	ldr r0, _081965C4 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081965A6:
	ldr r0, _081965C4 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _081965BE
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081965C8 @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _081965CC @ =FUN_081965d0
	str r0, [r1]
_081965BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081965C4: .4byte 0x00000CC3
_081965C8: .4byte 0x00000C48
_081965CC: .4byte FUN_081965d0
