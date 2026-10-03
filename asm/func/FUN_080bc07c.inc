	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BC0BC @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BC0C0 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BC0D0
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _080BC0C4 @ =0x0000140C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080BC0C8 @ =0x0000140D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080BC0CC @ =0x0000140E
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080bbbdc
	b _080BC0E0
	.align 2, 0
_080BC0BC: .4byte 0x00001278
_080BC0C0: .4byte 0x000012EF
_080BC0C4: .4byte 0x0000140C
_080BC0C8: .4byte 0x0000140D
_080BC0CC: .4byte 0x0000140E
_080BC0D0:
	cmp r0, #0
	bne _080BC0E0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080bbbdc
_080BC0E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
