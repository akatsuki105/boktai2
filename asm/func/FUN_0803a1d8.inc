	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	adds r5, r1, #0
	mov r7, r8
	adds r6, r7, #0
	adds r6, #0x48
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A21E
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x17
	bl Boss_PlayAnimFacing
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0803A21E:
	movs r2, #0xc
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	cmp r5, #0x1f
	bgt _0803A2A0
	ldrb r0, [r6, #5]
	adds r6, r7, #0
	adds r6, #0x58
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _0803A260 @ =gSineTable
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r1, r2, #0
	cmp r0, #0
	blt _0803A264
	asrs r3, r0, #0xc
	b _0803A26A
	.align 2, 0
_0803A260: .4byte gSineTable
_0803A264:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803A26A:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0803A288
	asrs r0, r0, #0xc
	b _0803A28E
_0803A288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803A28E:
	strh r0, [r6, #4]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r5, [r0]
	adds r0, r7, #0
	movs r1, #0x80
	bl FUN_08036884
_0803A2A0:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _0803A398
	ldr r4, _0803A2F0 @ =0x0203B400
	ldr r3, _0803A2F4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0803A2F8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	add r4, sp, #0xc
	adds r2, r1, #0
	adds r2, #0x20
	ldr r1, _0803A2FC @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r2, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0803A300
	asrs r3, r0, #0xc
	b _0803A306
	.align 2, 0
_0803A2F0: .4byte 0x0203B400
_0803A2F4: .4byte 0x030046B8
_0803A2F8: .4byte 0x000003FF
_0803A2FC: .4byte gSineTable
_0803A300:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803A306:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0803A31E
	asrs r0, r0, #0xc
	b _0803A324
_0803A31E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803A324:
	strh r0, [r4, #4]
	add r3, sp, #0xc
	movs r4, #0xa8
	lsls r4, r4, #2
	adds r2, r7, r4
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	adds r1, #0x80
	strh r1, [r3, #2]
	ldr r4, _0803A3C4 @ =0x0203B400
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _0803A3C8 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r3
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r2, [r2]
	movs r5, #0xf
	ands r2, r5
	adds r2, #0x10
	adds r0, #1
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	ands r3, r5
	adds r3, #4
	ldr r6, _0803A3CC @ =0x00000DE8
	adds r0, r7, r6
	ldr r0, [r0]
	movs r4, #0x3c
	str r4, [sp]
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrb r4, [r4]
	str r4, [sp, #4]
	add r6, sp, #0xc
	str r6, [sp, #8]
	bl FUN_08060220
_0803A398:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A3B6
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_0803A3B6:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A3C4: .4byte 0x0203B400
_0803A3C8: .4byte 0x000003FF
_0803A3CC: .4byte 0x00000DE8
