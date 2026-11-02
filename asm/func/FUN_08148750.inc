	push {lr}
	adds r1, r0, #0
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #6
	cmp r1, #1
	beq _08148778
	cmp r1, #1
	bgt _0814876A
	cmp r1, #0
	beq _08148774
	b _0814877A
_0814876A:
	cmp r1, #2
	beq _08148774
	cmp r1, #3
	beq _08148778
	b _0814877A
_08148774:
	movs r0, #0
	b _0814877A
_08148778:
	movs r0, #1
_0814877A:
	pop {r1}
	bx r1
	.align 2, 0
