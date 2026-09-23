	push {r4, r5, lr}
	adds r3, r0, #0
	adds r3, #0x24
	movs r2, #0
	movs r5, #1
	ldr r4, [r0, #0x1c]
_080604C8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r4
	cmp r0, #0
	bne _080604D8
	str r2, [r1]
	adds r0, r3, #0
	b _080604E4
_080604D8:
	adds r2, #1
	adds r3, #0x38
	cmp r2, #0xf
	ble _080604C8
	movs r0, #0
	str r0, [r1]
_080604E4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
