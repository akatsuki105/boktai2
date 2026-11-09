	push {lr}
	ldr r0, _08203740 @ =0x0300021C
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #7
	bls _08203748
	b _08203768
	.align 2, 0
_08203740: .4byte 0x0300021C
_08203744:
	adds r0, r1, #0
	b _0820376A
_08203748:
	adds r1, #0x40
	movs r2, #0
	movs r3, #1
_0820374E:
	adds r0, r1, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08203760
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _08203744
_08203760:
	adds r1, #0x98
	adds r2, #1
	cmp r2, #7
	ble _0820374E
_08203768:
	movs r0, #0
_0820376A:
	pop {r1}
	bx r1
	.align 2, 0
