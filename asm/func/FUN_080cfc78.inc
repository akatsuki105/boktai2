	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFCAA
	movs r1, #8
	ldr r0, _080CFC98 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC9C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFCA0
	movs r0, #1
	b _080CFCA2
	.align 2, 0
_080CFC98: .4byte 0x030046A0
_080CFC9C: .4byte 0x00000934
_080CFCA0:
	movs r0, #0
_080CFCA2:
	cmp r0, #0
	beq _080CFCAA
	movs r0, #1
	b _080CFCAC
_080CFCAA:
	movs r0, #0
_080CFCAC:
	pop {r1}
	bx r1
