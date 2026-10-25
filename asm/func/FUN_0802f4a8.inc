	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r4, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov r8, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F518
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F4E8
	ldr r1, _0802F4E4 @ =0x00000824
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x29
	cmp r0, #0
	bne _0802F4F8
	movs r3, #0x25
	b _0802F4F8
	.align 2, 0
_0802F4E4: .4byte 0x00000824
_0802F4E8:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0x25
	cmp r0, #0
	beq _0802F4F8
	movs r3, #0x29
_0802F4F8:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	bl Boss_PlayAnimFacing
	ldr r0, _0802F594 @ =0x0000034B
	bl PlaySound_0824078c
_0802F518:
	movs r1, #8
	adds r5, r4, #0
	adds r5, #0x98
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F5D8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F5D8
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0802F566
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0802F566:
	cmp r6, #9
	bgt _0802F5C2
	movs r0, #0xa
	subs r0, r0, r6
	mov r3, r8
	adds r3, #0x10
	mov r1, r8
	ldrb r5, [r1, #5]
	lsls r6, r0, #2
	ldr r2, _0802F598 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F59C
	asrs r1, r0, #0xc
	b _0802F5A2
	.align 2, 0
_0802F594: .4byte 0x0000034B
_0802F598: .4byte gSineTable
_0802F59C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0802F5A2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802F5BA
	asrs r0, r0, #0xc
	b _0802F5C0
_0802F5BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0802F5C0:
	strh r0, [r3, #4]
_0802F5C2:
	ldr r1, _0802F5E4 @ =0x00000311
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802F5D8
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0802F5D8:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F5E4: .4byte 0x00000311
