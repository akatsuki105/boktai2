	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080D8348
	subs r0, #1
	strh r0, [r1]
	b _080D838A
_080D8348:
	adds r5, r4, #0
	adds r5, #0xb2
	ldrh r0, [r5]
	lsrs r0, r0, #2
	strh r0, [r4, #0x28]
	ldrh r0, [r5]
	cmp r0, #0
	bne _080D8368
	ldr r0, [r4, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x18]
	ldr r0, _080D8394 @ =0x00000195
	bl PlaySound_082406e0
_080D8368:
	ldrh r0, [r5]
	cmp r0, #7
	bhi _080D8376
	adds r0, r4, #0
	adds r0, #0x60
	bl Hitbox_Register
_080D8376:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080D838A
	adds r0, r4, #0
	bl KillEntity
_080D838A:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D8394: .4byte 0x00000195
