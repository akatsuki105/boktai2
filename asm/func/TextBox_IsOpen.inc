	push {lr}
	ldr r0, _0804772C @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047728
	movs r0, #1
_08047728:
	pop {r1}
	bx r1
	.align 2, 0
_0804772C: .4byte 0x030000C4
