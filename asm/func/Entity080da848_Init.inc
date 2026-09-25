	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DA840 @ =0x000009FC
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080da7cc
	ldr r0, _080DA844 @ =0x0300015C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DA840: .4byte 0x000009FC
_080DA844: .4byte 0x0300015C
