	push {r4, r5, r6, r7, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, [r0, #8]
	ldrh r4, [r0]
	movs r2, #0
	ldrsh r3, [r1, r2]
	ldrh r2, [r0, #2]
	movs r7, #4
	ldrsh r0, [r1, r7]
	subs r2, r2, r0
	subs r4, r4, r3
	cmp r4, #0
	bge _081D267E
	rsbs r4, r4, #0
_081D267E:
	cmp r4, r5
	bhi _081D2690
	cmp r2, #0
	bge _081D2688
	rsbs r2, r2, #0
_081D2688:
	cmp r2, r6
	bhi _081D2690
	movs r0, #1
	b _081D2692
_081D2690:
	movs r0, #0
_081D2692:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
