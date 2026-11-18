	push {lr}
	adds r2, r0, #0
	ldr r0, _0819CD14 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CD18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CD1A
	.align 2, 0
_0819CD14: .4byte 0x0000046D
_0819CD18:
	movs r0, #0
_0819CD1A:
	cmp r0, #0
	beq _0819CD2E
	ldr r0, _0819CD34 @ =0x00000482
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Enemy_PlayAnimNoFacing
_0819CD2E:
	pop {r0}
	bx r0
	.align 2, 0
_0819CD34: .4byte 0x00000482
