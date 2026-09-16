	push {r4, lr}
	adds r3, r1, #0
	adds r4, r3, #0
	adds r4, #0x24
	ldrh r1, [r2]
	strh r1, [r3, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r3, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r3, #0x20]
	ldrh r1, [r2]
	strh r1, [r4, #0x1c]
	ldrh r1, [r2, #2]
	strh r1, [r4, #0x1e]
	ldrh r1, [r2, #4]
	strh r1, [r4, #0x20]
	ldrb r1, [r3, #2]
	cmp r1, #0
	beq _080092CC
	ldrh r1, [r3, #0x1c]
	adds r1, #0x80
	strh r1, [r3, #0x1c]
	ldrh r1, [r4, #0x20]
	subs r1, #0x80
	strh r1, [r4, #0x20]
	b _080092D8
_080092CC:
	ldrh r1, [r3, #0x20]
	adds r1, #0x80
	strh r1, [r3, #0x20]
	ldrh r1, [r4, #0x1c]
	subs r1, #0x80
	strh r1, [r4, #0x1c]
_080092D8:
	ldrh r1, [r4, #0x1c]
	adds r1, #0x3c
	strh r1, [r4, #0x1c]
	ldrh r1, [r4, #0x20]
	adds r1, #0x3c
	strh r1, [r4, #0x20]
	ldrh r1, [r4, #0x1e]
	adds r1, #0x14
	strh r1, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1
