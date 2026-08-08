	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	bne _0806CC04
	ldr r2, _0806CC30 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806CC7A
_0806CC04:
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0
	bl FUN_08060b84
	ldr r3, _0806CC34 @ =0x000002E7
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CC3C
	ldr r1, _0806CC38 @ =0x000002E6
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #7
	subs r1, r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	b _0806CC4E
	.align 2, 0
_0806CC30: .4byte 0x0000037E
_0806CC34: .4byte 0x000002E7
_0806CC38: .4byte 0x000002E6
_0806CC3C:
	ldr r3, _0806CCA8 @ =0x000002E6
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, #1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
_0806CC4E:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08063220
	adds r0, r5, #0
	bl FUN_08066e84
	ldr r0, _0806CCAC @ =0x0000039A
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0806CC7A:
	ldr r1, _0806CCB0 @ =0x0000037E
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r3, #7
	adds r1, r3, #0
	ands r1, r0
	lsrs r0, r0, #2
	subs r0, r3, r0
	cmp r1, r0
	bge _0806CCD0
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #3
	bls _0806CCB4
	ldrb r0, [r2]
	subs r0, r3, r0
	asrs r0, r0, #1
	b _0806CCF4
	.align 2, 0
_0806CCA8: .4byte 0x000002E6
_0806CCAC: .4byte 0x0000039A
_0806CCB0: .4byte 0x0000037E
_0806CCB4:
	lsrs r1, r1, #0x19
	ldr r2, _0806CCC8 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0806CCCC @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
	b _0806CD1A
	.align 2, 0
_0806CCC8: .4byte 0x000002E6
_0806CCCC: .4byte 0x000002E7
_0806CCD0:
	adds r0, r5, #0
	movs r1, #0x41
	bl FUN_08060c40
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r1, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	str r1, [r0]
	str r2, [r0, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _0806CD0C
	movs r0, #8
	subs r0, r0, r2
_0806CCF4:
	ldr r2, _0806CD04 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r3, _0806CD08 @ =0x000002E7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0806CD1A
	.align 2, 0
_0806CD04: .4byte 0x000002E6
_0806CD08: .4byte 0x000002E7
_0806CD0C:
	ldr r1, _0806CD90 @ =0x000002E6
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0806CD94 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
_0806CD1A:
	adds r0, r5, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r5, #0
	adds r0, #0xc2
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xd0
	ldr r0, _0806CD98 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r5, r3
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0806CD90 @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806CD9C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0806CDA4
	.align 2, 0
_0806CD90: .4byte 0x000002E6
_0806CD94: .4byte 0x000002E7
_0806CD98: .4byte 0x03003584
_0806CD9C:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806CDA4:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806CDC8
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0806CDD0
_0806CDC8:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806CDD0:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806CE08 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806CE40
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806CE0C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806CE00
	ldrb r0, [r4, #5]
_0806CE00:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806CE1C
	.align 2, 0
_0806CE08: .4byte 0x0000FFFF
_0806CE0C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806CE1C
	strh r1, [r4, #8]
_0806CE1C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _0806CE40
	movs r0, #1
	strb r0, [r4, #7]
_0806CE40:
	ldr r3, _0806CE9C @ =0x0000095E
	adds r1, r5, r3
	ldr r0, _0806CEA0 @ =0x0000026D
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _0806CEA4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806CE64
	movs r0, #0x20
	strh r0, [r1]
_0806CE64:
	ldr r0, _0806CEA8 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _0806CE94
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806CEAC @ =0x00000381
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806CE94:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806CE9C: .4byte 0x0000095E
_0806CEA0: .4byte 0x0000026D
_0806CEA4: .4byte 0x0000FFFF
_0806CEA8: .4byte 0x0000037E
_0806CEAC: .4byte 0x00000381
