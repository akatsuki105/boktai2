	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080CF648 @ =0x08DAA7E8
	ldr r0, _080CF64C @ =0x00000266
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r2, #2]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CF654
	subs r2, #0xfc
	adds r0, r4, r2
	ldr r2, _080CF650 @ =0x00000362
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #1
	movs r3, #2
	bl Hitbox_SetPowerAndAttributes
	b _080CF668
	.align 2, 0
_080CF648: .4byte 0x08DAA7E8
_080CF64C: .4byte 0x00000266
_080CF650: .4byte 0x00000362
_080CF654:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _080CF67C @ =0x00000362
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
_080CF668:
	movs r0, #0xde
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, _080CF680 @ =0xF000000F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF67C: .4byte 0x00000362
_080CF680: .4byte 0xF000000F
