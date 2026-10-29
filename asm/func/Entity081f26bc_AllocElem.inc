	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
	adds r6, r2, #0
	adds r6, #0x8b
	adds r4, r2, #0
	adds r4, #0x1c
_081F1954:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _081F1964
	movs r0, #1
	b _081F1966
_081F1964:
	movs r0, #0
_081F1966:
	cmp r0, #0
	bne _081F1980
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x18]
	adds r0, r4, #0
	movs r1, #0x78
	bl ClearMemory
	strb r5, [r6]
	adds r0, r4, #0
	b _081F198C
_081F1980:
	adds r6, #0x78
	adds r4, #0x78
	adds r5, #1
	cmp r5, #0x17
	ble _081F1954
	movs r0, #0
_081F198C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
