	push {lr}
	movs r2, #0
	ldrh r1, [r0, #0x24]
	cmp r2, r1
	bge _080193AA
	adds r3, r1, #0
	adds r1, r0, #0
	adds r1, #0x34
_08019398:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080193A2
	movs r0, #1
	b _080193AC
_080193A2:
	adds r1, #0x30
	adds r2, #1
	cmp r2, r3
	blt _08019398
_080193AA:
	movs r0, #0
_080193AC:
	pop {r1}
	bx r1
