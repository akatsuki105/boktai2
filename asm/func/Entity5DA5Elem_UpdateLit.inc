	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl Entity5DA5Elem_ConsumeStateEntered
	cmp r0, #0
	beq _08008C2E
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	movs r0, #1
	ldrb r1, [r4]
	lsls r0, r1
	ldrh r1, [r5, #0x1c]
	orrs r0, r1
	strh r0, [r5, #0x1c]
_08008C2E:
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x4c
	bl MainSprite_AdvanceAnim
	pop {r4, r5}
	pop {r0}
	bx r0
