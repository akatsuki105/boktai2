	push {r4, r5, lr}
	movs r3, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x18
_080E139C:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080E13AC
	movs r0, #1
	b _080E13AE
_080E13AC:
	movs r0, #0
_080E13AE:
	cmp r0, #0
	bne _080E13C2
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	strh r3, [r2, #0x1a]
	adds r0, r2, #0
	b _080E13CC
_080E13C2:
	adds r2, #0x20
	adds r3, #1
	cmp r3, #0xb
	ble _080E139C
	movs r0, #0
_080E13CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
