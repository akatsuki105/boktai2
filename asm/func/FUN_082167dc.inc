	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _082167F4 @ =0x000012B0
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #1
	beq _08216828
	cmp r4, #1
	bgt _082167F8
	cmp r4, #0
	beq _082167FE
	b _0821687C
	.align 2, 0
_082167F4: .4byte 0x000012B0
_082167F8:
	cmp r4, #2
	beq _08216858
	b _0821687C
_082167FE:
	ldr r5, _08216824 @ =0x000012BA
	adds r2, r3, r5
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	subs r5, #6
	adds r1, r3, r5
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	blt _0821681A
	strh r4, [r2]
_0821681A:
	adds r0, r3, #0
	bl FUN_08216000
	b _0821687C
	.align 2, 0
_08216824: .4byte 0x000012BA
_08216828:
	ldr r0, _08216850 @ =0x000012BC
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r4, _08216854 @ =0x000012B6
	adds r1, r3, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	blt _08216846
	movs r0, #0
	strh r0, [r2]
_08216846:
	adds r0, r3, #0
	bl FUN_0821605c
	b _0821687C
	.align 2, 0
_08216850: .4byte 0x000012BC
_08216854: .4byte 0x000012B6
_08216858:
	ldr r0, _08216888 @ =0x000012BE
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r4, _0821688C @ =0x000012B8
	adds r1, r3, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	blt _08216876
	movs r0, #0
	strh r0, [r2]
_08216876:
	adds r0, r3, #0
	bl FUN_082160d8
_0821687C:
	ldr r0, _08216890 @ =0x0000037D
	bl PlaySound_082406e0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08216888: .4byte 0x000012BE
_0821688C: .4byte 0x000012B8
_08216890: .4byte 0x0000037D
