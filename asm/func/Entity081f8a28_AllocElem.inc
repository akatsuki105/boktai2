	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r3, #0
	movs r5, #1
	adds r2, r4, #0
	adds r2, #0x3c
	movs r6, #0x92
	lsls r6, r6, #1
_081F7F4C:
	adds r0, r5, #0
	lsls r0, r3
	ldr r1, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7F5C
	movs r0, #1
	b _081F7F5E
_081F7F5C:
	movs r0, #0
_081F7F5E:
	cmp r0, #0
	bne _081F7F78
	adds r0, r5, #0
	lsls r0, r3
	orrs r0, r1
	str r0, [r4, #0x38]
	ldr r1, _081F7F74 @ =0x0000011F
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r2, #0
	b _081F7F82
	.align 2, 0
_081F7F74: .4byte 0x0000011F
_081F7F78:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #7
	ble _081F7F4C
	movs r0, #0
_081F7F82:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
