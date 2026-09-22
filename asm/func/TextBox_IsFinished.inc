	push {lr}
	ldr r0, _08048928 @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _0804892C
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	b _0804892E
	.align 2, 0
_08048928: .4byte 0x030000C4
_0804892C:
	movs r0, #0
_0804892E:
	pop {r1}
	bx r1
	.align 2, 0
