	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r3, r4, #0
	adds r3, #8
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08060372
	movs r0, #0
	strb r0, [r4, #1]
_08060372:
	adds r1, r4, #0
	adds r1, #0x20
	adds r2, r4, #0
	adds r2, #0x30
	ldrh r0, [r4, #0x30]
	ldrh r7, [r3, #0x18]
	adds r0, r0, r7
	strh r0, [r3, #0x18]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r7, [r1, #4]
	adds r0, r0, r7
	strh r0, [r1, #4]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	cmp r0, r1
	blo _080603B0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl Entity08060470_ReleaseElem
	movs r0, #0
	strb r0, [r4]
	movs r0, #1
	strb r0, [r4, #1]
	movs r0, #0
	strh r0, [r4, #2]
_080603B0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
