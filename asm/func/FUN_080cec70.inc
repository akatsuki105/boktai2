	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	blt _080CECA0
	adds r0, r4, #0
	bl GetMagicCategory
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrb r1, [r1]
	cmp r1, #0
	bne _080CECA4
	cmp r2, #0
	bne _080CEC98
	cmp r4, #1
	beq _080CECA0
	b _080CECF4
_080CEC98:
	cmp r2, #1
	beq _080CECF4
	cmp r2, #2
	bne _080CECFA
_080CECA0:
	movs r0, #0
	b _080CECFA
_080CECA4:
	cmp r1, #1
	bne _080CECE8
	cmp r2, #0
	bne _080CECC2
	cmp r4, #0
	beq _080CECA0
	cmp r4, #2
	beq _080CECA0
	cmp r4, #3
	beq _080CECA0
	cmp r4, #4
	beq _080CECA0
	cmp r4, #5
	beq _080CECA0
	b _080CECF4
_080CECC2:
	cmp r2, #1
	beq _080CECA0
	cmp r2, #2
	bne _080CECFA
	cmp r4, #0xe
	bne _080CECF4
	ldr r0, _080CECE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080CECE4 @ =0x00000252
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _080CECA0
	b _080CECF4
	.align 2, 0
_080CECE0: .4byte 0x030046A0
_080CECE4: .4byte 0x00000252
_080CECE8:
	cmp r1, #5
	beq _080CECF4
	cmp r1, #3
	bne _080CECF8
	cmp r4, #0x10
	bne _080CECA0
_080CECF4:
	movs r0, #1
	b _080CECFA
_080CECF8:
	movs r0, #0
_080CECFA:
	pop {r4, r5}
	pop {r1}
	bx r1
