	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
	movs r7, #0xae
	lsls r7, r7, #1
	ldr r0, _081F08A4 @ =0x0000018F
	adds r6, r2, r0
	adds r4, r2, #0
	adds r4, #0x3c
_081F0894:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F08A8
	movs r0, #1
	b _081F08AA
	.align 2, 0
_081F08A4: .4byte 0x0000018F
_081F08A8:
	movs r0, #0
_081F08AA:
	cmp r0, #0
	bne _081F08C4
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x38]
	adds r0, r4, #0
	adds r1, r7, #0
	bl ClearMemory
	strb r5, [r6]
	adds r0, r4, #0
	b _081F08D4
_081F08C4:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081F0894
	movs r0, #0
_081F08D4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
