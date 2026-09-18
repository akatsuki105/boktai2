	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _0804E90A
	movs r5, #0xff
	bl FUN_0804e3ec
	cmp r0, #0
	beq _0804E902
	ldr r0, _0804E8B8 @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2]
	adds r7, r0, #0
	cmp r1, #0
	bne _0804E8BC
	bl FUN_0804e3c0
	ldr r1, [r7]
	adds r1, #0xa
	adds r1, r1, r0
	ldrb r5, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl SignalStrengthIcon_SetStrength
	b _0804E8F8
	.align 2, 0
_0804E8B8: .4byte 0x03005800
_0804E8BC:
	movs r1, #0
	ldrb r3, [r2, #2]
	movs r6, #1
	adds r2, #0xa
_0804E8C4:
	adds r0, r3, #0
	asrs r0, r1
	ands r0, r6
	cmp r0, #0
	beq _0804E8D8
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r5, r0
	ble _0804E8D8
	adds r5, r0, #0
_0804E8D8:
	adds r1, #1
	cmp r1, #3
	ble _0804E8C4
	ldr r0, [r7]
	ldrb r0, [r0, #2]
	cmp r0, #0
	bne _0804E8F0
	adds r0, r4, #0
	movs r1, #0
	bl SignalStrengthIcon_SetStrength
	b _0804E8F8
_0804E8F0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl SignalStrengthIcon_SetStrength
_0804E8F8:
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0804E908
_0804E902:
	ldr r0, [r4, #0x4c]
	movs r1, #1
	orrs r0, r1
_0804E908:
	str r0, [r4, #0x4c]
_0804E90A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
