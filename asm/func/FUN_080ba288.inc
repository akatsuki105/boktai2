	push {r4, r5, lr}
	adds r5, r0, #0
	bl item_08092034
	movs r4, #0x32
	cmp r0, #0xcf
	beq _080BA2AE
	adds r1, r0, #0
	subs r1, #0xd0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r4, r4, r0
	cmp r4, #0x32
	ble _080BA2A8
	movs r4, #0x32
_080BA2A8:
	cmp r4, #0x13
	bgt _080BA2AE
	movs r4, #0x14
_080BA2AE:
	adds r0, r5, #0
	bl GetNormalItemID
	bl FUN_080ba220
	muls r0, r4, r0
	movs r1, #0x64
	bl Div
	cmp r0, #0
	bgt _080BA2C6
	movs r0, #1
_080BA2C6:
	ldr r1, _080BA2D4 @ =0x0000270F
	cmp r0, r1
	ble _080BA2CE
	adds r0, r1, #0
_080BA2CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080BA2D4: .4byte 0x0000270F
