	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BAF48 @ =0x00001314
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BAF42
	ldr r2, _080BAF4C @ =0x0000140E
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r2, #3
	adds r1, r4, r2
	ldrb r1, [r1]
	bl SwapNormalItem
	adds r0, r4, #0
	bl FUN_080baa64
_080BAF42:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BAF48: .4byte 0x00001314
_080BAF4C: .4byte 0x0000140E
