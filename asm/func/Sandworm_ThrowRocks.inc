	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	mov sb, r1
	ldr r2, _081766DC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081766E0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081766E4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0x28
	ldr r1, _081766E8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081766EC
	asrs r1, r0, #0xc
	b _081766F2
	.align 2, 0
_081766DC: .4byte 0x030046B8
_081766E0: .4byte 0x000003FF
_081766E4: .4byte 0x0203B400
_081766E8: .4byte gSineTable
_081766EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081766F2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _0817670C @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08176710
	asrs r0, r0, #0xc
	b _08176716
	.align 2, 0
_0817670C: .4byte gSineTable
_08176710:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08176716:
	movs r7, #0
	strh r0, [r4, #4]
	ldr r5, _08176788 @ =0x0203B400
	ldr r4, _0817678C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08176790 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x3f
	ands r0, r2
	adds r0, #0x14
	add r2, sp, #0x2c
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrb r0, [r1]
	cmp r0, #0x7f
	bgt _081767A4
	ldr r2, _08176794 @ =0x00009D41
	ldr r3, _08176798 @ =0x0000E677
	movs r1, #1
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _0817679C @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _081767A0 @ =0x0000022A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x16
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	subs r1, #0xe
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	b _081767E4
	.align 2, 0
_08176788: .4byte 0x0203B400
_0817678C: .4byte 0x030046B8
_08176790: .4byte 0x000003FF
_08176794: .4byte 0x00009D41
_08176798: .4byte 0x0000E677
_0817679C: .4byte 0x0000023D
_081767A0: .4byte 0x0000022A
_081767A4:
	ldr r2, _08176828 @ =0x00009D41
	ldr r3, _0817682C @ =0x0000E677
	movs r0, #1
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08176830 @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r1, _08176834 @ =0x0000022A
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r1, #0x16
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	subs r1, #0xe
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
_081767E4:
	movs r7, #0
	ldr r5, _08176838 @ =0x030046B8
	movs r2, #0xff
	mov r8, r2
	add r4, sp, #0x2c
	movs r0, #0xa
	mov sl, r0
_081767F2:
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0817683C @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08176840 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	mov r2, r8
	ands r3, r2
	ldr r1, _08176844 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08176848
	asrs r1, r0, #0xc
	b _0817684E
	.align 2, 0
_08176828: .4byte 0x00009D41
_0817682C: .4byte 0x0000E677
_08176830: .4byte 0x0000023D
_08176834: .4byte 0x0000022A
_08176838: .4byte 0x030046B8
_0817683C: .4byte 0x000003FF
_08176840: .4byte 0x0203B400
_08176844: .4byte gSineTable
_08176848:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817684E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _08176870 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08176874
	asrs r0, r0, #0xc
	b _0817687A
	.align 2, 0
_08176870: .4byte gSineTable
_08176874:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0817687A:
	movs r2, #0
	strh r0, [r4, #4]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081768E8 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _081768EC @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	adds r1, #0x20
	add r0, sp, #0x2c
	strh r1, [r0, #2]
	movs r3, #1
	adds r1, r7, #0
	ands r1, r3
	cmp r1, #0
	beq _08176904
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, _081768F0 @ =0x0000023D
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldr r2, _081768F4 @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _081768F8 @ =0x00000232
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r2, #0x1e
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	ldr r2, _081768FC @ =0x00009D41
	ldr r3, _08176900 @ =0x0000E677
	bl Entity081efa9c_Spawn
	b _08176944
	.align 2, 0
_081768E8: .4byte 0x000003FF
_081768EC: .4byte 0x0203B400
_081768F0: .4byte 0x0000023D
_081768F4: .4byte 0x0000022A
_081768F8: .4byte 0x00000232
_081768FC: .4byte 0x00009D41
_08176900: .4byte 0x0000E677
_08176904:
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _08176964 @ =0x0000023D
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, _08176968 @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _0817696C @ =0x00000232
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r2, #0x1e
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	adds r1, #8
	adds r0, r6, r1
	ldrh r0, [r0]
	str r0, [sp, #0x28]
	mov r0, sb
	add r1, sp, #0x2c
	ldr r2, _08176970 @ =0x00009D41
	ldr r3, _08176974 @ =0x0000E677
	bl Entity081efa9c_Spawn
_08176944:
	adds r7, #1
	cmp r7, #1
	bgt _0817694C
	b _081767F2
_0817694C:
	ldr r0, _08176978 @ =0x000003E2
	bl PlaySound_082406e0
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08176964: .4byte 0x0000023D
_08176968: .4byte 0x0000022A
_0817696C: .4byte 0x00000232
_08176970: .4byte 0x00009D41
_08176974: .4byte 0x0000E677
_08176978: .4byte 0x000003E2
