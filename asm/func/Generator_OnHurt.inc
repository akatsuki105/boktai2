	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0x7f
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080B2A0A
	adds r1, r2, #0
	adds r5, r1, #0
	adds r5, #0xe0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080B2A0A
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #2
	bne _080B2A0A
	ldrh r1, [r3, #0x3c]
	ldrh r0, [r4, #0x3c]
	subs r1, r1, r0
	cmp r1, #0
	bge _080B29D6
	movs r1, #1
_080B29D6:
	adds r3, r2, #0
	adds r3, #0xeb
	movs r0, #4
	strb r0, [r3]
	subs r3, #0x19
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xd4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _080B2A00
	strh r1, [r3]
	adds r0, r2, #0
	movs r1, #3
	bl Generator_SetState
	b _080B2A0A
_080B2A00:
	movs r0, #0xc
	strh r0, [r5]
	ldr r0, _080B2A10 @ =0x00000127
	bl PlaySound_082406e0
_080B2A0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2A10: .4byte 0x00000127
