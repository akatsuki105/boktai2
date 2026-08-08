	push {lr}
	ldr r0, _080F9B58 @ =0x03000184
	ldr r0, [r0]
	cmp r0, #0
	beq _080F9B54
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _080F9B54
_080F9B44:
	ldrh r0, [r1, #6]
	cmp r0, #0
	beq _080F9B4E
	subs r0, #1
	strh r0, [r1, #6]
_080F9B4E:
	ldr r1, [r1, #0xc]
	cmp r1, #0
	bne _080F9B44
_080F9B54:
	pop {r0}
	bx r0
	.align 2, 0
_080F9B58: .4byte 0x03000184
