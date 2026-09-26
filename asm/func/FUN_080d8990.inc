	push {lr}
	cmp r0, #1
	beq _080D89B4
	cmp r0, #1
	bgt _080D89A0
	cmp r0, #0
	beq _080D89AA
	b _080D89C6
_080D89A0:
	cmp r0, #2
	beq _080D89BE
	cmp r0, #3
	beq _080D89BE
	b _080D89C6
_080D89AA:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #0xb
	b _080D89C4
_080D89B4:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D89C4
_080D89BE:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D89C4:
	str r0, [r2]
_080D89C6:
	pop {r0}
	bx r0
	.align 2, 0
