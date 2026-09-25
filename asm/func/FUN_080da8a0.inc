	push {lr}
	adds r1, r0, #0
	ldr r0, _080DA8C0 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA8C4
	cmp r1, #0
	beq _080DA8C4
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DA8C4
	movs r0, #0
	b _080DA8C6
	.align 2, 0
_080DA8C0: .4byte 0x0300015C
_080DA8C4:
	movs r0, #1
_080DA8C6:
	pop {r1}
	bx r1
	.align 2, 0
