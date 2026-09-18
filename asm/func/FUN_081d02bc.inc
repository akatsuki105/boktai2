	push {r4, r5, r6, lr}
	adds r6, r0, #0
	mov ip, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0x78
	ldrh r0, [r0]
	cmp r0, #1
	bne _081D02F4
	adds r0, r6, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D02F4
	adds r0, r6, #0
	bl FUN_081cfa24
	adds r1, r6, #0
	adds r1, #0xbb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r3, r1, #0
	b _081D03DC
_081D02F4:
	adds r4, r6, #0
	adds r4, #0x70
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x70]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D0328
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D0334
_081D0328:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D0334:
	str r0, [r2]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D035A
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D0364
_081D035A:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D0364:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D03A0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r6, #0
	adds r3, #0xbb
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D03DC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D03A4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D039A
	ldrb r0, [r4, #5]
_081D039A:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D03B4
	.align 2, 0
_081D03A0: .4byte 0x0000FFFF
_081D03A4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D03B4
	strh r1, [r4, #8]
_081D03B4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	adds r3, r6, #0
	adds r3, #0xbb
	cmp r0, #0
	bne _081D03DC
	movs r0, #1
	strb r0, [r4, #7]
_081D03DC:
	ldrb r0, [r3]
	cmp r0, #0x1e
	bls _081D03F4
	adds r1, r6, #0
	adds r1, #0xb6
	movs r2, #0
	movs r0, #5
	strh r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	strb r2, [r3]
_081D03F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
