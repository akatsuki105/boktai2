	push {lr}
	ldr r2, _0817DECC @ =0x000008B7
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817DEC8
	subs r0, #1
	strb r0, [r1]
_0817DEC8:
	pop {r0}
	bx r0
	.align 2, 0
_0817DECC: .4byte 0x000008B7
