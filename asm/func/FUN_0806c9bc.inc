	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0806CA28
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r6, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806C9FC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _0806C9F8 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0806CA0C
	.align 2, 0
_0806C9F8: .4byte 0x000002E6
_0806C9FC:
	lsrs r1, r1, #0x19
	ldr r2, _0806CA7C @ =0x000002E6
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _0806CA80 @ =0x000002E7
	adds r0, r6, r5
	strb r2, [r0]
_0806CA0C:
	ldr r0, _0806CA84 @ =0x000003D6
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0806CA1E
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_0806CA1E:
	adds r0, r6, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
_0806CA28:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r5, _0806CA7C @ =0x000002E6
	adds r0, r6, r5
	ldrb r3, [r0]
	subs r2, #0x65
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
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
	beq _0806CA88
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806CA90
	.align 2, 0
_0806CA7C: .4byte 0x000002E6
_0806CA80: .4byte 0x000002E7
_0806CA84: .4byte 0x000003D6
_0806CA88:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806CA90:
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
	beq _0806CAB4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806CABC
_0806CAB4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806CABC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _0806CAF4 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806CB2C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806CAF8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806CAEC
	ldrb r0, [r4, #5]
_0806CAEC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806CB08
	.align 2, 0
_0806CAF4: .4byte 0x0000FFFF
_0806CAF8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806CB08
	strh r1, [r4, #8]
_0806CB08:
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
	bne _0806CB2C
	movs r0, #1
	strb r0, [r4, #7]
_0806CB2C:
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r3, r6, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _0806CBAC
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0806CB68 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806CB6C
	asrs r0, r0, #0xc
	b _0806CB72
	.align 2, 0
_0806CB68: .4byte 0x085B0A08
_0806CB6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806CB72:
	rsbs r0, r0, #0
	strh r0, [r6, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806CB90
	asrs r0, r0, #0xc
	b _0806CB96
_0806CB90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806CB96:
	rsbs r0, r0, #0
	strh r0, [r6, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _0806CBDE
_0806CBAC:
	ldr r1, _0806CBCC @ =0x000004C5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806CBD4
	ldr r2, _0806CBD0 @ =0x000004C7
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CBD4
	adds r0, r6, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	b _0806CBDE
	.align 2, 0
_0806CBCC: .4byte 0x000004C5
_0806CBD0: .4byte 0x000004C7
_0806CBD4:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806CBDE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
