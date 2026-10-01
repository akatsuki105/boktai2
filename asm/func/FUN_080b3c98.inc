	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #1
	bl Video_SetBGLayer
	movs r6, #0
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl SolarBank_HideAllSprites
	ldr r0, [r7, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x58
	adds r5, r7, #0
	adds r5, #0x18
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetAnim
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #0x12
	movs r3, #1
	bl MainSprite_SetPose
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, _080B3DB4 @ =0x030046A0
	ldr r1, [r0]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _080B3DB8 @ =0x000005D4
	adds r2, r7, r0
	movs r3, #0x91
	lsls r3, r3, #4
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	str r0, [r2]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0x90
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r3, #3
_080B3D30:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _080B3D30
	adds r0, r7, #0
	bl solar_bank_080b3a10
	movs r2, #2
	rsbs r2, r2, #0
	movs r0, #0xa7
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r3, #1
_080B3D58:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080B3D58
	movs r4, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, _080B3DBC @ =0x0000013D
	bl Video_SetAuxSpritePltt
	ldr r3, _080B3DC0 @ =0x000005AC
	adds r0, r7, r3
	movs r1, #0xa0
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r0, #2
	bl TextBox_ShowLine
	ldr r1, _080B3DC4 @ =0x000005E2
	adds r0, r7, r1
	strh r4, [r0]
	ldr r3, _080B3DC8 @ =0x000005E4
	adds r0, r7, r3
	strh r4, [r0]
	adds r1, #4
	adds r0, r7, r1
	strh r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	strh r4, [r0]
	subs r1, #6
	adds r0, r7, r1
	strh r4, [r0]
	ldr r1, _080B3DCC @ =solar_bank_080b3f38
	adds r0, r7, #0
	bl SolarBank_SetState
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B3DB4: .4byte 0x030046A0
_080B3DB8: .4byte 0x000005D4
_080B3DBC: .4byte 0x0000013D
_080B3DC0: .4byte 0x000005AC
_080B3DC4: .4byte 0x000005E2
_080B3DC8: .4byte 0x000005E4
_080B3DCC: .4byte solar_bank_080b3f38
