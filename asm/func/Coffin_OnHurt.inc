	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	bne _080875DC
	adds r5, r2, #0
	ldrb r0, [r5, #0x1b]
	cmp r0, #1
	beq _080875DC
	movs r2, #0
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _0808755E
	ldrh r1, [r3, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08087564
	ldr r0, [r3, #0x34]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08087560
	b _08087564
_0808755E:
	movs r2, #1
_08087560:
	cmp r2, #0
	beq _080875DC
_08087564:
	ldr r1, _08087584 @ =0x00000332
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080875DC
	ldrh r0, [r3, #0x3c]
	cmp r0, #0
	beq _080875DC
	movs r0, #1
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08087588
	movs r1, #0xc8
	b _080875C4
	.align 2, 0
_08087584: .4byte 0x00000332
_08087588:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08087598
	movs r1, #0x96
	lsls r1, r1, #1
	movs r4, #0xc
	b _080875C6
_08087598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080875A6
	movs r1, #0xfa
	lsls r1, r1, #1
	b _080875C4
_080875A6:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080875B2
	movs r1, #0x96
	b _080875C4
_080875B2:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080875C0
	movs r1, #0xfa
	lsls r1, r1, #1
	b _080875C4
_080875C0:
	movs r1, #0xc8
	lsls r1, r1, #1
_080875C4:
	movs r4, #8
_080875C6:
	adds r0, r5, #0
	bl FUN_080873b4
	movs r1, #0xcc
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	ldr r1, _080875E4 @ =0x00000332
	adds r0, r5, r1
	strh r4, [r0]
_080875DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080875E4: .4byte 0x00000332
