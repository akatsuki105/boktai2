	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _080540A2
	movs r4, #0
	strb r4, [r5, #0xe]
	str r4, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0xf
	movs r3, #2
	bl BlackPantherElem_PlayAnim
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #0x14
	str r0, [sp, #0x14]
	movs r0, #0x10
	str r0, [sp, #0x18]
	movs r0, #7
	movs r1, #0x1a
	movs r3, #0
	bl Entity080146e0_SpawnAtAngle
_080540A2:
	ldr r0, [r6, #0x28]
	adds r0, #0x18
	str r0, [r6, #0x28]
	str r0, [r6, #0x24]
	adds r0, r5, #0
	adds r0, #0x7c
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _080540C4
	movs r0, #3
	movs r1, #0
	strb r0, [r5, #0xd]
	movs r0, #1
	strb r0, [r5, #0xe]
	str r1, [r5, #0x1c]
	b _080540CA
_080540C4:
	ldr r0, [r5, #0x1c]
	adds r0, #1
	str r0, [r5, #0x1c]
_080540CA:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
