	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [sp, #0x24]
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _0816DC1C @ =0x0000FFFF
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #8
	bl Div
	str r0, [sp, #0x28]
	ldr r4, [sp, #0x24]
	ldr r7, _0816DC20 @ =0x00000888
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	str r0, [sp, #0x2c]
	ldr r2, _0816DC24 @ =0x0000088C
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #7
	str r0, [sp, #0x30]
	movs r0, #0
	mov r4, sp
	adds r4, #0x14
	str r4, [sp, #0x38]
	add r7, sp, #0x1c
	mov sl, r7
	add r1, sp, #4
	mov sb, r1
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x34]
_0816DBC4:
	adds r4, r0, #1
	lsls r0, r0, #3
	ldr r3, [sp, #0x24]
	adds r0, r0, r3
	mov r8, r0
	ldr r7, _0816DC28 @ =0x000007EC
	add r8, r7
	ldr r0, [sp, #0x28]
	adds r5, r0, #0
	muls r5, r4, r5
	add r0, sp, #0xc
	ldrh r1, [r0]
	add r0, sp, #4
	ldrh r0, [r0]
	subs r1, r1, r0
	add r0, sp, #0x14
	strh r1, [r0]
	ldr r1, [sp, #0x34]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	mov r3, sp
	strh r0, [r3, #0x16]
	ldr r7, [sp, #0x34]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	mov r1, sl
	ldr r2, _0816DC2C @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _0816DC30
	asrs r0, r0, #0xa
	b _0816DC36
	.align 2, 0
_0816DC1C: .4byte 0x0000FFFF
_0816DC20: .4byte 0x00000888
_0816DC24: .4byte 0x0000088C
_0816DC28: .4byte 0x000007EC
_0816DC2C: .4byte 0x05000002
_0816DC30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0816DC36:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _0816DC44
	asrs r1, r0, #0xa
	b _0816DC4A
_0816DC44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DC4A:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	str r1, [sp, #0x3c]
	subs r0, r2, r6
	adds r0, #1
	mov r7, sl
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	ldr r3, [sp, #0x38]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r1, [sp, #0x3c]
	adds r0, r0, r1
	cmp r0, #0
	blt _0816DC8A
	asrs r1, r0, #0xa
	b _0816DC90
_0816DC8A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DC90:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	mov r4, r8
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	mov r7, sl
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x40]
	ldr r1, [sp, #0x38]
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x40]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x3c]
	adds r0, r0, r4
	cmp r0, #0
	blt _0816DCCC
	asrs r1, r0, #0xa
	b _0816DCD2
_0816DCCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DCD2:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, sl
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	ldr r2, [sp, #0x38]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x3c]
	adds r0, r0, r4
	cmp r0, #0
	blt _0816DD06
	asrs r1, r0, #0xa
	b _0816DD0C
_0816DD06:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816DD0C:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	mov r0, ip
	cmp r0, #7
	bgt _0816DD1E
	b _0816DBC4
_0816DD1E:
	ldr r3, [sp, #0x24]
	ldr r4, _0816DD3C @ =0x0000082C
	adds r2, r3, r4
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816DD3C: .4byte 0x0000082C
