	push {r4, lr}
	adds r2, r0, #0
	movs r3, #8
	ldrsb r3, [r2, r3]
	movs r1, #9
	ldrsb r1, [r2, r1]
	cmp r3, #0x40
	ble _0819863C
	movs r4, #0xc3
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r3, r0
	cmp r3, #0x3f
	bgt _0819863C
	movs r3, #0x40
_0819863C:
	cmp r1, #0x7e
	bgt _08198652
	ldr r4, _08198678 @ =0x00000187
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	cmp r1, #0x7f
	ble _08198652
	movs r1, #0x7f
_08198652:
	strb r3, [r2, #8]
	strb r1, [r2, #9]
	cmp r1, #0x7f
	bne _08198670
	movs r0, #0x40
	strb r0, [r2, #8]
	ldr r0, _08198678 @ =0x00000187
	adds r1, r2, r0
	movs r0, #0xf0
	strb r0, [r1]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r1, r2, r4
	ldr r0, _0819867C @ =FUN_08198680
	str r0, [r1]
_08198670:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08198678: .4byte 0x00000187
_0819867C: .4byte FUN_08198680
