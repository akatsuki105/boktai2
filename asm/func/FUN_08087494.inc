	push {r4, lr}
	ldr r1, _080874B4 @ =0x000003B6
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r3, r1, #0
	cmp r3, #0
	beq _080874C4
	ldr r4, _080874B8 @ =0x000001F5
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _080874C0
	cmp r3, #2
	bls _080874BC
	subs r0, r1, #2
	b _080874C2
	.align 2, 0
_080874B4: .4byte 0x000003B6
_080874B8: .4byte 0x000001F5
_080874BC:
	movs r0, #0
	b _080874C2
_080874C0:
	subs r0, r1, #1
_080874C2:
	strh r0, [r2]
_080874C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
