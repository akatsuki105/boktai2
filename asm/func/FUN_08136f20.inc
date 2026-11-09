	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r3, #0
	ldr r5, [sp, #0x68]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r6, [r0]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	subs r1, r4, #1
	subs r1, r5, r1
	bl Div
	str r0, [sp, #0x2c]
	movs r1, #0
	mov sl, r4
	cmp sl, r5
	blt _08136F60
	b _081370E4
_08136F60:
	mov r4, sp
	adds r4, #4
	str r4, [sp, #0x30]
	add r7, sp, #0xc
	mov sb, r7
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x34]
	add r2, sp, #0x1c
	mov r8, r2
	mov r3, sl
	lsls r0, r3, #3
	add r0, sl
	lsls r0, r0, #5
	ldr r4, _08136FD4 @ =0x00000674
	adds r0, r0, r4
	adds r0, r0, r6
	str r0, [sp, #0x3c]
	mov r7, sp
	adds r7, #0x24
	str r7, [sp, #0x38]
	subs r3, r5, r3
	mov sl, r3
_08136F8E:
	adds r4, r1, #1
	ldr r0, [sp, #0x2c]
	adds r5, r0, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x34]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x34]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x24
	ldr r2, _08136FD8 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _08136FDC
	asrs r0, r0, #0xa
	b _08136FE2
	.align 2, 0
_08136FD4: .4byte 0x00000674
_08136FD8: .4byte 0x05000002
_08136FDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08136FE2:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _08136FF0
	asrs r1, r0, #0xa
	b _08136FF6
_08136FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08136FF6:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	str r1, [sp, #0x40]
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x38]
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	adds r7, r4, #0
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r1, [sp, #0x40]
	adds r0, r0, r1
	cmp r0, #0
	blt _08137036
	asrs r1, r0, #0xa
	b _0813703C
_08137036:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813703C:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x30]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x38]
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x44]
	mov r1, r8
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x40]
	adds r0, r0, r4
	cmp r0, #0
	blt _08137078
	asrs r1, r0, #0xa
	b _0813707E
_08137078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813707E:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	strh r0, [r1, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x38]
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x40]
	adds r0, r0, r4
	cmp r0, #0
	blt _081370B2
	asrs r1, r0, #0xa
	b _081370B8
_081370B2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081370B8:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	strh r0, [r1, #4]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	mov r1, ip
	movs r3, #0x90
	lsls r3, r3, #1
	adds r2, r2, r3
	str r2, [sp, #0x3c]
	movs r4, #1
	rsbs r4, r4, #0
	add sl, r4
	mov r7, sl
	cmp r7, #0
	beq _081370E4
	b _08136F8E
_081370E4:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
