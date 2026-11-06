	push {r4, r5, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r5, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x40
_0805B1F6:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _0805B206
	str r2, [r4]
	adds r0, r3, #0
	b _0805B210
_0805B206:
	adds r3, #0x8c
	adds r2, #1
	cmp r2, #0xf
	ble _0805B1F6
	movs r0, #0
_0805B210:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
