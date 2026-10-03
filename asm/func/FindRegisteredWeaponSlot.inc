	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r0, _080BD464 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x60
_080BD456:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080BD468
	adds r0, r2, #0
	b _080BD474
	.align 2, 0
_080BD464: .4byte 0x030046A0
_080BD468:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080BD456
	movs r0, #1
	rsbs r0, r0, #0
_080BD474:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
