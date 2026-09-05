	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r0, r5, #0
	bl FUN_080091d0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq _0800958C
	movs r0, #6
	ldr r1, _0800951C @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0800958C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0800958C
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x28
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r5, r3]
	movs r3, #0x2c
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r2, r1, #0
	muls r2, r1, r2
	adds r4, r4, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	ldr r0, [r5, #0x10]
	cmp r4, r0
	bhs _0800958C
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _08009520
	movs r2, #0
	movs r3, #1
	movs r4, #2
	b _08009526
	.align 2, 0
_0800951C: .4byte 0x03002BC0
_08009520:
	movs r2, #6
	movs r3, #7
	movs r4, #0
_08009526:
	cmp r2, r1
	beq _08009532
	cmp r3, r1
	beq _08009532
	cmp r4, r1
	bne _0800958C
_08009532:
	ldr r0, [r6, #0x24]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r2, r0
	beq _0800954C
	cmp r3, r0
	beq _0800954C
	cmp r4, r0
	beq _0800954C
	movs r1, #0
_0800954C:
	cmp r1, #0
	beq _0800958C
	ldr r0, _08009588 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08009594
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08009364
	cmp r0, #0
	beq _08009594
	movs r0, #5
	strb r0, [r5, #7]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08009278
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080091c4
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080093e0
	b _08009594
	.align 2, 0
_08009588: .4byte 0x030044E0
_0800958C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080091c4
_08009594:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
