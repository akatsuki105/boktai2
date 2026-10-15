	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x9a
	ldrh r0, [r3]
	cmp r0, #0
	beq _080A5BC0
	adds r7, r6, #0
	adds r7, #0xa0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	movs r1, #0xa2
	adds r1, r1, r6
	mov r8, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r1]
	cmp r0, r2
	blo _080A5B42
	adds r2, r6, #0
	adds r2, #0xa4
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	strh r0, [r3]
	b _080A5BB8
_080A5B42:
	mov r3, r8
	ldrh r1, [r3]
	ldrh r2, [r7]
	subs r4, r1, r2
	adds r0, r6, #0
	adds r0, #0xb4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0xac
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r2, r4, r2
	adds r0, r0, r2
	bl Div
	adds r5, r6, #0
	adds r5, #0xa4
	strh r0, [r5]
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xae
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa6
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, r8
	ldrh r1, [r3]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	adds r2, r5, #0
_080A5BB8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
_080A5BC0:
	adds r0, r6, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5BF8
	adds r0, r6, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5BF0
	ldr r0, _080A5BEC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x14
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A5BF0
	ldr r0, [r6, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080A5BF6
	.align 2, 0
_080A5BEC: .4byte 0x030046A0
_080A5BF0:
	ldr r0, [r6, #0x40]
	movs r1, #1
	orrs r0, r1
_080A5BF6:
	str r0, [r6, #0x40]
_080A5BF8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
