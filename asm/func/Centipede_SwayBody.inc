	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r3, [r6, #0x44]
	ldr r2, _081375BC @ =gSineTable
	ldr r4, _081375C0 @ =0x00000B32
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
	blt _081375C4
	asrs r1, r0, #0xc
	b _081375CA
	.align 2, 0
_081375BC: .4byte gSineTable
_081375C0: .4byte 0x00000B32
_081375C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081375CA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldr r1, [r6, #0x44]
	ldr r3, [sp, #0x24]
	ldr r4, _081375EC @ =0x00000B32
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #4
	cmp r0, #0
	blt _081375F0
	asrs r2, r0, #0xc
	b _081375F6
	.align 2, 0
_081375EC: .4byte 0x00000B32
_081375F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081375F6:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r0, [sp, #0x24]
	ldr r2, _08137648 @ =0x00000B32
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov sb, r5
	ldr r3, [sp, #0x24]
	ldr r4, _0813764C @ =0x00000B3A
	adds r1, r3, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sb, r0
	bge _08137686
	ldr r0, _08137650 @ =gSineTable
	mov r8, r0
	mov sl, r1
	movs r1, #0x90
	lsls r1, r1, #1
	adds r3, r3, r1
	ldr r4, [sp, #0x24]
	ldr r7, _08137654 @ =0x00000879
	adds r2, r4, r7
	movs r4, #0x90
	lsls r4, r4, #2
_08137632:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08137658
	asrs r0, r0, #0xc
	b _0813765E
	.align 2, 0
_08137648: .4byte 0x00000B32
_0813764C: .4byte 0x00000B3A
_08137650: .4byte gSineTable
_08137654: .4byte 0x00000879
_08137658:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813765E:
	ldr r7, _08137714 @ =0x00000674
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
	add sb, r0
	mov r1, sl
	movs r7, #0
	ldrsh r0, [r1, r7]
	subs r0, #1
	cmp sb, r0
	blt _08137632
_08137686:
	ldr r0, [r6, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0
	mov sb, r0
	ldr r1, [sp, #0x24]
	ldr r2, _08137718 @ =0x00000B3A
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sb, r0
	blt _081376A6
	b _081377D6
_081376A6:
	mov r4, sp
	adds r4, #4
	str r4, [sp, #0x28]
	add r7, sp, #0xc
	add r6, sp, #0x14
	ldr r0, _0813771C @ =0x00000794
	adds r5, r1, r0
	ldr r2, _08137714 @ =0x00000674
	adds r2, r1, r2
	str r2, [sp, #0x2c]
	movs r3, #0x80
	lsls r3, r3, #1
	mov r8, r3
	movs r4, #0xc0
	lsls r4, r4, #2
	mov sl, r4
_081376C6:
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
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _08137720 @ =0x05000002
	bl CpuSet
	mov r2, r8
	mov r3, sl
	subs r1, r2, r3
	adds r1, #1
	add r2, sp, #0x1c
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	subs r1, r3, r0
	movs r3, #0
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _08137724
	asrs r1, r0, #0xa
	b _0813772A
	.align 2, 0
_08137714: .4byte 0x00000674
_08137718: .4byte 0x00000B3A
_0813771C: .4byte 0x00000794
_08137720: .4byte 0x05000002
_08137724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813772A:
	ldrh r0, [r7]
	adds r0, r0, r1
	ldr r4, [sp, #0x28]
	strh r0, [r4]
	mov r0, r8
	mov r1, sl
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, r8
	rsbs r2, r0, #0
	mov r1, sl
	adds r1, r2, r1
	str r1, [sp, #0x30]
	movs r1, #2
	ldrsh r0, [r6, r1]
	ldr r1, [sp, #0x30]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _08137764
	asrs r1, r0, #0xa
	b _0813776A
_08137764:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813776A:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	ldr r1, [sp, #0x28]
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, sl
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _08137796
	asrs r1, r0, #0xa
	b _0813779C
_08137796:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813779C:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	ldr r4, [sp, #0x28]
	strh r0, [r4, #4]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r3, #0x90
	lsls r3, r3, #2
	adds r5, r5, r3
	adds r2, r2, r3
	str r2, [sp, #0x2c]
	movs r4, #2
	add sb, r4
	ldr r1, [sp, #0x24]
	ldr r2, _081377E8 @ =0x00000B3A
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #1
	cmp sb, r0
	bge _081377D6
	b _081376C6
_081377D6:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081377E8: .4byte 0x00000B3A
