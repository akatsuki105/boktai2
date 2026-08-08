	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0806D5CC
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0806D5CC:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0806D620
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xfe
	ands r0, r1
	adds r0, #1
	strb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806D610
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806D608 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _0806D60C @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _0806D61E
	.align 2, 0
_0806D608: .4byte 0x000002E6
_0806D60C: .4byte 0x000002E7
_0806D610:
	lsrs r1, r1, #0x19
	ldr r2, _0806D674 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0806D678 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_0806D61E:
	strb r0, [r1]
_0806D620:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _0806D67C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D684
	.align 2, 0
_0806D674: .4byte 0x000002E6
_0806D678: .4byte 0x000002E7
_0806D67C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D684:
	str r0, [r5]
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
	beq _0806D6A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D6B0
_0806D6A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D6B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D6E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D720
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D6EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D6E0
	ldrb r0, [r4, #5]
_0806D6E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D6FC
	.align 2, 0
_0806D6E8: .4byte 0x0000FFFF
_0806D6EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D6FC
	strh r1, [r4, #8]
_0806D6FC:
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
	bne _0806D720
	movs r0, #1
	strb r0, [r4, #7]
_0806D720:
	ldr r1, _0806D748 @ =0x000003FF
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0806D73E
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806D73E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D748: .4byte 0x000003FF
