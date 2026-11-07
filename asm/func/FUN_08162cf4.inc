	push {lr}
	adds r2, r0, #0
	ldr r0, _08162D14 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08162D06
	movs r0, #0
	strb r0, [r1]
_08162D06:
	adds r0, r2, #0
	movs r1, #1
	bl Enemy_PlayAnimNoFacing
	pop {r0}
	bx r0
	.align 2, 0
_08162D14: .4byte 0x0000046D
