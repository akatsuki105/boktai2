	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	mov sl, r7
	adds r2, r7, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	bne _0803180C
	b _08031A44
_0803180C:
	movs r1, #0
	strb r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r1, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r1, _080318A0 @ =0x00000873
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r6, #4
	str r6, [sp, #4]
	adds r0, r7, #0
	adds r2, r4, #0
	movs r3, #0x2f
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	str r6, [sp]
	adds r1, r4, #0
	movs r2, #0x30
	movs r3, #2
	bl MainSprite_SetAnim
	mov sb, r7
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	movs r3, #0xa4
	lsls r3, r3, #4
	adds r5, r7, r3
	adds r0, r7, #0
	bl FUN_08028ec8
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xa2
	lsls r0, r0, #4
	adds r1, r7, r0
	str r6, [sp]
	adds r0, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r0, r7, #0
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _080318A4
	ldr r0, [r5, #8]
	orrs r0, r6
	b _080318AC
	.align 2, 0
_080318A0: .4byte 0x00000873
_080318A4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080318AC:
	str r0, [r5, #8]
	ldr r1, _08031904 @ =0x00000173
	adds r3, r7, r1
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #2
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08031908 @ =0x00000A18
	adds r2, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, [sp, #0x1c]
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r6, r5, #0
	adds r6, #0x20
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
	mov r8, r3
	cmp r0, #0
	blt _0803190C
	asrs r0, r0, #8
	b _08031912
	.align 2, 0
_08031904: .4byte 0x00000173
_08031908: .4byte 0x00000A18
_0803190C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08031912:
	strh r0, [r6]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08031924
	asrs r0, r0, #8
	b _0803192A
_08031924:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0803192A:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08031940
	asrs r0, r0, #8
	b _08031946
_08031940:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08031946:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08031988 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	mov r0, sb
	adds r0, #0xaf
	ldrb r0, [r0]
	cmp r0, #0
	bne _08031990
	ldr r0, _0803198C @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r2, [r5, #0x20]
	adds r1, r1, r2
	strh r1, [r5, #0x20]
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r3, [r5, #0x22]
	adds r0, r0, r3
	b _080319A4
	.align 2, 0
_08031988: .4byte 0x030047C8
_0803198C: .4byte 0x085AABBC
_08031990:
	ldr r2, _08031A1C @ =0x085AABBC
	movs r1, #0
	ldrsb r1, [r2, r1]
	ldrh r0, [r5, #0x20]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	movs r0, #1
	ldrsb r0, [r2, r0]
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
_080319A4:
	strh r0, [r5, #0x22]
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	ldr r2, _08031A20 @ =0x00000A14
	adds r1, r7, r2
	ldr r0, _08031A24 @ =0x0000FFFF
	strh r0, [r1]
	ldr r3, [sp, #0x1c]
	ldrh r1, [r3, #0x14]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	mov r0, sb
	adds r0, #0xab
	ldrb r3, [r0]
	cmp r3, #0
	bne _080319F4
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _08031A28 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [sp, #0x1c]
	adds r1, #0x20
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #1
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	str r2, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
_080319F4:
	movs r0, #0x84
	lsls r0, r0, #7
	strh r0, [r5, #0x3a]
	mov r2, r8
	movs r0, #0
	ldrsb r0, [r2, r0]
	ldr r1, _08031A28 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r1, _08031A2C @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08031A30
	adds r0, r3, #0
	adds r0, #0xd0
	ldr r0, [r0]
	b _08031A3A
	.align 2, 0
_08031A1C: .4byte 0x085AABBC
_08031A20: .4byte 0x00000A14
_08031A24: .4byte 0x0000FFFF
_08031A28: .4byte 0x03002BE0
_08031A2C: .4byte 0x00000359
_08031A30:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
_08031A3A:
	str r0, [r5, #0x48]
	ldr r3, _08031A88 @ =0x00000874
	adds r1, r7, r3
	movs r0, #0x78
	strh r0, [r1]
_08031A44:
	movs r1, #0x80
	lsls r1, r1, #0x11
	mov r0, sl
	adds r0, #0x98
	ldr r2, [r0]
	orrs r2, r1
	str r2, [r0]
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	beq _08031A64
	cmp r1, #5
	bne _08031A90
_08031A64:
	movs r0, #0xc
	orrs r2, r0
	str r2, [r4]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _08031A8C @ =0x00000167
	adds r0, r7, r3
	strb r2, [r0]
	b _08031AA4
	.align 2, 0
_08031A88: .4byte 0x00000874
_08031A8C: .4byte 0x00000167
_08031A90:
	mov r0, sl
	adds r0, #0xfc
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031AA4
	b _08031EFE
_08031AA4:
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08031AD4
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _08031EFE
_08031AD4:
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _08031B46
	ldr r3, _08031B60 @ =0x00000173
	adds r0, r7, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r2, [r0]
	ldr r0, _08031B64 @ =0x00000877
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, r2
	beq _08031B18
	strb r2, [r1]
	ldr r2, _08031B68 @ =0x0000016D
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08031B18:
	ldr r0, _08031B68 @ =0x0000016D
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #3
	bls _08031B46
	adds r0, r3, #0
	bl Player_GetDpadFacing
	lsls r0, r0, #0x1d
	movs r1, #0xa0
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x10
	strb r0, [r1]
	strb r5, [r4]
_08031B46:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #5
	bls _08031B54
	b _08031EDA
_08031B54:
	lsls r0, r0, #2
	ldr r1, _08031B6C @ =_08031B70
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031B60: .4byte 0x00000173
_08031B64: .4byte 0x00000877
_08031B68: .4byte 0x0000016D
_08031B6C: .4byte _08031B70
_08031B70: @ jump table
	.4byte _08031B88 @ case 0
	.4byte _08031BCA @ case 1
	.4byte _08031C74 @ case 2
	.4byte _08031CCC @ case 3
	.4byte _08031D2A @ case 4
	.4byte _08031EC4 @ case 5
_08031B88:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r6, r7, r2
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031B9E
	b _08031EDA
_08031B9E:
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x31
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x32
	b _08031CB4
_08031BCA:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r6, r7, r3
	ldrh r0, [r6]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031BE4
	b _08031EDA
_08031BE4:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x33
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x34
	movs r3, #2
	bl MainSprite_SetAnim
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r6]
	ldr r3, _08031C64 @ =0x00000173
	adds r1, r7, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _08031C52
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r2, _08031C68 @ =0x00000876
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08031C6C @ =0x00000877
	adds r0, r7, r3
	strb r1, [r0]
_08031C52:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r3, _08031C70 @ =0x0000016D
	adds r0, r7, r3
	strb r2, [r0]
	b _08031EDA
	.align 2, 0
_08031C64: .4byte 0x00000173
_08031C68: .4byte 0x00000876
_08031C6C: .4byte 0x00000877
_08031C70: .4byte 0x0000016D
_08031C74:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r6, r7, r0
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031C8A
	b _08031EDA
_08031C8A:
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #4
	str r4, [sp, #4]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x35
	bl Boss_PlayAnim
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r5, #0
	movs r2, #0x36
_08031CB4:
	movs r3, #2
	bl MainSprite_SetAnim
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r6]
	b _08031EDA
_08031CCC:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r5, r7, r3
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031CE2
	b _08031EDA
_08031CE2:
	movs r0, #0xa4
	lsls r0, r0, #4
	adds r4, r7, r0
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0xb5
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0x37
	bl Boss_PlayAnim
	movs r0, #0xd5
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r4, #8]
	orrs r0, r2
	str r0, [r4, #8]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	strh r0, [r5]
	b _08031EDA
_08031D2A:
	movs r3, #0xae
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08031D40
	b _08031EDA
_08031D40:
	movs r1, #4
	ldr r0, _08031E04 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08031D7C
	ldr r1, _08031E08 @ =0x00000173
	adds r0, r7, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #2
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, sl
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _08031E0C @ =0x00000876
	adds r1, r7, r2
	ldrb r1, [r1]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r2, _08031E10 @ =0xFFFFFF00
	adds r1, r1, r2
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0xf
	ble _08031D84
_08031D7C:
	ldr r3, _08031E14 @ =0x00000874
	adds r1, r7, r3
	movs r0, #0
	strh r0, [r1]
_08031D84:
	ldr r1, _08031E14 @ =0x00000874
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08031E20
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0x38
	bl Boss_PlayAnim
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r7, #0
	adds r0, #0xab
	ldrb r4, [r0]
	ldr r2, _08031E08 @ =0x00000173
	adds r2, r2, r7
	mov r8, r2
	cmp r4, #0
	bne _08031DF6
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08031DF6
	adds r2, r0, #0
	ldr r1, _08031E18 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r7, #0
	adds r1, #0xc8
	adds r1, r1, r2
	ldrb r3, [r1]
	ldr r2, _08031E1C @ =0x00000A18
	adds r1, r7, r2
	movs r2, #0x32
	str r2, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_0807ac74
_08031DF6:
	movs r0, #0xff
	mov r3, r8
	strb r0, [r3]
	adds r0, #0x5f
	adds r1, r7, r0
	b _08031E54
	.align 2, 0
_08031E04: .4byte 0x03002BC0
_08031E08: .4byte 0x00000173
_08031E0C: .4byte 0x00000876
_08031E10: .4byte 0xFFFFFF00
_08031E14: .4byte 0x00000874
_08031E18: .4byte 0x03002BE0
_08031E1C: .4byte 0x00000A18
_08031E20:
	ldr r2, _08031E5C @ =0x00000873
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08031E60
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	mov r0, sl
	movs r3, #0x38
	bl Boss_PlayAnim
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r7, r2
_08031E54:
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08031EB8
	.align 2, 0
_08031E5C: .4byte 0x00000873
_08031E60:
	movs r3, #0xa4
	lsls r3, r3, #4
	adds r3, r3, r7
	mov sb, r3
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r6, r7, r2
	movs r3, #2
	mov r8, r3
	str r3, [sp]
	movs r5, #4
	str r5, [sp, #4]
	mov r0, sl
	adds r2, r6, #0
	movs r3, #0x35
	bl Boss_PlayAnim
	movs r0, #0xd5
	lsls r0, r0, #2
	adds r4, r7, r0
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x36
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	mov r2, sb
	ldr r0, [r2, #8]
	ands r0, r1
	str r0, [r2, #8]
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, r8
	strh r1, [r0]
_08031EB8:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	b _08031EDA
_08031EC4:
	ldr r3, _08031F10 @ =0x00000311
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08031EDA
	mov r1, sl
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_08031EDA:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r7, r2
	bl MainSprite_AdvanceAnim
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_08031EFE:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031F10: .4byte 0x00000311
