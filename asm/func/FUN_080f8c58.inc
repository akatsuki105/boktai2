	push {r4, lr}
	adds r3, r0, #0
	adds r4, r2, #0
	ldr r0, _080F8C70 @ =0x03000184
	ldr r2, [r0]
	cmp r2, #0
	beq _080F8C6C
	ldr r0, [r2, #0x1c]
	cmp r0, #5
	ble _080F8C74
_080F8C6C:
	movs r0, #0
	b _080F8CA4
	.align 2, 0
_080F8C70: .4byte 0x03000184
_080F8C74:
	ldr r0, [r2, #0x28]
	cmp r0, #0
	beq _080F8C84
_080F8C7A:
	cmp r0, r3
	beq _080F8C6C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _080F8C7A
_080F8C84:
	str r1, [r3]
	movs r1, #0
	strb r4, [r3, #5]
	movs r0, #1
	strb r0, [r3, #4]
	strh r1, [r3, #6]
	str r1, [r3, #8]
	ldr r0, [r2, #0x28]
	str r0, [r3, #0xc]
	str r3, [r2, #0x28]
	ldr r0, [r2, #0x1c]
	adds r0, #1
	str r0, [r2, #0x1c]
	bl FUN_080f8cec
	movs r0, #1
_080F8CA4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
