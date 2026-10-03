	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x6c
	movs r6, #0
_081E17CC:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _081E17EA
	cmp r7, #0
	bne _081E17DE
	adds r0, r5, #0
	bl FUN_081e1734
	movs r7, #1
_081E17DE:
	ldr r3, [r4, #0x20]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
_081E17EA:
	adds r6, #1
	adds r4, #0x90
	cmp r6, #4
	ble _081E17CC
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
