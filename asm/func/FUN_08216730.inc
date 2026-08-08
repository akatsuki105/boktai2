	push {lr}
	adds r2, r0, #0
	ldr r1, _08216748 @ =0x000012B0
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _08216778
	cmp r0, #1
	bgt _0821674C
	cmp r0, #0
	beq _08216752
	b _082167C4
	.align 2, 0
_08216748: .4byte 0x000012B0
_0821674C:
	cmp r0, #2
	beq _082167A4
	b _082167C4
_08216752:
	ldr r3, _08216774 @ =0x000012BA
	adds r1, r2, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0821676C
	subs r3, #6
	adds r0, r2, r3
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r1]
_0821676C:
	adds r0, r2, #0
	bl FUN_08216000
	b _082167C4
	.align 2, 0
_08216774: .4byte 0x000012BA
_08216778:
	ldr r0, _0821679C @ =0x000012BC
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08216792
	ldr r3, _082167A0 @ =0x000012B6
	adds r0, r2, r3
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r1]
_08216792:
	adds r0, r2, #0
	bl FUN_0821605c
	b _082167C4
	.align 2, 0
_0821679C: .4byte 0x000012BC
_082167A0: .4byte 0x000012B6
_082167A4:
	ldr r0, _082167D0 @ =0x000012BE
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _082167BE
	ldr r3, _082167D4 @ =0x000012B8
	adds r0, r2, r3
	ldrh r0, [r0]
	subs r0, #1
	strh r0, [r1]
_082167BE:
	adds r0, r2, #0
	bl FUN_082160d8
_082167C4:
	ldr r0, _082167D8 @ =0x0000037D
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_082167D0: .4byte 0x000012BE
_082167D4: .4byte 0x000012B8
_082167D8: .4byte 0x0000037D
