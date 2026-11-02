	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081EA228:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x34]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081EA23A
	movs r0, #1
	b _081EA23C
_081EA23A:
	movs r0, #0
_081EA23C:
	cmp r0, #0
	bne _081EA258
	movs r0, #0xd4
	muls r0, r2, r0
	adds r0, #0x38
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x34]
	adds r1, r0, #0
	adds r1, #0xd3
	strb r2, [r1]
	b _081EA260
_081EA258:
	adds r2, #1
	cmp r2, #7
	ble _081EA228
	movs r0, #0
_081EA260:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
