	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _0806E7FE
	ldr r2, _0806E858 @ =0x0000037E
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r4, r6, #0
	adds r4, #0xc2
	cmp r0, #0
	beq _0806E7FE
	b _0806E8FA
_0806E7FE:
	adds r0, r6, #0
	movs r1, #0xe
	movs r2, #0
	bl FUN_08060b84
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
	ldr r0, _0806E85C @ =0x0000098C
	adds r5, r6, r0
	ldr r0, [r5]
	adds r1, r6, #0
	adds r1, #0x24
	movs r3, #0x99
	lsls r3, r3, #4
	adds r2, r6, r3
	ldrb r2, [r2]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r5]
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0806E860 @ =0x0000043E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0806E864
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x20
	b _0806E8F6
	.align 2, 0
_0806E858: .4byte 0x0000037E
_0806E85C: .4byte 0x0000098C
_0806E860: .4byte 0x0000043E
_0806E864:
	ldr r2, _0806E888 @ =0x0000038E
	adds r0, r6, r2
	ldrb r0, [r0]
	ldr r1, _0806E88C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	ble _0806E890
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x21
	b _0806E8F6
	.align 2, 0
_0806E888: .4byte 0x0000038E
_0806E88C: .4byte 0x030046A0
_0806E890:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0806E8AC
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x94
	lsls r0, r0, #1
	b _0806E8F6
_0806E8AC:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0806E8C4
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _0806E8C0 @ =0x00000129
	b _0806E8F6
	.align 2, 0
_0806E8C0: .4byte 0x00000129
_0806E8C4:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0806E8D8
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x95
	lsls r0, r0, #1
	b _0806E8F6
_0806E8D8:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _0806E8F0
	adds r1, r6, #0
	adds r1, #0xc2
	ldr r0, _0806E8EC @ =0x0000012B
	b _0806E8F6
	.align 2, 0
_0806E8EC: .4byte 0x0000012B
_0806E8F0:
	adds r1, r6, #0
	adds r1, #0xc2
	movs r0, #0x26
_0806E8F6:
	strh r0, [r1]
	adds r4, r1, #0
_0806E8FA:
	adds r0, r6, #0
	movs r1, #0x40
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_08060a24
	adds r2, r6, #0
	adds r2, #0xd0
	ldr r0, _0806E988 @ =0x03003584
	ldrh r1, [r4]
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2]
	subs r2, #0x28
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _0806E98C @ =0x0000037E
	adds r0, r6, r3
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #9
	bls _0806E936
	b _0806EA3A
_0806E936:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _0806E990 @ =0x00000387
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, #8
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
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
	beq _0806E994
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E99C
	.align 2, 0
_0806E988: .4byte 0x03003584
_0806E98C: .4byte 0x0000037E
_0806E990: .4byte 0x00000387
_0806E994:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E99C:
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
	beq _0806E9C0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E9C8
_0806E9C0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E9C8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0806EA00 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806EA4C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806EA04
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E9F8
	ldrb r0, [r4, #5]
_0806E9F8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806EA14
	.align 2, 0
_0806EA00: .4byte 0x0000FFFF
_0806EA04:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806EA14
	strh r1, [r4, #8]
_0806EA14:
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
	bne _0806EA4C
	movs r0, #1
	strb r0, [r4, #7]
	b _0806EA4C
_0806EA3A:
	lsrs r0, r1, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806EA4C
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
_0806EA4C:
	ldr r3, _0806EA90 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _0806EA86
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0806EA94 @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	subs r3, #0x96
	adds r1, r6, r3
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806EA86:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806EA90: .4byte 0x0000037E
_0806EA94: .4byte 0x00000381
