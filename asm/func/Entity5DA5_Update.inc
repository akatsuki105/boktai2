	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08008C94 @ =0x030047A4
	ldr r1, _08008C98 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08008C6E
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	movs r2, #1
	bl Entity5DA5_SetState
_08008C6E:
	adds r5, r6, #0
	adds r5, #0x44
	adds r2, r6, #0
	adds r2, #0x3c
	ldrh r0, [r6, #0x3c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r2, #0
	cmp r0, #0
	blt _08008C9C
	asrs r0, r0, #8
	b _08008CA2
	.align 2, 0
_08008C94: .4byte 0x030047A4
_08008C98: .4byte 0x030047A0
_08008C9C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CA2:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08008CB4
	asrs r0, r0, #8
	b _08008CBA
_08008CB4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CBA:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08008CCE
	asrs r0, r0, #8
	b _08008CD4
_08008CCE:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08008CD4:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08008D30 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r4, r6, #0
	adds r4, #0xcc
	movs r5, #3
_08008CF8:
	ldr r1, _08008D34 @ =0x085AA6A0
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r4, #0
	adds r0, #8
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r1, [r4, #3]
	cmp r1, #0
	beq _08008D44
	subs r1, #1
	strb r1, [r4, #3]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08008D3C
	ldrh r1, [r4, #0xe]
	ldr r3, _08008D38 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	b _08008D42
	.align 2, 0
_08008D30: .4byte 0x030047C8
_08008D34: .4byte 0x085AA6A0
_08008D38: .4byte 0x0000FFFB
_08008D3C:
	ldrh r2, [r4, #0xe]
	movs r1, #4
	orrs r1, r2
_08008D42:
	strh r1, [r4, #0xe]
_08008D44:
	ldr r1, [r4, #4]
	adds r1, #1
	str r1, [r4, #4]
	subs r5, #1
	adds r4, #0xb8
	cmp r5, #0
	bge _08008CF8
	movs r5, #4
	ldrh r2, [r6, #0x1c]
	movs r1, #0xf
	ands r1, r2
	cmp r1, #0xf
	bne _08008DC4
	ldr r0, [r6, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x6c
	adds r1, r6, #0
	adds r1, #0x4c
	bl MainSprite_AdvanceAnim
	adds r3, r6, #0
	adds r3, #0x8c
	ldr r1, [r6, #0x44]
	ldr r2, [r6, #0x48]
	str r1, [r3]
	str r2, [r3, #4]
	adds r1, r6, #0
	adds r1, #0x89
	ldrb r1, [r1]
	ands r5, r1
	cmp r5, #0
	beq _08008DD6
	movs r0, #0x10
	str r0, [sp]
	ldr r2, _08008DBC @ =0x085AA6A8
	adds r0, r6, #0
	adds r0, #0x80
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r2, #2
	mov r3, sp
	bl BgMapScroller_PushCmd
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, _08008DC0 @ =0x03003E78
	ldrh r2, [r3]
	orrs r1, r2
	strh r1, [r3]
	b _08008DD6
	.align 2, 0
_08008DBC: .4byte 0x085AA6A8
_08008DC0: .4byte 0x03003E78
_08008DC4:
	ldr r3, _08008E34 @ =0x03003E78
	ldr r1, _08008E38 @ =0xFFFFFDFF
	ldrh r2, [r3]
	ands r1, r2
	strh r1, [r3]
	ldr r1, [r6, #0x74]
	movs r2, #1
	orrs r1, r2
	str r1, [r6, #0x74]
_08008DD6:
	ldrh r1, [r6, #0x34]
	cmp r1, #0
	beq _08008E00
	ldr r0, _08008E3C @ =0x0000014B
	bl PlaySound_082406e0
	movs r5, #0
_08008DE4:
	ldrh r1, [r6, #0x34]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008DFA
	adds r0, r6, #0
	movs r1, #1
	adds r2, r5, #0
	bl Entity5DA5_RunScript
_08008DFA:
	adds r5, #1
	cmp r5, #3
	ble _08008DE4
_08008E00:
	ldrh r1, [r6, #0x36]
	cmp r1, #0
	beq _08008E24
	movs r5, #0
_08008E08:
	ldrh r1, [r6, #0x36]
	asrs r1, r5
	movs r2, #1
	ands r1, r2
	cmp r1, #0
	beq _08008E1E
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl Entity5DA5_RunScript
_08008E1E:
	adds r5, #1
	cmp r5, #3
	ble _08008E08
_08008E24:
	movs r1, #0
	strh r1, [r6, #0x34]
	strh r1, [r6, #0x36]
	strh r1, [r6, #0x38]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08008E34: .4byte 0x03003E78
_08008E38: .4byte 0xFFFFFDFF
_08008E3C: .4byte 0x0000014B
