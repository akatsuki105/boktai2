	push {lr}
	adds r2, r0, #0
	ldr r0, _0819CCE4 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CCE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CCEA
	.align 2, 0
_0819CCE4: .4byte 0x0000046D
_0819CCE8:
	movs r0, #0
_0819CCEA:
	cmp r0, #0
	beq _0819CCF6
	adds r0, r2, #0
	movs r1, #1
	bl Enemy_PlayAnimNoFacing
_0819CCF6:
	pop {r0}
	bx r0
	.align 2, 0
