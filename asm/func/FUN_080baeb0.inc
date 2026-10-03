	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAEF0 @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BAEF4 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BAF04
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortInventory
	ldr r1, _080BAEF8 @ =0x0000140C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BAEFC @ =0x0000140D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BAF00 @ =0x0000140E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080baa64
	b _080BAF14
	.align 2, 0
_080BAEF0: .4byte 0x00001278
_080BAEF4: .4byte 0x000012EF
_080BAEF8: .4byte 0x0000140C
_080BAEFC: .4byte 0x0000140D
_080BAF00: .4byte 0x0000140E
_080BAF04:
	cmp r0, #0
	bne _080BAF14
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
