	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	ble _08049700
	adds r5, r2, #0
	adds r2, r6, #0
	adds r2, #0xc4
	adds r3, r4, #0
_080496F6:
	ldm r5!, {r1}
	stm r2!, {r1}
	subs r3, #1
	cmp r3, #0
	bne _080496F6
_08049700:
	strb r4, [r6, #0xd]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
