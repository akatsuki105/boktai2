	push {lr}
	cmp r0, #1
	beq _080034AE
	cmp r0, #1
	bgt _080034A0
	cmp r0, #0
	beq _080034A4
	b _080034BC
_080034A0:
	cmp r0, #5
	bgt _080034BC
_080034A4:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080034C4
_080034AE:
	ldr r0, _080034B8 @ =0x00000137
	bl PlaySound_082406e0
	b _080034C4
	.align 2, 0
_080034B8: .4byte 0x00000137
_080034BC:
	movs r0, #0xa1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080034C4:
	pop {r0}
	bx r0
