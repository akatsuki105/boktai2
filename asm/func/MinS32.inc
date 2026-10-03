	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	cmp r2, r0
	bgt _0808A4A8
	adds r0, r2, #0
_0808A4A8:
	pop {r1}
	bx r1
