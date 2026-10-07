	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r7, #1
_081D81D2:
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D81E2
	movs r0, #1
	b _081D81E4
_081D81E2:
	movs r0, #0
_081D81E4:
	cmp r0, #0
	bne _081D821C
	movs r0, #0xdc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r2, r4
	adds r0, r4, #0
	movs r1, #0xdc
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xd0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xd2
	ldr r0, _081D8218 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r4, #0
	b _081D8224
	.align 2, 0
_081D8218: .4byte 0x0000FFFF
_081D821C:
	adds r5, #1
	cmp r5, #3
	ble _081D81D2
	movs r0, #0
_081D8224:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
