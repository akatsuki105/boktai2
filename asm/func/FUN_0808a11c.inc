	push {r4, lr}
	movs r4, #0
_0808A120:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _0808A134
	adds r4, #1
	cmp r4, #0xf
	ble _0808A120
	movs r0, #0
_0808A134:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
