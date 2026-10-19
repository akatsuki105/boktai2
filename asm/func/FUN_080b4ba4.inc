	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #3
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r6, #0
	bl FUN_080b4abc
	ldr r0, [r6, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r6, #0x60]
	adds r0, r6, #0
	adds r0, #0x58
	adds r1, r6, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #7
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, _080B4C50 @ =0x00000842
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r1, r6, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	subs r1, #0x88
	str r5, [sp]
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #1
	bl MessageWindow_ShowLine
	ldr r1, _080B4C54 @ =0x0000082E
	adds r0, r6, r1
	strh r5, [r0]
	ldr r1, _080B4C58 @ =FUN_080b4f48
	adds r0, r6, #0
	bl DarkLoans_SetUpdate
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4C50: .4byte 0x00000842
_080B4C54: .4byte 0x0000082E
_080B4C58: .4byte FUN_080b4f48
