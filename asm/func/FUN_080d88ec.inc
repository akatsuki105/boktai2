	push {lr}
	cmp r0, #1
	beq _080D8918
	cmp r0, #1
	bgt _080D88FC
	cmp r0, #0
	beq _080D8906
	b _080D894E
_080D88FC:
	cmp r0, #2
	beq _080D892A
	cmp r0, #3
	beq _080D8936
	b _080D894E
_080D8906:
	cmp r3, #0
	bne _080D8914
	movs r0, #0xc
	rsbs r0, r0, #0
	str r0, [r1]
	str r3, [r2]
	b _080D894E
_080D8914:
	str r0, [r1]
	b _080D894C
_080D8918:
	cmp r3, #3
	bgt _080D894E
	cmp r3, #0
	blt _080D894E
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D894C
_080D892A:
	cmp r3, #0
	beq _080D8932
	cmp r3, #3
	bne _080D8942
_080D8932:
	movs r0, #0
	b _080D8946
_080D8936:
	cmp r3, #0
	beq _080D893E
	cmp r3, #3
	bne _080D8942
_080D893E:
	movs r0, #0
	b _080D8946
_080D8942:
	movs r0, #8
	rsbs r0, r0, #0
_080D8946:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
_080D894C:
	str r0, [r2]
_080D894E:
	pop {r0}
	bx r0
	.align 2, 0
