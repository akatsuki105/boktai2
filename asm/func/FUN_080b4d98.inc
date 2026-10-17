	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #5
	bl Video_SetBGLayer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b4abc
	ldr r0, _080B4DFC @ =0x000002C1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl MainSprite_SetAnim
	movs r0, #3
	bl MessageWindow_ShowLine
	ldr r1, _080B4E00 @ =FUN_080b539c
	adds r0, r4, #0
	bl FUN_080b4aec
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B4DFC: .4byte 0x000002C1
_080B4E00: .4byte FUN_080b539c
