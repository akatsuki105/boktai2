	push {lr}
	adds r2, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080BFD78 @ =0x0000058E
	adds r1, r2, r3
	ldrh r3, [r0]
	ldrh r1, [r1]
	cmp r3, r1
	bls _080BFD7C
	movs r0, #0xa
	b _080BFDA6
	.align 2, 0
_080BFD78: .4byte 0x0000058E
_080BFD7C:
	ldr r1, _080BFD8C @ =0x0000058C
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bls _080BFD90
	movs r0, #5
	b _080BFDA6
	.align 2, 0
_080BFD8C: .4byte 0x0000058C
_080BFD90:
	ldr r1, _080BFDA0 @ =0x0000058A
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r3, r0
	bhi _080BFDA4
	movs r0, #1
	b _080BFDA6
	.align 2, 0
_080BFDA0: .4byte 0x0000058A
_080BFDA4:
	movs r0, #2
_080BFDA6:
	pop {r1}
	bx r1
	.align 2, 0
