	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r3, [r6, #0x44]
	ldr r2, _081903A0 @ =gSineTable
	ldr r4, _081903A4 @ =0x00000F2E
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081903A8
	asrs r1, r0, #0xc
	b _081903AE
	.align 2, 0
_081903A0: .4byte gSineTable
_081903A4: .4byte 0x00000F2E
_081903A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081903AE:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldr r1, [r6, #0x44]
	ldr r3, [sp, #0x24]
	ldr r4, _081903D0 @ =0x00000F2E
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #4
	cmp r0, #0
	blt _081903D4
	asrs r2, r0, #0xc
	b _081903DA
	.align 2, 0
_081903D0: .4byte 0x00000F2E
_081903D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081903DA:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r0, [sp, #0x24]
	ldr r2, _0819042C @ =0x00000F2E
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov sl, r5
	ldr r3, [sp, #0x24]
	ldr r4, _08190430 @ =0x00000F36
	adds r1, r3, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sl, r0
	bge _0819046A
	ldr r0, _08190434 @ =gSineTable
	mov r8, r0
	mov sb, r1
	movs r1, #0x92
	lsls r1, r1, #1
	adds r3, r3, r1
	ldr r4, [sp, #0x24]
	ldr r7, _08190438 @ =0x0000087D
	adds r2, r4, r7
	movs r4, #0x92
	lsls r4, r4, #2
_08190416:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0819043C
	asrs r0, r0, #0xc
	b _08190442
	.align 2, 0
_0819042C: .4byte 0x00000F2E
_08190430: .4byte 0x00000F36
_08190434: .4byte gSineTable
_08190438: .4byte 0x0000087D
_0819043C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08190442:
	ldr r7, _081904F4 @ =0x00000674
	adds r1, r3, r7
	muls r0, r5, r0
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #8
	strb r0, [r2]
	rsbs r5, r5, #0
	adds r3, r3, r4
	adds r2, r2, r4
	movs r0, #2
	add sl, r0
	mov r1, sb
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sl, r0
	blt _08190416
_0819046A:
	ldr r0, [r6, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0
	mov sl, r0
	ldr r1, [sp, #0x24]
	ldr r2, _081904F8 @ =0x00000F36
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sl, r0
	blt _0819048A
	b _081905B4
_0819048A:
	add r4, sp, #4
	mov sb, r4
	add r7, sp, #0xc
	add r6, sp, #0x14
	movs r0, #0xf3
	lsls r0, r0, #3
	adds r5, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov r8, r1
_0819049E:
	ldrh r0, [r5]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _081904FC @ =0x05000002
	bl CpuSet
	mov r3, r8
	movs r4, #0xc0
	lsls r4, r4, #2
	subs r1, r3, r4
	adds r1, #1
	add r2, sp, #0x1c
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	mov r3, r8
	subs r1, r0, r3
	movs r3, #0
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _08190500
	asrs r1, r0, #0xa
	b _08190506
	.align 2, 0
_081904F4: .4byte 0x00000674
_081904F8: .4byte 0x00000F36
_081904FC: .4byte 0x05000002
_08190500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08190506:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r4, sb
	strh r0, [r4]
	mov r0, r8
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	rsbs r2, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r1, r2, r1
	str r1, [sp, #0x28]
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [sp, #0x28]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _08190544
	asrs r1, r0, #0xa
	b _0819054A
_08190544:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819054A:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, sb
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _08190578
	asrs r1, r0, #0xa
	b _0819057E
_08190578:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819057E:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r4, sb
	strh r0, [r4, #4]
	ldr r0, [sp, #0x24]
	mov r1, sl
	mov r2, sb
	bl FUN_0818f844
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x92
	lsls r0, r0, #2
	adds r5, r5, r0
	movs r1, #2
	add sl, r1
	ldr r2, [sp, #0x24]
	ldr r3, _081905C4 @ =0x00000F36
	adds r0, r2, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp sl, r0
	bge _081905B4
	b _0819049E
_081905B4:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081905C4: .4byte 0x00000F36
