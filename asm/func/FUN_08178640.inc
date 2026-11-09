	push {lr}
	cmp r1, #0
	beq _08178658
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0817865C @ =0x0000100A
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_08178658:
	pop {r0}
	bx r0
	.align 2, 0
_0817865C: .4byte 0x0000100A
