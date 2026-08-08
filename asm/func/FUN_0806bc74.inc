	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0806BCBC
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0
	bl FUN_08060b84
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08063220
	adds r0, r5, #0
	bl FUN_08066e84
	ldr r0, _0806BCFC @ =0x0000039A
	bl PlaySound_082406e0
	movs r0, #0x38
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_0806BCBC:
	ldr r0, _0806BD00 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _0806BCCE
	movs r0, #0xe8
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0806BCCE:
	ldrh r0, [r4]
	movs r4, #7
	adds r1, r4, #0
	ands r1, r0
	lsrs r0, r0, #2
	subs r0, r4, r0
	cmp r1, r0
	bge _0806BD24
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _0806BD0C
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _0806BD04 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0806BD08 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0806BD8A
	.align 2, 0
_0806BCFC: .4byte 0x0000039A
_0806BD00: .4byte 0x0000037E
_0806BD04: .4byte 0x000002E6
_0806BD08: .4byte 0x000002E7
_0806BD0C:
	ldr r1, _0806BD1C @ =0x000002E6
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0806BD20 @ =0x000002E7
	adds r0, r5, r2
	strb r1, [r0]
	b _0806BD8C
	.align 2, 0
_0806BD1C: .4byte 0x000002E6
_0806BD20: .4byte 0x000002E7
_0806BD24:
	adds r0, r5, #0
	movs r1, #0x41
	bl FUN_08060c40
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r0, _0806BD70 @ =0x00000382
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #3
	bls _0806BD7C
	ldrb r0, [r2]
	subs r0, r4, r0
	asrs r0, r0, #1
	ldr r2, _0806BD74 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _0806BD78 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	b _0806BD8A
	.align 2, 0
_0806BD70: .4byte 0x00000382
_0806BD74: .4byte 0x000002E6
_0806BD78: .4byte 0x000002E7
_0806BD7C:
	lsrs r1, r1, #0x19
	ldr r2, _0806BE1C @ =0x000002E6
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0806BE20 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #0
_0806BD8A:
	strb r0, [r1]
_0806BD8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806BE24 @ =0x0000095E
	adds r1, r5, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BDC6
	movs r0, #0x20
	strh r0, [r1]
_0806BDC6:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0]
	subs r2, #0x66
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
	beq _0806BE28
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0806BE30
	.align 2, 0
_0806BE1C: .4byte 0x000002E6
_0806BE20: .4byte 0x000002E7
_0806BE24: .4byte 0x0000095E
_0806BE28:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806BE30:
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
	beq _0806BE54
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0806BE5C
_0806BE54:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806BE5C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806BE94 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806BECC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806BE98
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806BE8C
	ldrb r0, [r4, #5]
_0806BE8C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806BEA8
	.align 2, 0
_0806BE94: .4byte 0x0000FFFF
_0806BE98:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806BEA8
	strh r1, [r4, #8]
_0806BEA8:
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
	bne _0806BECC
	movs r0, #1
	strb r0, [r4, #7]
_0806BECC:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, _0806BF10 @ =0x0000026D
	bl FUN_0822b20c
	ldr r2, _0806BF14 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _0806BF08
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #3
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806BF08:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806BF10: .4byte 0x0000026D
_0806BF14: .4byte 0x0000037E
