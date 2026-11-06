	push {lr}
	ldr r0, _081F4620 @ =0x030001F4
	ldr r0, [r0]
	cmp r0, #0
	bne _081F4628
	bl Entity081f4554_Create
	cmp r0, #0
	bne _081F4628
	b _081F4648
	.align 2, 0
_081F4620: .4byte 0x030001F4
_081F4624:
	movs r0, #0
	b _081F464A
_081F4628:
	movs r1, #0
	movs r3, #1
	ldr r2, [r0, #0x1c]
_081F462E:
	adds r0, r3, #0
	lsls r0, r1
	ands r0, r2
	cmp r0, #0
	beq _081F463C
	movs r0, #1
	b _081F463E
_081F463C:
	movs r0, #0
_081F463E:
	cmp r0, #0
	beq _081F4624
	adds r1, #1
	cmp r1, #3
	ble _081F462E
_081F4648:
	movs r0, #1
_081F464A:
	pop {r1}
	bx r1
	.align 2, 0
