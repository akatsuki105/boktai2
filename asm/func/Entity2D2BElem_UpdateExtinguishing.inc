	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r1, #0
	adds r0, r7, #0
	bl Entity2D2BElem_ConsumeStateEntered
	cmp r0, #0
	bne _080081FA
	b _080082FE
_080081FA:
	adds r5, r7, #0
	adds r5, #0x34
	adds r0, r7, #0
	adds r0, #0xe4
	ldr r1, [r0]
	ldr r2, _0800831C @ =0x085AA670
	ldr r0, [r7, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _08008320 @ =0x085AA678
	ldr r0, [r7, #0x18]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r0, r5, #0
	bl MainSprite_SetPlttID
	movs r0, #0xa
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl Entity2D2BElem_RunScript
	ldr r0, [r7, #0x54]
	ldr r1, [r7, #0x58]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	adds r6, r7, #0
	adds r6, #0x54
	ldr r2, _08008324 @ =0xFFFF0000
	movs r0, #0x56
	adds r0, r0, r7
	mov sl, r0
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r1, r3, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldrh r0, [r6]
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r1, #0x58
	adds r1, r1, r7
	mov sb, r1
	ldrh r1, [r1]
	add r5, sp, #0x1c
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r3, #4
	str r3, [sp, #0x10]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	subs r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	adds r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
	ldrh r0, [r6]
	adds r0, #0x40
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	adds r0, #0xc0
	strh r0, [r5, #2]
	mov r3, sb
	ldrh r0, [r3]
	subs r0, #0x40
	strh r0, [r5, #4]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	mov r1, r8
	str r1, [sp, #0x14]
	add r3, sp, #0x1c
	str r3, [sp, #0x18]
	movs r0, #1
	movs r1, #2
	ldr r2, _08008328 @ =0x00002001
	movs r3, #0x40
	bl FUN_08015ce0
_080082FE:
	ldr r0, [r7, #0xc]
	cmp r0, #0xa
	ble _0800830C
	adds r0, r7, #0
	movs r1, #1
	bl Entity2D2BElem_SetState
_0800830C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800831C: .4byte 0x085AA670
_08008320: .4byte 0x085AA678
_08008324: .4byte 0xFFFF0000
_08008328: .4byte 0x00002001
