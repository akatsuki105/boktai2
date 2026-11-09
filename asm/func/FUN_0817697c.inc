	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	mov sb, r1
	ldr r2, _081769C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081769C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081769C8 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _081769CC @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081769D0
	asrs r1, r0, #0xc
	b _081769D6
	.align 2, 0
_081769C0: .4byte 0x030046B8
_081769C4: .4byte 0x000003FF
_081769C8: .4byte 0x0203B400
_081769CC: .4byte gSineTable
_081769D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081769D6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081769F0 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081769F4
	asrs r0, r0, #0xc
	b _081769FA
	.align 2, 0
_081769F0: .4byte gSineTable
_081769F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081769FA:
	movs r7, #0
	strh r0, [r4, #4]
	ldr r5, _08176A6C @ =0x0203B400
	ldr r4, _08176A70 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08176A74 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x3f
	ands r0, r2
	adds r0, #0x2a
	add r2, sp, #0x2c
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrb r0, [r1]
	cmp r0, #0x7f
	bgt _08176A88
	ldr r2, _08176A78 @ =0x00009D41
	ldr r3, _08176A7C @ =0x0000E677
	movs r1, #1
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08176A80 @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _08176A84 @ =0x0000022A
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
	b _08176AC8
	.align 2, 0
_08176A6C: .4byte 0x0203B400
_08176A70: .4byte 0x030046B8
_08176A74: .4byte 0x000003FF
_08176A78: .4byte 0x00009D41
_08176A7C: .4byte 0x0000E677
_08176A80: .4byte 0x0000023D
_08176A84: .4byte 0x0000022A
_08176A88:
	ldr r2, _08176B0C @ =0x00009D41
	ldr r3, _08176B10 @ =0x0000E677
	movs r0, #1
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	ldr r0, _08176B14 @ =0x0000023D
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	ldr r1, _08176B18 @ =0x0000022A
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
_08176AC8:
	movs r7, #0
	ldr r5, _08176B1C @ =0x030046B8
	movs r2, #0xff
	mov r8, r2
	add r4, sp, #0x2c
	movs r0, #0xa
	mov sl, r0
_08176AD6:
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08176B20 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08176B24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	mov r2, r8
	ands r3, r2
	ldr r1, _08176B28 @ =gSineTable
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
	blt _08176B2C
	asrs r1, r0, #0xc
	b _08176B32
	.align 2, 0
_08176B0C: .4byte 0x00009D41
_08176B10: .4byte 0x0000E677
_08176B14: .4byte 0x0000023D
_08176B18: .4byte 0x0000022A
_08176B1C: .4byte 0x030046B8
_08176B20: .4byte 0x000003FF
_08176B24: .4byte 0x0203B400
_08176B28: .4byte gSineTable
_08176B2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08176B32:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _08176B54 @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08176B58
	asrs r0, r0, #0xc
	b _08176B5E
	.align 2, 0
_08176B54: .4byte gSineTable
_08176B58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08176B5E:
	movs r2, #0
	strh r0, [r4, #4]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _08176BCC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08176BD0 @ =0x0203B400
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
	beq _08176BE8
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, _08176BD4 @ =0x0000023D
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r2, _08176BD8 @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _08176BDC @ =0x00000232
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
	ldr r2, _08176BE0 @ =0x00009D41
	ldr r3, _08176BE4 @ =0x0000E677
	bl Entity081efa9c_Spawn
	b _08176C28
	.align 2, 0
_08176BCC: .4byte 0x000003FF
_08176BD0: .4byte 0x0203B400
_08176BD4: .4byte 0x0000023D
_08176BD8: .4byte 0x0000022A
_08176BDC: .4byte 0x00000232
_08176BE0: .4byte 0x00009D41
_08176BE4: .4byte 0x0000E677
_08176BE8:
	movs r0, #2
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _08176C48 @ =0x0000023D
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r3, [sp, #0x18]
	ldr r2, _08176C4C @ =0x0000022A
	adds r0, r6, r2
	ldrh r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, _08176C50 @ =0x00000232
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
	ldr r2, _08176C54 @ =0x00009D41
	ldr r3, _08176C58 @ =0x0000E677
	bl Entity081efa9c_Spawn
_08176C28:
	adds r7, #1
	cmp r7, #2
	bgt _08176C30
	b _08176AD6
_08176C30:
	ldr r0, _08176C5C @ =0x000003E2
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
_08176C48: .4byte 0x0000023D
_08176C4C: .4byte 0x0000022A
_08176C50: .4byte 0x00000232
_08176C54: .4byte 0x00009D41
_08176C58: .4byte 0x0000E677
_08176C5C: .4byte 0x000003E2
