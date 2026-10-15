	push {lr}
	bl Entity8AF6_FindEntry
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5A68
	ldr r0, [r2, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x40]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A68
	adds r1, r2, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
_080A5A68:
	pop {r0}
	bx r0
