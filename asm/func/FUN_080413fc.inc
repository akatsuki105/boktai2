	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	cmp r0, #1
	bne _08041426
	ldrb r0, [r4, #0x1a]
	cmp r0, #4
	bls _08041420
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _08041442
_08041420:
	ldrb r2, [r4, #0x1a]
	movs r3, #0
	b _08041442
_08041426:
	ldrb r0, [r4, #0x1a]
	cmp r0, #4
	bls _08041436
	adds r1, r0, #0
	movs r0, #8
	subs r2, r0, r1
	movs r3, #1
	b _0804143C
_08041436:
	ldrb r2, [r4, #0x1a]
	movs r3, #0
	adds r1, r2, #0
_0804143C:
	adds r0, r1, #0
	muls r0, r5, r0
	strb r0, [r4, #0x1a]
_08041442:
	adds r0, r4, #0
	adds r0, #0xd0
	str r6, [sp]
	ldr r1, [sp, #0x20]
	str r1, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	adds r1, r7, #0
	bl SpriteHolder_SetAnim
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
