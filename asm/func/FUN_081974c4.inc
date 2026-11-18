	push {r4, lr}
	ldr r2, _081974EC @ =0x00000B18
	adds r1, r0, r2
	movs r4, #0
	ldr r1, [r1]
	ldr r3, _081974F0 @ =0x00000A84
	adds r2, r0, r3
	movs r3, #0xf
_081974D4:
	strh r4, [r2]
	ldrh r0, [r1]
	strh r0, [r2, #0x20]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _081974D4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081974EC: .4byte 0x00000B18
_081974F0: .4byte 0x00000A84
