	push {r4, r5, r6, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0x40
	mov r2, ip
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [r2, #0x5c]
	str r1, [r2, #0x60]
	mov r4, ip
	adds r4, #0x30
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x30]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _08011918
	mov r1, ip
	ldr r0, [r1, #0x40]
	movs r1, #4
	orrs r0, r1
	b _08011922
_08011918:
	mov r1, ip
	ldr r0, [r1, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08011922:
	mov r2, ip
	str r0, [r2, #0x40]
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
	beq _08011948
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08011950
_08011948:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08011950:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08011988 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080119CE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08011992
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0801198C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080119A8
	.align 2, 0
_08011988: .4byte 0x0000FFFF
_0801198C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080119A6
_08011992:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080119A6
	strh r1, [r4, #8]
	movs r2, #1
	b _080119A8
_080119A6:
	movs r2, #0
_080119A8:
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
	cmp r0, #0
	bne _080119D0
	movs r0, #1
	strb r0, [r4, #7]
	b _080119D0
_080119CE:
	movs r2, #0
_080119D0:
	mov r0, ip
	strb r2, [r0, #2]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	ldrh r0, [r0, #0xa]
	cmp r1, r0
	ble _080119E8
	mov r1, ip
	ldrh r0, [r1, #0x12]
	subs r0, #1
	strh r0, [r1, #0x12]
	b _080119F4
_080119E8:
	cmp r1, r0
	bge _080119F4
	mov r2, ip
	ldrh r0, [r2, #0x12]
	adds r0, #1
	strh r0, [r2, #0x12]
_080119F4:
	ldr r0, _08011A0C @ =0x085B0A08
	mov r2, ip
	ldrb r1, [r2, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08011A10
	asrs r1, r0, #0xc
	b _08011A16
	.align 2, 0
_08011A0C: .4byte 0x085B0A08
_08011A10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08011A16:
	ldrh r0, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
	mov r1, ip
	ldrb r0, [r1, #3]
	adds r0, #4
	strb r0, [r1, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
