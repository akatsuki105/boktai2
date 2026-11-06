	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805C748
	movs r0, #0
	strb r0, [r7]
	ldr r2, _0805C68C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C690 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C694 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r5, [r0]
	ldr r1, _0805C698 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805C69C
	asrs r3, r0, #0xc
	b _0805C6A2
	.align 2, 0
_0805C68C: .4byte 0x030046B8
_0805C690: .4byte 0x000003FF
_0805C694: .4byte 0x0203B400
_0805C698: .4byte gSineTable
_0805C69C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C6A2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C6BC
	asrs r0, r0, #0xc
	b _0805C6C2
_0805C6BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C6C2:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805C758 @ =0x0203B400
	ldr r2, _0805C75C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C760 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	adds r2, r7, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C748:
	mov r2, r8
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	bne _0805C764
	movs r0, #1
	strb r0, [r7, #1]
	b _0805C80A
	.align 2, 0
_0805C758: .4byte 0x0203B400
_0805C75C: .4byte 0x030046B8
_0805C760: .4byte 0x000003FF
_0805C764:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805C7D0
	adds r6, r7, #0
	adds r6, #0x14
	adds r5, r7, #0
	adds r5, #0x1c
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805C7C4 @ =0x0203B400
	ldr r2, _0805C7C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C7CC @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	b _0805C7DC
	.align 2, 0
_0805C7C4: .4byte 0x0203B400
_0805C7C8: .4byte 0x030046B8
_0805C7CC: .4byte 0x000003FF
_0805C7D0:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x1c
	adds r6, r7, #0
	adds r6, #0x14
_0805C7DC:
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	movs r4, #0x14
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C810 @ =0x00000FFF
	cmp r1, r0
	bhi _0805C814
	movs r0, #7
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
_0805C80A:
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805C9A8
	.align 2, 0
_0805C810: .4byte 0x00000FFF
_0805C814:
	ldr r0, _0805C848 @ =0x0000FFFF
	cmp r1, r0
	bhi _0805C898
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #5
	mov ip, r1
	ldr r2, _0805C84C @ =gSineTable
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C850
	asrs r3, r0, #0xc
	b _0805C856
	.align 2, 0
_0805C848: .4byte 0x0000FFFF
_0805C84C: .4byte gSineTable
_0805C850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C856:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r4, ip
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r0, #0
	blt _0805C876
	asrs r0, r0, #0xc
	b _0805C87C
_0805C876:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C87C:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C898:
	ldrh r0, [r7, #4]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x3f
	bgt _0805C912
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _0805C8C8 @ =gSineTable
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C8CC
	asrs r3, r0, #0xc
	b _0805C8D2
	.align 2, 0
_0805C8C8: .4byte gSineTable
_0805C8CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C8D2:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C8F0
	asrs r0, r0, #0xc
	b _0805C8F6
_0805C8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C8F6:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C912:
	cmp r1, #0x5f
	bgt _0805C98C
	add r4, sp, #8
	ldrb r5, [r7, #6]
	movs r3, #6
	mov ip, r3
	ldr r2, _0805C944 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r4, #0
	cmp r0, #0
	blt _0805C948
	asrs r3, r0, #0xc
	b _0805C94E
	.align 2, 0
_0805C944: .4byte gSineTable
_0805C948:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C94E:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C96A
	asrs r0, r0, #0xc
	b _0805C970
_0805C96A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C970:
	strh r0, [r4, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r7, #0x14]
	adds r0, r0, r3
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r4, [r6, #2]
	adds r0, r0, r4
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r6, #4]
	adds r0, r0, r5
_0805C98A:
	strh r0, [r6, #4]
_0805C98C:
	adds r0, r7, #0
	adds r0, #0x7c
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
_0805C9A8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
