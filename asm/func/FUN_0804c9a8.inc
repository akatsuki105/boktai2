	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0x32
	ldrb r1, [r2]
	cmp r1, #0
	beq _0804C9BA
	movs r1, #0
	strb r1, [r2]
_0804C9BA:
	ldr r2, _0804CAA8 @ =0x030057F0
	adds r3, r6, #0
	adds r3, #0x21
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	ldrh r1, [r1, #0x34]
	adds r5, r3, #0
	cmp r1, #0x46
	bne _0804CA00
	ldr r1, _0804CAAC @ =0x00000135
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804C9E0
	adds r0, r6, #0
	bl FUN_0804dbe0
_0804C9E0:
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C9F8
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r6, #0x22]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r6, #0x22]
_0804C9F8:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
_0804CA00:
	ldr r1, _0804CAB0 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0804CA1C
	ldrh r1, [r6, #0x22]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r3, #0
	orrs r2, r1
	movs r1, #1
	orrs r2, r1
	strh r2, [r6, #0x22]
_0804CA1C:
	ldrh r2, [r6, #0x22]
	movs r1, #0x40
	ands r1, r2
	cmp r1, #0
	beq _0804CA3C
	movs r1, #0x28
	ands r1, r2
	cmp r1, #0
	bne _0804CA3C
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	movs r2, #1
	orrs r1, r2
	strh r1, [r6, #0x22]
_0804CA3C:
	ldrh r2, [r6, #0x22]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	bne _0804CAD2
	ldr r1, _0804CAB4 @ =0x03005800
	ldr r1, [r1]
	ldrb r1, [r1, #3]
	cmp r1, #0
	bne _0804CAC8
	movs r7, #1
	adds r1, r7, #0
	ands r1, r2
	cmp r1, #0
	beq _0804CAC8
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	adds r4, r6, #0
	adds r4, #0xa4
	cmp r0, #0
	beq _0804CA78
	movs r0, #1
	strb r0, [r4]
	ldrh r1, [r6, #0x22]
	ldr r0, _0804CAB8 @ =0x0000FEFF
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r6, #0x22]
_0804CA78:
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r7, #0
	ldrb r1, [r5]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #6
	adds r2, r4, #0
	movs r3, #4
	bl rfu_NI_setSendData
	adds r1, r0, #0
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _0804CABC
	movs r0, #2
	bl FUN_0804e584
	movs r0, #0
	b _0804CB5E
	.align 2, 0
_0804CAA8: .4byte 0x030057F0
_0804CAAC: .4byte 0x00000135
_0804CAB0: .4byte 0x030044E0
_0804CAB4: .4byte 0x03005800
_0804CAB8: .4byte 0x0000FEFF
_0804CABC:
	ldrh r1, [r6, #0x22]
	ldr r2, _0804CB10 @ =0x0000FFFE
	ands r2, r1
	movs r1, #2
	orrs r2, r1
	strh r2, [r6, #0x22]
_0804CAC8:
	ldrh r2, [r6, #0x22]
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0804CB30
_0804CAD2:
	ldr r1, _0804CB14 @ =0x030057F0
	ldrb r3, [r5]
	lsls r2, r3, #2
	adds r2, r2, r1
	ldr r1, [r2]
	ldrh r1, [r1]
	cmp r1, #0x26
	bne _0804CB20
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	ldrh r1, [r6, #0x22]
	ldr r2, _0804CB18 @ =0x0000FFFD
	ands r2, r1
	strh r2, [r6, #0x22]
	movs r1, #8
	ands r1, r2
	cmp r1, #0
	beq _0804CB30
	ldr r1, _0804CB1C @ =0x0000FFF7
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strh r1, [r6, #0x22]
	adds r2, r6, #0
	adds r2, #0xa4
	movs r1, #0
	strb r1, [r2]
	b _0804CB30
	.align 2, 0
_0804CB10: .4byte 0x0000FFFE
_0804CB14: .4byte 0x030057F0
_0804CB18: .4byte 0x0000FFFD
_0804CB1C: .4byte 0x0000FFF7
_0804CB20:
	cmp r1, #0x27
	bne _0804CB30
	movs r0, #4
	adds r1, r3, #0
	bl rfu_clearSlot
	movs r1, #0
	strh r1, [r6, #0x22]
_0804CB30:
	ldrh r2, [r6, #0x22]
	movs r1, #0x60
	ands r1, r2
	cmp r1, #0x60
	bne _0804CB5E
	ldr r0, _0804CB64 @ =0x0000FFDF
	ands r0, r2
	movs r4, #0
	movs r5, #0
	ldr r1, _0804CB68 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r6, #0x22]
	bl rfu_LMAN_requestChangeAgbClockMaster
	movs r0, #0xc
	strb r4, [r6, #0x1c]
	strh r0, [r6, #0x38]
	str r5, [r6, #0x44]
	adds r1, r6, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804CB5E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804CB64: .4byte 0x0000FFDF
_0804CB68: .4byte 0x0000FFBF
