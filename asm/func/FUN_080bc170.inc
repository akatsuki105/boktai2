	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080BC1D0 @ =0x00001314
	adds r0, r5, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BC1CA
	ldr r2, _080BC1D4 @ =0x0000140B
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r2, #3
	adds r1, r5, r2
	ldrb r4, [r1]
	adds r4, r5, r4
	ldr r1, _080BC1D8 @ =0x000012F4
	adds r4, r4, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl SetArmorIntoInventory
	ldr r0, _080BC1DC @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0x91
	lsls r0, r0, #4
	adds r2, r2, r0
	ldr r1, _080BC1E0 @ =0x08DAA7B0
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r2]
	ldrh r0, [r0, #6]
	subs r1, r1, r0
	strh r1, [r2]
	ldr r2, _080BC1E4 @ =0x0000151B
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BC1E8 @ =0x00000111
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080bbbdc
_080BC1CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BC1D0: .4byte 0x00001314
_080BC1D4: .4byte 0x0000140B
_080BC1D8: .4byte 0x000012F4
_080BC1DC: .4byte 0x030046A0
_080BC1E0: .4byte 0x08DAA7B0
_080BC1E4: .4byte 0x0000151B
_080BC1E8: .4byte 0x00000111
