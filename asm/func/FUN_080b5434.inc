	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080B5480 @ =0x00000844
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B5496
	ldr r0, _080B5484 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bne _080B5490
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B5488 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B548C @ =FUN_080b54ec
	adds r0, r4, #0
	bl DarkLoans_SetUpdate
	b _080B5496
	.align 2, 0
_080B5480: .4byte 0x00000844
_080B5484: .4byte 0x030046A0
_080B5488: .4byte 0x0000FFFF
_080B548C: .4byte FUN_080b54ec
_080B5490:
	adds r0, r4, #0
	bl FUN_080b4e04
_080B5496:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
