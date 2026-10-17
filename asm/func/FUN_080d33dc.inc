	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080D3428 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _080D342C @ =0x00000A8A
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _080D33F6
	ldr r0, [r6, #0x18]
	ldr r1, _080D3430 @ =0x00000391
	bl Sound_PlayForPlayer
_080D33F6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080D34A6
	ldr r2, _080D3434 @ =gSineTable
	ldr r3, _080D3438 @ =0x00000A8C
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080D343C
	asrs r1, r0, #0xc
	b _080D3442
	.align 2, 0
_080D3428: .4byte 0x000009C8
_080D342C: .4byte 0x00000A8A
_080D3430: .4byte 0x00000391
_080D3434: .4byte gSineTable
_080D3438: .4byte 0x00000A8C
_080D343C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D3442:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080D3474
	asrs r1, r0, #0xc
	b _080D347A
_080D3474:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D347A:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r4, r6, r3
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0
	b _080D34AC
_080D34A6:
	movs r0, #0
	strh r0, [r4]
	movs r0, #1
_080D34AC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
