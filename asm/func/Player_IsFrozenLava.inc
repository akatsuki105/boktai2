	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08065B02
	movs r1, #0x10
	ldr r0, _08065AF0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08065AF4 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065AF8
	movs r0, #1
	b _08065AFA
	.align 2, 0
_08065AF0: .4byte 0x030046A0
_08065AF4: .4byte 0x00000934
_08065AF8:
	movs r0, #0
_08065AFA:
	cmp r0, #0
	beq _08065B02
	movs r0, #1
	b _08065B04
_08065B02:
	movs r0, #0
_08065B04:
	pop {r1}
	bx r1
