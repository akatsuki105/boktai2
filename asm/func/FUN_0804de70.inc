	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5, #0x18]
	cmp r0, #0
	beq _0804DEB8
	ldr r1, _0804DEDC @ =0x030000DC
	ldrb r0, [r1]
	adds r4, r5, #0
	adds r4, #0x35
	cmp r0, #1
	bne _0804DE8C
_0804DE86:
	ldrb r0, [r1]
	cmp r0, #1
	beq _0804DE86
_0804DE8C:
	movs r0, #0
	bl rfu_LMAN_manager_entity
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804DEA4
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	movs r0, #0
	strb r0, [r4]
_0804DEA4:
	ldr r0, _0804DEE0 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0]
	cmp r1, #1
	bne _0804DEB8
	ldr r0, _0804DEDC @ =0x030000DC
	strb r1, [r0]
	movs r0, #1
	bl rfu_REQ_sendData
_0804DEB8:
	adds r0, r5, #0
	bl FUN_0804bdd4
	adds r0, r5, #0
	bl FUN_0804bed4
	ldr r0, _0804DEE4 @ =0x085AB5E0
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804DEDC: .4byte 0x030000DC
_0804DEE0: .4byte 0x03005800
_0804DEE4: .4byte 0x085AB5E0
