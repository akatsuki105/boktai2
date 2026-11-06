	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _081F7D72
	movs r4, #0
	ldr r7, _081F7D48 @ =0x085AE5B4
_081F7D36:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7D4C
	movs r0, #1
	b _081F7D4E
	.align 2, 0
_081F7D48: .4byte 0x085AE5B4
_081F7D4C:
	movs r0, #0
_081F7D4E:
	cmp r0, #0
	beq _081F7D6C
	movs r0, #0x9c
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F7D6C:
	adds r4, #1
	cmp r4, #1
	ble _081F7D36
_081F7D72:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
