	push {lr}
	adds r2, r0, #0
	ldr r0, _080F8D00 @ =0x03000184
	ldr r0, [r0]
	cmp r0, #0
	bne _080F8D08
	b _080F8D1A
	.align 2, 0
_080F8D00: .4byte 0x03000184
_080F8D04:
	adds r0, r1, #0
	b _080F8D1C
_080F8D08:
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _080F8D1A
_080F8D0E:
	ldrb r0, [r1, #5]
	cmp r0, r2
	beq _080F8D04
	ldr r1, [r1, #0xc]
	cmp r1, #0
	bne _080F8D0E
_080F8D1A:
	movs r0, #0
_080F8D1C:
	pop {r1}
	bx r1
