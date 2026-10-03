	push {lr}
	adds r1, r0, #0
	adds r0, #0x68
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AD4FE
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AD4FE
	movs r0, #1
	b _080AD500
_080AD4FE:
	movs r0, #0
_080AD500:
	pop {r1}
	bx r1
