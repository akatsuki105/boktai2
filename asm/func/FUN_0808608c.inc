	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r0, r6, #0
	bl Map_FindNavRectAt
	cmp r0, #0xff
	beq _080860BE
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl Map_InitNavAgent
	movs r0, #0xea
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08235a84
	cmp r0, #0
	bne _080860C2
_080860BE:
	movs r0, #0
	b _080860C4
_080860C2:
	movs r0, #1
_080860C4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
