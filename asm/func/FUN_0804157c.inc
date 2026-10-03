	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08041592
	rsbs r1, r1, #0
_08041592:
	cmp r1, r2
	bge _080415C2
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r5, #2
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _080415A6
	rsbs r1, r1, #0
_080415A6:
	cmp r1, #0xff
	bgt _080415C2
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _080415BA
	rsbs r0, r0, #0
_080415BA:
	cmp r0, r2
	bge _080415C2
	movs r0, #1
	b _080415C4
_080415C2:
	movs r0, #0
_080415C4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
