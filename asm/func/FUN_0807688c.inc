	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, _080768AC @ =0x0000037D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _080768A2
	b _08076F16
_080768A2:
	lsls r0, r0, #2
	ldr r1, _080768B0 @ =_080768B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080768AC: .4byte 0x0000037D
_080768B0: .4byte _080768B4
_080768B4: @ jump table
	.4byte _080768CC @ case 0
	.4byte _08076A0C @ case 1
	.4byte _08076A74 @ case 2
	.4byte _08076ACC @ case 3
	.4byte _08076C4C @ case 4
	.4byte _08076DE0 @ case 5
_080768CC:
	ldr r2, _0807693C @ =0x0000037E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080768E6
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
_080768E6:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076940 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
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
	beq _08076944
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0807694C
	.align 2, 0
_0807693C: .4byte 0x0000037E
_08076940: .4byte 0x000002E6
_08076944:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0807694C:
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
	beq _08076970
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08076978
_08076970:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076978:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080769B0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080769E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080769B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080769A8
	ldrb r0, [r4, #5]
_080769A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080769C4
	.align 2, 0
_080769B0: .4byte 0x0000FFFF
_080769B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080769C4
	strh r1, [r4, #8]
_080769C4:
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
	bne _080769E8
	movs r0, #1
	strb r0, [r4, #7]
_080769E8:
	ldr r3, _08076A08 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _080769FC
	b _08076F16
_080769FC:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076A08: .4byte 0x0000037E
_08076A0C:
	adds r2, r6, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08076A6C @ =0x0000037E
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xf0
	strb r1, [r0]
	ldrh r0, [r4]
	cmp r0, #8
	bls _08076A50
	lsls r0, r0, #3
	adds r1, r6, #0
	adds r1, #0xf1
	strb r0, [r1]
	ldrh r0, [r4]
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _08076A70 @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_08076A50:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08076A60
	b _08076F16
_08076A60:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076A6C: .4byte 0x0000037E
_08076A70: .4byte 0x000003F6
_08076A74:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r3, _08076AC4 @ =0x0000037E
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	adds r3, #0x78
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08076A9E
	b _08076F16
_08076A9E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08060c40
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08076AC8 @ =FUN_080726e0
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
	b _08076F16
	.align 2, 0
_08076AC4: .4byte 0x0000037E
_08076AC8: .4byte FUN_080726e0
_08076ACC:
	ldr r1, _08076B40 @ =0x0000037E
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08076AE6
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080609dc
_08076AE6:
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076B44 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _08076B48
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _08076B56
	.align 2, 0
_08076B40: .4byte 0x0000037E
_08076B44: .4byte 0x000002E6
_08076B48:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_08076B56:
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
	beq _08076B78
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08076B80
_08076B78:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076B80:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08076BB8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076BF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076BBC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076BB0
	ldrb r0, [r4, #5]
_08076BB0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08076BCC
	.align 2, 0
_08076BB8: .4byte 0x0000FFFF
_08076BBC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08076BCC
	strh r1, [r4, #8]
_08076BCC:
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
	bne _08076BF0
	movs r0, #1
	strb r0, [r4, #7]
_08076BF0:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	adds r1, r6, #0
	adds r1, #0xf0
	movs r0, #4
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x78
	strb r0, [r1]
	ldr r0, _08076C44 @ =0x0000037E
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xa0
	ldr r3, _08076C48 @ =0x000003F6
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08076C36
	b _08076F16
_08076C36:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076C44: .4byte 0x0000037E
_08076C48: .4byte 0x000003F6
_08076C4C:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _08076CA8 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r7
	cmp r1, r0
	beq _08076CAC
	mov r3, r8
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _08076CBA
	.align 2, 0
_08076CA8: .4byte 0x000002E6
_08076CAC:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
_08076CBA:
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
	beq _08076CDC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _08076CE4
_08076CDC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076CE4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08076D1C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08076D54
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076D20
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08076D14
	ldrb r0, [r4, #5]
_08076D14:
	subs r0, #1
	strh r0, [r4, #8]
	b _08076D30
	.align 2, 0
_08076D1C: .4byte 0x0000FFFF
_08076D20:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08076D30
	strh r1, [r4, #8]
_08076D30:
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
	bne _08076D54
	movs r0, #1
	strb r0, [r4, #7]
_08076D54:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldr r0, _08076D98 @ =0x0000037E
	adds r3, r6, r0
	ldrb r1, [r3]
	movs r2, #0xf
	subs r1, r2, r1
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0xf0
	strb r0, [r1]
	ldrh r0, [r3]
	cmp r0, #7
	bhi _08076DA0
	subs r0, r2, r0
	lsls r0, r0, #3
	adds r2, r6, #0
	adds r2, #0xf1
	strb r0, [r2]
	ldrh r1, [r3]
	movs r0, #8
	subs r0, r0, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _08076D9C @ =0x000003F6
	adds r0, r6, r2
	strh r1, [r0]
	b _08076DB8
	.align 2, 0
_08076D98: .4byte 0x0000037E
_08076D9C: .4byte 0x000003F6
_08076DA0:
	adds r1, r6, #0
	adds r1, #0xf1
	movs r0, #0x40
	strb r0, [r1]
	ldr r3, _08076DD8 @ =0x000003F6
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #4
	bl FUN_08060c40
_08076DB8:
	ldr r0, _08076DDC @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08076DCC
	b _08076F16
_08076DCC:
	adds r0, r6, #0
	movs r1, #7
	movs r2, #5
	bl FUN_08060b84
	b _08076F16
	.align 2, 0
_08076DD8: .4byte 0x000003F6
_08076DDC: .4byte 0x0000037E
_08076DE0:
	adds r4, r6, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r5, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r3, _08076E40 @ =0x000002E6
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r2, #0x69
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08076E44
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _08076E4C
	.align 2, 0
_08076E40: .4byte 0x000002E6
_08076E44:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08076E4C:
	str r0, [r4]
	ldrb r0, [r5, #4]
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
	beq _08076E70
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _08076E78
_08076E70:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08076E78:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r3, _08076EB0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _08076EE8
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08076EB4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _08076EA8
	ldrb r0, [r5, #5]
_08076EA8:
	subs r0, #1
	strh r0, [r5, #8]
	b _08076EC4
	.align 2, 0
_08076EB0: .4byte 0x0000FFFF
_08076EB4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _08076EC4
	strh r1, [r5, #8]
_08076EC4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08076EE8
	movs r0, #1
	strb r0, [r5, #7]
_08076EE8:
	ldr r3, _08076F24 @ =0x0000037E
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08076F16
	adds r0, r6, #0
	bl FUN_080609dc
	adds r0, r6, #0
	bl FUN_08072620
	movs r0, #0x93
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _08076F28 @ =FUN_08075df8
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080726b4
_08076F16:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076F24: .4byte 0x0000037E
_08076F28: .4byte FUN_08075df8
