	push {lr}
	adds r1, r0, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C950
	movs r0, #0
	strb r0, [r1]
_0804C950:
	bl rfu_getMasterSlave
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _0804C970
	ldr r0, _0804C974 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	orrs r0, r1
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_0804C970:
	pop {r1}
	bx r1
	.align 2, 0
_0804C974: .4byte 0x03005800
