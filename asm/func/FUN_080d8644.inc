	push {r4, lr}
	movs r4, #0
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x32
	adds r2, r0, #0
	adds r2, #0x3e
	adds r0, #0x4c
_080D8654:
	strb r3, [r1]
	strb r3, [r1, #3]
	stm r0!, {r3}
	strh r3, [r2]
	adds r1, #1
	adds r2, #2
	adds r4, #1
	cmp r4, #2
	ble _080D8654
	pop {r4}
	pop {r0}
	bx r0
