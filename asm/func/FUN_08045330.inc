	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldrb r0, [r1, #6]
	lsrs r3, r0, #4
	ldrh r1, [r1, #4]
	ldr r0, _08045354 @ =0x00000FFF
	ands r0, r1
	movs r5, #0
	movs r4, #0
	strh r0, [r2, #0x20]
	cmp r3, #1
	beq _08045362
	cmp r3, #1
	bgt _08045358
	cmp r3, #0
	beq _0804535E
	b _080453A0
	.align 2, 0
_08045354: .4byte 0x00000FFF
_08045358:
	cmp r3, #2
	beq _08045396
	b _080453A0
_0804535E:
	strb r5, [r2, #4]
	b _08045398
_08045362:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x1c
	movs r1, #0x23
	adds r1, r1, r2
	mov ip, r1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x65
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	mov r6, ip
	ldrb r6, [r6]
	cmp r0, r6
	bne _0804538E
	strb r5, [r2, #4]
	b _08045390
_0804538E:
	strb r3, [r2, #4]
_08045390:
	strb r3, [r2, #5]
	str r4, [r2, #0x10]
	b _080453AA
_08045396:
	strb r3, [r2, #4]
_08045398:
	movs r0, #1
	strb r0, [r2, #5]
	str r4, [r2, #0x10]
	b _080453AA
_080453A0:
	movs r1, #0
	strb r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #5]
	str r1, [r2, #0x10]
_080453AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
