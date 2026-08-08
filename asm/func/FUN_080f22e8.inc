	push {lr}
	ldr r2, _080F2308 @ =0x00000469
	adds r1, r0, r2
	ldrb r1, [r1]
	movs r3, #0xc6
	lsls r3, r3, #3
	adds r2, r0, r3
	ldr r2, [r2]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080F2308: .4byte 0x00000469
