	push {r4, lr}
	movs r2, #0
	movs r1, #0
	ldr r0, _08211150 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r4, #1
_08211134:
	adds r0, r3, #0
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _08211140
	adds r2, #1
_08211140:
	adds r1, #1
	cmp r1, #0x1a
	ble _08211134
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08211150: .4byte 0x030046A0
