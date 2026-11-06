	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	str r0, [sp, #0x2c]
	adds r4, r0, #0
	adds r4, #0x58
	ldr r0, _081F3880 @ =0x0203B400
	mov sb, r0
	ldr r7, _081F3884 @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _081F3888 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r2, [r4, #2]
	cmp r1, r2
	bne _081F37EA
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_081F37EA:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl Map_GetPathNodes
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	ldr r0, _081F388C @ =0x03002BE0
	add r2, sp, #4
	ldr r3, [r0]
	adds r5, r3, #0
	adds r5, #0x2c
	ldr r4, [sp, #0x2c]
	adds r4, #0x1c
	ldr r1, [sp, #0x2c]
	ldrh r0, [r1, #0x1c]
	ldrh r1, [r3, #0x2c]
	subs r0, r0, r1
	movs r6, #0
	strh r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r4, [sp, #0x2c]
	adds r4, #0xd0
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r4]
	str r1, [r4, #4]
	ldr r2, [sp, #0x2c]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r6, [r0]
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	lsls r1, r0, #1
	add r1, sb
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0xff
	ldrb r0, [r0]
	add r3, sp, #0xc
	adds r5, r1, #0
	adds r6, r0, #0
	subs r6, #0x80
	ldr r1, _081F3890 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	str r4, [sp, #0x44]
	adds r4, r3, #0
	cmp r0, #0
	blt _081F3894
	asrs r1, r0, #0xc
	b _081F389A
	.align 2, 0
_081F3880: .4byte 0x0203B400
_081F3884: .4byte 0x030046B8
_081F3888: .4byte 0x000003FF
_081F388C: .4byte 0x03002BE0
_081F3890: .4byte gSineTable
_081F3894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F389A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081F38B4 @ =gSineTable
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F38B8
	asrs r0, r0, #0xc
	b _081F38BE
	.align 2, 0
_081F38B4: .4byte gSineTable
_081F38B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F38BE:
	movs r2, #0
	strh r0, [r3, #4]
	ldrh r0, [r4]
	ldr r3, [sp, #0x44]
	ldrh r3, [r3]
	adds r0, r0, r3
	ldr r5, [sp, #0x44]
	strh r0, [r5]
	ldr r1, [sp, #0x2c]
	adds r1, #0xd4
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r3, [sp, #0x2c]
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #0x20]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _081F3988 @ =0x0000FFFF
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r3, #0
	adds r0, #0xd2
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc
	bl Div
	str r0, [sp, #0x30]
	ldr r5, [sp, #0x2c]
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	str r0, [sp, #0x34]
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #7
	str r0, [sp, #0x38]
	movs r0, #0
	mov r5, sp
	adds r5, #0x1c
	str r5, [sp, #0x40]
	add r7, sp, #0x24
	mov sl, r7
	add r1, sp, #0x14
	mov sb, r1
	ldr r2, [sp, #0x44]
	str r2, [sp, #0x3c]
_081F3932:
	adds r4, r0, #1
	lsls r0, r0, #3
	ldr r3, [sp, #0x2c]
	adds r3, r3, r0
	mov r8, r3
	movs r5, #0xd8
	add r8, r5
	ldr r7, [sp, #0x30]
	adds r5, r7, #0
	muls r5, r4, r5
	ldr r0, [sp, #0x3c]
	ldrh r1, [r0]
	add r0, sp, #0x14
	ldrh r0, [r0]
	subs r1, r1, r0
	add r0, sp, #0x1c
	strh r1, [r0]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	mov r3, sp
	strh r0, [r3, #0x1e]
	ldr r7, [sp, #0x3c]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #0x20]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	mov r1, sl
	ldr r2, _081F398C @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _081F3990
	asrs r0, r0, #0xa
	b _081F3996
	.align 2, 0
_081F3988: .4byte 0x0000FFFF
_081F398C: .4byte 0x05000002
_081F3990:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081F3996:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _081F39A4
	asrs r1, r0, #0xa
	b _081F39AA
_081F39A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F39AA:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	ldr r5, [sp, #0x38]
	adds r4, r0, #0
	muls r4, r5, r4
	subs r1, r1, r3
	str r1, [sp, #0x48]
	subs r0, r2, r6
	adds r0, #1
	mov r7, sl
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	ldr r7, [sp, #0x34]
	adds r5, r0, #0
	muls r5, r7, r5
	subs r1, r6, r2
	ldr r3, [sp, #0x40]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r5, r0
	adds r0, r0, r4
	ldr r1, [sp, #0x48]
	adds r0, r0, r1
	cmp r0, #0
	blt _081F39EA
	asrs r1, r0, #0xa
	b _081F39F0
_081F39EA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F39F0:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	mov r5, r8
	strh r0, [r5]
	subs r3, r2, r6
	adds r1, r3, #1
	mov r7, sl
	movs r5, #2
	ldrsh r0, [r7, r5]
	muls r0, r1, r0
	ldr r7, [sp, #0x34]
	adds r5, r0, #0
	muls r5, r7, r5
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x4c]
	ldr r1, [sp, #0x40]
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x4c]
	muls r0, r1, r0
	adds r0, r5, r0
	adds r0, r0, r4
	ldr r5, [sp, #0x48]
	adds r0, r0, r5
	cmp r0, #0
	blt _081F3A2C
	asrs r1, r0, #0xa
	b _081F3A32
_081F3A2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F3A32:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, sl
	movs r5, #4
	ldrsh r0, [r3, r5]
	muls r0, r1, r0
	ldr r7, [sp, #0x34]
	adds r5, r0, #0
	muls r5, r7, r5
	adds r1, r2, r6
	ldr r2, [sp, #0x40]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r5, r0
	adds r0, r0, r4
	ldr r5, [sp, #0x48]
	adds r0, r0, r5
	cmp r0, #0
	blt _081F3A66
	asrs r1, r0, #0xa
	b _081F3A6C
_081F3A66:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081F3A6C:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	mov r0, ip
	cmp r0, #0xb
	bgt _081F3A7E
	b _081F3932
_081F3A7E:
	ldr r3, [sp, #0x2c]
	movs r5, #0x9c
	lsls r5, r5, #1
	adds r2, r3, r5
	ldr r7, [sp, #0x44]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
