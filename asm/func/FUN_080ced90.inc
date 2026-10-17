	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	cmp r1, #0
	bge _080CEDAE
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	b _080CEEB6
_080CEDAE:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _080CEDBE
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	b _080CEEB6
_080CEDBE:
	cmp r1, #5
	bgt _080CEE10
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080CEDD8
	movs r1, #0
	strb r1, [r4, #3]
	ldr r2, _080CEDD4 @ =0x00000951
	adds r0, r6, r2
	strb r1, [r0]
	b _080CEDFE
	.align 2, 0
_080CEDD4: .4byte 0x00000951
_080CEDD8:
	movs r5, #1
	strb r5, [r4, #3]
	adds r0, r6, #0
	bl FUN_080ced00
	cmp r0, #0
	blt _080CEDFE
	ldr r1, _080CEE08 @ =0x00000979
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _080CEE0C @ =0x00000964
	adds r1, r6, r2
	movs r0, #0x20
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x13
	adds r1, r6, r2
	strb r0, [r1]
_080CEDFE:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	b _080CEEB6
	.align 2, 0
_080CEE08: .4byte 0x00000979
_080CEE0C: .4byte 0x00000964
_080CEE10:
	cmp r1, #0x10
	bne _080CEE72
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r4, r6, r2
	ldrb r0, [r4]
	cmp r0, #1
	bhi _080CEEB6
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080CEE6E
	adds r0, r6, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CEEB4
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r2, #0x20
	adds r1, r6, r2
	str r1, [r0]
	adds r5, r6, #0
	adds r5, #0xe8
	adds r0, r5, #0
	bl AuxSprite_SetGfx
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	movs r4, #0
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl AuxAnim_RestartAnim
	str r4, [r5]
	adds r0, r6, #0
	bl FUN_080cec18
_080CEE6E:
	movs r0, #0xd
	b _080CEEB6
_080CEE72:
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #1
	bhi _080CEEB6
	cmp r1, #8
	bne _080CEE96
	adds r0, r6, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CEEB4
	adds r0, r6, #0
	bl FUN_080cec18
	movs r0, #2
	b _080CEEB6
_080CEE96:
	cmp r1, #0xb
	bne _080CEE9E
	movs r0, #2
	b _080CEEB6
_080CEE9E:
	cmp r1, #0xd
	bne _080CEEB4
	ldr r1, _080CEEB0 @ =0x000003FB
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CEEB4
	movs r0, #0x11
	b _080CEEB6
	.align 2, 0
_080CEEB0: .4byte 0x000003FB
_080CEEB4:
	ldrb r0, [r4]
_080CEEB6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
