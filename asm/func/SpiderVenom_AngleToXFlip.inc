	push {lr}
	adds r1, r0, #0
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bgt _081E8AB0
	cmp r1, #1
	blt _081E8AB0
	movs r0, #1
	b _081E8AB2
_081E8AB0:
	movs r0, #0
_081E8AB2:
	pop {r1}
	bx r1
	.align 2, 0
