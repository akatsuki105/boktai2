	push {lr}
	adds r2, r0, #0
	movs r1, #0
	ldrh r0, [r2, #0x1a]
	cmp r1, r0
	bge _081DDC22
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r3, r2, r0
_081DDC16:
	adds r0, r3, r1
	strb r1, [r0]
	adds r1, #1
	ldrh r0, [r2, #0x1a]
	cmp r1, r0
	blt _081DDC16
_081DDC22:
	cmp r1, #4
	bgt _081DDC38
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r3, #4
_081DDC2E:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, #1
	cmp r1, #4
	ble _081DDC2E
_081DDC38:
	pop {r0}
	bx r0
