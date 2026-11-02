	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081E974C:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081E975E
	movs r0, #1
	b _081E9760
_081E975E:
	movs r0, #0
_081E9760:
	cmp r0, #0
	bne _081E977C
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0xe4
	strb r2, [r1]
	b _081E9784
_081E977C:
	adds r2, #1
	cmp r2, #0xb
	ble _081E974C
	movs r0, #0
_081E9784:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
