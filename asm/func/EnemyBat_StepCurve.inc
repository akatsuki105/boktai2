	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	movs r1, #0xd4
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r2, _08140754 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	str r1, [sp, #4]
	ldr r1, [sp, #0xc]
	ands r1, r2
	str r1, [sp, #0xc]
	ldr r1, _08140758 @ =0x00000664
	add r1, r8
	movs r3, #0xcd
	lsls r3, r3, #3
	add r3, r8
	ldr r5, _0814075C @ =0x000004A4
	adds r0, r0, r5
	ldr r0, [r0]
	adds r0, #0xc
	mov sb, r0
	add r7, sp, #4
	add r2, sp, #0xc
	ldrh r6, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x24]
	add r4, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	movs r3, #0
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	add r5, sp, #0x1c
	str r3, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _08140760 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _08140764
	asrs r0, r0, #0xa
	b _0814076A
	.align 2, 0
_08140754: .4byte 0x0000FFFF
_08140758: .4byte 0x00000664
_0814075C: .4byte 0x000004A4
_08140760: .4byte 0x05000002
_08140764:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0814076A:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _08140778
	asrs r3, r0, #0xa
	b _0814077E
_08140778:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_0814077E:
	lsls r2, r3, #1
	lsls r0, r1, #1
	adds r4, r0, r1
	subs r0, r3, r0
	adds r0, r0, r6
	ldr r5, [sp, #0x24]
	adds r3, r0, #0
	muls r3, r5, r3
	str r3, [sp, #0x30]
	subs r0, r2, r4
	adds r0, #1
	mov r6, ip
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r5, r0, #0
	muls r5, r1, r5
	subs r6, r4, r2
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r5, [sp, #0x30]
	adds r0, r0, r5
	cmp r0, #0
	blt _081407B6
	asrs r1, r0, #0xa
	b _081407BC
_081407B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081407BC:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r6, sb
	strh r0, [r6]
	subs r3, r2, r4
	adds r0, r3, #1
	str r0, [sp, #0x28]
	mov r1, ip
	movs r5, #2
	ldrsh r0, [r1, r5]
	ldr r6, [sp, #0x28]
	adds r5, r6, #0
	muls r5, r0, r5
	rsbs r2, r2, #0
	adds r0, r2, r4
	mov r1, sl
	movs r6, #2
	ldrsh r1, [r1, r6]
	adds r6, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r1, [sp, #0x30]
	adds r0, r0, r1
	adds r0, #0
	cmp r0, #0
	blt _081407F6
	asrs r1, r0, #0xa
	b _081407FC
_081407F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081407FC:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #2]
	adds r1, r3, #1
	mov r6, ip
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	adds r1, r2, r4
	mov r6, sl
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	adds r0, #0
	cmp r0, #0
	blt _0814082A
	asrs r1, r0, #0xa
	b _08140830
_0814082A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08140830:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r3, _0814084C @ =0x00000664
	add r3, r8
	ldrh r4, [r3]
	ldr r2, _08140850 @ =0x000003FF
	cmp r4, r2
	bls _08140854
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	b _08140882
	.align 2, 0
_0814084C: .4byte 0x00000664
_08140850: .4byte 0x000003FF
_08140854:
	ldr r1, _08140894 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08140898 @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	adds r0, r0, r1
	adds r0, r4, r0
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bls _08140880
	strh r1, [r3]
_08140880:
	movs r0, #0
_08140882:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08140894: .4byte 0x030046B8
_08140898: .4byte 0x0203B400
