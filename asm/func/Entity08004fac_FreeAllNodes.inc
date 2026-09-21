	push {r4, lr}
	ldr r0, _08004DF0 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004DF4
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E08
	.align 2, 0
_08004DF0: .4byte 0x03000024
_08004DF4:
	ldr r0, [r0, #0x18]
	cmp r0, #0
	beq _08004E06
_08004DFA:
	ldr r4, [r0, #0x20]
	bl Entity08004fac_FreeNode
	adds r0, r4, #0
	cmp r0, #0
	bne _08004DFA
_08004E06:
	movs r0, #0
_08004E08:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
