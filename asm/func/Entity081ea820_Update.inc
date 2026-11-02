	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x38
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _081EA7AA
	movs r4, #0
	ldr r7, _081EA780 @ =0x085AE46C
_081EA76E:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA784
	movs r0, #1
	b _081EA786
	.align 2, 0
_081EA780: .4byte 0x085AE46C
_081EA784:
	movs r0, #0
_081EA786:
	cmp r0, #0
	beq _081EA7A4
	movs r0, #0xd4
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EA7A4:
	adds r4, #1
	cmp r4, #7
	ble _081EA76E
_081EA7AA:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
