	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r6, r0, #0
	mov r8, r6
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	bne _08034B34
	b _08034D70
_08034B34:
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0x20
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x57
	bl Boss_PlayAnimFlip
	mov sb, r6
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r1, r1, r6
	mov sl, r1
	movs r2, #0xa4
	lsls r2, r2, #4
	adds r5, r6, r2
	adds r0, r6, #0
	bl FUN_08028ec8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r1, r6, r0
	str r4, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r6, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _08034B8E
	ldr r0, [r5, #8]
	orrs r0, r4
	b _08034B96
_08034B8E:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08034B96:
	str r0, [r5, #8]
	ldr r3, _08034BEC @ =0x00000173
	add r3, r8
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _08034BF0 @ =0x00000A18
	add r2, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r2, sl
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r7, r5, #0
	adds r7, #0x20
	add r0, sp, #0x14
	mov ip, r0
	add r0, sp, #0x14
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	str r3, [sp, #0x24]
	cmp r0, #0
	blt _08034BF4
	asrs r0, r0, #8
	b _08034BFA
	.align 2, 0
_08034BEC: .4byte 0x00000173
_08034BF0: .4byte 0x00000A18
_08034BF4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08034BFA:
	strh r0, [r7]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08034C0C
	asrs r0, r0, #8
	b _08034C12
_08034C0C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08034C12:
	adds r4, r0, #0
	mov r2, ip
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08034C28
	asrs r0, r0, #8
	b _08034C2E
_08034C28:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08034C2E:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08034C70 @ =0x030047C8
	ldrh r0, [r7]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r7]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r7, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r7, #4]
	mov r0, sb
	adds r0, #0xaf
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _08034C78
	ldr r0, _08034C74 @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x20]
	adds r1, r1, r2
	strh r1, [r5, #0x20]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
	b _08034C8C
	.align 2, 0
_08034C70: .4byte 0x030047C8
_08034C74: .4byte 0x085AABBC
_08034C78:
	ldr r2, _08034CBC @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	movs r0, #1
	ldrsb r0, [r2, r0]
	ldrh r2, [r5, #0x22]
	adds r0, r0, r2
_08034C8C:
	strh r0, [r5, #0x22]
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	ldr r1, _08034CC0 @ =0x00000A14
	add r1, r8
	ldr r0, _08034CC4 @ =0x0000FFFF
	strh r0, [r1]
	mov r0, sl
	ldrh r1, [r0, #0x14]
	ldr r0, _08034CC8 @ =0x00000A16
	add r0, r8
	strh r1, [r0]
	ldrb r0, [r3]
	cmp r0, #0
	bne _08034CD0
	ldr r3, _08034CCC @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	movs r1, #0x20
	b _08034CD8
	.align 2, 0
_08034CBC: .4byte 0x085AABBC
_08034CC0: .4byte 0x00000A14
_08034CC4: .4byte 0x0000FFFF
_08034CC8: .4byte 0x00000A16
_08034CCC: .4byte 0xFFFF0000
_08034CD0:
	ldr r3, _08034D50 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r3
	ldr r1, _08034D54 @ =0x0000FFE0
_08034CD8:
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r2, sp, #0x1c
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _08034D58 @ =0x0000FFFF
	ldr r0, [sp, #0x1c]
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x1c]
	adds r4, r2, #0
	mov r0, sb
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _08034D28
	ldr r1, [sp, #0x24]
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _08034D5C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, sl
	adds r1, #0x20
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	adds r2, r4, #0
	movs r3, #0
	bl Player_HoldGrabbed
_08034D28:
	movs r0, #0x84
	lsls r0, r0, #7
	strh r0, [r5, #0x3a]
	ldr r2, [sp, #0x24]
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r1, _08034D5C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r1, _08034D60 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08034D64
	adds r0, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _08034D6E
	.align 2, 0
_08034D50: .4byte 0xFFFF0000
_08034D54: .4byte 0x0000FFE0
_08034D58: .4byte 0x0000FFFF
_08034D5C: .4byte 0x03002BE0
_08034D60: .4byte 0x00000359
_08034D64:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_08034D6E:
	str r0, [r5, #0x48]
_08034D70:
	movs r1, #0xc0
	lsls r1, r1, #1
	add r1, r8
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #1
	add r0, r8
	strb r2, [r0]
	ldr r0, _08034DD0 @ =0x00000167
	add r0, r8
	strb r2, [r0]
	movs r2, #0xc
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034DC0
	ldr r0, _08034DD4 @ =0x00000311
	add r0, r8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034DC0
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08034DC0:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08034DD0: .4byte 0x00000167
_08034DD4: .4byte 0x00000311
