	push {lr}
	ldr r0, _080F8C28 @ =0x03000184
	ldr r1, [r0]
	cmp r1, #0
	beq _080F8C24
	movs r0, #0
	str r0, [r1, #0x1c]
	str r0, [r1, #0x20]
	str r0, [r1, #0x18]
	str r0, [r1, #0x28]
_080F8C24:
	pop {r0}
	bx r0
	.align 2, 0
_080F8C28: .4byte 0x03000184
