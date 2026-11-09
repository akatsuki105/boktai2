	push {r4, r5, lr}
	adds r5, r1, #0
	adds r2, r5, #0
	adds r2, #0x20
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805EB52
	movs r4, #0
	strb r4, [r5, #1]
	movs r1, #1
	strb r1, [r5, #2]
	str r4, [r5, #0x14]
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	adds r0, r2, #0
	bl AuxSprite_Remove
	strb r4, [r5]
_0805EB52:
	pop {r4, r5}
	pop {r0}
	bx r0
