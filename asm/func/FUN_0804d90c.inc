	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r1, [r5, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804D996
	ldr r7, _0804D988 @ =0x03005800
	ldr r0, [r7]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804D996
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804D99A
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r1, [r4]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r6, #0
	ldrb r1, [r4]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0xb8
	movs r1, #0xf
	movs r3, #0xc
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804D990
	movs r1, #0
	ldr r0, [r7]
	ldrb r0, [r0, #2]
	ands r0, r6
	cmp r0, #0
	bne _0804D978
	adds r3, r7, #0
	movs r2, #1
_0804D966:
	adds r1, #1
	cmp r1, #3
	bgt _0804D978
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0804D966
_0804D978:
	strb r1, [r4]
	ldrh r0, [r5, #0x22]
	ldr r1, _0804D98C @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r5, #0x22]
	b _0804D99A
	.align 2, 0
_0804D988: .4byte 0x03005800
_0804D98C: .4byte 0x0000FFFE
_0804D990:
	movs r0, #2
	bl FUN_0804e584
_0804D996:
	movs r0, #0
	b _0804D99C
_0804D99A:
	movs r0, #1
_0804D99C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
