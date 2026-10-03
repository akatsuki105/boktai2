	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _0804C1C0 @ =0x03002B58
	ldr r5, [r0]
	cmp r5, #0
	bne _0804C1A0
	b _0804C3A2
_0804C1A0:
	cmp r3, #0x33
	bne _0804C1A6
	b _0804C30C
_0804C1A6:
	cmp r3, #0x33
	bgt _0804C1EE
	cmp r3, #0x23
	beq _0804C290
	cmp r3, #0x23
	bgt _0804C1CE
	cmp r3, #0x20
	beq _0804C24E
	cmp r3, #0x20
	bgt _0804C1C4
	cmp r3, #0
	beq _0804C244
	b _0804C3A2
	.align 2, 0
_0804C1C0: .4byte 0x03002B58
_0804C1C4:
	cmp r3, #0x21
	beq _0804C260
	cmp r3, #0x22
	beq _0804C264
	b _0804C3A2
_0804C1CE:
	cmp r3, #0x30
	bne _0804C1D4
	b _0804C30C
_0804C1D4:
	cmp r3, #0x30
	bgt _0804C1E2
	cmp r3, #0x24
	beq _0804C294
	cmp r3, #0x25
	beq _0804C2BC
	b _0804C3A2
_0804C1E2:
	cmp r3, #0x31
	beq _0804C2C0
	cmp r3, #0x32
	bne _0804C1EC
	b _0804C2E8
_0804C1EC:
	b _0804C3A2
_0804C1EE:
	cmp r3, #0x45
	bne _0804C1F4
	b _0804C3A2
_0804C1F4:
	cmp r3, #0x45
	bgt _0804C218
	cmp r3, #0x42
	bne _0804C1FE
	b _0804C36C
_0804C1FE:
	cmp r3, #0x42
	bgt _0804C20A
	cmp r3, #0x40
	bne _0804C208
	b _0804C346
_0804C208:
	b _0804C3A2
_0804C20A:
	cmp r3, #0x43
	bne _0804C210
	b _0804C370
_0804C210:
	cmp r3, #0x44
	bne _0804C216
	b _0804C374
_0804C216:
	b _0804C3A2
_0804C218:
	cmp r3, #0xf1
	bne _0804C21E
	b _0804C378
_0804C21E:
	cmp r3, #0xf1
	bgt _0804C22E
	cmp r3, #0x50
	beq _0804C23C
	cmp r3, #0xf0
	bne _0804C22C
	b _0804C378
_0804C22C:
	b _0804C3A2
_0804C22E:
	cmp r3, #0xf2
	bne _0804C234
	b _0804C38A
_0804C234:
	cmp r3, #0xff
	bne _0804C23A
	b _0804C380
_0804C23A:
	b _0804C3A2
_0804C23C:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	b _0804C3A2
_0804C244:
	movs r0, #6
	strb r3, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r3, [r5, #0x44]
	b _0804C39A
_0804C24E:
	ldr r0, _0804C25C @ =0x03004740
	ldrh r1, [r0, #0x14]
	adds r0, r5, #0
	adds r0, #0x26
	strb r1, [r0]
	b _0804C3A2
	.align 2, 0
_0804C25C: .4byte 0x03004740
_0804C260:
	movs r1, #6
	b _0804C392
_0804C264:
	ldr r0, _0804C28C @ =0x03004740
	ldrh r0, [r0, #0x14]
	adds r1, r5, #0
	adds r1, #0x21
	movs r4, #0
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r0, #0x20
	movs r3, #0x40
	bl rfu_setRecvBuffer
	movs r0, #0xe
	strb r4, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r4, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C28C: .4byte 0x03004740
_0804C290:
	movs r1, #6
	b _0804C392
_0804C294:
	adds r1, r5, #0
	adds r1, #0x43
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0804C2B8 @ =0x03005800
	ldr r0, [r0]
	ldrb r3, [r0, #2]
	subs r3, #1
	cmp r3, #0
	bne _0804C2AA
	b _0804C3A2
_0804C2AA:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	subs r3, #1
	cmp r3, #0
	bne _0804C2AA
	b _0804C3A2
	.align 2, 0
_0804C2B8: .4byte 0x03005800
_0804C2BC:
	movs r1, #6
	b _0804C392
_0804C2C0:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C2E4 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	orrs r0, r1
	movs r3, #0
	strb r0, [r2]
	ldrh r1, [r5, #0x38]
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0
	strh r1, [r0]
	movs r0, #0x10
	strb r2, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r3, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C2E4: .4byte 0x03004740
_0804C2E8:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C308 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	b _0804C39A
	.align 2, 0
_0804C308: .4byte 0x03004740
_0804C30C:
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C338 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	movs r1, #0
	strb r0, [r2]
	ldrh r0, [r5, #0x38]
	cmp r0, #0xf
	bls _0804C33C
	movs r0, #0x1d
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	bl rfu_LMAN_stopManager
	b _0804C3A2
	.align 2, 0
_0804C338: .4byte 0x03004740
_0804C33C:
	movs r0, #0xb
	strb r1, [r5, #0x1c]
	strh r0, [r5, #0x38]
	str r1, [r5, #0x44]
	b _0804C39A
_0804C346:
	movs r1, #0xb
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x25
	ldr r0, _0804C368 @ =0x03004740
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	b _0804C3A2
	.align 2, 0
_0804C368: .4byte 0x03004740
_0804C36C:
	movs r1, #0x20
	b _0804C392
_0804C370:
	movs r1, #6
	b _0804C392
_0804C374:
	movs r1, #0x1e
	b _0804C392
_0804C378:
	ldrh r0, [r5, #0x38]
	cmp r0, #0x1c
	beq _0804C3A2
	b _0804C38A
_0804C380:
	ldrh r0, [r5, #0x38]
	cmp r0, #0x1c
	beq _0804C3A2
	cmp r0, #1
	bls _0804C3A2
_0804C38A:
	movs r0, #1
	bl rfu_LMAN_stopManager
	movs r1, #0x1c
_0804C392:
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r1, [r5, #0x38]
	str r0, [r5, #0x44]
_0804C39A:
	adds r1, r5, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
_0804C3A2:
	pop {r4, r5}
	pop {r0}
	bx r0
