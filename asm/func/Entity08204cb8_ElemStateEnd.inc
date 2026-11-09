	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x3f
	ldrb r2, [r4]
	cmp r2, #0
	bne _08204A8A
	adds r0, r6, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #1
	strb r0, [r4]
_08204A8A:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08204ABA
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _08204AC2
_08204ABA:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08204AC2:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08204AE6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08204AEE
_08204AE6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08204AEE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08204B28 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08204B6E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08204B32
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08204B2C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204B48
	.align 2, 0
_08204B28: .4byte 0x0000FFFF
_08204B2C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204B46
_08204B32:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204B46
	strh r1, [r4, #8]
	movs r2, #1
	b _08204B48
_08204B46:
	movs r2, #0
_08204B48:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08204B70
	movs r0, #1
	strb r0, [r4, #7]
	b _08204B70
_08204B6E:
	movs r2, #0
_08204B70:
	cmp r2, #0
	beq _08204B7A
	adds r0, r6, #0
	bl Entity08204cb8_RemoveElem
_08204B7A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
