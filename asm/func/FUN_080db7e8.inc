	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x20
	adds r6, r4, r1
	ldrh r1, [r5, #0x16]
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	ble _080DB80C
	subs r0, r1, #1
	strh r0, [r5, #0x16]
	b _080DB968
_080DB80C:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldrh r0, [r5, #8]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #8
	ldrsh r1, [r5, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0xa]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0xc]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	ldr r3, [r4, #0x1c]
	lsls r0, r0, #4
	adds r4, r0, r4
	movs r0, #0xa4
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
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
	beq _080DB8B2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080DB8BA
_080DB8B2:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB8BA:
	str r0, [r6]
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
	beq _080DB8DE
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080DB8E6
_080DB8DE:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DB8E6:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DB920 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DB958
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB92A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DB924
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DB940
	.align 2, 0
_080DB920: .4byte 0x0000FFFF
_080DB924:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DB93E
_080DB92A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DB93E
	strh r1, [r4, #8]
	movs r2, #1
	b _080DB940
_080DB93E:
	movs r2, #0
_080DB940:
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
	b _080DB95A
_080DB958:
	movs r2, #0
_080DB95A:
	cmp r2, #0
	beq _080DB962
	movs r0, #2
	strb r0, [r5, #0x12]
_080DB962:
	ldrh r0, [r5, #0x14]
	adds r0, #1
	strh r0, [r5, #0x14]
_080DB968:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
