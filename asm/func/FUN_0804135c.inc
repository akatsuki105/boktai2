	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0xd0
	ldr r0, [r5]
	cmp r0, #1
	bne _08041384
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bls _0804137E
	adds r1, r0, #0
	movs r0, #3
	subs r2, r0, r1
	b _0804139A
_0804137E:
	ldrb r2, [r4, #0x19]
	movs r3, #0
	b _0804139C
_08041384:
	ldrb r1, [r4, #0x19]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #1
	bhi _08041394
	adds r2, r3, #0
_08041394:
	movs r3, #0
	cmp r1, #1
	bls _0804139C
_0804139A:
	movs r3, #1
_0804139C:
	str r6, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r7, #0
	bl SpriteHolder_SetAnim
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
