	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_080091d0
	ldr r0, [r6, #0x24]
	cmp r0, #0
	beq _080094A4
	movs r0, #6
	ldr r1, _08009468 @ =0x03002BC0
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _080094A4
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080094A4
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
	bhs _080094A4
	ldrb r0, [r5, #2]
	cmp r0, #0
	beq _0800946C
	movs r2, #0
	movs r3, #1
	movs r4, #2
	b _08009472
	.align 2, 0
_08009468: .4byte 0x03002BC0
_0800946C:
	movs r2, #6
	movs r3, #7
	movs r4, #0
_08009472:
	cmp r2, r1
	beq _0800947E
	cmp r3, r1
	beq _0800947E
	cmp r4, r1
	bne _080094A4
_0800947E:
	ldr r0, [r6, #0x24]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r2, r0
	beq _08009498
	cmp r3, r0
	beq _08009498
	cmp r4, r0
	beq _08009498
	movs r1, #0
_08009498:
	cmp r1, #0
	beq _080094A4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080091c4
_080094A4:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
