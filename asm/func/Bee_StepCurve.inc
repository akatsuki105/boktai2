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
	ldr r1, _081681E0 @ =0x000006F4
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r1, _081681E4 @ =0x000006FC
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r2, _081681E8 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	str r1, [sp, #4]
	ldr r1, [sp, #0xc]
	ands r1, r2
	str r1, [sp, #0xc]
	ldr r1, _081681EC @ =0x000006B4
	add r1, r8
	movs r3, #0xd7
	lsls r3, r3, #3
	add r3, r8
	ldr r5, _081681F0 @ =0x000004A4
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
	ldr r2, _081681F4 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _081681F8
	asrs r0, r0, #0xa
	b _081681FE
	.align 2, 0
_081681E0: .4byte 0x000006F4
_081681E4: .4byte 0x000006FC
_081681E8: .4byte 0x0000FFFF
_081681EC: .4byte 0x000006B4
_081681F0: .4byte 0x000004A4
_081681F4: .4byte 0x05000002
_081681F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081681FE:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _0816820C
	asrs r3, r0, #0xa
	b _08168212
_0816820C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_08168212:
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
	blt _0816824A
	asrs r1, r0, #0xa
	b _08168250
_0816824A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08168250:
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
	blt _0816828A
	asrs r1, r0, #0xa
	b _08168290
_0816828A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08168290:
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
	blt _081682BE
	asrs r1, r0, #0xa
	b _081682C4
_081682BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081682C4:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r3, _081682E0 @ =0x000006B4
	add r3, r8
	ldrh r4, [r3]
	ldr r2, _081682E4 @ =0x000003FF
	cmp r4, r2
	bls _081682E8
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	b _08168316
	.align 2, 0
_081682E0: .4byte 0x000006B4
_081682E4: .4byte 0x000003FF
_081682E8:
	ldr r1, _08168328 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0816832C @ =0x0203B400
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
	bls _08168314
	strh r1, [r3]
_08168314:
	movs r0, #0
_08168316:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08168328: .4byte 0x030046B8
_0816832C: .4byte 0x0203B400
