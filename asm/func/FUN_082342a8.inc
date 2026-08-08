	push {lr}
	ldr r2, [r0, #8]
	ldr r1, [r0, #0xc]
	cmp r2, #0
	beq _082342B6
	str r1, [r2, #0xc]
	b _082342BC
_082342B6:
	ldr r0, _082342C8 @ =0x030046A4
	ldr r0, [r0]
	str r1, [r0, #0x18]
_082342BC:
	cmp r1, #0
	beq _082342C2
	str r2, [r1, #8]
_082342C2:
	pop {r0}
	bx r0
	.align 2, 0
_082342C8: .4byte 0x030046A4
