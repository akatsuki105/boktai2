	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0
	ldr r2, _080BD054 @ =0x00001648
	adds r0, r0, r2
	ldr r3, [r0]
	ldrb r2, [r3]
	cmp r2, #0
	beq _080BD044
	adds r4, r5, #0
	adds r4, #0xc
_080BD032:
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #1
	adds r1, #1
	ldrb r2, [r3]
	cmp r2, #0
	beq _080BD044
	cmp r1, #0xa
	ble _080BD032
_080BD044:
	adds r0, r5, #0
	adds r0, #0xc
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BD054: .4byte 0x00001648
