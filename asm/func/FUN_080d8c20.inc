	push {lr}
	cmp r0, #0
	blt _080D8C6C
	cmp r0, #2
	ble _080D8C6C
	cmp r0, #3
	bne _080D8C6C
	cmp r3, #1
	beq _080D8C50
	cmp r3, #1
	bgt _080D8C3C
	cmp r3, #0
	beq _080D8C46
	b _080D8C6C
_080D8C3C:
	cmp r3, #2
	beq _080D8C5A
	cmp r3, #3
	beq _080D8C62
	b _080D8C6C
_080D8C46:
	movs r0, #2
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #6
	b _080D8C6A
_080D8C50:
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #3
	b _080D8C6A
_080D8C5A:
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	b _080D8C6A
_080D8C62:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #7
_080D8C6A:
	str r0, [r2]
_080D8C6C:
	pop {r0}
	bx r0
