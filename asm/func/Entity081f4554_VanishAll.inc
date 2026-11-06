	push {r4, r5, r6, lr}
	ldr r0, _081F45DC @ =0x030001F4
	ldr r4, [r0]
	cmp r4, #0
	bne _081F45C0
	bl Entity081f4554_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _081F4606
_081F45C0:
	movs r3, #0
	movs r5, #1
	adds r2, r4, #0
	adds r2, #0x20
	movs r6, #0xba
	lsls r6, r6, #1
_081F45CC:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F45E0
	movs r0, #1
	b _081F45E2
	.align 2, 0
_081F45DC: .4byte 0x030001F4
_081F45E0:
	movs r0, #0
_081F45E2:
	cmp r0, #0
	beq _081F45FE
	movs r0, #0xa9
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #5
	beq _081F45FE
	movs r0, #5
	strb r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r2, r1
	strb r5, [r0]
_081F45FE:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #3
	ble _081F45CC
_081F4606:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
