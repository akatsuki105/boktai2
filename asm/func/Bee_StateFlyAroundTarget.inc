	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081691B0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081691B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081691B6
	.align 2, 0
_081691B0: .4byte 0x0000046C
_081691B4:
	movs r0, #0
_081691B6:
	add r7, sp, #4
	movs r3, #8
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	bne _081691C4
	b _0816931E
_081691C4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0816927C @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _08169280 @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r2, [r0]
	ldr r5, _08169284 @ =0x000006AC
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _08169288 @ =0x000006C4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r2, #2]
	mov r3, r8
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r5, #0
	ldrsh r0, [r7, r5]
	movs r2, #4
	ldrsh r1, [r7, r2]
	bl ArcTan2_8
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r3, r6, r5
	strb r0, [r3]
	ldr r2, _0816928C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08169290 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08169294 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldrb r3, [r3]
	adds r3, r0, r3
	movs r2, #0xff
	ldr r5, _08169298 @ =0x000006C2
	adds r0, r4, r5
	add r5, sp, #0xc
	ands r3, r2
	ldrh r0, [r0]
	mov ip, r0
	ldr r1, _0816929C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _081692A0
	asrs r1, r0, #0xc
	b _081692A6
	.align 2, 0
_0816927C: .4byte 0x0000046D
_08169280: .4byte 0x0000046B
_08169284: .4byte 0x000006AC
_08169288: .4byte 0x000006C4
_0816928C: .4byte 0x030046B8
_08169290: .4byte 0x000003FF
_08169294: .4byte 0x0203B400
_08169298: .4byte 0x000006C2
_0816929C: .4byte gSineTable
_081692A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081692A6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081692C4 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081692C8
	asrs r0, r0, #0xc
	b _081692CE
	.align 2, 0
_081692C4: .4byte gSineTable
_081692C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081692CE:
	movs r3, #0
	mov sb, r3
	strh r0, [r5, #4]
	ldr r5, _081693CC @ =0x000006BE
	adds r1, r4, r5
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	add r1, sp, #0xc
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	mov r5, r8
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	str r2, [sp, #0x1c]
	bl Bee_BuildCurvePoints
	adds r0, r6, #0
	mov r1, r8
	ldr r2, [sp, #0x1c]
	bl FUN_0816869c
	ldr r2, _081693D0 @ =0x00000704
	adds r1, r4, r2
	mov r3, sb
	str r3, [sp]
	mov r0, sp
	ldr r2, _081693D4 @ =0x05000002
	bl CpuSet
_0816931E:
	ldr r5, _081693D8 @ =0x000006AC
	adds r0, r4, r5
	ldrb r1, [r0]
	add r5, sp, #0x14
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r0, _081693DC @ =0x00000664
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r3, [r6, #8]
	subs r0, r0, r3
	strh r0, [r5]
	ldrh r2, [r1, #2]
	mov ip, r2
	mov r0, r8
	ldrh r0, [r0, #2]
	mov sb, r0
	mov r2, ip
	mov r0, sb
	subs r2, r2, r0
	strh r2, [r5, #2]
	ldrh r0, [r1, #4]
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	ldr r1, _081693E0 @ =0x000006C4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	subs r0, r0, r3
	add r3, sp, #4
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov ip, r0
	mov r1, r8
	ldrh r1, [r1, #2]
	mov sb, r1
	mov r0, ip
	mov r1, sb
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #4
	ldrsh r1, [r7, r2]
	bl ArcTan2_8
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r6, r3
	strb r0, [r1]
	strb r0, [r6, #5]
	ldr r0, _081693CC @ =0x000006BE
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0816946C
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816946C
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _081693E4
	asrs r1, r0, #5
	b _081693EA
	.align 2, 0
_081693CC: .4byte 0x000006BE
_081693D0: .4byte 0x00000704
_081693D4: .4byte 0x05000002
_081693D8: .4byte 0x000006AC
_081693DC: .4byte 0x00000664
_081693E0: .4byte 0x000006C4
_081693E4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_081693EA:
	adds r5, r1, #0
	cmp r5, #1
	bge _081693F2
	movs r5, #1
_081693F2:
	ldr r2, _08169458 @ =0x000006AC
	adds r7, r4, r2
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r3, _0816945C @ =0x00000664
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x10]
	adds r1, r1, r0
	strh r1, [r6, #0x10]
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r4, r0
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xc
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x14]
	adds r1, r1, r0
	strh r1, [r6, #0x14]
	ldr r3, _08169460 @ =0x00000704
	adds r2, r4, r3
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r5, _08169464 @ =0x000006BE
	adds r2, r4, r5
	ldr r1, _08169468 @ =0x00000484
	adds r0, r6, r1
	ldr r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	b _081695DE
	.align 2, 0
_08169458: .4byte 0x000006AC
_0816945C: .4byte 0x00000664
_08169460: .4byte 0x00000704
_08169464: .4byte 0x000006BE
_08169468: .4byte 0x00000484
_0816946C:
	ldr r2, _08169510 @ =0x000006AC
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _08169480
	b _081695BC
_08169480:
	ldr r3, _08169514 @ =0x000006A4
	adds r0, r4, r3
	ldrh r1, [r0]
	strh r1, [r6, #8]
	movs r5, #0xd5
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	adds r2, #0x18
	adds r0, r4, r2
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	subs r0, r0, r1
	add r3, sp, #4
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov r5, r8
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #4
	ldrsh r1, [r7, r2]
	bl ArcTan2_8
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r3, r6, r5
	strb r0, [r3]
	ldr r2, _08169518 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816951C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08169520 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldrb r3, [r3]
	adds r3, r0, r3
	movs r2, #0xff
	ldr r5, _08169524 @ =0x000006C2
	adds r0, r4, r5
	add r7, sp, #0xc
	ands r3, r2
	ldrh r5, [r0]
	ldr r1, _08169528 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r2, r7, #0
	cmp r0, #0
	blt _0816952C
	asrs r1, r0, #0xc
	b _08169532
	.align 2, 0
_08169510: .4byte 0x000006AC
_08169514: .4byte 0x000006A4
_08169518: .4byte 0x030046B8
_0816951C: .4byte 0x000003FF
_08169520: .4byte 0x0203B400
_08169524: .4byte 0x000006C2
_08169528: .4byte gSineTable
_0816952C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08169532:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _0816954C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08169550
	asrs r0, r0, #0xc
	b _08169556
	.align 2, 0
_0816954C: .4byte gSineTable
_08169550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08169556:
	movs r5, #0
	mov sb, r5
	movs r5, #0
	strh r0, [r7, #4]
	add r1, sp, #0xc
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	mov r3, r8
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	str r2, [sp, #0x1c]
	bl Bee_BuildCurvePoints
	adds r0, r6, #0
	mov r1, r8
	ldr r2, [sp, #0x1c]
	bl FUN_0816869c
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r3, _081695B0 @ =0x000006BE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, _081695B4 @ =0x000006AC
	adds r0, r4, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _081695B8 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	b _081695EC
	.align 2, 0
_081695B0: .4byte 0x000006BE
_081695B4: .4byte 0x000006AC
_081695B8: .4byte 0x00000484
_081695BC:
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r5, _081695FC @ =0x00000664
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r6, #8]
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r4, r0
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
_081695DE:
	ldr r2, _08169600 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0x13
	bgt _081695EC
	adds r0, #1
	str r0, [r1]
_081695EC:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081695FC: .4byte 0x00000664
_08169600: .4byte 0x00000484
