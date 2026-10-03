	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808da14
	cmp r0, #0
	bne _0808DA98
	movs r0, #0
	b _0808DAA0
_0808DA98:
	adds r0, r4, #0
	bl FUN_0808d908
	movs r0, #1
_0808DAA0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
