	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08013d10
	cmp r0, #0
	beq _08014016
	adds r1, r4, #0
	bl FUN_08013d28
	adds r2, r0, #0
	cmp r2, #0
	beq _08014016
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #4]
	str r1, [r2, #8]
	movs r0, #0
	b _0801401A
_08014016:
	movs r0, #1
	rsbs r0, r0, #0
_0801401A:
	pop {r4, r5}
	pop {r1}
	bx r1
