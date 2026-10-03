	push {r4, lr}
	movs r4, #0
_080BAA44:
	adds r0, r4, #0
	bl GetNormalItemID
	cmp r0, #0
	bge _080BAA52
	adds r0, r4, #0
	b _080BAA5C
_080BAA52:
	adds r4, #1
	cmp r4, #0xf
	ble _080BAA44
	movs r0, #1
	rsbs r0, r0, #0
_080BAA5C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
