	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BCE18 @ =0x0000189C
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080bcdec
	ldr r0, _080BCE1C @ =0x0000168E
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BCE18: .4byte 0x0000189C
_080BCE1C: .4byte 0x0000168E
