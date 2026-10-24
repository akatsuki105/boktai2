	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A45DE
	ldr r0, [r4]
	movs r1, #4
	ands r0, r1
	movs r5, #1
	cmp r0, #0
	beq _080A45C4
	movs r5, #2
_080A45C4:
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45D4
	asrs r0, r0, #8
	b _080A45DA
_080A45D4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A45DA:
	adds r3, r0, #1
	b _080A45F6
_080A45DE:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45F0
	asrs r3, r0, #8
	b _080A45F6
_080A45F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_080A45F6:
	adds r0, r4, #0
	adds r0, #0xf8
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r1, [r1]
	movs r2, #0xff
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	adds r2, r5, #0
	bl Map_AddTileOverride
	adds r1, r4, #0
	adds r1, #0xf7
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
