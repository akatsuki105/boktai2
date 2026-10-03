	push {lr}
	ldr r0, _0804E4A0 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E4A4
	ldrh r0, [r0, #0x38]
	b _0804E4A6
	.align 2, 0
_0804E4A0: .4byte 0x03002B58
_0804E4A4:
	movs r0, #0
_0804E4A6:
	pop {r1}
	bx r1
	.align 2, 0
