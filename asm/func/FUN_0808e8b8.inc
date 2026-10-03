	push {lr}
	asrs r0, r0, #2
	cmp r0, #1
	beq _0808E8D2
	cmp r0, #1
	ble _0808E8D6
	cmp r0, #2
	beq _0808E8CE
	cmp r0, #3
	beq _0808E8D2
	b _0808E8D6
_0808E8CE:
	movs r0, #2
	b _0808E8D8
_0808E8D2:
	movs r0, #1
	b _0808E8D8
_0808E8D6:
	movs r0, #0
_0808E8D8:
	pop {r1}
	bx r1
