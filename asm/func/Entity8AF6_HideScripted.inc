	push {lr}
	bl Entity8AF6_FindEntry
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5A3C
	ldr r0, [r1, #0x40]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #0x40]
	adds r0, r1, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A3C
	adds r0, r1, #0
	adds r0, #0x9e
	strh r2, [r0]
_080A5A3C:
	pop {r0}
	bx r0
