	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r4, #0x80
	movs r5, #7
_080A86AA:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080A86AA
	movs r1, #0
	ldr r0, _080A86C8 @ =0x03000154
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A86C8: .4byte 0x03000154
