	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _0806E690
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_0806E690:
	ldr r2, _0806E710 @ =0x00000387
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0806E6B6
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _0806E6B6
	subs r2, #0x9f
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_080609dc
_0806E6B6:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r5, #0xd5
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r1, [r0]
	ldr r2, _0806E710 @ =0x00000387
	adds r0, r7, r2
	ldrb r2, [r0]
	subs r3, #0x56
	adds r0, r7, r3
	ldrb r3, [r0]
	subs r5, #0x6d
	adds r0, r7, r5
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E714
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E71C
	.align 2, 0
_0806E710: .4byte 0x00000387
_0806E714:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E71C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806E740
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E748
_0806E740:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E748:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E780 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0806E7B8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E784
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E778
	ldrb r0, [r4, #5]
_0806E778:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E794
	.align 2, 0
_0806E780: .4byte 0x0000FFFF
_0806E784:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0806E794
	strh r1, [r4, #8]
_0806E794:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _0806E7B8
	movs r0, #1
	strb r0, [r4, #7]
_0806E7B8:
	ldr r1, _0806E7D8 @ =0x000003FF
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0806E7D0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806E7D0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E7D8: .4byte 0x000003FF
