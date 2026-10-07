	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x48
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D1E6
	movs r0, #0
	strb r0, [r4, #1]
_0800D1E6:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x31
	mov r5, sp
	ldrb r6, [r0]
	ldr r2, _0800D214 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D218
	asrs r1, r0, #0xc
	b _0800D21E
	.align 2, 0
_0800D214: .4byte 0x085B0A08
_0800D218:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D21E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x10
	muls r0, r1, r0
	cmp r0, #0
	blt _0800D238
	asrs r0, r0, #0xc
	b _0800D23E
_0800D238:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D23E:
	strh r0, [r5, #4]
	adds r2, r3, #0
	adds r2, #8
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r3, #8]
	adds r0, r0, r5
	strh r0, [r3, #8]
	ldrh r0, [r1, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r1, [r1, #4]
	ldrh r0, [r2, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldrh r0, [r3, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0800D282
	cmp r1, #0
	blt _0800D282
	ldr r0, _0800D288 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D282
	ldr r0, _0800D28C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D290
_0800D282:
	movs r0, #0
	b _0800D29E
	.align 2, 0
_0800D288: .4byte 0x030046A8
_0800D28C: .4byte 0x030046AC
_0800D290:
	ldr r0, _0800D2E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D29E:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r6, #0
	movs r7, #0
	strh r0, [r2]
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bls _0800D358
	ldrh r2, [r3, #8]
	ldr r1, _0800D2EC @ =0xFFFFFF00
	adds r0, r1, #0
	ands r0, r2
	adds r0, #0x80
	strh r0, [r3, #8]
	ldrh r0, [r3, #0xc]
	ands r1, r0
	adds r1, #0x80
	strh r1, [r3, #0xc]
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0800D2F0
	strb r6, [r4, #3]
	str r7, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
	subs r0, #6
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	b _0800D326
	.align 2, 0
_0800D2E8: .4byte 0x030046A4
_0800D2EC: .4byte 0xFFFFFF00
_0800D2F0:
	adds r0, r4, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800D302
	movs r0, #4
	strb r0, [r4, #3]
	str r7, [r4, #4]
	b _0800D322
_0800D302:
	strb r6, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	movs r2, #1
	rsbs r2, r2, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_0800cf30
	cmp r0, #0
	bne _0800D326
	strb r6, [r4, #3]
	str r0, [r4, #4]
_0800D322:
	movs r0, #1
	strb r0, [r4, #1]
_0800D326:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D330
	movs r0, #0x78
	b _0800D356
_0800D330:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D33E
	movs r0, #0x7b
	b _0800D356
_0800D33E:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D34A
	movs r0, #0x7c
	b _0800D356
_0800D34A:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D356
	movs r0, #0x79
_0800D356:
	strh r0, [r4, #0x2e]
_0800D358:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
