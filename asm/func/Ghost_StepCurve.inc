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
	ldr r1, _0816D078 @ =0x00000878
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r3, _0816D07C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r3
	str r1, [sp, #4]
	movs r1, #0x88
	lsls r1, r1, #4
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ands r1, r3
	str r1, [sp, #0xc]
	ldr r1, _0816D080 @ =0x00000838
	add r1, r8
	ldr r3, _0816D084 @ =0x0000083C
	add r3, r8
	ldr r5, _0816D088 @ =0x000004A4
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
	ldr r2, _0816D08C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _0816D090
	asrs r0, r0, #0xa
	b _0816D096
	.align 2, 0
_0816D078: .4byte 0x00000878
_0816D07C: .4byte 0x0000FFFF
_0816D080: .4byte 0x00000838
_0816D084: .4byte 0x0000083C
_0816D088: .4byte 0x000004A4
_0816D08C: .4byte 0x05000002
_0816D090:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0816D096:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _0816D0A4
	asrs r3, r0, #0xa
	b _0816D0AA
_0816D0A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_0816D0AA:
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
	blt _0816D0E2
	asrs r1, r0, #0xa
	b _0816D0E8
_0816D0E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816D0E8:
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
	blt _0816D122
	asrs r1, r0, #0xa
	b _0816D128
_0816D122:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816D128:
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
	blt _0816D156
	asrs r1, r0, #0xa
	b _0816D15C
_0816D156:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816D15C:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r1, _0816D17C @ =0x00000838
	add r1, r8
	ldrh r2, [r1]
	ldr r0, _0816D180 @ =0x000003FF
	cmp r2, r0
	bhi _0816D184
	adds r0, r2, #0
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0
	b _0816D186
	.align 2, 0
_0816D17C: .4byte 0x00000838
_0816D180: .4byte 0x000003FF
_0816D184:
	movs r0, #1
_0816D186:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
