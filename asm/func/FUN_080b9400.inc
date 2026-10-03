	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #0
	bl GetBgTilemapAddr
	adds r1, r0, #0
	cmp r4, #0
	bne _080B9444
	ldr r2, _080B9440 @ =0x0000F03B
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	bl Time_GetHour
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	bl Time_GetMinute
	b _080B9470
	.align 2, 0
_080B9440: .4byte 0x0000F03B
_080B9444:
	cmp r4, #1
	bne _080B9488
	ldr r2, _080B9480 @ =0x0000F045
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _080B9484 @ =0x030047E0
	ldrb r0, [r5, #0xa]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	ldrb r0, [r5, #0xb]
_080B9470:
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_080b93b0
	b _080B94BC
	.align 2, 0
_080B9480: .4byte 0x0000F045
_080B9484: .4byte 0x030047E0
_080B9488:
	ldr r2, _080B94C4 @ =0x0000F045
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _080B94C8 @ =0x030047E0
	ldrb r0, [r5, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_080b93b0
	ldrb r0, [r5, #0xd]
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_080b93b0
_080B94BC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B94C4: .4byte 0x0000F045
_080B94C8: .4byte 0x030047E0
