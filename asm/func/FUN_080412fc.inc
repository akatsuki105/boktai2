	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	adds r0, #0x44
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xa4
	adds r1, r4, #0
	adds r1, #0x64
	str r1, [r2]
	bl FUN_08234660
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _08041330
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	b _08041346
_08041330:
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055f1c
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _0804134E
_08041346:
	adds r0, r4, #0
	bl FUN_0804106c
	b _08041354
_0804134E:
	adds r0, r4, #0
	bl FUN_0804109c
_08041354:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
