	push {lr}
	ldr r0, _082380A4 @ =0x030046D4
	ldr r0, [r0]
	cmp r0, #0
	blt _082380A0
	movs r0, #0
_082380A0:
	pop {r1}
	bx r1
	.align 2, 0
_082380A4: .4byte 0x030046D4
