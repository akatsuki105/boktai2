	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, _08065180 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _08065184
	movs r0, #0xff
	b _0806518A
	.align 2, 0
_08065180: .4byte 0x030047A4
_08065184:
	adds r0, r5, #0
	bl FUN_08065110
_0806518A:
	strb r0, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _080651A2
	movs r0, #0xff
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #4]
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	b _080651F4
_080651A2:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCategory
	strb r0, [r4, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_08064b00
	strb r0, [r4, #4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_08064c48
	strb r0, [r4, #2]
	ldr r1, _080651D8 @ =0x03002BB0
	ldrh r1, [r1]
	adds r2, r1, #0
	strb r1, [r4, #3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080651DC
	strb r0, [r4, #3]
	b _080651F4
	.align 2, 0
_080651D8: .4byte 0x03002BB0
_080651DC:
	lsls r0, r2, #0x18
	cmp r0, #0
	beq _080651F4
	ldrb r1, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080651F4
	adds r1, #1
	ldr r2, _080651FC @ =0x00000951
	adds r0, r5, r2
	strb r1, [r0]
_080651F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080651FC: .4byte 0x00000951
