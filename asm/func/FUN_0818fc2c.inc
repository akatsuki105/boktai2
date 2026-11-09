	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r3, #0
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp, #0x2c]
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
	ldr r7, [sp, #0x68]
	subs r1, r7, r1
	bl Div
	str r0, [sp, #0x30]
	movs r0, #0
	mov sl, r4
	cmp sl, r7
	blt _0818FC6E
	b _0818FDC8
_0818FC6E:
	mov r1, sp
	adds r1, #4
	str r1, [sp, #0x34]
	add r2, sp, #0xc
	mov sb, r2
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x38]
	add r4, sp, #0x1c
	mov r8, r4
	mov r7, sp
	adds r7, #0x24
	str r7, [sp, #0x40]
_0818FC88:
	adds r4, r0, #1
	ldr r0, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x38]
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
	ldr r2, _0818FCCC @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	str r4, [sp, #0x3c]
	cmp r0, #0
	blt _0818FCD0
	asrs r0, r0, #0xa
	b _0818FCD6
	.align 2, 0
_0818FCCC: .4byte 0x05000002
_0818FCD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0818FCD6:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _0818FCE4
	asrs r1, r0, #0xa
	b _0818FCEA
_0818FCE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FCEA:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	mov ip, r1
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x40]
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
	add r0, ip
	cmp r0, #0
	blt _0818FD28
	asrs r1, r0, #0xa
	b _0818FD2E
_0818FD28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FD2E:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x40]
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
	add r0, ip
	cmp r0, #0
	blt _0818FD68
	asrs r1, r0, #0xa
	b _0818FD6E
_0818FD68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FD6E:
	mov r4, sb
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x40]
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
	add r0, ip
	cmp r0, #0
	blt _0818FDA0
	asrs r1, r0, #0xa
	b _0818FDA6
_0818FDA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0818FDA6:
	mov r4, sb
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #4]
	ldr r0, [sp, #0x2c]
	mov r1, sl
	ldr r2, [sp, #0x34]
	bl FUN_0818f844
	ldr r0, [sp, #0x3c]
	movs r1, #1
	add sl, r1
	ldr r2, [sp, #0x68]
	cmp sl, r2
	bge _0818FDC8
	b _0818FC88
_0818FDC8:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
