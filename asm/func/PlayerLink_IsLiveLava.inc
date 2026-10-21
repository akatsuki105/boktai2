	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFBFE
	movs r1, #0x18
	ldr r0, _080CFBEC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFBF0 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFBF4
	movs r0, #1
	b _080CFBF6
	.align 2, 0
_080CFBEC: .4byte 0x030046A0
_080CFBF0: .4byte 0x00000934
_080CFBF4:
	movs r0, #0
_080CFBF6:
	cmp r0, #0
	bne _080CFBFE
	movs r0, #1
	b _080CFC00
_080CFBFE:
	movs r0, #0
_080CFC00:
	pop {r1}
	bx r1
