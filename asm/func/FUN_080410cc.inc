	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x5c
	bl FUN_08002a48
	cmp r0, #0
	blt _080410E8
	movs r0, #0xf7
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _080410EC
_080410E8:
	movs r0, #1
	rsbs r0, r0, #0
_080410EC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
