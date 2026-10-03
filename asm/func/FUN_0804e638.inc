	push {lr}
	ldr r0, _0804E648 @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E64C
	adds r0, #0x6c
	ldrh r0, [r0]
	b _0804E64E
	.align 2, 0
_0804E648: .4byte 0x03002B58
_0804E64C:
	movs r0, #0
_0804E64E:
	pop {r1}
	bx r1
	.align 2, 0
