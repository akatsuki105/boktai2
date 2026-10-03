	push {lr}
	ldr r0, _0804E468 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E46C
	adds r0, #0x30
	ldrb r0, [r0]
	b _0804E46E
	.align 2, 0
_0804E468: .4byte 0x03002B58
_0804E46C:
	movs r0, #0
_0804E46E:
	pop {r1}
	bx r1
	.align 2, 0
