	push {lr}
	adds r3, r0, #0
	ldr r0, _080F8CD0 @ =0x03000184
	ldr r1, [r0]
	cmp r1, #0
	beq _080F8CE8
	ldr r0, [r1, #0x28]
	movs r2, #0
	cmp r0, #0
	beq _080F8CE8
_080F8CC0:
	cmp r0, r3
	bne _080F8CE0
	cmp r2, #0
	bne _080F8CD4
	ldr r0, [r0, #0xc]
	str r0, [r1, #0x28]
	b _080F8CD8
	.align 2, 0
_080F8CD0: .4byte 0x03000184
_080F8CD4:
	ldr r0, [r0, #0xc]
	str r0, [r2, #0xc]
_080F8CD8:
	ldr r0, [r1, #0x1c]
	subs r0, #1
	str r0, [r1, #0x1c]
	b _080F8CE8
_080F8CE0:
	adds r2, r0, #0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _080F8CC0
_080F8CE8:
	pop {r0}
	bx r0
