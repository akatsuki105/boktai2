	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r1, r3, #0
	ldr r0, _0804DB2C @ =0x03002B58
	ldr r2, [r0]
	cmp r2, #0
	beq _0804DBC4
	cmp r3, #0x41
	bgt _0804DB30
	cmp r3, #0x40
	bge _0804DBC4
	cmp r3, #0x30
	beq _0804DB84
	cmp r3, #0x30
	ble _0804DBC4
	cmp r3, #0x32
	beq _0804DB70
	cmp r3, #0x32
	blt _0804DB5E
	cmp r3, #0x33
	beq _0804DB84
	b _0804DBC4
	.align 2, 0
_0804DB2C: .4byte 0x03002B58
_0804DB30:
	cmp r3, #0x50
	beq _0804DB56
	cmp r3, #0x50
	bgt _0804DB3E
	cmp r3, #0x42
	beq _0804DBA4
	b _0804DBC4
_0804DB3E:
	cmp r3, #0xf1
	beq _0804DBAC
	cmp r3, #0xf1
	bgt _0804DB4C
	cmp r3, #0xf0
	beq _0804DBAC
	b _0804DBC4
_0804DB4C:
	cmp r1, #0xf2
	beq _0804DBAC
	cmp r1, #0xff
	beq _0804DBAC
	b _0804DBC4
_0804DB56:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804DBC4
_0804DB5E:
	adds r2, #0x25
	ldr r0, _0804DB6C @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804DBC4
	.align 2, 0
_0804DB6C: .4byte 0x03004740
_0804DB70:
	adds r2, #0x25
	ldr r0, _0804DB80 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804DBC4
	.align 2, 0
_0804DB80: .4byte 0x03004740
_0804DB84:
	adds r3, r2, #0
	adds r3, #0x25
	ldr r0, _0804DBA0 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r3]
	bics r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r0, #0x1d
	strb r1, [r2, #0x1c]
	strh r0, [r2, #0x38]
	str r1, [r2, #0x44]
	b _0804DBBC
	.align 2, 0
_0804DBA0: .4byte 0x03004740
_0804DBA4:
	adds r0, r2, #0
	bl FUN_0804ba64
	b _0804DBC4
_0804DBAC:
	ldrh r0, [r2, #0x38]
	cmp r0, #0x1c
	beq _0804DBC4
	movs r1, #0x1c
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r1, [r2, #0x38]
	str r0, [r2, #0x44]
_0804DBBC:
	adds r1, r2, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804DBC4:
	pop {r0}
	bx r0
