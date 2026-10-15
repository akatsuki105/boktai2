	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r4, [r7, #0x1c]
	movs r1, #0
	mov r8, r1
	ldr r1, [r7, #0x18]
	cmp r8, r1
	bhs _080084AC
	adds r6, r4, #0
	adds r6, #0x94
_080083D4:
	ldrb r1, [r4]
	adds r5, r4, #0
	adds r5, #0x9a
	cmp r1, #0
	beq _0800849E
	ldr r2, [r4, #0x14]
	cmp r2, #0
	blt _08008414
	ldr r1, _080083F8 @ =0x030046A0
	ldr r1, [r1]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r1, r3
	ldr r1, [r1]
	cmp r1, r2
	bne _080083FC
	movs r1, #1
	b _080083FE
	.align 2, 0
_080083F8: .4byte 0x030046A0
_080083FC:
	movs r1, #0
_080083FE:
	cmp r1, #0
	bne _08008414
	ldr r1, [r4, #0x3c]
	movs r2, #1
	orrs r1, r2
	str r1, [r4, #0x3c]
	ldrh r2, [r6, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r6, #6]
	b _0800849E
_08008414:
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	ldrh r0, [r6, #6]
	ldr r2, _08008448 @ =0x0000FFFB
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r6, #6]
	ldr r1, _0800844C @ =0x085AA67C
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _08008450
	adds r0, r4, #0
	bl Entity2D2BElem_WalkPath
	b _0800845A
	.align 2, 0
_08008448: .4byte 0x0000FFFB
_0800844C: .4byte 0x085AA67C
_08008450:
	cmp r0, #2
	bne _0800845A
	adds r0, r4, #0
	bl Entity2D2BElem_FollowElevator
_0800845A:
	adds r0, r4, #0
	adds r0, #0x34
	ldr r1, [r6, #0x50]
	bl MainSprite_AdvanceAnim
	adds r1, r4, #0
	adds r1, #0x54
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r1, [r4, #5]
	cmp r1, #0
	beq _08008498
	subs r1, #1
	strb r1, [r4, #5]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008490
	ldrh r1, [r5]
	ldr r3, _0800848C @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008496
	.align 2, 0
_0800848C: .4byte 0x0000FFFB
_08008490:
	ldrh r2, [r5]
	movs r1, #4
	orrs r1, r2
_08008496:
	strh r1, [r5]
_08008498:
	ldr r1, [r4, #0xc]
	adds r1, #1
	str r1, [r4, #0xc]
_0800849E:
	movs r1, #1
	add r8, r1
	adds r6, #0xe8
	adds r4, #0xe8
	ldr r1, [r7, #0x18]
	cmp r8, r1
	blo _080083D4
_080084AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
