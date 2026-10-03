	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d200
	adds r0, r4, #0
	bl FUN_0808d2ac
	bl FUN_082408d0
	movs r2, #4
	ldr r1, _0808D934 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0808D938 @ =FUN_0808db68
	adds r0, r4, #0
	bl FUN_0808a33c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D934: .4byte 0x030044BC
_0808D938: .4byte FUN_0808db68
