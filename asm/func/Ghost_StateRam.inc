	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816C6C8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816C6CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816C6CE
	.align 2, 0
_0816C6C8: .4byte 0x0000046C
_0816C6CC:
	movs r0, #0
_0816C6CE:
	ldr r3, _0816C728 @ =0x000007DC
	adds r3, r3, r7
	mov sb, r3
	adds r4, r5, #0
	adds r4, #8
	add r6, sp, #8
	mov r8, r6
	cmp r0, #0
	bne _0816C6E2
	b _0816C902
_0816C6E2:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0816C72C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0816C730 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _0816C734 @ =0x00000553
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	ldr r4, _0816C738 @ =0x00000834
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #4
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816C73C
	movs r0, #1
	b _0816C73E
	.align 2, 0
_0816C728: .4byte 0x000007DC
_0816C72C: .4byte 0x0000046D
_0816C730: .4byte 0x0000046B
_0816C734: .4byte 0x00000553
_0816C738: .4byte 0x00000834
_0816C73C:
	movs r0, #0
_0816C73E:
	cmp r0, #0
	beq _0816C7F4
	ldr r3, _0816C794 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0816C798 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _0816C79C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x80
	adds r4, r2, r0
	movs r1, #0xff
	mov r6, sp
	ands r4, r1
	movs r0, #0xb6
	lsls r0, r0, #2
	mov r8, r0
	ldr r2, _0816C7A0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov ip, r3
	mov sl, r2
	cmp r0, #0
	blt _0816C7A4
	asrs r1, r0, #0xc
	b _0816C7AA
	.align 2, 0
_0816C794: .4byte 0x030046B8
_0816C798: .4byte 0x000003FF
_0816C79C: .4byte 0x0203B400
_0816C7A0: .4byte gSineTable
_0816C7A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C7AA:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r4, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0816C7C6
	asrs r0, r0, #0xc
	b _0816C7CC
_0816C7C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C7CC:
	strh r0, [r6, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r5, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r1, r5, #0
	adds r1, #8
	ldrh r4, [r5, #0xa]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r6, [r2, #4]
	adds r0, r0, r6
	strh r0, [r2, #4]
	adds r4, r1, #0
	b _0816C80C
_0816C7F4:
	ldr r0, _0816C848 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _0816C84C @ =0x030046B8
	mov ip, r0
	ldr r1, _0816C850 @ =gSineTable
	mov sl, r1
	adds r4, r5, #0
	adds r4, #8
_0816C80C:
	add r2, sp, #8
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r6, #4
	ldrsh r0, [r2, r6]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _0816C854
	asrs r1, r0, #2
	b _0816C85A
	.align 2, 0
_0816C848: .4byte 0x03002BE0
_0816C84C: .4byte 0x030046B8
_0816C850: .4byte gSineTable
_0816C854:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0816C85A:
	movs r6, #0xfc
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0816C8A8 @ =0x000003FF
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0816C8AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r0, _0816C8B0 @ =0x00000888
	adds r3, r7, r0
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0816C8B4
	asrs r1, r0, #0xc
	b _0816C8BA
	.align 2, 0
_0816C8A8: .4byte 0x000003FF
_0816C8AC: .4byte 0x0203B400
_0816C8B0: .4byte 0x00000888
_0816C8B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C8BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0816C8D4
	asrs r0, r0, #0xc
	b _0816C8DA
_0816C8D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C8DA:
	strh r0, [r3, #4]
	adds r0, r5, #0
	mov r1, sp
	bl Ghost_BuildCurvePoints
	ldr r3, _0816C93C @ =0x000007EA
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
	adds r0, #0xff
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0816C940 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
_0816C902:
	ldr r1, _0816C944 @ =0x00000834
	adds r0, r7, r1
	ldrb r1, [r0]
	lsls r1, r1, #3
	adds r1, r1, r7
	ldr r2, _0816C948 @ =0x000007EC
	adds r1, r1, r2
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	add r2, sp, #8
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	mov r3, r8
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #4
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0816C94C
	movs r0, #1
	b _0816C94E
	.align 2, 0
_0816C93C: .4byte 0x000007EA
_0816C940: .4byte 0x00000482
_0816C944: .4byte 0x00000834
_0816C948: .4byte 0x000007EC
_0816C94C:
	movs r0, #0
_0816C94E:
	cmp r0, #0
	bne _0816C962
	movs r6, #0x94
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0816C962:
	adds r0, r5, #0
	bl Ghost_SpawnAfterimage
	add r0, sp, #8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816CA40
	ldr r6, _0816C9DC @ =0x00000834
	adds r0, r7, r6
	ldrb r1, [r0]
	lsls r1, r1, #3
	adds r1, r7, r1
	ldr r2, _0816C9E0 @ =0x000007EC
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r4, #8
	ldrsh r2, [r5, r4]
	subs r0, r0, r2
	subs r6, #0x44
	adds r1, r1, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r4, _0816C9E4 @ =0x000007EA
	adds r0, r7, r4
	mov r6, r8
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _0816C9E8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816C9EC
	asrs r1, r0, #0xc
	b _0816C9F2
	.align 2, 0
_0816C9DC: .4byte 0x00000834
_0816C9E0: .4byte 0x000007EC
_0816C9E4: .4byte 0x000007EA
_0816C9E8: .4byte gSineTable
_0816C9EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C9F2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _0816CA0C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816CA10
	asrs r0, r0, #0xc
	b _0816CA16
	.align 2, 0
_0816CA0C: .4byte gSineTable
_0816CA10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816CA16:
	strh r0, [r6, #4]
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r5, #0x10]
	adds r0, r0, r4
	strh r0, [r5, #0x10]
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r6, [r5, #0x14]
	adds r0, r0, r6
	strh r0, [r5, #0x14]
	ldr r0, _0816CA3C @ =0x00000888
	adds r2, r7, r0
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _0816CB70
	.align 2, 0
_0816CA3C: .4byte 0x00000888
_0816CA40:
	ldr r2, _0816CA94 @ =0x00000834
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0816CA54
	b _0816CB70
_0816CA54:
	ldr r3, _0816CA98 @ =0x0000082C
	adds r0, r7, r3
	ldrh r0, [r0]
	strh r0, [r5, #8]
	movs r4, #0x83
	lsls r4, r4, #4
	adds r0, r7, r4
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r0, _0816CA9C @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r3, #4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	mov r1, sb
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0816CAA0
	movs r0, #1
	b _0816CAA2
	.align 2, 0
_0816CA94: .4byte 0x00000834
_0816CA98: .4byte 0x0000082C
_0816CA9C: .4byte 0xFFFFFEFF
_0816CAA0:
	movs r0, #0
_0816CAA2:
	adds r4, r0, #0
	cmp r4, #0
	beq _0816CB14
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0816CB00 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0816CB04 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r6, _0816CB08 @ =0x00000484
	adds r0, r5, r6
	str r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _0816CB0C @ =Enemy_ClearStateBegun
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0816CB10 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	subs r1, #5
	mov r4, sb
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	b _0816CBC2
	.align 2, 0
_0816CB00: .4byte 0x00000469
_0816CB04: .4byte 0x0000046A
_0816CB08: .4byte 0x00000484
_0816CB0C: .4byte Enemy_ClearStateBegun
_0816CB10: .4byte 0x0000046B
_0816CB14:
	movs r2, #2
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _0816CB60 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _0816CB64 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r3, _0816CB68 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816CB6C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0816CBC2
	.align 2, 0
_0816CB60: .4byte 0x00000469
_0816CB64: .4byte 0x00000484
_0816CB68: .4byte Enemy_ClearStateBegun
_0816CB6C: .4byte 0x0000046B
_0816CB70:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816CBA4
	ldr r4, _0816CB9C @ =0x00000484
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _0816CBC2
	ldr r6, _0816CBA0 @ =0x000007EA
	adds r1, r7, r6
	ldrh r0, [r1]
	cmp r0, #0x13
	bhi _0816CBC2
	adds r0, #1
	b _0816CBC0
	.align 2, 0
_0816CB9C: .4byte 0x00000484
_0816CBA0: .4byte 0x000007EA
_0816CBA4:
	ldr r1, _0816CBD4 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0816CBC2
	ldr r2, _0816CBD8 @ =0x000007EA
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0x13
	bhi _0816CBC2
	adds r0, #2
_0816CBC0:
	strh r0, [r1]
_0816CBC2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816CBD4: .4byte 0x00000484
_0816CBD8: .4byte 0x000007EA
