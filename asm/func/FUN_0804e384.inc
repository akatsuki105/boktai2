	push {lr}
	ldr r0, _0804E39C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E396
	adds r1, r0, #0
	adds r1, #0xfb
	movs r0, #1
	strb r0, [r1]
_0804E396:
	pop {r0}
	bx r0
	.align 2, 0
_0804E39C: .4byte 0x03002B58
