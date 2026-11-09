	push {r4, lr}
	adds r4, r0, #0
	bl MainSprite_AdvanceAnim
	adds r2, r0, #0
	ldrb r1, [r4, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081DBE5C
	cmp r2, #0
	beq _081DBE60
_081DBE5C:
	movs r0, #1
	b _081DBE62
_081DBE60:
	movs r0, #0
_081DBE62:
	pop {r4}
	pop {r1}
	bx r1
