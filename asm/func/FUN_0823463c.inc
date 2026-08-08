	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	ldrb r0, [r5, #3]
	cmp r4, r0
	bge _0823465A
	adds r6, r5, #0
	adds r6, #8
_0823464C:
	ldm r6!, {r0}
	bl FUN_08234980
	adds r4, #1
	ldrb r0, [r5, #3]
	cmp r4, r0
	blt _0823464C
_0823465A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
