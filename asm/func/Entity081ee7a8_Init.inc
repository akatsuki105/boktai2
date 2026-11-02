	push {lr}
	ldr r1, _081EE7A4 @ =0x030001D0
	str r0, [r1]
	movs r3, #0xff
	adds r1, r0, #0
	adds r1, #0x88
	movs r2, #0x2f
_081EE78E:
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r1, #0x70
	subs r2, #1
	cmp r2, #0
	bge _081EE78E
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081EE7A4: .4byte 0x030001D0
