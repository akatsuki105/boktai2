	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08168868 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816886C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816886E
	.align 2, 0
_08168868: .4byte 0x0000046C
_0816886C:
	movs r0, #0
_0816886E:
	movs r3, #8
	adds r3, r3, r6
	mov sb, r3
	cmp r0, #0
	bne _0816887A
	b _08168A44
_0816887A:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _081688C8 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _081688CC @ =0x0000046B
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
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
	ldr r0, _081688D0 @ =0x000006AC
	add r0, r8
	strb r1, [r0]
	movs r2, #8
	movs r1, #0xcb
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081688D4
	movs r0, #1
	b _081688D6
	.align 2, 0
_081688C8: .4byte 0x0000046D
_081688CC: .4byte 0x0000046B
_081688D0: .4byte 0x000006AC
_081688D4:
	movs r0, #0
_081688D6:
	cmp r0, #0
	beq _0816896E
	ldr r2, _08168924 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08168928 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0816892C @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrb r2, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x80
	adds r3, r2, r0
	movs r1, #0xff
	add r4, sp, #4
	ands r3, r1
	movs r5, #0xa0
	lsls r5, r5, #1
	ldr r2, _08168930 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov sl, r4
	cmp r0, #0
	blt _08168934
	asrs r1, r0, #0xc
	b _0816893A
	.align 2, 0
_08168924: .4byte 0x030046B8
_08168928: .4byte 0x000003FF
_0816892C: .4byte 0x0203B400
_08168930: .4byte gSineTable
_08168934:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816893A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08168952
	asrs r0, r0, #0xc
	b _08168958
_08168952:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08168958:
	strh r0, [r4, #4]
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	adds r0, r6, #0
	bl Bee_GetCurveTimeShift
	movs r1, #6
	b _081689F6
_0816896E:
	ldr r2, _081689B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081689B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081689BC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r3, r0, r2
	movs r1, #0xff
	add r4, sp, #4
	ands r3, r1
	ldr r2, _081689C0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov sl, r4
	cmp r0, #0
	blt _081689C4
	asrs r1, r0, #0xc
	b _081689CA
	.align 2, 0
_081689B4: .4byte 0x030046B8
_081689B8: .4byte 0x000003FF
_081689BC: .4byte 0x0203B400
_081689C0: .4byte gSineTable
_081689C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081689CA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081689E6
	asrs r0, r0, #0xc
	b _081689EC
_081689E6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081689EC:
	strh r0, [r4, #4]
	adds r0, r6, #0
	bl Bee_GetCurveTimeShift
	movs r1, #0x28
_081689F6:
	lsls r1, r0
	ldr r0, _08168AAC @ =0x000006BE
	add r0, r8
	strh r1, [r0]
	add r1, sp, #4
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	movs r5, #0
	strh r0, [r1]
	mov r4, sl
	ldrh r0, [r4, #2]
	adds r4, r6, #0
	adds r4, #8
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	mov r2, sl
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r6, #0
	mov r1, sl
	bl Bee_BuildCurvePoints
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sl
	bl FUN_0816869c
	ldr r1, _08168AB0 @ =0x00000704
	add r1, r8
	str r5, [sp]
	mov r0, sp
	ldr r2, _08168AB4 @ =0x05000002
	bl CpuSet
	mov sb, r4
_08168A44:
	ldr r0, _08168AB8 @ =0x000006AC
	add r0, r8
	ldrb r1, [r0]
	add r3, sp, #0xc
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _08168ABC @ =0x00000664
	adds r1, r1, r4
	ldrh r0, [r1]
	ldrh r2, [r6, #8]
	subs r0, r0, r2
	strh r0, [r3]
	ldrh r0, [r1, #2]
	mov r4, sb
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	strb r0, [r6, #5]
	ldr r2, _08168AAC @ =0x000006BE
	add r2, r8
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	ble _08168B48
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _08168B48
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	blt _08168AC0
	asrs r1, r0, #5
	b _08168AC6
	.align 2, 0
_08168AAC: .4byte 0x000006BE
_08168AB0: .4byte 0x00000704
_08168AB4: .4byte 0x05000002
_08168AB8: .4byte 0x000006AC
_08168ABC: .4byte 0x00000664
_08168AC0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08168AC6:
	adds r5, r1, #0
	cmp r5, #1
	bge _08168ACE
	movs r5, #1
_08168ACE:
	ldr r4, _08168B34 @ =0x000006AC
	add r4, r8
	ldrb r0, [r4]
	lsls r0, r0, #3
	add r0, r8
	ldr r1, _08168B38 @ =0x00000664
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x10]
	adds r1, r1, r0
	strh r1, [r6, #0x10]
	ldrb r0, [r4]
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r0, r0, r4
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
	ldr r2, _08168B3C @ =0x00000704
	add r2, r8
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08168B40 @ =0x000006BE
	add r2, r8
	ldr r3, _08168B44 @ =0x00000484
	adds r0, r6, r3
	ldr r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	b _08168C7E
	.align 2, 0
_08168B34: .4byte 0x000006AC
_08168B38: .4byte 0x00000664
_08168B3C: .4byte 0x00000704
_08168B40: .4byte 0x000006BE
_08168B44: .4byte 0x00000484
_08168B48:
	ldr r1, _08168BB4 @ =0x000006AC
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _08168B5C
	b _08168C5C
_08168B5C:
	ldr r0, _08168BB8 @ =0x000006A4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, #8]
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	ldr r2, _08168BBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08168BC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08168BC4 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r6, r1
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r3, r0, r2
	movs r1, #0xff
	add r7, sp, #4
	ands r3, r1
	ldr r2, _08168BC8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #9
	mov sl, r7
	cmp r0, #0
	blt _08168BCC
	asrs r1, r0, #0xc
	b _08168BD2
	.align 2, 0
_08168BB4: .4byte 0x000006AC
_08168BB8: .4byte 0x000006A4
_08168BBC: .4byte 0x030046B8
_08168BC0: .4byte 0x000003FF
_08168BC4: .4byte 0x0203B400
_08168BC8: .4byte gSineTable
_08168BCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08168BD2:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _08168BEE
	asrs r0, r0, #0xc
	b _08168BF4
_08168BEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08168BF4:
	movs r4, #0
	movs r5, #0
	strh r0, [r7, #4]
	add r1, sp, #4
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	mov r3, sl
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r6, #0
	mov r1, sl
	bl Bee_BuildCurvePoints
	adds r0, r6, #0
	mov r1, sb
	mov r2, sl
	bl FUN_0816869c
	adds r0, r6, #0
	bl Bee_GetCurveTimeShift
	movs r1, #0xd6
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	lsls r1, r0
	ldr r0, _08168C50 @ =0x000006BE
	add r0, r8
	strh r1, [r0]
	ldr r0, _08168C54 @ =0x000006AC
	add r0, r8
	strb r4, [r0]
	ldr r2, _08168C58 @ =0x00000484
	adds r0, r6, r2
	str r5, [r0]
	b _08168D14
	.align 2, 0
_08168C50: .4byte 0x000006BE
_08168C54: .4byte 0x000006AC
_08168C58: .4byte 0x00000484
_08168C5C:
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	add r0, r8
	ldr r3, _08168C9C @ =0x00000664
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r6, #8]
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
_08168C7E:
	ldr r0, _08168CA0 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	cmp r0, #0x13
	bgt _08168C8C
	adds r0, #1
	str r0, [r1]
_08168C8C:
	ldr r1, _08168CA4 @ =0x000006AE
	add r1, r8
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _08168CA8
	subs r0, #1
	b _08168D12
	.align 2, 0
_08168C9C: .4byte 0x00000664
_08168CA0: .4byte 0x00000484
_08168CA4: .4byte 0x000006AE
_08168CA8:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r0, _08168CE8 @ =0x0000FFFE
	cmp r1, r0
	bhi _08168D14
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	cmp r2, #0
	beq _08168CF0
	movs r1, #2
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #1
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08168CEC @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	str r3, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	b _08168D14
	.align 2, 0
_08168CE8: .4byte 0x0000FFFE
_08168CEC: .4byte 0x0000046A
_08168CF0:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _08168D24 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	str r2, [r0]
	ldr r0, _08168D28 @ =0x0000046C
	adds r1, r6, r0
	movs r0, #1
_08168D12:
	strb r0, [r1]
_08168D14:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08168D24: .4byte 0x00000469
_08168D28: .4byte 0x0000046C
