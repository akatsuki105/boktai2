	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0806DA88
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _0806DA5C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _0806DA54 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _0806DA58 @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0806DA6C
	.align 2, 0
_0806DA54: .4byte 0x000002E6
_0806DA58: .4byte 0x000002E7
_0806DA5C:
	lsrs r1, r1, #0x19
	ldr r2, _0806DADC @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0806DAE0 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_0806DA6C:
	ldr r6, _0806DAE4 @ =0x000003D6
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0
	beq _0806DA7E
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_0806DA7E:
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08060b84
_0806DA88:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _0806DADC @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	ldr r6, _0806DAE0 @ =0x000002E7
	adds r0, r5, r6
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
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
	beq _0806DAE8
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0806DAF0
	.align 2, 0
_0806DADC: .4byte 0x000002E6
_0806DAE0: .4byte 0x000002E7
_0806DAE4: .4byte 0x000003D6
_0806DAE8:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806DAF0:
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
	beq _0806DB14
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0806DB1C
_0806DB14:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806DB1C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806DB54 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0806DB8C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806DB58
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806DB4C
	ldrb r0, [r4, #5]
_0806DB4C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806DB68
	.align 2, 0
_0806DB54: .4byte 0x0000FFFF
_0806DB58:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _0806DB68
	strh r1, [r4, #8]
_0806DB68:
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
	bne _0806DB8C
	movs r0, #1
	strb r0, [r4, #7]
_0806DB8C:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _0806DB9A
	b _0806DD22
_0806DB9A:
	ldr r1, _0806DBC8 @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DC18
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806DBCC
	asrs r0, r3, #3
	b _0806DBD2
	.align 2, 0
_0806DBC8: .4byte 0x00000395
_0806DBCC:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DBD2:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806DBDC
	asrs r0, r1, #3
	b _0806DBE2
_0806DBDC:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DBE2:
	strh r0, [r5, #0x38]
	ldr r3, _0806DC10 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bls _0806DBF0
	b _0806DD0A
_0806DBF0:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806DC06
	ldr r0, _0806DC14 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_080acd98
_0806DC06:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0806DD0A
	.align 2, 0
_0806DC10: .4byte 0x0000037E
_0806DC14: .4byte 0x00000191
_0806DC18:
	ldr r6, _0806DC48 @ =0x00000397
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DCA8
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _0806DC4C
	asrs r0, r3, #3
	b _0806DC52
	.align 2, 0
_0806DC48: .4byte 0x00000397
_0806DC4C:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DC52:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _0806DC5C
	asrs r0, r1, #3
	b _0806DC62
_0806DC5C:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0806DC62:
	strh r0, [r5, #0x38]
	ldr r3, _0806DCA0 @ =0x0000037E
	adds r6, r5, r3
	ldrh r0, [r6]
	cmp r0, #5
	bhi _0806DD0A
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	bne _0806DC96
	ldr r0, _0806DCA4 @ =0x00000191
	bl PlaySound_082406e0
	adds r0, r5, #0
	adds r0, #0x2c
	str r4, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ddcc8
_0806DC96:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	b _0806DD0A
	.align 2, 0
_0806DCA0: .4byte 0x0000037E
_0806DCA4: .4byte 0x00000191
_0806DCA8:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0806DCD8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806DCDC
	asrs r0, r0, #0xc
	b _0806DCE2
	.align 2, 0
_0806DCD8: .4byte 0x085B0A08
_0806DCDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806DCE2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0806DD00
	asrs r0, r0, #0xc
	b _0806DD06
_0806DD00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0806DD06:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_0806DD0A:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _0806DD74
_0806DD22:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _0806DD54 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0806DD58 @ =0x00000397
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0806DD5C @ =0x000004C5
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0806DD64
	ldr r1, _0806DD60 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806DD64
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08060b84
	b _0806DD74
	.align 2, 0
_0806DD54: .4byte 0x00000395
_0806DD58: .4byte 0x00000397
_0806DD5C: .4byte 0x000004C5
_0806DD60: .4byte 0x000004C7
_0806DD64:
	adds r0, r5, #0
	bl FUN_080609dc
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806DD74:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
