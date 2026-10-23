	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081E5A6C @ =0x00001614
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E58F8
	b _081E5A48
_081E58F8:
	bl Marquee_Clear
	bl FUN_08049f84
	ldr r2, _081E5A70 @ =0x00001610
	adds r1, r7, r2
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	movs r0, #0x14
	str r0, [sp]
	movs r6, #0
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl Video_FillBGRect
	adds r0, r7, #0
	bl FUN_081e47c4
	adds r0, r7, #0
	bl FUN_081e4838
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #4
	bl Video_SetBGLayer
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r4, r7, r0
	ldr r0, [r4]
	movs r5, #2
	str r5, [sp]
	movs r1, #0xd
	movs r2, #4
	movs r3, #0xa
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r1, _081E5A74 @ =0x000015F0
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r2, _081E5A78 @ =0x00001604
	adds r4, r7, r2
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #0xd
	movs r2, #0xa
	movs r3, #0xa
	bl TextPanel_SetRect
	ldr r0, [r4]
	mov r3, r8
	ldr r1, [r3]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #1
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r0, _081E5A7C @ =0x00001608
	adds r4, r7, r0
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #8
	movs r2, #7
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r2, _081E5A80 @ =0x00001590
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r3, _081E5A84 @ =0x00000E28
	adds r5, r7, r3
	ldr r1, _081E5A88 @ =0x0000159C
	adds r2, r7, r1
	adds r1, r5, #0
	bl FUN_08094d30
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r2, _081E5A8C @ =0x000014AC
	adds r0, r7, r2
	ldr r3, _081E5A90 @ =0x0000156C
	adds r1, r7, r3
	ldrb r2, [r5]
	bl MainSprite_LoadPose
	ldr r0, _081E5A94 @ =0x000014CC
	adds r1, r7, r0
	movs r5, #0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _081E5A98 @ =0x000014CE
	adds r1, r7, r2
	movs r0, #0x38
	strh r0, [r1]
	ldr r3, _081E5A9C @ =0x000014B4
	adds r1, r7, r3
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r3, _081E5AA0 @ =0x0000160C
	adds r4, r7, r3
	ldr r0, [r4]
	mov r2, r8
	ldr r1, [r2]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #0xb
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	adds r0, r7, #0
	bl FUN_081e4948
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _081E5AA4 @ =0x0000162A
	adds r0, r7, r1
	strh r6, [r0]
	mov r2, sl
	strb r5, [r2]
_081E5A48:
	ldr r3, _081E5AA8 @ =0x000009E8
	adds r6, r7, r3
	ldr r0, _081E5AAC @ =0x00000AC8
	adds r0, r0, r7
	mov r8, r0
	adds r0, r6, #0
	mov r1, r8
	bl MainSprite_AdvanceAnim
	ldr r2, _081E5AA4 @ =0x0000162A
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E5AB0
	adds r0, #1
	strh r0, [r1]
	b _081E5C24
	.align 2, 0
_081E5A6C: .4byte 0x00001614
_081E5A70: .4byte 0x00001610
_081E5A74: .4byte 0x000015F0
_081E5A78: .4byte 0x00001604
_081E5A7C: .4byte 0x00001608
_081E5A80: .4byte 0x00001590
_081E5A84: .4byte 0x00000E28
_081E5A88: .4byte 0x0000159C
_081E5A8C: .4byte 0x000014AC
_081E5A90: .4byte 0x0000156C
_081E5A94: .4byte 0x000014CC
_081E5A98: .4byte 0x000014CE
_081E5A9C: .4byte 0x000014B4
_081E5AA0: .4byte 0x0000160C
_081E5AA4: .4byte 0x0000162A
_081E5AA8: .4byte 0x000009E8
_081E5AAC: .4byte 0x00000AC8
_081E5AB0:
	ldr r0, _081E5AE8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081E5AF8
	adds r0, r7, #0
	movs r1, #9
	bl FUN_081e4c64
	ldr r3, _081E5AEC @ =0x00001618
	adds r1, r7, r3
	movs r2, #0
	movs r0, #9
	strb r0, [r1]
	ldr r1, _081E5AF0 @ =0x00001624
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081E5AF4 @ =FUN_081e5d14
	movs r2, #0x10
	str r0, [r7, #0x18]
	subs r3, #4
	adds r1, r7, r3
	movs r0, #1
	b _081E5BB8
	.align 2, 0
_081E5AE8: .4byte 0x030044E0
_081E5AEC: .4byte 0x00001618
_081E5AF0: .4byte 0x00001624
_081E5AF4: .4byte FUN_081e5d14
_081E5AF8:
	ldr r2, _081E5B28 @ =0x00001623
	adds r5, r7, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _081E5B78
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081E5B30
	ldr r3, _081E5B2C @ =0x00000B2C
	adds r0, r7, r3
	ldrh r2, [r0]
	str r4, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #1
	strb r0, [r5]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E5BEE
	.align 2, 0
_081E5B28: .4byte 0x00001623
_081E5B2C: .4byte 0x00000B2C
_081E5B30:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081E5BEE
	adds r0, r7, #0
	movs r1, #3
	bl FUN_081e4c64
	ldr r0, _081E5B6C @ =FUN_081e5c40
	movs r2, #0xd
	str r0, [r7, #0x18]
	ldr r0, _081E5B70 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5B74 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0x9f
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E5C24
	.align 2, 0
_081E5B6C: .4byte FUN_081e5c40
_081E5B70: .4byte 0x00001614
_081E5B74: .4byte 0x00001616
_081E5B78:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081E5BD4
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _081E5BEE
	adds r0, r7, #0
	movs r1, #9
	bl FUN_081e4c64
	ldr r3, _081E5BC4 @ =0x00001618
	adds r1, r7, r3
	movs r0, #9
	strb r0, [r1]
	ldr r1, _081E5BC8 @ =0x00001624
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9f
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r0, _081E5BCC @ =FUN_081e5d14
	movs r2, #0x10
	str r0, [r7, #0x18]
	subs r3, #4
	adds r1, r7, r3
	movs r0, #1
_081E5BB8:
	strb r0, [r1]
	ldr r1, _081E5BD0 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	b _081E5C24
	.align 2, 0
_081E5BC4: .4byte 0x00001618
_081E5BC8: .4byte 0x00001624
_081E5BCC: .4byte FUN_081e5d14
_081E5BD0: .4byte 0x00001616
_081E5BD4:
	ldr r2, _081E5C34 @ =0x00000B2A
	adds r0, r7, r2
	ldrh r2, [r0]
	str r4, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #1
	bl MainSprite_SetAnim
	strb r4, [r5]
	movs r0, #0xdc
	bl PlaySound_082406e0
_081E5BEE:
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r7, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _081E5C24
	ldr r2, _081E5C38 @ =0x00001624
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081E5C3C @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r7, #0x18]
	subs r3, #0xc
	adds r0, r7, r3
	movs r2, #1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E5C24:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5C34: .4byte 0x00000B2A
_081E5C38: .4byte 0x00001624
_081E5C3C: .4byte FUN_081e653c
