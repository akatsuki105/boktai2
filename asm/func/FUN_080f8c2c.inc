	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080F8C4E
	ldrh r0, [r2, #6]
	cmp r0, #0
	bne _080F8C4E
	ldrb r0, [r2, #5]
	cmp r0, #1
	bne _080F8C52
	bl FUN_0808672c
	cmp r0, #0
	bne _080F8C52
_080F8C4E:
	movs r0, #0
	b _080F8C54
_080F8C52:
	movs r0, #1
_080F8C54:
	pop {r1}
	bx r1
