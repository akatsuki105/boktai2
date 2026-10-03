	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x3c
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FB50
	movs r0, #2
	b _0804FB5C
_0804FB50:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FB5C
	movs r0, #1
_0804FB5C:
	strb r0, [r2, #7]
	ldrh r1, [r1, #0x1c]
	movs r0, #0xb4
	lsls r0, r0, #2
	subs r0, r0, r1
	str r0, [r2, #8]
	pop {r0}
	bx r0
