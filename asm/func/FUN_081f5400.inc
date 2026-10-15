	push {r4, r5, r6, lr}
	ldr r0, _081F5428 @ =0x030001F8
	ldr r4, [r0]
	cmp r4, #0
	beq _081F5452
	movs r3, #0
	movs r5, #1
	adds r2, r4, #0
	adds r2, #0x20
	movs r6, #0xc2
	lsls r6, r6, #1
_081F5416:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F542C
	movs r0, #1
	b _081F542E
	.align 2, 0
_081F5428: .4byte 0x030001F8
_081F542C:
	movs r0, #0
_081F542E:
	cmp r0, #0
	beq _081F544A
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #3
	beq _081F544A
	movs r0, #3
	strb r0, [r1]
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r0, r2, r1
	strb r5, [r0]
_081F544A:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #7
	ble _081F5416
_081F5452:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
