	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _081EAB9C @ =0x0000052C
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x3c
	movs r6, #0x9e
	lsls r6, r6, #1
_081EAB8A:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EABA0
	movs r0, #1
	b _081EABA2
	.align 2, 0
_081EAB9C: .4byte 0x0000052C
_081EABA0:
	movs r0, #0
_081EABA2:
	cmp r0, #0
	bne _081EABBC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	adds r0, r2, #0
	b _081EABC6
_081EABBC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #3
	ble _081EAB8A
	movs r0, #0
_081EABC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
