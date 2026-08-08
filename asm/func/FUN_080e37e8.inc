	push {r4, lr}
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r3, r0, r4
	str r1, [r3]
	ldr r1, _080E3800 @ =0x0000025D
	adds r0, r0, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E3800: .4byte 0x0000025D
