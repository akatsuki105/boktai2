	push {lr}
	ldr r0, _0804E600 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E5FA
	adds r1, r0, #0
	adds r1, #0x3d
	movs r0, #1
	strb r0, [r1]
_0804E5FA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E600: .4byte 0x03002B58
