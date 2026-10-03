	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #1
	bl GetBgTilemapAddr
	adds r1, r0, #0
	cmp r4, #0
	bne _080B9520
	ldr r2, _080B9518 @ =0x0000F03E
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x2a
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x68
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B951C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	b _080B9554
	.align 2, 0
_080B9518: .4byte 0x0000F03E
_080B951C: .4byte 0x030046A0
_080B9520:
	cmp r4, #1
	bne _080B956C
	ldr r2, _080B9564 @ =0x0000F040
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x2c
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x39
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B9568 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
_080B9554:
	movs r1, #0xfa
	lsls r1, r1, #2
	str r4, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_080b93b0
	b _080B95AA
	.align 2, 0
_080B9564: .4byte 0x0000F040
_080B9568: .4byte 0x030046A0
_080B956C:
	ldr r2, _080B95B4 @ =0x0000F042
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #0x25
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r0, _080B95B8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, #0x2c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_080b93b0
_080B95AA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B95B4: .4byte 0x0000F042
_080B95B8: .4byte 0x030046A0
