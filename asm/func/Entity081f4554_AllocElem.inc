	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
	ldr r0, _081F4284 @ =0x00000173
	adds r6, r2, r0
	adds r4, r2, #0
	adds r4, #0x20
_081F4274:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F4288
	movs r0, #1
	b _081F428A
	.align 2, 0
_081F4284: .4byte 0x00000173
_081F4288:
	movs r0, #0
_081F428A:
	cmp r0, #0
	bne _081F42A6
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x1c]
	adds r0, r4, #0
	movs r1, #0xba
	lsls r1, r1, #1
	bl ClearMemory
	strb r5, [r6]
	adds r0, r4, #0
	b _081F42B6
_081F42A6:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081F4274
	movs r0, #0
_081F42B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
