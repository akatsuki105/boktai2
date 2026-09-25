	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x8c
	movs r7, #0
	movs r6, #7
_080A98CC:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _080A98E0
	adds r0, r5, #0
	adds r0, #0xc4
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080A98E0:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A98CC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
