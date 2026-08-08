	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DFA0
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DFA0:
	ldr r1, [r6, #0x20]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6, #0x20]
	ldr r3, _0806E010 @ =0x00000387
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #3
	bne _0806DFBC
	movs r0, #0x80
	lsls r0, r0, #0xa
	orrs r1, r0
	str r1, [r6, #0x20]
_0806DFBC:
	movs r5, #0xcf
	lsls r5, r5, #2
	adds r4, r6, r5
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	ldr r3, _0806E014 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r5, #0x55
	adds r0, r6, r5
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
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
	beq _0806E018
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806E020
	.align 2, 0
_0806E010: .4byte 0x00000387
_0806E014: .4byte 0x000002E6
_0806E018:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806E020:
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
	beq _0806E044
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806E04C
_0806E044:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806E04C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806E084 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0806E0BC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806E088
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806E07C
	ldrb r0, [r4, #5]
_0806E07C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806E098
	.align 2, 0
_0806E084: .4byte 0x0000FFFF
_0806E088:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0806E098
	strh r1, [r4, #8]
_0806E098:
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
	bne _0806E0BC
	movs r0, #1
	strb r0, [r4, #7]
_0806E0BC:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r3, r6, r0
	ldr r2, _0806E144 @ =0x0000036A
	adds r1, r6, r2
	ldrh r0, [r3]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0806E13A
	movs r4, #0xe3
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r1, _0806E148 @ =0x085ABC82
	ldr r5, _0806E14C @ =0x00000387
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	movs r7, #0
	strh r0, [r2]
	ldr r4, _0806E150 @ =0x0000FFFF
	adds r1, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0806E100
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r2]
_0806E100:
	ldr r0, _0806E154 @ =0x0000037E
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ands r0, r1
	cmp r0, #0x45
	bls _0806E13A
	movs r2, #0x99
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #2
	strb r0, [r1]
	ldr r3, _0806E158 @ =0x0000098C
	adds r4, r6, r3
	ldr r0, [r4]
	adds r1, r6, #0
	adds r1, #0x24
	str r7, [sp]
	str r7, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r7, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	strh r7, [r5]
_0806E13A:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806E144: .4byte 0x0000036A
_0806E148: .4byte 0x085ABC82
_0806E14C: .4byte 0x00000387
_0806E150: .4byte 0x0000FFFF
_0806E154: .4byte 0x0000037E
_0806E158: .4byte 0x0000098C
