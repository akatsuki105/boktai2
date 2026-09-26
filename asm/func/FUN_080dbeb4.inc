	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	mov ip, r1
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x20
	adds r5, r2, r1
	mov r0, ip
	ldrh r1, [r0, #0x1a]
	movs r3, #0x1a
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _080DBEDC
	subs r0, r1, #1
	mov r4, ip
	strh r0, [r4, #0x1a]
	b _080DC004
_080DBEDC:
	ldr r6, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r6, r0
	str r6, [r5]
	mov r0, ip
	ldr r1, [r0]
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x18]
	mov r4, ip
	ldrh r0, [r4, #6]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r5, #0x1a]
	ldrh r0, [r4, #8]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	ldr r3, [r2, #0x1c]
	lsls r0, r0, #4
	adds r4, r0, r2
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DBF4E
	movs r0, #4
	orrs r6, r0
	b _080DBF54
_080DBF4E:
	movs r0, #5
	rsbs r0, r0, #0
	ands r6, r0
_080DBF54:
	str r6, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DBF78
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080DBF80
_080DBF78:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DBF80:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DBFB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DBFF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DBFC2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DBFBC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DBFD8
	.align 2, 0
_080DBFB8: .4byte 0x0000FFFF
_080DBFBC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DBFD6
_080DBFC2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DBFD6
	strh r1, [r4, #8]
	movs r2, #1
	b _080DBFD8
_080DBFD6:
	movs r2, #0
_080DBFD8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DBFF2
_080DBFF0:
	movs r2, #0
_080DBFF2:
	cmp r2, #0
	beq _080DBFFC
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0x16]
_080DBFFC:
	mov r4, ip
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
_080DC004:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
