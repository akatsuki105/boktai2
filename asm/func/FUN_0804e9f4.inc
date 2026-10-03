	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl SignalStrengthIcon_Create
	cmp r0, #0
	beq _0804EA08
	adds r0, #0x44
	strh r4, [r0, #0x20]
	strh r5, [r0, #0x22]
_0804EA08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
