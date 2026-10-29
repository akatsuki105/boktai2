	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _081EEEF8 @ =0x00000838
	adds r4, r2, r0
	movs r5, #1
_081EEEE8:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EEEFC
	movs r0, #1
	b _081EEEFE
	.align 2, 0
_081EEEF8: .4byte 0x00000838
_081EEEFC:
	movs r0, #0
_081EEEFE:
	cmp r0, #0
	bne _081EEF1C
	movs r0, #0xd0
	muls r0, r3, r0
	adds r0, #0x18
	adds r0, r2, r0
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	adds r1, r0, #0
	adds r1, #0xbd
	strb r3, [r1]
	b _081EEF24
_081EEF1C:
	adds r3, #1
	cmp r3, #9
	ble _081EEEE8
	movs r0, #0
_081EEF24:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
