	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816E3DC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816E3E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816E3E2
	.align 2, 0
_0816E3DC: .4byte 0x0000046C
_0816E3E0:
	movs r0, #0
_0816E3E2:
	movs r3, #8
	adds r3, r3, r5
	mov r8, r3
	cmp r0, #0
	bne _0816E3EE
	b _0816E588
_0816E3EE:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0816E468 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0816E46C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
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
	ldr r4, _0816E470 @ =0x00000834
	adds r0, r7, r4
	strb r1, [r0]
	ldr r0, _0816E474 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816E478 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E47C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816E480 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _0816E484 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov r8, r2
	mov ip, r3
	cmp r0, #0
	blt _0816E488
	asrs r1, r0, #0xc
	b _0816E48E
	.align 2, 0
_0816E468: .4byte 0x0000046D
_0816E46C: .4byte 0x0000046B
_0816E470: .4byte 0x00000834
_0816E474: .4byte 0x03002BE0
_0816E478: .4byte 0x030046B8
_0816E47C: .4byte 0x000003FF
_0816E480: .4byte 0x0203B400
_0816E484: .4byte gSineTable
_0816E488:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E48E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E4AA
	asrs r0, r0, #0xc
	b _0816E4B0
_0816E4AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E4B0:
	strh r0, [r4, #4]
	mov r0, sp
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _0816E540 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r2, sp
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E544 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816E548 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r0, _0816E54C @ =0x00000888
	adds r6, r7, r0
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov r8, r4
	cmp r0, #0
	blt _0816E550
	asrs r1, r0, #0xc
	b _0816E556
	.align 2, 0
_0816E540: .4byte 0xFFFF0000
_0816E544: .4byte 0x000003FF
_0816E548: .4byte 0x0203B400
_0816E54C: .4byte 0x00000888
_0816E550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E556:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E570
	asrs r0, r0, #0xc
	b _0816E576
_0816E570:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E576:
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r1, r3, #0
	bl Ghost_BuildCurvePoints
	ldr r3, _0816E628 @ =0x000007EA
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
_0816E588:
	ldr r4, _0816E62C @ =0x00000834
	adds r6, r7, r4
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	adds r1, r1, r7
	ldr r0, _0816E630 @ =0x000007EC
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	mov r3, r8
	ldrh r2, [r3, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl Ghost_SpawnAfterimage
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816E68C
	ldrb r1, [r6]
	lsls r1, r1, #3
	adds r1, r7, r1
	ldr r4, _0816E630 @ =0x000007EC
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #5]
	subs r4, #6
	adds r0, r7, r4
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _0816E634 @ =gSineTable
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
	blt _0816E638
	asrs r1, r0, #0xc
	b _0816E63E
	.align 2, 0
_0816E628: .4byte 0x000007EA
_0816E62C: .4byte 0x00000834
_0816E630: .4byte 0x000007EC
_0816E634: .4byte gSineTable
_0816E638:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E63E:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _0816E658 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0816E65C
	asrs r0, r0, #0xc
	b _0816E662
	.align 2, 0
_0816E658: .4byte gSineTable
_0816E65C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E662:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r0, _0816E688 @ =0x00000888
	adds r2, r7, r0
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _0816E7B8
	.align 2, 0
_0816E688: .4byte 0x00000888
_0816E68C:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0816E69C
	b _0816E7B8
_0816E69C:
	ldr r1, _0816E728 @ =0x00000888
	adds r3, r7, r1
	ldr r4, _0816E72C @ =0x0000082C
	adds r2, r7, r4
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov r4, r8
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, _0816E730 @ =0x0000088A
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _0816E734 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _0816E738 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816E73C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0816E740 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _0816E744 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov ip, r2
	cmp r0, #0
	blt _0816E748
	asrs r1, r0, #0xc
	b _0816E74E
	.align 2, 0
_0816E728: .4byte 0x00000888
_0816E72C: .4byte 0x0000082C
_0816E730: .4byte 0x0000088A
_0816E734: .4byte 0x03002BE0
_0816E738: .4byte 0x030046B8
_0816E73C: .4byte 0x000003FF
_0816E740: .4byte 0x0203B400
_0816E744: .4byte gSineTable
_0816E748:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816E74E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0816E76A
	asrs r0, r0, #0xc
	b _0816E770
_0816E76A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816E770:
	strh r0, [r3, #4]
	add r1, sp, #8
	mov r0, sp
	ldrh r2, [r0]
	ldrh r3, [r1]
	adds r2, r2, r3
	strh r2, [r1]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r1, #4]
	adds r0, r0, r4
	strh r0, [r1, #4]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	mov r0, sp
	strh r2, [r0]
	ldrh r0, [r1, #2]
	mov r4, r8
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r4, #4]
	subs r0, r0, r2
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl Ghost_BuildCurvePoints
	ldr r0, _0816E7B4 @ =0x000007EA
	adds r1, r7, r0
	ldrh r0, [r1]
	lsrs r0, r0, #1
	strh r0, [r1]
	b _0816E814
	.align 2, 0
_0816E7B4: .4byte 0x000007EA
_0816E7B8:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0816E7EC
	ldr r2, _0816E7E4 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _0816E80A
	ldr r3, _0816E7E8 @ =0x000007EA
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _0816E80A
	adds r0, #1
	b _0816E808
	.align 2, 0
_0816E7E4: .4byte 0x00000484
_0816E7E8: .4byte 0x000007EA
_0816E7EC:
	ldr r4, _0816E820 @ =0x00000484
	adds r0, r5, r4
	ldr r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _0816E80A
	ldr r0, _0816E824 @ =0x000007EA
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _0816E80A
	adds r0, #2
_0816E808:
	strh r0, [r1]
_0816E80A:
	ldr r2, _0816E820 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816E814:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816E820: .4byte 0x00000484
_0816E824: .4byte 0x000007EA
