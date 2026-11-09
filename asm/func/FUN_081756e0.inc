	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081756F2
	b _08175858
_081756F2:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r1, #0x20
	ldr r2, _0817570C @ =0x00001008
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08175710
	movs r0, #1
	b _08175712
	.align 2, 0
_0817570C: .4byte 0x00001008
_08175710:
	movs r0, #0
_08175712:
	adds r5, r0, #0
	cmp r5, #0
	beq _0817571A
	b _08175858
_0817571A:
	ldr r3, _08175794 @ =0x00000FAA
	adds r0, r7, r3
	ldrh r2, [r0]
	cmp r2, #0
	bne _08175730
	ldr r6, _08175798 @ =0x0000048A
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08175730
	b _08175848
_08175730:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r2
	movs r3, #0
	strh r0, [r1]
	movs r2, #0
	ldrsh r6, [r1, r2]
	ldr r0, _08175798 @ =0x0000048A
	adds r2, r4, r0
	ldrh r0, [r2]
	subs r0, r6, r0
	cmp r0, #0
	bgt _08175830
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r5, [r0]
	adds r6, #5
	adds r0, r4, r6
	strb r3, [r0]
	ldr r6, _0817579C @ =0x0000048C
	adds r0, r4, r6
	strb r3, [r0]
	strh r5, [r2]
	ldr r2, _081757A0 @ =0x000004BE
	adds r0, r4, r2
	strh r5, [r0]
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	movs r1, #0x20
	ldr r6, _081757A4 @ =0x00001008
	adds r0, r0, r6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r1, #0x84
	adds r0, r7, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081757A8
	movs r0, #1
	b _081757AA
	.align 2, 0
_08175794: .4byte 0x00000FAA
_08175798: .4byte 0x0000048A
_0817579C: .4byte 0x0000048C
_081757A0: .4byte 0x000004BE
_081757A4: .4byte 0x00001008
_081757A8:
	movs r0, #0
_081757AA:
	adds r5, r0, #0
	cmp r5, #0
	bne _08175800
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _0817581C @ =0x0000046D
	adds r0, r4, r3
	strb r2, [r0]
	ldr r6, _08175820 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r3, #0xe6
	adds r0, r4, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r3, #0xd
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08175824 @ =0x0000046A
	adds r0, r4, r1
	strb r3, [r0]
	ldr r3, _08175828 @ =0x00000484
	adds r0, r4, r3
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r2, [r0]
_08175800:
	ldrh r0, [r4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldr r3, _0817582C @ =0x0000025A
	adds r1, r4, r3
	ldrh r3, [r1]
	movs r1, #0
	str r1, [sp]
	bl HUD_ShowEnemyGauge
	b _08175848
	.align 2, 0
_0817581C: .4byte 0x0000046D
_08175820: .4byte 0x0000046B
_08175824: .4byte 0x0000046A
_08175828: .4byte 0x00000484
_0817582C: .4byte 0x0000025A
_08175830:
	ldrh r0, [r4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	ldr r3, _08175860 @ =0x0000025A
	adds r1, r4, r3
	ldrh r3, [r1]
	str r5, [sp]
	adds r1, r6, #0
	bl HUD_ShowEnemyGauge
_08175848:
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08175864 @ =0x00000FAA
	adds r0, r7, r2
	strh r1, [r0]
_08175858:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08175860: .4byte 0x0000025A
_08175864: .4byte 0x00000FAA
