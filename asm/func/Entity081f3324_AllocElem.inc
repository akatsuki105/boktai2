	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r7, #1
_081F30B4:
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F30C4
	movs r0, #1
	b _081F30C6
_081F30C4:
	movs r0, #0
_081F30C6:
	cmp r0, #0
	bne _081F30F0
	movs r0, #0xf4
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r5, r4
	adds r0, r4, #0
	movs r1, #0xf4
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r6
	ldr r0, [r5, #0x38]
	orrs r0, r1
	str r0, [r5, #0x38]
	adds r0, r4, #0
	adds r0, #0xeb
	strb r6, [r0]
	adds r0, r4, #0
	b _081F30F8
_081F30F0:
	adds r6, #1
	cmp r6, #0xb
	ble _081F30B4
	movs r0, #0
_081F30F8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
