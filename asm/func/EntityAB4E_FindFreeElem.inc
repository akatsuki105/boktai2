	push {lr}
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0xc0
	lsls r3, r3, #1
_080452DA:
	ldrb r0, [r1, #9]
	cmp r0, #0
	bne _080452E4
	adds r0, r1, #0
	b _080452EE
_080452E4:
	adds r2, #1
	adds r1, r1, r3
	cmp r2, #0xf
	ble _080452DA
	movs r0, #0
_080452EE:
	pop {r1}
	bx r1
	.align 2, 0
