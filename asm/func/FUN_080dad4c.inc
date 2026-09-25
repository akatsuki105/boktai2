	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_080DAD54:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _080DAD66
	movs r0, #1
	b _080DAD68
_080DAD66:
	movs r0, #0
_080DAD68:
	cmp r0, #0
	bne _080DAD84
	movs r0, #0xa4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0x42
	strh r2, [r1]
	b _080DAD8C
_080DAD84:
	adds r2, #1
	cmp r2, #7
	ble _080DAD54
	movs r0, #0
_080DAD8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
