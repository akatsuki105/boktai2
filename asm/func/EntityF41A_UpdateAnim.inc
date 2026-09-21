	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0x21
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r0, r3
	cmp r0, #1
	ble _080CBDB6
	subs r3, r3, r0
	movs r6, #1
	b _080CBDBA
_080CBDB6:
	adds r3, r0, #0
	movs r6, #0
_080CBDBA:
	movs r0, #0x84
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x60
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
	beq _080CBE0C
	ldr r0, [r5, #0x60]
	movs r1, #4
	orrs r0, r1
	b _080CBE14
_080CBE0C:
	ldr r0, [r5, #0x60]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CBE14:
	str r0, [r5, #0x60]
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
	beq _080CBE38
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080CBE40
_080CBE38:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CBE40:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CBE78 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CBEB0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CBE7C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CBE70
	ldrb r0, [r4, #5]
_080CBE70:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CBE8C
	.align 2, 0
_080CBE78: .4byte 0x0000FFFF
_080CBE7C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CBE8C
	strh r1, [r4, #8]
_080CBE8C:
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
	bne _080CBEB0
	movs r0, #1
	strb r0, [r4, #7]
_080CBEB0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
