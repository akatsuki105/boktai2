	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EDCA4
	movs r4, #0
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r7, _081EDC78 @ =0x085AE4BC
_081EDC66:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EDC7C
	movs r0, #1
	b _081EDC7E
	.align 2, 0
_081EDC78: .4byte 0x085AE4BC
_081EDC7C:
	movs r0, #0
_081EDC7E:
	cmp r0, #0
	beq _081EDC9E
	movs r0, #0xdc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, #0x18
	adds r1, r5, r1
	adds r0, r1, #0
	adds r0, #0xd7
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EDC9E:
	adds r4, #1
	cmp r4, #1
	ble _081EDC66
_081EDCA4:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
