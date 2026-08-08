	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080F8E74 @ =0x03000184
	ldr r0, [r0]
	cmp r0, #0
	beq _080F8E7E
	cmp r3, #0
	beq _080F8E7E
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _080F8E7E
	movs r4, #0
_080F8E54:
	cmp r1, r3
	bne _080F8E78
	ldrb r2, [r1, #4]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080F8E78
	movs r0, #0xfd
	ands r0, r2
	strb r0, [r1, #4]
	str r4, [r1, #8]
	movs r0, #0xf0
	strh r0, [r1, #6]
	bl FUN_080f8cec
	b _080F8E7E
	.align 2, 0
_080F8E74: .4byte 0x03000184
_080F8E78:
	ldr r1, [r1, #0xc]
	cmp r1, #0
	bne _080F8E54
_080F8E7E:
	pop {r4}
	pop {r0}
	bx r0
