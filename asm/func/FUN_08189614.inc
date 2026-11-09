	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0818963C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08189640
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08189642
	.align 2, 0
_0818963C: .4byte 0x0000046D
_08189640:
	movs r0, #0
_08189642:
	cmp r0, #0
	beq _0818973E
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r5, #5]
	add r1, sp, #8
	add r2, sp, #0xc
	bl Serpent_GetAnimVariant
	movs r7, #0x9f
	lsls r7, r7, #3
	adds r0, r5, r7
	ldrb r2, [r0]
	ldr r3, [sp, #8]
	ldr r4, [sp, #0xc]
	ldr r1, _08189698 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081896A0
	subs r7, #0x41
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl AuxAnim_SetAnim
	ldr r0, _0818969C @ =0x0000046E
	adds r7, r5, r0
	b _08189722
	.align 2, 0
_08189698: .4byte 0x0000025D
_0818969C: .4byte 0x0000046E
_081896A0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08189710 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08189714 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081896DA
	ldrb r0, [r7]
	cmp r0, #0
	bne _081896DA
	cmp r4, #1
	bne _081896CC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08189726
_081896CC:
	cmp r4, #0
	bne _081896DA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08189726
_081896DA:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081896EC
	movs r3, #6
_081896EC:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _08189718
	ldr r0, [r6, #8]
	mov r2, sb
	orrs r0, r2
	b _08189720
	.align 2, 0
_08189710: .4byte 0x000004B7
_08189714: .4byte 0x0000046E
_08189718:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08189720:
	str r0, [r6, #8]
_08189722:
	movs r0, #0
	strb r0, [r7]
_08189726:
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	mov r0, r8
	movs r1, #0xf
	bl FUN_0818f5f4
	movs r0, #2
	ldr r2, _08189798 @ =0x00000F2C
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0818973E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r4, #0
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r2, _0818979C @ =0x05000002
	bl CpuSet
	ldr r0, _081897A0 @ =0x00000F46
	add r0, r8
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _0818975E
	adds r2, #0x64
_0818975E:
	movs r7, #0xdf
	lsls r7, r7, #1
	adds r1, r5, r7
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r2
	blt _081897B0
	ldr r3, _081897A4 @ =FUN_08189958
	movs r2, #0x26
	ldr r7, _081897A8 @ =0x0000046D
	adds r1, r5, r7
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081897AC @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _08189944
	.align 2, 0
_08189798: .4byte 0x00000F2C
_0818979C: .4byte 0x05000002
_081897A0: .4byte 0x00000F46
_081897A4: .4byte FUN_08189958
_081897A8: .4byte 0x0000046D
_081897AC: .4byte 0x0000046B
_081897B0:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _081897C4
	movs r4, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _081897CA
_081897C4:
	movs r4, #2
	ldrh r0, [r1]
	adds r0, #0x28
_081897CA:
	strh r0, [r1]
	ldrb r0, [r5, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081897F0 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _081897F4
	asrs r1, r0, #0xc
	b _081897FA
	.align 2, 0
_081897F0: .4byte gSineTable
_081897F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081897FA:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08189812
	asrs r2, r0, #0xc
	b _08189818
_08189812:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08189818:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	mov r0, r8
	movs r1, #4
	bl FUN_0818f17c
	movs r6, #0
	mov ip, r6
	ldr r0, _0818985C @ =0x00000F36
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp ip, r0
	blt _08189838
	b _08189944
_08189838:
	ldr r3, _08189860 @ =gSineTable
	movs r4, #0
	ldr r2, _08189864 @ =0x00000674
	add r2, r8
	movs r7, #0x92
	lsls r7, r7, #1
	mov sb, r7
_08189846:
	mov r1, r8
	adds r0, r4, r1
	movs r1, #2
	ldr r7, _08189868 @ =0x0000077A
	adds r0, r0, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818986C
	movs r0, #1
	b _0818986E
	.align 2, 0
_0818985C: .4byte 0x00000F36
_08189860: .4byte gSineTable
_08189864: .4byte 0x00000674
_08189868: .4byte 0x0000077A
_0818986C:
	movs r0, #0
_0818986E:
	cmp r0, #0
	beq _0818992E
	mov r1, r8
	adds r0, r4, r1
	movs r1, #5
	ldr r7, _08189888 @ =0x0000077A
	adds r0, r0, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818988C
	movs r0, #1
	b _0818988E
	.align 2, 0
_08189888: .4byte 0x0000077A
_0818988C:
	movs r0, #0
_0818988E:
	cmp r0, #0
	bne _0818992E
	cmp r6, #0
	beq _081898A2
	cmp r6, #1
	beq _081898DE
	ldrh r0, [r5, #8]
	strh r0, [r2]
	ldrh r0, [r5, #0xc]
	b _0818992A
_081898A2:
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	blt _081898BE
	asrs r1, r0, #0xc
	b _081898C4
_081898BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081898C4:
	ldrh r0, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _0818991C
	b _08189920
_081898DE:
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081898FC
	asrs r1, r0, #0xc
	b _08189902
_081898FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189902:
	ldrh r0, [r5, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08189920
_0818991C:
	asrs r1, r0, #0xc
	b _08189926
_08189920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08189926:
	ldrh r0, [r5, #0xc]
	subs r0, r0, r1
_0818992A:
	strh r0, [r2, #4]
	adds r6, #1
_0818992E:
	add r4, sb
	add r2, sb
	movs r0, #1
	add ip, r0
	ldr r0, _08189954 @ =0x00000F36
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp ip, r0
	bge _08189944
	b _08189846
_08189944:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08189954: .4byte 0x00000F36
