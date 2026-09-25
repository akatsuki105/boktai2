	push {lr}
	cmp r0, #1
	beq _080D8978
	cmp r0, #1
	bgt _080D8964
	cmp r0, #0
	beq _080D896E
	b _080D898A
_080D8964:
	cmp r0, #2
	beq _080D8982
	cmp r0, #3
	beq _080D8982
	b _080D898A
_080D896E:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #0xb
	b _080D8988
_080D8978:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D8988
_080D8982:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D8988:
	str r0, [r2]
_080D898A:
	pop {r0}
	bx r0
	.align 2, 0
