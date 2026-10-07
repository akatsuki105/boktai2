	push {r4, lr}
	movs r4, #0
_080810FC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08081110
	adds r4, #1
	cmp r4, #0xf
	ble _080810FC
	movs r0, #0
_08081110:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
