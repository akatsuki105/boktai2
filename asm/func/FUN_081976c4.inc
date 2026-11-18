	push {lr}
	adds r2, r0, #0
	ldr r1, _081976E8 @ =0x00000CEC
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _081976E4
	ldr r0, _081976EC @ =0x00000C38
	adds r1, r2, r0
	ldr r0, _081976F0 @ =FUN_081976f4
	str r0, [r1]
	movs r0, #1
	adds r2, #0x45
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_081976E4:
	pop {r0}
	bx r0
	.align 2, 0
_081976E8: .4byte 0x00000CEC
_081976EC: .4byte 0x00000C38
_081976F0: .4byte FUN_081976f4
