	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r7, #0
	movs r5, #7
_080AA216:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _080AA22C
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080AA22C:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080AA216
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
