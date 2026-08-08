	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08065B76
	movs r1, #8
	ldr r0, _08065B64 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08065B68 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065B6C
	movs r0, #1
	b _08065B6E
	.align 2, 0
_08065B64: .4byte 0x030046A0
_08065B68: .4byte 0x00000934
_08065B6C:
	movs r0, #0
_08065B6E:
	cmp r0, #0
	beq _08065B76
	movs r0, #1
	b _08065B78
_08065B76:
	movs r0, #0
_08065B78:
	pop {r1}
	bx r1
