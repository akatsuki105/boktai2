	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080F8D34 @ =0x03000184
	ldr r0, [r0]
	cmp r0, #0
	beq _080F8D58
	cmp r3, #0
	bne _080F8D3C
	b _080F8D58
	.align 2, 0
_080F8D34: .4byte 0x03000184
_080F8D38:
	movs r0, #1
	b _080F8D5A
_080F8D3C:
	ldr r2, [r0, #0x28]
	cmp r2, #0
	beq _080F8D58
	movs r4, #1
_080F8D44:
	ldrb r1, [r2, #4]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080F8D52
	cmp r2, r3
	beq _080F8D38
_080F8D52:
	ldr r2, [r2, #0xc]
	cmp r2, #0
	bne _080F8D44
_080F8D58:
	movs r0, #0
_080F8D5A:
	pop {r4}
	pop {r1}
	bx r1
