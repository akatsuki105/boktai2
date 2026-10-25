	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C271A
	ldrb r0, [r6, #1]
	adds r1, r6, #0
	adds r1, #0x24
	adds r0, #0xd
	strh r0, [r1, #0x10]
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
_080C26EE:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C26EE
	ldrb r0, [r6, #2]
	cmp r0, #1
	bne _080C270C
	ldr r1, _080C2798 @ =0x00000167
	adds r0, r6, #0
	bl FUN_080c2694
	movs r0, #6
	strb r0, [r6, #3]
_080C270C:
	movs r0, #0
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	strh r0, [r6, #0x20]
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_080C271A:
	ldr r2, [r6, #0x18]
	ldr r1, [r2]
	ldr r0, [r6, #0x1c]
	cmp r1, r0
	bne _080C2730
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r4, #0x20
	ldrsh r0, [r6, r4]
	cmp r1, r0
	beq _080C2818
_080C2730:
	ldr r3, [r2, #4]
	ldr r2, [r2]
	adds r0, r2, #0
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080C279C @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r0, r1, #0x10
	ldrh r4, [r6, #0xa]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	ldr r4, _080C27A0 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	adds r2, r4, #0
	adds r0, r3, #0
	ldrh r1, [r6, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	movs r0, #0
	mov ip, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x40
	asrs r4, r4, #0x10
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
_080C277A:
	movs r0, #8
	mov r1, ip
	subs r5, r0, r1
	movs r3, #0x10
	ldrsh r0, [r6, r3]
	mov r1, ip
	muls r1, r0, r1
	mov r0, r8
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C27A4
	asrs r0, r0, #3
	b _080C27AA
	.align 2, 0
_080C2798: .4byte 0x00000167
_080C279C: .4byte 0xFFFF0000
_080C27A0: .4byte 0x0000FFFF
_080C27A4:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C27AA:
	strh r0, [r7]
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r4, #0
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C27C2
	asrs r0, r0, #3
	b _080C27C8
_080C27C2:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C27C8:
	strh r0, [r7, #2]
	movs r3, #0x14
	ldrsh r0, [r6, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C27E0
	asrs r0, r0, #3
	b _080C27E6
_080C27E0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C27E6:
	strh r0, [r7, #4]
	adds r7, #0x2c
	movs r0, #1
	add ip, r0
	mov r1, ip
	cmp r1, #7
	ble _080C277A
	ldrb r0, [r6, #3]
	cmp r0, #0
	beq _080C280E
	subs r0, #1
	strb r0, [r6, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C280E
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_080c2694
_080C280E:
	ldr r0, [r6, #0x18]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_080C2818:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
