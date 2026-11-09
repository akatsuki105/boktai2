	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #2
	bls _080A3370
	subs r0, #2
	strb r0, [r2]
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	b _080A3378
_080A3370:
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
_080A3378:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A3388
	subs r0, #1
	strh r0, [r1]
_080A3388:
	ldrh r0, [r1]
	cmp r0, #7
	bls _080A33A2
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A33CA
_080A33A2:
	cmp r0, #0
	beq _080A33BA
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A33CA
_080A33BA:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A33CA:
	ldr r0, _080A3424 @ =0x00000382
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _080A3428
	ldr r0, [r4, #0x50]
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0xa6
	strb r1, [r0]
	b _080A3440
	.align 2, 0
_080A3424: .4byte 0x00000382
_080A3428:
	ldr r0, [r4, #0x50]
	movs r2, #1
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl KillEntity
_080A3440:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
