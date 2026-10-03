	push {lr}
	cmp r0, #0
	beq _0808C652
	adds r0, #0xa0
	b _0808C654
_0808C652:
	movs r0, #0x93
_0808C654:
	pop {r1}
	bx r1
