	push {lr}
	ldr r0, _0804E5AC @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E5B0
	adds r0, #0x33
	ldrb r0, [r0]
	b _0804E5B4
	.align 2, 0
_0804E5AC: .4byte 0x03002B58
_0804E5B0:
	ldr r0, _0804E5B8 @ =0x030000E0
	ldr r0, [r0]
_0804E5B4:
	pop {r1}
	bx r1
	.align 2, 0
_0804E5B8: .4byte 0x030000E0
