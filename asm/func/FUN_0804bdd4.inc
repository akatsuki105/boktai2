	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	ldrh r2, [r4, #0x22]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804BDF8
	ldr r0, _0804BDFC @ =0x03005800
	ldr r1, [r0]
	ldrb r1, [r1, #3]
	adds r6, r0, #0
	cmp r1, #0
	bne _0804BDF8
	movs r0, #0xa0
	ands r0, r2
	cmp r0, #0
	beq _0804BE00
_0804BDF8:
	movs r0, #0
	b _0804BECC
	.align 2, 0
_0804BDFC: .4byte 0x03005800
_0804BE00:
	ldrh r0, [r4, #0x38]
	cmp r0, #9
	bne _0804BE18
	movs r0, #0x84
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804BE18
	ldr r1, _0804BEB4 @ =0x00000205
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r4, #0x22]
_0804BE18:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x1a]
	adds r3, r0, #0
	cmp r1, r3
	beq _0804BE3A
	ldrh r1, [r4, #0x22]
	movs r0, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r4, #0x22]
	ldr r0, [r6]
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _0804BE3A
	movs r0, #1
	orrs r1, r0
	strh r1, [r4, #0x22]
_0804BE3A:
	strb r3, [r4, #0x1a]
	ldrh r1, [r4, #0x22]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0804BE56
	adds r0, r4, #0
	bl FUN_0804bcc8
	ldrh r1, [r4, #0x22]
	ldr r0, _0804BEB8 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4, #0x22]
	movs r7, #1
_0804BE56:
	ldrh r1, [r4, #0x22]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0804BECA
	ldrb r0, [r4, #0x19]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #0x43
	movs r3, #0x40
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804BEC4
	movs r2, #0
	ldr r0, _0804BEBC @ =0x03005800
	ldr r1, [r0]
	ldrb r1, [r1, #2]
	ands r1, r5
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x20
	cmp r1, #0
	bne _0804BEA2
	adds r3, r6, #0
	movs r1, #1
_0804BE90:
	adds r2, #1
	cmp r2, #3
	bgt _0804BEA2
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r2
	ands r0, r1
	cmp r0, #0
	beq _0804BE90
_0804BEA2:
	strb r2, [r5]
	ldrh r0, [r4, #0x22]
	ldr r1, _0804BEC0 @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r4, #0x22]
	b _0804BECA
	.align 2, 0
_0804BEB4: .4byte 0x00000205
_0804BEB8: .4byte 0x0000FFFB
_0804BEBC: .4byte 0x03005800
_0804BEC0: .4byte 0x0000FFFE
_0804BEC4:
	movs r0, #2
	bl FUN_0804e584
_0804BECA:
	adds r0, r7, #0
_0804BECC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
