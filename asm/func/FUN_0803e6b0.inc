	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sl, r1
	adds r6, r4, #0
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
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803E726
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Boss_PlayAnimDir8
	b _0803E742
_0803E726:
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Boss_PlayAnimDir8
_0803E742:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E850
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #0
	bne _0803E850
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r7, r6, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _0803E7F0
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #3
	movs r1, #0
	bl FUN_08050e2c
	adds r0, r4, #0
	adds r0, #0x92
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r7]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x90
	movs r3, #0
	ldrsh r5, [r4, r3]
	adds r1, r5, r0
	adds r0, r6, #0
	bl Boss_SetHP
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r5, r0
	beq _0803E7E4
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r4, _0803E828 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	movs r3, #0x10
	orrs r1, r3
	ldr r2, _0803E82C @ =0x0000FFFF
	ands r1, r2
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r3
	str r1, [sp, #0x10]
	adds r3, r6, #0
	adds r3, #0x50
	add r1, sp, #0xc
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	mov r1, r8
	movs r2, #1
	bl FUN_0805fe7c
_0803E7E4:
	mov r2, sb
	strb r2, [r7]
	movs r0, #0xdd
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803E7F0:
	movs r3, #0xb1
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r2, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r0, #0
	cmp r1, #0x3d
	bgt _0803E806
	adds r0, r2, #2
	strh r0, [r3]
_0803E806:
	ldr r2, _0803E830 @ =gSineTable
	mov r1, sl
	lsls r0, r1, #1
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
	blt _0803E834
	asrs r1, r0, #0xc
	b _0803E83A
	.align 2, 0
_0803E828: .4byte 0xFFFF0000
_0803E82C: .4byte 0x0000FFFF
_0803E830: .4byte gSineTable
_0803E834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803E83A:
	ldrh r0, [r3]
	adds r0, r0, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0803E850
	movs r0, #0
	strh r0, [r1]
_0803E850:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
