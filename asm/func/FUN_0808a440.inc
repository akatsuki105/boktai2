	push {lr}
	adds r2, r0, #0
	movs r0, #0x11
	cmp r1, #0
	beq _0808A452
	movs r0, #0x31
	cmp r1, #1
	bne _0808A452
	movs r0, #0x91
_0808A452:
	adds r0, r2, r0
	pop {r1}
	bx r1
