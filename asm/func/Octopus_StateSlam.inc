	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov sb, r1
	ldr r0, [r5, #0x44]
	str r0, [sp, #0x1c]
	ldr r2, _0818597C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185980
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185982
	.align 2, 0
_0818597C: .4byte 0x0000046D
_08185980:
	movs r0, #0
_08185982:
	cmp r0, #0
	beq _08185A54
	adds r0, r5, #0
	movs r1, #0x14
	bl Enemy_PlayAnimNoFacing
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081859E8 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r6, _081859EC @ =0x00000474
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r6, r5, #0
	adds r6, #8
	adds r1, r5, #0
	adds r1, #0x9c
	ldr r0, [r1, #8]
	ldrh r0, [r0]
	strh r0, [r5, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r0, #2]
	strh r1, [r6, #4]
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081859E2
	cmp r1, #0
	blt _081859E2
	ldr r0, _081859F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081859E2
	ldr r0, _081859F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081859F8
_081859E2:
	movs r4, #0
	b _08185A06
	.align 2, 0
_081859E8: .4byte 0x0000FFF7
_081859EC: .4byte 0x00000474
_081859F0: .4byte 0x030046A8
_081859F4: .4byte 0x030046AC
_081859F8:
	ldr r0, _08185A18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08185A06:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08185A1C
	adds r0, #4
	b _08185A28
	.align 2, 0
_08185A18: .4byte 0x030046A4
_08185A1C:
	ldr r0, _08185A3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08185A28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08185A40
	cmp r2, #2
	beq _08185A44
	b _08185A48
	.align 2, 0
_08185A3C: .4byte 0x030046A4
_08185A40:
	ldrb r0, [r6, #4]
	b _08185A46
_08185A44:
	ldrb r0, [r6]
_08185A46:
	subs r1, r1, r0
_08185A48:
	strh r1, [r6, #2]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r2, [sp, #0x1c]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_08185A54:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r6, [r0]
	mov r0, sb
	cmp r0, #0x3c
	beq _08185A66
	cmp r0, #0x5a
	bne _08185B3A
_08185A66:
	ldr r1, _08185A84 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _08185A88
	ldr r0, [r5, #0x44]
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	adds r3, r0, #0
	b _08185A98
	.align 2, 0
_08185A84: .4byte 0x0000025D
_08185A88:
	ldr r3, [r5, #0x44]
	adds r2, r3, #0
	adds r2, #0x20
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
_08185A98:
	ldr r2, _08185AB0 @ =0x0000047C
	adds r0, r5, r2
	ldrh r1, [r0]
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185AB4
	adds r0, r3, #0
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08185ABE
	.align 2, 0
_08185AB0: .4byte 0x0000047C
_08185AB4:
	ldr r0, _08185B10 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r3, #0x68]
_08185ABE:
	ldr r0, _08185B14 @ =0x00000492
	adds r1, r5, r0
	movs r3, #0
	movs r0, #8
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r6, #4]
	cmp r1, #3
	bhi _08185B18
	ldr r1, [r6, #0x38]
	mov r8, r1
	adds r1, r5, #0
	adds r1, #8
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	adds r2, #0x1c
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [sp, #0x10]
	mov r0, r8
	movs r2, #0
	bl Player_HoldGrabbed
	movs r0, #0xe6
	bl PlaySound_082406e0
	b _08185B62
	.align 2, 0
_08185B10: .4byte 0x03003584
_08185B14: .4byte 0x00000492
_08185B18:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08185B62
	ldr r4, [r6, #0x38]
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r1, #2
	add r2, sp, #0x14
	movs r3, #0
	bl FUN_080e6978
	adds r0, r4, #0
	bl Enemy_PlayVoice
	b _08185B62
_08185B3A:
	movs r2, #1
	ldr r1, _08185B54 @ =0x0000025D
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _08185B58
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08185B62
	.align 2, 0
_08185B54: .4byte 0x0000025D
_08185B58:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08185B62:
	mov r0, sb
	subs r0, #0x33
	cmp r0, #8
	bhi _08185B70
	movs r0, #0x14
	bl Camera_Shake
_08185B70:
	mov r0, sb
	subs r0, #0x51
	cmp r0, #8
	bhi _08185B7E
	movs r0, #0x28
	bl Camera_Shake
_08185B7E:
	mov r2, sb
	cmp r2, #0x78
	bgt _08185B86
	b _08185D1A
_08185B86:
	movs r2, #1
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185B98
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08185BA2
_08185B98:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08185BA2:
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08185BC4
	ldr r4, [r6, #0x38]
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #2
	add r2, sp, #0x14
	movs r3, #0
	bl FUN_080e6978
	b _08185C88
_08185BC4:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08185C88
	ldr r6, [r6, #0x38]
	mov r8, r6
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _08185BE2
	asrs r0, r1, #6
	b _08185BE8
_08185BE2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08185BE8:
	lsls r0, r0, #6
	str r0, [sp, #0x20]
	ldr r6, _08185C30 @ =0x00000256
	adds r0, r5, r6
	ldrh r6, [r0]
	add r0, sp, #0x14
	mov sl, r0
	ldr r7, _08185C34 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x14
	strh r4, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08185C38
	adds r0, #4
	b _08185C42
	.align 2, 0
_08185C30: .4byte 0x00000256
_08185C34: .4byte 0x030046A4
_08185C38:
	ldr r0, [r7]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08185C42:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	mov r6, sl
	strh r0, [r6, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	movs r0, #0x3c
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	add r1, sp, #0x14
	movs r2, #0x80
	ldr r3, [sp, #0x20]
	bl Player_ReleaseGrabbed
	adds r0, r5, #0
	adds r0, #8
	movs r1, #0x8a
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #1
	bl Entity081ea120_Spawn
	ldr r0, _08185D2C @ =0x000001DF
	bl PlaySound_082406e0
_08185C88:
	adds r0, r5, #0
	movs r1, #0x10
	bl Enemy_PlayAnimFlipOnly
	ldr r3, _08185D30 @ =Enemy_ClearStateBegun
	movs r4, #1
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	subs r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	ldr r3, _08185D34 @ =FUN_080e68d8
	movs r1, #0xe
	subs r6, #0xe4
	adds r0, r5, r6
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08185D38 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08185D3C @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	ldrh r0, [r5, #8]
	adds r0, #0x20
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, #0x20
	strh r0, [r5, #0xc]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	ldr r6, [sp, #0x1c]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_08185D1A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08185D2C: .4byte 0x000001DF
_08185D30: .4byte Enemy_ClearStateBegun
_08185D34: .4byte FUN_080e68d8
_08185D38: .4byte 0x00000469
_08185D3C: .4byte 0x0000046C
