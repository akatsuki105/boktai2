	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C6C2
	movs r0, #0
	strb r0, [r1]
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1c]
_0804C6C2:
	adds r0, r4, #0
	bl FUN_0804bbf8
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C6F0
	ldr r2, _0804C76C @ =0x00000135
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #0
	bne _0804C6EC
	ldrh r2, [r4, #0x22]
	movs r1, #0x8e
	lsls r1, r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804C6EC
	ldr r3, _0804C770 @ =0x00000105
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r4, #0x22]
_0804C6EC:
	movs r1, #0
	strb r1, [r4, #0x1b]
_0804C6F0:
	ldrh r2, [r4, #0x22]
	movs r1, #0x40
	ands r1, r2
	cmp r1, #0
	beq _0804C70C
	movs r1, #0xce
	lsls r1, r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804C70C
	ldr r3, _0804C770 @ =0x00000105
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r4, #0x22]
_0804C70C:
	ldr r2, _0804C774 @ =0x030057F0
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r1, [r5]
	lsls r3, r1, #2
	adds r2, r3, r2
	ldr r1, [r2]
	ldrh r1, [r1, #0x34]
	cmp r1, #0x46
	bne _0804C740
	adds r0, r4, r3
	adds r1, r0, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C738
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r4, #0x22]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4, #0x22]
_0804C738:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
_0804C740:
	ldrh r2, [r4, #0x22]
	movs r1, #0x60
	ands r1, r2
	cmp r1, #0x60
	bne _0804C784
	ldr r0, _0804C778 @ =0x0000FFDF
	ands r0, r2
	ldr r1, _0804C77C @ =0x0000FFBF
	ands r0, r1
	strh r0, [r4, #0x22]
	adds r2, r4, #0
	adds r2, #0x35
	ldr r0, _0804C780 @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	orrs r0, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0
	b _0804C7BC
	.align 2, 0
_0804C76C: .4byte 0x00000135
_0804C770: .4byte 0x00000105
_0804C774: .4byte 0x030057F0
_0804C778: .4byte 0x0000FFDF
_0804C77C: .4byte 0x0000FFBF
_0804C780: .4byte 0x03005800
_0804C784:
	ldrb r3, [r4, #0x19]
	cmp r3, #0
	beq _0804C7BC
	movs r5, #0xb4
	lsls r5, r5, #1
	ands r5, r2
	cmp r5, #0
	bne _0804C7BC
	ldr r1, _0804C7C4 @ =0x03005800
	ldr r1, [r1]
	ldrb r1, [r1, #2]
	cmp r3, r1
	bne _0804C7BC
	adds r0, r4, #0
	bl FUN_0804bc10
	adds r1, r0, #0
	cmp r1, #0
	beq _0804C7BC
	movs r0, #9
	strb r5, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804C7BC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804C7C4: .4byte 0x03005800
