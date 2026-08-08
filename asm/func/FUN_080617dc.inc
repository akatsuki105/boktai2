	push {lr}
	adds r3, r0, #0
	movs r0, #3
	ands r0, r3
	cmp r0, #1
	beq _080617F8
	cmp r0, #1
	bgt _080617F2
	cmp r0, #0
	beq _080617F8
	b _080617F6
_080617F2:
	cmp r0, #2
	beq _080617F8
_080617F6:
	movs r0, #1
_080617F8:
	str r0, [r1]
	cmp r3, #2
	bhi _08061802
	movs r0, #0
	b _08061816
_08061802:
	subs r0, r3, #3
	cmp r0, #1
	bhi _0806180C
	movs r0, #2
	b _08061816
_0806180C:
	cmp r3, #5
	bne _08061814
	movs r0, #3
	b _08061816
_08061814:
	movs r0, #1
_08061816:
	str r0, [r2]
	pop {r0}
	bx r0
