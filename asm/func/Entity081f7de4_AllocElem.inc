	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081F79D4:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081F79E6
	movs r0, #1
	b _081F79E8
_081F79E6:
	movs r0, #0
_081F79E8:
	cmp r0, #0
	bne _081F7A04
	movs r0, #0x9c
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0x97
	strb r2, [r1]
	b _081F7A0C
_081F7A04:
	adds r2, #1
	cmp r2, #1
	ble _081F79D4
	movs r0, #0
_081F7A0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
