	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0801ACE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity78C9Elem_Destroy
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801ACE2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
