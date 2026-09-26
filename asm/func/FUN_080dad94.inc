	push {lr}
	adds r3, r0, #0
	ldr r0, _080DADD0 @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _080DADE6
	cmp r0, #0
	beq _080DADE6
	cmp r0, #4
	beq _080DADE6
	ldr r0, _080DADD4 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _080DADD8 @ =0x00000934
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080DADE6
	adds r0, r3, #0
	adds r0, #0x46
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080DADDC
	movs r0, #1
	b _080DADDE
	.align 2, 0
_080DADD0: .4byte 0x030047E0
_080DADD4: .4byte 0x030046A0
_080DADD8: .4byte 0x00000934
_080DADDC:
	movs r0, #0
_080DADDE:
	cmp r0, #0
	beq _080DADE6
	movs r0, #1
	b _080DADE8
_080DADE6:
	movs r0, #0
_080DADE8:
	pop {r1}
	bx r1
