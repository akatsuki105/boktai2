	push {r4, r5, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
_081F0040:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0050
	movs r0, #1
	b _081F0052
_081F0050:
	movs r0, #0
_081F0052:
	cmp r0, #0
	bne _081F007A
	movs r0, #0x9c
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r2, r4
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x38]
	adds r0, r4, #0
	movs r1, #0x9c
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x97
	strb r5, [r0]
	adds r0, r4, #0
	b _081F0082
_081F007A:
	adds r5, #1
	cmp r5, #0xb
	ble _081F0040
	movs r0, #0
_081F0082:
	pop {r4, r5}
	pop {r1}
	bx r1
