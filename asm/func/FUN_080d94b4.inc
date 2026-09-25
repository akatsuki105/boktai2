	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080D9500 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D94C6
	b _080D96AE
_080D94C6:
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D9504
	ldr r0, [r5, #0x5c]
	movs r1, #4
	orrs r0, r1
	b _080D950C
	.align 2, 0
_080D9500: .4byte 0x0300015C
_080D9504:
	ldr r0, [r5, #0x5c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D950C:
	str r0, [r5, #0x5c]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D9530
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080D9538
_080D9530:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D9538:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D9570 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080D95B6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D957A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D9574
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080D9590
	.align 2, 0
_080D9570: .4byte 0x0000FFFF
_080D9574:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D958E
_080D957A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080D958E
	strh r1, [r4, #8]
	movs r2, #1
	b _080D9590
_080D958E:
	movs r2, #0
_080D9590:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _080D95B8
	movs r0, #1
	strb r0, [r4, #7]
	b _080D95B8
_080D95B6:
	movs r2, #0
_080D95B8:
	mov ip, r2
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080D95D4
	ldrh r0, [r5, #0x30]
	adds r0, #0x19
	strh r0, [r5, #0x30]
	ldr r2, [r5]
	ldrh r1, [r5, #0x28]
	ldrh r3, [r2, #2]
	adds r1, r1, r3
	b _080D95E2
_080D95D4:
	ldrh r0, [r5, #0x30]
	adds r0, #0xa
	strh r0, [r5, #0x30]
	ldr r2, [r5]
	ldrh r1, [r5, #0x28]
	ldrh r6, [r2, #2]
	adds r1, r1, r6
_080D95E2:
	adds r0, r0, r1
	strh r0, [r5, #0x2a]
	ldrh r1, [r5, #0x2a]
	ldrh r3, [r5, #0x26]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r0, r3, r0
	adds r6, r3, #0
	cmp r1, r0
	ble _080D95FC
	ldrh r0, [r2, #2]
	adds r0, r6, r0
	strh r0, [r5, #0x2a]
_080D95FC:
	ldrh r1, [r5, #0x2a]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r0, r3, r0
	cmp r1, r0
	blt _080D9610
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	ble _080D9616
_080D9610:
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_080D9616:
	ldr r0, [r5, #0x4c]
	cmp r0, #0x1d
	bgt _080D9622
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_080D9622:
	mov r2, ip
	cmp r2, #0
	beq _080D9670
	adds r0, r5, #0
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	adds r6, r5, #0
	adds r6, #0x39
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r3, _080D966C @ =0x000009FC
	add r3, r8
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	ldr r0, [r7]
	orrs r0, r4
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0x32
	strb r2, [r0]
	movs r4, #0
	strh r2, [r5, #0x24]
	str r2, [r5, #0x4c]
	adds r0, r7, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	movs r0, #0xff
	strb r0, [r6]
	b _080D96AE
	.align 2, 0
_080D966C: .4byte 0x000009FC
_080D9670:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, [r5]
	cmp r0, #0
	beq _080D96A0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0x1e]
	ldrh r6, [r5, #0x2a]
	adds r0, r0, r6
	strh r0, [r7, #0x1e]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
_080D96A0:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080d8864
	ldr r0, [r5, #0x4c]
	adds r0, #1
	str r0, [r5, #0x4c]
_080D96AE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
