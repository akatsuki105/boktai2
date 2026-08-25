	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r7
	bne _08064FEE
	b _080650FE
_08064FEE:
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _08064FFE
	movs r1, #0
	strb r1, [r4, #3]
	ldr r2, _08065010 @ =0x00000951
	adds r0, r5, r2
	strb r1, [r0]
_08064FFE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08065014
	adds r0, r5, #0
	movs r1, #0xc
	b _0806501C
	.align 2, 0
_08065010: .4byte 0x00000951
_08065014:
	cmp r0, #3
	bne _08065024
	adds r0, r5, #0
	movs r1, #0xd
_0806501C:
	movs r2, #0
	bl FUN_08060b84
	b _08065032
_08065024:
	cmp r0, #4
	bne _08065032
	adds r0, r5, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
_08065032:
	movs r6, #0
	strb r7, [r4]
	lsls r0, r7, #0x18
	cmp r0, #0
	bge _08065068
	strb r6, [r4, #3]
	movs r0, #0xff
	strb r0, [r4, #1]
	strb r6, [r4, #2]
	strb r6, [r4, #4]
	ldr r2, _08065060 @ =0x00000979
	adds r0, r5, r2
	strb r6, [r0]
	ldr r1, _08065064 @ =0x00000962
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080650F0
	subs r2, #0x15
	adds r0, r5, r2
	strh r6, [r0]
	b _080650F0
	.align 2, 0
_08065060: .4byte 0x00000979
_08065064: .4byte 0x00000962
_08065068:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCategory
	strb r0, [r4, #1]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_08064c48
	strb r0, [r4, #2]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_08064b00
	strb r0, [r4, #4]
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _080650FE
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080650D8
	movs r6, #1
	strb r6, [r4, #3]
	adds r0, r5, #0
	bl FUN_08064d04
	cmp r0, #0
	blt _080650FE
	ldr r1, _080650CC @ =0x00000979
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080650D0 @ =0x00000964
	adds r1, r5, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, _080650D4 @ =0x00000121
	adds r0, r0, r1
	subs r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x11
	adds r1, r5, r2
	strb r0, [r1]
	b _080650FE
	.align 2, 0
_080650CC: .4byte 0x00000979
_080650D0: .4byte 0x00000964
_080650D4: .4byte 0x00000121
_080650D8:
	strb r6, [r4, #3]
	ldr r1, _08065104 @ =0x00000979
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _08065108 @ =0x00000962
	adds r0, r5, r2
	ldrh r1, [r0]
	cmp r1, #0
	bne _080650F0
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_080650F0:
	movs r1, #0x95
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0806510C @ =0x00000951
	adds r0, r5, r2
	strb r1, [r0]
_080650FE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065104: .4byte 0x00000979
_08065108: .4byte 0x00000962
_0806510C: .4byte 0x00000951
