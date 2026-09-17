	push {lr}
	ldr r0, _08013D24 @ =0x03002B40
	ldr r0, [r0]
	cmp r0, #0
	bne _08013D1E
	bl Entity08013df0_Create
_08013D1E:
	pop {r1}
	bx r1
	.align 2, 0
_08013D24: .4byte 0x03002B40
