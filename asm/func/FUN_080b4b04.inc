	push {r4, r5, r6, lr}
	sub sp, #0xc
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
	movs r2, #4
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
	movs r0, #0
	bl MessageWindow_ShowLine
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4B9C @ =0x0000FFFF
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B4BA0 @ =FUN_080b4f08
	adds r0, r6, #0
	bl DarkLoans_SetUpdate
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B4B9C: .4byte 0x0000FFFF
_080B4BA0: .4byte FUN_080b4f08
