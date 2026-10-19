	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #4
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_080b4abc
	ldr r0, [r7, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x58
	adds r6, r7, #0
	adds r6, #0x18
	str r5, [sp]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080B4D80 @ =0x0000082E
	adds r0, r7, r1
	strh r5, [r0]
	adds r6, #0x48
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #3
_080B4CD2:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B4CD2
	adds r0, r7, #0
	bl FUN_080b4818
	adds r0, r7, #0
	bl FUN_080b4a50
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r3, r6, r3
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r5, #3
_080B4D06:
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B4D06
	movs r4, #0
	adds r0, r7, #0
	bl dark_loans_080b48c8
	ldr r1, _080B4D84 @ =0x00000848
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080B4D88 @ =0x00000804
	adds r0, r7, r1
	ldr r1, _080B4D8C @ =0x00000143
	bl Video_SetAuxSpritePltt
	movs r0, #4
	bl MessageWindow_ShowLine
	ldr r1, _080B4D90 @ =0x0000083A
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	subs r1, #8
	adds r0, r7, r1
	strh r4, [r0]
	ldr r1, _080B4D94 @ =dark_loans_080b5020
	adds r0, r7, #0
	bl DarkLoans_SetUpdate
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B4D80: .4byte 0x0000082E
_080B4D84: .4byte 0x00000848
_080B4D88: .4byte 0x00000804
_080B4D8C: .4byte 0x00000143
_080B4D90: .4byte 0x0000083A
_080B4D94: .4byte dark_loans_080b5020
