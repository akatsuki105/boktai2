	push {lr}
	ldr r0, _080488F0 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _080488F4
	adds r0, #0x18
	bl FUN_08048c58
	b _080488F6
	.align 2, 0
_080488F0: .4byte 0x030000C4
_080488F4:
	movs r0, #0
_080488F6:
	pop {r1}
	bx r1
	.align 2, 0
