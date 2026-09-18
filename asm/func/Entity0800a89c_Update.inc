	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, _0800A5E8 @ =0x030047A4
	ldr r2, _0800A5EC @ =0x030047A0
	ldr r3, [r0]
	ldr r0, [r2]
	orrs r3, r0
	ands r1, r3
	cmp r1, #0
	beq _0800A59A
	movs r0, #0x80
	lsls r0, r0, #1
	ands r3, r0
	cmp r3, #0
	bne _0800A59A
	b _0800A79C
_0800A59A:
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sb
	ldr r3, [r0]
	ldrh r0, [r3, #0x2c]
	ldr r4, _0800A5F0 @ =0xFFFF0000
	ldr r2, [sp, #0x28]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x28]
	ldrh r1, [r3, #0x2e]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0800A5F4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldrh r2, [r3, #0x30]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	add r3, sp, #0x30
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A5F8
	asrs r0, r0, #8
	b _0800A5FE
	.align 2, 0
_0800A5E8: .4byte 0x030047A4
_0800A5EC: .4byte 0x030047A0
_0800A5F0: .4byte 0xFFFF0000
_0800A5F4: .4byte 0x0000FFFF
_0800A5F8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A5FE:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A610
	asrs r0, r0, #8
	b _0800A616
_0800A610:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A616:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800A62A
	asrs r1, r0, #8
	b _0800A630
_0800A62A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800A630:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
	mov r4, sp
	movs r1, #0x28
	add r1, sb
	mov r8, r1
	mov r7, r8
	movs r2, #5
	mov sl, r2
_0800A646:
	ldrb r0, [r7]
	cmp r0, #0
	bne _0800A64E
	b _0800A77E
_0800A64E:
	ldrb r0, [r7, #2]
	cmp r0, #2
	bne _0800A664
	mov r1, sp
	ldrh r0, [r1, #0x28]
	strh r0, [r4]
	add r1, sp, #0x28
	ldrh r0, [r1, #2]
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	b _0800A6A6
_0800A664:
	movs r0, #0xfb
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800A690
	ldrh r0, [r1, #0x2c]
	adds r0, #0x18
	strh r0, [r4]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x30]
	subs r0, #0x18
	b _0800A6A6
_0800A690:
	ldrh r0, [r1, #0x2c]
	subs r0, #0x20
	strh r0, [r4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x30]
	adds r0, #0x20
_0800A6A6:
	strh r0, [r4, #4]
	add r6, sp, #8
	mov r3, sp
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r5, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A6C8
	asrs r0, r0, #8
	b _0800A6CE
_0800A6C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A6CE:
	strh r0, [r6]
	adds r1, r5, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800A6E0
	asrs r0, r0, #8
	b _0800A6E6
_0800A6E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0800A6E6:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r3, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0800A6FA
	asrs r1, r0, #8
	b _0800A700
_0800A6FA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0800A700:
	subs r0, r2, r1
	strh r0, [r6, #2]
	adds r0, r2, r1
	strh r0, [r6, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r0, [r4, #8]
	subs r0, #5
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xa]
	subs r0, #5
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0x10]
	adds r0, #5
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x12]
	adds r0, #5
	strh r0, [r4, #0x12]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldrh r0, [r4, #0x18]
	subs r0, #8
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1a]
	subs r0, #0x14
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x20]
	adds r0, #8
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x22]
	adds r0, #0x14
	strh r0, [r4, #0x22]
	mov r0, sb
	mov r1, r8
	mov r2, sp
	bl Entity0800a89c_UpdateSwarm
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _0800A774
	subs r0, #1
	strb r0, [r7, #4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800A774
	ldrb r0, [r7, #2]
	ldr r1, _0800A7B0 @ =0x085AA724
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl PlaySound_0824078c
_0800A774:
	ldrh r0, [r7, #6]
	cmp r0, #0
	beq _0800A77E
	subs r0, #1
	strh r0, [r7, #6]
_0800A77E:
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r7, r7, r1
	add r8, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	blt _0800A794
	b _0800A646
_0800A794:
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
_0800A79C:
	movs r0, #0
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800A7B0: .4byte 0x085AA724
