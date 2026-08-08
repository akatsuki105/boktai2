	push {lr}
	adds r2, r0, #0
	ldr r0, _080F8BD0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080F8BD4
	movs r0, #1
	b _080F8BD6
	.align 2, 0
_080F8BD0: .4byte 0x030047A4
_080F8BD4:
	movs r0, #0
_080F8BD6:
	cmp r0, #0
	beq _080F8C0A
	ldrb r0, [r2, #4]
	cmp r0, #1
	beq _080F8BF8
	cmp r0, #1
	bgt _080F8BEA
	cmp r0, #0
	beq _080F8BF4
	b _080F8C0A
_080F8BEA:
	cmp r0, #2
	beq _080F8BFC
	cmp r0, #3
	beq _080F8C00
	b _080F8C0A
_080F8BF4:
	movs r0, #0
	b _080F8C02
_080F8BF8:
	movs r0, #1
	b _080F8C02
_080F8BFC:
	movs r0, #2
	b _080F8C02
_080F8C00:
	movs r0, #3
_080F8C02:
	adds r1, r2, #0
	adds r1, #8
	bl FUN_0801a0a0
_080F8C0A:
	pop {r0}
	bx r0
	.align 2, 0
