	push {lr}
	bl FUN_082316bc
	adds r1, r0, #0
	cmp r1, #0
	beq _082323EC
	bl fetch_082316e4
	ldr r1, _082323E8 @ =0x030045A0
	str r0, [r1, #4]
	b _082323F0
	.align 2, 0
_082323E8: .4byte 0x030045A0
_082323EC:
	ldr r0, _082323F8 @ =0x030045A0
	str r1, [r0, #4]
_082323F0:
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_082323F8: .4byte 0x030045A0
