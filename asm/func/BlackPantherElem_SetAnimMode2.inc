	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0x7c
	ldr r0, [r4, #0x7c]
	cmp r0, #1
	bne _0805324C
	ldrb r0, [r4, #0x10]
	cmp r0, #1
	bls _08053246
	adds r1, r0, #0
	movs r0, #3
	subs r2, r0, r1
	b _08053262
_08053246:
	ldrb r2, [r4, #0x10]
	movs r3, #0
	b _08053264
_0805324C:
	ldrb r1, [r4, #0x10]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	cmp r0, #1
	bhi _0805325C
	adds r2, r3, #0
_0805325C:
	movs r3, #0
	cmp r1, #1
	bls _08053264
_08053262:
	movs r3, #1
_08053264:
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
