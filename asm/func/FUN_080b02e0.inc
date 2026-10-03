	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	beq _080B038E
	cmp r0, #0
	beq _080B038E
	cmp r0, #1
	beq _080B038E
	cmp r0, #6
	beq _080B038E
	cmp r0, #2
	bne _080B031A
	adds r0, r4, #0
	bl FUN_080af508
	cmp r0, #0
	bne _080B037C
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080B038E
_080B031A:
	cmp r0, #7
	bne _080B037C
	adds r0, r4, #0
	bl FUN_080af508
	cmp r0, #0
	ble _080B037C
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r3, #0x58
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r2, r0
	subs r3, #0x54
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r3, #0x58
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	subs r0, #0x40
	subs r2, #0x40
	cmp r2, #0
	bge _080B0358
	rsbs r2, r2, #0
_080B0358:
	cmp r2, #0x7f
	bgt _080B037C
	cmp r0, #0
	bge _080B0362
	rsbs r0, r0, #0
_080B0362:
	cmp r0, #0x7f
	bgt _080B037C
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080af374
	ldr r0, _080B0378 @ =0x0000068E
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080B038E
	.align 2, 0
_080B0378: .4byte 0x0000068E
_080B037C:
	ldr r1, _080B0394 @ =0x0000068E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B038E
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080af374
_080B038E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B0394: .4byte 0x0000068E
