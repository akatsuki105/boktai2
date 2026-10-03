	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x78
	movs r5, #0x30
_080BCC96:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BCC96
	ldr r1, _080BCCBC @ =0x00001314
	adds r0, r6, r1
	bl FUN_080b9a0c
	ldr r1, _080BCCC0 @ =0x00001438
	adds r0, r6, r1
	bl FUN_080b9894
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BCCBC: .4byte 0x00001314
_080BCCC0: .4byte 0x00001438
