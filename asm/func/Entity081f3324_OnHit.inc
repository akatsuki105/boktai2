	push {lr}
	adds r3, r2, #0
	adds r3, #0xea
	ldrb r0, [r3]
	cmp r0, #1
	bne _081F2730
	adds r0, r2, #0
	adds r0, #0x88
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	movs r0, #2
	strb r0, [r3]
_081F2730:
	pop {r0}
	bx r0
