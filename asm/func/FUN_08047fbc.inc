	push {lr}
	ldr r0, _08047FCC @ =0x030000C4
	ldr r0, [r0]
	cmp r0, #0
	beq _08047FD0
	movs r0, #0
	b _08047FD4
	.align 2, 0
_08047FCC: .4byte 0x030000C4
_08047FD0:
	movs r0, #1
	rsbs r0, r0, #0
_08047FD4:
	pop {r1}
	bx r1
