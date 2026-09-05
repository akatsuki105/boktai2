	push {lr}
	ldr r2, _080A7A14 @ =0x085AD034
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A7A14: .4byte 0x085AD034
