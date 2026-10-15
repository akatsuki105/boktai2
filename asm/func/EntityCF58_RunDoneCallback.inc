	push {lr}
	adds r1, r0, #0
	adds r0, #0xa0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A5E8C
	adds r0, #4
	ldr r0, [r0]
	bl _call_via_r2
_080A5E8C:
	pop {r0}
	bx r0
