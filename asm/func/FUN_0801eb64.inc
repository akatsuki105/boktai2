	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EB7E
	ldrb r0, [r4, #0x1e]
	bl TextBox_ShowLine
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0
	strb r0, [r1]
_0801EB7E:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _0801EB9C
	ldr r1, [r4, #0x24]
	cmp r1, #0xf
	bhi _0801EB9C
	lsrs r1, r1, #1
	movs r0, #8
	subs r3, r0, r1
	adds r2, r1, #0
	adds r2, #8
	movs r0, #0
	adds r1, r3, #0
	bl FUN_0822f178
_0801EB9C:
	ldr r0, [r4, #0x24]
	adds r5, r4, #0
	adds r5, #0x22
	cmp r0, #0x1f
	bls _0801EBD8
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EBDE
	ldr r0, _0801EBF8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0801EBD8
	adds r1, r4, #0
	adds r1, #0x21
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	strb r0, [r5]
	ldr r0, _0801EBFC @ =0x00000107
	bl PlaySound_082406e0
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1, #8]
	orrs r0, r6
	str r0, [r1, #8]
_0801EBD8:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801EC20
_0801EBDE:
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801EC00
	ldrb r0, [r4, #0x1b]
	adds r0, #1
	strb r0, [r4, #0x1b]
	ldrb r1, [r4, #0x1b]
	adds r0, r4, #0
	bl FUN_0801e284
	b _0801EC46
	.align 2, 0
_0801EBF8: .4byte 0x030044E0
_0801EBFC: .4byte 0x00000107
_0801EC00:
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _0801EC46
	ldrb r0, [r1]
	movs r1, #0x10
	subs r3, r1, r0
	lsrs r0, r0, #1
	adds r2, r0, #0
	adds r2, #8
	movs r0, #0
	adds r1, r3, #0
	bl FUN_0822f178
	b _0801EC46
_0801EC20:
	ldr r0, [r4, #0x24]
	cmp r0, #0x20
	bne _0801EC36
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0801EC36:
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r4, r2
	bl MainSprite_AdvanceAnim
_0801EC46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
