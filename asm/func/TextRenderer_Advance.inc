	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strb r0, [r4, #0xe]
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _080495A6
	cmp r0, #1
	bgt _08049580
	cmp r0, #0
	beq _0804958A
	b _08049604
_08049580:
	cmp r0, #2
	beq _080495BA
	cmp r0, #3
	beq _080495CE
	b _08049604
_0804958A:
	ldr r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x1c]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08049600
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08049604
	ldrb r0, [r1]
	b _080495FC
_080495A6:
	ldr r1, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x20]
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne _08049604
	b _080495E0
_080495BA:
	ldr r1, [r4, #0x24]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x24]
	ldrb r0, [r4, #7]
	cmp r0, #2
	bne _08049604
	b _080495E0
_080495CE:
	ldr r1, [r4, #0x28]
	adds r0, r4, #0
	bl FUN_08049488
	adds r1, r0, #0
	str r1, [r4, #0x28]
	ldrb r0, [r4, #7]
	cmp r0, #3
	bne _08049604
_080495E0:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08049604
	adds r0, r4, #0
	bl FUN_08048964
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08049604
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	bne _08049600
	ldr r0, [r4, #0x1c]
	ldrb r0, [r0]
_080495FC:
	cmp r0, #0
	bne _08049604
_08049600:
	movs r0, #1
	b _08049606
_08049604:
	movs r0, #0
_08049606:
	pop {r4}
	pop {r1}
	bx r1
