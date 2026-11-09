	push {r4, lr}
	ldr r0, _08202EC8 @ =0x03000218
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #7
	bls _08202ED0
	b _08202EF4
	.align 2, 0
_08202EC8: .4byte 0x03000218
_08202ECC:
	adds r0, r1, #0
	b _08202EF6
_08202ED0:
	adds r1, #0x40
	movs r2, #0
	movs r4, #1
	movs r3, #0x82
	lsls r3, r3, #1
_08202EDA:
	adds r0, r1, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #0
	bne _08202EEC
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	bne _08202ECC
_08202EEC:
	adds r1, r1, r3
	adds r2, #1
	cmp r2, #7
	ble _08202EDA
_08202EF4:
	movs r0, #0
_08202EF6:
	pop {r4}
	pop {r1}
	bx r1
