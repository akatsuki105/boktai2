	push {r4, r5, lr}
	adds r4, r1, #0
	ldr r2, [r0, #0x70]
	movs r3, #0
	ldrh r0, [r0, #0x18]
	cmp r3, r0
	bge _080046C0
	movs r5, #0xce
	lsls r5, r5, #1
	adds r1, r0, #0
_080046A8:
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _080046B8
	ldrh r0, [r2, #0x2c]
	cmp r0, r4
	bne _080046B8
	adds r0, r2, #0
	b _080046C2
_080046B8:
	adds r2, r2, r5
	adds r3, #1
	cmp r3, r1
	blt _080046A8
_080046C0:
	movs r0, #0
_080046C2:
	pop {r4, r5}
	pop {r1}
	bx r1
