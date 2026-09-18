	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0xe4
	ble _0804E7E6
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3f
	adds r1, r0, #0
	cmp r3, #7
	ble _0804E82A
	movs r2, #0x40
	cmp r3, #0xf
	ble _0804E82A
	movs r2, #0x42
	cmp r3, #0x17
	bgt _0804E82A
	movs r2, #0x41
	b _0804E82A
_0804E7E6:
	cmp r1, #0x7e
	ble _0804E802
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3f
	adds r1, r0, #0
	cmp r3, #9
	ble _0804E82A
	movs r2, #0x41
	cmp r3, #0x13
	bgt _0804E82A
	movs r2, #0x40
	b _0804E82A
_0804E802:
	cmp r1, #0x18
	ble _0804E81C
	ldr r0, [r4, #0x1c]
	movs r3, #0x1f
	ands r3, r0
	movs r2, #0x3e
	adds r1, r0, #0
	cmp r3, #9
	ble _0804E82A
	movs r2, #0x40
	cmp r3, #0x13
	bgt _0804E82A
	b _0804E828
_0804E81C:
	ldr r1, [r4, #0x1c]
	movs r0, #0x1f
	ands r0, r1
	movs r2, #0x3e
	cmp r0, #0xf
	bgt _0804E82A
_0804E828:
	movs r2, #0x3f
_0804E82A:
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	ldr r0, [r4, #0x20]
	cmp r2, r0
	beq _0804E844
	str r2, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x44
	adds r1, r4, #0
	adds r1, #0x24
	movs r3, #0
	bl MainSprite_SetPose
_0804E844:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
