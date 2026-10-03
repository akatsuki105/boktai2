	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAF80 @ =0x00001278
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BAF84 @ =0x000012EF
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BAF8C
	bl TextBox_Close
	adds r0, r4, #0
	bl FUN_080ba7bc
	ldr r1, _080BAF88 @ =FUN_080bafa4
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080ba054
	b _080BAF9C
	.align 2, 0
_080BAF80: .4byte 0x00001278
_080BAF84: .4byte 0x000012EF
_080BAF88: .4byte FUN_080bafa4
_080BAF8C:
	cmp r0, #0
	bne _080BAF9C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
