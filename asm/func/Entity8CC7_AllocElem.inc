	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D8A58 @ =0x00000ECC
	adds r2, r3, r0
	movs r6, #1
_081D8A48:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D8A5C
	movs r0, #1
	b _081D8A5E
	.align 2, 0
_081D8A58: .4byte 0x00000ECC
_081D8A5C:
	movs r0, #0
_081D8A5E:
	cmp r0, #0
	bne _081D8A88
	movs r0, #0xbc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xbc
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x6c
	strh r5, [r0]
	adds r0, r4, #0
	b _081D8A90
_081D8A88:
	adds r5, #1
	cmp r5, #0x13
	ble _081D8A48
	movs r0, #0
_081D8A90:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
