	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r7, r6, r1
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F380
	movs r4, #0
	strb r4, [r1]
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r3, #0xe
	bl Boss_PlayAnimFacing
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
_0803F380:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F394
	b _0803F5AA
_0803F394:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F3AA
	b _0803F5AA
_0803F3AA:
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803F3C0
	adds r0, r2, #2
	strh r0, [r3]
_0803F3C0:
	ldr r2, _0803F3E0 @ =gSineTable
	mov r4, r8
	lsls r0, r4, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0803F3E4
	asrs r1, r0, #0xc
	b _0803F3EA
	.align 2, 0
_0803F3E0: .4byte gSineTable
_0803F3E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803F3EA:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803F400
	strh r3, [r1]
_0803F400:
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r0, [r2]
	cmp r0, #1
	beq _0803F468
	cmp r0, #1
	bgt _0803F416
	cmp r0, #0
	beq _0803F422
	b _0803F5AA
_0803F416:
	cmp r0, #2
	beq _0803F492
	cmp r0, #3
	bne _0803F420
	b _0803F598
_0803F420:
	b _0803F5AA
_0803F422:
	ldrh r0, [r7, #0x14]
	cmp r0, #7
	bne _0803F434
	ldrh r0, [r7, #0xc]
	cmp r0, #1
	bne _0803F434
	ldr r0, _0803F464 @ =0x0000035E
	bl PlaySound_0824078c
_0803F434:
	movs r0, #8
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r7, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803F44A
	b _0803F5AA
_0803F44A:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r4, #0xae
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #0
	strh r0, [r1]
	b _0803F5AA
	.align 2, 0
_0803F464: .4byte 0x0000035E
_0803F468:
	movs r0, #8
	movs r7, #0xb5
	lsls r7, r7, #1
	adds r1, r5, r7
	strb r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0803F488
	b _0803F5AA
_0803F488:
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	strh r3, [r1]
	b _0803F5AA
_0803F492:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0803F4A6
	cmp r0, #0x10
	beq _0803F4A6
	cmp r0, #0x20
	bne _0803F53C
_0803F4A6:
	add r2, sp, #0x14
	mov r3, sb
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldrh r0, [r2, #2]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r0, r4
	strh r0, [r2, #2]
	adds r0, r6, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	movs r7, #0xae
	lsls r7, r7, #1
	adds r1, r5, r7
	subs r0, #0x10
	ldrh r1, [r1]
	adds r4, r0, r1
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r3, [r0, r2]
	ldr r7, _0803F584 @ =0x000002B6
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F4EE
	subs r1, #0x26
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	asrs r3, r0, #6
_0803F4EE:
	ldr r7, _0803F588 @ =0x00000958
	adds r0, r5, r7
	ldr r0, [r0]
	ldr r2, _0803F58C @ =0x000002F2
	adds r1, r5, r2
	movs r7, #0
	ldrsh r2, [r1, r7]
	ldr r7, _0803F590 @ =0x000002EE
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp]
	movs r7, #0xbc
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #4]
	movs r7, #0xbd
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #8]
	ldr r7, _0803F594 @ =0x000002F6
	adds r1, r5, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	str r1, [sp, #0xc]
	add r1, sp, #0x14
	str r1, [sp, #0x10]
	adds r1, r4, #0
	bl FUN_0805ef68
	movs r0, #4
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_0803F53C:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0803F5AA
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r2]
	movs r7, #0xd3
	lsls r7, r7, #2
	adds r1, r5, r7
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0x17
	bl Boss_PlayAnimFacing
	b _0803F5AA
	.align 2, 0
_0803F584: .4byte 0x000002B6
_0803F588: .4byte 0x00000958
_0803F58C: .4byte 0x000002F2
_0803F590: .4byte 0x000002EE
_0803F594: .4byte 0x000002F6
_0803F598:
	ldrb r1, [r7, #0x1d]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F5AA
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803F5AA:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
