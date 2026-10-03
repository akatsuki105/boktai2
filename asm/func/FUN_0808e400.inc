	push {lr}
	adds r2, r0, #0
	ldr r0, _0808E41C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808E416
	adds r0, r2, #0
	bl FUN_0808e224
_0808E416:
	pop {r0}
	bx r0
	.align 2, 0
_0808E41C: .4byte 0x030044BC
