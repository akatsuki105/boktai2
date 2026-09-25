	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0
	movs r2, #1
_080DD898:
	adds r1, r2, #0
	lsls r1, r4
	ldr r0, [r3, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _080DD8A8
	movs r0, #1
	b _080DD8AA
_080DD8A8:
	movs r0, #0
_080DD8AA:
	cmp r0, #0
	bne _080DD8C6
	movs r0, #0x64
	muls r0, r4, r0
	adds r0, #0x1c
	adds r0, r3, r0
	adds r1, r0, #0
	adds r1, #0x5e
	strb r4, [r1]
	lsls r2, r4
	ldr r1, [r3, #0x18]
	orrs r1, r2
	str r1, [r3, #0x18]
	b _080DD8CE
_080DD8C6:
	adds r4, #1
	cmp r4, #4
	ble _080DD898
	movs r0, #0
_080DD8CE:
	pop {r4}
	pop {r1}
	bx r1
