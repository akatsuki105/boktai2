	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _0806D2F6
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _0806D274 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	adds r4, r2, #0
	cmp r0, #0
	blt _0806D278
	asrs r1, r0, #0xc
	b _0806D27E
	.align 2, 0
_0806D274: .4byte 0x085B0A08
_0806D278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0806D27E:
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0806D2B0 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0806D2B4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0806D2B8
	asrs r2, r0, #0xc
	b _0806D2BE
	.align 2, 0
_0806D2B0: .4byte 0xFFFF0000
_0806D2B4: .4byte 0x0000FFFF
_0806D2B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0806D2BE:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0806D34C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0
	bl FUN_08060b84
	adds r1, r7, #0
	adds r1, #0x2c
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _0806D350 @ =0x000003A1
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
_0806D2F6:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D354
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0806D35C
	.align 2, 0
_0806D34C: .4byte 0xFFFF0000
_0806D350: .4byte 0x000003A1
_0806D354:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0806D35C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0806D380
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0806D388
_0806D380:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0806D388:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0806D3C0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0806D3F8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0806D3C4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0806D3B8
	ldrb r0, [r4, #5]
_0806D3B8:
	subs r0, #1
	strh r0, [r4, #8]
	b _0806D3D4
	.align 2, 0
_0806D3C0: .4byte 0x0000FFFF
_0806D3C4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0806D3D4
	strh r1, [r4, #8]
_0806D3D4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0806D3F8
	movs r0, #1
	strb r0, [r4, #7]
_0806D3F8:
	ldr r0, _0806D41C @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806D414
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806D414:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806D41C: .4byte 0x0000037E
