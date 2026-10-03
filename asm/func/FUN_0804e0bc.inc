	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0804E11C @ =0x030000DC
_0804E0C2:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804E0C2
	movs r0, #0
	bl rfu_LMAN_manager_entity
	adds r4, r5, #0
	adds r4, #0x35
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E0E4
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, #0
	strb r0, [r4]
_0804E0E4:
	ldr r0, _0804E120 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0]
	cmp r1, #1
	bne _0804E0F8
	ldr r0, _0804E11C @ =0x030000DC
	strb r1, [r0]
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
_0804E0F8:
	adds r0, r5, #0
	bl FUN_0804d90c
	adds r0, r5, #0
	bl FUN_0804d9a4
	ldr r0, _0804E124 @ =0x085AB5E0
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E11C: .4byte 0x030000DC
_0804E120: .4byte 0x03005800
_0804E124: .4byte 0x085AB5E0
