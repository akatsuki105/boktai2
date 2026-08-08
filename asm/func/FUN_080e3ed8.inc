	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r4, #1
	beq _080E3F12
	cmp r4, #1
	bgt _080E3EF0
	cmp r4, #0
	beq _080E3EFA
	b _080E3F36
_080E3EF0:
	cmp r4, #2
	beq _080E3EFA
	cmp r4, #3
	beq _080E3F12
	b _080E3F36
_080E3EFA:
	movs r2, #0
	ldrsh r1, [r5, r2]
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080E3F0A
	rsbs r0, r0, #0
_080E3F0A:
	adds r0, #0x80
	cmp r0, #0
	bge _080E3F28
	b _080E3F2C
_080E3F12:
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080E3F22
	rsbs r0, r0, #0
_080E3F22:
	adds r0, #0x80
	cmp r0, #0
	blt _080E3F2C
_080E3F28:
	asrs r0, r0, #8
	b _080E3F32
_080E3F2C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080E3F32:
	adds r2, r0, #1
	b _080E3F38
_080E3F36:
	movs r2, #0
_080E3F38:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080e3cc8
	cmp r0, r6
	bne _080E3F48
	movs r0, #0
	b _080E3F4A
_080E3F48:
	movs r0, #1
_080E3F4A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
