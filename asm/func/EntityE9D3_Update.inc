	push {lr}
	ldr r2, _080B55A4 @ =0x0000084C
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080B55A4: .4byte 0x0000084C
